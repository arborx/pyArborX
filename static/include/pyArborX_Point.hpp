#ifndef PYARBORX_POINT_HPP
#define PYARBORX_POINT_HPP

#include <ArborX_Point.hpp>

#include <pybind11/pybind11.h>
#include <string.h>

namespace py = pybind11;

namespace pyArborX
{
namespace helper
{
  std::string pyPrintPoint(ArborX::Point const &p);
}

void generatePointWrapper(py::module &m);
}

#endif
