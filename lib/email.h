//
// Created by bender on 19/10/2021.
//

#ifndef ARJAN_OBSERVER_PATTERN_LIB_EMAIL_H_
#define ARJAN_OBSERVER_PATTERN_LIB_EMAIL_H_
#include <iostream>
#include <string>

void SendEmail(std::string_view name, std::string_view address, std::string_view subject, std::string_view body)  {
  std::cout << "Sending email to " << name << " (" << address << ")" << std::endl;
  std::cout << "-----" << std::endl;
  std::cout << "Subject: " << subject << std::endl;
  std::cout << body << std::endl;
}
#endif//ARJAN_OBSERVER_PATTERN_LIB_EMAIL_H_
