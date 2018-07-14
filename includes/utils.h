#ifndef IRC_SERVER_UTILS_H
#define IRC_SERVER_UTILS_H


#include <string.h>
#include <unistd.h>
#include "user.h"
#include "room.h"


#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))


char* strip_new_line(char* s);
void broadcast_to_everyone(int* connected, int nb_connected, char* msg, char* from);
void broadcast_to_everyone_except_one(int* connected, int nb_connected, char* msg, char* from, int excepted);
void broadcast_to_channel_except_one(int* connected, User (*users)[], Room (*rooms)[], char* msg, int conn_id, int uid);


#endif //IRC_SERVER_UTILS_H
