#include "Globals.h"
#include "Application.h"
#include "ModuleScene.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "SDL/include/SDL.h"

ModuleScene::ModuleScene()
{
}

ModuleScene::~ModuleScene()
{
}

bool ModuleScene::Init()
{
	// Load the selected texture 
	if (!texture) {
		texture = App->textures->Load("sprites.png");
	}

	return true;
}

update_status ModuleScene::Update()
{
	// Show the exactly pixels that we select
	SDL_Rect space { 50,50,50,50 };
	App->renderer->Blit(texture,50,50, &space);

	return UPDATE_CONTINUE;
}

bool ModuleScene::CleanUp()
{
	return true;
}
