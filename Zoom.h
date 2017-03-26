//
// Created by arxa on 26/3/2017.
//

#ifndef FRACTAL_IMAGES_GENERATOR_ZOOM_H
#define FRACTAL_IMAGES_GENERATOR_ZOOM_H

namespace arxa
{
    struct Zoom
    {
        int x{0};
        int y{0};
        double scale{0.0};

        Zoom(int x1, int y1, double scale1) : x(x1), y(y1), scale(scale1) {};

    };
}


#endif //FRACTAL_IMAGES_GENERATOR_ZOOM_H
