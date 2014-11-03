# LoadImage

Contains simple functions to load images. It is just a header/source file, so just a drag and drop is required. All code is within the namespace `li`.

# Usage

```c++
li::error error;

li::image_data data{li::load("cheese.png", &error)};

if(!data.pixels)
{
    std::cerr << "Failed to load image\n";
    std::cerr << "Reason:\n";
    std::cerr << error << '\n';
}

// ... do something with the image
```

# Dependencies

This library requires stb_image, which is located within the `extlibs` directory.

# NOTES

This library has taken some source code from the SFML library, however, I have altered it a little bit. Here are the differences:

1. SFML copies the data returned from `stb_image`, and stores it within a `vector`. I simply "move" the data, with the use of a `unique_ptr` (I basically copy the pointer to the data that `stb_image` returns).
2. I return the image data, instead of allowing it to be passed by reference. As it is a more C++11 approach.
3. Since `std::unique_ptr` is used, memory is managed for you, but if you want to transfer ownership (that is, you want to manage the memory), then you can simply call `release()`. Thus the RAII pattern is used to it's fullest.

# License

See [LICENSE](LICENSE)
