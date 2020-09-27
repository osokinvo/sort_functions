#include <stdio.h>
#include "list.h"

int	main(void)
{
	t_list a, b, c, d;
	t_list	*head;

	a.id = 4;
	a.next = &b;
	b.id = 2;
	b.next = NULL;
	c.id = 3;
	c.next = NULL;
	d.id = 1;
	d.next = NULL;
	head = &a;
	head = vm_sort_list(head);
	while (head)
	{
		printf("%d\n", head->id);
		head = head->next;
	}
	return (0);
}