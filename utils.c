#include "list.h"

t_node	*create_node(char data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	(*new).data = data;
	(*new).next = NULL;
	return (new);
}

void	cleanup(t_node *head)
{
	t_node	*current;
	t_node	*next;

	current = head;
	while (current)
	{
		next = (*current).next;
		free(current);
		current = next;
	}
}

t_node	*append(t_node *head, char data)
{
	t_node	*new;
	t_node	*current;

	new = create_node(data);
	if(!new)
	{
		cleanup(head);
		return (NULL);
	}
	else if (!head)
		return (new);
	current = head;
	while ((*current).next)
	{
		current = (*current).next;
	}
	(*current).next = new;
	return (head);
}

int	main()
{

	printf("------------test2---------------\n");
	printf("--------appending nodes---------\n");
	
	t_node*	head = NULL;
	
	head = append(head, 'T');
	return 0;
}
