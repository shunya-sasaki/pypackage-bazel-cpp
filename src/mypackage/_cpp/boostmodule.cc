/**
 * @file boostmodule.cc
 * @author Shunya Sasaki (shunya.sasaki1120@gmail.com)
 * @brief
 * @details
 * @date 2022-09-03
 */
#include "boostmodule.h"

namespace np = boost::python::numpy;

template <typename T, typename U>
void allignment_to_vector(std::vector<T> &data_, U const *input_ptr, int const &size_)
{
    for (auto i = 0; i < size_; i++)
    {
        data_[i] = *(input_ptr + i);
    }
}

BoostVectorBase::BoostVectorBase(np::ndarray &input)
{
    nd_ = input.get_nd();
    for (auto i_dim = 0; i_dim < nd_; i_dim++)
    {
        size_ *= input.shape(i_dim);
    }
}

BoostVectorDouble::BoostVectorDouble(np::ndarray &input) : BoostVectorBase(input)
{
    type_ = "double";
    data_ = std::vector<double>(size_);
    auto dtype = input.get_dtype();
    if (dtype == np::dtype::get_builtin<float>())
    {
        float *input_ptr = reinterpret_cast<float *>(input.get_data());
        allignment_to_vector(data_, input_ptr, size_);
    }
    else if (dtype == np::dtype::get_builtin<double>())
    {
        double *input_ptr = reinterpret_cast<double *>(input.get_data());
        allignment_to_vector(data_, input_ptr, size_);
    }
}

std::vector<double> BoostVectorDouble::get_data()
{
    return data_;
}

BoostVectorFloat::BoostVectorFloat(np::ndarray &input) : BoostVectorBase(input)
{
    type_ = "float";
    data_ = std::vector<float>(size_);
    auto dtype = input.get_dtype();
    if (dtype == np::dtype::get_builtin<float>())
    {
        float *input_ptr = reinterpret_cast<float *>(input.get_data());
        allignment_to_vector(data_, input_ptr, size_);
    }
    else if (dtype == np::dtype::get_builtin<double>())
    {
        double *input_ptr = reinterpret_cast<double *>(input.get_data());
        allignment_to_vector(data_, input_ptr, size_);
    }
}

std::vector<float> BoostVectorFloat::get_data()
{
    return data_;
}