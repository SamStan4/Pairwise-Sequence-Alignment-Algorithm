#ifndef __DP_CELL_HPP__
#define __DP_CELL_HPP__

#include <cstdint>
#include <algorithm>
#include <stdexcept>

extern const int64_t match_score;
extern const int64_t mismatch_score;
extern const int64_t opening_gap_score;
extern const int64_t gap_extension_score;

class dp_cell {
private:
  int64_t m_s_score;
  int64_t m_d_score;
  int64_t m_i_score;

  int32_t m_s_matches;
  int32_t m_d_matches;
  int32_t m_i_matches;

  void score_s(const dp_cell& cell_s);
  void score_d(const dp_cell& cell_d);
  void score_i(const dp_cell& cell_i);
public:
  dp_cell();
  ~dp_cell();
  int64_t get_max_score(void) const;
  int32_t get_max_score_matches(void) const;
  void score_cell(const dp_cell&, const dp_cell&, const dp_cell&);
  void reset_cell(void);

  int64_t get_s_score(void) const;
  int64_t get_d_score(void) const;
  int64_t get_i_score(void) const;

  int32_t get_s_matches(void) const;
  int32_t get_d_matches(void) const;
  int32_t get_i_matches(void) const;

  void set_s_score(int64_t _s_score);
  void set_d_score(int64_t _d_score);
  void set_i_score(int64_t _i_score);

  void set_s_matches(int32_t _s_matches);
  void set_d_matches(int32_t _d_matches);
  void set_i_matches(int32_t _i_matches);
};

#endif