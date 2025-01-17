#ifndef ENCHANTMENTDECORATOR_HPP
#define ENCHANTMENTDECORATOR_HPP

#include <memory>
#include "WeaponUpgrade.hpp"

class EnchantmentDecorator : public WeaponUpgrade {
public:
    EnchantmentDecorator(std::shared_ptr<IWeapon> weapon) : WeaponUpgrade(std::move(weapon)) {}

    std::string getDescription() const override {
        return weapon->getDescription() + " enchant,";
    }

    int getDamage() const override {
        return weapon->getDamage() + DAMAGE;
    }
private:
    static constexpr int DAMAGE = 10;
};

#endif //ENCHANTMENTDECORATOR_HPP