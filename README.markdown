# Summarize

## A Ruby C wrapper for Open Text Summarizer

## Install

### Easy

    gem install summarize

### Manual

    git clone https://github.com/ssoper/summarize.git
    cd summarize
    rake build
    gem build summarize.gemspec
    gem install summarize-1.0.gem

## Usage

The summarize method is added to File which you can use to summarize the contents of any plain text file

    File.open('path/to/file').summarize
    
Or use the String method

    "text to summarize".summarize

By default it uses an English dictionary for summarizing but forty languages are supported. Pass in the valid ISO 639 language code to use one. A ratio (default is 25%) can also be passed in.

    # Parse an article using Portuguese stemming rules with a ratio of 50%
    "text to summarize".summarize(:language => 'pt', :ratio => 50)

You can also use custom stemming rules

    "text to summarize".summarize(:dictionary => 'path/to/custom/dictionary')

## Dependencies

You must have glib-2.0 and libxml-2.0 installed and properly configured.
    
## Author

Gem written by Sean Soper ([@ssoper](http://twitter.com/ssoper))

The Open Text Summarizer library was written by Nadav Rotem and can be found at <http://libots.sourceforge.net/>
