#include "libtelegram/libtelegram.h"
#include <iostream>
#include <sstream>
#include <random>

auto main() -> int {
	std::string const token(".");
	std::cout << "randbot | Copyright (C) Hexawolf 2019" << std::endl;
	telegram::sender sender(token);
	telegram::listener::poll listener(sender);
	std::random_device urandom("/dev/urandom");
	std::uniform_int_distribution<> distr(1, 20);
	listener.set_callback_message([&](telegram::types::message const &message){
		sender.send_message(message.chat.id, std::to_string(distr(urandom))); 
	});
	listener.run();
	return EXIT_SUCCESS;
};
