#include <iostream>
#include <string>

// Vehicle class
class Vehicle
{
public:
    void setWheels(int wheels) { this->wheels = wheels; }
    void setEngine(std::string engine) { this->engine = engine; }
    void setColor(std::string color) { this->color = color; }
    void setFrame(std::string frame) { this->frame = frame; }
    void setDoors(int doors) { this->doors = doors; }
    void display()
    {
        std::cout << "Wheels: " << wheels << std::endl;
        std::cout << "Engine: " << engine << std::endl;
        std::cout << "Color: " << color << std::endl;
        std::cout << "Frame: " << frame << std::endl;
        std::cout << "Doors: " << doors << std::endl;
    }

private:
    int wheels;
    std::string engine;
    std::string color;
    std::string frame;
    int doors;
};

// Construction is seperated from Vehicle object representation
// VehicleBuilder class
class VehicleBuilder
{
public:
    virtual void buildWheels() = 0;
    virtual void buildEngine() = 0;
    virtual void buildColor() = 0;
    virtual void buildFrame() = 0;
    virtual void buildDoors() = 0;
    virtual Vehicle *getVehicle() = 0;
};

// Increase reusablity when car object needs to be created multiple times within a project
// CarBuilder class
class CarBuilder : public VehicleBuilder
{
public:
    void buildWheels() { vehicle->setWheels(4); }
    void buildEngine() { vehicle->setEngine("V8"); }
    void buildColor() { vehicle->setColor("Blue"); }
    void buildFrame() { vehicle->setFrame("Sedan"); }
    void buildDoors() { vehicle->setDoors(4); }
    Vehicle *getVehicle() { return vehicle; }

private:
    Vehicle *vehicle = new Vehicle();
};

// Director class
class Director
{
public:
    void construct(VehicleBuilder *builder)
    {
        builder->buildWheels();
        builder->buildEngine();
        builder->buildColor();
        builder->buildFrame();
        builder->buildDoors();
    }
};

int main()
{
    // Create a car builder
    CarBuilder carBuilder;
    // Create a director
    Director director;
    // Construct a car without passing parameters
    director.construct(&carBuilder);
    // Get the constructed car
    Vehicle *car = carBuilder.getVehicle();
    // Display the car's attributes
    car->display();
    return 0;
}