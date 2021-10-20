#include "database.h"
#include "plan_management.h"
#include "user_management.h"

int main() {
  Database users_db{};
  UserManagement plain_user_system{users_db};
  PlanManagement plain_plan_system{users_db};

  plain_user_system.RegisterNewUser("angelos", "1234", "angelos@in.gr");
  plain_user_system.PasswordForgotten("angelos@in.gr");
  plain_plan_system.UpgradePlan("angelos@in.gr");

  return 0;
}
