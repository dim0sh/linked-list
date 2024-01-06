#include <stdio.h>
#include <stdlib.h>
/**
* Linked list item
* @param int key
* @param int val
* @param Item next
*/
typedef struct Item
{
    int key;
    int val;
    struct Item * next;
} item_t;
/**
* Initializes an empty list.
* @code Example: Item list; init_empty(&list);
* @param Item
*/
void init_empty(item_t ** list)
{
    item_t * root = (item_t *) malloc(sizeof(item_t));
    root = NULL;
    *list = root;
}
/**
* add item at begining of list
* @param Item list
* @param int key
* @param int val
*/
void push_begin(item_t ** list, int key, int val)
{
    item_t * new = (item_t *) malloc(sizeof(item_t));
    new->key = key;
    new->val = val;
    new->next = *list;
    *list = new;
}
/**
* add item at end of list
* @param Item list
* @param int key
* @param int val
*/
void push_end(item_t * list, int key, int val)
{
    item_t * current = list;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = (item_t *) malloc(sizeof(item_t));
    current->next->key = key;
    current->next->val = val;
    current->next->next = NULL;
    return;    
}
/**
* delte item with key out of list.
* @param Item list
* @param int key
*/
void delete_key(item_t ** list, int key)
{
    item_t * current = *list;
    if (current->key == key)
    {
        *list = current->next;
        return;
    }
    while (current->next != NULL)
    {
        if (current->next->key == key)
        {
            current->next = current->next->next;
            return;
        }
        current = current->next;
    }
}
/**
* remove last item and return val
* @param Item list
*/
int pop_last(item_t * list)
{
    int pop_val = -1;
    item_t * current = list;
    if (list == NULL)
    {
        return pop_val;
    }
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    pop_val = current->next->val;
    current->next = NULL;
    return pop_val;
}
/**
* remove first item and return val.
* @param Item list
*/
int pop_first(item_t ** list)
{
    int pop_val = -1;
    item_t * next = NULL;
    if (*list == NULL)
    {
        return pop_val;
    }
    pop_val = (*list)->val;
    next = (*list)->next;
    *list = next;
    return pop_val;
}
/**
* print list to console
* @param Item list
*/
void print_list(item_t * list) 
{
    item_t * current = list;
    while (current != NULL) 
    {
        printf("key: %d -> val: %d\n", current->key, current->val);
        current = current->next;
    }
}
/**
* find item with key in list and return val.
* @param Item list
* @param int key
*/
int find_key(item_t * list, int key)
{
    item_t * current = list;
    while (current != NULL)
    {
        if (current->key == key)
        {
            return current->val;
        }
        current = current->next;
    }
    return -1;
}
/**
* free memory of linked list
* @param item_t list
*/
void destroy_linked_list(item_t * item)
{
    item_t * current = item;
    item_t * tmp;
    while(current->next != NULL)
    {
        tmp = current;
        current = current->next;
        free(tmp);
        return;
    }
    free(item);
}

int main()
{
    item_t * list;
    init_empty(&list);
    push_begin(&list,23,89);
    push_end(list,8,29);
    push_begin(&list,1,30);
    print_list(list);
    printf("pop first: %d\n",pop_first(&list));
    print_list(list);
    printf("pop last: %d\n",pop_last(list));
    print_list(list);
    printf("%d\n",find_key(list,4));
    push_begin(&list,3,9);
    print_list(list);
    delete_key(&list,4);
    printf("delete 4\n");
    print_list(list);
    push_end(list,5,7);
    printf("push end 5,7\n");
    print_list(list);
    delete_key(&list,3);
    printf("delete 3\n");
    print_list(list);
    destroy_linked_list(list);
    return 0;
}