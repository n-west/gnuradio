#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2014 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
#

from gnuradio import gr, gr_unittest
from gnuradio import blocks, zeromq
import time

class qa_zeromq_pubsub (gr_unittest.TestCase):

    def setUp (self):
        self.tb = gr.top_block ()

    def tearDown (self):
        self.tb = None

    def test_001 (self):
        vlen = 10
        src_data = range(vlen)*100
        src = blocks.vector_source_f(src_data, False, vlen)
        endpoint = "tcp://127.0.0.1:"
        zeromq_pub_sink = zeromq.pub_sink(gr.sizeof_float, vlen, endpoint + "*", 0)
        port = zeromq_pub_sink.endpoint().split(":")[-1]
        zeromq_sub_source = zeromq.sub_source(gr.sizeof_float, vlen, endpoint + port, 0)
        sink = blocks.vector_sink_f(vlen)
        self.tb.connect(src, zeromq_pub_sink)
        self.tb.connect(zeromq_sub_source, sink)
        self.tb.start()
        time.sleep(0.25)
        self.tb.stop()
        self.tb.wait()
        self.assertFloatTuplesAlmostEqual(sink.data(), src_data)

    def test_002(self):
        # Test getting the endpoint returns a port we explicitly set endpoint to
        endpoint = "tcp://127.0.0.1:5554"
        zeromq_pub_sink = zeromq.pub_sink(gr.sizeof_float, 1, endpoint, 0)
        self.assertEqual(endpoint, zeromq_pub_sink.endpoint())

    def test_003 (self):
        # Test the set_endpoint() call
        vlen = 10
        src_data = range(vlen)*100
        src = blocks.vector_source_f(src_data, False, vlen)
        endpoint = "tcp://127.0.0.1:"
        zeromq_pub_sink = zeromq.pub_sink(gr.sizeof_float, vlen, endpoint + "*", 0)
        port = zeromq_pub_sink.endpoint().split(":")[-1]
        zeromq_sub_source = zeromq.sub_source(gr.sizeof_float, vlen, endpoint + port, 0)
        # Now set new endpoints
        zeromq_pub_sink.set_endpoint(endpoint + "*")
        port = zeromq_pub_sink.endpoint().split(":")[-1]
        zeromq_sub_source.set_endpoint(endpoint + port)
        sink = blocks.vector_sink_f(vlen)
        self.tb.connect(src, zeromq_pub_sink)
        self.tb.connect(zeromq_sub_source, sink)
        self.tb.start()
        time.sleep(0.25)
        self.tb.stop()
        self.tb.wait()
        self.assertFloatTuplesAlmostEqual(sink.data(), src_data)


if __name__ == '__main__':
    gr_unittest.run(qa_zeromq_pubsub)
