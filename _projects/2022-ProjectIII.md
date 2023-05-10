---
layout: page
title: STACKing Codes - Automated Assessment in Higher Mathematics 
description: We will learn how to use modern automated assessment tools to prepare materials for courses in higher mathematics.
img: /assets/img/STACK-logo.png
current: false
hidden: false
module: Project III
academicYear: 2022/23
---
Description
-----------
It is often said that one of the best ways to gain a deep understanding of a topic is to teach it to somebody else. In this project, we will apply this maxim to a 3H mathematics course, designing automated assessment materials suitable for other students to use to help them learn the course. We will use the topic of [error-correcting codes][linear codes] (see also [this excellent book][PlessFundamentals]) as an example course, though it is not necessary to also be taking the Cryptography and Codes course.

Automated assessment is a powerful teaching tool, enabling learners to test their own understanding without the requirement of an external marker. This allows students to get feedback at a pace that would be unfeasible without the use of such tools. This is turn allows for students to immediately test whether they have understood the feedback and hence better understood the material - this is sometimes known as closing the feedback loop. This style of assessment is known as formative assessment (or assessment for learning), as opposed to summative assessment (or assessment of learning). However, producing automated assessments can be challenging, requiring both the pedagogical skills to know what sorts of errors to check for and what feedback to give, as well as the technical skills to produce an assessment capable of checking for these errors. 

In this project we will use a tool called [STACK], which in turn uses a computer algebra system known as [Maxima], in order to assess students' answers to the questions we design, and to produce feedback which the students can then use to help develop their knowledge. We will consider what makes for an effective formative assessment, as well as how to provide useful feedback to a student - pedagogical skills which are important in teaching, beyond producing automated assessments. Students taking this project will choose a topic from coding theory to learn about, and produce an assignment designed to support other students in learning about this topic.

<div class="img_row">
	 <a title="A diagram showing the data bits and redundancy bits of the (7,4) Hamming code. Image by Cburnett, CC BY-SA 3.0, via Wikimedia Commons" href="https://commons.wikimedia.org/wiki/File:Hamming(7,4).svg"><img class="col one left" alt="A diagram showing the data bits and redundancy bits of the (7,4) Hamming code." src="https://upload.wikimedia.org/wikipedia/commons/thumb/b/b0/Hamming%287%2C4%29.svg/256px-Hamming%287%2C4%29.svg.png"></a>
	<a title="The logo of the Maxima computer algebra system. Image by Jaime Villate, CC BY 4.0, via Wikimedia Commons" href="https://commons.wikimedia.org/wiki/File:Maxima-new.svg"><img class="col one left" alt="The logo of the Maxima computer algebra system." src="https://upload.wikimedia.org/wikipedia/commons/thumb/4/4a/Maxima-new.svg/128px-Maxima-new.svg.png"></a>
	<a title="The logo of the STACK automated assessment system." href="https://stack-assessment.org"><img class="col one left" alt="The logo of the STACK automated assessment system." src="{{ '/assets/img/stacklogo.png' | prepend: site.baseurl | prepend: site.url }}"></a>
</div>
<div class="col three caption" markdown="span">
    On the left we have a diagram showing the data bits and redundancy bits of the (7,4) Hamming code, representing a topic in coding theory which we could write assessment materials for. The middle image shows the logo of the Maxima computer algebra system, which we will use to be able to check students' answers to the questions we prepare. The image on the right shows the logo of the automated assessment system STACK, which is the tool we will use to prepare and deliver our assessments.
</div>

***

 
Prerequisites
-------------

Algebra II is a prerequisite for this project. Students taking this project will also be expected to have a good understanding of linear algebra. This project will also require some programming in a system called Maxima - no prior experience of Maxima is necessary.

Resources
----------
* W. Cary Huffman &amp; Vera Pless [Fundamentals of Error-Correcting Codes][PlessFundamentals]
* T. Lowe, C. Sanguin &amp; I. Jones [Getting started with STACK]
* The [STACK docs]
* The [Maxima Manual]

***

[Maxima]:https://maxima.sourceforge.io
[STACK]:https://stack-assessment.org
[PlessFundamentals]:https://library.dur.ac.uk/search/?searchtype=Y&searcharg=pless+fundamentals&searchscope=1&submit.x=0&submit.y=0&submit=Search
[linear codes]:https://en.wikipedia.org/wiki/Linear_code
[Getting started with STACK]:http://docs.stack-assessment.org/content/2019-STACK-Guide.pdf
[STACK docs]:http://docs.stack-assessment.org/en/
[Maxima Manual]:https://maxima.sourceforge.io/docs/manual/index.html
