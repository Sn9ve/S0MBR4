#include "SocketServer.h"

using asio::ip::tcp;

//static const int PORT = 52275;

void SocketServer::serverListener() {
	std::cout << "server is strating " << std::endl;
    try{
        asio::io_service io_service;
        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), PORT));

        for (;;){
            tcp::socket socket(io_service);
            acceptor.accept(socket);

            asio::streambuf sb;
            asio::error_code ec;
            while (asio::read(socket, sb, ec)) {
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

