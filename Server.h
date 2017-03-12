#include <cstdlib>
#include <iostream>
#include <asio.hpp>

#define PORT 999

using asio::ip::udp;

class Server{
		private:
	udp::socket socket_;
	udp::endpoint sender_endpoint_;
	enum { max_length = 8 };
	char data_[max_length];
	
		public:
	Server(asio::io_service& io_service, short port);
	void do_receive();
	void do_send(std::size_t length);
};

	void serverListener();

