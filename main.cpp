#include <optional>
#include "slack.h"
#include "log.h"
#include "database.h"
#include "user_management.h"

int main() {
//  PostSlackMessage("io_channel", "hello");
//  Log("hello");
  Database users_db{};
  UserManagement plain_system{users_db};
  plain_system.RegisterNewUser("angelos", "1234", "angelos@in.gr");


//  auto a_user = users_db.Create_User("angelos", "1234", "angelos@in.gr");
//  a_user.PrintUser();
//
//  const std::optional<User> another_user = users_db.FindUser("angelo@in.gr");
//  if (another_user)
//    another_user.value().PrintUser();
  return 0;
}
