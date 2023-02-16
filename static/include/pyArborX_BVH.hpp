#ifndef PYARBORX_BVH_HPP
#define PYARBORX_BVH_HPP

#include <ArborX_LinearBVH.hpp>

#include "config.hpp"
#include <pybind11/pybind11.h>

namespace pyArborX
{

void generateBVHWrapper(pybind11::module &m);

}

#endif
