#include "color.hh"

Color::Color(float red, float green, float blue, float alpha)
{
    this->r = red;
    this->g = green;
    this->b = blue;
    this->a = alpha;
}

Color::Color(uint32_t rgba)
{
    this->r = ((rgba & 0xff000000) >> 24) / 255.0f;
    this->g = ((rgba & 0x00ff0000) >> 16) / 255.0f;
    this->b = ((rgba & 0x0000ff00) >> 8) / 255.0f;
    this->a = (rgba & 0x000000ff) / 255.0f;
}

uint32_t Color::uint32() const
{
    uint32_t R = (uint32_t)(r * 255.0f);
    uint32_t G = (uint32_t)(g * 255.0f);
    uint32_t B = (uint32_t)(b * 255.0f);
    uint32_t A = (uint32_t)(a * 255.0f);
    uint32_t value = (A << 24) | (R << 16) | (G << 8) | B;
    return value;
}
