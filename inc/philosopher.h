/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** header file
*/

#ifndef PHILO
#define PHILO

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extern.h"

#define TIME_EAT 200
#define TIME_THINKS 200
#define TIME_REST 400

typedef struct	s_philo
{
	pthread_t	thread;
	int		stick;
	pthread_mutex_t	mutex;
}		t_philo;

typedef struct	arg_s
{
	int	e;
	int	p;
}		arg_t;

extern arg_t	arg;
extern t_philo	*assembl;

void	parsing_arg(int *nbr_e, int *nbr_p, int ac, char **av);
void	philosopher(void);
void	*game(void *arg);
void	thinks(int id);
void	eat(int id);
void	rest(int id);

#endif
