## Summarize - A Ruby C wrapper for Open Text Summarizer

## Installation

### Easy

    gem install summarize

### Manual

    git clone https://github.com/ssoper/summarize.git
    cd summarize
    rake build
    gem build summarize.gemspec
    gem install summarize-1.0.1.gem

## Usage

The summarize method is added to File which you can use to summarize the contents of any plain text file

    File.open('path/to/file').summarize
    
Or use the String method

    "text to summarize".summarize

By default it uses an English dictionary for summarizing but forty languages are supported. Pass in the valid ISO 639 language code to use one. A ratio (default is 25%) can also be passed in.

    # Parse an article using Portuguese stemming rules with a ratio of 50%
    "texto para sumariar".summarize(:language => 'pt', :ratio => 50)

You can also use custom stemming rules

    "text to summarize".summarize(:dictionary => 'path/to/custom/dictionary')

Topics can also be returned

    # Returns an array with content first and topics second
    content, topics = "text to summarize".summarize(:topics => true)
    # content => summarized text
    # topics  => Comma-delimited string of topics

## Dependencies

You must have glib-2.0 and libxml-2.0 installed and properly configured.
    
## Author

Gem written by Sean Soper ([@ssoper](http://twitter.com/ssoper))

The Open Text Summarizer library was written by Nadav Rotem and can be found at <http://libots.sourceforge.net/>

## License

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
