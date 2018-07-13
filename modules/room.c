#include <stdbool.h>
#include "../includes/room.h"


/**
 * Initialize a number of rooms based on their names
 * @param list_of_rooms
 * @return A list of Rooms initialized with their name, id and users
 */
Room* initialize_n_rooms(char** list_of_rooms) {
    int i, number_of_rooms = sizeof(list_of_rooms);
    Room* rooms[number_of_rooms];
    for (i = 1; i < number_of_rooms + 1; i++) {
        rooms[i]->id = i;
        *rooms[i]->name = *list_of_rooms[i];
        rooms[i]->number_of_user = 0;
    }
    return *rooms;
}


/**
 * Add a user to a channel / room
 * TODO: Handle max user connections
 * @param u The user to add
 * @param r The room to join in
 */
void add_user_to_channel(User* u, Room* r) {
    int i = 0;
    if (r->number_of_user < 100) {
        while (true) {
            if (r->uc[i] == 0) {
                r->uc[i] = u->connection_id;
                r->number_of_user++;
                break;
            }
            i++;
        }
    }
}


/**
 * Remove a user from a channel
 * @param u The user to remove
 * @param r The channel to be disconnected from
 */
void remove_user_from_channel(User* u, Room* r) {
    int i = 0;
    while (true) {
        if (r->uc[i] == u->connection_id) {
            r->uc[i] = 0;
            r->number_of_user--;
            break;
        }
        i++;
    }
}


/**
 * Move a user from a channel to another
 * @param u The user to move
 * @param r1 The origin room
 * @param r2 The target room
 */
void move_user_to_another_channel(User* u, Room* r1, Room* r2) {
    remove_user_from_channel(u, r1);
    add_user_to_channel(u, r2);
}
