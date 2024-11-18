#pragma once
#include "Game.h"


//Struct containing position and size values for Paddle
struct Paddle
{
	Play::Point2D position = { DISPLAY_WIDTH/2, 20 };
	int width = 50;
	int height = 8;
};



void resetPaddle(Paddle& paddle);

void MovePaddle(Paddle& paddle, float translationX);

void DrawPaddle(Paddle& paddle);

bool IsBounce(const Paddle& paddle, const Play::GameObject& obj);
