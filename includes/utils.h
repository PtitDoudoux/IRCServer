#ifndef IRC_SERVER_UTILS_H
#define IRC_SERVER_UTILS_H


#include <string.h>
#include <unistd.h>


#define max(x,y) ((x)>(y)?(x):(y))


char* strip_new_line(char* s);
void broadcast_to_everyone(int* connected, int nb_connected, char* msg, char* from);
void broadcast_to_everyone_except_one(int* connected, int nb_connected, char* msg, char* from, int excepted);


#endif //IRC_SERVER_UTILS_H
