#!/bin/bash

echo Start RPWG project

#echo Compiling Cluster Loader Tester
#g++ -o cluster_loader_tester cluster_loader_tester.cpp load_language.cpp con_cluster_list_test.cpp vow_cluster_list_test.cpp

# echo Compiling Cluster List Tester
# g++ -o cluster_list_tester cluster_list_tester.cpp con_cluster_list_test.cpp vow_cluster_list_test.cpp

# echo Compiling Word Generator Tester
# g++ -o word_building_test word_builder_tester.cpp word_builder.cpp con_cluster_list_test.cpp vow_cluster_list_test.cpp get_cluster.cpp find_indices.cpp get_flag_codes.cpp choose_cluster.cpp

# echo Compiling Cluster File Loading Tester
# g++ -o cluster_file_loading_tester cluster_file_loading_tester.cpp string_splitter.cpp file_reader.cpp

echo Compiling Word List Generator
g++ -o word_list_generator generate_words.cpp word_builder.cpp get_cluster.cpp \
find_indices.cpp filter_by_freq.cpp get_flag_codes.cpp choose_cluster.cpp \
file_reader.cpp string_splitter.cpp calc_intersection.cpp

echo Done


