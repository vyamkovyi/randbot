#include "libtelegram/libtelegram.h"
#include <iostream>
#include <sstream>
#include <random>

auto main() -> int {
	std::string const token("657444967:AAG_mQRgQxv_fhRJEbMiAHHpOqqSpvuyu4U");
	std::cout << "randbot | Copyright (C) Hexawolf 2019" << std::endl;
	telegram::sender sender(token);
	telegram::listener::poll listener(sender);
	std::random_device urandom("/dev/urandom");
	std::uniform_int_distribution<> distr(1, 20);
	listener.set_callback_message([&](telegram::types::message const &message){
		std::stringstream ss;
		ss << distr(urandom);
		sender.send_message(message.chat.id, ss.str()); 
	});
	listener.run();
	return EXIT_SUCCESS;
};