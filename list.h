#ifndef LIST_H
# define LIST_H

typedef struct	s_list
{
	int				id;
	int				data;
	struct s_list	*next;
}				t_list;

int	order(t_list *first, t_list *second);

t_list	*vm_sort_list(t_list *head);

t_list	*vm_sort_heap(t_list *head, t_list **heap, int len);

t_list	*vm_sort_merge(t_list *head, int len);

#endif

