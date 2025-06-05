#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "player.h"


player::~player()
{
	for (int i = 0; i < 6; i++) {
		al_destroy_bitmap(images[i]);
	}
}
player::player(int HEIGHT)
{	lives = 5;
	x = 20;
	y = HEIGHT / 2;
	speed = 7;
	score = 0;

	for (int i = 0; i < 6; i++) {
		images[i] = NULL;
	}
	images[0] = al_load_bitmap("kirby4.png");
	images[1] = al_load_bitmap("kirby4.png");
	images[2] = al_load_bitmap("kirby3.png");
	images[3] = al_load_bitmap("kirby2.png");
	images[4] = al_load_bitmap("kirby1.png");
	images[5] = al_load_bitmap("kirby0.png");
	
	image = images[lives];

	boundx = al_get_bitmap_width(image);
	boundy = al_get_bitmap_height(image);
}
void player::DrawPlayer()
{
	al_draw_bitmap(image, x, y, 0);
}
void player::removeLife() { 
	lives--;
	image = images[lives];
}
void player::MoveUp()
{
	y -= speed;
	if(y < 0)
		y = 0;
}
void player::MoveDown(int HEIGHT)
{
	y += speed;
	if((y + getBoundX()) > HEIGHT)
		y = (HEIGHT - getBoundX());
}
void player::MoveLeft()
{
	x -= speed;
	if(x < 0)
		x = 0;
}
void player::MoveRight()
{
	x += speed;
	if(x > 300)
		x = 300;
}
