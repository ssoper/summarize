require 'mkmf'

%w(glib-2.0 libxml-2.0).each do |lib|
  pkg_config lib
end

create_makefile('summarize/summarize')
