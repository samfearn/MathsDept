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

<div id="jxgbox" class="jxgbox" style="width:500px; height:500px;"></div>

<link rel="stylesheet" type="text/css" href="http://jsxgraph.uni-bayreuth.de/distrib/jsxgraph.css" />
<script type="text/javascript" src="http://jsxgraph.uni-bayreuth.de/distrib/jsxgraphcore.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/pizzicato/0.6.4/Pizzicato.js"></script>

<script type="text/javascript">
		var b = JXG.JSXGraph.initBoard('jxgbox', {boundingbox: [-10, 10, 10, -10], axis:true});
		  b.create('functiongraph', [function(x){return Math.sin(x);},-Math.PI,2*Math.PI]);

		var sawtoothWave = new Pizzicato.Sound({ 
		    source: 'wave',
		    options: {
				frequency: 440,
				volume: 0.2,
		    }
		});
		
		function playSound(){
			sawtoothWave.play();
		}
		
		function stopSound(){
			sawtoothWave.pause();
		}

		console.log(sawtoothWave);
	
		svgDoc = document.querySelector("#jxgbox svg");
		paths = svgDoc.querySelectorAll("g path");
		console.log(paths.length);
</script>
	
<button onclick="playSound()">Start</button>
<button onclick="stopSound()">Stop</button>

<iframe src="https://www.wolframcloud.com/obj/s.m.fearn/Labelled%20Icosahedron" style="width:700px; height:700px; border: 4px solid #657b83;"></iframe>

<iframe src="https://trinket.io/embed/python/e755d551c0?toggleCode=true&runOption=run&start=result" width="100%" height="500" frameborder="0" marginwidth="0" marginheight="0" allowfullscreen></iframe>

<script src="https://cdn.plot.ly/plotly-latest.min.js"></script>

<div id="tester" style="width:600px;height:250px;"></div>

<script>
	TESTER = document.getElementById('tester');
	Plotly.plot( TESTER, [{
	x: [1, 2, 3, 4, 5],
	y: [1, 2, 4, 8, 16] }], {
	margin: { t: 0 } } );
</script>

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