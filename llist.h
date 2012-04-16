#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// node definition
typedef struct  {
	void *item;
	struct list_node *next;
} list_node;

//linked list def
typedef struct {
	list_node *head;
	int size;
} linked_list;

// functions that operate on a linked list
linked_list *new_list();

list_node *new_node(void *item);

// returns 0 on error, 1 otherwise
int insert_node(linked_list *list, void *item);

// returns node if found, otherwise null
void *find_node(linked_list *list, void *item);

//returns 1 if found, 0 otherwise
int delete_node(linked_list *list, void *item);


#endif
