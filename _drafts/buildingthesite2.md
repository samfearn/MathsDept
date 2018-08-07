---
layout: post
title: "Building this website with Jekyll: part 2"
description: How to use Jekyll to build a static website.
comments: true
categories:
  - Web
  - Jekyll
---
<!-- I'm assuming no one is going to read these posts, by source, through GitHub. -->

## What is Jekyll? ##

[![Jekyll]({{ '/assets/img/jekyllvial.png' | prepend: site.baseurl | prepend: site.url }}){:.postimage.one.left}][Jekyll]

In my [previous post][jekyllfiles], I gave an overview of the basic files types used in building a modern website, and identified those that were relevant for building a website with Jekyll. To recap: with Jekyll, we write our content using [Markdown][jekyllfilesmarkdown] which is processed to produce the HTML and we write our styling using [SASS][jekyllfilessass] which is processed into CSS. We can choose to either write our client-side scripts as JavaScript, or use [CoffeeScript][jekyllfilescoffeescript] which will be processed to produce JavaScript.

In this post, I want to explain what Jekyll is, and how you can use Jekyll to produce a website. I plan to then discuss some particular features of this website in future posts.

So, what is Jekyll? Jekyll is a system for creating static sites. This means that there are no [server-side scripts][jekyllfilesserver] which get run when someone tries to view your webpage. Furthermore, Jekyll uses a templating system known as [liquid](#liquid) to make it easy to create pages for your website. Jekyll is therefore ideal for relatively simple websites which have a focus on content. Since my website was designed to give me space to host content related to my teaching, a blog to use to write about things I'm interested in or working on, as well as links to academic output, a static site was easily sufficient for my needs. With it's support for [liquid](#liquid) templating and many [themes](#themes) available to use immediately, Jekyll seemed like a great choice for what I wanted. It's worth mentioning that there are [many other static site generators][staticsitesgens] which one could use instead of Jekyll, but since Jekyll was the static site generator that I'd already heard of, I went with Jekyll.

### Building a website with Jekyll ###

Jekyll is a Ruby program which we use to turn a directory of content into a website which can be uploaded to a webserver. Jekyll is used from a command prompt, so I'll assume familiarity with working at a command line (terminal) -- [here's a good guide][terminal] if you're not already familiar with the terminal.

Once you have [installed Jekyll] onto your computer (if you have any problems with this, there is a [jekyll troubleshooting] page), you can create your first Jekyll site by opening up the terminal, `cd`ing to the directory you want to put the site in, and running the command `jekyll new mysite` (this names the site folder 'mysite' but has no effect on the site itself).

{% lightimg {"alt":"Scaffolding a new Jekyll site test", "img":"newjekyll.png", "img_class":"postimage three"} %}

