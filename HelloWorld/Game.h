#pragma once

#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "Constants.h"

//Funktion that checks which value is larger, takes two floats as arguments, returns the larger float
float Max(float a, float b);


//Funktion that checks which value is larger, takes two floats as arguments, returns the smaller float
float Min(float a, float b);



//Innitiate Array
void innitArray();


//Creates file with scores from array
void createFile();


//Check nr of lines in file
int lineCount();


//Create array from file
void createArray();


//Delete Array
void deleteArray();


//Sorts High Score array
void sortArray();


//Updates array with new high score at end of game
void ArrUppd();


//Prints top five Saved High Scores
void HighScore();




//Resets the Bricks, Ball, and Paddle
void resetScene();


// Function that creates the bricks
void SetupScene();


//Function that creates a ball
void SpawnBall();






//Function that loops through the different game objects and updates and renders them to the viewport, takes a float as argument
void StepFrame(float timePassed);
