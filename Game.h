#pragma once
#include"Bullet.h"
#include"Player.h"
#include"Enemy.h"
#include"Enemya.h"
#include"Coin.h"
#include "Potion.h"
#include"Cat.h"
#include"Shark.h"
class Game
{
private:
	
	bool catok = true;
	bool cathere = false;
	float plus = 2;
	
	RenderWindow *window;
	//สร้าง obj Bullet bullet เรียบร้อย
	vector <Bullet*> bullets;
	map<string, Texture> textureBullet;
	// ENEMY
	vector <Enemy*>enemys;
	map<string, Texture> textureEnemy;
	float spawnTimerEnemy;
	float spawnTimerMaxEnemy;
	float speedEnemy;
	float point_Enemy[10];

	vector <Enemya*>enemyas;
	map<string, Texture> textureEnemya;
	float spawnTimerEnemya;
	float spawnTimerMaxEnemya;
	float speedEnemya;

	vector <Cat*>cats;
	map<string, Texture> textureCat;
	float spawnTimerCat;
	float spawnTimerMaxCat;
	float speedCat;
	float moveCat;
	bool catDead = false;

	vector<Shark*>sharks;
	map<string, Texture> textureShark;
	float sharkTimeErase;
	float sharkTimeEraseMax;

	//anime enemy
	
	Vector2f EnemyImageCount;
	Vector2f EnemyCurrentImage;
	float EnemySwitchTime;
	float EnemyTotalTime = 0;
	
	IntRect EnemyuvRect;
	//point
	float pointP;
	//gui
	Font font;
	Text pointText;
	void inGui();
	
	float hpPlayer = 10;
	bool canDamagePlayer = true;
	float canDMG;

	bool canDamagePlayer2 = true;
	float canDMG2;

	//coin
	vector<Coin*>coins;
	map<string, Texture> textureCoin;
	float pointCoin=0;

	//potion
	vector<Potion*>potions;
	map<string, Texture> texturePotion;
	float timeSpawnPotions;
	float timeSpawnPotionsMax=50.f;
	float timeGetPotion;
	float timeGetPotionMax=5;
	float potionEff;


	//
	bool menuK=false;
	float selectMenu=0;
	
	//
	Sprite backGroundSprite;
	Texture backGroundTex;

	Sprite howToPlaySprite;
	Texture howToPlayTex;

public:

	//สร้าง obj Player *player ต้องเป็น Public เพราะอยากให้ใช้ได้ทั่วและ ต้องเป็นพอยเตอร์ชี้ไปแอดเดรต เพราะต้องการอัพเดดเรียลไทม์
	Game();
	~Game();
	Player* player;
	

	void menuF(RenderWindow* target);
	void how_to_play();

	void inTexture();
	void inWindow();

	void iniState();

	void run();
	void pollEvent();

	void inputKey();
	void updateBullet();
	void EnemyAnime(Texture*textureEnemy,Vector2f EnemyImageCount, float EnemySwitchTime);
	void EnemyUpdateAnime(float Enemyrow, float deltaTime, bool Enemyanime);

	

	void updateEnemy();
	void updateCombat();

	void spawn();
	void updateEnemy2(float deltaTime);
	void updateCombat2();
	void updateCat(float deltaTime);

	void updateShark();
	
	void updateCoin();

	void updatePoion();
	void colliPotion();

	void updateGame(float deltaTime); 
	void savePoint();

	void backGround();
	void backGroundRender(RenderWindow* target);

	void updateGui();
	void renderGui();
	void renderGame();
	void renderHowToPlay(RenderWindow* target);
};

