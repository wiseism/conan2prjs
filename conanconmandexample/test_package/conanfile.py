import os

from conans import ConanFile, CMake, tools


class ConanexampleTestConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"
    requires = "gtest/1.8.1", "cjson/1.7.12", "grpc/1.48.0", "openssl/1.1.1s", "zlib/1.2.13"

    def generate(self):
        gtest = self.dependencies["gtest"]
        # access to members
        gtest.ref.version
        gtest.ref.revision # recipe revision
        gtest.options
        gtest.settings
        for require, dependency in self.dependencies.items():
            self.output.info("Dependency is direct={}: {}".format(require.direct, dependency.ref))

    def build(self):
        cmake = CMake(self)
        # Current dir is "test_package/build/<build_id>" and CMakeLists.txt is
        # in "test_package"
        cmake.configure()
        cmake.build()

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")
        self.copy('*.so*', dst='bin', src='lib')

    def test(self):
        if not tools.cross_building(self):
            os.chdir("bin")
            self.run(".%sexample" % os.sep)
