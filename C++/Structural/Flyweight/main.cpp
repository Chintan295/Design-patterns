#include <iostream>
#include <string>
#include <unordered_map>

// Flyweight class
class Character {
private:
    char symbol; // intrinsic data
    int font;
    int size;
public:
    Character(char symbol, int font, int size) : symbol(symbol), font(font), size(size) {}
    void display(std::string color) { // extrinsic data
        std::cout << "Character: " << symbol << ", Font: " << font << ", Size: " << size << ", Color: " << color << std::endl;
    }
};

// Flyweight Factory class
class CharacterFactory {
private:
    std::unordered_map<std::string, Character*> characters;
public:
    Character* getCharacter(char symbol, int font, int size) {
        std::string key = std::to_string(symbol) + std::to_string(font) + std::to_string(size);
        if (characters.find(key) == characters.end()) {
            characters[key] = new Character(symbol, font, size);
        }
        return characters[key];
    }
};

int main() {
    CharacterFactory* factory = new CharacterFactory();
    Character* c1 = factory->getCharacter('A', 12, 24);
    c1->display("Red"); // extrinsic data
    Character* c2 = factory->getCharacter('A', 12, 24);
    c2->display("Blue"); // extrinsic data
    delete factory;
    return 0;
}