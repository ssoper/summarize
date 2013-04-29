require 'summarize/summarize'
require 'summarize/version'
require 'summarize/languages'
require 'summarize/core_ext/hash'

module Summarize
  def self.parse_options(options = {}) #:nodoc:
    default_options = {
      :ratio => 25,      # percentage
      :language => 'en', # ISO 639-1 code
      :topics => false
    }

    options = default_options.merge(options.symbolize_keys)

    if options.key? :dictionary
      dict_file = options[:dictionary]
    else
      raise "Language not supported" unless LANGUAGES.index(options[:language])
      dict_file = File.join(File.expand_path(File.dirname(__FILE__)), "../ext/summarize/dic/#{options[:language]}")
    end

    return [dict_file, options[:ratio], options[:topics]]
  end

  class << self
  	alias_method :summarize_with_options, :summarize

	  def summarize(text, options = {})
	  	summarize_with_options(text, *parse_options(options))
	  end
  end
end