cmake_minimum_required(VERSION 3.5)
project(hello_example VERSION 1.0.0)

find_package(eosio.cdt)

add_contract( income_14 income_14 income_14.cpp )
