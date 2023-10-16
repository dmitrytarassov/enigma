cmake_minimum_required(VERSION 3.26)
project(MyCProject)  # Consider renaming the project

set(CMAKE_C_STANDARD 11)

# If you have more source files, list them after main.c
add_executable(my_program main.c)  # Rename the executable

# If you have headers in other directories, specify them
# include_directories(your_directory_here)

# If you're using any libraries, link them
# target_link_libraries(my_program your_library_here)
