---
layout: page
title: projects
permalink: /projects/
description: Undergraduate projects available.
---

{% for project in site.projects %}

{% if project.redirect %}
<div class="project">
    <div class="thumbnail">
        <a href="{{ project.redirect }}" target="_blank">
        {% if project.img %}
        <img class="thumbnail" src="{{ project.img | prepend: site.baseurl | prepend: site.url }}"/>
        {% else %}
        <div class="thumbnail blankbox"></div>
        {% endif %}    
        <span>
            <h1 class="no-anchor">{{ project.title }}</h1>
            <br/>
            <p>{{ project.description }}</p>
        </span>
        </a>
    </div>
</div>
{% else %}

<div class="project three">
    <a href="{{ project.url | prepend: site.baseurl | prepend: site.url }}">
		<div class="col left one">
	        {% if project.img %}
	        <img class="thumbnail" src="{{ project.img | prepend: site.baseurl | prepend: site.url }}"/>
	        {% else %}
	        <div class="thumbnail blankbox"></div>
	        {% endif %}
		</div>
		<div class="col right two">
			<span>
            <h3 class="no-anchor">{{ project.title }}</h3>
            <br/>
            <p>{{ project.description }}</p>
			</span>
		</div>
    </a>
</div>

{% endif %}

{% endfor %}
