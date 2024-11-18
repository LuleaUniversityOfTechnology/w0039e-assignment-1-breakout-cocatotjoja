#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "Game.h"
#include "paddle.h"


Paddle paddle;
unsigned int scoreCounter = 0;

// Array for top Scores
unsigned int topScore[5] = {1, 2, 3, 4, 5};


//Sorts High Score array
void sortArray()
{
	std::sort(std::begin(topScore), std::end(topScore), greater<>());
}


//Prints top five Saved High Scores
void HighScore()
{
	int newRow = 100;

	Play::DrawDebugText({ DISPLAY_WIDTH - 60, 120 }, "High Scores");
	for (int i = 0; i < 5; i++)
	{
		std::string strScore = std::to_string(topScore[i]);
		Play::DrawDebugText({ DISPLAY_WIDTH - 50, newRow }, strScore.c_str());
		newRow -= 20;
	}
}

//Updates array with new high score at end of game
void ArrUppd()
{
	if (scoreCounter > topScore[4])
	{
		topScore[4] = scoreCounter;
		scoreCounter = 0;

		std::sort(std::begin(topScore), std::end(topScore), greater<>());
	}
}


//Funktion that checks which value is larger, takes two floats as arguments, returns the larger float
float Max(float a, float b)
{
	if (a > b)
		return a;
	else
		return b;
}

//Funktion that checks which value is larger, takes two floats as arguments, returns the smaller float
float Min(float a, float b)
{
	if (a < b)
		return a;
	else
		return b;
}



//Function that creates a ball
void SpawnBall()
{
	const int objectId = Play::CreateGameObject(ObjectType::TYPE_BALL, { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT - 200 }, 4, "ball");
	GameObject& ball = Play::GetGameObject(objectId);
	ball.velocity = normalize({ -1, -1 }) * ballSpeed;
}


//Function that loops through the different game objects and updates and renders them to the viewport, takes a float as argument
void StepFrame(float timePassed)
{
	//Make a list of the different ObjectTypes
	const std::vector<int> brickIds = Play::CollectGameObjectIDsByType(TYPE_BRICK);
	const std::vector<int> ballIds = Play::CollectGameObjectIDsByType(TYPE_BALL);

	
	
	HighScore();
	
	
	//Checks for user input and update paddle position
	if (Play::KeyDown(Play::KEY_RIGHT))
	{
		MovePaddle(paddle, 3.0);
	}

	if (Play::KeyDown(Play::KEY_LEFT))
	{
		MovePaddle(paddle, -3.0);
	}

	DrawPaddle(paddle);


	
	//Check if brick should be removed, loops through all bricks
	for (int brick : brickIds)
	{
		GameObject& currentBrick = Play::GetGameObject(brick);
		for (int ball : ballIds)
		{
			GameObject& currentBall = Play::GetGameObject(ball);
			if (Play::IsColliding(currentBrick, currentBall))
			{
				Play::DestroyGameObject(brick);
				currentBall.velocity.y *= -1;
				scoreCounter++;
			}
		}
		
		std::string strCount = std::to_string(scoreCounter);
		Play::DrawDebugText({ 20, 20 }, strCount.c_str());

		Play::UpdateGameObject(Play::GetGameObject(brick));
		Play::DrawObject(Play::GetGameObject(brick));
	}


	//Checks ball location and collisions, and updates velocity
	for (int ball : ballIds)
	{
		GameObject& obj_ball = Play::GetGameObject(ball);
		
		if (IsBounce(paddle, obj_ball))
		{
			obj_ball.velocity.y *= -1;
		}

		if ((obj_ball.pos.x > DISPLAY_WIDTH-5) || (obj_ball.pos.x < 0))
		{
			obj_ball.velocity.x *= -1;
		}

		if (obj_ball.pos.y > DISPLAY_HEIGHT-5)
		{
			obj_ball.velocity.y *= -1;
		}

		if (obj_ball.pos.y < 0)
		{
			ArrUppd();
		}

		Play::UpdateGameObject(Play::GetGameObject(ball));
		Play::DrawObject(Play::GetGameObject(ball));
	}
}



// Function that creates the bricks
void SetupScene()
{
	for (int x = 6; x < DISPLAY_WIDTH-5; x+=17)
	{
		for (int y = DISPLAY_HEIGHT-15; y > 200; y-=11)
		{
			const int objectId = Play::CreateGameObject(ObjectType::TYPE_BRICK, { x, y }, 6, "brick");
		}
	}
}
