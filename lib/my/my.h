/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** containe the prototype of all the function exposed by libmy.a
*/
#include <dirent.h>
#include <fcntl.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysmacros.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#ifndef MY_H_
    #define MY_H_

char **my_str_to_word_array(char const *str);
char *my_strcpy(char *dest, char *src);
char *my_strcat(char *dest, char const *src);
char check_letter(char **av, int ac);
void my_putchar(char c);
void my_put_revstr(const char *str);
void my_put_revstr(const char *str);
long my_put_hexa_low(long nb);
long my_put_hexa_up(long nb);
long my_put_hexa_base(long nb);
double my_put_float(double nb);
float my_put_sci_up(double nb);
float my_put_sci(double nb);
int my_getnbr(char const *str);
int my_printf(const char *format, ...);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_nbr_long(long nb);
int my_put_octal(int nb);
int space_flag(const char *format, int i);
int my_ls(int ac, char **av);
int my_strcmp(char const *s1, char const *s2);
int my_ls_a(char *file);
int my_ls_base(char *file);
int my_ls_l(char *file, int ac);
int my_ls_la(const char *file, int ac);
int my_ls_d(char *file, int ac);
int check_directory(char *file, int ac);
int check_directory_a(char *file, int ac);
int check_directory_d(char *file, int ac);
int my_strcmp(char const *s1, char const *s2);
int check_dash(char **av, int ac);
int nbr_to_dash(char **av, int ac);
int is_same(char **av, int ac, int i);
int my_ls_l_base(char *file, int ac);
int my_str_isnum(char const *str);
int number_line(char *buffer);
int number_col(char *buffer);
int find_error(char *buffer);
int generation_map(int ac, char **av);
int error_find(char **av, int ac);


typedef struct myls {
    int i;
    int j;
    int condi;
    int size;
} myls;

typedef struct error     {
    int j;
} error;

typedef struct setting_up  {
    int y;
    int x;
    int i;
    int nb_line;
    int nb_col;
} setting_up;

typedef struct save_square {
    int y;
    int x;
    int y2;
    int x2;
    int s_size;
    int save;
} save_square;

//function with struct
int find_square(char **array, struct setting_up *set);
int error_letter(char **av, struct myls *ls, int ac);
int error_manage(char **av, struct error *err);
#endif /* MY_H_ */
