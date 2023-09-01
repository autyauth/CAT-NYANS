#pragma once
#include<cstdlib>
#include<ctime>
#include<time.h>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include<math.h>
#include<map>
#include<string>
#include<sstream>
#include<vector>
#include<stack>

using namespace sf;
using namespace std;

inline float lenght(Vector2f vec)
{
    return sqrt(vec.x * vec.x + vec.y * vec.y);
}

inline Vector2f normalize(Vector2f vec)
{
    float len = lenght(vec);
    if (len != 0)
        return vec / len;
    return vec;
}