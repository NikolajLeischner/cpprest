#ifndef GCC_HANDLER_H
#define GCC_HANDLER_H

#include <iostream>
#include "stdafx.h"

using namespace std;
using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;


class handler {
public:
    handler() = default;

    explicit handler(utility::string_t url);

    virtual ~handler() = default;

    pplx::task<void> open() { return listener.open(); }

    pplx::task<void> close() { return listener.close(); }

protected:

private:
    void handle_get(http_request message);

    void handle_post(http_request message);

    void handle_delete(http_request message);

    http_listener listener;
};

#endif //GCC_HANDLER_H
