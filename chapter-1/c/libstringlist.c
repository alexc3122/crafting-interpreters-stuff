#include <stdlib.h>
#include "libstringlist.h"

// Alias of list_push()
int list_add(string_list *list, char *str)
{
    return list_push(list, str);
}

// Gets a string at the specified index from the list.
char* list_get(string_list *list, int index)
{
    struct node_t *node = NULL;
    unsigned int i = 0;

    // Basic sanity checks to ensure index is non-negative and in bounds of the list.
    if (index < 0)
        return NULL;

    if (index >= list->list_length)
        return NULL;

    // Iterate over the linked list now.
    node = list->root_node.next;
    i = 0;

    while (i < list->list_length && i != index)
    {
        node = node->next;
        i++;
    }

    return node->str;
}

// Inserts a string into the list at the given position/index.
int list_insert(string_list *list, char *str, int index)
{
    struct node_t *node = NULL;
    struct node_t *new_node = NULL;
    unsigned int i = 0;

    // Basic sanity checks
    if (index < 0)
        return -1;

    // Strictly 'greater than' comparision here. No 'greater than or equals'.
    // If index == list_length, then you're just doing an add to the end of the list.
    if (index > list->list_length)
        return -1;

    new_node = malloc(sizeof(struct node_t));

    if (new_node == NULL)
        return -1;

    memset(new_node, 0, sizeof(struct node_t));

    new_node->str = str;

    // edge case: adding to an empty list
    if (list->list_length == 0)
    {
        new_node->next = &(list->root_node);
        new_node->prev = &(list->root_node);

        list->root_node.next = new_node;
        list->root_node.prev = new_node;

        list->list_length++;
        return 0;
    }

    // iterate over the list now to do our insertion.
    node = list->root_node.next;
    i = 0;

    while (i < list->list_length && i != index)
    {
        node = node->next;
        i++;
    }

    // set the new node to point back to the previous node
    new_node->prev = node->prev;

    // set the new node to point forward to the current node
    new_node->next = node;

    // fix the pointer on the previous node to point forward to the new node
    node->prev->next = new_node;

    // fix the pointer on the current node to point back to the new node
    node->prev = new_node;

    list->list_length++;
    return i;
}

// Removes the last string from the list and return the pointer to the 
char* list_pop(string_list *list)
{
    struct node_t *root_node = NULL;
    struct node_t *last_node = NULL;
    char *str = NULL;

    // nothing to return
    if (list->list_length == 0)
        return NULL;

    root_node = &(list->root_node);
    last_node = root_node->prev;
    str = last_node->str;

    // edge case: removing the last item in the list requires handling the
    // pointers a slight bit differently
    if (list->list_length == 1)
    {
        root_node->next = NULL;
        root_node->prev = NULL;
    }
    else
    {
        // set the penultimate node to point forward to the root node
        last_node->prev->next = root_node;

        // set the root node to point back to the penultimate, now ultimate node.
        root_node->prev = last_node->prev;
    }
    
    free(last_node);
    last_node = NULL;
    list->list_length--;

    return str;
}

// Adds an element to the end of the list.
int list_push(string_list *list, char *str)
{
    struct node_t *root_node = &(list->root_node);
    struct node_t *new_node = NULL;

    new_node = malloc(sizeof(struct node_t));

    if (new_node == NULL)
        return -1;

    memset(new_node, 0, sizeof(struct node_t));

    // node allocated -- set the string pointer
    new_node->str = str;

    // edge case: if the list is empty, then there are no previous nodes to link to
    if (list->list_length == 0)
    {
        new_node->next = root_node;
        new_node->prev = root_node;

        root_node->next = new_node;
        root_node->prev = new_node;
    }
    else
    {
        // have the new node point back to the previously last node
        new_node->prev = root_node->prev;

        // set new node to point forward to the root node
        new_node->next = root_node;

        // set the previously last node in the list to point forward to the new node
        root_node->prev->next = new_node;

        // set the last node in the list to point to the new node
        root_node->prev = new_node;
    }

    list->list_length++;

    return list->list_length-1;
}

// Removes a string from the list at the given index.
char* list_remove(string_list *list, int index)
{
    struct node_t *node = NULL;
    char *str = NULL;
    unsigned int i = 0;

    // Basic sanity checks
    if (index < 0)
        return NULL;

    // 'greater than or equal' check, because if index == list_length, that is out-of-bounds and
    // off-by-one
    if (index >= list->list_length)
        return NULL;

    // Iterate over the linked list now.
    node = list->root_node.next;
    i = 0;

    while (i < list->list_length && i != index)
    {
        node = node->next;
        i++;
    }

    str = node->str;

    // fix the pointers in the list now

    // special case: removing the last item requires we reset pointers on the root node.
    if (list->list_length == 1)
    {
        list->root_node.next = NULL;
        list->root_node.prev = NULL;
    }
    else
    {
        // set the previous node's next pointer to the next node in the list
        node->prev->next = node->next;

        // vice-versa -- set the next node's previous pointer to the previous node in the list
        node->next->prev = node->prev;
    }

    free(node);
    node = NULL;
    list->list_length--;

    return str;
}

// Searches the list for the given string and returns a count of how many times the exact string
// was seen.
int list_search(string_list *list, char *needle)
{
    struct node_t *node = NULL;
    int count = 0;
    int i = 0;

    if (needle == NULL)
        return 0;

    node = &(list->root_node);

    for (i = 0; i < list->list_length; i++)
    {
        node = node->next;

        if(!strcmp(needle, node->str))
            count++;
    }

    return count;
}

// Updates the node at the specified index with a new/different string passed in.
char* list_update(string_list *list, char *str, int index)
{
    struct node_t *node = NULL;
    char *old_string = NULL;
    unsigned int i = 0;

    // Basic sanity checks to ensure index is non-negative and in bounds of the list.
    if (index < 0)
        return NULL;

    if (index >= list->list_length)
        return NULL;

    // iterate over the linked list now
    node = list->root_node.next;
    i = 0;

    while (i < list->list_length && i != index)
    {
        node = node->next;
        i++;
    }

    old_string = node->str;
    node->str = str;

    return old_string;
}
