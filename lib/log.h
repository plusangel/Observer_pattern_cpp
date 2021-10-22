//
// Created by bender on 18/10/2021.
//

#ifndef ARJAN_OBSERVER_PATTERN_LIB_LOG_H_
#define ARJAN_OBSERVER_PATTERN_LIB_LOG_H_
#include "spdlog/spdlog.h"

void Log(std::string_view message) {
  spdlog::info(std::string("[Log]: ") + message.data());
  //std::cout << time_str << " - " << message << std::endl;
}
#endif//ARJAN_OBSERVER_PATTERN_LIB_LOG_H_
