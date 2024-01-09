/*
** EPITECH PROJECT, 2023
** display_htrtures.c
** File description:
** display all htrture for the hunter
*/
#include "my_hunter.h"

sfSprite *display_planets(sfRenderWindow *window, struct game *htr)
{
    sfTexture       *texture_button;
    sfVector2f      set_pos_button = {750, 650};
    sfVector2f      scale = {0.5, 0.5};

    htr->button;
    texture_button = sfTexture_createFromFile("./assets/stone.png", NULL);
    htr->button = sfSprite_create();
    sfSprite_setTexture(htr->button, texture_button, sfTrue);
    sfSprite_setScale(htr->button, scale);
    sfSprite_setPosition(htr->button, set_pos_button);
    return htr->button;
}

sfSprite *display_sprite(sfRenderWindow *window, struct game *htr)
{
    sfTexture       *texture;

    htr->sprite;
    texture = sfTexture_createFromFile("./assets/cave.png", NULL);
    htr->sprite = sfSprite_create();
    sfSprite_setTexture(htr->sprite, texture, sfTrue);
    return htr->sprite;
}

sfSprite *display_game_bg(sfRenderWindow *window, struct game *htr)
{
    sfTexture       *texture_game;

    htr->game;
    texture_game = sfTexture_createFromFile("./assets/bat_sheet.png", NULL);
    htr->game = sfSprite_create();
    sfSprite_setTexture(htr->game, texture_game, sfTrue);
    return htr->game;
}

sfSprite *display_scope(sfRenderWindow *window, struct game *htr)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfTexture       *texture_scope;
    sfVector2f      scale = {0.3, 0.3};

    htr->scope;
    texture_scope = sfTexture_createFromFile("./assets/cross_cross.png", NULL);
    htr->scope = sfSprite_create();
    sfSprite_setTexture(htr->scope, texture_scope, sfTrue);
    sfSprite_setScale(htr->scope, scale);
    return htr->scope;
}
