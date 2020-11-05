#include <stdio.h>
#include <stdlib.h>

#define IDX 8

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
	
	char *file_name_read = "config.dat";
	config c = read_config(file_name_read, IDX);
	if (c.number_of_soldiers <= 0)
	{
		perror("Config");
		return 1;
	}
	printf("Configuration for index %d\nNumber of soldiers: %d, kill every %d\n",
		   IDX, c.number_of_soldiers, c.kill_every_k);
	
	
	// Part 2 (2 point)
	
	soldiers_list sl = create_soldiers_list(c.number_of_soldiers);
	if (!sl.head)
	{
		perror("List creation");
		return 1;
	}
	

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


config read_config(const char* file, int n){

    config c;
    FILE* fp;

    if(n > 31 || n < 1){
        c.number_of_soldiers = -1;
        c.kill_every_k = -1;
        return c;
    }
    fp = fopen(file, "rb");
    if(fp == NULL){
        c.number_of_soldiers = -1;
        c.kill_every_k = -1;
        return c;
    }

    if(fseek(fp, (n - 1) * sizeof(config), SEEK_SET) != 0){
        fclose(fp);
        c.number_of_soldiers = -1;
        c.kill_every_k = -1;
        return c;
    }
    if(fread(&c, sizeof(config), 1, fp) != 1){
        fclose(fp);
        c.number_of_soldiers = -1;
        c.kill_every_k = -1;
        return c;
    }
    fclose(fp);
	
    return c;    
}

soldiers_list create_soldiers_list(int n){
    soldiers_list sol_list;
    soldier *prev;
    soldier *ptr;
    soldiers_list er;

    er.head = NULL;
    er.tail = NULL;
    prev = NULL;
    ptr = NULL;
    for(int i = 0; i < n; i++){
        prev = ptr;
        ptr = (soldier*) malloc(1 * sizeof(soldier));

        if(ptr == NULL){
            return er;
        }
        if(i == 0){
            sol_list.head = ptr;
        }
        if(i == n -1){
            sol_list.tail = ptr;
        }
        if(prev != NULL){
            prev->next = ptr;
        }
        //prev = ptr;
        ptr->id = i + 1;
        
    }
	ptr->next = sol_list.head;
    
    return sol_list;
}
