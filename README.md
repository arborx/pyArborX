pyArborX
======
This is a tailored Python binding of the ArborX library. It consists of a narrow subset of functionality and dataclasses from both ArborX. We are working on extending it.
Be advised, that this is work in progress and will not be stable. Multiple major changes are necessary to support the majority of ArborX in python.

Installation
------------
The build instructions here are for Unix systems. Building pyArborX in Windows has not been tested.
All build requirements for [ArborX](https://github.com/arborx/ArborX/wiki/Build) have to be fulfilled.
In case Cuda is used as a backend to run the computations on Nvidia-GPUs `-DKokkos_ENABLE_CUDA_LAMBDA` must be enabeled when compiling Kokkos.
pyArborX additionally requires [pybind11](https://pybind11.readthedocs.io/en/stable/index.html). This can either be installed manually or by `pip install pybind11`.

The only toolchain that was tested for this build is [cmake](https://cmake.org/). Cmake must be able to find all above mentioned packages.

The bindings are build with Cmake as usual (out of source build). In this process Cmake will generate several of the source files for the bindings in order to allow for easy integration of other capabilities inside ArborX.

After building the bindings (e.g. make), pip can be used to install the bindings into the python environment. As the state of the binding is far from being a full package, only development install is supported.
For this run `pip install --user -e .` in the Cmake build directory. The successful install can be checked with `pip list` ... pyArborX should be listed as package with the build directory as location.

License
-------
The bindings are considered part of the ArborX package. Refer to the top-level license information.
