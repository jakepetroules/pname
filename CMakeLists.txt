cmake_minimum_required(VERSION 2.6)
project(pname)

add_definitions(/MT -D_CRT_SECURE_NO_WARNINGS)

add_executable(pname uname.c)
target_link_libraries(pname user32 version)

add_definitions(-DUNICODE)

add_executable(pname-uni uname.c)
target_link_libraries(pname-uni user32 version)

install(TARGETS pname RUNTIME DESTINATION "$ENV{WINDIR}" COMPONENT Runtime)
