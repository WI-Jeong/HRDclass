#pragma once
#include "EngineMinimal.h"

// boost
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>

using boost::asio::ip::tcp;
using FSocket = boost::asio::ip::tcp::socket;