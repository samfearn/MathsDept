---
layout: post
title: Advanced $$\LaTeX{}$$ with xparse and Ti*k*Z
description: Creating mini Galton boards in $$\LaTeX{}$$.
date: 2018-10-15 18:38:56+0100
comments: true
categories:
  - LaTeX
---
## Context ##

My department will be contributing to an outreach event entitled [Celebrate Science] at the end of the month. The event is aimed primarily at 7-11 year olds in order to expose them to some interesting and exciting applications of the STEM subjects (Science, Technology and Mathematics) and the maths department will be organising a stand at the event. I have been designing the departments stand and activities for this event -- with the help of a couple of others from the department -- and this year we will be using [random walks] as our theme. In particular we are going to be using a [Galton board] to give an interactive demonstration of a binomial distribution and linking this to Pascal's triangle. We decided that a nice paper exercise -- after putting some ball bearings down the Galton board -- would be to count how many pathways there were through a Galton board with a small number of rows. We therefore wanted a picture modelling the Galton board to print onto a small worksheet that the kids could use to count the paths, and obviously this should be done in $$\LaTeX{}$$ in order to look professional. The best tool that I know of for producing diagrams in $$\LaTeX{}$$ is [Ti*k*Z][TikZ] and so I wanted to write some Ti*k*Z which could produce these types of diagrams. An example of the output of the code I wrote is below (with more rows than I will be asking students to complete) and the purpose of this post is to explain how this works.

{% lightimg {"alt":"An output Galton board with 8 rows and buckets for students answers", "img":"8_row_Pascal_Triangle_with_buckets.pdf", "img_class":"postimage two"} %}

## The Code ##

The following is written with the intention that the reader knows some basic $$\LaTeX{}$$. If you haven't come across $$\LaTeX{}$$ before, I've written an introductory guide with links to more information [here][latexpost].

The picture is eventually produced using the command `\pascalRows{8}`, which is obviously not too interesting by itself. The more interesting part is the actual definition of `\pascalRows`. I don't claim this is necessarily the best way to achieve what I wanted, only the way that I found to do it. The following should all be placed in the document preamble.

~~~tex
\usepackage{tikz}
\usepackage{xparse}

