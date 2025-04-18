#ifndef __DP_CELL_HPP__
#define __DP_CELL_HPP__

#include <cstdint>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <fstream>
#include <string>
#include <sstream>

extern const int64_t match_score;
extern const int64_t mismatch_score;
extern const int64_t opening_gap_score;
extern const int64_t gap_extension_score;

class dp_cell {
private:
  static constexpr int64_t min_score = static_cast<int64_t>(std::numeric_limits<int32_t>::min());

  int64_t m_i_score;
  int64_t m_s_score;
  int64_t m_d_score;

  int32_t m_i_matches;
  int32_t m_s_matches;
  int32_t m_d_matches;
public:
  dp_cell();
  ~dp_cell();
  int64_t get_max_score(void) const;

  int64_t get_i_score(void) const;
  int64_t get_s_score(void) const;
  int64_t get_d_score(void) const;

  void set_i_score(const int64_t);
  void set_i_score(const int64_t);
  void set_i_score(const int64_t);
};

#endif