#include <iostream>

// Component
class Beverage {
public:
    virtual int cost() = 0;
};

// Concrete Component
class Espresso : public Beverage {
public:
    int cost() override {
        return 10;
    }
};

// Decorator
class CondimentDecorator : public Beverage {
protected:
    Beverage* beverage;
public:
    CondimentDecorator(Beverage* beverage) : beverage(beverage) {}
    int cost() override {
        return beverage->cost();
    }
};

// Concrete Decorator: Mocha
class MochaDecorator : public CondimentDecorator {
public:
    MochaDecorator(Beverage* beverage) : CondimentDecorator(beverage) {}
    int cost() override {
        return CondimentDecorator::cost() + 20;
    }
};

// Concrete Decorator: Whip
class WhipDecorator : public CondimentDecorator {
public:
    WhipDecorator(Beverage* beverage) : CondimentDecorator(beverage) {}
    int cost() override {
        return CondimentDecorator::cost() + 30;
    }
};

int main() {
    // Create an espresso
    Beverage* espresso = new Espresso();
    std::cout << "Espresso cost: " << espresso->cost() << std::endl;
    
    // Create a mocha espresso
    Beverage* mochaEspresso = new MochaDecorator(espresso);
    std::cout << "Mocha Espresso cost: " << mochaEspresso->cost() << std::endl;
    
    // Create a double mocha espresso
    Beverage* doubleMochaEspresso = new MochaDecorator(mochaEspresso);
    std::cout << "Double Mocha Espresso cost: " << doubleMochaEspresso->cost() << std::endl;
    
    // Create a double mocha espresso with whip
    Beverage* doubleMochaWhipEspresso = new WhipDecorator(doubleMochaEspresso);
    std::cout << "Double Mocha Whip Espresso cost: " << doubleMochaWhipEspresso->cost() << std::endl;
    
    delete espresso;
    delete mochaEspresso;
    delete doubleMochaEspresso;
    delete doubleMochaWhipEspresso;
    
    return 0;
}