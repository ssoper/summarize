class File
  # Summarizes the contents of a file
  #
  # == Options:
  # ratio::
  #   A Fixnum from 0 to 100
  #
  # language::
  #   An ISO 639-1 language code. See Summarize::LANGUAGES for the supported list.
  #
  # dictionary::
  #   A path to a custom stemming XML file
  #
  # topics::
  #   A boolean indicating whether to return topics as well. Return value will be
  #   an array instead with content first and topics second. Default is false.
  #
  # == Returns:
  # A string summary OR an array of content and topics
  #
  def summarize(options = {})
  	self.read.summarize(options)
  end

end
