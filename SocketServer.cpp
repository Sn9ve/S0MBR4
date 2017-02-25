#include "SocketServer.h"

Socket SocketServer::init_socket(){
	sock = socket(AF_INET, SOCK_STREAM, 0);
	char value = 1;
	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value));

	if(sock == INVALID_SOCKET)
		error("error creating socket");

	sockaddr_in sin;
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(23);

	if(bind(sock, (sockaddr*)&sin, sizeof(sin)) == INVALID_SOCKET)
		error("error binding socket");


	if(listen(sock, 5) == SOCKET_ERROR)
		error("error listening");

	return sock;
}

Socket SocketServer::add_client(Socket socket){
	sockaddr_in csin = { 0 };
	socklen_t size = sizeof(csin);

	clientSock = accept(socket, (sockaddr*)&csin, &size);

	if(clientSock == INVALID_SOCKET)
		error("error accepting");

	return clientSock;
}
/*
void SocketServer::write(std::string msg, int length){
	
	Socket n = write(newsockfd, msg, length);
	if (n < 0) 
		error("ERROR writing to socket");
}
*/
char* SocketServer::readSocket(int length){
	int nb = 0, offset = 0;
	char buffer[2];

	while(1){
		nb = recv(clientSock, &buffer[offset], sizeof(buffer) - offset, 0);
		offset += nb;
		if(nb <= 0){
			shutdown(clientSock, SHUT_RDWR);
			closesocket(clientSock);
			return buffer;
		}

		if(offset == 2){
			printf("Received --> x: %d, y: %d\n", buffer[0], buffer[1]);
			offset = 0;
			return buffer;
		}
	}
}

void SocketServer::closeSocket(){
	close(clientSock);
	close(sock);
}

void error(const char *msg){
	perror(msg);
	exit(1);
}
