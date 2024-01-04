#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int key;
    int val;
    struct Item * next;
} Item;
/**
* Initializes an empty list.
* @code Example: Item list; init_empty(&list);
* @param Item
*/
void init_empty(Item ** list)
{
    Item * root = (Item *) malloc(sizeof(Item));
    root = NULL;
    *list = root;
}
/**
* add item at begining of list
* @param Item list
* @param int key
* @param int val
*/
void push_begin(Item ** list, int key, int val)
{
    Item * new = (Item *) malloc(sizeof(Item));
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
void push_end(Item * list, int key, int val)
{
    Item * current = list;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = (Item *) malloc(sizeof(Item));
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
void delete_key(Item ** list, int key)
{
    Item * current = *list;
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
int pop_last(Item * list)
{
    int pop_val = -1;
    Item * current = list;
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
int pop_first(Item ** list)
{
    int pop_val = -1;
    Item * next = NULL;
    if (*list == NULL)
    {
        return pop_val;
    }
    pop_val = (*list)->val;
    next = (*list)->next;
    *list = next;
    return pop_val;
}

void print_list(Item * list) 
{
    Item * current = list;
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
int find_key(Item * list, int key)
{
    Item * current = list;
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

int main()
{
    Item * list;
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
    return 0;
}