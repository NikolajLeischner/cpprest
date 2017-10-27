#include <iostream>
#include <csignal>
#include <thread>

#include "include/stdafx.h"
#include "include/handler.h"

using namespace std;
using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;


std::unique_ptr<handler> httpHandler;

void start(const string_t &address) {
    uri_builder uri(address);
    auto addr = uri.to_uri().to_string();
    httpHandler = std::unique_ptr<handler>(new handler(addr));
    httpHandler->open().wait();
    ucout << utility::string_t(U("Listening for requests at: ")) << addr << std::endl;
}

void on_shutdown(int signal) {
    try {
        httpHandler->close().wait();
    } catch(...) { }
    std::_Exit(0);
}

int main(int argc, char *argv[]) {
    utility::string_t port = U("8080");
    if (argc == 2) {
        port = argv[1];
    }

    utility::string_t address = U("http://0.0.0.0:");

    address.append(port);
    start(address);
    std::signal(SIGTERM, on_shutdown);
    std::signal(SIGKILL, on_shutdown);
    while(true);
}