#include "Game.h"

Game::Game()
{

	inWindow();
	inTexture();
	inGui();
	how_to_play();
	backGround();
	spawnTimerMaxEnemy = 30.f;
	spawnTimerMaxEnemya = 10.f;
	speedEnemy = 0.2f;
	speedEnemya = 10.f;
	speedCat = 5.f;
	spawnTimerMaxCat = 20.f;
	moveCat=-10;

	sharkTimeEraseMax = 20.f;
}

Game::~Game()
{

}
void Game::menuF(RenderWindow* target)
{
	
	
	Text menuText("Play", font, 80);
	menuText.setFillColor(Color(255, 0, 108));
	menuText.setOutlineColor(Color::Green);
	menuText.setOutlineThickness(2);
	menuText.setPosition(500, 300);

	Text howToPlay("How To Play", font, 80);
	howToPlay.setFillColor(Color(255, 0, 108));
	howToPlay.setOutlineColor(Color::Green);
	howToPlay.setOutlineThickness(2);
	howToPlay.setPosition(500, 450);

	if (menuText.getGlobalBounds().contains(Mouse::getPosition(*target).x, Mouse::getPosition(*target).y) && Mouse::isButtonPressed(Mouse::Left)) {
		cout << "fk";
		menuK= true;
		selectMenu = 1;
	}

	if (howToPlay.getGlobalBounds().contains(Mouse::getPosition(*target).x, Mouse::getPosition(*target).y) && Mouse::isButtonPressed(Mouse::Left)) {
		cout << "fk25";
		menuK = true;
		selectMenu = 2;
	}
	target->draw(menuText);
	target->draw(howToPlay);
}
void Game::how_to_play()
{
	if (!howToPlayTex.loadFromFile("text/howtoplay1x.png")) {
		cout << "Shit how to play not load";
	}
	howToPlaySprite.setTexture(howToPlayTex);
}
void Game::inTexture()
{
	//ตั้งค่าให้ map ของ textureBullet โดยใช้ ["bullet"] แล้วตั้งให้มันเป็น texture() แล้วค่อยใส่ texture ลงไป
	textureBullet["BULLET"] = Texture();
	textureBullet["BULLET"].loadFromFile("text/arrow.png");
	
	//Enemy
	textureEnemy["ENEMY"] = Texture();
	textureEnemy["ENEMY"].loadFromFile("text/Enemy.png");

	textureEnemya["ENEMYA"] = Texture();
	textureEnemya["ENEMYA"].loadFromFile("text/bullet.png");

	textureCoin["COIN"] = Texture();
	textureCoin["COIN"].loadFromFile("text/coin2.png");

	texturePotion["POTION"] = Texture();
	texturePotion["POTION"].loadFromFile("text/potion.png");

	textureCat["CAT"] = Texture();
	textureCat["CAT"].loadFromFile("text/cat.png");

	textureShark["SHARK"] = Texture();
	textureShark["SHARK"].loadFromFile("text/shark.png");
	
}
void Game::inWindow()
{
	this->window = new RenderWindow(sf::VideoMode(1080, 720), "SFML works!", sf::Style::Titlebar | sf::Style::Close);
	window->setFramerateLimit(60);
}
void Game::iniState()
{
	
}
void Game::run()
{
	player = this->player;
	Clock clock;
	Clock animeTime;
	float deltaTime = 0;
	
	while (window->isOpen())
	{
		pollEvent();
		
		deltaTime = clock.restart().asSeconds();
		window->clear();
		
		if (selectMenu == 0) {
			
			menuF(this->window);
			
		}
		else if(selectMenu==1){
			window->clear();
			player->update(deltaTime);
			updateGame(deltaTime);
		}
		else if (selectMenu == 3) {

		}
		renderGame();
		window->display();
			
	
	}
}
void Game::pollEvent()
{
	Event ev;
	while (window->pollEvent(ev))
	{
		if (ev.type == Event::Closed) {
			window->close();
		}
	}
}
void Game::EnemyAnime(Texture* textureEnemy, Vector2f EnemyImageCount, float EnemySwitchTime)
{
	this->EnemyImageCount = EnemyImageCount;
	this->EnemySwitchTime = EnemySwitchTime;
	EnemyuvRect.width = textureEnemy->getSize().x / EnemyImageCount.x;
	EnemyuvRect.height = textureEnemy->getSize().y / EnemyImageCount.y;
}



