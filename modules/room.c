#include <stdbool.h>
#include "../includes/room.h"


/**
 * Initialize a number of rooms based on their names
 * @param rooms The list of room to initialize
 * @param list_of_rooms The name of the rooms
 * @return A list of Rooms initialized with their name, id and users
 */
void initialize_n_rooms(Room (*rooms)[MAX_ROOMS], char** list_of_rooms) {
    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        rooms[i]->id = i + 1;
        strcpy(rooms[i]->name, list_of_rooms[i]);
        rooms[i]->number_of_user = 0;
    }
}


/**
 * Add a user to a channel / room
 * TODO: Handle max user connections
 * @param u The user to add
 * @param r The room to join in
 */
void add_user_to_room(User* u, Room* r) {
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
 * Remove a user from a rooml
 * @param u The user to remove
 * @param r The room to be disconnected from
 */
void remove_user_from_room(User* u, Room* r) {
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
 * Move a user from a room to another
 * @param u The user to move
 * @param r1 The origin room
 * @param r2 The target room
 */
void move_user_to_another_room(User* u, Room* r1, Room* r2) {
    remove_user_from_room(u, r1);
    add_user_to_room(u, r2);
}
