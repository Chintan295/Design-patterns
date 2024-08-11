#include <iostream>

// Implementor
class Color {
public:
    virtual void applyColor() = 0;
};

// Concrete Implementor 1
class RedColor : public Color {
public:
    void applyColor() override {
        std::cout << "Applying red color." << std::endl;
    }
};

// Concrete Implementor 2
class BlueColor : public Color {
public:
    void applyColor() override {
        std::cout << "Applying blue color." << std::endl;
    }
};

// Abstraction
class Shape {
protected:
    Color* color;
public:
    Shape(Color* c) : color(c) {}
    virtual void draw() = 0;
    void setColor(Color* c) {
        color = c;
    }
};

// Refined Abstraction 1
class Circle : public Shape {
public:
    Circle(Color* c) : Shape(c) {}
    void draw() override {
        std::cout << "Drawing a circle. ";
        color->applyColor();
    }
};

// Refined Abstraction 2
class Square : public Shape {
public:
    Square(Color* c) : Shape(c) {}
    void draw() override {
        std::cout << "Drawing a square. ";
        color->applyColor();
    }
};

int main() {
    // Create implementors
    Color* red = new RedColor();
    Color* blue = new BlueColor();

    // Create abstractions
    Shape* redCircle = new Circle(red);
    Shape* blueSquare = new Square(blue);

    // Use the bridge
    redCircle->draw();
    blueSquare->draw();

    // Change color of the circle
    redCircle->setColor(blue);
    redCircle->draw();

    // Clean up
    delete red;
    delete blue;
    delete redCircle;
    delete blueSquare;

    return 0;
}