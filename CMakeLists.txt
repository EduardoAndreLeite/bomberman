cmake_minimum_required(VERSION 3.0.0)
project(bomberman VERSION 0.1.0)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
file(GLOB SOURCE
  "*.c"
  "*.h"
)

add_executable(bomberman ${SOURCE})

target_link_libraries(bomberman ${CURSES_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
