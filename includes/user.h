#ifndef IRC_SERVER_USER_H
#define IRC_SERVER_USER_H


#include <stdbool.h>


/**
 * User struct which represent a user
 */
typedef struct user {
    // char nick[25];  // The nickname of the room_user
    char username[25];  // The name of the room_user
    int connection_id;  // The ID of the room_user
    // bool is_admin;  // If the room_user is an admin or not
} User;


User** user_connection(User** users, int conn_id, char* username);
User** user_disconnection(User** users, int conn_id);


#endif //IRC_SERVER_USER_H
