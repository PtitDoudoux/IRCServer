#ifndef IRC_SERVER_ROOM_H
#define IRC_SERVER_ROOM_H


#define MAX_ROOMS 10


#include "user.h"


/**
 * Room struct which represent a room
 */
typedef struct room {
    int  id;  // The ID of the room
    char name[25];  // The name of the room
    int uc[100];  // The list of connected users
    int number_of_user;
} Room;


void initialize_n_rooms(Room (*rooms)[], char** list_of_rooms);
void add_user_to_room(User* u, Room* r);
void remove_user_from_room(User* u, Room* r);
void move_user_to_another_room(User* u, Room* r1, Room* r2);


#endif //IRC_SERVER_ROOM_H
