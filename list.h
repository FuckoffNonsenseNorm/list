#ifndef LIST_H

# define LIST_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>


# include <string.h>


# define ERROR -1
# define END_OF_LIST -2

typedef struct t_node
{
	char			data;
	struct t_node	*next;
}	t_node;

void cleanup(t_node *head);
t_node *append(t_node *head, char data);
char *list_tostr(t_node *head);

#endif
