#include <iostream>
#include <string>

// Handler interface
class Handler {
public:
    virtual void processOrder(const std::string& customer, const std::string& product, double price) = 0;
    void setNextHandler(Handler* nextHandler) { this->nextHandler = nextHandler; }
protected:
    Handler* nextHandler = nullptr;
};

// Concrete Handler 5: Order Handler
class OrderHandler : public Handler {
public:
    void processOrder(const std::string& customer, const std::string& product, double price) override {
        std::cout << "Order processed. Total: $" << price << std::endl;
        std::cout << "Confirmation email sent to " << customer << std::endl;
    }
};

// Concrete Handler 4: Tax Handler
class TaxHandler : public Handler {
public:
    void processOrder(const std::string& customer, const std::string& product, double price) override {
        double tax = price * 0.08;
        std::cout << "Tax: $" << tax << std::endl;
        if (nextHandler != nullptr) {
            nextHandler->processOrder(customer, product, price + tax);
        }
    }
};


// Concrete Handler 3: Shipping Handler
class ShippingHandler : public Handler {
public:
    void processOrder(const std::string& customer, const std::string& product, double price) override {
        if (customer == "InternationalCustomer") {
            std::cout << "Shipping not available to international customers." << std::endl;
        } else {
            if (nextHandler != nullptr) {
                nextHandler->processOrder(customer, product, price);
            }
        }
    }
};

// Concrete Handler 2: Inventory Handler
class InventoryHandler : public Handler {
public:
    void processOrder(const std::string& customer, const std::string& product, double price) override {
        if (product == "ProductA") {
            std::cout << "Product out of stock." << std::endl;
        } else {
            if (nextHandler != nullptr) {
                nextHandler->processOrder(customer, product, price);
            }
        }
    }
};

// Concrete Handler 1: Payment Handler
class PaymentHandler : public Handler {
public:
    void processOrder(const std::string& customer, const std::string& product, double price) override {
        if (price < 100) {
            std::cout << "Payment method not accepted for orders under $100." << std::endl;
        } else {
            if (nextHandler != nullptr) {
                nextHandler->processOrder(customer, product, price);
            }
        }
    }
};

int main() {
    Handler* paymentHandler = new PaymentHandler();
    Handler* inventoryHandler = new InventoryHandler();
    Handler* shippingHandler = new ShippingHandler();
    Handler* taxHandler = new TaxHandler();
    Handler* orderHandler = new OrderHandler();

    paymentHandler->setNextHandler(inventoryHandler);
    inventoryHandler->setNextHandler(shippingHandler);
    shippingHandler->setNextHandler(taxHandler);
    taxHandler->setNextHandler(orderHandler);

    paymentHandler->processOrder("JohnDoe", "ProductB", 150); // Order processed
    paymentHandler->processOrder("JaneDoe", "ProductA", 50); // Product out of stock
    paymentHandler->processOrder("InternationalCustomer", "ProductB", 100); // Shipping not available

    delete paymentHandler;
    delete inventoryHandler;
    delete shippingHandler;
    delete taxHandler;
    delete orderHandler;

    return 0;
}