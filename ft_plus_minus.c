/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigelrobinson <Nigel@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:20:00 by nigelrobinson     #+#    #+#             */
/*   Updated: 2023/05/15 17:06:12 by nigelrobinson    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/**
*
*  Description : EXERCISE plus_minus_de_Vincent
*
*	Guess the number between 1 and 10000 ( three levels of difficulties
*
*	Computer gives you a clue if it's higher or lower
*
*	This is how it should be prototyped :  void	ft_plus_minus(void);
*
*	Files to turn in: void	ft_plus_minus.c
*
* 	Allowed libary : all 
*
*  Args: void
*
*	Returns: void
*
*/
/**
***** headers
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

/**
**** Defines
*/

#define MIN 1
#define QUIT 0
#define EASY 10
#define NORMAL 100
#define HARD 10000

/**
**** Definitions of functions
*/

void	ft_print_head(void);
bool	compare_answer(int mistery_number, int guess);
void	ft_clear_scr(void);
bool	ft_play_again(void);
void	ft_win(int score);
bool	ft_is_not_digit(int nbr);
void	ft_question(int level);
void	ft_bye(void);
int	ft_level(void);

/**
**** principal game function
*/

int	ft_plus_minus(void)
{
	int		guess;
	int		mistery_number;
	bool	try_to_find;
	int level;
	int score;

	score = 0;
	mistery_number = 0;
	guess = 1;
	try_to_find = true;
	srand(time(NULL));
	ft_print_head();
	level = 0;
	level = ft_level();
	printf("\033[5A");
	while ((try_to_find == true) && (level != QUIT))
	{
		mistery_number = (rand() % (level - MIN + 1) + MIN);
		while (try_to_find > 0)
		{
			ft_question(level);
			while (scanf("%d", &guess) != 1)
			{
				fgetc(stdin);	
				ft_print_head();
				ft_question(level);
			}
			if (guess == QUIT)
			{
				ft_clear_scr();
				ft_bye();	
				return (0);
			}
			score++;
			if (compare_answer(mistery_number, guess))
			{
				ft_clear_scr();
				ft_win(score);
				if (ft_play_again())
				{
					try_to_find = true;
					score = 0;
					mistery_number = (rand() % (level - MIN + 1) + MIN);
				}
				else
					try_to_find = false;
			}
	 	}
	}
	return (0);
}

/**
**** check answer function returns true if the same as mistery number
*/

bool	compare_answer(int mistery_number, int guess)
{
	if (guess == 0)
		return (false);
	if (guess == mistery_number)
		return (true);
	if (guess > mistery_number)
		printf("                                                              C'est moins ! \n");
	if (guess < mistery_number)
		printf("                                                               C'est plus ! \n");
	return (false);
}

/**
**** Title header of the game - instructions and choice of level
*/

void	ft_print_head(void)
{
	ft_clear_scr();
	printf("/* ************************************************************************** */\n");
	printf("/* ************************************************************************** */\n");
	printf("/* ****                                                                  **** */\n");
	printf("/* ****                                                                  **** */\n");
	printf("/* ****               GUESSING GAME - GUESS THE NUMBER !                 **** */\n");
	printf("/* ****                                                                  **** */\n");
	printf("/* ****           EASY MODE - ADVANCED MODE - EXPERT MODE                **** */\n");
	printf("/* ****                                                                  **** */\n");
	printf("/* ****                  ENTER 0 TO QUIT THE GAME !                      **** */\n");
	printf("/* ****                                                                  **** */\n");
	printf("/* ****                       ????????????????                           **** */\n");
	printf("/* ****                                                                  **** */\n");
	printf("/* ****                                                                  **** */\n");
	printf("/* ************************************************************************** */\n");
	printf("/* ************************************************************************** */\n");
}

/**
**** clear screen and go to home-space positiom 1,1
*/

void	ft_clear_scr(void)
{
	printf("\033[2J");
	printf("\033[2H");
}

/**
**** Asks the question  play again ? and gets reply from user
*/

bool	ft_play_again(void)
{
	char answer = '\0';

	read(1, &answer, 1);
	if (answer == 'y')
	{
		printf("\033[25m");
		ft_clear_scr();
		ft_print_head();
		return (true);
	}
	else
	{
		printf("\033[25m");
		ft_clear_scr();
		return (false);	
	}
}

/**
**** Winners window with the score.
*/


void	ft_win(int score)
{
	printf("\033[5m");
	printf("/* ************************************************************************** */\n");
	printf("/* ************************************************************************** */\n");
	printf("/* ****                                                                  **** */\n");
	printf("/* ****                                                                  **** */\n");
	printf("/* ****              WELL DONE !! You found the number :-)               **** */\n");
	printf("/* ****                                                                  **** */\n");
	printf("/* ****                 \033[33m\033[25m It took %d atemptes to find it !      \033[5m\033[37m           **** */\n", score);
	printf("/* ****                                                                  **** */\n");
	printf("/* ****      \033[33m\033[25m          Do you wish to play again ?  y / n    \033[5m\033[37m            **** */\n");
	printf("/* ****                                                                  **** */\n");
	printf("/* ****                                                                  **** */\n");
	printf("/* ************************************************************************** */\n");
	printf("/* ************************************************************************** */\n");
}

/**
**** Prints the question on stdout
*/

void	ft_question(int level)
{
	printf("\n                   Quel est le nombre entre 1 et %d ?         ", level);
	printf("\n                                                              ");
	printf("\n                                                              ");
	printf("\n                                                              ");
	printf("\n                                                              ");
	printf("\033[4A");
}

/**
**** Exit sentence Saying good bye
*/

void	ft_bye(void)
{
	printf("                         Thanks for playing !\n\n");
}

/**
**** level coice selecter
*/

int	ft_level()
{
	int	level_choice;

	level_choice = 0;
	printf("\n              Which level do you want to play    (1) - EASY");
	printf("\n                                                 (2) - NORMAL");
	printf("\n                                                 (3) - HARD");
	printf("\n            PRESS THE KEY 1, 2 OR 3 TO CHOOSE ! : ");
	while ((scanf("%d", &level_choice) != 1) || ((level_choice > 3)))
	{
		fgetc(stdin);
	}
	while (1)
	{
		if (level_choice == 1)
			return (EASY);
		if (level_choice == 2)
			return (NORMAL);
		if (level_choice == 3)
			return (HARD);
		if (level_choice == 0)
		{
			ft_clear_scr();
			ft_bye();
			return (QUIT);
		}
	}
	ft_clear_scr();
	return (QUIT);
}
