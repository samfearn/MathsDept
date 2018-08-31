---
---
$(document).ready ->
	diagram = $("#diagram")
	obj = new MathJaxObject "mathjaxSource"
	obj.appendTo diagram
	obj.translate 100, 200