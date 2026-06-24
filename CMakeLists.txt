cmake_minimum_required(VERSION 3.20)
project(dossier C)

set(CMAKE_C_STANDARD 23)

find_package(SQLite3 REQUIRED)

add_executable(dossier
    main.c
    db.c
    person.c
)

target_link_libraries(dossier PRIVATE SQLite::SQLite3)
