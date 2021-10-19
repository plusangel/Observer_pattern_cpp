//
// Created by bender on 19/10/2021.
//

#ifndef ARJAN_OBSERVER_PATTERN_API_USER_MANAGEMENT_H_
#define ARJAN_OBSERVER_PATTERN_API_USER_MANAGEMENT_H_
#include "database.h"
#include "user.h"
#include "slack.h"
#include "log.h"
#include "email.h"

class UserManagement {
 public:
  explicit UserManagement(Database &user_database) : database_{user_database} {}

  void RegisterNewUser(std::string_view name, std::string_view password, std::string_view email) {
    User a_user = database_.Create_User(name, password, email);

    PostSlackMessage("sales", name.data() + std::string(" has registered with email ") + email.data());
    Log(std::string("User registered with email address ") + email.data());
  }

 private:
  Database& database_;
};
#endif//ARJAN_OBSERVER_PATTERN_API_USER_MANAGEMENT_H_
