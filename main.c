#include "llist.h"

int main() {

	linked_list *list;
	int i;

	printf("Testing simple linked list c 'class'\n");

	for(i = 0 ; i < 20; ++i ) {
		print("inserting %d\n", i);
		insert_node( list, (void *)i);
	}

	for(i = 0 ; i < 20; i++) {
		if(find_node(list, (void *)i))
		{
			delete_node(list, (void *)i);
			printf("removed node %d\n", i);
		}
	}

	printf("cleaning up head\n");
	delete_node(list, (void *)list->head);
}
