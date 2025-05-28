#ifndef LIST_H

# define LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct t_node
{
	char			data;
	struct t_node	*next;
}	t_node;

#endif
