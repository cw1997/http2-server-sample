add_executable(${PROJECT_NAME} main.h main.cpp)

#target_link_libraries(main nghttp2_asio boost_system ssl crypto)
#target_compile_options(main PUBLIC "-lnghttp2_asio -lboost_system -lssl -lcrypto")

target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE Threads::Threads
        PRIVATE Boost::system
        PRIVATE Boost::thread
        PRIVATE Boost::log
        PRIVATE OpenSSL::Crypto
)

target_link_libraries(${PROJECT_NAME} PUBLIC nghttp2_asio)
