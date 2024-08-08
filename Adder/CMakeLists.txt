add_library(adder adder.cpp)

install(TARGETS adder DESTINATION /usr/local/lib)
install(FILES adder.h DESTINATION /usr/local/include)