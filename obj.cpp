//
//  obj.cpp
//  yuthyg
//
//  Created by Евгений on 08/04/2019.
//  Copyright © 2019 Евгений. All rights reserved.
//

#include "obj.hpp"

GameObject::GameObject(Vec pos, Vec speed, int alive, float rotation, float k, sf::Sprite sprite):
pos_(pos),
speed_(speed),
is_alive_(alive),
k_(k),
rotation_(rotation),
sprite_(sprite)
{
    pos_.first = pos.first;
    printf("in constructor:pos_x = %f pos_y = %f\n", pos_.first, pos_.second);
    auto bounds = sprite_.getLocalBounds();
    size_.first = bounds.width;
    size_.second = bounds.height;
}


GameObject::~GameObject()
{}

Ship::Ship (Vec pos, Vec speed, int alive, float rotation, float k, sf::Sprite sprite):
GameObject(pos, speed, alive, rotation, k, sprite)
{}

void Ship::control()
{
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left))    speed_.first -= 1;
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::Right))   speed_.first += 1;
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::Up))      speed_.second -= 1;
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::Down))    speed_.second += 1;
}

void GameObject::physics(Vec sz, float t)
{
    pos_.first  = pos_.first + speed_.first * t;
    pos_.second = pos_.second + speed_.second * t;
}

void GameObject::draw(sf::RenderWindow* screen)
{
    if(sprite_.getTexture() && is_alive_ == 1)
    {
        sprite_.setOrigin (size_.first / 2, size_.second / 2);
        sprite_.setPosition(pos_.first, pos_.second);
        sprite_.setScale(k_, k_);
        screen->draw(sprite_);
    }
    else
        printf("i need a sprite!\n");
}

Asteroid::Asteroid (Vec pos, Vec speed, int alive, float rotation, float k, sf::Sprite sprite):
GameObject(pos, speed, alive, rotation, k, sprite)
{}

void Asteroid::draw(sf::RenderWindow* screen)
{
    if(sprite_.getTexture() && is_alive_ == 1)
    {
        sprite_.setOrigin (size_.first / 2, size_.second / 2);
        sprite_.setPosition(pos_.first, pos_.second);
        sprite_.setScale(k_, k_);
        float size = size_.first / 3;
        sprite_.setTextureRect(sf::IntRect(size * 2, 0, size, size_.second));
        screen->draw(sprite_);
    }
    else
        printf("i need a sprite!\n");
}
