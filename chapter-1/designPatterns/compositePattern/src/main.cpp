#include "Entity.hpp"
#include "Group.hpp"

int main(int argc, char const *argv[])
{
    const std::shared_ptr<Entity> entity1 = std::make_shared<Entity>();
    const std::shared_ptr<Entity> entity2 = std::make_shared<Entity>();
    const std::shared_ptr<Entity> entity3 = std::make_shared<Entity>();
    const std::shared_ptr<Entity> entity4 = std::make_shared<Entity>();
    const std::shared_ptr<Entity> entity5 = std::make_shared<Entity>();
    const std::shared_ptr<Group> group1 = std::make_shared<Group>();

    group1->add(entity1);
    group1->add(entity2);
    group1->add(entity3);
    group1->add(entity4);
    group1->add(entity5);

    group1->update();

    group1->remove(entity5);

    group1->update();

    return 0;
}
