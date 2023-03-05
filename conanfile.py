from conans import ConanFile

class CvMatch(ConanFile):
    generators = "cmake_find_package"

    def build_requirements(self):
        self.tool_requires("opencv/4.5.3")
        # self.test_requires("gtest/0.1")


