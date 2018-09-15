/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** function philosopher for each thread
*/

#include "philosopher.h"

/*
** threads corp
*/
void	*game(void *argu)
{
	int	id = *((int *) argu);
	int	idp = (id + 1) % arg.p;
	int	nbeat = 0;

	while (nbeat < arg.e) {
		if (assembl[id].stick == 1 && assembl[idp].stick == 1) {
			thinks(id);
			eat(id);
			nbeat ++;
			rest(id);
		}
	}
	pthread_exit(NULL);
}

/*
** thinking fonction for philosopher
*/
void	thinks(int id)
{
	pthread_mutex_lock(&(assembl[id].mutex));
	lphilo_take_chopstick(&(assembl[id].mutex));
	assembl[id].stick = 0;
	lphilo_think();
	pthread_mutex_unlock(&(assembl[id].mutex));
	usleep(TIME_THINKS);
	pthread_mutex_lock(&(assembl[id].mutex));
	lphilo_release_chopstick(&(assembl[id].mutex));
	pthread_mutex_unlock(&(assembl[id].mutex));
}

/*
** eating fonction for philosopher 
*/
void	eat(int id)
{
	int	idp = (id + 1) % arg.p;

	pthread_mutex_lock(&(assembl[id].mutex));
	assembl[idp].stick = 0;
	assembl[id].stick = 0;
	lphilo_take_chopstick(&(assembl[id].mutex));
	lphilo_take_chopstick(&(assembl[idp].mutex));
	lphilo_eat();
	pthread_mutex_unlock(&(assembl[id].mutex));
	usleep(TIME_EAT);
	pthread_mutex_lock(&(assembl[id].mutex));
	assembl[idp].stick = 1;
	assembl[id].stick = 1;
	lphilo_release_chopstick(&(assembl[id].mutex));
	lphilo_release_chopstick(&(assembl[idp].mutex));
	pthread_mutex_unlock(&(assembl[id].mutex));
}

/*
** resting fonction for philosopher
*/
void	rest(int id)
{
	pthread_mutex_lock(&(assembl[id].mutex));
	lphilo_sleep();
	pthread_mutex_unlock(&(assembl[id].mutex));
	usleep(TIME_REST);
	pthread_mutex_lock(&(assembl[id].mutex));
	pthread_mutex_unlock(&(assembl[id].mutex));
}
