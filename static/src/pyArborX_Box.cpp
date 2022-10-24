#ifndef PYARBORX_BOX_CPP
#define PYARBORX_BOX_CPP

#include "pyArborX_Box.hpp"
#include "pyArborX_Point.hpp"

namespace py = pybind11;

namespace pyArborXHelper
{
std::string pyPrintBox(ArborX::Box const &b)
{
  return "<pyArborX::Box with min Corner \n" + pyPrintPoint(b.minCorner()) +
         "and max Corner \n" + pyPrintPoint(b.maxCorner()) + ">";
}
} // end of namespace pyArborXHelper

void generateBoxWrapper(py::module &m)
{

  py::class_<ArborX::Box>(m, "Box")
      .def(py::init<>())
      .def(py::init<ArborX::Point, ArborX::Point>(), py::arg("min_corner"),
           py::arg("max_corner"))

      .def("minCorner",
           py::overload_cast<>(&ArborX::Box::minCorner, py::const_),
           py::return_value_policy::reference)
      .def("minCorner", py::overload_cast<>(&ArborX::Box::minCorner),
           py::return_value_policy::reference)
      .def("maxCorner",
           py::overload_cast<>(&ArborX::Box::maxCorner, py::const_),
           py::return_value_policy::reference)
      .def("maxCorner", py::overload_cast<>(&ArborX::Box::maxCorner),
           py::return_value_policy::reference)

      .def("__iadd__",
           py::overload_cast<ArborX::Box const &>(&ArborX::Box::operator+=),
           py::arg("ArborX::Box"), py::return_value_policy::reference)

      .def("__repr__",
           py::overload_cast<ArborX::Box const &>(&pyArborXHelper::pyPrintBox));
}

#endif
