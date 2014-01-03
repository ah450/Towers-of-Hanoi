#pragma once
#include "gl.hpp"
#include "disk.hpp"
#include "rods.hpp"
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
    std::array<Rod, 3> rods;
    std::array<Disk, 8> disks;
    std::array<std::stack<Disk *>, 3> stacks_array;
    bool current_selected;
    Disk * selected; 
    int selected_rod;
    Point last_point;
public:
    unsigned int move_counter;
    Environment();
    void draw();
    bool select(rod_selected);
    void move(direction);
    void unselect();
    void highLight(rod_selected);
    bool should_move_back();
    void apply_gravity();
    bool can_move(Disk&);
};