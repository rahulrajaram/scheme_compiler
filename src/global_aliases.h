#ifndef GLOBAL_ALIASES_H
#define GLOBAL_ALIASES_H

#include <iostream>
#include <fstream>

using IfStream = std::ifstream;
using CIfStream = const std::ifstream;
using SpdlogLogger = std::shared_ptr<spdlog::logger>;
#endif
