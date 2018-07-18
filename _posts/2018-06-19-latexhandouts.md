---
layout: post
title: Handouts for beamer talks in $$\LaTeX{}$$
date: 2018-06-19 18:56:21+0100
description: Using the handoutsWithNotes package to create talk notes. Plus a cute document class trick.
categories:
  - LaTeX
comments: false
---
When I give a talk, I usually write the slides using the [Beamer] class in $$\LaTeX{}$$. For the purposes of this post, I'm going to assume the basics of using Beamer are known -- maybe I'll write a post about using Beamer at a later date, but as well as the official user guide linked above, the documentation available at the excellent [ShareLaTeX] is also a good starting point.

### Adding the handoutWithNotes Package ###

Once I've written my talk, I like to prepare myself some presenter's notes, by printing the slides off and annotating them with some key points and information that isn't on the slides that I may want to refer to. Although I could simply print off the pdf which $$\LaTeX{}$$ produces, the problem is that beamer produces one 'page' per transition, and so this would result in a very inefficient set of notes. Moreover, this doesn't leave any space on the page to write the notes. To fix this, I use a latex package called `handoutWithNotes` which is available [here][handoutWithNotes].

To use this package, one simply downloads the associated style file (available from [github]) and puts this `handoutWithNotes.sty` files either in the same directory as the main talk tex file, or in the local texmf directory (found by running `kpsewhich -var-value=TEXMFHOME` at a terminal). One then adds the package to the talk by adding
~~~latex
\usepackage{handoutWithNotes}
~~~
as is usual for any package. At this point, the document will still compile in the usual way, producing one page per transition. To create our handout we need to make at least one more change:

* Add the handout option to the beamer document class:
~~~latex
\documentclass[handout]{beamer}
~~~
This tells $$\LaTeX{}$$ to produce one page per slide, collapsing the transitions.
* (Optionally) Change the number of pages shown on each page. I find it best to have three slides per A4 page, though this can be adjusted in the obvious way:
~~~latex
\pgfpagesuselayout{3 on 1 with notes}[a4paper]
~~~
Note that `\pgfpagesuselayout{}`{:.highlight.language-latex} can be used without requiring the handoutWithNotes package, but the 3 on 1 layout that I use here is added by handoutWithNotes, as is the 'with notes' option.

If you build your file at this point, you should find that the output document contains three slides per page, with space at the side for your notes. We can now produce the handout file, rename the output pdf so that it doesn't get overwritten when we rebuild the actual slides, and then change the document class back and remove the `\pgfpages{}` command,
~~~latex
\documentclass{beamer}
%\pgfpagesuselayout{3 on 1 with notes}[a4paper]
~~~
Here I've used a $$\LaTeX{}$$ comment (the `%` at the start of the second line) so that $$\LaTeX{}$$ doesn't process this command. This way if we need to rebuild the handout at any point we can simply uncomment this line and add the handout option back to the document class. At the end of this post I'll show you a neater way to manage this switch.

### Overflow ###

When I write my slides, I sometimes add pictures that only stay on the slides for a single transition, by using code of the form
~~~latex
\only<3>{
    \begin{center}
        \includegraphics{image.jpg}
    \end{center}
}
~~~
This causes a problem when one follows the steps described above, as the `handout` option which we passed to the beamer document class ignores transitions such as `\only<3>{Content}`{:.highlight.language-latex}. The solution is to use an additional option to the `\only<3>{Content}`{:.highlight.language-latex} command,
~~~latex
\only<3 | handout:0>{
    \begin{center}
        \includegraphics{image.jpg}
    \end{center}
}
~~~
This tells $$\LaTeX{}$$ to ignore anything inside this `only` block while producing the output, **but only if we're in handout mode**. That means we're safe to add this to all the images that we're happy to ignore in our notes, and every time we build the actual slides (without using the handout option to the document class) our images appear, only when using the handout option (to the document class) do they not appear. We can actually use this same option to make our images appear on separate slides in our handout with commands of the form
~~~latex
\only<3 | handout:1>{
    \begin{center}
        \includegraphics{image.jpg}
    \end{center}
}
~~~
This is discussed further in a nice [StackExchange] answer.

### The Cute \documentclass Trick ###

At this point we should be able to switch at will between producing our actual talk slides
~~~latex
\documentclass{beamer}
%\pgfpagesuselayout{3 on 1 with notes}[a4paper]
~~~
or handouts that don't have any horrible overflowing issues
~~~latex
\documentclass[handout]{beamer}
\pgfpagesuselayout{3 on 1 with notes}[a4paper]
~~~

This is very nice, but if you're anything like me you'll quickly get tired of adding and removing the comment and the option. We can use some low level $$\TeX{}$$ to make the set-up of our document be based on a variable:
~~~tex
\def\mode{0} % Mode 0 for presentation, mode 1 (or not 0) for a handout.
\if 0\mode
	\documentclass{beamer}
\else
	\documentclass[handout]{beamer}
	\usepackage{handoutWithNotes}
	\pgfpagesuselayout{3 on 1 with notes}[a4paper] 
\fi
~~~

Let's go through this slowly. In the first line we define a variable called mode and set its value equal to the number 0 using `\def\mode{1}`{:.highlight.language-tex}. We then use the built-in $$\TeX{}$$ `if` command (this commmand is detailed further [here][texif]) to test the variable against the constant 0. This works by expanding the 'token' `\mode` and comparing it to the token `0`. If they are equal, then we are building the actual slides with transitions, and we execute the first block, `\documentclass{beamer}`{:.highlight.language-tex}. If they are not equal, then we are creating the handout and we use the `\else` command to instead execute the second set of commands, passing the handout option to the document class and setting the '3 on 1' pages option using `\pgfpages`. Finally, all $$\TeX{}$$ `\if` commands have to finish with a closing `\fi`. Clearly, one can easily extend this trick to test our `\mode` token against other values, setting up the document class options differently for each different mode.

We can now easily switch between creating clean handouts with space for our notes by setting `\mode` to be 1 (or anything other than 0) on the first line, or create our usual slides with transitions by setting the `\mode` to 0.

[Beamer]:http://tug.ctan.org/macros/latex/contrib/beamer/doc/beameruserguide.pdf
[ShareLaTeX]:https://www.sharelatex.com/learn/Beamer
[handoutWithNotes]:https://www.guidodiepen.nl/2009/07/creating-latex-beamer-handouts-with-notes/
[github]:https://github.com/gdiepen/latexbeamer-handoutWithNotes
[StackExchange]:https://tex.stackexchange.com/questions/6582/how-can-i-distribute-beamer-overlayareas-in-handout-mode-across-multiple-frames/272552#272552
[texif]:https://en.wikibooks.org/wiki/TeX/if