//
// Created by bender on 21/10/2021.
//

#ifndef ARJAN_OBSERVER_PATTERN_API2_EVENT_H_
#define ARJAN_OBSERVER_PATTERN_API2_EVENT_H_
#include "user.h"
#include <functional>
#include <map>
#include <string>
#include <vector>

class Event {
 public:
  void Subscribe(std::string_view event_type, std::function<void(User)> function) {
    subscribers_[event_type.data()].push_back(function);
  }

  std::function<void(User)> PostEvent(std::string_view event_type, User a_user) {
    for (auto fn : subscribers_[event_type.data()]) {
      fn(a_user);
    }
  }

  void ListSubscribers() {
    for (const auto &[event, fun] : subscribers_)
      std::cout << "Event type: " << event << " subscribers " << subscribers_[event].size() << std::endl;
  }

 private:
  std::map<std::string, std::vector<std::function<void(User)>>> subscribers_;
};
#endif//ARJAN_OBSERVER_PATTERN_API2_EVENT_H_
