#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define ERROR -1
#define END_OF_LIST -2

typedef struct t_node {
    char data;
    struct t_node *next;
} t_node;

int allocation_counter;

void cleanup(t_node *head) {
    t_node *current;
    t_node *next;
    
    current = head;
    while (current) {
        next = current->next;
        free(current);
        current = next;
        allocation_counter--;
    }
}

t_node *append(t_node *head, char data) {
    t_node *new;
    t_node *current;
    
    new = malloc(sizeof(t_node));
    if (!new) {
        cleanup(head);
        return NULL;
    }
    
    allocation_counter++;
    new->data = data;
    new->next = NULL;
    
    if (!head)
        return new;
    
    current = head;
    while (current->next)
        current = current->next;
    
    current->next = new;
    return head;
}

size_t	list_len(t_node	*current)
{
	size_t	length;

	length = 0;
	while (current)
	{
		current = current->next;
		length++;
	}
	return (length);
}

char *list_tostr(t_node *head)
{
    char *line;
    t_node *current;
    size_t length;
    size_t i;

	length = list_len(head);
    line = calloc(length + 1, sizeof(char));
    if (!line)
        return NULL;
    allocation_counter++;
    current = head;
    i = 0;
    while (current)
	{
        line[i] = current->data;
        current = current->next;
        i++;
    }
    line[i] = '\0';
    return line;
}

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
	line = list_tostr(head);
	printf("\n%s\n", line);
	cleanup(head);
	free(line);
	allocation_counter--;
	printf("allocation_counter: %d\n", allocation_counter);
	return 0;
}
