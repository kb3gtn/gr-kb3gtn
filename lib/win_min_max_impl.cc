/* -*- c++ -*- */
/*
 * Copyright 2022 Peter Fetterer (KB3GTN).
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <gnuradio/io_signature.h>
#include "win_min_max_impl.h"

namespace gr {
  namespace kb3gtn {

    //#pragma message("set the following appropriately and remove this warning")
    using input_type = float;
    //#pragma message("set the following appropriately and remove this warning")
    using output_type = float;
    win_min_max::sptr
    win_min_max::make(int win_size)
    {
      return gnuradio::make_block_sptr<win_min_max_impl>(
        win_size);
    }


    /*
     * The private constructor
     */
    win_min_max_impl::win_min_max_impl(int win_size)
      : gr::sync_decimator("win_min_max",
              gr::io_signature::make(1 /* min inputs */, 1 /* max inputs */, sizeof(input_type)),
              gr::io_signature::make(1 /* min outputs */, 2 /*max outputs */, sizeof(output_type)), win_size /*<+decimation+>*/),
              win_size(win_size)
    {
        std::vector<int> forecast_inputs = { win_size };
        forecast(1, forecast_inputs );
    }

    /*
     * Our virtual destructor.
     */
    win_min_max_impl::~win_min_max_impl()
    {

    }

    int
    win_min_max_impl::work(
              int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items)
    {
      auto in = static_cast<const input_type*>(input_items[0]);
      auto max_out = static_cast<output_type*>(output_items[0]);
      auto min_out = static_cast<output_type*>(output_items[1]);

      input_type max = in[0];
      input_type min = in[0];

      for (int i=1; i < win_size; i++) {
        if (max < in[i] ) max = in[i];
        if (min > in[i] ) min = in[i];
      }

      max_out[0] = max;
      min_out[0] = min;

      // Tell runtime system how many output items we produced.
      return 1;
    }

  } /* namespace kb3gtn */
} /* namespace gr */
