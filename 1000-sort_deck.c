#include "deck.h"

/**
*swap - swaps 2 nodes in a doubly-linked list
*@m: address of first node
*@n: address of second node
*
*Return: void
*/
void swap(deck_node_t *m, deck_node_t *n)
{
	if (m->prev)
		m->prev->next = n;
	if (n->next)
		n->next->prev = m;
	m->next = n->next;
	n->prev = m->prev;
	m->prev = n;
	n->next = m;
}

/**
 * insert_sort_list - insert sorts a doubly-linked list
 * @list: address of pointer to head node
 * Return: nothing
 */
void insert_sort_list(deck_node_t **list)
{
	deck_node_t *c, *d;

	if (!list || !*list || !(*list)->next)
		return;
	c = (*list)->next;
	while (c)
	{
		d = c;
		c = c->next;
		while (d && d->prev)
		{
			if (less_than(d->prev->card, d->card))
			{
				swap(d->prev, d);
				if (!d->prev)
					*list = d;
			}
			else
				d = d->prev;
		}

	}
}

/**
* sort_deck - sorts the deck by a given sort function
* @deck: address to pointer of head
*
*/
void sort_deck(deck_node_t **deck)
{
	insert_sort_list(deck);
}

/**
* less_than - establishes the sequence of comparison between two cards.
* @a: pointer of first card
* @b: pointer of second card
* Return: true if a > b
*/
int less_than(const card_t *a, const card_t *b)
{
	char *s1, *s2, *values[] = {"King", "Queen", "Jack", "10", "9", "8",
		"7", "6", "5", "4", "3", "2", "Ace"};
	int val_a = 0, val_b = 0, d = 0;

	for (d = 0; d < 13; d++)
	{
		for (s1 = (char *)a->value, s2 = values[d]; *s1 && *s1 == *s2; ++s1, ++s2)
			;
		if (*s1 == 0 && *s2 == 0)
		{
			val_a = d;
			break;
		}
	}
	for (d = 0; d < 13; d++)
	{
		for (s1 = (char *)b->value, s2 = values[d]; *s1 && *s1 == *s2; ++s1, ++s2)
			;
		if (*s1 == 0 && *s2 == 0)
		{
			val_b = d;
			break;
		}
	}
	if (a->kind == b->kind)
		return (val_a < val_b);
	return (a->kind > b->kind);

}
