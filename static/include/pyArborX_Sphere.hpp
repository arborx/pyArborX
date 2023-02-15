#ifndef PYARBORX_SPHERE_HPP
#define PYARBORX_SPHERE_HPP

#include <ArborX_Sphere.hpp>

#include <string>

#include <pybind11/pybind11.h>

namespace pyArborX
{
namespace helper
{
std::string pyPrintSphere(ArborX::Sphere const &s);
}

void generateSphereWrapper(pybind11::module &m);
} // namespace pyArborX

#endif
