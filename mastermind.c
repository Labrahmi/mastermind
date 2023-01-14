/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mastermind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:07:10 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/14 19:46:11 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/*
	time;
	tryes;
	playes_moves:
	[
		[1, 0, 1, 0]
		[1, 0, 1, 0]
		[1, 0, 1, 0]
		[1, 0, 1, 0]
	];
	playes_results:
	[
		['X', 'O', 'X', 'X']
		['X', 'O', 'X', 'X']
		['X', 'O', 'X', 'X']
		['X', 'O', 'X', 'X']
	];
*/

typedef struct s_games
{
	double	time;
	int		id;
	int		tryes;
	int		won;
	int 	**playes_moves;
	int		**playes_results;
	struct s_games *next;
}	t_games;

typedef struct s_queue
{
	t_games	*head;
	t_games	*tail;
}	t_queue;

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

void	ft_enqueue(t_queue *q, t_games *data)
{
	if (q->head == NULL)
		q->head = data;
	else
		q->tail->next = data;
	q->tail = data;
	
}

t_games	*ft_set_game(int parties)
{
	int	array[4];
	int	user_resp[4];
    int	i;
	int	j;
	int	k;
	int	result;
	int win;
	time_t start_time, end_time;
	double elapsed_time;
	// -
	t_games	*new_game;

	time(&start_time);
	new_game = (t_games *) malloc(sizeof(t_games));
	new_game->id = parties;
	new_game->time = 0;
	new_game->tryes = 0;
	new_game->won = 0;
	new_game->next = NULL;
	new_game->playes_moves = NULL;
	new_game->playes_results = NULL;

	
	new_game->playes_moves = (int **) malloc(sizeof(int *));

	

/*
	time_t start_time, end_time;
	double elapsed_time;
	time(&start_time);
	sleep(3);
	usleep(100000);
	time(&end_time);
	elapsed_time = difftime(end_time, start_time);
	printf("Elapsed time is: %f\n", elapsed_time);
	return 0;
*/	




	srand(time(0));
	for (i = 0; i < 4; i++)
	{
		int random_num = (rand() % 5);
		array[i] = random_num;
	}
	printf("\n\n%d %d %d %d\n\n", array[0], array[1], array[2], array[3]);
	j = 0;
	k = 0;
	while (j < 10)
	{
		printf("Give Your Numbers: ");
		scanf("%d %d %d %d", &user_resp[0], &user_resp[1], &user_resp[2], &user_resp[3]);
		fflush(stdin);
		i = 0;
		while (i < 4)
		{
			printf("K:%d\n", k);
			printf("i:%d\n", i);
			printf("user_resp[i]:%d\n", user_resp[i]);
			new_game->playes_moves[k] = (int *) malloc(sizeof(int));
			new_game->playes_moves[k][i] = user_resp[i];
			printf("[%d]\n", new_game->playes_moves[k][i]);
			sleep(1);
			printf("-\n");
			i++;
		}
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
			new_game->won = 1;
			break;
			// printf("\nYou Win The Game\n");
			// return 0;
		}
		printf("\n");
		j++;
		k++;
	}
	new_game->tryes = (j + 1);
	if ((j + 1) == 11)
		new_game->tryes--;
	// printf("\nHard Luck Next Time!\n");
	time(&end_time);
	new_game->time = difftime(end_time, start_time);
	return (new_game);
}



int main(void) 
{
	int		parties;
	int		user_menu_chosen_value;
	char	*user_name;
	

	
	parties = 0;
	/* - */
	t_queue new_que;
	
	new_que.head = NULL;
	new_que.tail = NULL;
	/* - */

	user_name = calloc(128, sizeof(char));
	printf("Please Enter Your Name: ");
	scanf("%s", user_name);
	fflush(stdin);
	system("clear");
	printf("Welcome To Mastermind Game, %s\n", user_name);
	printf("please choose an option: \n");
	choose:
	// -
	printf("\n\n");
	printf("	[1]: Play a new game\n");
	printf("	[2]: See History\n");
	printf("	[3]: See Game rules\n");
	printf("	[4]: Exit\n");
	printf("\n\n");
	// -
	scanf("%d", &user_menu_chosen_value);
	fflush(stdin);
	if (!(user_menu_chosen_value == 1 || user_menu_chosen_value == 2 || user_menu_chosen_value == 3 || user_menu_chosen_value == 4))
	{
		fflush(stdout);
	    system("clear");
		printf("please choose a valid number!\n");
		goto choose;
	}
	if (user_menu_chosen_value == 1)
	{
		ft_enqueue(&new_que, ft_set_game(parties));
		printf("\nid:%d\ntime:%f\ntryes:%d\nwon:%d\n", new_que.head->id, new_que.head->time, new_que.head->tryes, new_que.head->won);
		printf("%d ", new_que.head->playes_moves[0][0]);
		printf("%d ", new_que.head->playes_moves[0][1]);
		printf("%d ", new_que.head->playes_moves[0][2]);
		printf("%d ", new_que.head->playes_moves[0][3]);
		parties++;
	}
    return 0;
}
