#ifndef PYARBORX_SPHERE_CPP
#define PYARBORX_SPHERE_CPP

#include "pyArborX_Sphere.hpp"
#include "pyArborX_Point.hpp"

namespace py = pybind11;

namespace pyArborX
{
namespace helper
{
std::string pyPrintSphere(ArborX::Sphere const &s)
{
  return "<pyArborX::Sphere with centroid \n" + pyPrintPoint(s.centroid()) +
         "and radius \n" + std::to_string(s.radius()) + ">";
}
}

void generateSphereWrapper(py::module &m)
{

  py::class_<ArborX::Sphere>(m, "Sphere")
      .def(py::init<>())
      .def(py::init<ArborX::Point, double>(), py::arg("centroid"),
           py::arg("radius"))

      .def("centroid",
           py::overload_cast<>(&ArborX::Sphere::centroid, py::const_),
           py::return_value_policy::reference)
      .def("centroid", py::overload_cast<>(&ArborX::Sphere::centroid),
           py::return_value_policy::reference)
      .def("radius",
           py::overload_cast<>(&ArborX::Sphere::radius, py::const_),
           py::return_value_policy::move)

      .def("__repr__",
           py::overload_cast<ArborX::Sphere const &>(&pyArborX::helper::pyPrintSphere));
}
} // end of namespace pyArborX

#endif
