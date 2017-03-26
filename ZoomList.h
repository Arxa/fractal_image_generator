//
// Created by arxa on 26/3/2017.
//

#ifndef FRACTAL_IMAGES_GENERATOR_ZOOMLIST_H
#define FRACTAL_IMAGES_GENERATOR_ZOOMLIST_H

#include <vector>
#include <utility>
#include "Zoom.h"

using namespace std;

namespace arxa
{
    class ZoomList
    {

    private:
        double xCenter{0.0};
        double yCenter{0.0};
        double scale{1.0};
        int width{0};
        int height{0};
        vector<Zoom> zooms;

    public:
        ZoomList();
        ZoomList(int width1, int height1);
        void add(const Zoom &zoom);
        pair<double, double> doZoom(int x, int y);
    };
}


#endif //FRACTAL_IMAGES_GENERATOR_ZOOMLIST_H
