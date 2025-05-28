#include "list.h"

int	allocation_counter;

t_node	*create_node(char data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	allocation_counter++;
	if (!new)
	{
		free(new);
		allocation_counter--;
		return (NULL);
	}
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
		allocation_counter--;
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
		free(new);
		allocation_counter--;
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

size_t	list_len(t_node *head)
{
	t_node	*current;
	size_t	length;

	if (!head)
		return (0);
	length = 0;
	current = head;
	while (current)
	{
		current = (*current).next;
		length++;
	}
	return (length);
}

int	getc_list(t_node *head)
{
	static t_node	*current;
	static size_t	i;
	char			data;

	if (!head)
		return (ERROR);
	if (i == 0)
		current = head;
	if (current == NULL)
		return (END_OF_LIST);
	data = (*current).data;
	current = (*current).next;
	i++;
	return (data);
}

void	write_list(t_node *head, char line[])
{
	int		c;
	size_t	i;

	if (!line)
		return ;
	c = getc_list(head);
	i = 0;
	while (c != ERROR)
	{
		line[i] = c;
		c = getc_list(head);
		i++;
		if (c == END_OF_LIST)
		{
			line[i] = '\0';
			break;
		}
	}
}

char	*list_tostr(t_node *head)
{
	char	*line;
	size_t	length;

	length = list_len(head);
	line = (char *)calloc(sizeof(char), length + 1);
	allocation_counter++;
	if(!line)
	{
		free(line);
		allocation_counter--;
		return (NULL);
	}
	write_list(head, line);
	return (line);
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
