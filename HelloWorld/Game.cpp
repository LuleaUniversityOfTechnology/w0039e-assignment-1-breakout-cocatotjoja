#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "Game.h"

void SpawnBall()
{
	const int objectId = Play::CreateGameObject(ObjectType::TYPE_BALL, { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT - 350 }, 4, "ball");
	GameObject& ball = Play::GetGameObject(objectId);
	ball.velocity = normalize({ 1, 1 }) * ballSpeed;
}

void StepFrame(float timePassed)
{
	const std::vector<int> ballIds = Play::CollectGameObjectIDsByType(TYPE_BALL);
	for (int i = 0; i < ballIds.size(); i++)
	{
		GameObject& obj_ball = Play::GetGameObject(ballIds[i]);
		if ((obj_ball.pos.x > DISPLAY_WIDTH-5) || (obj_ball.pos.x < 0))
		{
			obj_ball.velocity.x = obj_ball.velocity.x * -1;
		}

		if ((obj_ball.pos.y > DISPLAY_HEIGHT-5) || (obj_ball.pos.y < 0))
		{
			obj_ball.velocity.y = obj_ball.velocity.y * -1;
		}

		Play::UpdateGameObject(Play::GetGameObject(ballIds[i]));
		Play::DrawObject(Play::GetGameObject(ballIds[i]));
	}
	const std::vector<int> brickIds = Play::CollectGameObjectIDsByType(TYPE_BRICK);
	for (int i = 0; i < brickIds.size(); i++)
	{
		Play::UpdateGameObject(Play::GetGameObject(ballIds[i]));
		Play::DrawObject(Play::GetGameObject(brickIds[i]));
	}
}


void SetupScene()
{
	for (int x = 0; x < DISPLAY_WIDTH; x++)
	{
		for (int y = DISPLAY_HEIGHT; y > 0; y--)
		{
			Play::CreateGameObject(ObjectType::TYPE_BRICK, { x, y }, 6, "brick");
		}
	}
}
