add_executable(ex3.11.2 stringTuple.cpp)
target_compile_features(ex3.11.2 PUBLIC 
	cxx_std_17 
	cxx_variadic_templates)