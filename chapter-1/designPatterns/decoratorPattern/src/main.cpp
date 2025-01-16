#include <memory>
#include <iostream>

#include "Sword.hpp"
#include "SharpeningDecorator.hpp"
#include "EnchantmentDecorator.hpp"


int main(int argc, char **argv) 
{
    std::shared_ptr<IWeapon> sword = std::make_shared<Sword>();

    for (size_t i = 1; i < size_t(argc); i++)
    {
        if (std::string(argv[i]) == "sharp")
        {
            sword = std::make_shared<SharpeningDecorator>(sword);
        }
        else if (std::string(argv[i]) == "enchant")
        {
            sword = std::make_shared<EnchantmentDecorator>(sword);
        }
    }
    std::cout << sword->getDescription() << " atk:  " << sword->getDamage() << std::endl;
}