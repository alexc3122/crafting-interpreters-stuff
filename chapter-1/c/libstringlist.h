#pragma once

/**
 *  Basic structure of a doubly linked list node.
 */
struct node_t {
    struct node_t *prev;
    struct node_t *next;
    char *str;
};

/**
 * List object type definition. This implementation of doubly-linked list is 
 * circular.
 */
typedef struct string_list {
    struct node_t root_node;
    unsigned int length;
} string_list;


/**
 * Alias of list_push()
 */
int list_add(string_list *list, char *str);

/**
 * Empties the list list of all strings in it. Strings that were previously in 
 * the list are deallocated/freed.
 * @param list  The list object to empty/free.
 */
void list_empty(string_list *list);

/**
 * Gets a string at the specified index from the list.
 * @param list  the list to retrieve the string from
 * @param index the index of the string in the list.
 * @return pointer to the string retrieved in the list.
 */
char* list_get(string_list *list, int index);

/**
 * Inserts a string into the list at the given position/index.
 * @param list  The list to insert into.
 * @param index the index in the list where to insert the new string into
 * @param str   the string to insert into the list
 * @return The index of the string that was inserted, or -1 if insertion failed
 */
int list_insert(string_list *list, char *str, int index);

/**
 * Removes the last string from the list and returns the pointer to the 
 * string. Returns NULL if the list is empty or if the pointer provided to 
 * the list addition function was NULL.
 * @param list  The list object to pop from.
 * @return The string that is taken from the list
 */
char* list_pop(string_list *list);

/**
 * Pretty prints the list of strings;
 * @param list  The list to print
 */
void list_print(string_list *list);

/**
 * Adds an element to the end of the list.
 * @param list  the list object to add to.
 * @param str   string pointer to add to the list.
 * @return the index of the added element. Returns -1 if the string could not
 *         be added to the list.
 */
int list_push(string_list *list, char *str);

/**
 * Removes a string from the list at the given index.
 * @param list  The list to remove the string from
 * @param index The index in the list to remove.
 * @return Returns a pointer to the removed string, or NULL if removal failed.
 */
char* list_remove(string_list *list, int index);

/**
 * Searches the list for the given string and returns a count of how many times
 * the exact string was seen in the list.
 * @param list  The list to search
 * @param needle    The string to search for in the list
 * @return The number of times a string was found in the list.
 */
int list_search(string_list *list, char *needle);

/**
 * Updates the entry in the string list with a different string. This function 
 * does not deallocated/free the previously stored string in the list. Instead,
 * it is update to perform the clean-up. For that reason, the function returns
 * a pointer to the previously stored string.
 * @param list  The list to update
 * @param str   string pointer to update the list entry with
 * @param index The index where to update the stored string.
 * @return The pointer to the previously stored string.
 */
char* list_update(string_list *list, char *str, int index);
