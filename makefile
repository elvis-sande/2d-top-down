compile:
	clang++ -o gen/2d-top-down src/**.cpp -lSDL2 -lSDL2_image
run:
	gen/2d-top-down