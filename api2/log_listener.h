//
// Created by bender on 22/10/2021.
//

#ifndef ARJAN_OBSERVER_PATTERN_API2_LOG_LISTENER_H_
#define ARJAN_OBSERVER_PATTERN_API2_LOG_LISTENER_H_
#include "event_system.h"
#include "log.h"

void HandleUserRegisteredEventLog(const User &user) {
  Log("User has registered with email address " + user.email_);
}

void HandleUserPasswordForgottenEventLog(const User &user) {
  Log("User with email address " + user.email_ + " requested a password reset.");
}

void HandleUserUpgradePlanEventLog(const User &user) {
  Log("User with email address " + user.email_ + " has upgraded their plan");
}

void SetupLogEventHandlers(EventSystem &events_system) {
  events_system.Subscribe("user_registered", HandleUserRegisteredEventLog);
  events_system.Subscribe("user_password_forgotten", HandleUserPasswordForgottenEventLog);
  events_system.Subscribe("user_upgrade_plan", HandleUserUpgradePlanEventLog);
}
#endif//ARJAN_OBSERVER_PATTERN_API2_LOG_LISTENER_H_
