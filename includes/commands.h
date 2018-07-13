#ifndef IRC_SERVER_COMMANDS_H
#define IRC_SERVER_COMMANDS_H


#include "user.h"
#include "room.h"


int parse_cmd(char* cmd, User* u, Room* r);
void join_cmd(Room* r, User* u);
void nick_cmd(char* nick, User* u);
void list_cmd(Room* r);
void quit_cmd();
void help_cmd();


#endif //IRC_SERVER_COMMANDS_H
