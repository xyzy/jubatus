// Jubatus: Online machine learning framework for distributed environment
// Copyright (C) 2012 Preferred Infrastructure and Nippon Telegraph and Telephone Corporation.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

#pragma once

#include <vector>
#include <string>
#include <netinet/in.h> // sockaddr_in

#include <pficommon/lang/shared_ptr.h>

namespace jubatus {
namespace common {

class network_address
{
public:
  virtual ~network_address() {}
  virtual bool v4() const = 0;
  virtual bool v6() const = 0;
  virtual bool loopback() const = 0;
  virtual std::string address() const = 0;
  virtual std::string interface() const = 0;
  virtual const sockaddr_in* v4_address() const = 0;
  virtual const sockaddr_in6* v6_address() const = 0;
};

typedef std::vector<pfi::lang::shared_ptr<network_address> > address_list;

address_list get_network_address();

std::string get_default_v4_address(std::string primary_hostaddr = std::string());
// v6 version not implmented yet

} // common
} // jubatus