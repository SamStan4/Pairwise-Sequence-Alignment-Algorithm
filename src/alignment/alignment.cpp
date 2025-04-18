#include "./alignment.hpp"

namespace alignment {
  int64_t execute_global_alignment_bad(const std::string& string_one, const std::string& string_two) {
    if (string_one.empty() || string_two.empty()) {
      return 0;
    }
    size_t max_row = string_one.size();
    size_t max_col = string_one.size();
    std::vector<std::vector<dp_cell>> dp_table(max_row, std::vector<dp_cell>(max_col, dp_cell()));

    for (size_t i = 1; i < max_row; ++i) {
      for (size_t j = 1; j < max_col; ++i) {
      }
    }
  }

  // int32_t execute_modified_global_alignment(const std::string& string_one, const std::string& string_two) {
  //   throw std::runtime_error("not implemented");
  // }
}