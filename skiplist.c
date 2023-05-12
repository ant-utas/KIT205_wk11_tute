#include "skiplist.h"

Skiplist new_skiplist()
{
	int i;

	Skiplist list;

	list.header = malloc(sizeof * (list.header));
	list.header->data = 0;
	list.header->next = malloc(SKIPLIST_MAX_LEVELS * sizeof * (list.header->next));
	for (i = 0; i < SKIPLIST_MAX_LEVELS; i++) {
		list.header->next[i] = NULL;
	}

	list.max_levels = SKIPLIST_MAX_LEVELS;

	return list;
}

void skiplist_insert(Skiplist* self, int data)
{
	int level = rand_level();
	SkipNodePtr current = self->header;
	SkipNodePtr new_node = malloc(sizeof * new_node);//allocate memory for skiplistnode
	new_node->next = malloc(level * sizeof * new_node->next);//allocate memory for array of next pointers in new_node
	new_node->data = data;//setting data of new_node
	
	int i;

	for (i = self->max_levels - 1; i >= 0; i--) {//finding correct position of new node, current should be new_node's predecessor
		while (current->next[i] != NULL && current->next[i]->data < data)
			current = current->next[i];
	}
	//by now current should be the node before where we want new_node to be isnerted; first insertion current should be self->header

	for (i = 0; i < level; i++) {
		new_node->next[i] = current->next[i];
		current->next[i] = new_node;
	}
}

void skiplist_print(Skiplist* self)
{
	SkipNodePtr current = self->header->next[0];
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next[0];
	}
	printf("\n");
}

SkipNodePtr skiplist_find(Skiplist* self, int data) {
	SkipNodePtr current = self->header;
	int i;
	for (i = self->max_levels - 1; i >= 0; i--) {
		while (current->next[i] != NULL && current->next[i]->data < data)
			current = current->next[i];

		if (current->next[i] != NULL && current->next[i]->data == data)
			return current->next[i];
	}
	return NULL;
}

int rand_level()
{
	int level = 1;
	while (rand() < RAND_MAX / 2 && level < SKIPLIST_MAX_LEVELS)
		level++;
	return level;
}

void skiplist_delete(Skiplist* self, int data) {
	// TODO
}
