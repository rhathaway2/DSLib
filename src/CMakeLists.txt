# Create library of just header files. Need INTERFACE
add_library(DataStructuresLib INTERFACE)
# Specify the include directory for the library
target_include_directories(DataStructuresLib INTERFACE ${PROJECT_SOURCE_DIR}/include)

# Create executable for LinkedList demo
add_executable(LinkedListDemo LinkedListDemo.cpp)
target_link_libraries(LinkedListDemo PRIVATE DataStructuresLib)

# Create executable for Stack demo
add_executable(StackDemo StackDemo.cpp)
target_link_libraries(StackDemo PRIVATE DataStructuresLib)

# Create executable for Queue demo
add_executable(QueueDemo QueueDemo.cpp)
target_link_libraries(QueueDemo PRIVATE DataStructuresLib)
