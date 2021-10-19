//
// Created by bender on 18/10/2021.
//

#ifndef ARJAN_OBSERVER_PATTERN_LIB_LOG_H_
#define ARJAN_OBSERVER_PATTERN_LIB_LOG_H_
#include <chrono>
#include <iostream>
#include <string>
#include <iomanip>

void Log(std::string_view message) {
  std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
  time_t now_time = std::chrono::system_clock::to_time_t(now);
  std::string time_str = std::ctime(&now_time);
  time_str.resize(time_str.size() - 1);

   std::cout << time_str << " - " << message << std::endl;
}
#endif//ARJAN_OBSERVER_PATTERN_LIB_LOG_H_
