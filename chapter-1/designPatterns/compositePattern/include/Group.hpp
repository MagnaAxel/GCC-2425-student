#ifndef GROUP_HPP
#define GROUP_HPP

#include "Component.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

class Group : public Component
{
private:
    std::vector<std::shared_ptr<Component>> children;
public:
    Group(/* args */) {};
    ~Group() {};
    void update() override {
        std::cout<< "Group override update\n";
        for(auto& i : children) {
            i->update();
        }
    }
    void add(const std::shared_ptr<Component>& component) override {
        children.push_back(component);
    };
    void remove(const std::shared_ptr<Component>& component) override {
        children.erase(
            std::remove_if(children.begin(), children.end(),
                
                [&component](const std::shared_ptr<Component>& c) {
                    return c == component;
                }), children.end()
        );
    };
};

#endif //GROUP_HPP