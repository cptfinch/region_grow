// Convert a file from PNM format to BMP format
#include "core/io/bmp_output.hpp"
#include "utils/rgb_pixel.hpp"

int main() {
    constexpr unsigned width = 200;
    constexpr unsigned height = 200;
    
    try {
        image_io::BMPOutputStream out_file("test_pattern.bmp", width, height);
        
        // Define colors using modern initializers
        const image_utils::rgb_pixel colors[] = {
            {255, 0, 0},    // Red
            {0, 255, 0},    // Green
            {0, 0, 255},    // Blue
            {255, 255, 128} // Yellow
        };

        // Generate quadrant pattern
        for(unsigned row = 0; row < height; ++row) {
            for(unsigned col = 0; col < width; ++col) {
                const unsigned quadrant = (row/(height/2)) * 2 + (col/(width/2));
                out_file.write(&colors[quadrant], 1);
            }
        }
        
        return 0;
    }
    catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return -1;
    }
}
