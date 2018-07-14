#ifndef IRC_SERVER_USER_H
#define IRC_SERVER_USER_H


#define MAX_CONN 1000


#include <stdbool.h>
#include <memory.h>


/**
 * User struct which represent a user
 */
typedef struct user {
    // char nick[25];  // The nickname of the room_user
    char username[25];  // The name of the room_user
    int connection_id;  // The ID of the room_user
    // bool is_admin;  // If the room_user is an admin or not
} User;


void initialize_user_list(User** users, int max);
void user_connection(User (*users)[], int conn_id, char* username);
void user_disconnection(User** users, int conn_id);


#endif //IRC_SERVER_USER_H
