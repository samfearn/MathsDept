---
layout: post
title: An addendum to the previous post on xparse and Ti*k*Z
description: Adding additional features to `\pascalRows{n}`
date: 2018-10-16 23:35:48+0100
comments: true
categories:
  - LaTeX
---
Two posts in as many days, a first!

## New Stuff in pascalRows ##

After writing the [previous post][prevpost] on using [xparse] and [Ti*k*Z][Tikz] to create mini [Galton boards][Galton board] for a worksheet, I decided to add an additional feature to the function. We wanted to add space for students to write down the possible sequences of 'Left' and 'Right' that a ball could have bounced through the Galton board to get to any given position. The final output for this looks like the following:

{% lightimg {"alt":"An output Galton board with 3 rows, buckets and answer rows.", "img":"3_row_Pascal_with_answer_rows.pdf", "img_class":"postimage two"} %}

The code is now given by:

~~~tex
\usepackage{tikz}
\usepackage{xparse}
\usepackage{xintexpr}

\NewDocumentCommand{\pascalRows}{s t_ O{0.5} m}{
	%the xparse package makes available the \NewDocumentCommand.
	% This is similar to the \newcommand, though the format for
	% arguments is different and much more powerful than \newcommand.
	% The above formatting of arguments means that we define a
	% starred arguent as the first argument which is \BooleanTrue
	% if we call a starred version of \pascalrows*{}. The second
	% argument is also boolean with value \BooleanTrue if we call
	% the function with an underscore before the argument names
	% as in \pascalRows_{n} and value \BooleanFalse otherwise.
	% The third argument is an optional argument with default value
	% 0.5 which is being used to pick a default scale. There is
	% then a final mandatory argument which controls the number
	% of rows of `pegs' which should be drawn in the diagram.
	\edef\bin{\xinttheiiexpr binomial(#4,#4//2)\relax}
	\begin{tikzpicture}[scale=#3]
		% Draw the start of the outside edges, as we have these
		% bits independent of the number of rows we want 
		\draw[-] (-1/2,0) -- (-1,-1);
		\draw[-] (1/2,0) -- (1,-1);
		% Draw the rest of the outside edges
		\draw[-] (-1,-1) -- (-1 - #4,-1 - #4*2);
		\draw[-] (1,-1) -- (1 + #4,-1 - #4*2);
		% Draw the diamonds which represent the pins
		% Each row needs rownumber diamonds
		\foreach \y in {1,...,#4}
		{
			\foreach [evaluate=\loopx as \x using 2*\loopx-1-\y] \loopx in {1,...,\y}
			{
				\fill[gray] (\x,1 - \y*2) -- (\x-1/2, -\y*2) -- (\x,-1 - \y*2) -- (\x+1/2,- \y*2) -- (\x,1 - \y*2);
			}
		}
		% Optionally, draw 'buckets' for the answers.
		% This command is also part of the xparse package.
		% It tests the first argument, the one which is a
		% boolean coressponding to whether we call a starred
		% version of \pascalRows or an un-starred version.
		% If we want both buckets and answer rows, then the
		% answer rows need shifting vertically one unit
		\edef\bucketyshift{0}
		\IfBooleanF {#1}
		{
			% We have buckets, so shift answer rows one unit if they exist
			\edef\bucketyshift{1}
			% Draw the buckets
			\foreach [evaluate=\loopx as \x using 2*\loopx-#4] \loopx in {0,1,...,#4}
			{
				\draw[-] (\x-1/2,-1-#4*2) -- (\x-1/2,-2-#4*2) -- (\x+1/2,-2-#4*2) -- (\x+1/2,-1-#4*2);
			}
		}
		% If we have an underscore as the second argument then
		% we want to draw answer rows. We need nC(n//2) of them
		% using choose notation and floored division. This
		% binomial coefficient is saved in the \bin variable.
		\IfBooleanT {#2}
		{
			\foreach [evaluate=\loopy as \y using -\loopy-#4*2-1-\bucketyshift]\loopy in {1,...,\bin}
			{
				\foreach [evaluate=\loopx as \x using 2*\loopx-#4] \loopx in {0,1,...,#4}
				{
					\draw[-] (\x-1/2,\y) -- (\x+1/2,\y);
				}
			}
		}
	\end{tikzpicture}}
~~~
{:.anchored id="Latex1"}

## The New Code ##

Drawing the lines on which to write the paths is done simply by using some basic paths as in the previous version of the code. One of the two main challenges here was getting my function to automatically compute the number of rows it needed to draw. Since this is going to be the same as the largest binomial coefficient corresponding to the final row, which will always be the middle coefficient(s) of the row, we need $$\binom{n}{\left \lfloor{n/2}\right \rfloor }$$ (where $$\left \lfloor{n/2}\right \rfloor$$ denotes the floor of $$n/2$$) rows. Note that although this code does work for general n (within reason), no effort has been made to page break after a large number of rows, or to scale the horizontal lengths of the sections of the answer row to take into account how many binary 'decisions' were made to end up at any given final point.

To compute the required number of rows, we use 

~~~tex
\edef\bin{\xinttheiiexpr binomial(#4,#4//2)\relax}
~~~
{:.anchored id="Latex2"}

The `\edef\bin` command says that we are going to define a new quantity called `\bin` which is given by the expanded form of the argument that follows. By expanded, we basically mean that this argument is first fully evaluated and then saved into the expression `\bin`. In our case, we use the binomial function from the xintexpr package, which according to the [documentation][xintexpr], needs to be contained in between the commands `\xinttheiiexpr` and `\relax`. We can also easily do the floor of $$n/2$$, as the xintexpr package supports floored division using the `//` operator.

The main other notable point in the new code is that the choice as to whether to draw the answer rows is made by using another decoration on the function name. I'm not really sure if this is the cleanest way to have implemented this, but when I saw that I could use underscore as a decoration, I decided that since the answer rows underscore the picture it would be visually nice to do it this way. The structure argument to `/NewDocumentCommand` is now given by `{s t_ O{0.5} m}`. The first argument is the same as before, the second argument of type `t` is our new decoration, specified as the underscore, which is `\BooleanTrue` if the underscore is present. The two decorations can be used in conjunction, but if they both appear, the star must go first, as in `\pascalRows*_{3}`.

The remaining new code should now be fairly self explanatory if you followed the explanation given in the [previous post][prevpost]. Note that one more expression is defined using `\edef\bucketyshift{0}`, which is a vertical offset to be used in the case when we draw both buckets and answer rows.

This code is now certainly over-engineered, given that I probably only need to create about three pictures, each with a small number of rows and probably all using both buckets and answer rows. However, it was a fun little challenge to code up in $$\LaTeX{}$$ and Ti*k*Z, and has been a good chance to learn a little about complex functions using [xparse] and calculations in $$\LaTeX{}$$ using [xintexpr]. I imagine that even if this code is never used again to create Galton boards, the basic ideas are likely to appear again in code I write in the future.

[prevpost]: {{ '/blog/2018/xparseandtikz/' | prepend: site.baseurl | prepend: site.url }}
[TikZ]: https://www.sharelatex.com/learn/TikZ_package
[xparse]: http://mirror.ox.ac.uk/sites/ctan.org/macros/latex/contrib/l3packages/xparse.pdf
[Celebrate Science]: https://www.dur.ac.uk/celebrate.science/
[random walks]: https://en.wikipedia.org/wiki/Random_walk
[Galton board]: http://galtonboard.com
[xintexpr]: http://anorien.csc.warwick.ac.uk/mirrors/CTAN/macros/generic/xint/xint.pdf