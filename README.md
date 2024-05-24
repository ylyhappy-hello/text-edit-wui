# text-editor
编译器程序使用c语言写的，需要这些依赖
先编译出静态库libhushu.a, 去hushu目录下执行make lib
sudo apt install flex bison g++ make
gui使用的是cpp的imgui, 需要依赖glfw, 用的vulkan后端
sudo snap install cmake 
sudo apt install libglfw3-dev
执行程序，在项目根目录 make run
