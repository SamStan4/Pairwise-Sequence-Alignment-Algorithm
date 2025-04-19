#ifndef __IO_UTILS_HPP__
#define __IO_UTILS_HPP__

#include <string>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <sstream>

namespace io_utils {
  bool load_one_gene(const char*, std::string&, std::string&);
  bool load_one_gene(const char*, std::string&);
  bool load_two_genes(const char*, std::string&, std::string&, std::string&, std::string&);
  bool load_alphabet(const char*, std::string&);
  bool load_alignment_params(const char*, int64_t&, int64_t&, int64_t&, int64_t&);
}

#endif