$:.unshift(File.join(File.dirname(__FILE__), "lib"))
require "summarize"

Gem::Specification.new do |s|
  s.name             = %q{summarize}
  s.summary          = %q{Open Text Summarizer}
  s.description      = %q{Ruby C Extension for Open Text Summarizer}
  s.homepage         = %q{http://github.com/ssoper/summarize}
  s.version          = Summarize::VERSION
  s.authors          = ["Sean Soper", "Yury Batenko"]
  s.email            = %q{sean.soper@gmail.com}

  s.rubygems_version  = %q{1.3.7}
  s.date              = %q{2012-04-24}
  s.rubyforge_project = "summarize"

  s.require_paths = ["lib"]
  s.extensions    = ["ext/summarize/extconf.rb"]
  s.files         = %x{git ls-files}.split("\n").reject {|file| file =~ /^(features|cucumber)/ }

  s.add_dependency 'rake-compiler'
end
