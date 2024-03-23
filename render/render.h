//
// Created by Justin Tunheim on 2/26/24.
//

#ifndef CELL99_RENDER_H
#define CELL99_RENDER_H

#define CELL99_RENDER_BUILD

#define CELL99_RENDER_WIDTH  1280
#define CELL99_RENDER_HEIGHT 720

#define DEFAULT_GAME_WIDTH  CELL99_RENDER_WIDTH
#define DEFAULT_GAME_HEIGHT CELL99_RENDER_HEIGHT

#include <stdio.h>
#include <string.h>
#include <util.h>
#include <stdbool.h>

#include <SDL.h>
#include <SDL_opengl.h>
#ifdef __APPLE__
#include <OpenGL/glu.h> // [mac/i]OS OpenGL headers are in OpenGL/
#else
#include <GL/gl.h>
#endif

#include "game.h"


char static* DEFAULT_APP_TITLE = "cell99";

struct render_program {
    GLuint id;
    GLint  vertex_pos_2d_location;
    GLuint vbo;
    GLuint ibo;
};

struct renderer {
    uint8_t        width;
    uint8_t        height;

    struct render_program program;

    char const    *title;
    SDL_Window    *window;
    SDL_GLContext *gl;
};

static struct render_program init_program = {
        0,
        -1,
        0,
        0
};

static struct renderer renderer_default()
{
    struct renderer settings = {
            .width  = DEFAULT_GAME_WIDTH,
            .height = DEFAULT_GAME_HEIGHT,
            .title  = DEFAULT_APP_TITLE,
            .window = NULL,
    };

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

#define SDL2_text KTXT(KBLU, "sdl2")
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        printf(KTXT(KBLU, "sdl2") " failed initializing.\n");
        return settings;
    }
    settings.window = SDL_CreateWindow(
            settings.title,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            settings.width,
            settings.height,
            SDL_WINDOW_OPENGL
    );
    SDL_Delay(100);
    if (settings.window == NULL) {
        printf(SDL2_text " failed to initialize window: %s\n", SDL_GetError());
        return settings;
    }

    settings.gl = SDL_GL_CreateContext(settings.window);
    if (!settings.gl) {
        printf(SDL2_text " could not create OpenGL context: %s\n", SDL_GetError());
        return settings;
    }

    if (SDL_GL_SetSwapInterval(1) < 0) {
        printf(SDL2_text " couldn't enable v-sync: %s\n", SDL_GetError());
    }

    printf(SDL2_text " initialized.\n");
#undef SDL2_text

    return settings;
}

cell99_game_t render(struct renderer *r, cell99_game_t game);

#endif //CELL99_RENDER_H
