﻿#include "World.h"

void dead_check(World* world)
{

    std::vector<NPC*>::iterator f = world->my_world.begin();
    while (f != world->my_world.end())
    {

        if ((*f)->live <= 0)
        {
            std::cout << (*f)->get_name() << "已经阵亡\n";
            world->my_world.erase(f);
            f = world->my_world.begin();
            continue;
        }
        f++;
    }
}

void World::use_one_card()
{
}

void World::add_NPC(NPC*npc)
{
    my_world.push_back(npc);
    //time_npc++;
    npc->world = this;
}

void World::combat_readiness()
{

    std::vector<NPC*>::iterator f = my_world.begin();
    while (f != my_world.end())
    {
        (*f)->combat_readiness();
        f++;
    } 
    dead_check(this);
}

void World::by_timepass()
{
    std::vector<NPC*>::iterator f = my_world.begin();
    while (f != my_world.end())
    {
        (*f)->by_timepass();
        f++;
    } 
    dead_check(this);
    
}

void World::by_timebegin()
{
    std::vector<NPC*>::iterator f = my_world.begin();
    
    while (f != my_world.end())
    {
        (*f)->by_timebegin();
        f++;
    }
    dead_check(this);
}

void World::init(void(*ptr)(World* self, World* enemies))
{
    p = ptr;
    if(handtiles==nullptr)
        handtiles = new HandTiles(*this, max_npc);
    else {
        delete handtiles;
        handtiles = new HandTiles(*this, max_npc);
    }
    if (!my_world.size())
        throw "Error!，角色尚未未导入";
    if (my_law==nullptr)
        std::cout << "Warning!，未设置律" << std::endl;
    handtiles = new HandTiles(*this,max_npc);
    combat_readiness();
}

CardBase* World::request_card()
{
    NPC* user = my_world[get_randomss() % my_world.size()];
    return user->skills[get_randomss() % (user->skills.size() - 1)]->clone(); // 除去大招
}

void World::use_card()
{


}

NPC* World::select_sub_target(World*enemies,NPC* main_t)
{
    if (enemies->my_world.size() <= 1) {
        return nullptr;
    }
    while (true) {
        int index = rand() % enemies->my_world.size();
        if (enemies->my_world[index] != main_t) {
            return enemies->my_world[index];
        }
    }
}