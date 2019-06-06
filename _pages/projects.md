---
layout: page
title: projects
permalink: /projects/
description: Undergraduate projects
---
{% assign currentProjects = site.projects | where: 'current', 'true' %}
{% assign previousProjects = site.projects | where: 'current', 'false' %}

## current projects ##

{% for project in currentProjects %}

{% if project.redirect %}

{% include project_redirect.html redirect=project.redirect img=project.img title=project.title description=project.description module=project.module academicYear=project.academicYear %}

{% else %}

{% include project_three.html url=project.url img=project.img title=project.title description=project.description module=project.module academicYear=project.academicYear %}
{% else %}

{% endif %}

{% endfor %}

## previous projects ##

{% for project in previousProjects %}

{% if project.redirect %}

{% include project_redirect.html redirect=project.redirect img=project.img title=project.title description=project.description module=project.module academicYear=project.academicYear %}

{% else %}

{% include project_three.html url=project.url img=project.img title=project.title description=project.description module=project.module academicYear=project.academicYear %}
{% else %}

{% endif %}

{% endfor %}
