#pragma once
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struc s_game
{
	char **grid;
	int x;
	int y;
	int h;
	int w;
	int draw;
	int ite;
} t_game;


