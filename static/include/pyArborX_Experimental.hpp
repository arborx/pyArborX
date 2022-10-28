#ifndef PYARBORX_EXPERIMENTAL_HPP
#define PYARBORX_EXPERIMENTAL_HPP

#include <ArborX_SpaceFillingCurves.hpp>

#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace pyArborX
{

void generateExperimentalWrapper(py::module &m);

} // namespace pyArborX
#endif
