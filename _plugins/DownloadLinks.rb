require 'json'
# Based on code at https://blog.sverrirs.com/2016/04/custom-jekyll-tags.html

module Jekyll

  class DownloadLinks < Liquid::Tag
    def initialize(tag_name, input, tokens)
      super
      @input = input
    end

    # Lookup allows access to the page/post variables through the tag context
    def lookup(context, name)
      lookup = context
      name.split(".").each { |value| lookup = lookup[value] }
      lookup
    end

    def render(context)
    
      # Set defaults first
      title = ""
      link = ""
      full_link_path = ""

      # Attempt to parse the JSON if any is passed in
      begin
        if( !@input.nil? && !@input.empty? )
          jdata = JSON.parse(@input)
          title = jdata["title"].strip
          link = jdata["link"].strip
        end
      rescue
      end
      
      # Accessing the page/site variables
      baseurl = "#{lookup(context, 'site.baseurl')}/"
      full_link_path = (baseurl+link).tr_s("//","/")

      # Create the HTML output for the image container
      output =  "<div class=\"center dlink\">"
      output += "<a href=\"#{full_link_path}\"><span class=\"fas fa-download\">&nbsp; #{title}</span></a>"
      output += "</div>"

      return output    
    end

  end
end
Liquid::Template.register_tag('dlink', Jekyll::DownloadLinks)