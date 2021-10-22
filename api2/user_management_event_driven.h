//
// Created by bender on 19/10/2021.
//

#ifndef ARJAN_OBSERVER_PATTERN_API_USER_MANAGEMENT_H_
#define ARJAN_OBSERVER_PATTERN_API_USER_MANAGEMENT_H_
#include "database.h"
#include "event_system.h"
#include "user.h"

class UserManagementEventDriven {
 public:
  explicit UserManagementEventDriven(Database &user_database, EventSystem &event_system)
      : database_{user_database}, event_system_{event_system} {}

  void RegisterNewUser(std::string_view name, std::string_view password, std::string_view email) {
    User a_user = database_.Create_User(name, password, email);

    event_system_.PostEvent("user_registered", a_user);
  }

  void PasswordForgotten(std::string_view email) const {
    const auto found_the_user = database_.FindUser(email);
    if (found_the_user.has_value()) {
      User the_user = found_the_user.value();
      the_user.reset_code_ = "11111";

      event_system_.PostEvent("user_password_forgotten", the_user);
    }
  }

 private:
  Database &database_;
  EventSystem &event_system_;
};
#endif//ARJAN_OBSERVER_PATTERN_API_USER_MANAGEMENT_H_
