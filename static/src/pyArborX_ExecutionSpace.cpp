#ifndef PYARBORX_EXECUTION_SPACE_CPP
#define PYARBORX_EXECUTION_SPACE_CPP

#include "pyArborX_ExecutionSpace.hpp"

#include "config.hpp"

namespace pyArborX
{

void generateExecutionSpaceWrapper(pybind11::module &m)
{
  namespace py = pybind11;

  py::class_<ExecutionSpace>(m, "ExecutionSpace").def(py::init<>([]() {
    return new ExecutionSpace{};
  }));

  // .def("fence", py::overload_cast<>(&ExecutionSpace::fence, py::const_));
}

} // namespace pyArborX

#endif
