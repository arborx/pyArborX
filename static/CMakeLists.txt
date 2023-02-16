project(pyArborX_static LANGUAGES CXX)

#choose modules that should be included in the build
set(pyArborX_STATIC_GEOMETRY_MODULES Point Box Sphere)
set(pyArborX_STATIC_UTILITY_MODULES BVH ExecutionSpace Experimental Util)

# get source files for selected static modules
foreach(PY_MODULE IN LISTS pyArborX_STATIC_GEOMETRY_MODULES pyArborX_STATIC_UTILITY_MODULES)
  list(APPEND pyArborX_SRC ${PROJECT_SOURCE_DIR}/src/pyArborX_${PY_MODULE}.cpp)
  list(APPEND MODULE_INCLUDES "\n#include \"pyArborX_${PY_MODULE}.hpp\"" )
  list(APPEND MODULE_GENERATORS "\npyArborX::generate${PY_MODULE}Wrapper(m)")
endforeach()

#generate bindings for views of ArborX types
set(LAYOUTS LayoutLeft LayoutRight)
# set(MEMORYSPACES Default HostSpace)
set(MEMORYSPACES Default)
file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/generated_files)

foreach(GEOMETRY IN LISTS pyArborX_STATIC_GEOMETRY_MODULES)
  foreach(LAYOUT IN LISTS LAYOUTS)
    foreach(MEMORYSPACE IN LISTS MEMORYSPACES)
      set(VIEW_NAME "Kokkos_View_ArborX_${GEOMETRY}_1D_${LAYOUT}_${MEMORYSPACE}")
      if (MEMORYSPACE STREQUAL Default)
        set(VIEW_TYPE "Kokkos::View<ArborX::${GEOMETRY}*,Kokkos::${LAYOUT},Kokkos::${MEMORYSPACE}ExecutionSpace::memory_space>")
      else()
        set(VIEW_TYPE "Kokkos::View<ArborX::${GEOMETRY}*,Kokkos::${LAYOUT},Kokkos::${MEMORYSPACE}>")
      endif()
      set(VIEW_BASE_TYPE "ArborX::${GEOMETRY}")
      set(VIEW_INCLUDE "\n#include \"pyArborX_${VIEW_NAME}.hpp\"")

      configure_file(include/pyArborX_Views.hpp.in generated_files/pyArborX_${VIEW_NAME}.hpp)
      configure_file(src/pyArborX_Views.cpp.in generated_files/pyArborX_${VIEW_NAME}.cpp)
      list(APPEND pyArborX_SRC ${PROJECT_BINARY_DIR}/generated_files/pyArborX_${VIEW_NAME}.cpp)
      list(APPEND MODULE_INCLUDES "\n#include \"pyArborX_${VIEW_NAME}.hpp\"" )
      list(APPEND MODULE_GENERATORS "\npyArborX::generate${VIEW_NAME}Wrapper(m)")
    endforeach()
  endforeach()
endforeach()


string(REPLACE ";" " " MODULE_INCLUDES "${MODULE_INCLUDES}")

configure_file(pyArborX_static.cpp.in generated_files/pyArborX_static.cpp)

PYBIND11_ADD_MODULE(pyArborX_static generated_files/pyArborX_static.cpp ${pyArborX_SRC})
target_include_directories(pyArborX_static PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(pyArborX_static PUBLIC ${PROJECT_BINARY_DIR}/generated_files)
target_link_libraries(pyArborX_static PUBLIC ArborX::ArborX INTERFACE Kokkos::kokkos)
set_target_properties(pyArborX_static PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/pyArborX)
