#include <iostream>
#include <string>

// Abstract product A
class Engine
{
public:
    virtual void start() = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
};

// Concrete product A1
class CarEngine : public Engine
{
public:
    void start() override
    {
        std::cout << "Car engine started." << std::endl;
    }
    void accelerate() override
    {
        std::cout << "Car accelerated." << std::endl;
    }
    void brake() override
    {
        std::cout << "Car braked." << std::endl;
    }
};

// Concrete product A2
class TruckEngine : public Engine
{
public:
    void start() override
    {
        std::cout << "Truck engine started." << std::endl;
    }
    void accelerate() override
    {
        std::cout << "Truck accelerated." << std::endl;
    }
    void brake() override
    {
        std::cout << "Truck braked." << std::endl;
    }
};

// Concrete product A3
class BusEngine : public Engine
{
public:
    void start() override
    {
        std::cout << "Bus engine started." << std::endl;
    }
    void accelerate() override
    {
        std::cout << "Bus accelerated." << std::endl;
    }
    void brake() override
    {
        std::cout << "Bus braked." << std::endl;
    }
};

// Abstract product B
class Transmission
{
public:
    virtual void shiftGear() = 0;
};

// Concrete product B1
class CarTransmission : public Transmission
{
public:
    void shiftGear() override
    {
        std::cout << "Car transmission shifted gear." << std::endl;
    }
};

// Concrete product B2
class TruckTransmission : public Transmission
{
public:
    void shiftGear() override
    {
        std::cout << "Truck transmission shifted gear." << std::endl;
    }
};

// Concrete product B3
class BusTransmission : public Transmission
{
public:
    void shiftGear() override
    {
        std::cout << "Bus transmission shifted gear." << std::endl;
    }
};

// Abstract factory
class VehicleFactory
{
public:
    virtual Engine *createEngine() = 0;
    virtual Transmission *createTransmission() = 0;
};

// Concrete factory 1
class CarFactory : public VehicleFactory
{
public:
    Engine *createEngine() override
    {
        return new CarEngine();
    }
    Transmission *createTransmission() override
    {
        return new CarTransmission();
    }
};

// Concrete factory 2
class TruckFactory : public VehicleFactory
{
public:
    Engine *createEngine() override
    {
        return new TruckEngine();
    }
    Transmission *createTransmission() override
    {
        return new TruckTransmission();
    }
};

// Concrete factory 3
class BusFactory : public VehicleFactory
{
public:
    Engine *createEngine() override
    {
        return new BusEngine();
    }
    Transmission *createTransmission() override
    {
        return new BusTransmission();
    }
};

// Client code
int main()
{
    // Create a car factory
    VehicleFactory *carFactory = new CarFactory();
    // Create a car engine and transmission
    Engine *carEngine = carFactory->createEngine();
    Transmission *carTransmission = carFactory->createTransmission();
    // Use the car engine and transmission
    carEngine->start();
    carEngine->accelerate();
    carEngine->brake();
    carTransmission->shiftGear();
    // Clean up
    delete carEngine;
    delete carTransmission;
    delete carFactory;

    // Create a truck factory
    VehicleFactory *truckFactory = new TruckFactory();
    // Create a truck engine and transmission
    Engine *truckEngine = truckFactory->createEngine();
    Transmission *truckTransmission = truckFactory->createTransmission();
    // Use the truck engine and transmission
    truckEngine->start();
    truckEngine->accelerate();
    truckEngine->brake();
    truckTransmission->shiftGear();
    // Clean up
    delete truckEngine;
    delete truckTransmission;
    delete truckFactory;

    // Create a bus factory
    VehicleFactory *busFactory = new BusFactory();
    // Create a bus engine and transmission
    Engine *busEngine = busFactory->createEngine();
    Transmission *busTransmission = busFactory->createTransmission();
    // Use the bus engine and transmission
    busEngine->start();
    busEngine->accelerate();
    busEngine->brake();
    busTransmission->shiftGear();
    // Clean up
    delete busEngine;
    delete busTransmission;
    delete busFactory;

    return 0;
}