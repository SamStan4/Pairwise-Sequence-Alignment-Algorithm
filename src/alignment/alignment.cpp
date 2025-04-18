#include "./alignment.hpp"

namespace alignment {
  int64_t execute_global_alignment(const std::string& string_one, const std::string& string_two) {
    const size_t row_size = string_one.size() + 1;
    const size_t col_size = string_two.size() + 1;
    std::vector<dp_cell> cur_dp_row(col_size, dp_cell());
    std::vector<dp_cell> prev_dp_row(col_size, dp_cell());

    // temp
    std::ofstream s("./output.txt");

    // prev_dp_row[0].print_scores(s);
    // s << " ";

    for (size_t i = 1; i < col_size; ++i) {
      prev_dp_row[i].set_top_row(i);
      // prev_dp_row[i].print_scores(s);
      // s << " ";
    }

    for (size_t row_idx = 1; row_idx < row_size; ++row_idx) {
      cur_dp_row[0].set_left_col(row_idx);
      // cur_dp_row[0].print_scores(s);
      // s << " ";
      for (size_t col_idx = 1; col_idx < col_size; ++col_idx) {
        cur_dp_row[col_idx].score_cell(
          prev_dp_row[col_idx-1],
          prev_dp_row[col_idx],
          cur_dp_row[col_idx-1],
          string_one[row_idx-1],
          string_two[col_idx-1]
        );
        cur_dp_row[col_idx].print_scores(s);
        s << " ";
      }
      s << std::endl;
      std::swap(prev_dp_row, cur_dp_row);
    }

    s.close();

    return prev_dp_row.back().get_max_score();
  }

  // int32_t execute_modified_global_alignment(const std::string& string_one, const std::string& string_two) {
  //   throw std::runtime_error("not implemented");
  // }
}