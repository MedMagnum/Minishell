/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 04:40:09 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/03/15 04:53:25 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

t_op	*get_last(t_op *head_ptr)
{
	if (!head_ptr)
		return (NULL);
	if (!head_ptr->next)
		return (head_ptr);
	return (get_last(head_ptr->next));
}

void	pb(t_op **head, t_op *new)
{
	t_op	*last;

	if (!(*head))
		*head = new;
	else
	{
		last = get_last(*head);
		last->next = new;
	}
	new->next = NULL;
}

t_vars	*go_next_d(t_vars *head_ptr)
{
	if (!head_ptr)
		return (NULL);
	if (!head_ptr->next)
		return (head_ptr);
	return (go_next_d(head_ptr->next));
}

void	pbd(t_vars **head, t_vars *to_push)
{
	t_vars	*ptr;

	if (!(*head))
		*head = to_push;
	else
	{
		ptr = go_next_d(*head);
		ptr->next = to_push;
	}
	to_push->next = NULL;
}
