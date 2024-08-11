#include <iostream>

// Strategy interface
class PaymentStrategy {
public:
    virtual void pay(double amount) = 0;
};

// Concrete Strategy 1: Credit Card
class CreditCardStrategy : public PaymentStrategy {
public:
    void pay(double amount) override {
        std::cout << "Paid $" << amount << " using credit card." << std::endl;
    }
};

// Concrete Strategy 2: PayPal
class PayPalStrategy : public PaymentStrategy {
public:
    void pay(double amount) override {
        std::cout << "Paid $" << amount << " using PayPal." << std::endl;
    }
};

// Concrete Strategy 3: GPay
class GPayStrategy : public PaymentStrategy {
public:
    void pay(double amount) override {
        std::cout << "Paid $" << amount << " using GPay." << std::endl;
    }
};

// Context: PaymentProcessor
class PaymentProcessor {
private:
    PaymentStrategy* strategy_;
public:
    PaymentProcessor(PaymentStrategy* strategy) : strategy_(strategy) {}
    void setStrategy(PaymentStrategy* strategy) {
        strategy_ = strategy;
    }
    void processPayment(double amount) {
        strategy_->pay(amount);
    }
};

int main() {
    // Create strategies
    PaymentStrategy* creditCard = new CreditCardStrategy();
    PaymentStrategy* payPal = new PayPalStrategy();
    PaymentStrategy* gPay = new GPayStrategy();

    // Create payment processor with credit card strategy
    PaymentProcessor paymentProcessor(creditCard);
    paymentProcessor.processPayment(100.0); // Output: Paid $100 using credit card.

    // Change strategy to PayPal
    paymentProcessor.setStrategy(payPal);
    paymentProcessor.processPayment(200.0); // Output: Paid $200 using PayPal.

    // Change strategy to GPay
    paymentProcessor.setStrategy(gPay);
    paymentProcessor.processPayment(200.0); // Output: Paid $200 using GPay.

    // Clean up
    delete creditCard;
    delete payPal;
    delete gPay;

    return 0;
}