#pragma once
#include "gl.hpp"
#include "disk.hpp"
#include "rods.hpp"
#include "land.hpp"
#include <stack>
#include <array>

class Environment{
private:
    std::array<Disk, 8> disks;
    std::array<std::stack<Disk *>, 3> stacks_array;
    std::array<Rod, 3> rods;
    Land land;
public:
    Environment();
};