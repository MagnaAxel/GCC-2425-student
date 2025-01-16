#ifndef WEAPONUPGRADE_HPP
#define WEAPONUPGRADE_HPP

#include <memory>
#include "IWeapon.hpp"

class WeaponUpgrade : public IWeapon {
protected:
    std::shared_ptr<IWeapon> weapon;
public:
    WeaponUpgrade(std::shared_ptr<IWeapon> weapon) : weapon(std::move(weapon)) {}
    virtual ~WeaponUpgrade() = default;

    std::string getDescription() const override {
        return weapon->getDescription();
    }

    int getDamage() const override {
        return weapon->getDamage();
    }
};

#endif //WEAPONUPGRADE_HPP