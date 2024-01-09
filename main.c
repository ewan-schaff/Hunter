/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** project my_hunter named space hunter in this case
*/
#include "./src/my_hunter.h"
#include "./lib/my/my.h"

static void helper_flag(void)
{
    write(1, "USAGE\n", 6);
    write(1, "\t./my_hunter\n", 14);
    write(1, "DESCRIPTION\n", 13);
    write(1, "\tThis project is a small video game ", 37);
    write(1, "based on the rules of Duck Hunt\n", 33);
    write(1, "\tHere we make a hunter on the theme of the space\n", 50);
    write(1, "\tPressed start to begin and mouse click left to play\n", 53);
}

void move_sprite(sfRenderWindow *window, struct game *htr)
{
    sfVector2f max;
    sfVector2f ran = {0, rand() % 850};

    max = sfSprite_getPosition(htr->game);
    game_move(window, htr);
    if (max.x >= 2000)
        sfSprite_setPosition(htr->game, ran);
}

void pos_scope(sfRenderWindow *window, struct game *htr)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos_scope;

    pos_scope.x = mouse.x - 30;
    pos_scope.y = mouse.y - 60;
    sfSprite_setPosition(htr->scope, pos_scope);
}

static void print_assets(sfRenderWindow *window, struct game *htr)
{
    htr->sprite = display_sprite(window, htr);
    htr->button = display_planets(window, htr);
    htr->game = display_game_bg(window, htr);
    htr->scope = display_scope(window, htr);
    htr->text = display_text(window, htr);
    htr->scr = display_score(window, htr);
    htr->cave = display_write(window, htr);
    htr->play = display_play(window, htr);
    htr->win = display_win(window, htr);
    htr->play2 = display_play2(window, htr);
    htr->brek = display_break(window, htr);
}

void analyse_event(sfRenderWindow *window, sfEvent event, struct game *htr)
{
    sfVector2i pos;
    sfVector2f sprite_pos = sfSprite_getPosition(htr->button);

    pos = sfMouse_getPositionRenderWindow(window);
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
    mouse_statement(window, htr, event);
    kill_bat(window, htr);
    if (event.type == sfEvtMouseButtonReleased
            && pos.x > sprite_pos.x && pos.x + 50 < sprite_pos.x + 350
            && pos.y > sprite_pos.y && pos.y < sprite_pos.y + 200) {
            htr->butt = 1;
            sfMusic_play(htr->sound);
            pos_rect(htr);
            display_game(window, htr);
        }
}

static void display_assets(sfRenderWindow *window, struct game *htr)
{
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfRenderWindow_drawSprite(window, htr->sprite, NULL);
    sfRenderWindow_drawSprite(window, htr->button, NULL);
    sfRenderWindow_drawText(window, htr->cave, NULL);
    sfRenderWindow_drawText(window, htr->text, NULL);
    sfRenderWindow_drawText(window, htr->play, NULL);
    sfRenderWindow_drawText(window, htr->scr, NULL);
    if (htr->butt == 1)
        sfRenderWindow_drawSprite(window, htr->game, NULL);
    if (htr->butt == 2)
        sfRenderWindow_drawText(window, htr->play2, NULL);
    if (htr->butt == 3)
        sfRenderWindow_drawText(window, htr->play, NULL);
    sfRenderWindow_drawSprite(window, htr->scope, NULL);
}

static void init_hunter(sfRenderWindow *window, struct game *htr)
{
    htr->music = sfMusic_createFromFile("./assets/bat_theme.ogg");
    htr->score = "0";
    htr->butt = 0;
    htr->kill = 0;
    htr->speed = 5;
    htr->clock = sfClock_create();
    htr->clock2 = sfClock_create();
    htr->sound = sfMusic_createFromFile("./assets/transition_bat.ogg");
    sfMusic_setLoop(htr->music, sfTrue);
    sfMusic_play(htr->music);
}

static void more_hunter(sfRenderWindow *window, struct game *htr)
{
    move_sprite(window, htr);
    game_display(window, htr);
    pos_scope(window, htr);
    display_assets(window, htr);
    sfRenderWindow_display(window);
}

void my_hunter(void)
{
    struct game htr;
    sfVector2f set_pos_game = {0, 0};
    sfVideoMode     video_mode = {1920, 1080, 32};
    sfRenderWindow  *window;
    sfEvent         event;

    init_hunter(window, &htr);
    window = sfRenderWindow_create(video_mode, "huntr", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    print_assets(window, &htr);
    while (sfRenderWindow_isOpen(window)) {
            sfRenderWindow_clear(window, sfBlack);
            while (sfRenderWindow_pollEvent(window, &event)) {
                analyse_event(window, event, &htr);
            }
            more_hunter(window, &htr);
        }
    hunter_destroy(window, &htr);
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            helper_flag();
            return 0;
        }else
            return 84;
    } else if (ac > 2) {
        return 84;
    }else {
        my_hunter();
    }
}
