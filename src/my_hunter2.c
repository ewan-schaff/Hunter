/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** second file for all main function
*/
#include "my_hunter.h"

void hunter_destroy(sfRenderWindow *window, struct game *htr)
{
    sfMusic_stop(htr->music);
    sfMusic_stop(htr->sound);
    sfRenderWindow_destroy(window);
}

void pos_rect(struct game *htr)
{
    sfVector2f dep = {-230, 50};
    sfVector2f setpos = {5000, 500};

    sfSprite_setPosition(htr->button, setpos);
    sfText_setPosition(htr->cave, setpos);
    sfSprite_setPosition(htr->game, dep);
    sfText_setPosition(htr->play, setpos);
    sfText_setPosition(htr->play2, setpos);
}

sfText *display_play2(sfRenderWindow *window, struct game *htr)
{
    sfVector2f     pos_text2 = {830, 690};

    htr->start2 = sfFont_createFromFile("./assets/dragon.ttf");
    htr->play2 = sfText_create();
    sfText_setString(htr->play2, "PLAY");
    sfText_setFont(htr->play2, htr->start2);
    sfText_setCharacterSize(htr->play2, 80);
    sfText_setPosition(htr->play2, pos_text2);
    sfText_setColor(htr->play2, sfBlack);
    return htr->play2;
}

sfSprite *display_break(sfRenderWindow *window, struct game *htr)
{
    sfTexture       *texture_button;
    sfVector2f      set_pos_button = {750, 650};
    sfVector2f      scale = {0.5, 0.5};

    htr->brek;
    texture_button = sfTexture_createFromFile("./assets/break.png", NULL);
    htr->brek = sfSprite_create();
    sfSprite_setTexture(htr->brek, texture_button, sfTrue);
    sfSprite_setScale(htr->brek, scale);
    sfSprite_setPosition(htr->brek, set_pos_button);
    return htr->brek;
}

void mouse_statement(sfRenderWindow *window, struct game *htr, sfEvent event)
{
    sfVector2f sprite = sfSprite_getPosition(htr->button);
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f      set_pos_button = {5000, 5000};

    if (pos.x >= sprite.x && pos.x <= sprite.x + 360
            && pos.y >= sprite.y + 30 && pos.y <= sprite.y + 180) {
            sfText_setColor(htr->play, sfBlack);
    } else {
            sfText_setColor(htr->play, sfWhite);
    }
    if (pos.x >= sprite.x && pos.x <= sprite.x + 360
        && pos.y >= sprite.y + 30 && pos.y <= sprite.y + 180) {
        if (event.type == sfEvtMouseButtonReleased) {
            htr->butt = 4;
        }
    }
}
