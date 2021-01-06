#include "color.hh"

class MyImage
{
public:
    uint32_t *pixels;
    int width;
    int height;

    MyImage(const char *path);

    virtual ~MyImage()
    {
        delete[] pixels;
    };
};

