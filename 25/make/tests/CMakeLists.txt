add_executable(tests test.cpp ../a.cpp)

add_test(NAME a COMMAND tests)