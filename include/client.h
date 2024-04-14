//
// Created by Justin Tunheim on 2/3/24.
//

#ifndef CELL99_CLIENT_H
#define CELL99_CLIENT_H

#include "flecs.h"

struct cell99_camera {};
struct cell99_input_handler {};

/*!
 * @typedef
 * An active or inactive participant. e.g Player, Spectator, Admin. */
typedef ecs_entity_t cell99_client_t;

/*!
 * @typedef
 * An Enttity composed of Components that describe the state necessary for the
 * _current_ machine's execution of the game binary.
 *  Such as camera, lighting, assets, etc. */
typedef ecs_entity_t cell99_passenger_t;

cell99_client_t    cell99_client   (ecs_world_t *ecs);
cell99_passenger_t cell99_passenger(ecs_world_t *ecs);

#endif //CELL99_CLIENT_H
