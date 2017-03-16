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

#ifndef PMT_UNV_INT_H
#define PMT_UNV_INT_H

#include "pmt_int.h"
#include <stdint.h>

namespace pmt {

  template<typename type>
  class pmt_unv_vector : public pmt_uniform_vector
  {
  private:
    std::vector <type> d_v;

  public:
    pmt_unv_vector(size_t k, type fill);
    pmt_unv_vector(size_t k, const type *data);

    bool is_unv_vector() const
    { return true; }

    size_t length() const
    { return d_v.size(); }

    size_t itemsize() const
    { return sizeof(type); }

    type ref(size_t k) const;
    void set(size_t k, type x);

    const type *elements(size_t &len);
    type *writable_elements(size_t &len);

    const void *uniform_elements(size_t &len);
    void *uniform_writable_elements(size_t &len);

    virtual const std::string string_ref(size_t k) const;
  };

  typedef pmt_unv_vector<uint8_t> pmt_u8vector;
  typedef pmt_unv_vector<int8_t> pmt_s8vector;
  typedef pmt_unv_vector<uint16_t> pmt_u16vector;
  typedef pmt_unv_vector<int16_t> pmt_s16vector;
  typedef pmt_unv_vector<uint32_t> pmt_u32vector;
  typedef pmt_unv_vector<int32_t> pmt_s32vector;
  typedef pmt_unv_vector<float> pmt_f32vector;
  typedef pmt_unv_vector<double> pmt_f64vector;
  typedef pmt_unv_vector<std::complex < float> >
  pmt_c32vector;
  typedef pmt_unv_vector<std::complex < double> >
  pmt_c64vector;

}
#endif