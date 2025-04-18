#include "./dp_cell.hpp"

// MARK: scores

const int64_t match_score = 1;
const int64_t mismatch_score = -2;
const int64_t opening_gap_score = -5;
const int64_t gap_extension_score = -2;

dp_cell::dp_cell() :
  m_i_score(0),
  m_s_score(0),
  m_d_score(0),
  m_i_matches(0),
  m_s_matches(0),
  m_d_matches(0) {}

dp_cell::~dp_cell() {}

int64_t dp_cell::get_max_score(void) const {
  return std::max(this->m_i_score, std::max(this->m_s_score, this->m_d_score));
}

// MARK: getters

int64_t dp_cell::get_i_score(void) const {
  return this->m_i_score;
}

int64_t dp_cell::get_s_score(void) const {
  return this->m_s_score;
}

int64_t dp_cell::get_d_score(void) const {
  return this->m_d_score;
}

// MARK: setters

void dp_cell::set_i_score(const int64_t _i_score) {
  this->m_i_score = _i_score;
}

void dp_cell::set_i_score(const int64_t _s_score) {
  this->m_s_score = _s_score;
}

void dp_cell::set_i_score(const int64_t _d_score) {
  this->m_d_score = _d_score;
}