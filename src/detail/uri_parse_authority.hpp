// Copyright 2013-2016 Glyn Matthews.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef NETWORK_DETAIL_URI_PARSE_AUTHORITY_INC
#define NETWORK_DETAIL_URI_PARSE_AUTHORITY_INC

#include <network/uri/detail/uri_parts.hpp>

namespace network {
namespace detail {
bool parse_authority(std::string_view::const_iterator &first,
                     std::string_view::const_iterator last,
                     std::optional<uri_part> &user_info,
                     std::optional<uri_part> &host,
                     std::optional<uri_part> &port);
}  // namespace detail
}  // namespace network

#endif // NETWORK_DETAIL_URI_PARSE_AUTHORITY_INC
