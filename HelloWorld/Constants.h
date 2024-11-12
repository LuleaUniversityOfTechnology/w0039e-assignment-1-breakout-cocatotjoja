#pragma once

const int DISPLAY_WIDTH = 640;
const int DISPLAY_HEIGHT = 360;
const int DISPLAY_SCALE = 2;
const float ballSpeed = 2.0f;


enum ObjectType
{
	TYPE_BALL,
	TYPE_BRICK
};

inline float Max(float a, float b)
{
	return a > b ? a : b;
}

inline float Min(float a, float b)
{
	return a < b ? a : b;
}
