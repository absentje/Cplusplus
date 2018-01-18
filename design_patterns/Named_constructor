// разрешен вызов конструктора лишь с определенными параметрами

struct Game {
	// named constructor
	static Game createSinglePlayerGame() { return Game(0); }
	// named constructor
	static Game createMultiPlayerGame() { return Game(1); }
protected:
	Game(int game_type);
};
int main(void)
{
	// Using named constructor
	Game g1 = Game::createSinglePlayerGame();
	// multiplayer game; without named constructor (does not compile)
	Game g2 = Game(1);
}
