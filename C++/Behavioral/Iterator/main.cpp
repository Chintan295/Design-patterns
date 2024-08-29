#include <iostream>
#include <vector>

// Iterator interface
class Iterator
{
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
    virtual int currentItem() = 0;
};

// Concrete Iterator
class VectorIterator : public Iterator
{
private:
    std::vector<int> *vector_;
    int position_;

public:
    VectorIterator(std::vector<int> *vector) : vector_(vector), position_(0) {}
    void first() override { position_ = 0; }
    void next() override { position_++; }
    bool isDone() override { return position_ >= vector_->size(); }
    int currentItem() override { return (*vector_)[position_]; }
};

// Aggregate interface
class Aggregate
{
public:
    virtual Iterator *createIterator() = 0;
};

// Concrete Aggregate
class VectorAggregate : public Aggregate
{
private:
    std::vector<int> vector_;

public:
    VectorAggregate(std::vector<int> vector) : vector_(vector) {}
    Iterator *createIterator() override { return new VectorIterator(&vector_); }
};

int main()
{
    // Create a vector and add elements
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    
    // Create a VectorAggregate object
    VectorAggregate aggregate(v);

    // Create an Iterator object
    Iterator *iterator = aggregate.createIterator();

    // Traverse the vector using the iterator
    std::cout << "Traversing the vector using the iterator:" << std::endl;
    while (!iterator->isDone())
    {
        std::cout << iterator->currentItem() << std::endl;
        iterator->next();
    }

    // Delete the iterator to free memory
    delete iterator;

    return 0;
}