This scaffolds out a basic site using the default theme 'minima', [which we can change later](#themes). To have a look at your new site, we can use Jekyll's built in local webserver. Change into the directory by running `cd mysite` and then run `bundle exec jekyll serve`. This command uses the [ruby gem] '[bundler]' to make sure that any gem used in your Jekyll site is up-to-date and then runs the local server. By default this site will now be available at `http://127.0.0.1:4000/` as indicated by the 'server address:' part of the output of the previous command.

{% lightimg {"alt":"Running the local Jekyll server", "img":"jekyllserve.png", "img_class":"postimage half right"} %}

If you now open a web browser and type the server address (`http://127.0.0.1:4000/`, unless you've changed it from the default) into the address bar at the top, you will see the default homepage of your new Jekyll based website. By using the power of Jekyll themes, not only does the website already look good, it's also got a responsive mobile-friendly design.

{% lightimg {"alt":"Responsive out of the box", "img":"mobileready.png", "img_class":"postimage three"} %}

When we run `bundle exec jekyll serve`, as well as starting a local webserver to let us test the site, Jekyll has also built the site for us. We'll look at where the files for the built so go in the [next section](#directory-structure), but basically this means that Jekyll has processed all the files that describe our site, and produced the html and css which we can put onto a server. If we want to build the site without running the test server, we can do that using `bundle exec jekyll build`.

### Directory Structure ###

If you look at the contents of your Jekyll directory, you should see that running `jekyll new mysite`, followed by `bundle exec jekyll serve`, has created 6 regular files and 2 folders for us. 

{% lightimg {"alt":"The directory structure of a new Jekyll project using the Minima theme", "img":"newjekylldir.png", "img_class":"postimage three"} %}

We have 2 basic pages called 'About' and 'Index', both of which are stored as [Markdown][jekyllfilesmarkdown] files, as well as a third page, `404.html`, which is loaded when the server can't find a page we ask it for. The index page is the one which is loaded when you just type the url of the website (which is the local server address for the time being) without asking for a specific page. We'll discuss the structure of these pages in the [next section](#a-jekyll-page), for now let's just consider the overall directory structure.

The next file I want to discuss in our new site folder is the `_config.yml` file. Note that this file, as well as some of the folders in this directory have names starting with an underscore character. This is a naming convention Jekyll uses for files and folders which are processed when [building the site](#building-a-website-with-jekyll), but which don't explicitly appear in the output files which are uploaded to our server. The `_config.yml` file is a configuration file written in a language called [YAML (to rhyme with camel)][yaml]. I won't go into the details of YAML here, as its designed to be very easy to read, and looking through the default config file should make everything clear. The values which we set in this configuration file can be easily accessed through [liquid](#liquid).

{% lightimg {"alt":"Default build settings in the config.yml file", "img":"defaultjekyllconfig.png", "img_class":"postimage one right"} %}

As well as allowing us to set some site wide constants which we can access through liquid, the `_config.yml` file also sets options which are interpreted by Jekyll when we [build the site](#building-a-website-with-jekyll). For instance, the default build settings tell Jekyll to use the [kramdown] markdown processor and the [theme](#themes) called minima.

[![Ruby Gems logo]({{ '/assets/img/rubygem.jpg' | prepend: site.baseurl | prepend: site.url }}){:.postimage.one.left}][rubygem]

The final files included in our new site are `Gemfile` and `Gemfile.lock`. As the name suggests, these files concern [Ruby 'gems'][rubygem], which are Ruby packages - libraries or programs. Jekyll uses a gem called [bundler] to manage the other gems that you might want to use in your website. For example, this website uses the [jemoji] gem to enable me to easily include emoji in my posts - like this :see_no_evil:. The default Gemfile in your new site folder ensures that the gem associated with the default minima theme is installed and up-to-date, amongst other things. When we [build the site](#building-a-website-with-jekyll) by running `bundle exec jekyll serve`, this tells bundler to check the `Gemfile` to ensure that all required gems are installed and up-to-date (and that all gems which our required gems are dependent on are also installed) before running the `jekyll serve` command. The `Gemfile.lock` contains a list of all the gems that bundler has installed for your site.

One main usage of Jekyll is to run a simple blog (though Jekyll is still useful for static sites without a blog), and these blog posts live in the `_posts` folder. Each post should be a [markdown][jekyllfilesmarkdown] file, with a name of the form `YYYY-MM-DD-title`, and will then automatically be included by Jekyll in the blog posts for the site. We'll look at the content of these files in [the next section](#a-jekyll-page).

The final folder you will see in your new site folder is the `_site` folder. If you were paying careful attention to the contents of this folder, you'll have realised that this folder was only created once we first [built the site](#building-a-website-with-jekyll) by running `bundle exec jekyll serve`. This command told Jekyll to look at all the content making up our website and from this to produce the actual html, css and javascript files which we should upload to our server. These files are then placed in the `_site` folder, and so it is the entire contents of this folder which we should upload to our server. Any files or folders not otherwise processed by Jekyll will be copied verbatim into the `_site` folder. If we therefore create an `assets` folder in the root of our site folder, we can place any images or other files which Jekyll doesn't need to process in this folder, and they will appear in our final `_site` folder ready to be uploaded.

Although these are the only files and folders present in a new Jekyll site created with `jekyll new mysite`, there are some other special folders used by Jekyll themes that [we'll discuss later](#overriding-theme-defaults).

### A Jekyll page ###

If you open the markdown file associated with the about page, `about.md`, you'll see that it only contains the *content* of the page. The theme styling, as well as the header and footer of the page, are included by Jekyll using the [liquid](#liquid) templating system, which we discuss in more detail below.

### Liquid ###


### Themes ###

#### Installing a new gem-based theme ####

#### Overriding theme defaults ####



[Jekyll]:https://jekyllrb.com
[jekyllfiles]:{{ site.baseurl }}{% post_url 2018-07-20-buildingthesite1 %}
[jekyllfilesmarkdown]:{{ site.baseurl }}{% post_url 2018-07-20-buildingthesite1 %}#markdown
[jekyllfilessass]:{{ site.baseurl }}{% post_url 2018-07-20-buildingthesite1 %}#sass
[jekyllfilescoffeescript]:{{ site.baseurl }}{% post_url 2018-07-20-buildingthesite1 %}#coffeescript
[jekyllfilesserver]:{{ site.baseurl }}{% post_url 2018-07-20-buildingthesite1 %}#server-side-scripts
[staticsitesgens]:https://www.netlify.com/blog/2017/05/25/top-ten-static-site-generators-of-2017/
[installed Jekyll]:https://jekyllrb.com/docs/installation/
[terminal]:https://freedompenguin.com/articles/how-to/beginners-guide-bash-terminal/
[jekyll troubleshooting]:https://jekyllrb.com/docs/troubleshooting/
[yaml]:http://yaml.org
[kramdown]:https://kramdown.gettalong.org
[rubygem]:https://rubygems.org
[bundler]:https://bundler.io
[jemoji]:https://github.com/jekyll/jemoji
[minima]:https://github.com/jekyll/minima
