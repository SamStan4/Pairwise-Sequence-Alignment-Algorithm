#include "./program_wrapper.hpp"

// MARK: private methods

program_wrapper::program_wrapper() {
}

// MARK: public methods

program_wrapper& program_wrapper::get_instance(void) {
  static program_wrapper instance;
  return instance;
}

void program_wrapper::run_program(const int arg_count, const char* const* arg_vector) {
  std::cout << "here" << std::endl;
}