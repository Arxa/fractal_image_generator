//
// Created by arxa on 23/3/2017.
//

#ifndef FRACTAL_IMAGES_GENERATOR_BITMAP_H
#define FRACTAL_IMAGES_GENERATOR_BITMAP_H

#include <string>
#include <cstdint>
#include <bits/unique_ptr.h>

using namespace std;

namespace arxa
{
    class Bitmap
    {
    private:
        int m_width{0};
        int m_height{0};
        unique_ptr<uint8_t[]> m_pPixels{nullptr}; // Using unique pointer we don't have to delete the allocated memory afterwards
    public:
        Bitmap(int width, int height);
        void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
        bool write(string filename);
        virtual ~Bitmap();
    };
}


#endif //FRACTAL_IMAGES_GENERATOR_BITMAP_H
