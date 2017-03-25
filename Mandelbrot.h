//
// Created by arxa on 24/3/2017.
//

#ifndef FRACTAL_IMAGES_GENERATOR_MANDELBROT_H
#define FRACTAL_IMAGES_GENERATOR_MANDELBROT_H

namespace arxa
{
    class Mandelbrot
    {
    public:
        static const int MAX_ITERATIONS{1000};
    public:
        static int getIterations(double x, double y);
    };
}

#endif //FRACTAL_IMAGES_GENERATOR_MANDELBROT_H
