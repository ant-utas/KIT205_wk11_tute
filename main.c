#include "skiplist.h"

int main()
{
	SkipNodePtr found_7;
	SkipNodePtr found_10;

	int arr[] = { 3, 6, 9, 2, 11, 1, 4, 8, 5, 7, 0 }, i;
	Skiplist list = new_skiplist();

	printf("Insert:--------------------\n");
	for (i = 0; i < 11; i++) {
		skiplist_insert(&list, arr[i]);
		skiplist_print(&list);
	}
	skiplist_print(&list);

	found_7 = skiplist_find(&list, 7);
	if (found_7){
		printf("7 found %d\n", found_7->data);
	}
	else printf("7 not found\n");

	found_10 = skiplist_find(&list, 10);
	if (found_10){
		printf("10 found %d\n", found_10->data);
	} else printf("10 not found\n");

	return 0;
}
