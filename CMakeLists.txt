cmake_minimum_required(VERSION 3.16)
project(pyArborX LANGUAGES CXX)

#check for required packages to generate static bindings
find_package(ArborX REQUIRED)
find_package(pybind11 REQUIRED)

#add the static bindings for non-template classes/generated classes
add_subdirectory(static)
