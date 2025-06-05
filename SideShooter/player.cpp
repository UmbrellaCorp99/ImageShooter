//Alexander Young
//Lab 8

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "player.h"

//This is a deconstructor for the player class. It destroys all the bitmaps stored ib the images array and the image bitmap
//Takes no parameters
//No return
player::~player()
{
	for (int i = 0; i < 6; i++) {
		al_destroy_bitmap(images[i]);
	}
	al_destroy_bitmap(image);
}

//This is the constructor for the player class. It stores five bitmaps loading images into the images array and sets the image bitmap equal to the images index that matches the lives variable.
//Takes an integer representing the display height as a parameter
//No return
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

//This function draws a specified bitmap
//Takes no parameters
//No return
void player::DrawPlayer()
{
	al_draw_bitmap(image, x, y, 0);
}

//This function decrememnts the lives variable and changes the images index from which the new image bitmap will pull it's image from
//No parameters
//No return
void player::removeLife() { 
	lives--;
	image = images[lives];
}

//This function moves the player up
//Takes no parameters
//No return
void player::MoveUp()
{
	y -= speed;
	if(y < 0)
		y = 0;
}

//This function moves the player down
//Takes no parameters
//No return
void player::MoveDown(int HEIGHT)
{
	y += speed;
	if((y + getBoundX()) > HEIGHT)
		y = (HEIGHT - getBoundX());
}

//This function moves the player left
//Takes no parameters
//No return
void player::MoveLeft()
{
	x -= speed;
	if(x < 0)
		x = 0;
}

//This function moves the player right
//Takes no parameters
//No return
void player::MoveRight()
{
	x += speed;
	if(x > 300)
		x = 300;
}
