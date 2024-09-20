//
//  collide.hpp
//  yuthyg
//
//  Created by Евгений on 22/04/2019.
//  Copyright © 2019 Евгений. All rights reserved.
//

#ifndef collide_hpp
#define collide_hpp

#include <stdio.h>
#include <utility>

#include "obj.hpp"

using namespace std;
using Vec  = pair<float, float>;

class Collide
{
public:
    
};

float distance(Vec pos1, Vec pos2);
float collide (const GameObject* obj1, const GameObject* obj2);

#endif /* collide_hpp */
