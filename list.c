#include "list.h"

void	cleanup(t_node *head)
{
	t_node	*current;
	t_node	*next;

	current = head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

t_node	*append(t_node *head, char data)
{
	t_node	*new;
	t_node	*current;

	new = malloc(sizeof(t_node));
	if (!new)
	{
		cleanup(head);
		return (NULL);
	}
	new->data = data;
	new->next = NULL;
	if (head == NULL)
		return (new);
	current = head;
	while (current->next)
		current = current->next;
	current->next = new;
	return (head);
}

size_t	list_len(const t_node *head)
{
	size_t			length;
	const t_node	*current;

	length = 0;
	current = (const t_node *)head;
	while (current)
	{
		current = current->next;
		length++;
	}
	return (length);
}

char	*list_tostr(const t_node *head)
{
	char	*line;
	t_node	*current;
	size_t	length;
	size_t	i;

	length = list_len(head);
	line = malloc(sizeof(char) * (length + 1));
	if (!line)
		return (NULL);
	current = (t_node *)head;
	i = 0;
	while (current)
	{
		line[i] = current->data;
		current = current->next;
		i++;
	}
	line[i] = '\0';
	return (line);
}
