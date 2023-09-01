#pragma once
#include "Header.h"

class Player
{
private:
    
    Vector2f direction;
    float speed;
    
    IntRect currentFramePlayer;

    //sprite and texture
    Sprite player;
    Texture texturePlayer;

    //anime
    Vector2f imageCount;
    Vector2f currentImage;
    
    float totalTime=0;
    float switchTime;
    IntRect uvRect;
    
    //GUN COOLDOWN

public:
    float hp = 100;
    float coolDownShooting=0.f;
    float coolDownShootingMax;
    float coolDownShootingPlus=0.f;

    float coolDownShooting2 = 0.f;
    float coolDownShootingMax2;
    float coolDownShootingPlus2 = 0.f;

    Player();
    ~Player();
    FloatRect getBounds();
    //anime
    void updateAnime(float row, float deltaTime,bool anime);
    void PlayerAnime(Texture* texturePlayer, Vector2f imageCount, float switchTime);
    Vector2f positionPlayer();

    bool canOrNotATK();
    bool canOrNotATK2();
    void updateTimeForATK();
    void updateTimeForATK2();

    void update(float deltaTime);
    void renderOn(RenderWindow& target);
};