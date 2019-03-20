---
layout: page
permalink: /playground/
title: playground
description: Test ground for new stuff.
navinclude: false
numbas: 
  enabled: false
  <!-- custom_script: homogeneousode.js -->

---
This page currently exists as a jekyll page, but is excluded from the list of pages which get built into the navbar. This page isn't really meant to be being read by anyone at the moment, it's just a space for me to test things for the site.

<script src="{{ '/~sxwc62/assets/coffee/mathjaxhelper.js' }}"></script>
<script type="text/x-mathjax-config">
    MathJax.Hub.Config({
        extensions: ["tex2jax.js", "TeX/AMSmath.js"],
        jax: ["input/TeX", "output/SVG"],
    })
</script>

<script src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=default"></script>

<svg id="diagram" viewBox="0 0 10 10" role="img" aria-labelledby="title desc">
   <title id="title">Circle</title>
   <desc id="desc">Large red circle with a black border</desc>
   <circle cx="2" cy="5" r="1" stroke="black" stroke-width="0.1" fill="red" role="img" aria-labelledby="circdesc1" tabindex="0">
	   <desc id="circdesc1">Testing Aria</desc>
   </circle>
   <circle cx="7" cy="5" r="1" stroke="black" stroke-width="0.1" fill="yellow" role="img" aria-labelledby="circdesc2" tabindex="0">
	   <desc id="circdesc2">The second circle</desc>
   </circle>
</svg>
<div id="mathjaxSource">
$\Omega$
</div>
	
<script src="{{ '/~sxwc62/assets/coffee/espresso.js' }}"></script>

<!-- <iframe src="{{ '/~sxwc62/assets/odequestion/index.html' }}" height="700px" width="100%">
  <p>Your browser does not support iframes.</p>
</iframe> -->