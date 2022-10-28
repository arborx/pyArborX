#ifndef PYARBORX_EXPERIMENTAL_CPP
#define PYARBORX_EXPERIMENTAL_CPP

#include "pyArborX_Experimental.hpp"

namespace py = pybind11;

namespace pyArborX
{

void generateExperimentalWrapper(py::module &m)
{
  py::class_<ArborX::Experimental::Morton64>(m, "Morton64")
      .def(py::init<>())

      .def("cpp_type", []() { return "ArborX::Experimental::Morton64"; });
}

} // namespace pyArborX
#endif
