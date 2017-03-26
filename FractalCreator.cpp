//
// Created by arxa on 26/3/2017.
//

#include <iostream>
#include <assert.h>
#include "FractalCreator.h"

namespace arxa
{
    FractalCreator::FractalCreator(int width1, int height1) :
            width(width1), height(height1),
            histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}),
            fractal(new int[width * height]{0}),
            bitmap(width, height),
            zoomList(width, height)
    {
        zoomList.add(Zoom(width/2, height/2, 4.0/width));
    }

    FractalCreator::~FractalCreator(){}

    void FractalCreator::run(string name)
    {

        calculateIteration();
        calculateTotalIterations();
        calculateRangeTotals();
        drawFractal();
        writeBitmap(name);
    }

    void FractalCreator::calculateIteration()
    {
        for (int y=0; y < height; y++)
        {
            for (int x=0; x < width; x++)
            {
                pair<double, double> coords = zoomList.doZoom(x,y);
                int iterations = Mandelbrot::getIterations(coords.first, coords.second);
                fractal[y*width+x] = iterations;
                if (iterations != Mandelbrot::MAX_ITERATIONS){
                    histogram[iterations]++;
                }
            }
        }
    }

    void FractalCreator::drawFractal()
    {
        for (int y=0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                int iterations  = fractal[y * width + x];
                int range = getRange(iterations);
                int rangeTotal = rangeTotals[range];
                int rangeStart = ranges[range];

                RGB& startColor = colors[range];
                RGB& endColor = colors[range + 1];
                RGB colorDiff = endColor - startColor;

                uint8_t red = 0;
                uint8_t green = 0;
                uint8_t blue = 0;

                if (iterations != Mandelbrot::MAX_ITERATIONS)
                {
                    int totalPixels = 0;
                    for (int i = rangeStart; i <= iterations; i++)
                    {
                        totalPixels += histogram[i];
                    }
                    red = startColor.r + colorDiff.r * (double)totalPixels / rangeTotal;
                    green = startColor.g + colorDiff.g * (double)totalPixels / rangeTotal;
                    blue = startColor.b + colorDiff.b * (double)totalPixels / rangeTotal;
                }
                bitmap.setPixel(x, y, red, green, blue);
            }
        }
    }

    void FractalCreator::calculateTotalIterations()
    {
        for (int i=0; i < Mandelbrot::MAX_ITERATIONS; i++)
        {
            total += histogram[i];
        }
    }

    void FractalCreator::addZoom(const Zoom& zoom)
    {
        zoomList.add(zoom);
    }

    void FractalCreator::writeBitmap(string name)
    {
        bitmap.write(name);
    }

    void FractalCreator::addRange(double rangeEnd, const RGB& rgb)
    {
        ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
        colors.push_back(rgb);
        if (gotFristRange){
            rangeTotals.push_back(0);
        }
        gotFristRange = true;
    }

    void FractalCreator::calculateRangeTotals()
    {
        int rangeIndex = 0;

        for (int i=0; i < Mandelbrot::MAX_ITERATIONS; i++)
        {
            int pixels = histogram[i];
            if (i >= ranges[rangeIndex + 1]){
                rangeIndex++;
            }
            rangeTotals[rangeIndex] += pixels;
        }
    }

    int FractalCreator::getRange(int iterations) const
    {
        int range = 0;

        for (int i=1; i < ranges.size(); i++)
        {
            range = i;
            if (ranges[i] > iterations){
                break;
            }
        }
        range--;
        assert(range > -1);
        assert(range < ranges.size());

        return range;
    }
}
