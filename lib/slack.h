//
// Created by bender on 18/10/2021.
//

#ifndef ARJAN_OBSERVER_PATTERN_LIB_SLACK_H_
#define ARJAN_OBSERVER_PATTERN_LIB_SLACK_H_
#include "spdlog/spdlog.h"
#include <iostream>
#include <string>

void PostSlackMessage(std::string_view channel, std::string_view message)  {
  spdlog::info("[SlackBot {}]: {}", channel, message);
}

#endif//ARJAN_OBSERVER_PATTERN_LIB_SLACK_H_
