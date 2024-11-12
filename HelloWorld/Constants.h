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

//Funktion that checks which value is larger, takes two floats as arguments, returns the larger float
inline float Max(float a, float b)
{
	return a > b ? a : b;
}


//Funktion that checks which value is larger, takes two floats as arguments, returns the smaller float
inline float Min(float a, float b)
{
	return a < b ? a : b;
}
