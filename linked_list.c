#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int val;
    struct Item * next;
} Item;

Item * new()
{
    Item * root = NULL;
    root = (Item *) malloc(sizeof(Item));
    return root;
}

void push_end(Item * list, int val)
{
    Item * current = list;
    if (current->next != NULL)
    {
        current = current->next;
    }
    current->next = (Item *) malloc(sizeof(Item));
    current->next->val = val;
    current->next->next = NULL;
}

void push_begin(Item ** list, int val)
{
    Item * new = (Item *) malloc(sizeof(Item));
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

void print_list(Item * head) {
    Item * current = head;
    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int main()
{
    Item * list = (Item *) malloc(sizeof(Item));
    list->val = 9;
    list->next = malloc(sizeof(Item));
    list->next = NULL;
    push_end(list,8);
    // printf("%d",find(&list,8));
    push_begin(&list,1);

    print_list(list);
    printf("pop first: %d\n",pop_first(&list));
    print_list(list);
    printf("pop last: %d\n",pop_last(list));
    print_list(list);
    return 0;
}