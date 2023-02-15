#ifndef PYARBORX_CONFIG_H
#define PYARBORX_CONFIG_H

#include <ArborX_Point.hpp>
#include <ArborX_Predicates.hpp>
#include <ArborX_SpaceFillingCurves.hpp>
#include <ArborX_Sphere.hpp>

#include <Kokkos_Core.hpp>

namespace pyArborX
{

// instantiation of all template arguments by hand, as there is no interface for
// these ... for now
using ExecutionSpace = Kokkos::DefaultExecutionSpace;
using MemorySpace = ExecutionSpace::memory_space;
// using MemorySpace = Kokkos::CudaUVMSpace;

using intView1DBaseType = int;
using intView1DType = Kokkos::View<int *, MemorySpace>;

using PointViewBaseType = ArborX::Point;
using PointViewType = Kokkos::View<PointViewBaseType *, MemorySpace>;

using IntersectViewBaseType = decltype(ArborX::intersects(ArborX::Sphere{}));
using IntersectViewType = Kokkos::View<IntersectViewBaseType *, MemorySpace>;

using Primitives = PointViewType;
using Predicates = IntersectViewType;

using SpaceFillingCurve = ArborX::Experimental::Morton64;

} // namespace pyArborX

#endif
