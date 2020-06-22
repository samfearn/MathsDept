---
layout: page
title: talks
permalink: /talks/
description: A selection of recent talks.
navinclude: false
---

This page is still a work in progress.

A few of the recent talks I've given have been using [reveal.js], which is a framework for building presentations for the web. The presentation is written in html, styled with css, and turned into interactive slides using a javascript library. I'm making these talks available here. If you like to know more about how these talks were made, you can either look at the source on [github], or [ask me].

Some of these talks have a two-dimensional layout, with slides both below and to the right of the current slide. Press `o` on your keyboard to see the full outline of the talk.

<ul class="post-list">
  {% for talk in site.talks %}
    <li>
      <h2><a class="post-title" href="{{ talk.url | prepend: site.baseurl }}">{{ talk.title | markdownify | remove: '<p>' | remove: '</p>' }}</a></h2>
	  <p class="post-meta">{{ talk.event | markdownify | remove: '<p>' | remove: '</p>' }}</p>
	  <p class="post-meta">{{ talk.date | date: '%B %-d, %Y' }}</p>
      <p>{{ talk.description | markdownify | remove: '<p>' | remove: '</p>' }}</p>
    </li>
  {% endfor %}
</ul>

[reveal.js]:https://revealjs.com
[github]:https://github.com/samfearn/MathsDept
[ask me]:mailto:s.m.fearn@durham.ac.uk