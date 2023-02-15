#ifndef PYARBORX_BVH_CPP
#define PYARBORX_BVH_CPP

#include "pyArborX_BVH.hpp"

#include <ArborX_LinearBVH.hpp>

#include <pybind11/pybind11.h>

namespace pyArborX
{

void generateBVHWrapper(pybind11::module &m)
{
  using BVH = ArborX::BVH<MemorySpace>;
  namespace py = pybind11;

  m.def("ArborX::Details::sortObjects",
        &ArborX::Details::sortObjects<ExecutionSpace, intView1DType,
                                      unsigned int>,
        py::arg("ExecutionSpace"), py::arg("ViewType"));

  py::class_<BVH>(m, "BVH")
      .def(py::init<>())
      .def(py::init<ExecutionSpace, Primitives, SpaceFillingCurve>(),
           py::arg("ExecutionSpace"), py::arg("Primitives"),
           py::arg("SpaceFillingCurve") = SpaceFillingCurve())

      .def("query",
           &BVH::query<ExecutionSpace const &, Predicates const &,
                       intView1DType &, intView1DType &>,
           py::arg("ExecutionSpace"), py::arg("Predicates"), py::arg("Indices"),
           py::arg("Offsets"));
}

} // namespace pyArborX

#endif
