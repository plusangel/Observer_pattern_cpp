//
// Created by bender on 20/10/2021.
//

#ifndef ARJAN_OBSERVER_PATTERN_API_PLAN_MANAGEMENT_H_
#define ARJAN_OBSERVER_PATTERN_API_PLAN_MANAGEMENT_H_
#include "database.h"
#include "event_system.h"
#include "user.h"

class PlanManagementEventDriven {
 public:
  explicit PlanManagementEventDriven(Database &user_database, EventSystem &event_system)
      : database_{user_database}
      , event_system_{event_system} {}

  void UpgradePlan(std::string_view email) const {
    const auto found_the_user = database_.FindUser(email);
    if (found_the_user.has_value()) {
      User the_user = found_the_user.value();
      the_user.plan_ = "paid";

      event_system_.PostEvent("user_upgrade_plan", the_user);
    }
  }

 private:
  Database &database_;
  EventSystem &event_system_;
};
#endif//ARJAN_OBSERVER_PATTERN_API_PLAN_MANAGEMENT_H_
