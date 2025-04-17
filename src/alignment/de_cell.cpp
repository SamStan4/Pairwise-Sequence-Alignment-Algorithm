#include "./dp_cell.hpp"

// MARK: public methods

dp_cell::dp_cell() :
  m_s_score(0),
  m_d_score(0),
  m_i_score(0),
  m_s_matches(0),
  m_d_matches(0),
  m_i_matches(0) {
}

int64_t dp_cell::get_max_score(void) {
  return std::max(this->m_s_score, std::max(this->m_d_score, this->m_i_score));
}

int32_t dp_cell::get_max_score_matches(void) {
  const int64_t max_score = std::max(this->m_s_score, std::max(this->m_d_score, this->m_i_score));
  if (max_score == this->m_s_score) {
    return this->m_s_matches;
  } else if (max_score == this->m_d_score) {
    return this->m_d_matches;
  }
  return this->m_i_matches;
}

void dp_cell::score_cell(const dp_cell& cell_s, const dp_cell& cell_d, const dp_cell& cell_i) {
  throw std::runtime_error("not implemented");
}

void dp_cell::reset_cell(void) {
  this->m_s_score = 0;
  this->m_d_score = 0;
  this->m_i_score = 0;
  this->m_s_matches = 0;
  this->m_d_matches = 0;
  this->m_i_matches = 0;
}

// MARK: getters

int64_t dp_cell::get_s_score(void) const {
  return this->m_s_score;
}

int64_t dp_cell::get_d_score(void) const {
  return this->m_d_score;
}

int64_t dp_cell::get_i_score(void) const {
  return this->m_i_score;
}

int32_t dp_cell::get_s_matches(void) const {
  return this->m_s_matches;
}

int32_t dp_cell::get_d_matches(void) const {
  return this->m_d_matches;
}

int32_t dp_cell::get_i_matches(void) const {
  return this->m_i_matches;
}

// MARK: setters

void dp_cell::set_s_score(int64_t _s_score) {
  this->m_s_score = _s_score;
}

void dp_cell::set_d_score(int64_t _d_score) {
  this->m_d_score = _d_score;
}

void dp_cell::set_i_score(int64_t _i_score) {
  this->m_i_score = _i_score;
}

void dp_cell::set_s_matches(int32_t _s_matches) {
  this->m_s_matches = _s_matches;
}

void dp_cell::set_d_matches(int32_t _d_matches) {
  this->m_d_matches = _d_matches;
}

void dp_cell::set_i_matches(int32_t _i_matches) {
  this->m_i_matches = _i_matches;
}