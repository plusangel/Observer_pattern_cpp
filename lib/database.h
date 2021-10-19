//
// Created by bender on 18/10/2021.
//

#ifndef ARJAN_OBSERVER_PATTERN_LIB_DATABASE_H_
#define ARJAN_OBSERVER_PATTERN_LIB_DATABASE_H_
#include <optional>
#include <vector>
#include "user.h"

class Database {
 public:
  Database() = default;

  User Create_User(std::string_view name, std::string_view pasword, std::string_view email) {
    User new_user{name, pasword, email};
    users_.push_back(new_user);
    return new_user;
  }

  [[nodiscard]] std::optional<User> FindUser(const std::string &email) const {
    for (auto user : users_) {
      if (user.email_ == email)
        return user;
    }
    return std::nullopt;
  }

  std::vector<User> users_;
};

#endif//ARJAN_OBSERVER_PATTERN_LIB_DATABASE_H_
