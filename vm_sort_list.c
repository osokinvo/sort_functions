/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:47:52 by val               #+#    #+#             */
/*   Updated: 2020/08/21 06:35:53 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_list.h"
#include <stdlib.h>
#include <errno.h>

int	order(t_champ *first, t_champ *second)
{
	if (first->id < second->id)
		return (1);
	return (0);
}

int	vm_list_is_sort(t_champ *head)
{
	while(head->next)
	{
		if (order(head->next, head))
			return (0);
		head = head->next;
	}
	return (1);
}

t_champ	*vm_sort_list(t_champ *head)
{
	t_champ **heap;
	int	len;

	if (!head || vm_list_is_sort(head))
		return (head);
	len = vm_len_champ(head);
	if (!(heap = (t_champ **)malloc(len * sizeof(t_champ *))))
	{
		errno = 0;
		return (vm_sort_merge(head, len));
	}
	head = vm_sort_heap(head, heap, len);
	free(heap);
	return(head);
}
