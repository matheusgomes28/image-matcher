from conans import ConanFile

class CvMatch(ConanFile):
    generators = "cmake_find_package"
    requires = [
        "fmt/9.1.0",
        "opencv/4.5.3",
        "xz_utils/5.4.0"
    ]