void Game::EnemyUpdateAnime(float Enemyrow, float deltaTime, bool Enemyanime)
{
	EnemyCurrentImage.y = Enemyrow;
	EnemyTotalTime += deltaTime;
	plus = 2.f;
	if (EnemyTotalTime >= EnemySwitchTime) {
		EnemyTotalTime -= EnemySwitchTime;
		EnemyCurrentImage.x += plus;
		if (EnemyCurrentImage.x >= 3.f) {
			EnemyCurrentImage.x = 0.f;

		}
	}
	EnemyuvRect.left = EnemyCurrentImage.x * EnemyuvRect.width;
	EnemyuvRect.top = EnemyCurrentImage.x * EnemyuvRect.width;
	
}


void Game::inGui()
{
	if (!font.loadFromFile("font/1.ttf"))
	{
		cout << "ERRORFONT";
	}
	pointText.setFont(font);
	pointText.setCharacterSize(50);
	pointText.setFillColor(Color::White);
	
}

void Game::updateEnemy()
{
	spawnTimerEnemy += 0.3f;
	if (spawnTimerEnemy >= spawnTimerMaxEnemy) {
		spawnTimerEnemy = 0.f;
		enemys.push_back(new Enemy(this->textureEnemy["ENEMY"], 1100.f, rand() % 700, -10.f, 0.f, speedEnemy));
	}
	unsigned counter = 0;
	for (auto *enemy:enemys) {
		enemy->Enemy1.setTextureRect(EnemyuvRect);
		enemy->updateEnemy();
		++counter;		
	}
	
}

void Game::updateCombat()
{
	for (int i = 0; i < this->enemys.size(); ++i) {
		bool enemy_removed = false;
		
			for (size_t k = 0; k < this->bullets.size() && enemy_removed == false; k++) {
				if (this->bullets[k]->getBounds().intersects(enemys[i]->getBoundsEnemy()) ) {
					
					this->bullets.erase(bullets.begin() + k);

					point_Enemy[i] += 1;
					if (point_Enemy[i] >= 1.f) {
						if (rand() % 5 == 4) {
							coins.push_back(new Coin(this->textureCoin["COIN"], enemys[i]->getBoundsEnemy().left, enemys[i]->getBoundsEnemy().top));
						}
						else if (rand() % 3 == 2) {
							potions.push_back(new Potion(this->texturePotion["POTION"], enemys[i]->getBoundsEnemy().left, enemys[i]->getBoundsEnemy().top));
						}
						this->enemys.erase(enemys.begin() + i);
						point_Enemy[i] = 0.f;

						pointP += 1;
						enemy_removed = true;
					}
				}
			
		}

		if (!enemy_removed)
		{
			if (this->enemys[i]->getBoundsEnemy().left + this->enemys[i]->getBoundsEnemy().width < 0) {
			//	delete this->enemys[i];
				this->enemys.erase(this->enemys.begin() + i);
				enemy_removed = true;
				pointP -= 1;
			}

			if (canDamagePlayer == true) {
				if (this->player->getBounds().intersects(enemys[i]->getBoundsEnemy())) {
					hpPlayer -= 1;
					canDamagePlayer = false;
					canDMG = 0.f;
				}
			}
			else {
				canDMG += 1.f;
			}
			if (canDMG >= 200.f) {
				canDamagePlayer = true;
			}	
		}	
	}	
}

void Game::spawn()
{
	spawnTimerCat += 1.f;
	spawnTimerEnemya += 0.05f;
	
	if (spawnTimerCat == 1000.f && catok == true) {
		
		cats.push_back(new Cat(this->textureCat["CAT"], 900.f, 350.f, 0.f, 5, speedCat));
		cout << "cat\n";
		cathere = true;
		
	}
	if (spawnTimerEnemya >= spawnTimerMaxEnemya && cathere==true) {
		for (int i = 0; i < cats.size();++i) {
			enemyas.push_back(new Enemya(this->textureEnemya["ENEMYA"], 900.f, cats[i]->getBoundsEnemy().top + rand() % 100, -10.f, 0.f, speedEnemya));
			enemyas.push_back(new Enemya(this->textureEnemya["ENEMYA"], 900.f, cats[i]->getBoundsEnemy().top + rand() % 100, -10.f, 0.f, speedEnemya));
			enemyas.push_back(new Enemya(this->textureEnemya["ENEMYA"], 900.f, rand() % 700, -10.f, 0.f, speedEnemya));
			enemyas.push_back(new Enemya(this->textureEnemy["ENEMYA"], 900.f, rand() % 700, -10.f, 0.f, speedEnemya));
			spawnTimerEnemya = 0.f;
		}
		
		
		//		enemyas.push_back(new Enemya(this->textureEnemy["ENEMYA"], -10.f, rand() % 700, 10.f, 0.f, speedEnemya));
		//		enemyas.push_back(new Enemya(this->textureEnemy["ENEMYA"], -10.f, rand() % 700, 10.f, 0.f, speedEnemya));
	}
	if (Keyboard::isKeyPressed(Keyboard::F) && player->canOrNotATK2() && cathere) {
		cout << "SHARK\n";
		sharks.push_back(new Shark(this->textureShark["SHARK"], player->getBounds().left+10, player->getBounds().top+10, 0.f, 0.f, 0));
	}

}

