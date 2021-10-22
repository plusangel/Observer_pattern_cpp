#include "email_listener.h"
#include "event_system.h"
#include "log_listener.h"
#include "slack_listener.h"
#include "user_management_event_driven.h"

int main() {
  EventSystem events_system{};
  SetupSlackEventHandlers(events_system);
  SetupEmailEventHandlers(events_system);
  SetupLogEventHandlers(events_system);

  Database users_db{};
  UserManagementEventDriven users_management_system{users_db, events_system};

  users_management_system.RegisterNewUser("angelos", "1234", "angelos@in.gr");
  users_management_system.PasswordForgotten("angelos@in.gr");

  return 0;
}
