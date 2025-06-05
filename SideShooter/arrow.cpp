//Alexander Young
//Lab 8

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "Arrow.h"

//This is a constructor for the arrow class
//Takes no parameters
//No return
Arrow::Arrow()
{
	speed = 10;
	live = false;
	image = al_load_bitmap("arrow.png");
}

//This is a deconstructor for the arrow class
//Takes no parameters
//No return
Arrow::~Arrow()
{
	al_destroy_bitmap(image);
}

//This fucntion draws an arrow with a 90 degree rotation
//Takes no parameters
//No return
void Arrow::DrawArrow()
{

	if(live)
		al_draw_rotated_bitmap(image,al_get_bitmap_width(image)/2,al_get_bitmap_height(image)/2,x,y,90,0);

}

//This function records the player location and sets live to true to indicate that an arrow should be drawb
//Takes a player object as a parameter
//No return
void Arrow::FireArrow(player &Player)
{
	if(!live)
	{
		x = Player.getX();
		y = Player.getY();
		live = true;
	}
}

//This function moves the arrow to the right
//Takes an integer representing the display's width as a parameter
//No return
void Arrow::UpdateArrow(int WIDTH)
{
	if(live)
	{
		x += speed;
		if(x > WIDTH)
			live = false;
	}
}

//This function determines if an arrow touches a ghost bitmap. If so, it changes the live status for both the arrow and the ghost to false, as well as updates the player's score
//Takes a ghost object, a player object, and the number of ghosts as a parameter
//No return
void Arrow::CollideArrow(ghost ghosts[], int cSize, player &Player)
{
	if(live)
	{
		for(int j =0; j < cSize; j++)
		{
			if(ghosts[j].getLive())
			{
				if(x > (ghosts[j].getX() - ghosts[j].getBoundX()) &&
					x < (ghosts[j].getX() + ghosts[j].getBoundX()) &&
					y > (ghosts[j].getY() - ghosts[j].getBoundY()) &&
					y < (ghosts[j].getY() + ghosts[j].getBoundY()))
				{
					live = false;
					ghosts[j].setLive(false);
					Player.updateScore(1);
				}
			}
		}
	}

}