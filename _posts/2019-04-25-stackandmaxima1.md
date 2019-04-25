---
layout: post
title: Stack and Maxima -- Part 1
date: 2019-04-25 00:37:42+0100
description: Setting up Maxima for writing Stack questions
categories:
  - e-assessment
  - Stack
  - Moodle
comments: true
---

[![Stack logo]({{ '/assets/img/stacklogo.png' | prepend: site.baseurl | prepend: site.url }}){:.postimage.one.left}][Stack]

As detailed in a previous [news item], I'm interested in exploring e-assessment for formative assessment purposes. I'll probably write more about the *why* of e-assessment later, but for now I want to start discussing the *how* (please don't mention the *when*).

There are a few different e-assessment tools in which I'm particularly interested, namely [Stack] and [Numbas]. Both of these systems have their own strengths and weaknesses which deserve further discussion at a later point, but for the time being I'm going to be focussing on using Stack as it's my current preference.

## Moodle ##

[![Moodle logo]({{ '/assets/img/moodle-logo.png' | prepend: site.baseurl | prepend: site.url }}){:.postimage.one.right}][Moodle]

Stack exists primarily (maybe solely[^1]) as a question-type plugin for the open source VLE [Moodle]. This means that before using Stack, you need to install -- or otherwise have access to -- a Moodle server. Moodle is an open-source (and therefore free) tool, but those with 'an academic interest in using Stack' may request access to a [demo server][Stack Demo] set up by the lead developer of Stack, [Chris Sangwin], in order to test it without having to first install their own Moodle server. If you're going to be running your own Moodle server, once you've installed the Moodle server, you'll then need to install Stack as a plugin. Installation instructions for Stack can be found [here][stackinstall] and instructions for optimising [Maxima](#maxima) can be found [here][optimisingmaxima].

Once Stack is installed on the Moodle server, it's available as a question type and can be integrated into any Moodle quiz. One benefit of this approach [^2] is that Stack questions can be included in quizzes alongside other types of Moodle questions. Examples of how this could be used include: allowing students to submit pictures alongside their mathematical working (for graph theory questions, for example); asking students to write some text after an answer, justifying their solution, or explaining the interpretation; asking students to write computer code to do numerics alongside analytical solutions [^3].

If your institution doesn't already use Moodle as its VLE (at Durham, we use [Blackboard]), Moodle can be set up to act as an LTI provider. This allows other VLEs such as Blackboard to add an individual Moodle quiz -- or a full Moodle course -- as an external tool. Using LTI, students can be logged into the Moodle server automatically and securely (with accounts being created as necessary) and data can then be passed back from Moodles Gradebook to the grade system of the institutional VLE.  

## Maxima ##

[![Maxima logo]({{ '/assets/img/maxima-logo.png' | prepend: site.baseurl | prepend: site.url }}){:.postimage.left}][Maxima]

One of the most powerful features of Stack, is that it is built on top of the Computer Algebra System (CAS) [Maxima] (Née Macsyma). This means when writing Stack questions, you have the tools you may be used to from other computer algebra systems (Mathematica or Maple for example), such as powerful simplification, or symbolic calculus functions. Unlike the two previously mentioned systems however, Maxima is open source and free.

Assuming you want to randomise your questions, a large part of writing a Stack question is writing the Maxima code to generate the randomised question and to test whether a student has the correct answer. Although it's certainly possible to do this by interacting with Maxima only through Stack in the browser, I find it easier to use a local copy of Maxima initially, and then move the code into Moodle as a Stack question once I'm happy with my code. Installation instructions for Maxima are available [here][maximainstall] [^4]. I found the wxMaxima graphical frontend to be the easiest to use as a Maxima beginner due to its variety of tool bars and accessible documentation.

As detailed [here in the Stack documentation][stackrandom], Stack provides its own functions for randomisation. In order to be able to write code locally for use in Stack, we therefore need to make our local copy of Maxima aware of the Stack rand functions. The definitions for these functions can be found -- alongside other Maxima configuration options and Stack specific functions -- in the [Stack GitHub] in the file `stack/maxima/stackmaxima.mac`. In order to make these functions available in your local copy of Maxima, you should create a file with filename `wxmaxima-init.mac` inside the folder `~/.maxima` (create it if it doesn't exist). Inside this file, you will need to copy the section of code from the `stackmaxima.mac` file under the random numbers block heading, as well as the definitions for `simplify(ex)` and `degree(ex,v)`, which appear under the general options block header. In order to make this easier, I've created a [gist with only the required lines of code][wxmaximagist]. This can be placed in the previously mentioned location. This file (`wxmaxima-init.mac`) gets loaded when wxMaxima is opened, so the next time you load wxMaxima you should be able to use the rand functions which Stack defines in your local copy of Maxima.


[^1]: There is [some mention] of Stack being used as a standalone tool, through some API, but I haven't yet found any further mention of this or tried to use said API. 

[^2]: As opposed to [Numbas] for example, which exists separately to any particular VLE. This makes including Numbas questions in a personal website much more simple and doesn't require the additional step of setting up a Moodle instance.

[^3]: For the last year we have been using [CodeRunner] in Durham as part of the assessment for our first year Introduction to Programming module. I will probably write a separate post about CodeRunner at a later date, but since this is also a Moodle question type it can be used alongside Stack very easily.

[^4]: When I first installed Maxima on my Mac, there were some problems getting it to work due to the recent security features. Unfortunately I no longer remember what the fix was for me, but the most recent version of Maxima for Mac includes some troubleshooting instructions which look to work around the problem.

[news item]: {{ '/news/announcement_5/' | prepend: site.baseurl | prepend: site.url }}
[Stack]: https://stack2.maths.ed.ac.uk/demo/question/type/stack/doc/doc.php/
[Numbas]: https://www.numbas.org.uk
[some mention]: https://www.ed.ac.uk/maths/stack/integration
[Moodle]: https://moodle.org
[Chris Sangwin]: https://www.maths.ed.ac.uk/school-of-mathematics/people?person=439
[Stack Demo]:https://www.ed.ac.uk/maths/stack/demo
[stackinstall]:https://stack2.maths.ed.ac.uk/demo/question/type/stack/doc/doc.php/Installation/index.md
[optimisingmaxima]:https://stack2.maths.ed.ac.uk/demo/question/type/stack/doc/doc.php/CAS/Optimising_Maxima.md
[CodeRunner]:https://coderunner.org.nz
[Blackboard]:blackboard.com
[Maxima]:http://maxima.sourceforge.net
[maximainstall]:http://maxima.sourceforge.net/download.html
[stackrandom]:http://fourier.dur.ac.uk/moodle/question/type/stack/doc/doc.php/CAS/Random.md
[Stack GitHub]:https://github.com/maths/moodle-qtype_stack
[wxmaximagist]:https://gist.github.com/samfearn/dc911f365ddb2384f19e6db12413aa99