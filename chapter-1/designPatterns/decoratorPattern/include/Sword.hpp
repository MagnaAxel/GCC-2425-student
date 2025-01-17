#ifndef SWORD_HPP
#define SWORD_HPP

#include "IWeapon.hpp"

class Sword : public IWeapon {
public:
    std::string getDescription() const override {
        return "Sword";
    }

    int getDamage() const override {
        return DAMAGE;
    }
    
private:
    static constexpr int DAMAGE = 10;
};

#endif //SWORD_HPP