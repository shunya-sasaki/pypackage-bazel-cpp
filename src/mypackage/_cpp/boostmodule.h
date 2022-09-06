#ifndef MYPACKAGE_CPP_BOOSTMODULE_
#define MYPACKAGE_CPP_BOOSTMODULE_

#define BOOST_PYTHON_STATIC_LIB
#define BOOST_NUMPY_STATIC_LIB

#include <iostream>
#include <vector>
#include <Python.h>
#include <boost/python/numpy.hpp>

namespace np = boost::python::numpy;

template <typename T, typename U>
void allignment_to_vector(std::vector<T> &data_, U const *input_ptr, int const &size_t);

class BoostVectorBase
{
protected:
    int nd_;
    int64_t size_ = 1;
    std::string type_;

public:
    BoostVectorBase(np::ndarray &input);
};

class BoostVectorFloat : public BoostVectorBase
{
    std::vector<float> data_;

public:
    BoostVectorFloat(np::ndarray &input);
    std::vector<float> get_data();
};

class BoostVectorDouble : public BoostVectorBase
{
    std::vector<double> data_;

public:
    BoostVectorDouble(np::ndarray &input);
    std::vector<double> get_data();
};

class BoostVector : public BoostVectorBase
{

};

#endif // MYPACKAGE_CPP_BOOSTMODLUE_H_