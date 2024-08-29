#include <iostream>

// Command interface
class Command {
public:
    virtual void execute() = 0;
};

// Receiver
class Light {
public:
    void on() {
        std::cout << "Light is on" << std::endl;
    }
    void off() {
        std::cout << "Light is off" << std::endl;
    }
};

// Concrete Command
class LightOnCommand : public Command {
private:
    Light* light_;
public:
    LightOnCommand(Light* light) : light_(light) {}
    void execute() override {
        light_->on();
    }
};

class LightOffCommand : public Command {
private:
    Light* light_;
public:
    LightOffCommand(Light* light) : light_(light) {}
    void execute() override {
        light_->off();
    }
};

// Invoker
class RemoteControl {
private:
    Command* command_;
public:
    RemoteControl(Command* command) : command_(command) {}
    void pressButton() {
        command_->execute();
    }
};

int main() {
    Light* light = new Light();
    Command* lightOnCommand = new LightOnCommand(light);
    Command* lightOffCommand = new LightOffCommand(light);
    RemoteControl* remoteControl = new RemoteControl(lightOnCommand);
    remoteControl->pressButton(); // Output: Light is on
    remoteControl = new RemoteControl(lightOffCommand);
    remoteControl->pressButton(); // Output: Light is off
    return 0;
}