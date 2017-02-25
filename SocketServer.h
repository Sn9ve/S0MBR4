#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close (s)
#define PORT 23

typedef struct sockaddr_in sockaddr_in;
typedef struct sockaddr sockaddr;
typedef int Socket;

class SocketServer{
	public : 
		Socket sock, clientSock;

		Socket init_socket();
        Socket add_client(Socket socket);
		//void write(std::string msg, int length);
		char* readSocket(int length);
		void closeSocket();
};

void error(const char *msg);
