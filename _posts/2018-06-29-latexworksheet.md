---
layout: post
title: A $$\LaTeX{}$$ worksheet for beginners
date: 2018-06-29 21:03:56+0100
description: Originally created as a worksheet for first year undergraduates.
categories:
  - LaTeX
  - Teaching
comments: true
---
Edit: The worksheets linked in this post have been updated. You can find the new worksheets [here][updatedworksheets].

***

Given that my [first post][firstpost] concerned tips for using $$\LaTeX{}$$ and the beamer package to create presentations, I thought I'd use this post to share a resource I recently created to help teach $$\LaTeX{}$$. The worksheet is simultaneously an information sheet -- with information about various environments and commands -- as well as an exercise sheet. The exercise is to recreate the sheet yourself as closely as possible using $$\LaTeX{}$$. The worksheet is available from the following link:

<a href="/~sxwc62/assets/postfiles/20180626/LaTeXWorksheet.pdf"><span class="fas fa-download">&nbsp; $$\LaTeX{}$$ Worksheet</span></a>
{: .center}

At the end of this post, I'll also provide a link to the source tex file used to create the worksheet. You can use this to check your own solution against to see how close you were to the original worksheet. I've also included some comments in the source file which you might hopefully find interesting. For the time being, I'm going to enable comments on this post, so if you have any questions feel free to ask in the comments below. The rest of this post will be a brief introduction to $$\LaTeX{}$$ for those that haven't encountered it before.

### What is $$\LaTeX{}$$? ###

$$\LaTeX{}$$ (built on $$\TeX{}$$) is a system for producing formatted text-based documents. Unlike most word processors, the document is written in plain text, without formatting. Markup commands are included in order to tell $$\LaTeX{}$$ how the document should look. This is very similar in spirit to the way that html works. $$\LaTeX{}$$ makes many decisions automatically in order to easily produce high quality output that doesn't require the reader to own proprietary software.

