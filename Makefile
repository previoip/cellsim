all:
	cmake -P build.cmake

run:
	cmake -P build.cmake
	./build/cellsim.exe