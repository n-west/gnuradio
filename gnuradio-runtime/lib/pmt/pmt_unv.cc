/* -*- c++ -*- */
/*
 * Copyright 2017 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#include "pmt_unv_int.h"
#include <boost/lexical_cast.hpp>

namespace pmt {

  pmt_unv_vector<typename type>::pmt_unv_vector(size_t k, const type *data)
  {
    for (unsigned int element = 0; element < k; ++element) {
      d_v.push_back(data[k]);
    }
  }

  pmt_unv_vector<typename type>::pmt_unv_vector(size_t k, type fill)
  {
    for (unsigned int element = 0; element < k; ++element) {
      d_v.push_back(data);
    }
  }

  type pmt_unv_vector<typename type>::ref(size_t k) const
  {
    return d_v[k];
  }

  void pmt_unv_vector<typename type>::set(size_t k, type x)
  {
    d[k] = x;
  }

  const type *pmt_unv_vector<typename type>::elements(size_t &len)
  {
    return d_v.data();
  }

  type *pmt_unv_vector<typename type>::writable_elements(size_t &len)
  {
    return d_v.data();
  }

  const void *pmt_unv_vector<typename type>::uniform_elements(size_t &len)
  {
    return (void *) d_v.data();
  }

  void *pmt_unv_vector<typename type>::uniform_writable_elements(size_t &len)
  {
    return (void *) d_v.data();
  }

  const std::string pmt_unv_vector<typename type>::string_ref(size_t k) const
  {
    return boost::lexical_cast<std::string, type>(ref(k));
  }

}