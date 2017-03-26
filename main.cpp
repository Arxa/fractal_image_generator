#include <iostream>
#include <memory>
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "FractalCreator.h"
#include "Zoom.h"
#include "RGB.h"


using namespace std;
using namespace arxa;

int main()
{
    FractalCreator fractalCreator(800, 600);

    fractalCreator.addRange(0.0, RGB(0, 0, 0));
    fractalCreator.addRange(0.05, RGB(255, 99, 71));
    fractalCreator.addRange(0.08, RGB(255, 215, 0));
    fractalCreator.addRange(1.0, RGB(255, 255, 255));

    fractalCreator.addZoom(Zoom(295, 202, 0.1));
    fractalCreator.addZoom(Zoom(312, 304, 0.1));

    fractalCreator.run("fractal_image_output.bmp");

    cout <<"Fractal Image Created!"<<endl;
    return 0;
}