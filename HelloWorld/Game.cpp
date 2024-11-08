#define PLAY_IMPLEMENTATION
#include "Game.h"

void SpawnBall()
{
	const int objectId = Play::CreateGameObject(ObjectType::TYPE_BALL, { DISPLAY_WIDTH / 2, 
	DISPLAY_HEIGHT - 60 }, 4, "ball");
}

void StepFrame(float timePassed)
{
	const std::vector<int> ballIds = Play::CollectGameObjectIDsByType(TYPE_BALL);
}
