# Facade

## Problem
* Complex subsystems with multiple classes and interfaces
* Difficult to use and understand for clients
* Tight coupling between subsystems and clients

## Intent
* Provide a simplified interface to a complex subsystem
* Reduce dependencies and coupling between subsystems and clients
* Improve readability and usability of the subsystem

## Example
* The code demonstrates the Facade pattern by providing a simplified interface (ComputerFacade) to a complex subsystem (comprising CPU, Memory, and HardDrive classes). The facade class encapsulates the complexity of the subsystem and provides a single method (startComputer()) to interact with it.

![Facade](./facade_img.png)

## Advantages
* Simplifies the interface to a complex subsystem
* Reduces dependencies and coupling
* Improves readability and usability
* Provides a layer of abstraction

## Disadvantages
* May not provide a clear separation of concerns, violate single responsibility principle
* Can lead to a "god object"(Facade) that is difficult to maintain (Can be simplify using Facade of facade...)

## Real-world analogy:
A restaurant: The waiter (facade) provides a simple interface to the complex kitchen subsystem, allowing customers to order food without knowing the details of the kitchen operations.

## Resources
* [https://www.youtube.com/watch?v=GYaBXK54eLo](https://www.youtube.com/watch?v=GYaBXK54eLo)
