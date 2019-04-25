---
layout: post
date: 2019-04-25 00:44:32+0100
inline: false
title: "Feature Update -- AnchorJS and bigfoot"
---
At some point I'd like to write a third post in my series of posts about how I built this website, detailing some of the features I've enabled for the site and how I set them up. Until I get around to writing that, I'll just make news posts when I add or update a feature to remind myself what I've changed.

I originally added AnchorJS to the site in order to easily link to particular sections of the long posts on setting up the site. This worked at some point, but I realised today that it was broken. After a while of testing it turned out that I was trying to load AnchorJS and add my anchor tags too early on my pages, and so the Javascript was being called before the DOM had actually finished being built. The [AnchorJS page] even gives an example of how to best call the relevant function, so I just followed the instructions here -- I don't know why I didn't do that originally :see_no_evil:.

Secondly, although the markdown parser my site uses, [kramdown], has [support for footnotes][kramdownfootnote], I like footnotes on webpages to pop-up in place to save having to scroll up and down the page as you read them. In order to enable this style of footnotes on my site I added [bigfoot], a Javascript library designed to do exactly this. The bigfoot download comes with an [scss] style file which I included along with my other stylesheets, and a javascript file which I added into the assets folder for my site. This script is loaded in one of my template include files, alongside all the other javascript I load for the site. Bigfoot footnotes can then be added just by using the kramdown footnote syntax `[^1]` and placing the footnote at the bottom of the markdown file like a reference link [^1]. These work nicely on mobile, and fall back to footnotes at the bottom of the page if Javascript is disabled [^2].

[^1]: Like this. 
[^2]: There actually seems to be a small bug in my current set up where following the footnote link causes the footnote number to disappear, and following the return link adds a line break. I'll probably try to fix this at some point, but I'm going to work on the assumption that most people accessing the site will be using javascript and therefore this isn't very high priority. 


[AnchorJS page]:https://www.bryanbraun.com/anchorjs/#dont-run-it-too-late
[kramdown]:https://kramdown.gettalong.org/index.html
[kramdownfootnote]:https://kramdown.gettalong.org/syntax.html#footnotes
[bigfoot]:http://www.bigfootjs.com
[scss]:{{ site.baseurl }}{% post_url 2018-07-20-buildingthesite1 %}#sass
[javascript]:{{ site.baseurl }}{% post_url 2018-07-20-buildingthesite1 %}#javascript