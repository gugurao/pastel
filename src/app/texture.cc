#include <cstring>
#include "texture.hh"

Texture::Texture(const char *path)
{
}

Color Texture::sample(float u, float v) const
{
    if (_pixels != NULL)
    {
        int tu = abs((int)(u * (_width - 1)));
        int tv = abs((int)(v * (_height - 1)));

        int index = tu + tv * _width;
        Color c = Color(_pixels[index]);

        return c;
    }
    else
    {
        return Color();
    }
}