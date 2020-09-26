cmake_minimum_required(VERSION 3.15)
project(TwitterGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Werror -Wextra -pedantic -pedantic-errors")

set(SOURCE_FILES
        tweets/elontweets
        tweets/kanyetweets
        Tweet.h
        Tweet.cpp
        TwitterGame.cpp)

add_executable(TwitterGame ${SOURCE_FILES})