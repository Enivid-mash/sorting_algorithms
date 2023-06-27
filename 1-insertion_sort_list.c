#include "sort.h"

/**
 * insertion_sort_list - Sort a doubly linked list of integers
 * in ascending order
 * @list: A doubly linked list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node = *list, *temp_next, *p_node, *n_node, *p2_nodes;
	size_t go_to_nxt_node;

	if (list == NULL || (*list)->next == NULL)
		return;

	go_to_nxt_node = 1;
	while (node)
	{
		if (go_to_nxt_node)
			temp_next = node->next;

		if (node->prev && node->n < node->prev->n)
		{
			p_node = node->prev;
			n_node = node->next;
			if (node->prev && node->prev->prev)
				p2_nodes = node->prev->prev;
			else
				p2_nodes = NULL;

			node->prev = p2_nodes;
			node->next = p_node;
			if (p2_nodes)
				p2_nodes->next = node;
			p_node->prev = node;
			p_node->next = n_node;
			if (n_node)
				n_node->prev = p_node;

			if (p2_nodes == NULL)
				*list = node;

			print_list(*list);
			go_to_nxt_node = 0;
		}
		else
			go_to_nxt_node = 1;
		node = go_to_nxt_node ? temp_next : node;
	}
}
