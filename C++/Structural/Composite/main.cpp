#include<iostream>
// Component
class FileSystemComponent {
public:
    virtual void print() = 0;
};

// Leaf
class File : public FileSystemComponent {
private:
    std::string name;
public:
    File(std::string name) : name(name) {}
    void print() override {
        std::cout << "File: " << name << std::endl;
    }
};

// Composite
class Folder : public FileSystemComponent {
private:
    std::string name;
    std::vector<FileSystemComponent*> components;
public:
    Folder(std::string name) : name(name) {}
    void add(FileSystemComponent* component) {
        components.push_back(component);
    }
    void print() override {
        std::cout << "Folder: " << name << std::endl;
        for (auto component : components) {
            component->print();
        }
    }
};

int main() {
    // Create folders
    Folder* rootFolder = new Folder("Root");
    Folder* documentsFolder = new Folder("Documents");
    Folder* imagesFolder = new Folder("Images");
    // Create files
    File* file1 = new File("example.txt");
    File* file2 = new File("image1.jpg");
    File* file3 = new File("image2.jpg");
    // Add files to folders
    documentsFolder->add(file1);
    imagesFolder->add(file2);
    imagesFolder->add(file3);
    // Add folders to root folder
    rootFolder->add(documentsFolder);
    rootFolder->add(imagesFolder);
    // Print file system structure
    rootFolder->print();
    return 0;
}