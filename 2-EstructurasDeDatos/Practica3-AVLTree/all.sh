#!/bin/bash

salida=$(cmake -S . -B ./build)
salida=$(cmake --build ./build)

echo "COMPILANDO LA PRÁCTICA"
cd build
make
cd ..
echo ""

bash ./run_tests.sh build/test_bstree tests_bstnode/
bash ./run_tests.sh build/test_bstree tests_bstree
bash ./run_tests.sh build/test_bstree tests_bstree_perfectly_balanced/
bash ./run_tests.sh build/test_avltree tests_avltnode/
bash ./run_tests.sh build/test_avltree tests_avltree/