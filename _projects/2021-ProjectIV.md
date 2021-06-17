---
layout: page
title: Codes and Lattices
description: Discussing connections between error-correcting codes and unimodular lattices in dimensions up to 24.
img: /assets/img/E8Petrie.png
current: true
hidden: false
module: Project IV
academicYear: 2021/22
---
Description
-----------
Error-correcting codes allow for information to be encoded such that even if a number of errors occur during the transmission of a message, the original message may still be recovered. Linear codes of length $$n$$ are subspaces of $$n$$-dimensional vector spaces over finite fields. Binary linear codes are therefore made of codewords which are length $$n$$ strings of $$0$$s and $$1$$s (the elements of the finite field of two elements). The binary Hamming codes are classic examples of such codes, and the length seven binary Hamming code can transmit 16 different messages in such a way that any one symbol-error that occurs during transmission of the message can be corrected. It can be shown that no code of length seven which can correct a single symbol-error can encode more messages than this, and this code is known as a perfect code.

Starting from the binary Hamming code of length seven, which we may think of as a particular subspace of $$\mathbb{Z}_2^7$$, we can construct an exceptional lattice in eight real dimensions, known as the $$E8$$ lattice.

In general, a (real) lattice describes a discrete set of points in $$\mathbb{R}^n$$, and we say the lattice has rank $$k$$ if the lattice is the span of $$k$$ linearly independent basis vectors. We may think of the lattice as dividing the underlying real space into cells, where the fundamental cell is the parallelepiped whose edges are described by the basis vectors. A lattice is integral if the inner product of any two basis vectors is an integer, and unimodular (or self-dual) if it is integral and the volume of the fundamental cell is equal to one.

Famous examples of unimodular lattices include the $$E8$$ lattice mentioned previously, as well as the Leech lattice. As well as exhibiting many connections to interesting mathematical topics  (including group theory, number theory and the mathematical physics of Conformal Field Theory and String Theory), the $$E8$$ and Leech lattices are known to describe the most effective ways of packing (hyper)spheres into $$8$$- and $$24$$-dimensional space respectively ([see here for an interesting and accessible article on this][SpherePacking]).

In this project we will first describe how binary codes can give rise to lattices, and discuss particularly important lattices known as root lattices. We will then discuss the classification of unimodular lattices in dimensions up to 24, and see how certain codes (including the famous extended binary Golay code, and the hexacode) appear in the construction of these lattices. 

<div class="img_row">
	 <a title="Gunther, Public domain, via Wikimedia Commons" href="https://commons.wikimedia.org/wiki/File:Fano_plane.svg"><img class="col one left" alt="The Fano plane" src="https://upload.wikimedia.org/wikipedia/commons/thumb/a/af/Fano_plane.svg/512px-Fano_plane.svg.png"></a>
	 <a title="I, Jonathunder, CC BY-SA 3.0 &lt;http://creativecommons.org/licenses/by-sa/3.0/&gt;, via Wikimedia Commons" href="https://commons.wikimedia.org/wiki/File:Animated-HCP-Lattice.gif"><img class="col one left" alt="An animation of the construction of the laminated lattice A3." src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/32/Animated-HCP-Lattice.gif/512px-Animated-HCP-Lattice.gif"></a>
	<a title="The E8 root system." href="https://commons.wikimedia.org/wiki/File:E8Petrie.svg"><img class="col one left" alt="This picture shows a projection of the E8 root system into the Coxeter plane. Image by Jgmoxness." src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/14/E8Petrie.svg/512px-E8Petrie.svg.png"></a>
</div>
<div class="col three caption" markdown="span">
    On the left is the Fano plane, whose lines describe the weight 3 codewords of the length 7 binary Hamming code. The middle animation shows the first stage of the construction of the root lattice $$A_3$$ as a laminated lattice. The image on the right shows a projection of the root lattice $$E_8$$, which is the first unimodular lattice we discuss.
</div>

***

 
Prerequisites
-------------

Algebra II is a prerequisite for this project. Cryptography and Codes III will be beneficial to this project, but it is not a compulsory prerequisite. Students taking this project will also be expected to have a good understanding of linear algebra.

Resources
----------
* W. Ebeling, [Lattices and Codes]
* J. H. Conway &amp; N. J. A. Sloane [Sphere Packings, Lattices and Groups]
* W. C. Huffman &amp; V. Pless, [Fundamentals of error correcting codes]

***

[Lattices and Codes]:https://library.dur.ac.uk/search~S1?/Yhirzebruch+lattices&searchscope=1&SORT=D/Yhirzebruch+lattices&searchscope=1&SORT=D&SUBKEY=hirzebruch+lattices/1%2C2%2C2%2CE/frameset&FF=Yhirzebruch+lattices&searchscope=1&SORT=D&1%2C1%2C
[Sphere Packings, Lattices and Groups]:http://library.dur.ac.uk/search~S1?/Yconway+sphere+packings&searchscope=1&SORT=D/Yconway+sphere+packings&searchscope=1&SORT=D&SUBKEY=conway+sphere+packings/1%2C2%2C2%2CE/frameset&FF=Yconway+sphere+packings&searchscope=1&SORT=D&2%2C2%2C
[SpherePacking]:https://www.quantamagazine.org/sphere-packing-solved-in-higher-dimensions-20160330
[Fundamentals of error correcting codes]:http://library.dur.ac.uk/search~S1?/Yfundamentals+of+error+correcting&searchscope=1&SORT=DZ/Yfundamentals+of+error+correcting&searchscope=1&SORT=DZ&extended=1&SUBKEY=fundamentals+of+error+correcting/1%2C5%2C5%2CE/frameset&FF=Yfundamentals+of+error+correcting&searchscope=1&SORT=DZ&1%2C1%2C