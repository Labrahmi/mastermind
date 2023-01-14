/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mastermind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:07:10 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/01/14 22:41:20 by ylabrahm         ###   ########.fr       */
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
	int 	playes_moves[10][4];
	int		playes_results[10][4];
	int		winner_numbers[4];
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

void	ft_init_array(t_games *var)
{
	int i, j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			var->playes_moves[i][j] = -1;
			var->playes_results[i][j] = -1;
			j++;
		}
		i++;
	}
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
	ft_init_array(new_game);
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
			new_game->winner_numbers[i] = array[i];
			new_game->playes_moves[k][i] = user_resp[i];
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
			{
				new_game->playes_results[k][i] = result;
				printf("\033[1;28m\033[0m\033[1;31m%c\033[0m ", print_res(result));
			}
			i++;
			win += result;
		}
		if (win == 8)
		{
			printf("\nYou Won The Game!\n");
			sleep(4);
			new_game->won = 1;
			break;
		}
		printf("\n");
		j++;
		k++;
	}
	new_game->tryes = (j + 1);
	if ((j + 1) == 11)
		new_game->tryes--;
	time(&end_time);
	new_game->time = difftime(end_time, start_time);
	return (new_game);
}

int ft_count(t_queue *q)
{
	int	i;
	t_games	*new_game;

	new_game = q->head;
	i = 0;
	while (new_game)
	{
		new_game = new_game->next;
		i++;
	}
	return (i);
}

t_games	*ft_get_game(int id, t_queue *q)
{
	t_games	*new_game;
	
	new_game = q->head;
	while (new_game)
	{
		if (new_game->id == (id - 1))
			return (new_game);
		new_game = new_game->next;
	}
	return (NULL);
}

int main(void) 
{
	int		i, j;
	int		parties;
	int		user_menu_chosen_value;
	char	*user_name;
	t_games *new_game;
	int		c;
	
	

	
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
	
	
	while (1)
	{
		printf("\n");
		system("clear");
		usleep(300000);
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
			parties++;
		}
		if (user_menu_chosen_value == 2)
		{
			system("clear");
			int	count_nodes;
			int	chosen_partie;
			
			count_nodes = ft_count(&new_que);
			chosen_partie = 0;

			printf("You Have (%d) old parties\n", count_nodes);
			printf("Which one you want to see from (1 to %d): ", count_nodes);
			scanf("%d", &chosen_partie);
			fflush(stdin);
			
			if (!(chosen_partie >= 1 && chosen_partie <= count_nodes))
				break;
			else
			{
				new_game = ft_get_game(chosen_partie, &new_que);
				printf("\n\n");
				printf("		*) Game n : %d \n", (new_game->id + 1));
				printf("		*) Time   : %.0fs\n", new_game->time);
				printf("		*) Tryes  : %d \n", new_game->tryes);
				if (new_game->won == 1)
					printf("		*) Won   : Yes \n");
				else
					printf("		*) Won   : No \n");
				
				printf("		*) Winning Moves : ");
				i = 0;
				while (i < 4)
				{
					printf("%d ", new_game->winner_numbers[i]);
					i++;
				}
				printf("\n");
				printf("		*) Player Moves : \n");
				i = 0;
				while (i < new_game->tryes)
				{
					j = 0;
					printf("			");
					while (j < 4)
					{
						printf("%d ", new_game->playes_moves[i][j]);
						j++;
					}
					j = 0;
					printf("	|	");
					while (j < 4)
					{
						printf("\033[1;28m\033[0m\033[1;31m%c\033[0m ", print_res(new_game->playes_results[i][j]));
						j++;
					}
					printf("\n");
					i++;
				}
				printf("\n\n");
				printf("type [c] to continue : ");
				scanf("%d", &c);
				fflush(stdin);
			}
		}
		
		if (user_menu_chosen_value == 4)
		{
			system("clear");
			printf("GoodBye %s!\n", user_name);
			exit(0);
		}
	}
    return 0;
}
