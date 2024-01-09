/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** recreat the ls function
*/
#include "my.h"

char *my_strdup(char *str)
{
    char *res;

    res = malloc(sizeof(char *) * 1000 + 1);
    res = my_strcpy(res, str);
    return res;
}

static char *catstr(char *str, char *file)
{
    char *src = str;
    char *car = my_strdup(str);

    if (my_strcmp(str, ".") == 0) {
        car = my_strcat(car, file);
        return car;
        }
    my_strcat(car, file);
    return car;
}

void display_right(struct dirent *entry, const char *file, struct stat *s)
{
    my_printf(S_ISDIR(s->st_mode) ? "d" : "-");
    my_printf(s->st_mode & S_IRUSR ? "r" : "-");
    my_printf(s->st_mode & S_IWUSR ? "w" : "-");
    my_printf(s->st_mode & S_IXUSR ? "x" : "-");
    my_printf(s->st_mode & S_IRGRP ? "r" : "-");
    my_printf(s->st_mode & S_IWGRP ? "w" : "-");
    my_printf(s->st_mode & S_IXGRP ? "x" : "-");
    my_printf(s->st_mode & S_IROTH ? "r" : "-");
    my_printf(s->st_mode & S_IWOTH ? "w" : "-");
    my_printf(s->st_mode & S_IXOTH ? "x" : "-");
}

int display_l(char *file, int ac, struct dirent *entry)
{
    struct passwd *pswrd;
    struct group *grp;
    struct stat s;
    char *str;

    str = catstr(file, entry->d_name);
    stat(str, &s);
    pswrd = getpwuid(s.st_uid);
    grp = getgrgid(s.st_gid);
    display_right(entry, file, &s);
    my_printf(" %d ", s.st_nlink);
    my_printf("%s ", pswrd->pw_name);
    my_printf("%s ", grp->gr_name);
    my_printf("%d ", s.st_size);
    write(1, (ctime(&s.st_mtime) + 4), 12);
    my_printf(" ");
    my_printf("%s\n", entry->d_name);
}

static int count_st_block(const char *file)
{
    DIR *dir;
    int nb_block = 0;
    int var;
    struct stat s;
    struct dirent *entry;

    dir = opendir(file);
    while (true) {
        entry = readdir(dir);
        if (entry == 0)
            return (nb_block / 2);
        if (entry->d_name[0] != '.') {
            stat(entry->d_name, &s);
            nb_block += s.st_blocks;
        }
    }
}

int my_ls_l(char *file, int ac)
{
    DIR *dir;
    struct dirent *entry;
    struct stat s;
    int i = 4;

    dir = opendir(file);
    while (true) {
        entry = readdir(dir);
        if (entry == 0)
            break;
        if (entry->d_name[0] != '.') {
            display_l(file, ac, entry);
        }
    }
    closedir(dir);
}
