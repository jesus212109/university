#!/bin/bash

salida=$(cmake -S . -B ./build)
salida=$(cmake --build ./build)

echo "COMPILANDO LA PRÁCTICA"
cd debug
make
cd ..
echo ""

bash ./run_tests.sh build/test_trie_node tests_trie_node/
bash ./run_tests.sh build/test_trie_node tests_trie_node_fold_unfold/
bash ./run_tests.sh build/test_trie tests_trie/
bash ./run_tests.sh build/test_trie tests_retrieve/
bash ./run_tests.sh build/test_trie tests_trie_fold_unfold/
bash ./run_tests.sh build/test_alphabet_soup_solver tests_alphabet_soup/
