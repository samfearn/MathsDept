---
layout: page
title: Self-Dual Codes
description: We study the possible weight distributions of self-dual codes, and consider classifications of such codes up to equivalence.
img: /assets/img/golay_egan.gif
current: true
hidden: false
module: Project IV
academicYear: 2023/24
---
Description
-----------
Error-correcting codes allow for information to be encoded such that even if a number of errors occur during the transmission of a message, the original message may still be recovered. Linear codes of length $$n$$ are subspaces of $$n$$-dimensional vector spaces over finite fields. These codes may be equipped with an inner-product, valued in the underlying field, which allows us to define the dual of a code as the set of vectors in the underlying vector space which have an inner-product of zero with every word of our code. A code is known as self-orthogonal if it is contained within its dual code, and self-dual if it is equal to its dual code.

In this project, we will first study some particular examples of self-dual codes (such as the [extended binary Golay code]), before moving on to consider some general results constraining the possible weight-distributions of such codes. We will then consider examples of so-called 'mass formulas' for codes, which provide a method for counting all inequivalent codes of a given type, and use this result to investigate the classification of codes of these types up to equivalence.

Not only are many notable codes self-dual, such codes also have very interesting connections to other mathematical topics such as modular forms, often via associated (real) unimodular lattices, and these are topics a student on this project might choose to investigate further. Famous examples of unimodular lattices include the $$E8$$ lattice, as well as the Leech lattice, which are known to describe the most effective ways of packing (hyper)spheres into $$8$$- and $$24$$-dimensional space respectively ([see here for an interesting and accessible article on this][SpherePacking]). 

<!-- 
Given a binary code, one can construct a discrete subgroup of $$\mathbb{R}^n$$ known as a (real) lattice. We say the lattice has rank $$k$$ if the lattice is the span of $$k$$ linearly independent basis vectors. We may think of the lattice as dividing the underlying real space into cells, where the fundamental cell is the parallelepiped whose edges are described by the basis vectors. A lattice is integral if the inner product of any two basis vectors is an integer, and unimodular (or self-dual) if it is integral and the volume of the fundamental cell is equal to one. 

In this project we will first describe how binary codes can give rise to lattices, and discuss particularly important lattices known as root lattices. We will then discuss the classification of unimodular lattices in dimensions up to 24, and see how certain codes (including the famous extended binary Golay code, and the hexacode) appear in the construction of these lattices.
-->

<div class="img_row">
	 <a title="The Fano Plane: Gunther, Public domain, via Wikimedia Commons" href="https://commons.wikimedia.org/wiki/File:Fano_plane.svg"><img class="col one left" alt="This picture shows the Fano plane" src="https://upload.wikimedia.org/wikipedia/commons/thumb/a/af/Fano_plane.svg/512px-Fano_plane.svg.png"></a>
	 <a title="Extended Hamming Code: Cburnett, CC BY-SA 3.0, via Wikimedia Commons" href="https://commons.wikimedia.org/wiki/File:Hamming(8,4).svg"><img class="col one left" alt="This diagram depicts the data bits and check bits for the extended [8,4] binary Hamming code." src="https://upload.wikimedia.org/wikipedia/commons/1/13/Hamming%288%2C4%29.svg"></a>
	 <a title="Icosahedron: Cyp, CC BY-SA 3.0, via Wikimedia Commons" href="https://commons.wikimedia.org/wiki/File:Icosahedron.gif"><img class="col one left" alt="An animation of a rotating icosahedron." src="https://upload.wikimedia.org/wikipedia/commons/e/e2/Icosahedron.gif"></a>
	
</div>
<div class="col three caption" markdown="span">
    On the left is the Fano plane, whose lines describe the weight 3 codewords of the length 7 binary Hamming code. The middle diagram depicts the data bits and check bits for the extended $[8,4]$ binary Hamming code. The animation on the right shows an icosahedron, which may be used to construct the extended binary Golay code.
</div>

***

 
Prerequisites
-------------

Codes and Cryptography III is a prerequisite for this project. Students taking this project will also be expected to have a good understanding of linear algebra.

Resources
----------
* W. C. Huffman &amp; V. Pless, [Fundamentals of error correcting codes]
* W. Ebeling, [Lattices and Codes]
* J. H. Conway &amp; N. J. A. Sloane [Sphere Packings, Lattices and Groups]

***

[extended binary Golay code]: https://blogs.ams.org/visualinsight/2015/12/01/golay-code/
[Lattices and Codes]:https://library.dur.ac.uk/search~S1?/Yhirzebruch+lattices&searchscope=1&SORT=D/Yhirzebruch+lattices&searchscope=1&SORT=D&SUBKEY=hirzebruch+lattices/1%2C2%2C2%2CE/frameset&FF=Yhirzebruch+lattices&searchscope=1&SORT=D&1%2C1%2C
[Sphere Packings, Lattices and Groups]:http://library.dur.ac.uk/search~S1?/Yconway+sphere+packings&searchscope=1&SORT=D/Yconway+sphere+packings&searchscope=1&SORT=D&SUBKEY=conway+sphere+packings/1%2C2%2C2%2CE/frameset&FF=Yconway+sphere+packings&searchscope=1&SORT=D&2%2C2%2C
[SpherePacking]:https://www.quantamagazine.org/sphere-packing-solved-in-higher-dimensions-20160330
[Fundamentals of error correcting codes]:http://library.dur.ac.uk/search~S1?/Yfundamentals+of+error+correcting&searchscope=1&SORT=DZ/Yfundamentals+of+error+correcting&searchscope=1&SORT=DZ&extended=1&SUBKEY=fundamentals+of+error+correcting/1%2C5%2C5%2CE/frameset&FF=Yfundamentals+of+error+correcting&searchscope=1&SORT=DZ&1%2C1%2C