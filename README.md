# LoadImage

Contains simple functions to load images. It is just a header/source file, so just a drag and drop is required. All code is under a `util` namespace, standing for utility.

# Usage

```c++
ImageData data{util::loadImage("cheese.png")};
if(!data.pixels)
{
    std::cerr << "Failed to load image\n";
}

// ... do something with the image
```

# Dependencies

This library requires stb_image, which is located within the `extlibs` directory.

# NOTES

This library has taken some source code from the SFML library, however, I have altered it a little bit. Returning the image data is one major difference, as it seems more natural to do so (plus the fact that C++11 supports moving now more than ever). Also, `std::unique_ptr` is used, that way memory is managed for you, but you can take over managament by a call to `release()`.

# License
Copyright (C) 2013 Miguel Martin (miguel.martin7.5@hotmail.com)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
