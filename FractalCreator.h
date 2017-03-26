//
// Created by arxa on 26/3/2017.
//

#ifndef FRACTAL_IMAGES_GENERATOR_FRACTALCREATOR_H
#define FRACTAL_IMAGES_GENERATOR_FRACTALCREATOR_H

#include <string>
#include <memory>
#include <vector>

#include "Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "RGB.h"

using namespace std;

namespace arxa
{
    class FractalCreator
    {
    private:
        int width;
        int height;
        int total{0};
        bool gotFristRange{false};
        unique_ptr<int[]> histogram;
        unique_ptr<int[]> fractal;
        Bitmap bitmap;
        ZoomList zoomList;
        vector<int> ranges;
        vector<RGB> colors;
        vector<int> rangeTotals;

    private:
        void calculateIteration();
        void calculateTotalIterations();
        void calculateRangeTotals();
        void drawFractal();
        void writeBitmap(string name);
        int getRange(int iterations) const;

    public:
        FractalCreator(int width, int height);
        virtual ~FractalCreator();

        void addRange(double rangeEnd, const RGB& rgb);
        void addZoom(const Zoom& zoom);
        void run(string name);

    };
}


#endif //FRACTAL_IMAGES_GENERATOR_FRACTALCREATOR_H
