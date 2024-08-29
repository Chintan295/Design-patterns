#include <iostream>
#include <string>

// Forward declarations
class RedState;
class YellowState;
class GreenState;
class State;

// Context class
class TrafficLight {
public:
    TrafficLight();
    void timerExpired();
    void pedestrianButtonPressed();
    void changeState(State* state);

private:
    State* currentState;
};

// State interface
class State {
public:
    virtual void timerExpired(TrafficLight* trafficLight) = 0;
    virtual void pedestrianButtonPressed(TrafficLight* trafficLight) = 0;
};

// Concrete states
class RedState : public State {
public:
    void timerExpired(TrafficLight* trafficLight) override;
    void pedestrianButtonPressed(TrafficLight* trafficLight) override;
};

class YellowState : public State {
public:
    void timerExpired(TrafficLight* trafficLight) override;
    void pedestrianButtonPressed(TrafficLight* trafficLight) override;
};

class GreenState : public State {
public:
    void timerExpired(TrafficLight* trafficLight) override;
    void pedestrianButtonPressed(TrafficLight* trafficLight) override;
};

// Implementation
TrafficLight::TrafficLight() : currentState(new RedState()) {}

void TrafficLight::timerExpired() {
    currentState->timerExpired(this);
}

void TrafficLight::pedestrianButtonPressed() {
    currentState->pedestrianButtonPressed(this);
}

void TrafficLight::changeState(State* state) {
    currentState = state;
}

void RedState::timerExpired(TrafficLight* trafficLight) {
    std::cout << "Red light: timer expired. Turning green." << std::endl;
    trafficLight->changeState(new GreenState());
}

void RedState::pedestrianButtonPressed(TrafficLight* trafficLight) {
    std::cout << "Red light: pedestrian button pressed. Doing nothing." << std::endl;
}

void YellowState::timerExpired(TrafficLight* trafficLight) {
    std::cout << "Yellow light: timer expired. Turning red." << std::endl;
    trafficLight->changeState(new RedState());
}

void YellowState::pedestrianButtonPressed(TrafficLight* trafficLight) {
    std::cout << "Yellow light: pedestrian button pressed. Doing nothing." << std::endl;
}

void GreenState::timerExpired(TrafficLight* trafficLight) {
    std::cout << "Green light: timer expired. Turning yellow." << std::endl;
    trafficLight->changeState(new YellowState());
}

void GreenState::pedestrianButtonPressed(TrafficLight* trafficLight) {
    std::cout << "Green light: pedestrian button pressed. Turning red." << std::endl;
    trafficLight->changeState(new RedState());
}

int main() {
    TrafficLight trafficLight;

    trafficLight.timerExpired(); // Red light: timer expired. Turning green.
    trafficLight.pedestrianButtonPressed(); // Green light: pedestrian button pressed. Turning red.
    trafficLight.timerExpired(); // Red light: timer expired. Turning green.
    trafficLight.timerExpired(); // Green light: timer expired. Turning yellow.
    trafficLight.pedestrianButtonPressed(); // Yellow light: pedestrian button pressed. Doing nothing.
    trafficLight.timerExpired(); // Yellow light: timer expired. Turning red.

    return 0;
}