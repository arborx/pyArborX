#ifndef PYARBORX_BOX_HPP
#define PYARBORX_BOX_HPP

#include <ArborX_Box.hpp>

#include <string>

#include <pybind11/pybind11.h>

namespace pyArborX
{
namespace helper
{
std::string pyPrintBox(ArborX::Box const &b);
}

void generateBoxWrapper(pybind11::module &m);

} // namespace pyArborX

#endif
