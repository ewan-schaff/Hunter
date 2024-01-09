/*
** EPITECH PROJECT, 2023
** my_strncmp
** File description:
** compare two string
*/

int strcmp_len(char const *str1, char const *str2)
{
    int i = 0;
    int j = 0;

    while (str1[i] != '\0')
        i++;
    while (str2[j] != '\0')
        j++;
    if (i < j) {
        return (j);
    } else
        return (i);
}

int my_strcmp(char const *s1, char const *s2)
{
    int result;
    int i = 0;
    int len = strcmp_len(s1, s2);

    while (len > 0) {
        if (s1[i] != s2[i]) {
            result = s1[i] - s2[i];
            return (result);
        }
        i++;
        len--;
    }
    return (0);
}
