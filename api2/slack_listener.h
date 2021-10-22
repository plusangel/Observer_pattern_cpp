//
// Created by bender on 22/10/2021.
//

#ifndef ARJAN_OBSERVER_PATTERN_API2_SLACK_LISTENER_H_
#define ARJAN_OBSERVER_PATTERN_API2_SLACK_LISTENER_H_
#include "event_system.h"
#include "slack.h"

void HandleUserRegisteredEvent(const User &user) {
  PostSlackMessage("sales", user.name_ + " has registered with email address " + user.email_);
}

void HandleUserPasswordForgottenEvent(const User &user) {
  PostSlackMessage("sales", user.name_ + " has upgraded their plan.");
}

void HandleUserUpgradePlanEvent(const User &user) {
  PostSlackMessage("sales", user.name_ + " has forgotten their password.");
}

void SetupSlackEventHandlers(EventSystem &events_system) {
  events_system.Subscribe("user_registered", HandleUserRegisteredEvent);
  events_system.Subscribe("user_password_forgotten", HandleUserPasswordForgottenEvent);
  events_system.Subscribe("user_upgrade_plan", HandleUserUpgradePlanEvent);
}

#endif//ARJAN_OBSERVER_PATTERN_API2_SLACK_LISTENER_H_
