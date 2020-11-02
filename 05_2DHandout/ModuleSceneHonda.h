#ifndef __MODULESCENEHONDA_H__
#define __MODULESCENEHONDA_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct SDL_Rect;
typedef struct _Mix_Music Mix_Music;

class ModuleSceneHonda : public Module
{
public:
	ModuleSceneHonda(bool start_enabled = true);
	~ModuleSceneHonda();

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

#endif // __MODULESCENEHONDA_H__