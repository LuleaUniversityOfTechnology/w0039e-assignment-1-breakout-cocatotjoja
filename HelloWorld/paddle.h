#pragma once
#include "Game.h"


struct Paddle
{
	Play::Point2D position = { DISPLAY_WIDTH/2, 20 };
	int width = 50;
	int height = 8;
};

void MovePaddle(Paddle& paddle, float translationX);

void DrawPaddle(Paddle& paddle);

bool IsBounce(const Paddle& paddle, const Play::GameObject& obj);
