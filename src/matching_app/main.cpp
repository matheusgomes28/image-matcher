#include <fmt/format.h>
#include <opencv2/opencv.hpp>

// Contains cout cin
#include <iostream>
#include <vector>
#include <utility>

namespace
{
    cv::Mat convert_to_grayscale(cv::Mat const& colour_image)
    {
        cv::Mat gray_image;
        cv::cvtColor(colour_image, gray_image, cv::COLOR_BGR2RGB);
        return gray_image;
    }

    std::vector<std::pair<int, int>> find_match_positions(cv::Mat const& match_array, float thresh)
    {
        std::vector<std::pair<int, int>> positions;

        for (int y = 0; y < match_array.rows; ++y)
        {
            for (int x = 0; x < match_array.cols; ++x)
            {
                auto const pixel_val = match_array.at<float>(y, x);
                if (pixel_val >= thresh)
                {
                    positions.push_back({y, x});
                }
            }
        }
        return positions;
    }
} // namespace
 
int main(int argc, char** argv)
{
    // Make sure we have the full image
    // and also the template image passed in
    // as arguments
    if (argc != 3)
    {
        std::cout << "Please pass two images as arguments to program.\n";
        return -1;
    }

    
    // read both images in full RGB colour
    cv::Mat full_image = cv::imread(argv[1]);
    cv::Mat little_image = cv::imread(argv[2]);

    if (full_image.empty())
    {
        std::cerr << fmt::format("could not find or open image {}", argv[1]);
        return -1;
    }

    if (little_image.empty())
    {
        std::cerr << fmt::format("could not find or open image {}", argv[2]);
        return -1;
    }

    fmt::print("Size of full image: ({0}, {1})\n", full_image.rows, full_image.cols);
    fmt::print("Size of template image: ({0}, {1})\n", little_image.rows, little_image.cols);

    // Convert images to gray
    cv::Mat const full_image_gray = convert_to_grayscale(full_image);
    cv::Mat const little_image_gray = convert_to_grayscale(little_image);
    
    cv::Mat template_matches;
    cv::matchTemplate(full_image_gray, little_image_gray, template_matches, cv::TM_CCOEFF_NORMED);

    // Find the positions of the matches & draw a rectangle
    auto const positons = find_match_positions(template_matches, 0.9f);
    for (auto const& pos : positons)
    {
        cv::rectangle(full_image, {pos.second, pos.first}, {pos.second + little_image.cols, pos.first + little_image.rows}, {0, 0, 255});
    }
    
    cv::namedWindow("Image", cv::WINDOW_NORMAL); // Create window
    cv::imshow("Image", full_image); // Show image in the window
    
    cv::waitKey(0); // Wait for a key press
    return 0;
}