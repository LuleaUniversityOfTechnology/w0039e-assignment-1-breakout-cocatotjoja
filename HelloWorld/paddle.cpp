#include "paddle.h"



//Resets Paddle Position
void resetPaddle(Paddle& paddle)
{
	paddle.position.x = DISPLAY_WIDTH / 2;
}



//Function to update paddle position, takes a Paddle and a float value as arguments
void MovePaddle(Paddle& paddle, float translationX)
{
	paddle.position.x += translationX;
}


//Function to draw paddle, takes a Paddel as argument
void DrawPaddle(Paddle& paddle)
{
	const Play::Point2D bottomLeft = { paddle.position.x - (paddle.width / 2), paddle.position.y };
	const Play::Point2D topRigth = { paddle.position.x + (paddle.width / 2), paddle.position.y + paddle.height };
	Play::DrawRect(bottomLeft, topRigth, Play::cRed, true);
}


//Function that checks collision between paddle and object, takes a Paddle and a Object as arguments
bool IsBounce(const Paddle& paddle, const Play::GameObject& obj)
{
	const Play::Point2D bottomLeft = { paddle.position.x - (paddle.width / 2), paddle.position.y };
	const Play::Point2D topRight = { paddle.position.x + (paddle.width / 2), paddle.position.y + paddle.height };
	
	const float dx = obj.pos.x - Max(bottomLeft.x, Min(obj.pos.x, topRight.x));
	const float dy = obj.pos.y - Max(bottomLeft.y, Min(obj.pos.y, topRight.y));
	return (dx * dx + dy * dy) < (obj.radius * obj.radius);
}
