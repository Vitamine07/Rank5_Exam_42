#include "bsq.h"

int	read_chars(FILE *file, t_map *map)
{
	if (fscanf(file, "%d%c%c%c", &map->hei, &map->chars.empty, &map->chars.obstacle, &map->chars.full) != 4)
		return (1);
	if (map->hei <= 0)
		return (1);
	if (map->chars.empty == map->chars.full || map->chars.empty == map->chars.obstacle || map->chars.full == map->chars.obstacle)
		return (1);
	if (map->chars.empty < 32 || map->chars.empty > 126)
		return (1);
	if (map->chars.full < 32 || map->chars.full > 126)
		return (1);
	if (map->chars.obstacle < 32 || map->chars.obstacle > 126)
		return (1);
	return (0);
}

void	free_grid(t_map *map)
{
	if (map->grid)
	{
		for (int i = 0; i < map->hei; i++)
		{
			if (map->grid[i])
				free(map->grid[i]);
		}
		free(map->grid);
	}
}

int	read_map(FILE *file, t_map *map)
{
	char	*line = NULL;
	ssize_t	bytes;
	size_t	len = 0;

	if (read_chars(file, map))
		return (1);
	map->grid = malloc(map->hei * sizeof(char*));
	if (!map->grid)
		return (1);
	for (int i = 0; i < map->hei; i++)
	{
		bytes = getline(&line, &len, file);
		if (bytes == -1)
			return (free_grid(map), free(line), 1);
		if (line[bytes - 1] != '\n')
			return (free_grid(map), free(line), 1);
		if (!i)
			map->wid = bytes - 1;
		else
		{
			if (map->wid < 1 || bytes - 1 != map->wid)
				return (free(line), free_grid(map), 1);
		}
		map->grid[i] = malloc(map->wid * sizeof(char));
		if (!map->grid[i])
			return (free_grid(map), free(line), 1);
		for (int j = 0; j < map->wid; j++)
		{
			if (line[j] != map->chars.empty && line[j] != map->chars.obstacle)
				return (free_grid(map), free(line), 1);
			map->grid[i][j] = line[j];
		}
	}
	free(line);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;
	FILE	*file;

	if (ac == 1)
	{
		if (!read_map(stdin, &map))
			fprintf(stderr, "Map error");
	}
	else
	{
		for (int i = 1; i < ac; i++)
		{
			file = fopen(av[i], "r");
			if (!file)
				fprintf(stderr, "Map error");
			if (!read_map(file, &map))
			{
				fprintf(stderr, "Map error");
				fclose(file);
			}
			find_bsq();
			print_bsq();
			fclose(file);
			fputc(stderr, "\n");
		}
	}

}