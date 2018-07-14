#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/select.h>
#include <stdbool.h>
#include "includes/utils.h"
#include "includes/user.h"
#include "includes/room.h"


// TODO: Handle disconnection
// TODO: Handle max connection
// TODO: Handle Room switching
// TODO: Handle the modification and availability of a username


/**
 * Start a server on a socket
 * @param lf The adress of the socket to start listening on
 * @param mc The max connection on the socket
 * @return The status of the function
 */
int starting_server(int *lf, int mc) {
    int error = 0, server_port = 4444;
    struct sockaddr_in server_socket;
    char* server_addr = "127.0.0.1";
    printf("Welcome to the ESGI IRC Server !\n");

    // Definition of the server
    memset(&server_socket, 0, sizeof(server_socket));
    server_socket.sin_family = AF_INET;
    server_socket.sin_port = htons(server_port);
    inet_pton(AF_INET, server_addr, &server_socket.sin_addr);

    // Launching the server
    *lf = socket(AF_INET, SOCK_STREAM, 0);
    error = bind(*lf, (struct sockaddr*)&server_socket, sizeof(server_socket));
    if (error != 0) {
        printf("An error as occured during the bind ! Error %d\n", error);
        return error;
    }
    error = listen(*lf, mc);
    if (error != 0) {
        printf("Can't listen on %s:%d\n ! Error %d", server_addr, server_port, error);
        return error;
    }
    printf("Listening on %s:%d\n !", server_addr, server_port);

    return 0;
}


/**
 * Server for a socket
 * @return The status of the server
 */
int server() {
    int i, y, count = 0, maxfdp1 = 0, error = 0,
            listen_fd = 0, active_conn[MAX_CONN];
    char msg_buffer[512];
    User user_list[MAX_CONN];  // initialize_user_list(user_list, max_conn);
    Room room_list[MAX_ROOMS];
    char* room_name[] = {"room1", "room2", "room3", "room4", "room5", "room6", "room7", "room8", "room9", "room10"};
    initialize_n_rooms(room_list, room_name);
    fd_set rdfs;

    error = starting_server(&listen_fd, MAX_CONN);
    if (error != 0) {
        printf("An error occured ! Exiting !\n");
        return -1;
    }
    active_conn[0] = listen_fd;
    count++;
    maxfdp1 = listen_fd + 1;

    // Serving ...
    while (true) {
        FD_ZERO(&rdfs);
        for (i = 0; i < count; i++) FD_SET(active_conn[i], &rdfs);
        select(maxfdp1, &rdfs, NULL, NULL, NULL);

        // Handle User connection
        if (FD_ISSET(listen_fd, &rdfs)) {
            active_conn[count] = accept(listen_fd, NULL, NULL);
            write(active_conn[count], "Set username : ", sizeof("Set username : "));
            memset(&msg_buffer, 0, sizeof(msg_buffer));
            read(active_conn[count], &msg_buffer, 512);
            strip_new_line(msg_buffer);
            user_connection(user_list, active_conn[count], msg_buffer);
            add_user_to_room(&user_list[count-1], &room_list[0]);
            strcat(msg_buffer, " connected !\n");
            write(active_conn[i], msg_buffer, sizeof(msg_buffer)); // TODO: Write to everyone
            count++;
            maxfdp1 = max(maxfdp1, active_conn[count]) + 1;  // Why the last fd ?
        }

        // Handle User messaging
        for (i = 0; i < count; i++) {
            if (FD_ISSET(active_conn[i], &rdfs)) {
                memset(&msg_buffer, 0, sizeof(msg_buffer));
                read(active_conn[i], &msg_buffer, 512);
                // broadcast_to_everyone_except_one(active_conn, count, msg_buffer, user_list[i].username, i);
                broadcast_to_channel_except_one(active_conn, user_list, room_list, msg_buffer, active_conn[i], i);
            }
        }
    }

    return 0;
}


/**
 * Main Function
 * @return Status of main function
 */
int main() {
    server();
    return 0;
}
