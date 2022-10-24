project(pyArborX_static LANGUAGES CXX)

#choose modules that should be included in the build
set(PY_STATIC_MODULES Point Box)

# get source files for selected static modules
foreach(PY_MODULE IN LISTS PY_STATIC_MODULES)
  list(APPEND PY_SRC ${PROJECT_SOURCE_DIR}/src/pyArborX_${PY_MODULE}.cpp)
  list(APPEND MODULE_INCLUDES "\n#include \"pyArborX_${PY_MODULE}.hpp\"" )
  list(APPEND MODULE_GENERATORS "\n generate${PY_MODULE}Wrapper(m)")
endforeach()

string(REPLACE ";" " " MODULE_INCLUDES "${MODULE_INCLUDES}")

configure_file(pyArborX_static.cpp.in generated_files/pyArborX_static.cpp)

PYBIND11_ADD_MODULE(pyArborX_static generated_files/pyArborX_static.cpp ${PY_SRC})
target_include_directories(pyArborX_static PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(pyArborX_static PUBLIC ${PROJECT_BINARY_DIR}/generated_files)
target_link_libraries(pyArborX_static PUBLIC ArborX::ArborX)
set_target_properties(pyArborX_static PROPERTIES
         LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../pyArborX)

