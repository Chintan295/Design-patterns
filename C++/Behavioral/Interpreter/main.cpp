#include <iostream>
using namespace std;

// Abstract class for expressions
class Expression {
public:
    virtual int interpret() = 0;
};

// Terminal expression for numbers
class NumberExpression : public Expression {
private:
    int number;
public:
    NumberExpression(int number) {
        this->number = number;
    }
    int interpret() {
        return number;
    }
};

// Non-terminal expression for addition
class AdditionExpression : public Expression {
private:
    Expression* left;
    Expression* right;
public:
    AdditionExpression(Expression* left, Expression* right) {
        this->left = left;
        this->right = right;
    }
    int interpret() {
        return left->interpret() + right->interpret();
    }
};

// Non-terminal expression for subtraction
class SubtractionExpression : public Expression {
private:
    Expression* left;
    Expression* right;
public:
    SubtractionExpression(Expression* left, Expression* right) {
        this->left = left;
        this->right = right;
    }
    int interpret() {
        return left->interpret() - right->interpret();
    }
};

// Client code
int main() {
    // Create expressions
    Expression* two = new NumberExpression(2);
    Expression* three = new NumberExpression(3);
    Expression* addition = new AdditionExpression(two, three);
    Expression* five = new NumberExpression(5);
    Expression* subtraction = new SubtractionExpression(five, two);
    
    // Interpret expressions
    int result1 = addition->interpret();
    int result2 = subtraction->interpret();
    
    // Print results
    cout << "Result of 2+3: " << result1 << endl; // Output: 5
    cout << "Result of 5-2: " << result2 << endl; // Output: 3
    
    // Clean up memory
    delete two;
    delete three;
    delete addition;
    delete five;
    delete subtraction;
    
    return 0;
}