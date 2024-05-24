lib:
	cd hushu && make lib && cd ..
all: lib 
	cmake -S . build && cmake --build build -j 10
run: all
	./build/example_glfw_vulkan
