#ifndef PYARBORX_EXECUTION_SPACE_HPP
#define PYARBORX_EXECUTION_SPACE_HPP

#include "config.hpp"
#include <pybind11/pybind11.h>

namespace pyArborX
{

void generateExecutionSpaceWrapper(pybind11::module &m);

}

#endif
