//
// Created by bender on 19/10/2021.
//

#ifndef ARJAN_OBSERVER_PATTERN_API_USER_MANAGEMENT_H_
#define ARJAN_OBSERVER_PATTERN_API_USER_MANAGEMENT_H_
#include "database.h"
#include "email.h"
#include "log.h"
#include "slack.h"
#include "user.h"

class UserManagement {
 public:
  explicit UserManagement(Database &user_database)
      : database_{user_database} {}

  void RegisterNewUser(std::string_view name, std::string_view password, std::string_view email) {
    User a_user = database_.Create_User(name, password, email);

    PostSlackMessage("sales", name.data() + std::string(" has registered with email ") + email.data());
    Log(std::string("User registered with email address ") + email.data());
    SendEmail(a_user.name_, a_user.email_, "Welcome", "Thanks for registering, " + a_user.name_);
  }

  void PasswordForgotten(std::string_view email) const {
    const auto found_the_user = database_.FindUser(email);
    if (found_the_user.has_value()) {
      User the_user = found_the_user.value();
      the_user.reset_code_ = "11111";

      SendEmail(the_user.name_, the_user.email_, "Reset your password", "To reset your password, use this very secure code:" + the_user.reset_code_);
      Log("User with email address " + the_user.email_ + " requested a password reset");
    }
  }

 private:
  Database &database_;
};
#endif//ARJAN_OBSERVER_PATTERN_API_USER_MANAGEMENT_H_
