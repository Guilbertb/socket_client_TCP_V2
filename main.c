/*
 * Client TCP Simple en reception
-------------------------------------------------------------------------------------------------------------------
socket()
connect()
recv()
close()
-------------------------------------------------------------------------------------------------------------------
*/


#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <unistd.h>

#define PORT 9002

int main(int argc, char ** argv)

{
    int network_socket;
    int connection_status;

    /* creation de la socket */
    network_socket= socket( AF_INET, SOCK_STREAM, 0);

    /* specication de  l'adresse pour la socket */

    struct  sockaddr_in  server_address;

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons (PORT); /* format pour */
    server_address.sin_addr.s_addr = INADDR_ANY;

    connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof (server_address));

    if (connection_status == -1)
    {
        printf("Pas de connection possible \n");
        return EXIT_FAILURE;
    }
    /* reception des donnees venant du server */

    char server_response[256];

    recv(network_socket, &server_response, sizeof(server_response), 0);

    printf("La reponse du serveur est : %s\n",server_response);

    /* fermer le prise */

    close(network_socket);
    return EXIT_SUCCESS;
}
