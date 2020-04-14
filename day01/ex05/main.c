#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

static void	tankput(struct s_tank *tank)
{
	int	i;

	i = -1;
	while (++i <= tank->n)
		if (tank->stacks[i])
			printf("no: %d energy: %d\t", i + 1, tank->stacks[i]->sum);
	printf("\n");
}

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	int	energy;
	int	i;

	i = -1;
	while (++i < 30)
	{
		tankPush(tank, 10 * i);
		tankput(tank);
	}
	printf("is the tank empty: %d\n", tankIsEmpty(tank));
	while (!tankIsEmpty(tank))
	{
		energy = tankPop(tank);
		tankput(tank);
	}
	return (0);
}



// Function used for the test
// Don't go further :)
