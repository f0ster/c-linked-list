/* -----------------------------------------------------------------
 *  * llist.c
 *   *
 *    * Somewhat bogus linked list implementation in C.
 *     * ----------------------------------------------------------------- */

/* we want to use functions in the stdio library */
#include <stdio.h>
#include <stdlib.h>

/* The definition of what a lnode (linked list node) is.  This would
 *    usually be in a header file rather than in a .c file.  */
struct lnode {
  struct lnode *next;
  void *item;
};  /* <---- note the semicolon */

/* The definition of what a llist (linked list) is.  */
struct llist {
  struct lnode *head;
  int size;
};


/* Functions that operate on llists */

/* -----------------------------------------------------------------
 *  * struct llist * new_list(void)
 *   * 
 *    * A function that is basically a list constructor.
 *     * Returns a pointer to a llist structure.
 *      * ----------------------------------------------------------------- */
struct llist *  /* return type */
new_list() {   /* function name */
  struct llist *lst;
  /* our first use of malloc().  Allocates enough space for a 
 *      llist structure, casts the void pointer returned by malloc() to 
 *           the correct type (struct llist pointer) and stores that pointer in lst.*/
  lst = (struct llist *) malloc(sizeof(struct llist));

  /* malloc returns 0 on error */
  if (lst == NULL) {
    fprintf(stderr, "new_list() : malloc error");
    return NULL;
  }

  /* initialize the list size and the list head */
  lst->head = 0;
  lst->size = 0;
  return lst;
}

/* -----------------------------------------------------------------
 *  * struct new_node * new_node(void *item)
 *   *
 *    * Function that works like a constructor for lnodes.
 *     * Takes a void pointer and returns a pointer to a struct lnode.
 *      * ----------------------------------------------------------------- */
struct lnode *
new_node(void *item) {
  struct lnode *node;
  node = (struct lnode *) malloc (sizeof (struct lnode));
  if (node == NULL) {
    fprintf(stderr, "new_node() : malloc error");
    return NULL;
  }
  node->item = item;
  node->next = 0;
  return node;
}  


/* -----------------------------------------------------------------
 *  * int l_insert(struct llist *ls, void *item)
 *   *
 *    * Insert function for a list.  Takes a pointer 'ls' to the list on 
 *     * which we want to insert 'item'.
 *      * Returns 0 on error, 1 otherwise.
 *       * ----------------------------------------------------------------- */
int
l_insert(struct llist *ls, void *item) {
  struct lnode *node;
  /* get a new node */
  node = new_node(item);
  if (node == NULL) return 0;
  
  /* insert the node at the head of the list */
  node->next = ls->head;
  ls->head = node;  
  (ls->size)++;
  return 1;
}

/* -----------------------------------------------------------------
 *  * int l_delete(struct llist *ls, void *item) {
 *   *
 *    * Searches list 'ls' for 'item' and removes it from the list.
 *     * Returns 1 if found or 0 otherwise.
 *      * ----------------------------------------------------------------- */
int
l_delete(struct llist *ls, void *item) {
  struct lnode *node;
  struct lnode *prev;
  
  /* iterate through the list looking for 'item'. */
  for (node = ls->head; node != NULL && node->item != item; node = node->next) {
    prev = node;
  }
  if (node == NULL) {
    printf("Item not found\n");
    return 0; /* 'item' not found */
  }

  /* Do bookkeeping on the list */
  if (node == ls->head) {
    ls->head = node->next;
  } else {
    prev->next = node->next;
  }

  (ls->size)--;
  
  /* free the memory we allocated for the list node we're no longer using */
  free(node);
  return 1;
}


/* -----------------------------------------------------------------
 *  * main()
 *   * This test code is admittedly bogus.
 *    * ----------------------------------------------------------------- */
int main() {
  struct llist *list;
  int i;

  list = new_list();

  printf("Testing C linked list class.\n");
  for(i = 0; i < 20; i++) {
    printf("Inserting %d\n", i);
    l_insert(list, (void *) i);
  }

  for(i = 0; i < 20; i++) {
    if (l_delete(list, (void *) i)) {
      printf("Removed %d\n", i);
    }
  }
  l_delete(list, (void *) 21);
}












