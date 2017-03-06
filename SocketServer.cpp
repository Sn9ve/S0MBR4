#include "SocketServer.h"

using asio::ip::tcp;

//static const int PORT = 52275;

void SocketServer::serverListener() {
	try{
		// Création du service principal et du résolveur.
		asio::io_service ios;
					
		// Création de l'acceptor avec le port d'écoute 7171 et une adresse quelconque de type IPv4 // (1)
		tcp::acceptor acceptor(ios, tcp::endpoint(tcp::v4(), PORT));
					
		std::string msg ("Bienvenue sur le serveur !"); // (2)
		// On attend la venue d'un client
		asio::streambuf sb;
		asio::error_code ec;
		while (1)
		{
			// Création d'une socket
			tcp::socket socket(ios); // (3)
					
			// On accepte la connexion
			acceptor.accept(socket); // (4)
			std::cout << "Client reçu ! " << std::endl;
				
			// On reçoit les messages
			while(asio::read(socket, sb, ec)){ // (5)
				std::cout << "received: '" << &sb << "'\n";

				if (ec) {
					std::cout << "status: " << ec.message() << "\n";
					break;
				}
			}
		}
	}	catch (std::exception& e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }
				
}

