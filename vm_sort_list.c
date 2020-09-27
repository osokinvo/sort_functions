#include "list.h"
#include <stdlib.h>
#include <errno.h>

int	order(t_list *first, t_list *second)
{
	if (first->id < second->id)
		return (1);
	return (0);
}

int	vm_len_champ(t_list *head)
{
	int	len;

	len = 0;
	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);
}

int	vm_list_is_sort(t_list *head)
{
	while(head->next)
	{
		if (order(head->next, head))
			return (0);
		head = head->next;
	}
	return (1);
}

t_list	*vm_sort_list(t_list *head)
{
	t_list **heap;
	int	len;

	if (!head || vm_list_is_sort(head))
		return (head);
	len = vm_len_champ(head);
	if (!(heap = (t_list **)malloc(len * sizeof(t_list *))))
	{
		errno = 0;
		return (vm_sort_merge(head, len));
	}
	head = vm_sort_heap(head, heap, len);
	free(heap);
	return(head);
}
