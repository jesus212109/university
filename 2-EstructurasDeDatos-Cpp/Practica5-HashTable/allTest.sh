#!/bin/bash

# salida=$(cmake -S . -B ./build)
# salida=$(cmake --build ./build)

# echo "COMPILANDO LA PRÁCTICA"
# cd build
# make
# cd ..
# echo ""

# ./run_tests.sh build/test_ip_utils tests_ip_utils
./run_tests.sh build/test_hash_f tests_hash_function
./run_tests.sh build/test_hash_f tests_hash_function_lp
./run_tests.sh build/test_hash_f tests_hash_function_qp
./run_tests.sh build/test_hash_f tests_hash_function_rp 
./run_tests.sh build/test_hash_f tests_hash_function_rh
./run_tests.sh build/test_ip_utils tests_ip_utils 
./run_tests.sh build/test_hash_table tests_hash_table

