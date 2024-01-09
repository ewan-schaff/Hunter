/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** Return the len of a string in parameter
*/

int my_strlen(char const *str)
{
    int index = 0;

    while (str[index] != '\0') {
        index++;
    }
    return index;
}
