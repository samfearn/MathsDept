---
layout: page
title: Games and Codes
module: Project III
description: We consider some mathematical games and the error-correcting codes which describe their winning strategies.
img: /assets/img/smarties.jpg
current: false
hidden: false
academicYear: 2019/20
---
Description
-----------
Impartial games are two player games, whose allowable moves depend only on the current state of the game, and not on the player whose turn it is. Although the games you are most familiar with probably do not fall into this class of games, there are many [interesting games][sprouts] which do. For games where only a finite number of moves are possible, we can then ask which player should win from any given position, assuming both players know the ideal strategies. Furthermore, what exactly are the strategies we should follow to win? For certain games, these strategies can be described in terms of linear error correcting codes.

In general, an [error correcting code] describes a way in which messages can be encoded before being transmitted. The resulting message is resilient to changes which may occur during transmission. By this, we mean that the received communication can be correctly decoded, even when it contains some errors. Many different such codes exist, and the best code to use for any given task depends on the specific requirements of the situation.

In this project, we will begin by studying some examples of impartial games. We will learn how to describe the different positions of such games, and from this begin to develop strategies to win these games. We will see how the strategies for certain games may be described in terms of particularly interesting examples of error correcting codes, such as the [Golay codes]. 

<div class="img_row">
	<a title="Piles of sweets" href="https://www.flickr.com/photos/sneeu/3202317738/in/photostream/"><img class="col one left" alt="Piles of smarties, edited background colour" src="{{ '/assets/img/smarties.jpg' | prepend: site.baseurl | prepend: site.url }}"></a>
	<a title="A Basis for the Extended Binary Golay Code" href="https://blogs.ams.org/visualinsight/2015/12/01/golay-code/"><img class="col one left" alt="This animation displays a basis for the extended binary Golay code using the geometry of the great dodecahedron." src="https://blogs.ams.org/visualinsight/files/2015/12/golay_egan.gif"></a>
   <a title="A Mock Turtle from Alice in Wonderland, by John Tenniel" href="https://commons.wikimedia.org/wiki/File:Alice_par_John_Tenniel_34.png"><img class="col one left" alt="A picture of a mock turtle from Lewis Carroll's Alice in Wonderland, drawn by John Tenniel." src="https://upload.wikimedia.org/wikipedia/commons/9/9a/Alice_par_John_Tenniel_34.png"></a>
</div>
<div class="col three caption" markdown="span">
    On the left we have some piles of sweets, representing a 7 pile mathematical heap game. In the middle, the extended binary Golay code is captured by the geometry of the great dodecahedron. On the right, a mock turtle from Alice in Wonderland, representing another impartial game.
</div>

***

 
Prerequisites
-------------

Algebra II is a prerequisite for this project. Those students who are also studying Cryptography and Codes III will likely find this helpful, though this is not a requirement.

Resources
----------
* J. H. Conway, [On Numbers and Games]
* E. R. Berlekamp, J. H. Conway &amp; R. K. Guy, [Winning ways for your mathematical plays]
* W. C. Huffman &amp; V. Pless, [Fundamentals of error correcting codes]
* J. H. Conway &amp; N. J. A. Sloane, [Sphere Packings, Lattices and Groups]

[Sphere Packings, Lattices and Groups]:http://library.dur.ac.uk/search~S1?/Yconway+sphere+packings&searchscope=1&SORT=D/Yconway+sphere+packings&searchscope=1&SORT=D&SUBKEY=conway+sphere+packings/1%2C2%2C2%2CE/frameset&FF=Yconway+sphere+packings&searchscope=1&SORT=D&2%2C2%2C
[On Numbers and Games]:http://library.dur.ac.uk/search~S1?/Yconway+games&searchscope=1&SORT=D/Yconway+games&searchscope=1&SORT=D&SUBKEY=conway+games/1%2C3%2C3%2CE/frameset&FF=Yconway+games&searchscope=1&SORT=D&1%2C1%2C
[Winning ways for your mathematical plays]:http://library.dur.ac.uk/search~S1?/Ywinning+ways&searchscope=1&SORT=DZ/Ywinning+ways&searchscope=1&SORT=DZ&extended=1&SUBKEY=winning+ways/1%2C37%2C37%2CE/frameset&FF=Ywinning+ways&searchscope=1&SORT=DZ&3%2C3%2C
[Fundamentals of error correcting codes]:http://library.dur.ac.uk/search~S1?/Yfundamentals+of+error+correcting&searchscope=1&SORT=DZ/Yfundamentals+of+error+correcting&searchscope=1&SORT=DZ&extended=1&SUBKEY=fundamentals+of+error+correcting/1%2C5%2C5%2CE/frameset&FF=Yfundamentals+of+error+correcting&searchscope=1&SORT=DZ&1%2C1%2C
[Golay codes]:https://blogs.ams.org/visualinsight/2015/12/01/golay-code/
[sprouts]:https://nrich.maths.org/2413
[error correcting code]:https://plus.maths.org/content/error-correcting-codes