import pyArborX


def run():
    num_primitives = 100
    num_queries = 100

    radius = 1.0

    # Type alias
    ExecutionSpace = pyArborX.ExecutionSpace
    Primitives = pyArborX.Kokkos_View_ArborX_Point_1D_Default
    BVH = pyArborX.BVH

    execution_space = ExecutionSpace()

    primitives = Primitives("primitives", num_primitives)
    print(primitives.size())
    queries = pyArborX.generateWithinQueries_device(
        execution_space,
        Primitives("query_points", num_queries),
        num_queries,
        radius,
    )
    print(queries.size())
    #  execution_space.fence()

    bvh = BVH(execution_space, primitives)
    print(bvh.size())

    offsets = pyArborX.intView1D("offsets", 0)
    indices = pyArborX.intView1D("indices", 0)

    bvh.query(execution_space, queries, indices, offsets)

    print(offsets.size())
    print(indices.size())

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
