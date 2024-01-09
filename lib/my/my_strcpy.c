/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** Copy a string into another string
*/

char *my_strcpy(char *dest, char *src)
{
    int index = 0;

    while (src[index] != '\0') {
        dest[index] = src[index];
        index++;
    }
    dest[index] = '\0';
    return dest;
}
