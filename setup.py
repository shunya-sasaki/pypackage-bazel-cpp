import os
import glob
from setuptools import setup
from setuptools import Extension

include_path = os.environ.get("CPLUS_INCLUDE_PATH")
library_path= os.environ.get("LIBRARY_PATH")

local_include_path = ["src/mypackage/_cpp"]

ext_module = Extension(
    name="mypackage._cpp",
    sources=glob.glob("src/mypackage/_cpp/*.cc"),
    libraries=["boost_python310", "boost_numpy310"],
    include_dirs=include_path.split(";") + local_include_path,
    library_dirs=library_path.split(";"),
    extra_compile_args=["-O2", "-std=c++17"],
    extra_link_args=["-O2", "-std=c++17"]
)

setup(py_modules=["mypackage"], ext_modules=[ext_module])
