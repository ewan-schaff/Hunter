/*
** EPITECH PROJECT, 2023
** bs_csfml.h
** File description:
** .h for the bs of the csfml
*/
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/Network.h>
#include <SFML/System.h>
#include <SFML/System/Export.h>
#include <SFML/System/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Window.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/BlendMode.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/ConvexShape.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/FontInfo.h>
#include <SFML/Graphics/Glyph.h>
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderStates.h>
#include <SFML/Graphics/RenderTexture.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Shader.h>
#include <SFML/Graphics/Shape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Transformable.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Graphics/VertexArray.h>
#include <SFML/Graphics/VertexBuffer.h>
#include <SFML/Graphics/View.h>

#ifndef BS_CSFML_H_
    #define BS_CSFML_H_

typedef struct game{
    sfSprite        *comet;
    sfSprite        *button;
    sfSprite        *button2;
    sfSprite        *brek;
    sfSprite        *moon1;
    sfSprite        *moon2;
    sfSprite        *moon3;
    sfSprite        *mars;
    sfSprite        *sprite;
    sfSprite        *title;
    sfSprite        *game;
    sfSprite        *scope;
    sfSprite        *moon4;
    sfFont          *font;
    sfFont          *tit;
    sfFont          *start2;
    sfText          *play2;
    sfFont          *start;
    sfText          *play;
    sfFont          *vic;
    sfText          *win;
    sfFont          *cops;
    sfText          *text;
    sfText          *cave;
    sfText          *scr;
    sfClock         *clock;
    sfClock         *clock2;
    sfTime          time;
    sfTime          time2;
    sfVector2f      pos;
    sfIntRect       rect;
    sfIntRect       rect2;
    sfMusic         *sound;
    sfMusic        *music;
    float           seconds;
    float           seconds2;
    int             speed;
    int             offset;
    int             miss;
    int             kill;
    int             butt;
    char            *score;
}   game;

sfSprite *display_title(sfRenderWindow *window, struct game *htr);
sfSprite *display_planets(sfRenderWindow *window, struct game *htr);
sfSprite *display_sprite(sfRenderWindow *window, struct game *htr);
sfSprite *display_game_bg(sfRenderWindow *window, struct game *htr);
sfSprite *display_scope(sfRenderWindow *window, struct game *htr);
sfSprite *display_break(sfRenderWindow *window, struct game *htr);
sfText *display_text(sfRenderWindow *window, struct game *htr);
sfText *display_score(sfRenderWindow *window, struct game *htr);
sfText *display_write(sfRenderWindow *window, struct game *htr);
sfText *display_play(sfRenderWindow *window, struct game *htr);
sfText *display_play2(sfRenderWindow *window, struct game *htr);
sfText *display_win(sfRenderWindow *window, struct game *htr);
void mouse_statement(sfRenderWindow *window, struct game *htr, sfEvent event);
void hunter_destroy(sfRenderWindow *window, struct game *htr);
void pos_rect(struct game *htr);
void game_display(sfRenderWindow *window, struct game *htr);
void kill_bat(sfRenderWindow *window, struct game *htr);
void display_game(sfRenderWindow *window, struct game *htr);
void game_move(sfRenderWindow *window, struct game *htr);
#endif /* !BS_CSFML_H_ */
