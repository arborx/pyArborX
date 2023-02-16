import pyArborX


def run():
    num_points = 100

    radius = 2.0

    # Type alias
    ExecutionSpace = pyArborX.ExecutionSpace
    Primitives = pyArborX.Kokkos_View_ArborX_Point_1D_Default
    Point = pyArborX.Point
    BVH = pyArborX.BVH

    execution_space = ExecutionSpace()

    primitives = Primitives("primitives", num_points)
    for i in range(primitives.size()):
        primitives[i] = Point(i, i, i)

    queries = pyArborX.generateWithinQueries_device(
        execution_space,
        primitives,
        num_points,
        radius,
    )
    #  execution_space.fence()

    bvh = BVH(execution_space, primitives)

    offsets = pyArborX.intView1D("offsets", 0)
    indices = pyArborX.intView1D("indices", 0)

    bvh.query(execution_space, queries, indices, offsets)

    for i in range(offsets.size()-1):
        print("[%d]" % i, end="")
        for j in range(offsets[i], offsets[i+1]):
            print(" %d" % indices[j], end="")
        print("")

    # As the Python garbage collector does not respect Kokkos finalize at this
    # time, explicitly delete all ArborX structures
    del bvh
    del queries
    del primitives
    del indices
    del offsets


if __name__ == "__main__":
    pyArborX.initialize()
    pyArborX.printConfig()
    run()
    pyArborX.finalize()
