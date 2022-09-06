/**
 * @file hellocpp.cc
 * @brief boost-python sample program 
 */
#include <iostream>
#include <boost/python.hpp>
#include "boostmodule.h"

namespace py = boost::python;
namespace np = boost::python::numpy;

/**
 * @brief Output message to the standard output. 
 * 
 */
void hello_cpp()
{
    std::cout << "Hello World, Hello C++" << std::endl;
    return;
}

np::ndarray raw_ndarray(np::ndarray &input)
{
    std::cout << "check: type double" << std::endl;
    auto vector_d = BoostVectorDouble(input);
    for (auto &val: vector_d.get_data())
    {
        std::cout << "val: " << val << std::endl;
    }

    std::cout << "check: type float" << std::endl;
    auto vector_f = BoostVectorFloat(input);
    for (auto &val: vector_d.get_data())
    {
        std::cout << "val: " << val << std::endl;
    }
    return input;
}

// The argument of BOOST_PYTHON_MODULE must be same to module name.
BOOST_PYTHON_MODULE(_cpp){
    Py_Initialize();
    np::initialize();
    py::def("hello_cpp", hello_cpp);
    py::def("raw_ndarray", raw_ndarray);
}