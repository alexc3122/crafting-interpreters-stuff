#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libstringlist.c"


int main(int argc, char *argv[])
{    
    string_list *list = NULL;
    char *str = NULL;
    int retval = 0;
    int c = 0;

    list = malloc(sizeof(string_list));
    memset(list, 0, sizeof(string_list));

    str = malloc(64);
    strcpy(str, "Hello world!");
    printf("calling list_insert() with \"%s\" @ at index 0\n", str);
    retval = list_insert(list, str, 0);
    printf("retval: %d\n", retval);
    list_print(list);

    str = malloc(64);
    strcpy(str, "second string!");
    printf("calling list_push() with \"%s\"\n", str);
    retval = list_push(list, str);
    printf("retval: %d\n", retval);
    list_print(list);

    str = malloc(64);
    strcpy(str, "third string.");
    printf("calling list_push() with \"%s\"\n", str);
    retval = list_push(list, str);
    printf("retval: %d\n", retval);
    list_print(list);

    str = malloc(64);
    strcpy(str, "fourth? string");
    printf("calling list_insert() with \"%s\" @ at index 1\n", str);
    retval = list_insert(list, str, 1);
    printf("retval: %d\n", retval);
    list_print(list);

    str = malloc(64);
    strcpy(str, "abcd");
    printf("calling list_push() with \"%s\"\n", str);
    retval = list_push(list, str);
    printf("retval: %d\n", retval);
    list_print(list);;

    str = malloc(64);
    strcpy(str, "abcde");
    printf("calling list_push() with \"%s\"\n", str);
    retval = list_push(list, str);
    printf("retval: %d\n", retval);
    list_print(list);;

    str = malloc(64);
    strcpy(str, "second string!");
    retval = list_search(list, str);
    printf("called list_search() for \"%s\" -- count is: %d\n", str, retval);
    free(str);
    str = NULL;

    str = list_get(list, 3);
    printf("called list_get() @ index=3. string: %s\n", str);

    str = malloc(64);
    strcpy(str, "second string!");
    printf("calling list_update with str=\"%s\" and index=%d\n", str, 1);
    str = list_update(list, str, 1);
    printf("  previously stored string:\"%s\"\n", str);
    free(str);
    str = NULL;
    list_print(list);

    str = malloc(64);
    strcpy(str, "second string!");
    retval = list_search(list, str);
    printf("called list_search() for \"%s\" -- count is: %d\n", str, retval);
    free(str);
    str = NULL;

    str = list_remove(list, 0);
    printf("called list_remove() with index=0. string: %s\n", str);
    list_print(list);
    free(str);
    str = NULL;

    str = malloc(64);
    strcpy(str, "impostor string? is now here");
    printf("calling list_insert() with \"%s\" @ at index 0\n", str);
    retval = list_insert(list, str, 0);
    printf("retval: %d\n", retval);
    list_print(list);

    printf("now deleting the list\n");
    list_empty(list);
    list_print(list);

    free(list);
    list = NULL;

    return 0;
}