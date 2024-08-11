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

// Factory class
class DocumentFactory {
public:
    static Document* createDocument(const std::string& type) {
        if (type == "PDF") {
            return new PDFDocument();
        } else if (type == "Text") {
            return new TextDocument();
        } else {
            return nullptr;
        }
    }
};

int main() {
    // Create objects using the factory
    Document* pdfDoc = DocumentFactory::createDocument("PDF");
    Document* textDoc = DocumentFactory::createDocument("Text");

    // Call template method
    pdfDoc->print();
    textDoc->print();

    // Clean up
    delete pdfDoc;
    delete textDoc;

    return 0;
}