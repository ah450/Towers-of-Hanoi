#include "../include/environment.hpp"

Environment::Environment() : land({6}), rods({Rod({-5.0,0.0,0.0},{1.0,0.0,0.0,1.0f}),
    Rod({0.0,0.0,0.0},{1.0,0.0,0.0,1.0f}),Rod({5.0,0.0,0.0},{1.0,0.0,0.0,1.0f})}), 
    disks({Disk({},{},0.3,0.9)}){
    for(auto & i:disks){
        stacks_array[0].push_back(&i);  
    }
}