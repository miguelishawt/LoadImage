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

#include "LoadImage.hpp"

#include <sstream>

#include <stb_image/stb_image.h>

namespace util
{
    // TODO:
    // Support different types of channels? lel
    // Look at GIMP source code for image loading perhaps, hah.
    ImageData loadImage(const std::string& path, ErrorCode* error)
    {
        if(error)
        {
            *error = ErrorCode::NO_ERROR;
        }
        
        // Load the image and get a pointer to the pixels in memory
        ImageData imageData;
        int w = 0, h = 0, channels = 0;
        unsigned char* ptr = stbi_load(path.c_str(), &w, &h, &channels, STBI_rgb_alpha);
        
        if (!(ptr && w && h))
        {
            // Error, failed to load the image
            if(error) *error = ErrorCode::FAILED_TO_LOAD_IMAGE_FROM_FILE;
            return imageData;
        }
        
        // Assign the image properties
        imageData.width = w;
        imageData.height = h;

        // Copy the loaded pixels to the pixel buffer
        imageData.pixels.reset(ptr);
        
        return imageData;
    }
    
    ImageData loadImage(const void* data, std::size_t dataSize, ErrorCode* error)
    {
        ImageData imageData;
        
        // Check input parameters
        if (data && dataSize)
        {
            // Load the image and get a pointer to the pixels in memory
            int w = 0, h = 0, channels = 0;
            const unsigned char* buffer = static_cast<const unsigned char*>(data);
            unsigned char* ptr = stbi_load_from_memory(buffer, static_cast<int>(dataSize), &w, &h, &channels, STBI_rgb_alpha);
            
            if (ptr && w && h)
            {
                // Assign the image properties
                imageData.width = w;
                imageData.height = h;
                
                // Copy the loaded pixels to the pixel buffer
                imageData.pixels.reset(ptr);
            }
            else
            {
                // Error, failed to load the image
                if(error) *error = ErrorCode::FAILED_TO_LOAD_IMAGE_FROM_MEMORY;
            }
        }
        else
        {
            if(error) *error = ErrorCode::NO_DATA_PROVIDED;
        }
        
        return imageData;
    }

    std::string errorCodeToString(const ErrorCode& errorCode)
    {
        std::ostringstream temp;
        switch(errorCode)
        {
            case ErrorCode::NO_ERROR:
                temp << "No error";
            case ErrorCode::FAILED_TO_LOAD_IMAGE_FROM_FILE:
                temp << "Failed to load image from file. Reason: " << stbi_failure_reason();
                break;
            case ErrorCode::FAILED_TO_LOAD_IMAGE_FROM_MEMORY:
                temp << "Failed to load image from memory. Reason: " << stbi_failure_reason();
                break;
            case ErrorCode::NO_DATA_PROVIDED:
                temp << "Failed to load image from memory. Reason: no data provided.";
                break;
            default:
                break;
        }
        return temp.str();
    }
}
