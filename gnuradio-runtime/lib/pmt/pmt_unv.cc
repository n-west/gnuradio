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
#include <pmt/pmt.h>
#include <boost/lexical_cast.hpp>
#include "pmt_int.h"

namespace pmt {

  template <typename type>
  pmt_unv_vector<type>::pmt_unv_vector(size_t k, const type *data)
  {
    for (unsigned int element = 0; element < k; ++element) {
      d_v.push_back(data[k]);
    }
  }

  template <typename type>
  pmt_unv_vector<type>::pmt_unv_vector(size_t k, type fill)
  {
    for (unsigned int element = 0; element < k; ++element) {
      d_v.push_back(fill);
    }
  }

  template <typename type> type
  pmt_unv_vector<type>::ref(size_t k) const
  {
    return d_v[k];
  }

  template <typename type> void
  pmt_unv_vector<type>::set(size_t k, type x)
  {
    d_v[k] = x;
  }

  template <typename type> const type*
  pmt_unv_vector<type>::elements(size_t &len)
  {
    return d_v.data();
  }

  template <typename type> type*
  pmt_unv_vector<type>::writable_elements(size_t &len)
  {
    return d_v.data();
  }

  template <typename type> const void*
  pmt_unv_vector<type>::uniform_elements(size_t &len)
  {
    return (void *) d_v.data();
  }

  template <typename type> void*
  pmt_unv_vector<type>::uniform_writable_elements(size_t &len)
  {
    return (void *) d_v.data();
  }

  template <typename type> const std::string
  pmt_unv_vector<type>::string_ref(size_t k) const
  {
    return boost::lexical_cast<std::string, type>(ref(k));
  }

  // UNV sugar
  template<typename type> pmt_t
  make_uniform_vector(size_t k, type fill)
  {
    return pmt_t(new pmt_unv_vector(k, fill));
  }

  template<typename type> pmt_t
  make_uniform_vector(size_t k, type* data)
  {
    return pmt_t(new pmt_unv_vector(k, data));
  }

  template<typename type> type
  uniform_vector_ref(pmt_t vector, size_t k)
  {
    vector->ref(k);
  }

  template<typename type> type
  uniform_vector_set(pmt_t vector, size_t k, type x)
  {
    vector->set(k, x);
  }

  template<typename type> bool
  is_u8vector(pmt_t v)
  { return v->is_u8vector(); }

  template<typename type> bool
  is_s8vector(pmt_t v)
  { return v->is_s8vector(); }

  template<typename type> bool
  is_u16vector(pmt_t v)
  { return v->is_u16vector(); }

  template<typename type> bool
  is_s16vector(pmt_t v)
  { return v->is_s16vector(); }

  template<typename type> bool
  is_u32vector(pmt_t v)
  { return v->is_u32vector(); }

  template<typename type> bool
  is_s32vector(pmt_t v)
  { return v->is_s32vector(); }

  template<typename type> bool
  is_f32vector(pmt_t v)
  { return v->is_f32vector(); }

  template<typename type> bool
  is_f64vector(pmt_t v)
  { return v->is_f64vector(); }

  template<typename type> bool
  is_c32vector(pmt_t v)
  { return v->is_c32vector(); }

  template<typename type> bool
  is_c64vector(pmt_t v)
  { return v->is_cf64vector(); }


}