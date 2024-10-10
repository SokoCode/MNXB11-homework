#include <iostream>
#include <string>

int main(int argument_count, char *arguments[]) {
    
  bool has_required_arguments = (argument_count == 3);

  if (has_required_arguments) {
    std::string program_name{arguments[0]};
    char first_char_of_argument{*(arguments[1])};
    std::size_t program_name_length{program_name.size()};
    int provided_checksum{std::atoi(arguments[2])};

    int calculated_value{0};
    std::string input_string{arguments[1]};
    int index{0};

    while (true) {
      calculated_value += input_string[index++];
      if (index >= static_cast<int>(input_string.size())) {
        break;
      }
    }

    if ((calculated_value ^ first_char_of_argument * 3) << (program_name_length & 0x1f) == provided_checksum) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
}

