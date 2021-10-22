//
// Created by bender on 21/10/2021.
//

#ifndef ARJAN_OBSERVER_PATTERN_API2_EVENT_SYSTEM_H_
#define ARJAN_OBSERVER_PATTERN_API2_EVENT_SYSTEM_H_
#include "spdlog/spdlog.h"
#include "user.h"
#include <functional>
#include <map>
#include <string>
#include <vector>

class EventSystem {
 public:
  void Subscribe(std::string_view event_type, const std::function<void(const User &)> &function) {
    subscribers_[event_type.data()].push_back(function);
  }

  void PostEvent(std::string_view event_type, const User &a_user) {
    for (const auto &fn : subscribers_[event_type.data()]) {
      fn(a_user);
    }
  }

  [[maybe_unused]] void ListSubscribers() {
    for (const auto &[event, fun] : subscribers_)
      spdlog::info("EventSystem type: " + event + " subscribers " + std::to_string(subscribers_[event].size()));
  }

 private:
  std::map<std::string, std::vector<std::function<void(const User &)>>> subscribers_;
};
#endif//ARJAN_OBSERVER_PATTERN_API2_EVENT_SYSTEM_H_
