#include "list.h"

t_list	*vm_get_champ(t_list **heap, int len)
{
	t_list	*champ;
	t_list	*tmp;
	int	i;
	int	c[2];

	i = 0;
	champ = heap[i];
	heap[i] = heap[len];
	while(i < len)
	{
		c[0] = (i * 2) + 1;
		c[1] = (i * 2) + 2;
		if (c[0] < len)
		{
			if (c[1] < len)
			{
				if (order(heap[c[1]], heap[c[0]]))
				{
					c[0] = c[1];
				}
			}
			if (order(heap[c[0]], heap[i]))
			{
				tmp = heap[i];
				heap[i] = heap[c[0]];
				i = c[0];
				heap[i] = tmp;
				continue;
			}
		}
		return (champ);
	}
	return (champ);
}

t_list	*vm_get_head(t_list **heap, int len)
{
	t_list	*champ;
	t_list	*head;

	head = (void *)0;
	if (len--)
	{
		head = vm_get_champ(heap, len);
		champ = head;
		while(len--)
		{
			champ->next = vm_get_champ(heap, len);
			champ = champ->next;
		}
		champ->next = (void *)0;
	}
	return (head);
}

t_list	*vm_sort_heap(t_list *head, t_list **heap, int len)
{
	t_list	*tmp;
	int		i;
	int 	c[2];

	i = 0;
	while(i < len)
	{
		heap[i] = head;
		head = head->next;
		i++;
	}
	i = (len - 2) / 2;
	while (i >= 0)
	{
		c[0] = (i * 2) + 1;
		c[1] = (i * 2) + 2;
		if (c[1] < len && order(heap[c[1]], heap[c[0]]))
		{
			c[0] = c[1];
		}
		if (order(heap[c[0]], heap[i]))
		{
			tmp = heap[i];
			heap[i] = heap[c[0]];
			heap[c[0]] = tmp;
		}
		i--;
	}
	return (vm_get_head(heap, len));
}