//
// Created by arxa on 26/3/2017.
//

#include "ZoomList.h"

namespace arxa
{
    ZoomList::ZoomList()
    {}

    ZoomList::ZoomList(int width1, int height1) : width(width1), height(height1)
    {}

    void ZoomList::add(const Zoom &zoom)
    {
        zooms.push_back(zoom);
        xCenter += (zoom.x - width/2) * scale;
        yCenter += -(zoom.y - height/2) * scale;
        scale *= zoom.scale;
    }

    pair<double, double> ZoomList::doZoom(int x, int y)
    {
        double xFractal = (x - width / 2) * scale + xCenter;
        double yFractal = (y - height / 2) * scale + yCenter;

        return pair<double, double>(xFractal, yFractal);
    }
}