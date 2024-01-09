/*
** EPITECH PROJECT, 2023
** display_htrtures.c
** File description:
** display all htrture for the hunter
*/
#include "my_hunter.h"


sfText *display_text(sfRenderWindow *window, struct game *htr)
{
    sfVector2f     pos_text = {20, 10};

    htr->font = sfFont_createFromFile("./assets/dragon.ttf");
    htr->text = sfText_create();
    sfText_setString(htr->text, "SCORE : ");
    sfText_setFont(htr->text, htr->font);
    sfText_setCharacterSize(htr->text, 50);
    sfText_setPosition(htr->text, pos_text);
    return htr->text;
}

sfText *display_score(sfRenderWindow *window, struct game *htr)
{
    sfVector2f     pos_text = {240, 10};

    htr->cops = sfFont_createFromFile("./assets/dragon.ttf");
    htr->scr = sfText_create();
    sfText_setString(htr->scr, htr->score);
    sfText_setFont(htr->scr, htr->cops);
    sfText_setCharacterSize(htr->scr, 50);
    sfText_setPosition(htr->scr, pos_text);
    return htr->scr;
}

sfText *display_write(sfRenderWindow *window, struct game *htr)
{
    sfVector2f     pos_text = {640, 100};

    htr->tit = sfFont_createFromFile("./assets/dragon.ttf");
    htr->cave = sfText_create();
    sfText_setString(htr->cave, "  CAVE\nhunter");
    sfText_setFont(htr->cave, htr->tit);
    sfText_setCharacterSize(htr->cave, 150);
    sfText_setPosition(htr->cave, pos_text);
    return htr->cave;
}

sfText *display_play(sfRenderWindow *window, struct game *htr)
{
    sfVector2f     pos_text = {830, 690};

    htr->start = sfFont_createFromFile("./assets/dragon.ttf");
    htr->play = sfText_create();
    sfText_setString(htr->play, "PLAY");
    sfText_setFont(htr->play, htr->start);
    sfText_setCharacterSize(htr->play, 80);
    sfText_setPosition(htr->play, pos_text);
    return htr->play;
}

sfText *display_win(sfRenderWindow *window, struct game *htr)
{
    sfVector2f     pos_text = {730, 10};

    htr->vic = sfFont_createFromFile("./assets/dragon.ttf");
    htr->win = sfText_create();
    sfText_setString(htr->win, "\t\t\tYOU WIN\nCLIQUE ON ESCAPE TO CONTINUE");
    sfText_setFont(htr->win, htr->vic);
    sfText_setCharacterSize(htr->play, 80);
    sfText_setPosition(htr->win, pos_text);
    return htr->win;
}
