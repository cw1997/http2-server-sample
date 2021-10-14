//
// Created by 86759 on 2021/10/8.
//

#include "main.h"

#include <iostream>

#include <nghttp2/asio_http2_server.h>

using namespace nghttp2::asio_http2;
using namespace nghttp2::asio_http2::server;

int main(int argc, char *argv[]) {
    boost::system::error_code ec;

    boost::asio::ssl::context tls(boost::asio::ssl::context::sslv23);

    tls.use_private_key_file("../../server.key", boost::asio::ssl::context::pem);
    tls.use_certificate_chain_file("../../server.crt");

    configure_tls_context_easy(ec, tls);

    http2 server;

    server.handle("/", [](const request &req, const response &res) {
        std::cout << "receive a http2 request" << std::endl;
        res.write_head(200);
        res.end("hello, world\n");
    });

    if (server.listen_and_serve(ec, tls,"localhost", "8001")) {
        std::cerr << "error: " << ec.message() << std::endl;
    }
}
