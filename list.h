#ifndef LIST_H

# define LIST_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

# define ERROR -1
# define END_OF_LIST -2

typedef struct s_node
{
	char			data;
	struct s_node	*next;
}	t_node;

void	cleanup(t_node *head);
t_node	*append(t_node *head, char data);
size_t	list_len(const t_node *current);
char	*list_tostr(const t_node *head);

#endif
