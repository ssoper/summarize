Summarize - A Ruby C wrapper for Open Text Summarizer
=====================================================

Installation
------------

    gem install summarize


Usage
-----

    require 'summarize'

    Summarize.summarize('text to summarize')


By default it uses an English dictionary for summarizing but forty languages are supported. Pass in the valid ISO 639 language code to use one. A ratio (default is 25%) can also be passed in.

    # Parse an article using Portuguese stemming rules with a ratio of 50%
    Summarize.summarize('texto para sumariar', language: 'pt', ratio: 50)


You can also use custom stemming rules
    Summarize.summarize('text to summarize', dictionary: 'path/to/custom/dictionary')


Topics can also be returned

    # Returns an array with content first and topics second
    content, topics = Summarize.summarize('text to summarize', topics: true)
    # content => summarized text
    # topics  => Comma-delimited string of topics


### Usage (with monkey patch)

    require 'summarize/ext_core'


The summarize method is added to File and String:

    File.open('path/to/file').summarize


Or use the String method

    "text to summarize".summarize


As it is a Delegate to Summarize.summarize, same parameters are accepted.


Dependencies
------------

You must have glib-2.0 and libxml-2.0 installed and properly configured.


Author
------

Gem written by Sean Soper ([@ssoper](http://twitter.com/ssoper))

The Open Text Summarizer library was written by Nadav Rotem and can be found at <http://libots.sourceforge.net/>

Gem fixed to handle UTF-8 encoding by Yury Batenko ([@svenyurgensson](http://twitter.com/svenyurgensson))


License
-------

Copyright (C) 2010 Sean Soper <sean.soper@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Library General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
