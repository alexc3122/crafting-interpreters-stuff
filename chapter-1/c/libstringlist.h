
/**
 *  Basic structure of a doubly linked list node
 */
typedef struct node_t {
    struct node_t *prev;
    struct node_t *next;
    char *str;
};

/**
 * List object type definition.
 */
typedef struct string_list {
    // This implementation will be circular.
    struct node_t root_node;

    // Self-explainitory
    unsigned int list_length;
} string_list;


/**
 * Alias of list_push()
 */
int add(string_list *list, char *str);

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
 * @param list The list object to pop from.
 * @return The string that is taken from the list
 */
char* list_pop(string_list *list);

/**
 * Adds an element to the end of the list.
 * @param list the list object to add to.
 * @param str string pointer to add to the list.
 * @return the index of the added element. Returns -1 if the string could not
 *         be added to the list.
 */
int list_push(string_list *list, char *str);

/**
 * Removes a string from the list at the given index.
 * @param list The list to remove the string from
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
