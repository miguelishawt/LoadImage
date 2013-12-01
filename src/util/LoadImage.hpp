///
/// LoadImage
/// Copyright (C) 2013 Miguel Martin (miguel.martin7.5@hotmail.com)
///
///
/// This software is provided 'as-is', without any express or implied warranty.
/// In no event will the authors be held liable for any damages arising from the
/// use of this software.
///
/// Permission is hereby granted, free of charge, to any person
/// obtaining a copy of this software and associated documentation files (the "Software"),
/// to deal in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// 1. The origin of this software must not be misrepresented;
///    you must not claim that you wrote the original software.
///    If you use this software in a product, an acknowledgment
///    in the product documentation would be appreciated but is not required.
///
/// 2. Altered source versions must be plainly marked as such,
///	   and must not be misrepresented as being the original software.
///
/// 3. The above copyright notice and this permission notice shall be included in
///    all copies or substantial portions of the Software.
///

#ifndef __UTIL_LOADIMAGE_HPP__
#define __UTIL_LOADIMAGE_HPP__

#include <memory>
#include <string>
#include <cstdint>

namespace util
{
    struct ImageData
    {
        std::unique_ptr<std::uint8_t[]> pixels;
        unsigned int width;
        unsigned int height;
    };
    
    /// Loads image data into memory
    /// \param path The path to the image
    /// \return The image data loaded from the file.
    /// \note If this method fails, the pixels of the image a nullptr
    ImageData loadImage(const std::string& path);
    
    /// Loads image data into memory
    /// \param data The data of the image
    /// \param dataSize The size of the data
    /// \note If this method fails, the pixels of the image a nullptr
    ImageData loadImage(const void* data, std::size_t dataSize);
}

#endif // __UTIL_LOADIMAGE_HPP__