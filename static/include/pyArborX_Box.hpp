#ifndef PYARBORX_BOX_HPP
#define PYARBORX_BOX_HPP

#include <ArborX_Box.hpp>

#include <pybind11/pybind11.h>
#include <string.h>

namespace py = pybind11;

namespace pyArborX
{
namespace helper
{
std::string pyPrintBox(ArborX::Box const &b);
}

void generateBoxWrapper(py::module &m);
} // namespace pyArborX

#endif
