#include <iostream>
#include <string>

// Abstract prototype class
class VehiclePrototype {
public:
    virtual ~VehiclePrototype() {}
    virtual VehiclePrototype* clone() = 0;
    virtual void drive() = 0;
};

// Concrete prototype class
class CarPrototype : public VehiclePrototype {
public:
    CarPrototype() {}
    VehiclePrototype* clone() override {
        return new CarPrototype(*this);
    }
    void drive() override {
        std::cout << "Driving a car." << std::endl;
    }
};

// Concrete prototype class
class TruckPrototype : public VehiclePrototype {
public:
    TruckPrototype() {}
    VehiclePrototype* clone() override {
        return new TruckPrototype(*this);
    }
    void drive() override {
        std::cout << "Driving a truck." << std::endl;
    }
};

// Client code
int main() {
    // Create a prototype car object
    VehiclePrototype* carPrototype = new CarPrototype();
    // Create a new car object by copying the prototype
    VehiclePrototype* newCar = carPrototype->clone();
    // Use the new car object
    newCar->drive();
    // Create a prototype truck object
    VehiclePrototype* truckPrototype = new TruckPrototype();
    // Create a new truck object by copying the prototype
    VehiclePrototype* newTruck = truckPrototype->clone();
    // Use the new truck object
    newTruck->drive();
    // Clean up
    delete carPrototype;
    delete newCar;
    delete truckPrototype;
    delete newTruck;
    return 0;
}