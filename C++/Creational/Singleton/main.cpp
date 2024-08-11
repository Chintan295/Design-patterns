#include <iostream>
#include <string>

class Vehicle
{
public:
    Vehicle(const std::string &licensePlate) : licensePlate_(licensePlate) {}
    std::string getLicensePlate() const
    {
        return licensePlate_;
    }

private:
    std::string licensePlate_;
};

class VehicleRegistry
{
public:
    static VehicleRegistry &getInstance()
    {
        static VehicleRegistry instance;
        return instance;
    }
    void registerVehicle(const Vehicle &vehicle)
    {
        vehicles_.push_back(vehicle);
    }
    void deregisterVehicle(const Vehicle &vehicle)
    {
        // Find and remove the vehicle from the registry
    }
    void displayVehicles() const
    {
        for (const auto &vehicle : vehicles_)
        {
            std::cout << vehicle.getLicensePlate() << std::endl;
        }
    }

private:
    VehicleRegistry() {}                                          // Private constructor to prevent instantiation
    VehicleRegistry(const VehicleRegistry &) = delete;            // Delete copy constructor
    VehicleRegistry &operator=(const VehicleRegistry &) = delete; // Delete assignment operator
    std::vector<Vehicle> vehicles_;
};

int main()
{
    VehicleRegistry &registry = VehicleRegistry::getInstance();
    registry.registerVehicle(Vehicle("ABC123"));
    registry.registerVehicle(Vehicle("DEF456"));
    registry.displayVehicles();
    return 0;
}