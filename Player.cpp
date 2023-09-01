#include"Player.h"

Player::Player()
{
    if (!texturePlayer.loadFromFile("text/sans2.png"))
    {
        cout << "ERROR\n";
    }
    player.setTexture(texturePlayer);
    /*
    Vector2u textureSize = texturePlayer.getSize();
    textureSize.x /= 12; //32
    textureSize.y /= 8; //32

    player.setTextureRect(IntRect(textureSize.x, textureSize.y, textureSize.x, textureSize.y));
    */
    speed = 200.f;
    currentImage.x = 0.f;
    player.setPosition(Vector2f(500.f, 350.f));
    player.setScale(1.5f,1.5f);

    coolDownShootingMax = 10.f;
    coolDownShootingMax2 = 10.f;
}

Player::~Player()
{
}

FloatRect Player::getBounds()
{
    return player.getGlobalBounds();
}

void Player::PlayerAnime(Texture* texturePlayer, Vector2f imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    
    // ขนาดภาพหารด้วยจำนวนภาพ จะได้ขนาดของรูปแต่ละรูป
    uvRect.width = texturePlayer->getSize().x / imageCount.x;
    uvRect.height = texturePlayer->getSize().y / imageCount.y;
    
}

Vector2f Player::positionPlayer() 
{
    return player.getPosition();
}

bool Player::canOrNotATK()
{
    if (coolDownShooting >= coolDownShootingMax )
    {
        coolDownShooting = 0.f;
        return true;

    }
    return false;
}

bool Player::canOrNotATK2()
{
    if (coolDownShooting2 >= coolDownShootingMax2)
    {
        coolDownShooting2 = 0.f;
        return true;

    }
    return false;
}

void Player::updateTimeForATK()
{
    if (coolDownShooting < coolDownShootingMax)
    {
        coolDownShooting += 0.3f+coolDownShootingPlus;
    }
}

void Player::updateTimeForATK2()
{
    if (coolDownShooting2 < coolDownShootingMax2)
    {
        coolDownShooting2 += 0.3f + coolDownShootingPlus2;
    }
}

void Player::updateAnime(float row, float deltaTime,bool anime)
{
 
    if (direction == Vector2f(0.f, 0.f)) {
        row = 4.f;
        anime = true;
    }
    else if (direction == Vector2f(0.f, -1.f)) {
        row = 3.f;
        anime = true;
    }
    else if (direction == Vector2f(0.f, 1.f)) {
        row = 0.f;
        anime = true;
    }
    else if (direction == Vector2f(-1.f, 0.f)) {
        row = 1.f;
        anime = true;
    }
    else if (direction == Vector2f(1.f, 0.f)) {
        row = 2.f;
        anime = true;
    }
    float plus = 2.f;
    currentImage.y = row;
    totalTime = totalTime + deltaTime;

    if (totalTime >= switchTime && anime == true)
    {
        totalTime -= switchTime;
        currentImage.x =currentImage.x+plus;
        if (currentImage.x >= 3.f  )
        {
           
            currentImage.x = 0.f;
        }
 
    }
    //ขนาดภาพ คูณ ตำแหน่งภาพก็จะทำให้ x y ย้ายไปยังรูปที่ต้องการต่อไป
    uvRect.left = currentImage.x * uvRect.width;
    uvRect.top = currentImage.y * uvRect.height;
    
}

void Player::update(float deltaTime)
{
    direction = Vector2f(0.f, 0.f);
    if (Keyboard::isKeyPressed(Keyboard::W) && player.getPosition().y >= 5.f)
    {
        direction = Vector2f(0.f, -1.f);
        
    }
    if (Keyboard::isKeyPressed(Keyboard::A) && player.getPosition().x >= 5.f)
    {
        direction = Vector2f(-1.f, 0.f);
    }
    if (Keyboard::isKeyPressed(Keyboard::S) && player.getPosition().y <= 660.f)
    {
        direction = Vector2f(0.f, 1.f);
    }
    if (Keyboard::isKeyPressed(Keyboard::D) && player.getPosition().x <= 1050.f)
    {
        direction = Vector2f(1.f, 0.f);
    }
    if (Keyboard::isKeyPressed(Keyboard::LShift)) {
        speed = 300;
    }
    
    player.move(normalize(direction) * speed * deltaTime);
    speed = 200.f;
    PlayerAnime(&texturePlayer, Vector2f(12.f, 8.f), 0.3f);
    updateAnime(0, deltaTime,false);
    
    positionPlayer();
    updateTimeForATK();
    updateTimeForATK2();
//------------------------------------------------------------------------------------------------------------------------
  //  cout << "OK--->" << positionPlayer().x << "---->" << positionPlayer().y << "\n";
}

void Player::renderOn(RenderWindow& target)
{
    player.setTextureRect(uvRect);
    target.draw(player);
}
