//
// Created by bender on 18/10/2021.
//

#ifndef ARJAN_OBSERVER_PATTERN_LIB_USER_H_
#define ARJAN_OBSERVER_PATTERN_LIB_USER_H_
#include <iostream>
#include <string>

class User {
 public:
  User(std::string_view name, std::string_view password, std::string_view email)
      : name_{name}
      , password_{password}
      , email_{email}
      , plan_{"basic"} {}

  void ResetPassword(std::string_view code, std::string_view new_password) {
    if (code == reset_code_) {
      password_ = new_password;
    } else {
      std::cout << "Invalid password reset code." << std::endl;
    }
  }

  void PrintUser() const {
    std::cout << "[" << name_ << ", " << email_ << "]" << std::endl;
  }

  std::string name_;
  std::string password_;
  std::string email_;
  std::string plan_{"basic"};
  std::string reset_code_;
};
#endif//ARJAN_OBSERVER_PATTERN_LIB_USER_H_
