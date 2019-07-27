#!/bin/bash

echo Compiling RPWG project

echo Compiling Cluster Loader Tester
g++ -o cluster_loader_tester cluster_loader_tester.cpp load_language.cpp con_cluster_list_test.cpp vow_cluster_list_test.cpp

echo Compiling Cluster List Tester
g++ -o cluster_list_tester cluster_list_tester.cpp con_cluster_list_test.cpp vow_cluster_list_test.cpp

echo Compiling Word Generator Tester
g++ -o word_building_test word_builder_tester.cpp word_builder.cpp con_cluster_list_test.cpp vow_cluster_list_test.cpp get_cluster.cpp find_indices.cpp get_flag_codes.cpp choose_cluster.cpp

echo Done


