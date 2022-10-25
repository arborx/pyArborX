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
std::string pyPrintPoint(ArborX::Point const &p)
{
  return "<pyArborX::Point with " + std::to_string(p[0]) + " " +
         std::to_string(p[1]) + " " + std::to_string(p[2]) + ">";
}
} // namespace helper

void generatePointWrapper(py::module &m)
{

  py::class_<ArborX::Point>(m, "Point")
      .def(py::init<>())
      .def(py::init<float, float, float>(), py::arg("x"), py::arg("y"),
           py::arg("z"))

      .def("__getitem__",
           py::overload_cast<unsigned int>(&ArborX::Point::operator[],
                                           py::const_),
           py::arg("i"))
      .def("__setitem__",
           [](ArborX::Point &p, int idx, double val) { p[idx] = val; })

      .def("__repr__", py::overload_cast<ArborX::Point const &>(
                           &pyArborX::helper::pyPrintPoint));
}
} // namespace pyArborX

#endif
