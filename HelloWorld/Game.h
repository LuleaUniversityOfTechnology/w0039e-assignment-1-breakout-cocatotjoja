#pragma once

#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "Constants.h"

//Funktion that checks which value is larger, takes two floats as arguments, returns the larger float
float Max(float a, float b);


//Funktion that checks which value is larger, takes two floats as arguments, returns the smaller float
float Min(float a, float b);


void SpawnBall();

void StepFrame(float timePassed);

void SetupScene();

void resetScene();

void HighScore();

void ArrUppd();

void sortArray();

