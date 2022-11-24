/* ************************************************************************** */
/*			                                                                */
/*                                                        :::      ::::::::   */
/*   parsing_map_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:10:31 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/10/26 13:10:37 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int if_0_or_1_or_player(char c)
{
	if (c != '1' && c != '0' && !if_player(c))
		return (0);
	return (1);
}

static void check_map_characters(char **map, int i, int j)
{
	while (map[i][j])
	{
		if ((!i || !map[i + 1]) && (map[i][j] == '0' || if_player(map[i][j])))
			msg_error(1);
		else if (map[i][j] == '0' || if_player(map[i][j]))
		{
			if (!if_0_or_1_or_player(map[i][j + 1])) // map[i][j + 1] != '1' && map[i][j + 1] != '0'&& !if_player(map[i][j + 1]))
				msg_error(1);
			if (!if_0_or_1_or_player(map[i][j - 1])) // map[i][j - 1] != '1' && map[i][j - 1] != '0'&& !if_player(map[i][j - 1]))
				msg_error(1);
			if (!if_0_or_1_or_player(map[i + 1][j - 1])) // map[i + 1][j - 1] != '1' && map[i + 1][j - 1] != '0'&& !if_player(map[i + 1][j - 1]))
				msg_error(1);
			if (!if_0_or_1_or_player(map[i + 1][j + 1])) // map[i + 1][j + 1] != '1' && map[i + 1][j + 1] != '0'&& !if_player(map[i + 1][j + 1]))
				msg_error(1);
			if (!if_0_or_1_or_player(map[i + 1][j])) // map[i + 1][j] != '1' && map[i + 1][j] != '0' &&!if_player(map[i + 1][j]))
				msg_error(1);
			if (!if_0_or_1_or_player(map[i - 1][j + 1])) // map[i - 1][j + 1] != '1' && map[i - 1][j + 1] != '0' && !if_player(map[i - 1][j + 1]))
				msg_error(1);
			if (!if_0_or_1_or_player(map[i - 1][j - 1])) // map[i - 1][j - 1] != '1' && map[i - 1][j - 1] != '0'&& !if_player(map[i - 1][j - 1]))
				msg_error(1);
			if (!if_0_or_1_or_player(map[i - 1][j])) // map[i - 1][j] != '1' && map[i - 1][j] != '0'&& !if_player(map[i - 1][j]))
				msg_error(1);
		}
		j++;
	}
}
void map_characters(char **map, int i, int j)
{

	if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ' && !if_player(map[i][j]) && map[i][0] != '\n')
	{
		// printf("%s\n", map[i]);
		msg_error(5);
	}
	if (i > 1)
	{

		if (map[i][j] == 'D')
		{
			if ((map[i - 1][j] != '1' || map[i + 1][j] != '1') && (map[i][j - 1] != '1' || map[i][j + 1] != '1'))
				msg_error(1);
		}
	}
}

void check_may_map(char **map, int i, int j, int k)
{
	char *s1;
	char *s2;

	k = 0;
	int d = 0;
	// while (map[d])
	// {
	// 	s1 = ft_strtrim(map[d], " \n");
	// 	printf(">>>>%s\n",s1);
	// 		d++;
	// }

	while (map[++i])
	{
		s1 = ft_strtrim(map[i], " \n");
		// if (!map[i + 1])
		// 	s2 = ft_strtrim(map[i + 1], " \n");
		if (!*s1)
		{
			msg_error(1);
		}
		j = -1;
		while (map[i][++j])
		{
			if (if_player(map[i][j]) && map[i][j] != 'D')
				k++;
			map_characters(map, i, j);
		}
		check_map_characters(map, i, 0);
		free(s1);
	}
	if (k != 1)
		msg_error(6);
}
