// Copyright 2016 Glyn Matthews.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef NETWORK_DETAIL_URI_GRAMMAR_INC
#define NETWORK_DETAIL_URI_GRAMMAR_INC

#include <string_view>
#include <cstdlib>
#include <locale>
#include <cstring>
#include <string>

namespace network {
namespace detail {
inline bool isalnum(std::string_view::const_iterator &it,
                    std::string_view::const_iterator last) {
  if (it != last) {
    if (std::isalnum(*it, std::locale("C"))) {
      ++it;
      return true;
    }
  }
  return false;
}

inline bool isdigit(std::string_view::const_iterator &it,
                    std::string_view::const_iterator last) {
  if (it != last) {
    if (std::isdigit(*it, std::locale("C"))) {
      ++it;
      return true;
    }
  }
  return false;
}

inline bool is_in(std::string_view::const_iterator &it,
                  std::string_view::const_iterator last, const char *chars) {
  if (it != last) {
    auto length = std::strlen(chars);
    for (std::size_t i = 0; i < length; ++i) {
      if (*it == chars[i]) {
        ++it;
        return true;
      }
    }
  }
  return false;
}

inline bool is_sub_delim(std::string_view::const_iterator &it,
                         std::string_view::const_iterator last) {
  return is_in(it, last, "!$&'()*+,;=");
}

inline bool is_ucschar(std::string_view::const_iterator &it,
                       std::string_view::const_iterator last) {
  if (it == last) {
    return false;
  }



  return false;
}

inline bool is_private(std::string_view::const_iterator &it,
                       std::string_view::const_iterator last) {
  return false;
}

inline bool is_unreserved(std::string_view::const_iterator &it,
                          std::string_view::const_iterator last) {
  return isalnum(it, last) || is_in(it, last, "-._~");
}

inline bool is_pct_encoded(std::string_view::const_iterator &it,
                           std::string_view::const_iterator last) {
  if (it == last) {
    return false;
  }

  std::string_view::const_iterator it_copy = it;

  if (*it_copy == '%') {
    ++it_copy;
    if (it_copy == last) {
      return false;
    }
  }

  if (std::isxdigit(*it_copy, std::locale("C"))) {
    ++it_copy;
    if (it_copy == last) {
      return false;
    }
  }

  if (std::isxdigit(*it_copy, std::locale("C"))) {
    ++it_copy;
    it = it_copy;
    return true;
  }

  return false;
}

inline bool is_pchar(std::string_view::const_iterator &it,
                     std::string_view::const_iterator last) {
  return
    is_unreserved(it, last) ||
    is_pct_encoded(it, last) ||
    is_sub_delim(it, last) ||
    is_in(it, last, ":@") ||
    is_ucschar(it, last)
    ;
}

inline bool is_valid_port(std::string_view::const_iterator it) {
  const char* port_first = &(*it);
  char* port_last = 0;
  unsigned long value = std::strtoul(port_first, &port_last, 10);
  return (value < std::numeric_limits<unsigned short>::max());
}
}  // namespace detail
}  // namespace network

#endif  // NETWORK_DETAIL_URI_GRAMMAR_INC
