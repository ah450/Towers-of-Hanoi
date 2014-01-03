#pragma once
#include "gl.hpp"
#include "disk.hpp"
#include "rods.hpp"
#include "land.hpp"
#include <stack>
#include <array>

enum class rod_selected{
    left, middle, right
};

enum class direction{
    up, down, left, right, in, out
};

class Environment{
private:
    Land land;
    std::array<Rod, 3> rods;
    std::array<Disk, 8> disks;
    std::array<std::stack<Disk *>, 3> stacks_array;
    bool current_selected;
    Disk * selected;
public:
    Environment();
    void draw();
    bool select(rod_selected);
    void move(direction);
    void unselect();
    void highLight(rod_selected);
};