#include "list.h"

int	allocation_counter;

int	main()
{

	printf("------------test2---------------\n");
	printf("--------appending nodes---------\n");
	
	allocation_counter = 0;
	t_node*	head = NULL;
	char*	line = NULL;
	head = append(head, 'T');
	head = append(head, 'h');
	head = append(head, 'i');
	head = append(head, 's');
	head = append(head, ' ');
	head = append(head, 'a');
	head = append(head, ' ');
	head = append(head, 'S');
	head = append(head, 't');
	head = append(head, 'r');
	head = append(head, 'i');
	head = append(head, 'n');
	head = append(head, 'g');
	head = append(head, '\n');
	line = list_tostr((const t_node *)head);
	printf("\n%s\n", line);
	cleanup(head);
	free(line);
	allocation_counter--;
	printf("allocation_counter: %d\n", allocation_counter);
	return 0;
}
