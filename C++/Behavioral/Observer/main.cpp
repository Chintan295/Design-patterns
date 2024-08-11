#include <iostream>
#include <vector>
#include <string>

// Observer interface
class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

// Subject interface
class Subject {
public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify(const std::string& message) = 0;
};

// Concrete Subject
class NewsAgency : public Subject {
private:
    std::vector<Observer*> observers_;
public:
    void attach(Observer* observer) override {
        observers_.push_back(observer);
    }
    void detach(Observer* observer) override {
        observers_.erase(std::remove(observers_.begin(), observers_.end(), observer), observers_.end());
    }
    void notify(const std::string& message) override {
        for (auto observer : observers_) {
            observer->update(message);
        }
    }
};

// Concrete Observer
class Subscriber : public Observer {
private:
    std::string name_;
public:
    Subscriber(const std::string& name) : name_(name) {}
    void update(const std::string& message) override {
        std::cout << name_ << " received news: " << message << std::endl;
    }
};

int main() {
    NewsAgency agency;
    Subscriber subscriber1("John");
    Subscriber subscriber2("Alice");

    agency.attach(&subscriber1);
    agency.attach(&subscriber2);

    agency.notify("Breaking News: Observer Pattern is awesome!");

    agency.detach(&subscriber1);

    agency.notify("Latest News: C++ is powerful!");

    return 0;
}