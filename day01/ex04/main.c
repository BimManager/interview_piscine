#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

static void	general_tests(struct s_queue *queue)
{
	char	buffer[256];
	char	*message;

	printf("isEmpty: %d\n", isEmpty(queue));
	strcpy(buffer, "first");
	enqueue(queue, buffer);
	printf("isEmpty: %d\n", isEmpty(queue));
	printf("peek: %s\n", peek(queue));
	printf("isEmpty: %d\n", isEmpty(queue));
	message = dequeue(queue);
	free(message);
	printf("message: %s\n", message);
	printf("isEmpty: %d\n", isEmpty(queue));
}

static void	specific_tests(struct s_queue *queue)
{
	char			buffer[256];
	struct s_node	*it;
	char			*msg;

	strcpy(buffer, "fst");
	enqueue(queue, buffer);
	strcpy(buffer, "snd");
	enqueue(queue, buffer);
	strcpy(buffer, "thd");
	enqueue(queue, buffer);
	it = queue->first;
	printf("===enqueuing===\n");
	while (it)
	{
		printf("%s\n", it->message);
		it = it->next;
	}
	printf("===dequeuing===\n");
	while (!isEmpty(queue))
	{
		msg = dequeue(queue);
		printf("%s\n", msg);
		free(msg);
	}
	printf("isEmpty: %d\n", isEmpty(queue));
}

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/
	struct s_queue	*queue;

	queue = queueInit();
	general_tests(queue);
	specific_tests(queue);
	return (0);
}



// Function used for the test
// Don't go further :)

