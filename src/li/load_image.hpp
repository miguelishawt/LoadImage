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

#ifndef LI_LOADIMAGE_HPP
#define LI_LOADIMAGE_HPP

#include <memory>
#include <string>
#include <cstdint>

namespace li
{
    /// \brief A data structure that describes information present within an image
    ///
    /// \author Miguel Martin
    struct image_data
    {
        std::unique_ptr<std::uint8_t[]> pixels;
        unsigned int width;
        unsigned int height;
        
        explicit operator bool() const
        { return pixels.get() != nullptr; }
    };
   
    /// \brief An enumeration that describes an error code
    enum class error
    {
        NO_ERROR = 0,
        FAILED_TO_LOAD_IMAGE_FROM_FILE,
        FAILED_TO_LOAD_IMAGE_FROM_MEMORY,
        NO_DATA_PROVIDED
    };

    /// Loads image data into memory
    /// \param path The path to the image
    /// \param error An optional error code, to determine how the function fails (if it does)
    /// \return The image data loaded from the file.
    /// \note If this method fails, the pixels of the image will be a nullptr
    image_data load(const std::string& path, error* error = nullptr);
    
    /// Loads image data into memory
    /// \param data The data of the image
    /// \param dataSize The size of the data
    /// \param error An optional error code, to determine how the function fails (if it does)
    /// \note If this method fails, the pixels of the image will be a nullptr
    image_data load(const void* data, std::size_t dataSize, error* error = nullptr);

    std::ostream& operator<<(std::ostream& o, const error& error);
}

#endif // __UTIL_LOADIMAGE_HPP__
