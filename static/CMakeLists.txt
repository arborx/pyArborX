project(pyArborX_static LANGUAGES CXX)

#choose modules that should be included in the build
set(pyArborX_STATIC_GEOMETRY_MODULES Point Box Sphere)
set(pyArborX_STATIC_UTILITY_MODULES Experimental)

# get source files for selected static modules
foreach(PY_MODULE IN LISTS pyArborX_STATIC_GEOMETRY_MODULES pyArborX_STATIC_UTILITY_MODULES)
  list(APPEND PY_SRC ${PROJECT_SOURCE_DIR}/src/pyArborX_${PY_MODULE}.cpp)
  list(APPEND MODULE_INCLUDES "\n#include \"pyArborX_${PY_MODULE}.hpp\"" )
  list(APPEND MODULE_GENERATORS "\npyArborX::generate${PY_MODULE}Wrapper(m)")
endforeach()

string(REPLACE ";" " " MODULE_INCLUDES "${MODULE_INCLUDES}")

configure_file(pyArborX_static.cpp.in generated_files/pyArborX_static.cpp)

PYBIND11_ADD_MODULE(pyArborX_static generated_files/pyArborX_static.cpp ${PY_SRC})
target_include_directories(pyArborX_static PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(pyArborX_static PUBLIC ${PROJECT_BINARY_DIR}/generated_files)
target_link_libraries(pyArborX_static PUBLIC ArborX::ArborX)
set_target_properties(pyArborX_static PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/pyArborX)
