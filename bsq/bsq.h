#ifndef BSQ_H
#define BSQ_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>


typedef struct s_chars
{
	char	empty;
	char	obstacle;
	char	full;
}	t_chars;

typedef struct s_map
{
	int	wid;
	int	hei;
	char	**grid;
	t_chars	chars;
}	t_map;

typedef struct s_sq
{
	int	x;
	int	y;
	int	size;
}	t_sq;

#endif