//
// Created by arxa on 23/3/2017.
//

#ifndef FRACTAL_IMAGES_GENERATOR_BITMAPINFOHEADER_H
#define FRACTAL_IMAGES_GENERATOR_BITMAPINFOHEADER_H

#include <cstdint>

/* By default C++ will pack our struct with padding. For this application though,
 * our struct will be written to a file so we should tell the preprocessor to pack our struct with 2-bytes boundaries,
 * which will work for our case.
*/
#pragma pack(2)

namespace arxa
{

    struct BitmapInfoHeader // Struct members are public by default, in contrast to class members which are private.
    {
        int32_t headerSize{40}; // Size of struct in bytes
        int32_t width;
        int32_t height;
        int16_t planes{1};
        int16_t bitsPerPixel{24}; // Using one byte for each color in our RGB bitmap image. 3*8=24 bits
        int32_t compression{0};
        int32_t dataSize{0}; // Initial value
        int32_t horizontalResolution{2400};
        int32_t verticalResolution{2400};
        int32_t colors{0};
        int32_t importantColors{0};
    };
}

#endif //FRACTAL_IMAGES_GENERATOR_BITMAPFILEHEADER_H
