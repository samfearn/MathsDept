---
layout: post
title: "Building this website with Jekyll: part 1"
date: 2018-07-20 23:46:40+0100
description: The first of a few posts describing how this website is built. In this post we introduce some of the relevant file types and technologies involved.
comments: true
categories:
  - Web
  - Jekyll
---
## Jekyll ##

[![Jekyll](https://jekyllrb.com/img/logo-2x.png){:.postimage.one.right}][Jekyll]

This website was built as a static site using [Jekyll]. The purpose of the current (hopefully short) series of posts is to explain what that means, why I chose to build the site this way, and to explain how the site was created so that others can build a similar site. In this first post, I want to explain what is meant by a 'static' site and the types of files involved in creating a Jekyll based site. Those who don't need or want to read about the background to the website can find all the source files for this website in the relevant repository on my [github page].

## The (main) types of files in a website ##

There are four main types of files involved in a simple website that we'll consider here. Many books have been written on each of these and so the point of this post won't be to explain these in any details, but will hopefully give you an idea of the building blocks of a website and how they fit together in a Jekyll website. In the same way as a $\LaTeX{}$ file, all of the files I'll discuss here can be read and edited as plain text files in any text editor, though there exist many specialised developers tools for working with the different file types, just as there are for $\LaTeX{}$ files. If you'd like to learn more about $\LaTeX{}$, I wrote a brief introduction in my [previous post][LatexPost].

### The Content ###

#### HTML ####

HTML (or HyperText Markup Language) files, stored as `.html` files, contain the main content for [**most**](#server-side-scripts) websites. HTML is similar to $\LaTeX{}$, in that we focus on writing the content of the document and label the structure, and the presentation of the content is handled [separately](#CSS) and interpreted by the web browser. A simple example of an HTML document (with the same *structure* as one of our $\LaTeX{}$ [examples][LatexExamples]) might look like:

~~~html
<!DOCTYPE html>
<html>
<body>

<h1>A Very Quick Introduction To HTML</h1>
<h3>Sam Fearn</h3>
<h3>July 20<sup>th</sup> 2018</h3>

<h2>Introduction</h2>
<p>Some introductory text goes here</p>
<h2>Content</h2>
<p>The main content goes here</p>

</body>
</html>
~~~
{: .anchored id="html1"}

The structure of the HTML document is defined through the use of 'tags'. For example, the paragraph tag `<p>` tells the browser that the text between the opening `<p>` and closing `</p>` tags is a paragraph. This example also uses heading tags of various levels which denote the main title `<h1>`, subtitles `<h2>`, and `<h3>` tags which in this example we're using to denote the author and date. Note that similarly to the $\LaTeX{}$ [example][LatexExamples], we have some extra tags which are used to tell the browser which part consists of the main body of the document -- most web pages would also have a document head, enclosed by opening `<head>` and closing `</head>` tags, which is used to contain various types of metadata.
	
The are many tags which can be used in a HTML document and we shan't try to explain all of them here. Some tags which are worth mentioning however are: 

*  The anchor tag `<a>`. This can be used to add links to other web pages. For instance, we can make the word 'hello' a link to Google by using `<a href = "http://www.google.co.uk" > hello </a>`.
*  The `<img src="link_to_image">` tag which is used to add images to pages.
*  (Unordered) Lists can be added by using `<ul> </ul>` to denote the list, and then `<li> </li>` to add elements to the list. Numbered (Ordered) lists can be created by replacing the `<ul>` tags with `<ol>` tags.

A good introduction to HTML is available at [W3 Schools][W3HTML], and [Mozilla][MozillaHTML] (the creators of the Firefox web browser) also have a good beginners guide.

#### Markdown ####

[![Markdown]({{ '/assets/img/Markdown208x128.png' | prepend: site.baseurl | prepend: site.url }}){:.postimage.one.right}][DFMarkdown]

Markdown is also a filetype used to denote document structure. Originally created by [John Gruber of DaringFireball] fame, markdown files are designed to be simple to read and understand in their plain text form. They remove the need for many of the tags found in a standard HTML document. Note that there is no single Markdown standard and so the exact syntax can vary depending on the implementation being used. If we take the same example document as before, this would be written in markdown as:

~~~md
# A Very Quick Introduction To HTML

### Sam Fearn

### July 20th 2018

## Introduction

Some introductory text goes here

## Content

The main content goes here
~~~

Here, the `#` symbol is used to denote a heading, with the number of `#`s at the start of the line indicating the level of heading. Lines separated by blank lines are interpreted as paragraphs. Markdown files can be processed to turn them into their HTML equivalent, and these output HTML files are the ones that would be put onto a web server. Jekyll uses markdown as the main filetype for producing the content of a website and processes these into HTML files during the Jekyll build phase (see a later post for details).

More information on markdown can be found on [DaringFireball][DFMarkdown] or on [GitHub][GHMarkdown], which allows the use of markdown to provide formatting for comments, gists etc.

### Styling ###

#### CSS ####

CSS, which stands for Cascading Style Sheets, is the technology used to tell the browser how we want the *content* of our webpages -- which is defined through [HTML](#html) -- to look. These stylesheets are 'cascading', since there are multiple places we can define our styles. A fixed order of precedence is then used to decide which of the possible conflicting styles is to be applied to each tag of our HTML document. A simple way to use CSS is to have a `.css` file, known as the stylesheet, which is linked as a resource in the head of an HTML file using `<link rel="stylesheet" href="link_to_stylesheet">`. This stylesheet then contains a simple list of style instructions which the browser uses when displaying the html. A simple example of a CSS file might look like:

~~~css
body {
    background-color: lightgray;
}

h1 {
    color: purple;
    text-align: center;
}

p {
    font-family: Arial, Helvetica, sans-serif;
    font-size: 18px;
}
~~~

Although these self-explanatory commands are very simple, CSS provides a powerful method of styling a webpage. CSS is capable of defining layout and positioning commands, as well as basic animations. We can also use CSS to apply different styles depending on the browser that is trying to view our page through a feature known as [media queries]. This is used in my site to display a full width navigation bar at the top of the screen on a computer, whilst on mobile devices a drop-down menu navigation is used.

A good tutorial on CSS is available from [W3 Schools][W3CSS] and [CSS-Tricks] also has some very useful tips and tricks.

#### SASS ####

[![SASS](https://sass-lang.com/assets/img/logos/logo-b6e1ef6e.svg){:.postimage.one.right}][SASS]

Just as markdown was processed to produce HTML files, [SASS] is a CSS pre-processor. Our SASS files are stored as `.scss` files (in fact there are two types of SASS, one of which uses `.sass` files, but we won't discuss the distinction here) and are then processed to produce standard `.css` files which can be uploaded to a web server and interpreted by the browser. SASS lets us use variables and functions in our style files, making it much easier to write powerful stylesheets. SASS files also allow us to 'include' other SASS files using the `@include` command. This acts like copying and pasting the 'included' file into the main file in which we write the `@include` command. This lets us break our stylesheet into different parts which focus on different parts of our styling -- we might have one file for all the styling of our links, and one which contains all our basic media queries for instance -- and then include all the different parts into one 'main' `.scss` file, which is in turn processed into a single main `.css` file. Jekyll uses `.scss` as the main file type for its style files, though unlike in the case of markdown and HTML, all valid `.css` files are also valid `.scss` files, and so we don't need to know much about SASS in order to use Jekyll.

### Client-side Scripting ###

#### JavaScript ####

The third main type of file which is used in web development is JavaScript. JavaScript is a programming language, where the program is executed on the client side -- that is, in the web browser. JavaScript can be embedded into a web page by using the `<script>` tag. In order to keep the markup content of our webpage separate from the style and functionality, we can write our JavaScript program into a `.js` file and then use the script tag to link to the JavaScript file `<script src="link_to_javascript"></script>`. Note that simple programs are often simply included in the HTML document, by putting the content of the program directly inside the `<script>` tags. JavaScript can be used to manipulate the content, layout and styling of a web page based on the users actions. Given the depth of JavaScript it seems impossible to give a single example of any worth, but ignoring that here is a simple one-line example program:

~~~js
document.getElementById("demo").innerHTML = "Hello World!";
~~~

This interacts with the HTML content of the page, setting the content of an HTML tag with an ID of 'demo' to 'Hello World!'. Let's consider this as part of an HTML file:

~~~html
<!DOCTYPE html>
<html>
<body>

<h2>Simple Hello World example</h2>
<p>This example writes "Hello World!" into a paragraph tag</p>

<p id="demo"></p>

<script>
document.getElementById("demo").innerHTML = "Hello World!";
</script> 

</body>
</html>
~~~

When this web page is loaded the user will see a heading and two paragraphs, the second one containing 'Hello World!'.

W3 Schools also has a good [JavaScript Tutorial][W3JavaScript].

#### CoffeeScript ####

Just as SASS complies to CSS, CoffeeScript compiles to JavaScript. Jekyll supports both JavaScript and CoffeeScript and that's all I want to say about CoffeeScript. If you already know CoffeeScript, you can easily use it with Jekyll, otherwise you can either stick with -- or learn -- plain JavaScript.

### Server-side Scripts ###

The fourth and final main type of file used in building a standard website is a server-side programming language file. Popular choices of server-side languages include PHP, Perl, JavaScript (on the server with Node.js), Python and Ruby. Because these programs are run on the web server, rather than in the clients browser as with JavaScript, they are able to achieve things that client-side scripts cannot. For instance, server-side scripts can be used to communicate with a database of users and customise the interface to a website based on the user accessing the site. These server side scrips can dynamically produce the HTML that is received by the users browser, and in this case it is possible to have a website that doesn't have any `.html` pages at all, with all the HTML being the output of script files.

Having discussed the main building blocks of a website, I can finally explain what I meant when I said that this site is a 'static' website build with Jekyll. This simply means that it contains no server-side scripting -- each user of the site is served the same content by the web server.

### Summary ###

Although this was a long post, hopefully it helps make sense of the main components of a modern website. We have the content delivered to the users browser as a [HTML](#html) file, the styling served as a [CSS](#css) file and potentially also some client-side scripting served as [JavaScript](#javascript). Since Jekyll sites are static, they don't contain any server-side scripts. With Jekyll, we write our content using [Markdown](#markdown) which is processed to produce the HTML and we write our styling using [SASS](#sass) which is processed into CSS. We can choose to either write our client-side scripts as JavaScript, or use [CoffeeScript](#coffeescript) which will be processed to produce JavaScript. In the next -- hopefully shorter -- post (Edit: Sorry :speak_no_evil:), I'll explain more about how we actually use Jekyll to produce a website.

[Jekyll]:https://jekyllrb.com
[LatexPost]:{{ '/blog/2018/latexworksheet/' | prepend: site.baseurl | prepend: site.url }}
[LatexExamples]:{{ '/blog/2018/latexworksheet/#Latex2' | prepend: site.baseurl | prepend: site.url }}
[HTML5]:https://www.w3.org/html/
[W3HTML]:https://www.w3schools.com/html/default.asp
[MozillaHTML]:https://developer.mozilla.org/en-US/docs/Learn/HTML/Introduction_to_HTML
[github page]:https://github.com/samfearn/MathsDept
[John Gruber of DaringFireball]:https://daringfireball.net
[DFMarkdown]:https://daringfireball.net/projects/markdown/
[GHMarkdown]:https://guides.github.com/features/mastering-markdown/
[media queries]:https://www.w3schools.com/css/css3_mediaqueries.asp
[W3CSS]:https://www.w3schools.com/css/default.asp
[CSS-Tricks]:https://css-tricks.com
[SASS]:https://sass-lang.com
[W3JavaScript]:https://www.w3schools.com/js/default.asp
