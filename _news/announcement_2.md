---
layout: post
title: Project pages up and running and now more mobile friendly
date: 2018-06-13 12:51:10+0100
inline: false
---
One of the uses this site was designed for, was as a place to host a page describing available undergraduate projects. This part of the site is now live, and can be accessed from the navigation at the top of the page, or from [here][projects]. While adding this part of the site, I also tried to check that everything works nicely on mobile and touch based devices, so please let me know if you find any problems using this site on any device.

***

While I intend to write a couple of longer posts detailing the technical side of creating this site, for the time being I want to make a note about the main [projects] page. On larger devices each project (though there is only one for the time being) has a wide link to the detailed description of the project, and this link contains both an image of the picture as well as the project title and a short description. As one moves a mouse over any part of this link, the link area gains a light gray shading to indicate the fact that it is a link. On mobile/smaller devices, the first issue is that wide layout does not work well, and so the image and title/description areas are split onto separate lines. This causes the potential issue that the user does not realise where/if they are able to click to find out more information. I therefore added the gray shading permanently on devices that are touch based using the following css hover media query:
~~~css
@media (hover: none) {
	background-color: rgba($grey-color-dark,0.1);
}
~~~
I decided to use the hover query rather than a device width query, as even a user of a larger iPad-like device might not realise that the project link can be clicked, as they don't have the ability to hover over it. 

[projects]:http://www.maths.dur.ac.uk/~sxwc62/projects/