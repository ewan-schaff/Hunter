/*
** EPITECH PROJECT, 2023
** game_window.c
** File description:
** display the window of the game
*/
#include "my_hunter.h"

static char *put_nbr_str(struct game *htr)
{
    int i = 1000000000;
    int nb = htr->kill;
    int var = nb;
    int j = 0;

    htr->score = malloc(sizeof(char) * nb + 1);
    while (i > nb)
        i = i / 10;
    while (i != 0) {
        if ( nb / i >= 0) {
            nb = nb / i;
            htr->score[j] = nb + 48;
            j++;
            nb = var - nb * i;
            var = nb;
        }
        i = i / 10;
    }
    htr->score[j] = '\0';
}

static int init_game(struct game *htr)
{
    htr->rect.width = 237;
    htr->rect.height = 152;
    htr->rect.top = 0;
    htr->rect.left = 0;
    htr->offset = 0;
    htr->comet = htr->game;
}

void game_move(sfRenderWindow *window, struct game *htr)
{
    sfVector2f move = sfSprite_getPosition(htr->game);

    htr->time = sfClock_getElapsedTime(htr->clock2);
    htr->seconds = htr->time.microseconds / 1000000.0;
    if (htr->seconds >= 0.0002) {
        if (move.x < 1920) {
            move.x += htr->speed;
        }else {
            move.x = -230;
            move.y = rand() % 850;
        }
    sfSprite_setPosition(htr->game, move);
    sfClock_restart(htr->clock2);
    }
}

void game_display(sfRenderWindow *window, struct game *htr)
{
    htr->time = sfClock_getElapsedTime(htr->clock);
    htr->seconds = htr->time.microseconds / 1000000.0;
    if (htr->seconds >= 0.2) {
        if (htr->rect.left < 710) {
            htr->rect.left += 237;
        }else {
            htr->rect.left = 0;
        }
    sfSprite_setTextureRect(htr->game, htr->rect);
    sfClock_restart(htr->clock);
    }
}

void display_game(sfRenderWindow *window, struct game *htr)
{
    init_game(htr);
    game_display(window, htr);
    sfRenderWindow_drawSprite(window, htr->game, NULL);
}

void kill_bat(sfRenderWindow *window, struct game *htr)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f bat = sfSprite_getPosition(htr->game);
    sfVector2f pos = {100, 10};
    sfVector2f ran;

    ran.x = -230;
    ran.y = rand() % 850;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (mouse.x >= bat.x && mouse.x <= bat.x + 200
            && mouse.y >= bat.y + 50 && mouse.y <= bat.y + 150) {
                htr->kill += 1;
                htr->speed += 1;
                put_nbr_str(htr);
                display_score(window, htr);
                sfSprite_setPosition(htr->game, ran);
            }
    }
}
