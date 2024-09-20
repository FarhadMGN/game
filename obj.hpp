//
//  obj.hpp
//  yuthyg
//
//  Created by Евгений on 08/04/2019.
//  Copyright © 2019 Евгений. All rights reserved.
//

#ifndef obj_hpp
#define obj_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <utility>

#include <stdio.h>
using namespace std;
using Vec  = pair<float, float>;

class GameObject
{
    public:
    Vec pos_;
    Vec speed_;
    Vec size_;
    int is_alive_;
    float rotation_;
    float k_;
    sf::Sprite sprite_;
    GameObject(Vec pos, Vec speed, int alive, float rotation, float k, sf::Sprite sprite);
    virtual ~GameObject() = 0;
    virtual void draw(sf::RenderWindow* screen);
    void physics(Vec sz, float t);
};

class Ship: public GameObject
{
public:
    Ship (Vec pos, Vec speed, int alive, float rotation, float k, sf::Sprite sprite);
    ~Ship () = default;
    void control();
    //void physics(Vec sz, float t):physics(sz, t){};
};

class Asteroid: public GameObject
{
public:
    Asteroid (Vec pos, Vec speed, int alive, float rotation, float k, sf::Sprite sprite);
    ~Asteroid () = default;
    void draw(sf::RenderWindow* screen);
    //void physics(Vec sz, float t): GameObject::physics(sz,t){};
};
#endif /* obj_hpp */

