#include "event.h"
#include "user.h"
#include <iostream>

int main() {
  Event events_system{};
  events_system.Subscribe("hola", [](User a_user) { std::cout << "Hello, " << a_user.name_ << "!" << std::endl; });
  events_system.ListSubscribers();
  User b_user{"angelos", "1234", "angelos@in.gr"};
  events_system.PostEvent("hola", b_user);

  return 0;
}