void Game::updateEnemy2(float deltaTime)
{
	
		unsigned counter = 0;
		for (auto* enemya : enemyas) {
			enemya->updateEnemy2(deltaTime);
//			if (enemya->getBoundsEnemy2().left + enemya->getBoundsEnemy2().width < 0.f) {
	//			enemyas.erase(enemyas.begin() + counter);
	//			--counter;
				//	cout << "REMOVE BULLET\n";
	//		}
			++counter;
		}
	
	
}

void Game::updateCombat2()
{
	
		for (int i = 0; i < this->enemyas.size(); ++i) {
			bool enemy_removed = false;
			for (size_t k = 0; k < this->sharks.size() && enemy_removed == false; k++) {
				if (sharks[k]->getBoundsEnemy().intersects(enemyas[i]->getBoundsEnemy2())) {
					sharks.erase(sharks.begin()+k);
					enemyas.erase(enemyas.begin()+i);
					enemy_removed = true;
				}
			}
			if (!enemy_removed) {
				if (enemyas[i]->getBoundsEnemy2().left + enemyas[i]->getBoundsEnemy2().width < 0.f) {
					enemyas.erase(enemyas.begin()+i);
				}

				if (canDamagePlayer2 == true) {
					if (this->player->getBounds().intersects(this->enemyas[i]->getBoundsEnemy2())) {
						hpPlayer -= 1.f;
						canDamagePlayer2 = false;
						canDMG2 = 0.f;
					}
				}
				else {
					canDMG2 += 1.f;
				}
				if (canDMG2 >= 200.f) {
					canDamagePlayer2 = true;
				}
			}		
		}
}

void Game::updateCat(float deltaTime)
{
		unsigned counter = 0;
		for (auto cat : cats) {
			if (player->getBounds().top < cat->getBoundsEnemy().top) {
				//		cout << player->getBounds().top<<" PLAY\n";
				//		cout << cat->getBoundsEnemy().top << " CAT\n";
				cat->moveUp();

			}

			if (player->getBounds().top > cat->getBoundsEnemy().top)
			{
				//		cout << player->getBounds().top << " PLAY\n";
					//	cout << cat->getBoundsEnemy().top << " CAT\n";
				cat->moveDown();
			}
			if (pointP >= 50 && Keyboard::isKeyPressed(Keyboard::E)) {
				pointCoin = 0;
				cats.erase(cats.begin() + counter);
				catok = false;
				cathere = false;
				cout << "123";
				selectMenu = 3;
			}
			++counter;
		}
	
}

void Game::updateShark()
{
	sharkTimeErase += 0.1f;
	unsigned counter = 0;
	for (auto* shark:sharks) {
		
		if (sharkTimeErase >= sharkTimeEraseMax) {
			this->sharks.erase(sharks.begin()+counter);
			sharkTimeErase = 0.f;
			cout << "SHARKGONE\n";
		}
		++counter;
	}
}

void Game::updateBullet()
{

	unsigned counter = 0;
	for (auto *bullet : bullets) {
		bullet->update();
		if (bullet->getBounds().left + bullet->getBounds().width > 1080) {
			delete this->bullets.at(counter);
			this->bullets.erase(bullets.begin() + counter);
			--counter;
		}
		++counter;
	}
}

void Game::updateCoin()
{
	for (int i = 0; i < coins.size();++i) {
		if (this->player->getBounds().intersects(coins[i]->getBounds())) {

			pointCoin += 1;
			this->coins.erase(this->coins.begin()+i);

		}
	}
}

