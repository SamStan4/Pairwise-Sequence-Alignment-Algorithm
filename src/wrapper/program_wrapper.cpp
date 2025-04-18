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
  if (arg_count != 2) {
    throw std::runtime_error("error, not enough command line args");
  }
  std::string gene_one;
  std::string gene_two;
  std::string gene_one_name;
  std::string gene_two_name;
  if (!io_utils::load_two_genes(arg_vector[1], gene_one, gene_two, gene_one_name, gene_two_name)) {
    throw std::runtime_error("error, not able to load genes from file");
  }
}