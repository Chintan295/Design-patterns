#include <iostream>
#include <vector>

// Vehicle class
class Vehicle {
public:
    virtual ~Vehicle() {}
    virtual void doSomething() = 0;
};

// Car class
class Car : public Vehicle {
public:
    void doSomething() override {
        std::cout << "Driving a car." << std::endl;
    }
};

// Truck class
class Truck : public Vehicle {
public:
    void doSomething() override {
        std::cout << "Driving a truck." << std::endl;
    }
};

// VehiclePool class
class VehiclePool {
public:
    Vehicle* borrowVehicle();
    void returnVehicle(Vehicle* vehicle);
private:
    std::vector<Vehicle*> vehicles_;
};

// VehiclePool implementation
Vehicle* VehiclePool::borrowVehicle() {
    if (vehicles_.empty()) {
        return new Car();
    } else {
        Vehicle* vehicle = vehicles_.back();
        vehicles_.pop_back();
        return vehicle;
    }
}

void VehiclePool::returnVehicle(Vehicle* vehicle) {
    vehicles_.push_back(vehicle);
}

// Client code
int main() {
    VehiclePool pool;
    Vehicle* car = pool.borrowVehicle();
    car->doSomething();
    pool.returnVehicle(car);
    Vehicle* truck = pool.borrowVehicle();
    truck->doSomething();
    pool.returnVehicle(truck);
    return 0;
}