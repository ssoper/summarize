require 'mkmf'

$CFLAGS = ENV["CFLAGS"].to_s + " " + `pkg-config --cflags glib-2.0 libxml-2.0`.chomp
$LDFLAGS = ENV["LDFLAGS"].to_s  + " " + `pkg-config --libs glib-2.0 libxml-2.0`.chomp

create_makefile('summarize/summarize')
