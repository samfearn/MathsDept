---
layout: post
date: 2020-07-01 19:06:02+0100
inline: false
title: "Better Categories"
---
All the blog posts on this site are tagged with categories. The only place that these categories were shown was at the top of the post, under the title. However, there was no way to browse posts by these categories, or see a list of all the categories I was using, without browsing through all the separate posts. As well as limiting the readers capability to find posts on the topics of greatest interest to them, I was also finding it difficult to remember what category names I was already using.

In order to combat these issues, I've added a new category filter to the [main blog post page][blog]. This takes the form of a 'Category Filter' button at the top of the page which, when clicked, opens up a menu with buttons for each of the categories in use on the site. Once one of these category buttons is clicked, only posts tagged with that category remain visible. Multiple categories can be selected at once to filter further [^1].

I'm using javascript and CSS transitions to hide the category buttons until the 'Category Filter' button is clicked, and to hide them again if the filter button is clicked again. My understanding is that care is required to ensure that these buttons are also hidden for those using screen-readers, as html elements which are not visible to the eye may still be visible to a screen-reader [^2]. I've tried to ensure that this menu is read properly with a screen-reader, but I'd happily take feedback on this for those with more experience in this area. I'm not sure whether the menu is sufficiently accessible to keyboard input, and I'd be happy to hear comments on this also.

One additional effect of these changes is that it no longer made sense to use the [Jekyll] pagination filter to display posts 5 at a time. This was probably never really necessary due to the currently limited number of total posts on the site. However, now that I've implemented a javascript solution to control the visibility of posts by their category, it would make sense to also use javascript to limit the number of visible posts. I may choose to implement this at a later time if the number if posts becomes sufficiently large. 

<!----------------- -->

[^1]: Posts are only displayed if they are tagged with all of the selected categories. I'm displaying the intersection of the selected categories rather than the union.

[^2]: My understanding is that if an element is hidden using `display:none`, then screen-readers know to ignore the element. However, unfortunately it seems using `display:none` interferes with the CSS transitions I wanted to use. I'm therefore hiding the elements visually using a combination of `visibility: hidden` and `height: 0px`. In particular, I was transitioning the height property of the div containing the category buttons. Since this doesn't stop screen-readers from seeing the buttons, I've added the `aria-hidden: true` attribute to the div containing the buttons. I believe this should hide the buttons from screen-readers, but if someone with more experience wants to correct me I'd be happy to learn more about this. 

<!----------------- -->

[blog]:{{ '/blog' | prepend: site.baseurl | prepend: site.url }}
[Jekyll]: {{ '/blog/2018/buildingthesite1' | prepend: site.baseurl | prepend: site.url }}