/* -*- c++ -*- */
/*
 * Copyright 2022 Peter Fetterer (KB3GTN).
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_KB3GTN_WIN_MIN_MAX_H
#define INCLUDED_KB3GTN_WIN_MIN_MAX_H

#include <gnuradio/kb3gtn/api.h>
#include <gnuradio/sync_decimator.h>

namespace gr {
  namespace kb3gtn {

    /*!
     * \brief <+description of block+>
     * \ingroup kb3gtn
     *
     */
    class KB3GTN_API win_min_max : virtual public gr::sync_decimator
    {
     public:
      typedef std::shared_ptr<win_min_max> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of kb3gtn::win_min_max.
       *
       * To avoid accidental use of raw pointers, kb3gtn::win_min_max's
       * constructor is in a private implementation
       * class. kb3gtn::win_min_max::make is the public interface for
       * creating new instances.
       */
      static sptr make(int win_size);
    };

  } // namespace kb3gtn
} // namespace gr

#endif /* INCLUDED_KB3GTN_WIN_MIN_MAX_H */