Although it may take you a little time to become familiar using $$\LaTeX{}$$, you will find that after a little practice you are able to create professional looking documents using $$\LaTeX{}$$ very easily. $$\LaTeX{}$$ is very widely used by those teaching and researching at universities around the work, particularly among the sciences, and therefore I would expect most mathematics and physics students (I'm less sure in the other sciences) to encounter $$\LaTeX{}$$ at some point during their degrees.

### How Do I Use $$\LaTeX{}$$? ###

Since a $$\LaTeX{}$$ (or $$\TeX{}$$, I won't discuss the differences here) document is written in plain text, any plain text editor (Notepad, TextEdit, Gedit, Leafpad, Vim...) can be used to write the tex file. However, in order to produce the formatted output, the tex file must be 'typeset' using the $$\LaTeX{}$$ system to produce a PDF of your document.

$$\LaTeX{}$$ is free software and can be easily installed on your own computer. Windows users can install [MiKTeX] and macOS/OS X users can install [MacTeX]. I think many Linux distributions come with $$\LaTeX{}$$ installed by default, but if anyone wants to clarify this for me then please do so in the comments below. These installations come with specialised $$\LaTeX{}$$ frontends (editors) which provide features like syntax colouring, code completion and documentation. While you get comfortable using $$\LaTeX{}$$, I recommend you use one of the dedicated editors that comes with your installation, as it will provide a convenient button in the interface for 'building' the source file (which is a `.tex` file) into a pdf output.

There exist iPad apps capable of producing $$\LaTeX{}$$ documents, and you can also produce $$\LaTeX{}$$ documents using a web browser with [ShareLaTeX] (and others).

Let's now look at the most basic example of a $$\LaTeX{}$$ file:

~~~tex
\documentclass{article}
\begin{document}
Some text here
\end{document}
~~~
{:.anchored id="Latex1"}

All $$\LaTeX{}$$ documents have to begin with a line that sets a document class (this isn't quite true, see [my previous post][prev]). The document class tells $$\LaTeX{}$$ what kind of document we're trying to produce, and sets a particular layout style for the document. Here are some available [document classes] that are available by default in $$\LaTeX{}$$. Everything between the `\begin{document}` and `\end{document}` lines constitutes the 'body' of the document. This is where we place all the content of our document.

Although this produces a document, it has very minimal formatting and isn't very attractive. Let's consider an example with some more structure.

~~~tex
\documentclass{article}
% We define an Author, Title and Date
\author{Sam Fearn}
\title{A Very Quick Introduction To \LaTeX{}}
\date{March 15\textsuperscript{th}, 2018}

\begin{document}
% Create a title from our Author, Title and Date
\maketitle
\section{Introduction}
Some introductory text goes here
\section{Content}
The main content goes here
\end{document}
~~~
{:.anchored id="Latex2"}

Here we recognise the same basic structure as in the first example, starting with a `\documentclass{}` and containing the body of the document between the `\begin{document}` and `\end{document}` lines. The first main change is that we have a section before the body, which is known as the 'preamble'. We've used the preamble in this example to set some variables which are then used in the `\maketitle` line to produce a title page for the document. We also can use the preamble section of a $$\LaTeX{}$$ document to load additional 'packages', which extend the functionality of $$\LaTeX{}$$, or to define our own custom commands -- packages are explained in more detail in the worksheet. This short example also shows how we can use `\section{}`s to break our document into smaller sections with titles. Finally, the lines which start with a `#` are 'comments', these lines are ignored by $$\LaTeX{}$$ and allow us to leave ourselves notes in the source file.

### Typesetting Mathematics In $$\LaTeX{}$$ ###

$$\LaTeX{}$$ is **very** good at typesetting mathematical formulae. Here's a quick example:

~~~tex
If $\phi(x) = \frac{1}{\sqrt{2\pi}}e^{- x^2/2}$, then
\begin{equation}
	\Phi(x) := \int_{-\infty}^x \phi(t) dt.
\end{equation}
Moreover,
\begin{equation}
	\int_{-\infty}^\infty \frac{1}{\sigma
\sqrt{2\pi}} e^{-\frac{1}{2}\left(\frac{x-\mu}{\sigma}
\right)^2} dt = 1
\end{equation}
~~~

This gives the following output:

If $$\phi(x) = \frac{1}{2\pi}e^{- x^2/2}$$, then

$$
\Phi(x) := \int_{-\infty}^x \phi(t) dt.
$$

Moreover,

$$
	\int_{-\infty}^\infty \frac{1}{\sigma\sqrt{2\pi}}e^{-\frac{1}{2}\left(\frac{x-\mu}{\sigma}\right)^2} dt = 1.
$$

Here's another example:

~~~tex
We say a map $\psi:A \to B$ is \emph{injective} if
\begin{equation}
	\psi(a_1) = \psi(a_2) \implies a_1 = a_2,\ 
\forall\ a_1,a_2 \in A.
\end{equation}
~~~

which produces:

We say a map $$\psi:A \to B$$ is *injective* if

$$
	\psi(a_1) = \psi(a_2) \implies a_1 = a_2,\ \forall\ a_1,a_2 \in A.
$$

$$\LaTeX{}$$ can produce any mathematical expression you might want. Most of the commands you'll need are named with simple, self-explanatory names, and so you can probably guess many commands without even having to search them. In the next section you'll find some useful references to look up any command you might need.

### Learning $$\LaTeX{}$$ ###

The best way to learn $$\LaTeX{}$$ is simply to start practicing using it. This is what the worksheet provided at the start of this post is designed to help you do. Beyond simply practicing, some useful resources to be aware of are:

* Durham mathematics department's page on [$$\LaTeX{}$$ for undergraduates][latex for undergraduates]. This contains links to the relevant installers, as well as instructions for Durham students on running \LaTeX{} on university computers.
* The $$\LaTeX{}$$ documentation available on [ShareLaTeX][sharelatexhelp]. These pages have some excellent documentation and are a great place to learn the basics of using $$\LaTeX{}$$.
* [The Not So Short Introduction to $$\LaTeX{}$$][notsoshort], which contains almost everything you'll need to know about $$\LaTeX{}$$ (for a while at least).
* [Detexify], which lets you search for anything you can draw.
* [StackExchange] and [Google], where you'll find someone has almost certainly answered the question you have already.

You don't have to learn everything about $$\LaTeX{}$$ initially, just start trying to write in $$\LaTeX{}$$ and you'll figure it out as you go!

### Other Files

This post is based on a presentation I gave about $$\LaTeX{}$$. The slides for the presentation are available here:

<a href="/~sxwc62/assets/postfiles/20180626/LaTeXWorkshop.pdf"><span class="fas fa-download">&nbsp; $$\LaTeX{}$$ Presentation Slides</span></a>
{: .center}

If you'd like to see how these slides were created using Beamer, the source code for the slides is available here:

<a href="/~sxwc62/assets/postfiles/20180626/LaTeXWorkshop.tex"><span class="fas fa-download">&nbsp; $$\LaTeX{}$$ Presentation Slides Source File</span></a>
{: .center}

If you'd like to check your source code for the worksheet against mine then you can get the source tex file used for the worksheet here:
	
<a href="/~sxwc62/assets/postfiles/20180626/LaTeXWorksheet.tex"><span class="fas fa-download">&nbsp; $$\LaTeX{}$$ Worksheet Source File</span></a>
{: .center}

***

This worksheet formed the main exercise for a two hour beginner session on $$\LaTeX{}$$ given to first year undergraduates taking a course in mathematics at Durham University. If you are involved with teaching $$\LaTeX{}$$ then you are welcome to use this sheet freely as detailed by the license below. If you do use the sheet, either with or without modification, I'd be keen to hear from you either via a comment below or an [email].

<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons Licence" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" />{: display: "block"; style="margin: auto";}</a>
{: .center}

This work by <a xmlns:cc="http://creativecommons.org/ns#" href="http://www.maths.dur.ac.uk/~sxwc62/" property="cc:attributionName" rel="cc:attributionURL">Sam Fearn</a> is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.

[updatedworksheets]:{{ '/blog/2019/latexworksheetupdates/' | prepend: site.baseurl | prepend: site.url }}
[firstpost]:{{ '/blog/2018/latexhandouts/' | prepend: site.baseurl | prepend: site.url }}
[email]:mailto:s.m.fearn@durham.ac.uk
[MiKTeX]:http://miktex.org/
[MacTeX]:http://www.tug.org/mactex/
[ShareLaTeX]:https://www.sharelatex.com/
[prev]:/~sxwc62/blog/2018/latexhandouts/
[document classes]:https://en.wikibooks.org/wiki/LaTeX/Document_Structure#Document_classes
[latex for undergraduates]:https://www.dur.ac.uk/mathematical.sciences/teaching/latex/
[sharelatexhelp]:https://www.sharelatex.com/learn
[notsoshort]:https://tobi.oetiker.ch/lshort/lshort.pdf
[Detexify]:http://detexify.kirelabs.org/classify.html
[StackExchange]:https://tex.stackexchange.com
[Google]:http://www.google.com