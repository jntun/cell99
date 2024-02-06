//
// Created by Justin Tunheim on 2/3/24.
//

#include "include/client.h"

cell99_client_t cell99_client(ecs_world_t *ecs)
{
    ecs_entity_t client = ecs_new_id(ecs);
    return client;
}

cell99_passenger_t cell99_passenger(ecs_world_t *ecs)
{
    ecs_entity_t passenger = ecs_new_id(ecs);
    return passenger;
}