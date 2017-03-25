//
// Created by arxa on 23/3/2017.
//

#ifndef FRACTAL_IMAGES_GENERATOR_BITMAPFILEHEADER_H
#define FRACTAL_IMAGES_GENERATOR_BITMAPFILEHEADER_H

#include <cstdint>

#pragma pack(2)

namespace arxa
{

    struct BitmapFileHeader
    {
        char header[2]{'B', 'M'};
        int32_t fileSize;
        int32_t reserved{0};
        int32_t dataOffset;
    };

}

#endif //FRACTAL_IMAGES_GENERATOR_BITMAPFILEHEADER_H
