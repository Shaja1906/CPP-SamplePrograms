
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8888
 
int main(int argc, char const* argv[])
{
    int sock, valread, client_fd = 0;
    struct sockaddr_in serv_addr = { 0, 0, {0}, '\0'};
    char* hello = (char*)("Hello from client");
    char buffer[1024] = { '\0' };
    
    // create a socket simillar to server
    if (0 > (sock = socket(AF_INET, SOCK_STREAM, 0))) {
        printf("\n Socket creation error \n");
        return -1;
    }
    
    printf("%s\n", "socket created");
 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
 
    
    if (inet_pton(AF_INET, "192.168.151.95", &serv_addr.sin_addr)
        <= 0) {
        printf(
            "\nInvalid address/ Address not supported \n");
        return -1;
    }
    
    // connect is a blocking call
    if (0 > (client_fd = connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))))
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    
    printf("%s\n", "Connection established");
    int i = 100;
    while ( i <= 100) {
    	send(sock, hello, strlen(hello), 0);
    	printf("Hello message sent\n");
    	valread = read(sock, buffer, 1024);
    	printf("%s\n", buffer);
	i--;
        usleep(1000);
    }
 
    // closing the connected socket
    close(client_fd);
    return 0;
}
