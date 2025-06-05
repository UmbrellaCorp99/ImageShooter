#ifndef PLAYERH
#define PLAYERH
class player
{
public:
	player(int HEIGHT);
	~player();
	void DrawPlayer();
	void MoveUp();
	void MoveDown(int HEIGHT);
	void MoveLeft();
	void MoveRight();
	int getBoundX(){return boundx;}
	int getBoundY(){return boundy;}
	int getX(){return x;}
	int getY(){return y;}
	int getScore() { return score; }
	void removeLife();
	void updateScore(int i) { score += i; }
	int getLives(){return lives;}
private:
	int x;
	int y;
	int lives;
	int speed;
	int boundx;
	int boundy;
	int score;
	ALLEGRO_BITMAP* images[6];
	ALLEGRO_BITMAP *image;
};
#endif
