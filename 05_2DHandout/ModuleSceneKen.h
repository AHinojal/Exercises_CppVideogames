#ifndef __MODULESCENEKEN_H__
#define __MODULESCENEKEN_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
typedef struct _Mix_Music Mix_Music;

class ModuleSceneKen : public Module
{
public:
	ModuleSceneKen( bool start_enabled = true);
	~ModuleSceneKen();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	
	SDL_Texture* graphics = nullptr;
	SDL_Rect ground;
	SDL_Rect background;
	//iPoint moveUpDownShip;
	SDL_Rect redShip;
	Animation flag;
	Animation girl;
	Animation gangtersGuys;
	Animation boy;
	Animation richGuy;
	Animation brownGuy;
	Animation purpleGuy;

};

#endif // __MODULESCENEKEN_H__