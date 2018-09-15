/*
** EPITECH PROJECT, 2018
** philosophers
** File description:
** main file
*/

#include "philosopher.h"

t_philo	*assembl;
arg_t	arg;

int	main(int ac, char **av)
{
	int	nbr_p = -1;
	int	nbr_e = -1;

	parsing_arg(&nbr_e, &nbr_p, ac, av);
	RCFStartup(ac, av);
	arg.p = nbr_p;
	arg.e = nbr_e;
	philosopher();
	RCFCleanup();
	return (0);
}

/*
** parsing and error handling argument
*/
void	parsing_arg(int *nbr_e, int *nbr_p, int ac, char **av)
{
	int	i;

	for (i = 1; i < ac; ++i) {
		if (strcmp("-p", av[i]) == 0 && (i + 1) < ac)
			*nbr_p = atoi(av[i+1]);
		if (strcmp("-e", av[i]) == 0 && (i + 1) < ac)
			*nbr_e = atoi(av[i+1]);
	}
	if (*nbr_p <= 1 || *nbr_e < 0)
		exit(84);
}

/*
** Creation and Waiting of all thread
*/
void	philosopher(void)
{
	int	*i = malloc(sizeof(*i));;

	assembl = malloc(sizeof(t_philo) * arg.p);
	*i = 0;
	for (; *i < arg.p; (*i)++) {
		assembl[*i].stick = 1;
		pthread_mutex_init(&(assembl[*i].mutex), NULL);
	}
	for (*i = 0; *i < arg.p; (*i)++) {
		if (pthread_create(&(assembl[*i].thread), NULL,
				game, (void *) i) == -1)
			exit(84);
		usleep(400);
	}
	for (*i = 0; *i < arg.p; (*i)++) {
		if (pthread_join(assembl[*i].thread, NULL))
			exit(84);
	}
}
