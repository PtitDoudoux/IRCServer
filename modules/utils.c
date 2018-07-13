#include "../includes/utils.h"


/**
  * Replace any new line char by a '\0'
  * @param s The string to strip
  * @return The stripped string
  */
char* strip_new_line(char* s) {
    s[strcspn(s, "\r")] = 0;
    s[strcspn(s, "\n")] = 0;
    return s;
}


/**
  * Broadcast a message to everyone
  * @param connected The array of connected user ID
  * @param nb_connected the number of user connected
  * @param msg The message to send
  * @param from The Sender of the message
  */
void broadcast_to_everyone(int* connected, int nb_connected, char* msg, char* from) {
     int i;
     char tmp[512];
     if (msg[0] != '\0') {
        memset(&tmp, 0, sizeof(tmp));
        strcpy(tmp, from);
        strcat(tmp, " : ");
        strcat(tmp, msg);
        for (i = 0; i < nb_connected; i++) write(connected[i], tmp, sizeof(tmp));
     }
}


/**
 * Broadcast a message to everyone
 * @param connected The array of connected user ID
 * @param nb_connected the number of user connected
 * @param msg The message to send
 * @param from The Sender of the message
 * @param The excepted user id
 */
void broadcast_to_everyone_except_one(int* connected, int nb_connected, char* msg, char* from, int excepted) {
    int i;
    char tmp[512];
    if (msg[0] != '\0') {
        memset(&tmp, 0, sizeof(tmp));
        strcpy(tmp, from);
        strcat(tmp, " : ");
        strcat(tmp, msg);
        for (i = 0; i < nb_connected; i++)
            if (i != excepted) write(connected[i], tmp, sizeof(tmp));
    }
}
