/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mastermind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:07:10 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/14 17:48:49 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	check_exist(int user, int *array)
{
	int i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < 4)
	{
		if (user == array[i])
			ret = 1;
		i++;
	}
	return (ret);
}

int	check_pos(int user, int array_e)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (user == array_e)
		ret = 1;
	return (ret);
}

char	print_res(int res)
{
	if (res == 1)
		return 'X';
	if (res == 2)
		return 'O';
	return 0;
}

int main(void) 
{
	int	array[4];
	int	user_resp[4];
    int	i;
	int	j;
	int	result;
	int win;

    srand(time(0));
    for (i = 0; i < 4; i++)
	{
        int random_num = (rand() % 5);
		array[i] = random_num;
    }
	// printf("%d, %d, %d, %d\n", array[0], array[1], array[2], array[3]);
	j = 0;
	while (j < 10)
	{
		printf("Give Your Numbers: ");
		scanf("%d %d %d %d", &user_resp[0], &user_resp[1], &user_resp[2], &user_resp[3]);
		fflush(stdin);
		i = 0;
		printf("|");
		while (i < 4)
		{
			printf (" %d |", user_resp[i]);
			i++;
		}
		printf(" ");
		i = 0;
		win = 0;
		while (i < 4)
		{
			result = 0;
			result += check_exist(user_resp[i], array);
			result += check_pos(user_resp[i], array[i]);
			if (result)
				printf("\033[1;28m\033[0m\033[1;31m%c\033[0m ", print_res(result));
			i++;
			win += result;
		}
		if (win == 8)
		{
			printf("\nYou Win The Game\n");
			return 0;
		}
		printf("\n");
		j++;
	}
	printf("\nHard Luck Next Time!\n");
    return 0;
}
