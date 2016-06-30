
ChangeLog v3.7.9.2
==================

Contributors
------------

The following list of people directly contributed code to this release.

 * A. Maitland Bottoms <bottoms@debian.org>
 * Andrej Rode <mail@andrejro.de>
 * Andy Sloane <andy@a1k0n.net>
 * Andy Walls <awalls@md.metrocast.net>
 * Chris Kuethe <chris.kuethe+github@gmail.com>
 * Clayton Smith <argilo@gmail.com>
 * dae hyun, yang <daehyun.yang@gmail.com>
 * DaulPavid <paul.david@ettus.com>
 * Derek Kozel <derek.kozel@ettus.com>
 * flarroca <flarroca@fing.edu.uy>
 * Glenn Richardson <glenn.richardson@live.com>
 * gnieboer <gnieboer@corpcomm.net>
 * Jiří Pinkava <j-pi@seznam.cz>
 * Johannes Schmitz <schmitz@ti.rwth-aachen.de>
 * Johnathan Corgan <johnathan@corganlabs.com>
 * johschmitz <johannes.schmitz1@gmail.com>
 * Kevin McQuiggin <mcquiggi@sfu.ca>
 * Laur Joost <daremion@gmail.com>
 * Marcus Müller <marcus.mueller@ettus.com>
 * Martin Braun <martin.braun@ettus.com>
 * mhostetter <mhostetter@users.noreply.github.com>
 * Michael Dickens <michael.dickens@ettus.com>
 * Nathan West <nathan.west@gnuradio.org>
 * Paul Cercueil <paul.cercueil@analog.com>
 * Philip Balister <philip@balister.org>
 * Ron Economos <w6rz@comcast.net>
 * Sean Nowlan <sean.nowlan@gtri.gatech.edu>
 * Sebastian Koslowski <koslowski@kit.edu>
 * Seth Hitefield <sdh11@vt.edu>
 * Stefan Wunsch <stefan.wunsch@student.kit.edu>
 * Tim O'Shea <tim.oshea753@gmail.com>
 * Tom Rondeau <tom@trondeau.com>
 * tracierenea <tracie.perez@mavs.uta.edu>


### Closed issues

 * \#713
 * \#878
 * \#853
 * \#857
 * \#908

Code
----

v3.7.10 spans a time of organization transition as Tom stepped down to
work on other things. The major development efforts of GNU Radio continue
to focus on improving packet and bursty communication modems. As always
the build system continues to improve as people work on diverse platforms.

### GRC

The refactor of GRC continues. This should be mostly feature neutral
and make it easier for new contributors to come in and make useful
changes. Part of this is deprecating blks2 and and xmlrpc blocks and
moving them to components where they would be expected to be found
rather than the GRC sub-tree.

GRC tools and workflow have been improved in the following ways:
 * variable explorer panel and option to hide variables from canvas
 * nicer block documentation tool-tip and properties dialog tab
 * screenshots can have transparent background
 * darker color for bypassed blocks
 * select all action
 * block alignment tools
 * added bits (unpacked bytes) as a data type
 * show warning for blocks flagged as deprecated
 * remove [] around categories in the block library
 * separate core and OOT block trees via the category of each block

### Runtime

Clear tags and reset all item counters when merging connections between
blocks, which prevents bad values from being propagated on lock/unlock
operations.

Blocks always set their max_noutput_items before a flowgraph starts if it
hasn't already been set.

Added some options to gnuradio-config-info that prints information about
the gnuradio prefs file. The old customized preference file reader is
replaced with a boost program options object.

### QT GUIs

The QT GUI widgets can now toggle axis labels and the frequency sink has
a new feature to set the y-axis label. This could be useful for changing
units on calibrated measurements.

The QT GUI Entry widget has a new message port that emits a message
containing the new text whenever editing is finished.

QT widgets recently had an optional message port to plot PDUs. This release
adds a feature to plot the tag metadata contained in the PDU.

A new example shows how to build a C++ only QT based application.

### gr-digital

New QA for tagged stream correlate access code blocks further cement
how these blocks should be behaving.

The big change revolves around a branch known formerly known as packet2.
This introduces packet formatting and parsing tools. There are several
new examples and documentation that explain how they are used. The big
signal processing change is in the corr_est block which uses a linear
estimator now rather than the parabolic estimator.

16QAM is now available from the GRC constellation object dialog drop down
menu.

### gr-analog

The frequency modulator now has sensitivity exposed through controlport.

New FM pre emphasis and de-emphasis filters. The previous filters were
effectively all-pass filters. There is a very nice write up on the new
filters in gr-analog/python/analog/fm_emph.py

A new message port to sig_source is available that can set signal frequency
with the same convention as gr-uhd usrp_source.

### gr-filter

Use the max_noutput_items in start() to allocate FFT buffers for the PFB
decimator rather than always allocating/freeing a buffer in work().

### gr-blocks

Add a run-time accessor and setter for interpolation of repeat blocks.

vector_sink.reset() clears tags now

Add accessors for the vector_source repeat flag so it's settable outside
the ctor.

Fix tuntap devices MTU size. Previously MTU size argument was used to
allocate correct buffer size, but didn't actually change the MTU of the
underlying device.

The UDP source block can read gr prefs file for the payload buffer size
or default to the existing value of 50.

Yet another block making use of VOLK: the divide_cc block is now 10x
faster on some machines.

### gr-dtv

Improved OFDM symbol acquisition for DVB-T receiver.
Several controlport hooks created as well as some performance
improvements

DTV has new transmitters for DVB-S and ITU-T J.83B 64QAM. New support for
DVB-S2X VL-SNR code rates, modulation, and framing for AMSAT are also
available.

### gr-uhd

New argument in usrp_source initializer to start streaming on the start
of a flowgraph which defaults to true (the existing behavior).

Add a clock-source argument to uhd_fft.

A new message command handler for the usrp_source block will trigger a
time and rate tag to be emitted.

Added support for importing, exporting, and sharing LOs.

### gr-audio

Refactor audio sink for windows with multiple buffers to prevent
skipping.

### modtool

Add an option to set the copyright field for new files.

New modules will detect PYBOMBS_PREFIX and install to the defined
location.

Add versioning support for OOT modules by default.

### Builds

Eanble controlport for static builds.

Enable GR_GIT_COUNT and GR_GIT_HASH environment variables for extended
versioning number for packagers.

We explicitly set the C/C++ standards to C++98 and gnu11 rather than use
the compiler defaults since many compilers are moving to C++11 by default.
Incidentally this caused minor breakage with a subtle VOLK API fix in
gr-dtv which was also fixed.

Fixed finding GNU Radio + VOLK in non-standard prefixes when compiling
OOT modules.