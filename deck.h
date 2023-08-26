#ifndef DECK_H
#define DECK_H

#include <stdio.h>

/**
 * enum kind_e - suit enumeration
 *
 *
 * @SPADE: suit spade
 * @HEART: suit heart
 * @CLUB: suit heart
 * @DIAMOND: suit diamond
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: card value
 * From "Ace" to "King"
 * @kind: card kind
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

	/*prototypes*/
void sort_deck(deck_node_t **deck);
int less_than(const card_t *a, const card_t *b);
void cocktail_sort_list(deck_node_t **list);

#endif /*DECK_H*/
