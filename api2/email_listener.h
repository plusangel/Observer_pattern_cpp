//
// Created by bender on 22/10/2021.
//

#ifndef ARJAN_OBSERVER_PATTERN_API2_EMAIL_LISTENER_H_
#define ARJAN_OBSERVER_PATTERN_API2_EMAIL_LISTENER_H_
#include "email.h"
#include "event_system.h"

void HandleUserRegisteredEventEmail(const User &user) {
  SendEmail(user.name_, user.email_, "Welcome",
            "Thanks for registering, " + user.name_ + "!");
}

void HandleUserPasswordForgottenEventEmail(const User &user) {
  SendEmail(user.name_, user.email_, "Reset your password",
            "To reset your password, use this very secure code: " + user.reset_code_ + ".");
}

void HandleUserUpgradePlanEventEmail(const User &user) {
  SendEmail(user.name_, user.email_, "Thank you",
            "Thanks for upgrading, " + user.name_ + "! You're gonna love it.");
}

void SetupEmailEventHandlers(EventSystem &events_system) {
  events_system.Subscribe("user_registered", HandleUserRegisteredEventEmail);
  events_system.Subscribe("user_password_forgotten", HandleUserPasswordForgottenEventEmail);
  events_system.Subscribe("user_upgrade_plan", HandleUserUpgradePlanEventEmail);
}

#endif//ARJAN_OBSERVER_PATTERN_API2_EMAIL_LISTENER_H_
