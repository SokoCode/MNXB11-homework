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


int calculate_key(int checksum, char first_char, std::size_t program_name_length) {
    return (checksum ^ first_char * 3) << (program_name_length & 0x1f);
}


void print_usage(const std::string& program_name) {
    std::cout << "Usage: " << program_name << " <string> <expected_checksum>" << std::endl;
    std::cout << "Example: " << program_name << " hello 12345" << std::endl;
}


void print_results(int calculated_checksum, int calculated_key, int expected_key) {
    std::cout << "Calculated checksum: " << calculated_checksum << std::endl;
    std::cout << "Calculated key: " << calculated_key << std::endl;
    std::cout << "Expected key (provided checksum): " << expected_key << std::endl;
}

int main(int argument_count, char *arguments[]) {

    
    if (argument_count != 3) {
        print_usage(arguments[0]);
        return 1;
    }

    std::string program_name{arguments[0]};
    std::string input_string{arguments[1]};
    char first_char_of_argument{input_string[0]};
    std::size_t program_name_length{program_name.size()};
    int provided_checksum{std::atoi(arguments[2])};

 
    int calculated_checksum = compute_checksum(input_string);


    int calculated_key = calculate_key(calculated_checksum, first_char_of_argument, program_name_length);


    print_results(calculated_checksum, calculated_key, provided_checksum);


    if (calculated_key == provided_checksum) {
        std::cout << "Correct!" << std::endl;
    } else {
        std::cout << "Wrong!" << std::endl;
    }

    return 0;
}