void Game::colliPotion()
{
	timeSpawnPotions += 0.1f;
	bool removed = false;
	for (int i = 0; i < potions.size() && removed==false;++i) {
		if (this->player->getBounds().intersects(potions[i]->getBounds())) {
			this->potions.erase(this->potions.begin()+i);
			updatePoion();
			removed = true;
		}
	
		if (!removed) {
			if (timeSpawnPotions>=timeSpawnPotionsMax) {
				this->potions.erase(this->potions.begin() + i);
				timeSpawnPotions = 0.f;
				removed = true;
			}
		}
	}
}

void Game::updatePoion()
{

		potionEff = 0.05f;
		player->coolDownShootingPlus += potionEff;
	
}

void Game::inputKey()
{

	if (Keyboard::isKeyPressed(Keyboard::Space) && player->canOrNotATK()) {
		//                               (รับเท็คเจอร์แต่ละตัวเข้า สไปต์ , เกิดตามตำแหน่่งคน.x + 50 เพราะอยากให้กระสุนเกิดห่างจากคน , ก็ตำแหน่งคน.y ให้กระสุนออกกลางๆตัว , ทิศทางที่จะไป.x ,ทางที่จะไป.y , ความเร็ว)
		bullets.push_back(new Bullet(this->textureBullet["BULLET"], this->player->positionPlayer().x + 50.f, this->player->positionPlayer().y + 16.f, 10.f, 0.f, 1.f));
		//cout << "OK--->" << player.positionPlayer().x << "---->" << player.positionPlayer().y << "\n";

	}

}


void Game::updateGame(float deltaTime)
{
//	inTexture();
	EnemyAnime(&textureEnemy["ENEMY"],Vector2f(12,8),0.3f);
	EnemyUpdateAnime(2,deltaTime,true);
	updateCombat();
	updateEnemy();
	updateBullet();
	updateCombat();

	spawn();
	updateEnemy2(deltaTime);
	updateCombat2();
	updateCat(deltaTime);

	updateShark();

	updateCoin();
	colliPotion();
	updateGui();
	inputKey();

	savePoint();

	
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		cout << "fk";
		menuK = false;
		selectMenu = 0;

	}
}

void Game::updateGui()
{
	stringstream s;
	s <<" HP : "  << hpPlayer <<"   " << "Point : " << pointP << "   " << "Coin : " << pointCoin;
	pointText.setString(s.str());

}

void Game::renderGui()
{
	window->draw(pointText);
}

void Game::savePoint()
{
	
	
	
}

void Game::backGround()
{
	if (!backGroundTex.loadFromFile("text/back3.png")) {
		cout << "back3\n";
	}
	backGroundSprite.setTexture(backGroundTex);
}

void Game::backGroundRender(RenderWindow* target)
{
	target->draw(backGroundSprite);
}

void Game::renderGame()
{
//	window->clear();
	
	//if (menu->okeyPlay == false) {
	//	menu->render(*this->window);
	//}
	//else {
	
	if (selectMenu==0) {
		
		menuF(this->window);
		
	}
	else if(selectMenu==1){
		backGroundRender(this->window);

		player->renderOn(*this->window);
		for (auto* enemy : enemys) {
			enemy->renderEnemy(this->window);
		}
		//เรนเดอร์กระสูนแต่ละกันตลอดเกม เมื่อมีกระสุนเกิดขึ้น
		for (auto* bullet : bullets) {
			bullet->renderBullet(this->window);
		}
		for (auto* coin : coins) {
			coin->reder(this->window);
		}
		for (auto* potion : potions) {
			potion->reder(this->window);
		}
		for (auto* enemya : enemyas) {
			enemya->renderEnemy2(this->window);
		}
		for (auto* cat:cats) {
			cat->renderEnemy(this->window);
		}
		for (auto *shark:sharks) {
			shark->renderEnemy(this->window);
		}
		window->draw(pointText);
	}
	else if (selectMenu==2) {
		renderHowToPlay(this->window);
	}	
//	
	
//	window->display();
}

void Game::renderHowToPlay(RenderWindow* target)
{
	window->draw(howToPlaySprite);

	Text howToPlayEX("Exit", font, 50);
	howToPlayEX.setFillColor(Color(255, 0, 108));
	howToPlayEX.setOutlineColor(Color::Green);
	howToPlayEX.setOutlineThickness(2);
	howToPlayEX.setPosition(1000, 650);
	window->draw(howToPlayEX);

	if (howToPlayEX.getGlobalBounds().contains(Mouse::getPosition(*target).x, Mouse::getPosition(*target).y) && Mouse::isButtonPressed(Mouse::Left)) {
		cout << "fk25";
		menuK = true;
		selectMenu = 0;
	}

}