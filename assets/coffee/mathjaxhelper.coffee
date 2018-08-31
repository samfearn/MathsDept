---
---
class MathJaxObject

    constructor: (@divId) ->
        @scale=0.02
        @source = $("##{@divId}").find ".MathJax_SVG"
        @svg = @source.find "svg"
        g = @svg.find "g"
        @group = $(g[0]).clone()
        @translate 0, 0

    viewBox: -> @svg[0].viewBox

    width: -> @scale * @viewBox().baseVal.width

    height: -> @scale * @viewBox().baseVal.height

    translate: (@dx, @dy) ->
        dy = @dy + (-@scale * @viewBox().baseVal.y)
        @group[0].setAttribute "transform", 
            "translate(#{@dx} #{dy}) scale(#{@scale}) matrix(1 0 0 -1 0 0)"

    appendTo: (diagram) ->
        diagram.append @group