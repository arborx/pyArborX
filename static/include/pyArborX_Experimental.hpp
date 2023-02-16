#ifndef PYARBORX_EXPERIMENTAL_HPP
#define PYARBORX_EXPERIMENTAL_HPP

#include <ArborX_SpaceFillingCurves.hpp>

#include <pybind11/pybind11.h>

namespace pyArborX
{

void generateExperimentalWrapper(pybind11::module &m);

} // namespace pyArborX

#endif
