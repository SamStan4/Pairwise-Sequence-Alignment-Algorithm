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
  if (arg_count != 3) {
    throw std::runtime_error("error, not enough command line args");
  }
  std::string gene_one;
  std::string gene_two;
  std::string gene_one_name;
  std::string gene_two_name;
  if (!io_utils::load_two_genes(arg_vector[2], gene_one, gene_two, gene_one_name, gene_two_name)) {
    throw std::runtime_error("error, not able to load genes from file");
  }
  int64_t match_score;
  int64_t mismatch_score;
  int64_t opening_gap_score;
  int64_t gap_extension_score;
  if (!io_utils::load_alignment_params(arg_vector[1], match_score, mismatch_score, opening_gap_score, gap_extension_score)) {
    throw std::runtime_error("error, not able to load alignment parameters from file");
  }
  int64_t result1 = alignment::execute_global_alignment(
    gene_one,
    gene_two,
    match_score,
    mismatch_score,
    opening_gap_score,
    gap_extension_score
  );
  int32_t result2 = alignment::execute_modified_global_alignment(
    gene_one,
    gene_two,
    match_score,
    mismatch_score,
    opening_gap_score,
    gap_extension_score
  );
  std::cout << result1 << std::endl;
  std::cout << result2 << std::endl;
}