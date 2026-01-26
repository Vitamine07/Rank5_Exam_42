#ifndef LIFE_H
#define LIFE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef	struct s_game
{
	char	**grid;
	int		wid;
	int		hei;
	int		ite;
	int		x;
	int		y;
	int		draw;
} t_game;

#endif