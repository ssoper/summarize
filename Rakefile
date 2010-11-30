require "rubygems"
require "rake"
require "benchmark"

# Built using rake-compiler (https://github.com/luislavena/rake-compiler)
begin
  require "rake/extensiontask"
rescue LoadError
  abort "\nYou must install the rake-compiler gem\n\n  gem install rake-compiler\n\n"
end

Rake::ExtensionTask.new("summarize") do |extension|
  extension.lib_dir = "lib/summarize"
end

task :build => [:clean, :compile]

task :test => :build do
  $:.unshift(File.join(File.dirname(__FILE__), "lib"))
  require "summarize"
  require "test/unit"

  class TestSummarizer < Test::Unit::TestCase
    def setup
      @jupiter = File.read(File.join(File.dirname(__FILE__), 'sample_data/jupiter.txt'))
    end

    def test_ratios
      content, ratio_25, ratio_50 = @jupiter.split('||').collect { |text| text.strip }
      assert content.summarize(:ratio => 25) == ratio_25
      assert content.summarize(:ratio => 50) == ratio_50
    end

    def test_unsupported_language
      content = @jupiter.split('||').first
      assert_raise RuntimeError do
        content.summarize(:language => 'nonexistent')
      end
    end

    def test_invalid_dictionary_file
      content = @jupiter.split('||').first
      assert_raise RuntimeError do
        content.summarize(:dictionary => '/path/to/nowhere')
      end
    end
  end

end
