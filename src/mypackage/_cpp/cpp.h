#ifndef MYPACKAGE_CPP_CPP_
#define MYPACKAGE_CPP_CPP_

#define BOOST_PYTHON_STATIC_LIB
#define BOOST_NUMPY_STATIC_LIB

#include <iostream>
#include <vector>
#include <Python.h>
#include <boost/python.hpp>
#include <boost/python/numpy.hpp>

namespace py = boost::python;
namespace np = boost::python::numpy;

void hello_cpp();
np::ndarray raw_ndarray(np::ndarray & input);

#endif // MYPACKAGE_CPP_CPP_
