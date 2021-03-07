#include <iostream>

#include <absl/strings/str_format.h>

int main(int argc, char **argv) {
  constexpr absl::string_view kFormatString = "Welcome to %s, Number %d!";
  std::string s = absl::StrFormat(kFormatString, "The Village", 6);
  std::cout << s << std::endl;
  return 0;
}
