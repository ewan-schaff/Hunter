/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** write a function that split a string into word
*/

#include <stddef.h>
#include <stdlib.h>

int test_alphanum(char i)
{
    if (i >= '0' && i <= '9')
        return 1;
    if (i >= 'A' && i <= 'Z')
        return 1;
    if (i >= 'a' && i <= 'z') {
        return 1;
    }else{
        return 0;
    }
}

int len_str(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

int nb_word(char const *str)
{
    int i = 0;
    int j = 0;
    int var = 0;

    while (str[i] != '\0') {
        if (test_alphanum(str[i]) == 0 && j == 0) {
            var++;
            j = 1;
        }
        if (test_alphanum(str[i]) != 0 && j == 1) {
            j = 0;
        }
        i++;
        if (str[i] == '\0' && j == 0) {
            var++;
        }
    }
    return var;
}

char *new_str(char const *str, int i)
{
    int var = 0;
    int j = 0;
    char *nstr;

    nstr = malloc(sizeof(char *) * nb_word(str) + 1);
    while (test_alphanum(str[i]) != 0) {
        i++;
        var++;
    }
    i = i - var;
    while (j != var) {
        nstr[j] = str[i];
        i++;
        j++;
    }
    return nstr;
}

char **my_str_to_word_array(char const *str)
{
    char **array;
    char *src;
    int i = 0;
    int k = 0;

    array = malloc(sizeof(char *) * len_str(str) + sizeof(NULL));
    if (str[0] == '\0')
        return NULL;
    while (str[i] != '\0') {
        if (test_alphanum(str[i])) {
            src = new_str(str, i);
            array[k] = src;
            i = i + len_str(src);
            k++;
        } else {
            i++;
        }
    }
    array[k] = NULL;
    return array;
}
