cmake_minimum_required(VERSION 4.1.2)

project(csci_201_final)

add_executable(csci_201_final src/main.cpp)

install (TARGETS csci_201_final
    LIBRARY DESTINATION lib)
