/* -*- c++ -*- */
/*
 * Copyright 2022 Peter Fetterer (KB3GTN).
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_KB3GTN_WIN_MIN_MAX_IMPL_H
#define INCLUDED_KB3GTN_WIN_MIN_MAX_IMPL_H

#include <gnuradio/kb3gtn/win_min_max.h>

namespace gr {
  namespace kb3gtn {

    class win_min_max_impl : public win_min_max
    {
      private:
        int win_size;

      public:
        win_min_max_impl(int win_size);
        ~win_min_max_impl();

        // Where all the action really happens
        int work(
              int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items
        );
    };

  } // namespace kb3gtn
} // namespace gr

#endif /* INCLUDED_KB3GTN_WIN_MIN_MAX_IMPL_H */
