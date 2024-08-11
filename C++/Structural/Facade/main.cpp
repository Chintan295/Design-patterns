#include <iostream>

// Subsystem classes
class CPU
{
public:
    void freeze() { std::cout << "CPU: Freezing..." << std::endl; }
    void jump(long position) { std::cout << "CPU: Jumping to position " << position << std::endl; }
    void execute() { std::cout << "CPU: Executing..." << std::endl; }
};

class Memory
{
public:
    void load(long position, long data) { std::cout << "Memory: Loading data " << data << " at position " << position << std::endl; }
};

class HardDrive
{
public:
    void read(long sector, long data) { std::cout << "HardDrive: Reading data " << data << " from sector " << sector << std::endl; }
};

// Facade class
class ComputerFacade
{
private:
    CPU *cpu;
    Memory *memory;
    HardDrive *hardDrive;

public:
    ComputerFacade(CPU *cpu, Memory *memory, HardDrive *hardDrive) : cpu(cpu), memory(memory), hardDrive(hardDrive) {}
    void startComputer()
    {
        cpu->freeze();
        memory->load(0, 0);
        hardDrive->read(0, 0);
        cpu->jump(0);
        cpu->execute();
    }
};

int main()
{
    // Create subsystem objects
    CPU *cpu = new CPU();
    Memory *memory = new Memory();
    HardDrive *hardDrive = new HardDrive();

    // Create facade object
    ComputerFacade *computer = new ComputerFacade(cpu, memory, hardDrive);

    // Use facade to start computer
    computer->startComputer();

    delete cpu;
    delete memory;
    delete hardDrive;
    delete computer;

    return 0;
}