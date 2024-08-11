#include <iostream>

// Abstract base class
class Document {
public:
    void print() {
        open();
        printContent();
        close();
    }
    virtual void open() = 0;
    virtual void printContent() = 0;
    virtual void close() = 0;
};

// Concrete class 1
class PDFDocument : public Document {
public:
    void open() override {
        std::cout << "Opening PDF document." << std::endl;
    }
    void printContent() override {
        std::cout << "Printing PDF content." << std::endl;
    }
    void close() override {
        std::cout << "Closing PDF document." << std::endl;
    }
};

// Concrete class 2
class TextDocument : public Document {
public:
    void open() override {
        std::cout << "Opening text document." << std::endl;
    }
    void printContent() override {
        std::cout << "Printing text content." << std::endl;
    }
    void close() override {
        std::cout << "Closing text document." << std::endl;
    }
};

int main() {
    // Create objects
    Document* pdfDoc = new PDFDocument();
    Document* textDoc = new TextDocument();

    // Call template method
    pdfDoc->print();
    textDoc->print();

    // Clean up
    delete pdfDoc;
    delete textDoc;

    return 0;
}