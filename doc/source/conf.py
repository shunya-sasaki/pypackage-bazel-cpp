import platform
# OS Identification
platform_name = platform.system()  # Windows, Darwin, Linux

project = 'Bazel C++ Project'
copyright = 'Shunya Sasaki'
author = 'Shunya Sasaki'

extensions = ['sphinx.ext.autodoc', 'sphinx.ext.napoleon', 'sphinxcontrib.blockdiag']
language = 'ja'
html_theme = 'sphinx_rtd_theme'
html_static_path = ['_static']

# blockdiag
blockdiag_html_image_format = 'SVG'
blockdiag_html_image_format = 'SVG'
