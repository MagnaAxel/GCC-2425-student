#ifndef SHARPENINGDECORATOR_HPP
#define SHARPENINGDECORATOR_HPP

#include <memory>
#include "WeaponUpgrade.hpp"

class SharpeningDecorator : public WeaponUpgrade {
public:
    SharpeningDecorator(std::shared_ptr<IWeapon> weapon) : WeaponUpgrade(std::move(weapon)) {}

    std::string getDescription() const override {
        return weapon->getDescription() + " sharp,";
    }

    int getDamage() const override {
        return weapon->getDamage() + DAMAGE;
    }
private:
    static constexpr int DAMAGE = 5;
};

#endif //SHARPENINGDECORATOR_HPP