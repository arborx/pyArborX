#ifndef PYARBORX_VIEW_UTIL_HPP
#define PYARBORX_VIEW_UTIL_HPP

#include <Kokkos_Core.hpp>

namespace pyArborX
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

} // namespace pyArborX

#endif
