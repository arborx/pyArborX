#ifndef PYARBORX_SPHERE_HPP
#define PYARBORX_SPHERE_HPP

#include <ArborX_Sphere.hpp>

#include <pybind11/pybind11.h>
#include <string.h>

namespace py = pybind11;

namespace pyArborX
{
namespace helper
{
  std::string pyPrintSphere(ArborX::Sphere const &s);
}

void generateSphereWrapper(py::module &m);
}

#endif
