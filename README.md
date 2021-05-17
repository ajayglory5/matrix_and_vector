# read_file_and_sort
This is a C++ program, that has two class. One class is a matrix class while another is a vector class. These classes supports the following:
* Cross product of two vectors
* Product of two given matrix
* Multiplication of a given matrix and a given vector
* Scaling of the given vector/matrix
* Addition of two given vectors/matrix
* Subtraction of two given vectors/matrix
* No linear algebra functions are sought for (e.g. inverse, linear solving, svd etc.).

# steps to compile and run
* Unzip the package.

* Go inside the package:
```
cd matrix_and_vector/
```

* Now create a temporary build directorsy to compile. Execute the following command:
```
mkdir build
cd build
cmake ../
make
```

* To execute the unit testcases, run the following command:
```
./test/matrix_and_vector_test
```
This should give the output as:
```
[==========] Running 15 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 8 tests from matrix
[ RUN      ] matrix.initError
[       OK ] matrix.initError (15 ms)
[ RUN      ] matrix.initSuccess
[       OK ] matrix.initSuccess (2 ms)
[ RUN      ] matrix.copySuccess
[       OK ] matrix.copySuccess (1 ms)
[ RUN      ] matrix.productMatrixToMatrix
[       OK ] matrix.productMatrixToMatrix (3 ms)
[ RUN      ] matrix.productMatrixToVector
[       OK ] matrix.productMatrixToVector (6 ms)
[ RUN      ] matrix.scaling
[       OK ] matrix.scaling (1 ms)
[ RUN      ] matrix.addition
[       OK ] matrix.addition (4 ms)
[ RUN      ] matrix.subtraction
[       OK ] matrix.subtraction (3 ms)
[----------] 8 tests from matrix (39 ms total)

[----------] 7 tests from vector
[ RUN      ] vector.initError
[       OK ] vector.initError (1 ms)
[ RUN      ] vector.initSuccess
[       OK ] vector.initSuccess (0 ms)
[ RUN      ] vector.copySuccess
[       OK ] vector.copySuccess (1 ms)
[ RUN      ] vector.crossProduct
[       OK ] vector.crossProduct (0 ms)
[ RUN      ] vector.scaling
[       OK ] vector.scaling (1 ms)
[ RUN      ] vector.addition
[       OK ] vector.addition (0 ms)
[ RUN      ] vector.subtraction
[       OK ] vector.subtraction (0 ms)
[----------] 7 tests from vector (7 ms total)

[----------] Global test environment tear-down
[==========] 15 tests from 2 test suites ran. (47 ms total)
[  PASSED  ] 15 tests.
```

* To check for memory leaks, run the following command (install valgrind if required):
```
valgrind ./test/matrix_and_vector_test
```
This should give the output as:
```
==85558== Memcheck, a memory error detector
==85558== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==85558== Using Valgrind-3.17.0 and LibVEX; rerun with -h for copyright info
==85558== Command: ./test/matrix_and_vector_test
==85558== 
[==========] Running 15 tests from 2 test suites.
...
...
...
[  PASSED  ] 15 tests.
==85558== 
==85558== HEAP SUMMARY:
==85558==     in use at exit: 0 bytes in 0 blocks
==85558==   total heap usage: 914 allocs, 914 frees, 236,270 bytes allocated
==85558== 
==85558== All heap blocks were freed -- no leaks are possible
==85558== 
==85558== For lists of detected and suppressed errors, rerun with: -s
==85558== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```