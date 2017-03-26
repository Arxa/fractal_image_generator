cmake_minimum_required(VERSION 3.6)
project(Fractal_Images_Generator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BitmapInfoHeader.h BitmapFileHeader.h Bitmap.cpp Bitmap.h Mandelbrot.cpp Mandelbrot.h Zoom.h ZoomList.cpp ZoomList.h Zoom.cpp FractalCreator.cpp FractalCreator.h RGB.cpp RGB.h)
add_executable(Fractal_Images_Generator ${SOURCE_FILES} BitmapInfoHeader.h BitmapFileHeader.h Bitmap.cpp Bitmap.h Mandelbrot.cpp Mandelbrot.h Zoom.h ZoomList.cpp ZoomList.h Zoom.cpp FractalCreator.cpp FractalCreator.h RGB.cpp RGB.h)