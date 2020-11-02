#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "SDL/include/SDL.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA
ModulePlayer::ModulePlayer(bool start_enabled) : Module(start_enabled)
{
	// Draw static Ryu
	/*ryu.x = 8;
	ryu.y = 14;
	ryu.w = 58;
	ryu.h = 90;*/

	position.x = 50; //100
	position.y = 108; //216

	// idle animation (arcade sprite sheet)
	idle.frames.push_back({7, 14, 60, 90});
	idle.frames.push_back({95, 15, 60, 89});
	idle.frames.push_back({184, 14, 60, 90});
	idle.frames.push_back({276, 11, 60, 93});
	idle.frames.push_back({366, 12, 60, 92});
	idle.speed = 0.2f;
	
	// walk backward animation (arcade sprite sheet)
	backward.frames.push_back({542, 131, 61, 87});
	backward.frames.push_back({628, 129, 59, 90});
	backward.frames.push_back({713, 128, 57, 90});
	backward.frames.push_back({797, 127, 57, 90});
	backward.frames.push_back({883, 128, 58, 91});
	backward.frames.push_back({974, 129, 57, 89});
	backward.speed = 0.1f;

	// OK -- TODO 8: setup the walk forward animation from ryu4.png
	forward.frames.push_back({ 7, 131, 55, 92 });
	forward.frames.push_back({ 77, 130, 52, 94 });
	forward.frames.push_back({ 160, 130, 67, 93 });
	forward.frames.push_back({ 258, 128, 66, 91 });
	forward.frames.push_back({ 351, 127, 56, 93 });
	forward.frames.push_back({ 432, 131, 51, 89 });
	forward.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{
	// TODO 12: Homework : check for memory leaks
}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("ryu4.png"); // arcade version

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}

// Update
update_status ModulePlayer::Update()
{
	// TODO 9: Draw the player with its animation
	// make sure to detect player movement and change its
	// position while cycling the animation(check Animation.h)
	//App->renderer->Blit(graphics, position.x, position.y, &(idle.GetCurrentFrame()), 2.0f); // static ryu
	// App->renderer->Blit(graphics, position.x, position.y, &(backward.GetCurrentFrame()), 2.0f); // backward ryu
	App->renderer->Blit(graphics, position.x, position.y, &(forward.GetCurrentFrame()), 2.0f); // forward ryu


	return UPDATE_CONTINUE;
}