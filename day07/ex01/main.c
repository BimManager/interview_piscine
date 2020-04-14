#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

static void	deque_test(void)
{
	struct s_deque	*deque;
	int				value;
	int				i;

	sranddev();
	deque = dequeInit();
	printf("isEmpty: %d\n", isEmpty(deque));
	i = 7;
	printf("pushFront\n");
	while (i--)
	{
		value = rand() % 100;
		printf("value: %d\n", value);
		pushFront(deque, value);
	}
	i = 7;
	printf("popFront\n");
	while (i--)
	{
		value = popFront(deque);
		printf("value: %d\n", value);
	}
	printf("isEmpty: %d\n", isEmpty(deque));
	i = 7;
	printf("pushBack\n");
	while (i--)
	{
		value = rand() % 100;
		printf("value: %d\n", value);
		pushBack(deque, value);
	}
	i = 7;
	printf("popBack\n");
	while (i--)
	{
		value = popBack(deque);
		printf("value: %d\n", value);
	}
	printf("isEmpty: %d\n", isEmpty(deque));
}

int main(void)
{
	int arr[] = {10, -2, 2, 21, -5, 42, 3, -6, 17, 11};
//	int arr[] = {42, 10, 17, 25, -5, -42, 100};
//	int arr[] = {1, 10, 17, 5, -5, -42, 1};
	int n;
	int k;
	struct s_max *res;

	res = NULL;
	n = sizeof(arr) / sizeof(arr[0]);
//	n = 10;
	k = 4;
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	/*-------------------
	launch your test here
	--------------------*/
	deque_test();
	res = maxSlidingWindow(arr, n, k);
	 if (res) {
	 	for (int i = 0; i < res->length; i++)
	 		printf("%d ", res->max[i]);
	 	printf("\n");
	 }

	return (0);
}



// Function used for the test
// Don't go further :)

