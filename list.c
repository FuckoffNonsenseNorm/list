#include "list.h"

extern int	allocation_counter;

void cleanup(t_node *head)
{
	t_node	*current;
	t_node	*next;

	current = head;
	while (current)
	{
        next = current->next;
        free(current);
        current = next;
        allocation_counter--;
    }
}

t_node *append(t_node *head, char data)
{
    t_node *new;
    t_node *current;

    new = malloc(sizeof(t_node));
    if (!new)
	{
        cleanup(head);
        return (NULL);
    }

    allocation_counter++;
    new->data = data;
    new->next = NULL;
    
    if (!head)
        return (new);
    
    current = head;
    while (current->next)
        current = current->next;
    
    current->next = new;
    return (head);
}

static size_t	list_len(t_node	*current)
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
    line = malloc(sizeof(char) * (length + 1));
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
