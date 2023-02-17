project(pyArborX_static LANGUAGES CXX)

# Choose modules to be included
set(pyArborX_STATIC_GEOMETRY_MODULES Point Box Sphere)
set(pyArborX_STATIC_UTILITY_MODULES Experimental)

# Grab source files for the selected static modules
foreach(PY_MODULE IN LISTS pyArborX_STATIC_GEOMETRY_MODULES pyArborX_STATIC_UTILITY_MODULES)
  list(APPEND pyArborX_SRC ${PROJECT_SOURCE_DIR}/src/pyArborX_${PY_MODULE}.cpp)
  list(APPEND MODULE_INCLUDES "\n#include \"pyArborX_${PY_MODULE}.hpp\"" )
  list(APPEND MODULE_GENERATORS "\npyArborX::generate${PY_MODULE}Wrapper(m)")
endforeach()

# Generate View bindings
set(pyArborX_STATIC_VIEW_TYPES ${pyArborX_STATIC_GEOMETRY_MODULES})
list(TRANSFORM pyArborX_STATIC_VIEW_TYPES PREPEND "ArborX::")
list(APPEND pyArborX_STATIC_VIEW_TYPES "int") # extra types

file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/generated_files)

set(LAYOUTS LayoutLeft LayoutRight)
set(MEMORYSPACES Default HostSpace)
foreach(VIEW_BASE_TYPE IN LISTS pyArborX_STATIC_VIEW_TYPES)
  foreach(LAYOUT IN LISTS LAYOUTS)
    foreach(MEMORYSPACE IN LISTS MEMORYSPACES)
      string(REPLACE "::" "_" VIEW_BASE_NAME ${VIEW_BASE_TYPE})
      set(VIEW_NAME "Kokkos_View_${VIEW_BASE_NAME}_1D_${LAYOUT}_${MEMORYSPACE}")
      if (MEMORYSPACE STREQUAL Default)
        set(VIEW_TYPE "Kokkos::View<${VIEW_BASE_TYPE}*,Kokkos::${LAYOUT},Kokkos::${MEMORYSPACE}ExecutionSpace::memory_space>")
      else()
        set(VIEW_TYPE "Kokkos::View<${VIEW_BASE_TYPE}*,Kokkos::${LAYOUT},Kokkos::${MEMORYSPACE}>")
      endif()
      set(VIEW_INCLUDE "\n#include \"pyArborX_${VIEW_NAME}.hpp\"")

      configure_file(include/pyArborX_Views.hpp.in generated_files/pyArborX_${VIEW_NAME}.hpp)
      if(VIEW_BASE_TYPE MATCHES "^ArborX::")
        set(INCLUDE_HEADER "${VIEW_BASE_NAME}.hpp")
      else()
        set(INCLUDE_HEADER "string")
      endif()
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
target_link_libraries(pyArborX_static PUBLIC ArborX::ArborX)
set_target_properties(pyArborX_static PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/pyArborX)
