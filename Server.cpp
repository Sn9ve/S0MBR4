#include "Server.h"

	Server::Server(asio::io_service &io_service, short port): socket_(io_service, udp::endpoint(udp::v4(), port)){
		do_receive();
	}

	void Server::do_receive()  {
		socket_.async_receive_from( asio::buffer(data_, max_length), sender_endpoint_,
			[this](std::error_code ec, std::size_t bytes_recvd)
		{
			if (!ec && bytes_recvd > 0){
				std::cout << "reception d'un msg --> " << sizeof(data_) << std::endl;
				int32_t x, y;
				std::memcpy(&x, data_, sizeof(x));
				std::memcpy(&y, data_ + sizeof(x), sizeof(y));
				x = asio::detail::socket_ops::network_to_host_long(x);
				y = asio::detail::socket_ops::network_to_host_long(y);
				std::cout << "x = " << x << " | y = " << y << std::endl;
				
			} else {
				do_receive();
			}
		});
	}

	void serverListener(){
		try{
			asio::io_service io_service;

			Server s(io_service, PORT);

			io_service.run();
		}  catch (std::exception& e){
			std::cerr << "Exception: " << e.what() << "\n";
		}
	}
