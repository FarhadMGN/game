
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <math.h>


// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include "obj.hpp"
#include "collide.hpp"

int animation(sf::Sprite sp, int t)
{
    int frames = 3;
    int sp_x = sp.getLocalBounds().width;
    int sp_y = sp.getLocalBounds().height;
    sp.setTextureRect(sf::IntRect(t % frames * sp_x, 0, (t % frames + 1) * sp_x, sp_y));
    
    /*window.clear();
    window.draw(sp);
    window.display();
    t++;*/
}

sf::RenderWindow* Window = nullptr;

/*void DoRender(sf::RenderWindow* Window, const Ship& shp, const Ship& ast)
{
    Window->clear();
    shp.draw(Window);
    ast.draw(Window);
    
    Window->display();
    
}*/
GameObject** GameConstr(sf::Sprite ship, sf::Sprite aster)
{
    
    Ship     *s1 = new Ship(Vec (600.0, 300.0), Vec (0.0, 0.0), 1, 0.0, 0.1, ship);

    Asteroid *a1 = new Asteroid(Vec (1200.0, 700.0), Vec (-100.0, -60.0), 1, 0.0, 0.1, aster);
    Asteroid *a2 = new Asteroid(Vec (1200, 900.0), Vec (-100.0, -80.0), 1, 0.0, 0.1, aster);
    Asteroid *a3 = new Asteroid(Vec (0.0, 0.0), Vec (0.0, 0.0), 0, 0.0, 0.1, aster);
    Asteroid *a4 = new Asteroid(Vec (0.0, 0.0), Vec (0.0, 0.0), 0, 0.0, 0.1, aster);
    Asteroid *a5 = new Asteroid(Vec (0.0, 0.0), Vec (0.0, 0.0), 0, 0.0, 0.1, aster);
    Asteroid *a6 = new Asteroid(Vec (0.0, 0.0), Vec (0.0, 0.0), 0, 0.0, 0.1, aster);
    Asteroid *a7 = new Asteroid(Vec (0.0, 0.0), Vec (0.0, 0.0), 0, 0.0, 0.1, aster);
    Asteroid *a8 = new Asteroid(Vec (0.0, 0.0), Vec (0.0, 0.0), 0, 0.0, 0.1, aster);
    Asteroid *a9 = new Asteroid(Vec (0.0, 0.0), Vec (0.0, 0.0), 0, 0.0, 0.1, aster);
    
    
    GameObject** obj = new GameObject*[3]{};
    obj[0] = s1;
    obj[1] = a1;
    obj[2] = a2;
    return obj;
}

void RunGame()
{
    sf::Image ship;
    if (!ship.loadFromFile(resourcePath() + "ship.png")) {
        printf("can't load ship\n");
    }
    
    sf::Texture ship_tex;
    if (!ship_tex.loadFromImage(ship)) {
        printf("can't load texture ship\n");
    }
    sf::Sprite shp(ship_tex);
    
    sf::Texture asteroid_tex;
    if (!asteroid_tex.loadFromFile(resourcePath() + "asteroid.png"))
        printf("can't load texture asteroid\n");
    
    sf::Sprite aster(asteroid_tex);
    
    
    auto sz = Window->getSize();
    
    sf::Texture bg_tex;
    bg_tex.loadFromFile(resourcePath() + "bg.jpg");
    
    sf::Sprite bg(bg_tex);
    bg.setScale(sz.x / bg.getLocalBounds().width, sz.y / bg.getLocalBounds().height);

    GameObject** ar = GameConstr(shp, aster);
    
    
    for (int i = 1; i < 3; i++)
    {
        ar[i]->pos_.first = 0;
        ar[i]->pos_.second = rand() % 700 + 1;
    
        ar[i]->speed_.first = (ar[0]->pos_.first - ar[i]->pos_.first);
        ar[i]->speed_.second = (ar[0]->pos_.second - ar[i]->pos_.second);
        printf("arr[%d].pos = %f\n", i, ar[i]->pos_.second);
    }
    
    sf::Clock clock;
    while(Window->isOpen())
    {
        float time = clock.restart().asSeconds();
        sf::Event event;
        while (Window->pollEvent (event)) if (event.type == sf::Event::Closed) break;
        if (sf::Keyboard::isKeyPressed (sf::Keyboard::Escape)) break;
        if (!Window->isOpen()) break;
        
        //____RENdER_______
        Window->clear();
        
        Window->draw(bg);
        for (int i = 0; i < 3; i++)
        ar[i]->draw(Window);
        
        Window->display();
        //____RENdER_______
        
        ((Ship*)ar[0])->control();
        
        if (collide(ar[0], ar[1]) < 0.0 ||
        collide(ar[0], ar[2]) < 0.0)
            break;
        
        Vec p;
        p.first = 1800;
        p.second = 1050;
        
        for (int i = 0; i < 3; i++)
            ar[i]->physics(p, time);
    }
    for (int i = 0; i < 3; i++)
        delete(ar[i]);
        delete ar;
}

int main(int, char const**)
{
    sf::RenderWindow window(sf::VideoMode(2700, 1575), "lol");
    
    Window = &window;
    
    RunGame();
    
    return EXIT_SUCCESS;
}
