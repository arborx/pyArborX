#ifndef PYARBORX_POINT_HPP
#define PYARBORX_POINT_HPP

#include <ArborX_Point.hpp>

#include <string>

#include <pybind11/pybind11.h>

namespace pyArborX
{
namespace helper
{
std::string pyPrintPoint(ArborX::Point const &p);
}

void generatePointWrapper(pybind11::module &m);
} // namespace pyArborX

#endif
