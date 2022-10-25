#ifndef PYARBORX_CONFIG_H
#define PYARBORX_CONFIG_H

#include <ArborX_Box.hpp>
#include <ArborX_Point.hpp>
#include <ArborX_Sphere.hpp>

#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

PYBIND11_MAKE_OPAQUE(std::vector<ArborX::Point>);
PYBIND11_MAKE_OPAQUE(std::vector<ArborX::Box>);
PYBIND11_MAKE_OPAQUE(std::vector<ArborX::Sphere>);
#endif
