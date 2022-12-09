#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080 // default connecting to 8080 port
int main(int argc, char const* argv[])
{
	printf("%s\n","main");
	// always initialize variables.
	// int server_fd, new_socket, valread;
	int server_fd = 0;
	int new_socket = 0;
	int valread = 0;
	// struct sockaddr_in address;
	// Always initialize variables to default values.
	struct sockaddr_in address = { 0, 0, { 0 }, '\0' };
	// int opt = 1;
	// Commented to remove unused varaible for removing the warning message.
	int addrlen = sizeof(address);
	// char buffer[1024] = { 0 };
	// Initialize to null character instead of using zero
	char buffer[1024] = { '\0' };
	// char* hello = "Hello World from Server";
	// Convert string to (char*) to remove warning message.
	char* hello = (char*) "Hello World from Server";
	// Creating socket file descriptor
	// This will create a socket and return a file descriptor on success.
	// returns -1 on failure.
	// Takes 3 param, communication domain : whether local or internet
	// type - whether TCP or UDP
	// Protocal : 0 for IP protocal
	// if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	// Better to write value at left and variable/function at right to remove future errors due to typing.
	if( 0 > (server_fd = socket(AF_INET, SOCK_STREAM, 0) ) )
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	printf("%s\n","Server Socket created");
	// socket option set to reuse the socket address so that more than 1 instance
	// of the server can be launched
	int option = 1;
	setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option));
	// used to bind the Scoket to a Particular Port.
	// Structure containing details of the port.
	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);
	// The kernel will use to assign incoming packet on a particular port to the process socket
	// Param : File Descriptor, Address of the structure and size of the adress.
	// Better to write value at left and variable/function at right to remove future errors due to typing.
	// if( bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0)
	if( 0 > bind(server_fd, (struct sockaddr*)&address, sizeof(address) ) )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	printf("%s\n","Bind");
	// The Server will start listening on the socket
	// Params : File Descriptor and backlog queue size(maximum number of queued connections)
	// Better to write value at left and variable/function at right to remove future errors due to typing.
	// if( listen(server_fd, 3) < 0)
	if( 0 > listen(server_fd, 3) )
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	printf("%s\n","listen");
	// Update here to use select using timeout.
	// Accepts the incoming connection on the bound socket
	// This returns a new file descriptor, so that it can be used for communication with the client
	// While the original file descriptor can listen for other connections.
	// Accept blocks the call until a connection is available
	// Better to write value at left and variable/function at right to remove future errors due to typing.
	// if( (new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0)
	if( 0 > (new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) )
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}
	printf("%s\n","accept");
	// Reads the data sent by the client
	valread = read(new_socket, buffer, 1024);
	// use valread to remove warning message
	if ( valread )
	{
	}
	printf("%s\n", buffer);
	// Sends the data to the client
	send(new_socket, hello, strlen(hello), 0);
	printf("Hello message sent\n");
	// closing the connected socket
	close(new_socket);
	// closing the listening socket
	shutdown(server_fd, SHUT_RDWR);
	server_fd = 0;
	return 0;
}
