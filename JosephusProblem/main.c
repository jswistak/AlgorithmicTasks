#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int number_of_soldiers;
	int kill_every_k;
} config;

typedef struct soldier
{
	int id;
	struct soldier *next;
} soldier;

typedef struct
{
	soldier *head, *tail;
} soldiers_list;

config read_config(const char *, int);
soldiers_list create_soldiers_list(int);
int eliminate_soldiers(const char *, soldiers_list *, int);

int main()
{
	// Part 1 (2 point)
	/*
	char *file_name_read = "config.dat";
	config c = read_config(file_name_read, IDX);
	if (c.number_of_soldiers <= 0)
	{
		perror("Config");
		return 1;
	}
	printf("Configuration for index %d\nNumber of soldiers: %d, kill every %d\n",
		   IDX, c.number_of_soldiers, c.kill_every_k);
	*/
	
	// Part 2 (2 point)
	/*
	*soldiers_list sl = create_soldiers_list(c.number_of_soldiers);
	if (!sl.head)
	{
		perror("List creation");
		return 1;
	}
	*/

	//Part 3 (2 points)
	/*
	char *file_name_save = "elimination_order.txt";
	int const survivor = eliminate_soldiers(file_name_save, &sl, c.kill_every_k);
	if (survivor <= 0)
	{
		perror("Elimiation order");
		return 1;
	}
	printf("The survivor is soldier %d.\n", survivor);
	*/

	return 0;
}