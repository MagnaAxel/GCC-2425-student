#ifndef IWEAPON_HPP
#define IWEAPON_HPP

#include <string>

class IWeapon {
public:
    virtual ~IWeapon() = default;
    virtual std::string getDescription() const = 0;
    virtual int getDamage() const = 0;
};

#endif //IWEAPON_HPP