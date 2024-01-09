/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** returns a number
*/

int condition(char const *str, int nbr, int i)
{
    if (str[i] == '\0') {
        return (nbr);
    }
    if (str[i] >= 48 && str[i] <= 57) {
        nbr = nbr * 10;
        nbr = nbr + (str[i] - 48);
    }
    return (nbr);
}

int cond_val(char const *str, int val, int i)
{
    int val2 = 1;

    if (str[i] == 43) {
        val2 = 1;
    }
    if (str[i] == 45) {
        val2 = -1;
    }
    val = val * val2;
    return (val);
}

int my_getnbr(char *str)
{
    int i = 0;
    int cond = 0;
    int val = 1;
    int nbr = 0;

    while (cond != 1) {
        if (nbr > 2147483648 || nbr < 0)
            return (0);
        if (nbr != 0 && str[i] < 48 || str[i] > 57) {
            nbr = nbr * val;
            return (nbr);
        }
        val = cond_val(str, val, i);
        nbr = condition(str, nbr, i);
        i++;
    }
    return (nbr);
}
