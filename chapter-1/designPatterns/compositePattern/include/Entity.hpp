#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Component.hpp"
#include <iostream>

class Entity : public Component
{
private:
    /* data */
public:
    Entity(/* args */) {};
    ~Entity() {};
    void update() override {
        std::cout<< "Entity override update\n";
    }
};

#endif //ENTITY_HPP