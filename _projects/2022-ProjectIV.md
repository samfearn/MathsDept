---
layout: page
title: Niemeier Lattices and Moonshine
description: Investigating the connections between Lie algebras, lattices, modular forms, and string theory.
img: /assets/img/A2Weyl.png
current: false
module: Project IV
academicYear: 2022/23
---
Description
-----------
Moonshine describes a series of interesting connections between number theory, algebra and mathematical physics. One series of examples of moonshine is known as [Umbral Moonshine][moonshine], and can be described in terms of a set of lattices known as the Niemeier lattices. In general, a (real) lattice describes a discrete set of points in $$\mathbb{R}^n$$, and the Niemeier lattices are particularly interesting examples of lattices in dimension 24. These lattices may be described in terms of their root lattices, which we will describe via the roots of Lie algebras.

Lie algebras describe the infinitesimal symmetries associated with classical symmetry groups such as $SO(N)$ and $SU(N)$. Though this connection to the associated groups, known as Lie groups, has very interesting geometric meaning, the Lie algebras themselves have a very rich mathematical structure which can be studied independently. Given an algebraic structure such as a group or a Lie algebra, one can try to study the algebraic object using linear algebra, by considering vector spaces on which the algebraic object acts through linear transformations. Such a vector space, along with a description of how the algebraic objects acts on the space, is known as a representation of the algebraic object. In a physical context, representations of Lie algebras appear naturally, as the quantum states of the physical system must form representations of the underlying symmetry algebra of the system.

In this project, we will start by introducing the theory of Lie algebras and their representations. We will see how Lie algebras may be classified by their root systems and the associated Dynkin diagrams. We will see how the root systems of these Lie algebras can be used to construct interesting lattices with connections to many different areas of mathematics and physics. In particular, we will see how the phenomena of [Monstrous and Umbral Moonshine][cheng interview] connect Lie algebras and their associated lattices (using some [linear codes]) to the theory of [modular forms], and the representation theory of some simple sporadic groups (via [string theory] and conformal field theory).
<div class="img_row">
	<a title="A Kummer K3 surface, by Claudio Rocchini" href="https://commons.wikimedia.org/wiki/File:Kummer_surface.png"><img class="col one left" alt="A Kummer K3 surface" src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/3e/Kummer_surface.png/512px-Kummer_surface.png"></a>
	<a title="The E8 root system, by Jgmoxness" href="https://commons.wikimedia.org/wiki/File:E8Petrie.svg"><img class="col one left" alt="This picture shows a projection of the E8 root system into the Coxeter plane" src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/14/E8Petrie.svg/512px-E8Petrie.svg.png"></a>
    <a title="The Klein j-invariant, by Jan Homann" href="https://commons.wikimedia.org/wiki/File:KleinInvariantJ.jpg"><img class="col one left" alt="A plot of the Klein j-invariant in the complex plane, where the colour shows the value of the j function at that point." src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/37/KleinInvariantJ.jpg/512px-KleinInvariantJ.jpg"></a>
</div>
<div class="col three caption" markdown="span">
    On the left we have an image of a $$K3$$ surface. The middle image shows the root system of the Lie algebra $$E8$$. On the right we have a plot of the Klein j-function in the complex plane.
</div>

***

 
Prerequisites
-------------

Algebra II is a prerequisite for this project, and students taking this project will also be expected to have a good understanding of linear algebra. Cryptography and Codes III will be beneficial to the project, but it is not a compulsory pre-requisite. Representation Theory IV will be beneficial to this project, but it is not a compulsory co-requisite.

Resources
----------
* R. N. Cahn, [Semi-Simple Lie Algebras and Their Representations]
* J. P. Serre, [A Course In Arithmetic - Part II]
* P. Di Francesco et al., [Conformal Field Theory]
* J. H. Conway &amp; N. J. A. Sloane [Sphere Packings, Lattices and Groups]

<!-- Additional Week 1 Reading:

* Mark Ronan, [Lie Theory, in the Princeton Companion to Mathematics][LieTheory]
* Terry Gannon, [Moonshine Beyond The Monster, Chapter 0][MoonshineBeyondMonster]
* Brandon Rayhaun, [A nice blog post on Moonshine by a Stanford University Ph.D. student][BrandonBlog] -->

***


[linear codes]:https://en.wikipedia.org/wiki/Linear_code
[modular forms]:http://mathworld.wolfram.com/ModularForm.html
[moonshine]:https://www.quantamagazine.org/mathematicians-chase-moonshine-string-theory-connections-20150312/
[cheng interview]:https://www.quantamagazine.org/moonshine-master-toys-with-string-theory-20160804/
[string theory]:http://whystringtheory.com
[Semi-Simple Lie Algebras and Their Representations]:http://phyweb.lbl.gov/%7Erncahn/www/liealgebras/texall.pdf
[A Course In Arithmetic - Part II]:http://library.dur.ac.uk/search/?searchtype=Y&searcharg=j+p+serre+arithmetic&searchscope=1&submit.x=0&submit.y=0&submit=Search
[Conformal Field Theory]:http://library.dur.ac.uk/search~S1/?searchtype=Y&searcharg=di+francesco+conformal&searchscope=1&sortdropdown=-&SORT=DZ&extended=1&SUBMIT=Search&searchlimits=&searchorigarg=Ydi+francesco
[Sphere Packings, Lattices and Groups]:http://library.dur.ac.uk/search~S1?/Yconway+sphere+packings&searchscope=1&SORT=D/Yconway+sphere+packings&searchscope=1&SORT=D&SUBKEY=conway+sphere+packings/1%2C2%2C2%2CE/frameset&FF=Yconway+sphere+packings&searchscope=1&SORT=D&2%2C2%2C
[LieTheory]:http://library.dur.ac.uk/search~S1?/Yprinceton+companion+mathematics&searchscope=1&SORT=D/Yprinceton+companion+mathematics&searchscope=1&SORT=D&SUBKEY=princeton+companion+mathematics/1%2C4%2C4%2CE/frameset&FF=Yprinceton+companion+mathematics&searchscope=1&SORT=D&3%2C3%2C
[MoonshineBeyondMonster]:http://library.dur.ac.uk/search~S1?/YMoonshine+beyond+the+monster+gannon&SORT=D/YMoonshine+beyond+the+monster+gannon&SORT=D&SUBKEY=Moonshine+beyond+the+monster+gannon/1%2C2%2C2%2CE/frameset&FF=YMoonshine+beyond+the+monster+gannon&SORT=D&2%2C2%2C
[BrandonBlog]:http://www.brandonrayhaun.com/2015/07/19/moonshine-theory-i-symmetry-numbers-and-the-monster/
