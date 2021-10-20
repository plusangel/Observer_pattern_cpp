//
// Created by bender on 20/10/2021.
//

#ifndef ARJAN_OBSERVER_PATTERN_API_PLAN_MANAGEMENT_H_
#define ARJAN_OBSERVER_PATTERN_API_PLAN_MANAGEMENT_H_
#include "database.h"
#include "email.h"
#include "log.h"
#include "slack.h"
#include "user.h"

class PlanManagement {
 public:
  explicit PlanManagement(Database &user_database)
      : database_{user_database} {}

  void UpgradePlan(std::string_view email) const {
    const auto found_the_user = database_.FindUser(email);
    if (found_the_user.has_value()) {
      User the_user = found_the_user.value();
      the_user.plan_ = "paid";
      PostSlackMessage("sales", the_user.name_ + " has upgraded their plan.");
      SendEmail(the_user.name_, the_user.email_, "Thank you", "Thanks for upgrading, You're gonna love it.");
      Log("User with email address " + the_user.email_ + " has upgraded their plan");
    }
  }

 private:
  Database &database_;
};
#endif//ARJAN_OBSERVER_PATTERN_API_PLAN_MANAGEMENT_H_
