#include"Game.h"
int main()
{
	srand(time(0));
	Clock clock;
	Clock animeTime;
	float deltaTime = 0;
	
	Player player;
	Game game;
	game.player = &player;


	//ต้องอ้างถึง player ที่ class Player เพราะว่าเราต้องการข้อมูลเรียลไทม์ และ game.player กับ Player player เป็นคนละตัวเพราะคนละคลาส
	
	
	game.run();
	
	//	cout << Mouse::getPosition().x << "-------->" << Mouse::getPosition().y << "\n";

	
	return 0;
}