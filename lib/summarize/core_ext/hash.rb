class Hash #:nodoc:
  def symbolize_keys
    inject({}) do |options, (key, value)|
      options[(key.to_sym rescue key) || key] = value
      options
    end
  end
end unless {}.respond_to? 'symbolize_keys'