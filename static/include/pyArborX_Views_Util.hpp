#ifndef PYARBORX_VIEW_UTIL_HPP
#define PYARBORX_VIEW_UTIL_HPP

#include <Kokkos_Core.hpp>

// pybind11 can not do the overload resolution that is necessary to select the
// right function on the cpp side, as it only takes a functionptr. In order to
// not having to resolve the overloading by hand in the binding impl, these mock
// functions force the cpp side to chose the respective overloads.
namespace pyArboX
{
template <typename ViewType>
auto create_mirror_view(ViewType const &source)
{
  return Kokkos::create_mirror_view(source);
}

template <typename ViewDest, typename ViewSrc>
auto deep_copy(ViewDest const &dest, ViewSrc const &src)
{
  return Kokkos::deep_copy(dest, src);
}
} // namespace pyArboX
#endif
