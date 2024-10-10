#include <iostream>
#include <string>
#include <cstdlib>


int compute_checksum(const std::string& input_string) {
    int checksum = 0;
    for (char ch : input_string) {
        checksum += ch;
    }
    return checksum;
}

int main(int argument_count, char *arguments[]) {
    
  bool has_required_arguments = (argument_count == 3);

  if (has_required_arguments) {
    std::string program_name{arguments[0]}; 
    char first_char_of_argument{*(arguments[1])};
    std::size_t program_name_length{program_name.size()};
    int provided_checksum{std::atoi(arguments[2])};

    std::string input_string{arguments[1]};

   
    int calculated_value = compute_checksum(input_string);

    
    if ((calculated_value ^ first_char_of_argument * 3) << (program_name_length & 0x1f) == provided_checksum) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
}


