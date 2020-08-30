/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_sort_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:45:40 by val               #+#    #+#             */
/*   Updated: 2020/08/28 14:27:12 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_list.h"

void	push_heap(t_champ *head, t_champ **heap, int block)
{
	int i;
	int	k;
	t_champ *tmp;
	
	heap[0] = (void *)0;
	heap[1] = (void *)0;
	i = 0;
	while (head)
	{
		if (i / 2)
			i %= 2;
		k = block;
		while (k-- && head)
		{
			tmp = head->next;
			head->next = heap[i];
			heap[i] = head;
			head = tmp;
		}
		i++;
	}
}

t_champ	*merge_list(t_champ **heap, int block)
{
	t_champ	*head;
	t_champ	*champ;
	int	k[2];
	int	max;

	head = (void *)0;
	while (heap[0] || heap[1])
	{
		k[0] = block;
		k[1] = block;
		while ((k[0] || k[1]) && (heap[0] || heap[1]))
		{
			if (heap[0] && k[0])
			{
				if (heap[1] && k[1])
				{
					if (order(heap[0], heap[1]))
					{
						max = 0;
					}
					else
					{
						max = 1;
					}
				}
				else
				{
					max = 0;
				}
			}
			else if (heap[1] && k[1])
			{
				max = 1;
			}
			else
			{
				return (head);
			}
			champ = heap[max]->next;
			heap[max]->next = head;
			head = heap[max];
			heap[max] = champ;
			k[max]--;
		}
	}
	return (head);
}

t_champ	*vm_sort_merge(t_champ *head, int len)
{
	t_champ *heap[2];
	int	block;

	block = 1;
	while(block < len)
	{
		push_heap(head, heap, block);
		head = merge_list(heap, block);
		block *= 2;
	}
	return (head);
}