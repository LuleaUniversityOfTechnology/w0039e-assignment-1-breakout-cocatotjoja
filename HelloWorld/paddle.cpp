#include "paddle.h"

void MovePaddle(Paddle& paddle, float translationX)
{
	paddle.position.x += translationX;
}

void DrawPaddle(Paddle& paddle)
{
	const Play::Point2D bottomLeft = { paddle.position.x - (paddle.width / 2), paddle.position.y };
	const Play::Point2D topRigth = { paddle.position.x + (paddle.width / 2), paddle.position.y + paddle.height };
	Play::DrawRect(bottomLeft, topRigth, Play::cRed, true);
}

bool IsBounce(const Paddle& paddle, const Play::GameObject& obj)
{
	const Play::Point2D bottomLeft = { paddle.position.x - (paddle.width / 2), paddle.position.y };
	const Play::Point2D topRight = { paddle.position.x + (paddle.width / 2), paddle.position.y + paddle.height };
	
	const float dx = obj.pos.x - Max(bottomLeft.x, Min(obj.pos.x, topRight.x));
	const float dy = obj.pos.y - Max(bottomLeft.y, Min(obj.pos.y, topRight.y));
	return (dx * dx + dy * dy) < (obj.radius * obj.radius);
}
