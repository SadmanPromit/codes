import numpy, time
for i in range(4, 9):
    start_time = time.time()
    size = 2 ** i
    C = numpy.dot(numpy.ones((size, size)).astype(int), numpy.ones((size, size)).astype(int))
    print("T(", size, "): ", (time.time() - start_time), "s", sep='')