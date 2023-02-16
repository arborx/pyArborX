#ifndef PYARBORX_UTIL_HPP
#define PYARBORX_UTIL_HPP

#include "config.hpp"
#include <pybind11/pybind11.h>

namespace pyArborX
{

namespace helper
{
Predicates generateWithinQueries_device(ExecutionSpace execution_space,
                                        Primitives query_pts_view,
                                        int n_queries, float radius);
}

void generateUtilWrapper(pybind11::module &m);

} // namespace pyArborX

#endif
