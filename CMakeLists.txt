cmake_minimum_required(VERSION 2.8)
project(project1_fatih_iver_2016400264)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    LinkedList.cpp
    LinkedList.h
    main.cpp
    Member.cpp
    Member.h
    Node.cpp
    Node.h
    SurveyClass.cpp
    SurveyClass.h)

add_executable(project1_fatih_iver_2016400264 ${SOURCE_FILES})