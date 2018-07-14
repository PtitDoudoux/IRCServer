#include "../includes/user.h"


/**
 * Initialize a list of empty users
 * @param users The list of users to initialize
 * @pram max The maximum number of users
 */
void initialize_user_list(User** users, int max) {
    int i;
    for (i = 0; i < max; i++) {
        users[i]->connection_id = 0;
        memset(&users[i]->username, 0, sizeof(users[i]->username));
    }
}


/**
 * Add a user to a list of connected users
 * @param users The list of connected users to add in
 * @param conn_id The ID of the users
 * @param username The username of the user
 */
void user_connection(User (*users)[MAX_CONN], int conn_id, char* username) {
    int i = 0;
    while (true) {
        if (users[i]->connection_id == 0) {
            users[i]->connection_id = conn_id;
            strcpy(users[i]->username, username);
            break;
        }
        i++;
    }
}


/**
 * Remove a user from a list of connected users
 * @param users The list of user to search in
 * @param conn_id The ID of the user to be removed
 */
void user_disconnection(User** users, int conn_id) {
    int i = 0;
    while (true) {
        if (users[i]->connection_id == conn_id) {
            users[i]->connection_id = 0;
            memset(&users[i]->username, 0, sizeof(users[i]->username));
            break;
        }
        i++;
    }
}
