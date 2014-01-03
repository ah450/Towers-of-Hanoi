#include "../include/environment.hpp"

Environment::Environment() : 
    land({8}), 
    rods({
        Rod({-7.0,0.0,0.0},{1.0,0.0,0.0,1.0f}),
        Rod({0.0,0.0,0.0},{1.0,0.0,0.0,1.0f}),
        Rod({7.0,0.0,0.0},{1.0,0.0,0.0,1.0f})}), 
    disks({
        Disk({-7,-5,0},{0.0f, 1.0f, 0.0f, 1.0f},0.35,2.75),
        Disk({-7,-4,0},{0.0f, 1.0f, 0.0f, 1.0f},0.35,2.5),
        Disk({-7,-3,0},{0.0f, 1.0f, 0.0f, 1.0f},0.35,2.25),
        Disk({-7,-2,0},{0.0f, 1.0f, 0.0f, 1.0f},0.35,2),
        Disk({-7,-1,0},{0.0f, 1.0f, 0.0f, 1.0f},0.35,1.75),
        Disk({-7,0,0},{0.0f, 1.0f, 0.0f, 1.0f},0.35,1.5),
        Disk({-7,1,0},{0.0f, 1.0f, 0.0f, 1.0f},0.35,1.25),
        Disk({-7,2,0},{0.0f, 1.0f, 0.0f, 1.0f},0.35,1)}){
    
    for(auto & i:disks){
        stacks_array[0].push(&i);  
    }
}

void Environment::draw(){
    land.draw();
    for(auto &i: rods){
        i.draw();
    }
    for(auto &j: disks){
        j.draw();
    }
}