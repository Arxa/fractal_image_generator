//
// Created by arxa on 26/3/2017.
//

#ifndef FRACTAL_IMAGES_GENERATOR_RGB_H
#define FRACTAL_IMAGES_GENERATOR_RGB_H


namespace arxa
{
    struct RGB
    {
        double r;
        double g;
        double b;
        RGB(double r1, double g1, double b1);
    };

    RGB operator- (const RGB& first, const RGB& second);
}

#endif //FRACTAL_IMAGES_GENERATOR_RGB_H
