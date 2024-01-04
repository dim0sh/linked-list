#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int key;
    int val;
    struct Item * next;
} Item;

Item * new()
{
    Item * root = NULL;
    root = (Item *) malloc(sizeof(Item));
    return root;
}

void push_end(Item * list, int key, int val)
{
    Item * current = list;
    if (current->next != NULL)
    {
        current = current->next;
    }
    current->next = (Item *) malloc(sizeof(Item));
    current->next->key = key;
    current->next->val = val;
    current->next->next = NULL;
}

void push_begin(Item ** list, int key, int val)
{
    Item * new = (Item *) malloc(sizeof(Item));
    new->key = key;
    new->val = val;
    new->next = *list;
    *list = new;
}

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
    Item * list = (Item *) malloc(sizeof(Item));
    list->val = 9;
    list->key = 4;
    list->next = malloc(sizeof(Item));
    list->next = NULL;
    push_end(list,8,29);
    // printf("%d",find(&list,8));
    push_begin(&list,1,30);

    print_list(list);
    printf("pop first: %d\n",pop_first(&list));
    print_list(list);
    printf("pop last: %d\n",pop_last(list));
    print_list(list);
    printf("%d",find_key(list,4));
    return 0;
}