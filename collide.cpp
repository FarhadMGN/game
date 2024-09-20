//
//  collide.cpp
//  yuthyg
//
//  Created by Евгений on 22/04/2019.
//  Copyright © 2019 Евгений. All rights reserved.
//

#include "collide.hpp"

float distance(Vec pos1, Vec pos2)
{
    float dst = (pos1.first - pos2.first) * (pos1.first - pos2.first) + (pos1.second - pos2.second) * (pos1.second - pos2.second);
    return dst;
}

float collide (const GameObject* obj1, const GameObject* obj2)
{
    float dist = distance(obj1->pos_, obj2->pos_);
    float size_dist =   250;
    //(obj1->size_.first + obj2->size_.first) * (obj1->size_.first + obj2->size_.first) / 4;
    //printf("do not cicle dist = %f\n", dist);
    //printf("do not cicle size_dist = %f\n", size_dist);
    return dist - size_dist;
}
