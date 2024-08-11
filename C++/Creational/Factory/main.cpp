#include <iostream>
#include <string>

// Product interface
class Vehicle {
public:
    virtual void startEngine() = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
};

// Concrete product 1
class Car : public Vehicle {
public:
    void startEngine() override {
        std::cout << "Car engine started." << std::endl;
    }
    void accelerate() override {
        std::cout << "Car accelerated." << std::endl;
    }
    void brake() override {
        std::cout << "Car braked." << std::endl;
    }
};

// Concrete product 2
class Truck : public Vehicle {
public:
    void startEngine() override {
        std::cout << "Truck engine started." << std::endl;
    }
    void accelerate() override {
        std::cout << "Truck accelerated." << std::endl;
    }
    void brake() override {
        std::cout << "Truck braked." << std::endl;
    }
};

// Factory interface
class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0;
};

// Concrete factory 1
class CarFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Car();
    }
};

// Concrete factory 2
class TruckFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Truck();
    }
};

// Client code
int main() {
    // Create a Car factory
    VehicleFactory* carFactory = new CarFactory();
    // Create a Car using the factory
    Vehicle* car = carFactory->createVehicle();
    // Use the Car
    car->startEngine();
    car->accelerate();
    car->brake();
    // Clean up
    delete car;
    delete carFactory;

    // Create a Truck factory
    VehicleFactory* truckFactory = new TruckFactory();
    // Create a Truck using the factory
    Vehicle* truck = truckFactory->createVehicle();
    // Use the Truck
    truck->startEngine();
    truck->accelerate();
    truck->brake();
    // Clean up
    delete truck;
    delete truckFactory;

    return 0;
}