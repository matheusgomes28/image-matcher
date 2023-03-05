#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat image = cv::imread("image.jpg"); // Load image from file
    
    if (image.empty()) // Check if image was loaded successfully
    {
        std::cerr << "Error: Could not open or find the image" << std::endl;
        return 1;
    }
    
    cv::namedWindow("Image", cv::WINDOW_NORMAL); // Create window
    cv::imshow("Image", image); // Show image in the window
    
    cv::waitKey(0); // Wait for a key press
    
    return 0;
}