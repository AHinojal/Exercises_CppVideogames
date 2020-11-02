#include "Globals.h"
#include "Application.h"
#include "ModuleSceneHonda.h"
#include "ModuleSceneKen.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL.h"

ModuleSceneHonda::ModuleSceneHonda(bool start_enabled) : Module(start_enabled)
{
	// ground
	ground.x = 8;
	ground.y = 391;
	ground.w = 896;
	ground.h = 72;

	// OK -- TODO 2 : setup the foreground (red ship) with
	// coordinates x,y,w,h from ken_stage.png
	redShip.x = 8;
	redShip.y = 23;
	redShip.w = 523;
	redShip.h = 181;

	// Background / sky
	background.x = 72;
	background.y = 208;
	background.w = 768;
	background.h = 176;

	// flag animation
	flag.frames.push_back({ 848, 208, 40, 40 });
	flag.frames.push_back({ 848, 256, 40, 40 });
	flag.frames.push_back({ 848, 304, 40, 40 });
	flag.speed = 0.08f;

	// OK -- TODO 4: Setup Girl Animation from coordinates from ken_stage.png
	girl.frames.push_back({ 624, 16, 32, 56 });
	girl.frames.push_back({ 624, 80, 32, 56 });
	girl.frames.push_back({ 624, 144, 32, 56 });
	girl.speed = 0.08f;

	// OK -- TODO 4.2: Setup NPC Animation from coordinates from ken_stage.png
	gangtersGuys.frames.push_back({ 552, 16, 64, 64 });
	gangtersGuys.frames.push_back({ 552, 80, 64, 56 });
	gangtersGuys.frames.push_back({ 552, 144, 64, 56 });
	gangtersGuys.speed = 0.08f;

	boy.frames.push_back({ 664, 16, 32, 56 });
	boy.frames.push_back({ 664, 80, 32, 56 });
	boy.speed = 0.08f;

	richGuy.frames.push_back({ 704, 16, 48, 56 });
	richGuy.frames.push_back({ 704, 80, 48, 56 });
	richGuy.frames.push_back({ 704, 144, 48, 56 });
	richGuy.speed = 0.08f;

	brownGuy.frames.push_back({ 760, 16, 40, 40 });
	brownGuy.frames.push_back({ 760, 64, 40, 40 });
	brownGuy.frames.push_back({ 760, 112, 40, 40 });
	brownGuy.speed = 0.08f;

	purpleGuy.frames.push_back({ 808, 24, 48, 32 });
	purpleGuy.frames.push_back({ 808, 72, 48, 32 });
	purpleGuy.frames.push_back({ 808, 120, 48, 32 });
	purpleGuy.speed = 0.08f;
}

ModuleSceneHonda::~ModuleSceneHonda()
{}

// Load assets
bool ModuleSceneHonda::Start()
{
	LOG("Loading honda scene");

	graphics = App->textures->Load("honda_stage.png");

	// OK -- TODO 7: Enable the player module
	App->player->Enable();
	// OK -- TODO 0: trigger background music
	App->audio->PlayMusic("honda.ogg");

	return true;
}

// UnLoad assets
bool ModuleSceneHonda::CleanUp()
{
	LOG("Unloading honda scene");

	App->textures->Unload(graphics);
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleSceneHonda::Update()
{
	// TODO 5: make sure the ship goes up and down

	// Draw everything --------------------------------------
	// OK -- TODO 1: Tweak the parallax movement speed of the sea&sky + flag to your taste
	// To modify the speed, you have to change the forth parameter
	// (In this case, has to be the same speed in both texture, because if you put different speeds, the flag goes to shit)
	App->renderer->Blit(graphics, 0, 0, &background, 2.0f); // sea and sky
	App->renderer->Blit(graphics, 560, 8, &(flag.GetCurrentFrame()), 2.0f); // flag animation

	// OK -- TODO 3: Draw the ship. Be sure to tweak the speed.
	App->renderer->Blit(graphics, 0, 0, &redShip, 2.0f); // redShip
	// OK -- TODO 6: Draw the girl. Make sure it follows the ship movement!
	App->renderer->Blit(graphics, 192, 105, &(girl.GetCurrentFrame()), 2.0f); // girl animation
	// OK -- TODO 6.2: Draw the other NPC in the ship. Make sure it follows the ship movement!
	App->renderer->Blit(graphics, 128, 105, &(gangtersGuys.GetCurrentFrame()), 2.0f); // gansters animation
	App->renderer->Blit(graphics, 224, 105, &(boy.GetCurrentFrame()), 2.0f); // boy animation
	App->renderer->Blit(graphics, 288, 97, &(richGuy.GetCurrentFrame()), 2.0f); // richGuy animation
	App->renderer->Blit(graphics, 88, 25, &(brownGuy.GetCurrentFrame()), 2.0f); // brownGuy animation
	App->renderer->Blit(graphics, 128, 25, &(purpleGuy.GetCurrentFrame()), 2.0f); // purpleGuy animation
	App->renderer->Blit(graphics, 0, 170, &ground);

	// TODO 10: Build an entire new scene "honda", you can find its
	// and music in the Game/ folder

	// TODO 11: Make that pressing space triggers a switch to honda logic module
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT) {
		LOG("PRESSING SPACE");
		App->fade->FadeToBlack(App->scene_ken, App->scene_honda, 3.0f);
	}
	// using FadeToBlack module

	return UPDATE_CONTINUE;
}