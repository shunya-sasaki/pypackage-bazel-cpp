#include <iostream>
#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
#include "src/mypackage/_cpp/boostmodule.h"

namespace py = boost::python;
namespace np = boost::python::numpy;

int main()
{
    Py_Initialize();
    np::initialize();
    py::tuple shape = py::make_tuple(3, 3);
    np::dtype dtype = np::dtype::get_builtin<float>();
    py::object own;
    py::tuple stride = py::make_tuple(sizeof(float)*3, sizeof(float));
    float data[3][3] = {{1.f, 2.f, 3.f}, {4.f, 5.f, 6.f}, {7.f, 8.f, 9.f}};
    np::ndarray np_array = np::from_data(data, dtype, shape, stride, own);

    BoostVectorDouble vector_d = BoostVectorDouble(np_array);

    std::cout << "check input" << std::endl;
    for (auto &val: vector_d.get_data())
    {
        std::cout << "val: " << val << std::endl;
    }
    return 0;
}