\NewDocumentCommand{\pascalRows}{s O{0.5} m}{
	% The xparse package makes available the \NewDocumentCommand.
	% This is similar to the \newcommand, though the format for
	% arguments is different and much more powerful than \newcommand.
	% The above formatting of arguments means that we define a
	% starred arguent as the first argument which is \BooleanTrue
	% if we call a starred version of \pascalrows*{}. The second
	% argument is an optional argument with default value 0.5 which
	% is being used to pick a default scale. There is then a final
	% mandatory argument which controls the number of rows of `pegs'
	% which should be drawn in the diagram.
	\begin{tikzpicture}[scale=#2]
		% Draw the start of the outside edges, as we have these bits
		% independent of the number of rows we want 
		\draw[-] (-1/2,0) -- (-1,-1);
		\draw[-] (1/2,0) -- (1,-1);
		% Draw the rest of the outside edges
		\draw[-] (-1,-1) -- (-1 - #3,-1 - #3*2);
		\draw[-] (1,-1) -- (1 + #3,-1 - #3*2);
		% Draw the diamonds which represent the pins
		% Each row needs rownumber diamonds
		\foreach \y in {1,...,#3}
		{
			\foreach [evaluate=\loopx as \x using 2*\loopx-1-\y] \loopx in {1,...,\y}
			{
				\fill[gray] (\x,1 - \y*2) -- (\x-1/2, -\y*2) -- (\x,-1 - \y*2) -- (\x+1/2,- \y*2) -- (\x,1 - \y*2);
			}
		}
		% Optionally, draw 'buckets' for the answers. This command
		% is also part of the xparse package. It tests the first
		% argument, the one which is a boolean corresponding
		% to whether we call a starred version of \pascalRows
		% or an un-starred version.
		\IfBooleanF {#1}
		{
			\foreach [evaluate=\loopx as \x using 2*\loopx-#3] \loopx in {0,1,...,#3}
			{
				\draw[-] (\x-1/2,-1-#3*2) -- (\x-1/2,-2-#3*2) -- (\x+1/2,-2-#3*2) -- (\x+1/2,-1-#3*2);
			}
		}
	\end{tikzpicture}}
~~~
{:.anchored id="Latex1"}

This is my first time using the [xparse] package, and I inevitably have a lot to learn about the best ways to use it. The point of using it in this instance was that it allows more flexibility in the arguments of custom $$\LaTeX{}$$ functions than the default `\newcommand`. Here we are using the xparse command `\NewDocumentCommand`; the first argument of this is the name of the command we want to define, the second is the structure of the arguments for our command, and the third is the actual command itself.

The first thing to discuss is the second argument, the one which specifies the argument structure for our command `\pascalRows`. The format of this argument is that we list the types (and possibly the default values) of each of the arguments in turn. For `\pascalRows` I define the first argument as an `s` type argument, which means that the function is defined to have both a starred and un-starred variant, so we call call `\pascalRows{n}` or `\pascalRows*{n}`. The first argument is then a boolean with value `True` if we called the starred variant `\pascalRows*{n}` and value False for the un-starred `\pascalRows{n}`. The second argument is specified with a capital `O` to denote an optional argument, and inside the curly braces we can give a default value for this second argument. Finally we have one mandatory argument specified by type `m`. These arguments can then be accessed from inside the definition of the function using `#1`,`#2` and `#3`. In the case of `\pascalRows`, we use the starred argument to decide whether or not to draw 'bins' under the final row of the triangle for students to put their answers in. The optional argument -- with default value 0.5 -- is used to control the scale of the picture, and the mandatory third argument is used to define how many rows should be drawn.

I'll now go through the actual code briefly. Since we want to draw a picture, we need to tell $$\LaTeX{}$$ to start a tikzpicture environment which will be used to define our picture in Ti*k*z code. Since I use explicit coordinate references in the code which follows -- chosen to make the code easier to write -- I use a scale option to the tikzpicture environment to control the actual size of the output. By using `scale=#2`, we set the scale to be the value of the second, optional, argument which had default value 0.5. If we want to enter a value for this optional argument, for instance to make a picture with a 10 rows smaller, we would call it with `\pascalRows[0.25]{10}`.

The first things we actually draw are the outside edges of the triangle. We always want a small piece of edge above the first row, so we draw this first with explicit coordinates (chosen to use the reflection symmetry of the diagram, using (0,0) as the middle of the 'opening' at the top of the triangle). To get the relative scales of the triangle the way I wanted, I was imagining the triangle being drawn on a triangular grid, where the 'x' distance between neighbouring points is 1/2, and the 'y' distance between neighbouring points is 1. The command to do this, for the left hand side for instance, in Ti*k*z is `\draw[-] (-1/2,0) -- (-1,-1);`. The option to `\draw` says what type of line to draw, here we want a solid line with no ends and so we use the option `[-]`. We then give the starting coordinate, two hyphens, and then the end coordinate. Note that all Ti*k*z drawing commands must end in a semicolon. To draw the rest of the edges, we essentially use the same command. This time, the start coordinates are still constant, but the end coordinates depend on how many rows we want to draw. The end coordinates are therefore simple functions of the third variable which details how many rows to draw.

The next section is probably the most complicated part of this function. We use a `\foreach` loop to run over a variables which takes successive values from a list. In our case, the outer loop is for the y coordinates, and we let the variable `\y` run over the list `{1,...,#3}`. The notation means that the list is to start at 1 and go in integer increments up to and including `#3`, the number of rows we want. Inside this loop we have another loop for the x coordinates of the tops of the diamonds that represent the pegs in the Galton board. Let's break this command down:

~~~tex
\foreach \y in {1,...,#3}
{
	\foreach [evaluate=\loopx as \x using 2*\loopx-1-\y] \loopx in {1,...,\y}
	{
		\fill[gray] (\x,1 - \y*2) -- (\x-1/2, -\y*2) -- (\x,-1 - \y*2) -- (\x+1/2,- \y*2) -- (\x,1 - \y*2);
	}
}
~~~
{:.anchored id="Latex2"}

We use the same structure as before, letting the value `\loopx` run over the list `{1,...,\y}`, as there should be the same number of diamonds in each row as the row number of that row -- remember that we build the diamonds one row at a time, as the x loop sits inside the y loop. However, this time we don't want our x-coordinates to be the values `{1,...,\y}`, as we want to use x=0 as the midpoint the diagram. We therefore construct a new variable `\x` as a function of `\loopx` (and `\y`) using the evaluate option of `\foreach`. This function simply scales the list by a factor of 2 -- as that is the distance the top points of our diamonds should have -- and then shifts them by an amount which has to depend on `\y` in order to make the list of values of `\x` symmetric around x=0.

Inside of these nested loops we can then give the command to actually draw our diamonds, whose vertices are now simple functions of the coordinates `\x` and `\y`. We use the Ti*k*z `\fill[gray]` command to specify a path which should have its interior filled in gray. As for the `\draw` command that we used for the edges, we specify one vertex at a time -- choosing to start at the top vertex -- and then specify successive vertices with two hyphens between each pair of vertices. Since we want to create a closed path which can be filled, we need to finish with the same vertex as the one we started on -- the top given our earlier choice of starting vertex.

The final line of interest is `\IfBooleanF {#1}`. Argument one is the boolean which is true iff we called the starred version of our function `\pascalRows`. The block of code following this line therefore only runs if `#1` is false, that is if we called the un-starred version. The remainder of the code works similarly to code already explained; we run over a loop of `\loopx` values (this time from 0 to `#3`) but map these to the values of `\x` that we want to define the top of each bucket. We then draw a simple path of 3 straight edges underneath the bottom row for each value of `\x`.

[xparse] seems much more powerful for defining commands than the default \newcommand. Hopefully this post has taught you something about writing custom commands with xparse and tikz.

[Celebrate Science]: https://www.dur.ac.uk/celebrate.science/
[random walks]: https://en.wikipedia.org/wiki/Random_walk
[Galton board]: http://galtonboard.com
[TikZ]: https://www.sharelatex.com/learn/TikZ_package
[latexpost]: {{ '/blog/2018/latexworksheet/' | prepend: site.baseurl | prepend: site.url }}
[xparse]: http://mirror.ox.ac.uk/sites/ctan.org/macros/latex/contrib/l3packages/xparse.pdf