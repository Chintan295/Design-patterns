# SOLID Principles

## Single responsibility principle

The Single Responsibility Principle states that a class should have only one reason to change, meaning it should have only one responsibility or single purpose. In other words, a class should have only one job to perform.

Example:

Consider a Product class that has the following methods:

    public class Product {
        public String getName() { ... }
        public double getPrice() { ... }
        public void addProductToCart(User user) { ... }
        public void updateProductStock(int quantity) { ... }
    }

Problem:
The Product class has multiple responsibilities:
* It handles product details (name and price).
* It handles adding products to the cart.
* It handles updating product stock.

Solution:

Split the Product class into separate classes, each with a single responsibility:

    public class ProductDetails {
        public String getName() { ... }
        public double getPrice() { ... }
    }

    public class ProductCartManager {
        public void addProductToCart(User user, ProductDetails product) { ... }
    }

    public class ProductStockManager {
        public void updateProductStock(ProductDetails product, int quantity) { ... }
    }

By applying the Single Responsibility Principle, we've made the code more modular, easier to understand, and less prone to errors.

Single responsibility principle related to following design patterns:
* Facade Pattern
* Strategy Pattern
* Template Method Pattern
* MVC (Model-View-Controller) Pattern
* Service Pattern
* Adapter Pattern
* Decorator Pattern


## Open-Closed Principle
 Software entities (classes, modules, functions, etc.) should be open for extension but closed for modification.

Example:

Violation of OCP:

    public class PaymentGateway {
        public void processPayment(String paymentMethod, double amount) {
            if (paymentMethod.equals("creditCard")) {
                // Credit card payment logic
            } else if (paymentMethod.equals("payPal")) {
                // PayPal payment logic (added later, violating OCP)
            }
        }
    }

Here payment gateway needs to be modified when we want to add another payment method(Google Pay).

Solution:

    public abstract class PaymentGateway {
        public abstract void processPayment(double amount);
    }

    public class CreditCardPaymentGateway extends PaymentGateway {
        @Override
        public void processPayment(double amount) {
            // Credit card payment logic
        }
    }

    public class PayPalPaymentGateway extends PaymentGateway {
        @Override
        public void processPayment(double amount) {
            // PayPal payment logic
        }
    }

 If we want to add a new payment method (e.g., Google Pay), we can simply create a new class GooglePayPaymentGateway that extends PaymentGateway without modifying the existing code.

Benefits:
* We've decoupled the payment logic from the PaymentGateway class.
* We can add new payment methods without modifying existing code.
* We can use the PaymentGateway class in new contexts without modifying it.

## Liskov Substitution Principle (LSP)
Derived classes should be substitutable for their base classes.
In other words, if you have a class hierarchy where a subclass inherits from a base class, the subclass should be able to be used anywhere the base class is expected.

Example:

    public class Rectangle {
        private double width;
        private double height;
        
        public Rectangle(double width, double height) {
            this.width = width;
            this.height = height;
        }

        public double area() {
            return width * height;
        }
        
        public double perimeter() {
            return 2 * (width + height);
        }
    }

    public class Square extends Rectangle {
        public Square(double side) {
            super(side, side);
        }

        public double setSide(double side) {
            this.width = side;
            this.height = side;
        }
    }

    Rectangle rectangle = new Square(4);
    rectangle.setSide(5); // Error! Rectangle does not have a setSide() method

This violates LSP because the Square class is not substitutable for its base class Rectangle.

Solution:

    // Common interface for shapes
    interface Shape {
        double area();
        double perimeter();
    }

    // Rectangle class
    public class Rectangle implements Shape {
        protected double width;
        protected double height;

        public Rectangle(double width, double height) {
            this.width = width;
            this.height = height;
        }

        @Override
        public double area() {
            return width * height;
        }

        @Override
        public double perimeter() {
            return 2 * (width + height);
        }
    }

    // Square class
    public class Square implements Shape {
        private double side;

        public Square(double side) {
            this.side = side;
        }

        @Override
        public double area() {
            return side * side;
        }

        @Override
        public double perimeter() {
            return 4 * side;
        }
    }

    // Usage
    public class Main {
        public static void main(String[] args) {
            Rectangle rectangle = new Rectangle(4, 5);
            System.out.println("Rectangle Area: " + rectangle.area()); // Output: 20.0
            System.out.println("Rectangle Perimeter: " + rectangle.perimeter()); // Output: 18.0

            Square square = new Square(4);
            System.out.println("Square Area: " + square.area()); // Output: 16.0
            System.out.println("Square Perimeter: " + square.perimeter()); // Output: 16.0

            // You can still use the objects through the Shape interface
            Shape shape = new Square(5);
            System.out.println("Shape Area: " + shape.area()); // Output: 25.0
            System.out.println("Shape Perimeter: " + shape.perimeter()); // Output: 20.0
        }
    }

    

By following the Liskov Substitution Principle, we ensure that our subclass (Square) is substitutable for its base class (Rectangle).

##  Interface segregation principle

__Clients should not be forced to depend on interfaces they do not use.__
In other words, ISP suggests that we should break large, fat interfaces into smaller, more focused interfaces that meet the needs of specific clients. This way, clients are not forced to implement methods they don't need or use.

Violation:

    public interface Printer {
        void print();
        void scan();
        void fax();
    }

    public class PhotoPrinter implements Printer {
        @Override
        public void print() {
            // Print photo logic
        }

        @Override
        public void scan() {
            // No scan logic needed!
        }

        @Override
        public void fax() {
            // No fax logic needed!
        }
    }

In this example, the PhotoPrinter class is forced to implement methods it doesn't need or use (scan and fax). This violates ISP.

Solution:

    public interface Printable {
        void print();
    }

    public interface Scannable {
        void scan();
    }

    public interface Faxable {
        void fax();
    }

    public class PhotoPrinter implements Printable {
        @Override
        public void print() {
            // Print photo logic
        }
    }

By applying ISP, we've made the code more modular, flexible, and easier to maintain. Clients are no longer forced to depend on interfaces they don't use.

## Dependency inversion principle

__High-level modules should not depend on low-level modules. Both high-level and low-level modules should depend on abstractions.__
In other words, DIP suggests that we should decouple dependent components by introducing an abstraction layer between them. This abstraction layer can be an interface, an abstract class, or even a function.

Violation:

    public class Car {
        private GasolineEngine engine;

        public Car(GasolineEngine engine) {
            this.engine = engine;
        }

        public void start() {
            engine.start();
        }
    }

    public class GasolineEngine {
        public void start() {
            // Start engine logic
        }
    }

In this example, the Car class is tightly coupled to the GasolineEngine class. If we want to use a different engine type, like a DieselEngine, we'd have to modify the Car class which violates open closed principle also.

Solution:

    public interface Engine {
        void start();
    }

    public class Car {
        private Engine engine;

        public Car(Engine engine) {
            this.engine = engine;
        }

        public void start() {
            engine.start();
        }
    }

    public class GasolineEngine implements Engine {
        @Override
        public void start() {
            // Start engine logic
        }
    }

    public class DieselEngine implements Engine {
        @Override
        public void start() {
            // Start engine logic
        }
    }

By applying DIP, we've made the code more modular, flexible, and easier to maintain. High-level modules (Car) no longer depend on low-level modules (GasolineEngine); both depend on abstractions (Engine).
