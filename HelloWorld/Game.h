#pragma once

#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "Constants.h"

void SpawnBall();

void StepFrame(float timePassed, int& scoreCounter);

void SetupScene();

//Funktion that checks which value is larger, takes two floats as arguments, returns the larger float
float Max(float a, float b);


//Funktion that checks which value is larger, takes two floats as arguments, returns the smaller float
float Min(float a, float b);

