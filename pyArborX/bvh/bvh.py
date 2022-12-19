import pykokkos as pk
from pathlib import Path
from .util import ClassGenerator,ModuleGenerator

class BVH():
    def __init__(self,memorySpace: pk.MemorySpace):
        self.memorySpace: pk.MemorySpace = memorySpace
        #  self.module_name: str = f"BVH_{memorySpace.name}"+"Space"
        self.classGenerator: ClassGenerator = ClassGenerator("BVH","ArborX::BVH",f"{memorySpace.name}"+"Space")
        self.classGenerator.addCtor([],[])


    def __init__(self,memorySpace: pk.MemorySpace,executionSpace: pk.ExecutionSpace, primitives, spaceFillingCurve):
        self.memorySpace: pk.MemorySpace = memorySpace
        self.classGenerator: ClassGenerator = ClassGenerator("BVH","ArborX::BVH",f"{memorySpace.name}"+"Space")
        self.classGenerator.addCtor([f"executionSpace.name", primitives.cpp_type,spaceFillingCurve.cpp_type],["ExecutionSpace","Primitives","SpaceFillingCurve"])
