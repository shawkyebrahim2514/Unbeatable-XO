cmake_minimum_required(VERSION 3.23)
project(XO)

set(CMAKE_CXX_STANDARD 20)

add_executable(XO XO_App.cpp XO_Board.cpp XO_GameManager.cpp XO_Player.cpp XO_UnbeatableMoves.cpp XO_UnbeatableMoves.h XO_GameManager.h XO_Player.h XO_Board.h)
