#include "../include/handler.h"

handler::handler(utility::string_t url) : listener(url) {
    listener.support(methods::GET, std::bind(&handler::handle_get, this, std::placeholders::_1));
    listener.support(methods::POST, std::bind(&handler::handle_post, this, std::placeholders::_1));
    listener.support(methods::DEL, std::bind(&handler::handle_delete, this, std::placeholders::_1));
}

void handler::handle_get(http_request message) {
    ucout << message.to_string() << endl;
    message.reply(status_codes::OK, message.to_string());
};

void handler::handle_post(http_request message) {
    ucout << message.to_string() << endl;
    message.reply(status_codes::OK, message.to_string());
};

void handler::handle_delete(http_request message) {
    ucout << message.to_string() << endl;
    string rep = U("WRITE YOUR OWN DELETE OPERATION");
    message.reply(status_codes::OK, rep);
};
