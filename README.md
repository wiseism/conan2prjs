# README

asio
poco
grpc
zlib
qt6
opencv
创建库


conan new cmake_exe -d name=conan2opencvtest -d version=0.1 -f

conan new cmake_exe -d name=conan2grpctest -d version=0.1 -f

conan new cmake_exe -d name=conan2thrifttest -d version=0.1 -f

conan new cmake_exe -d name=conan2pocotest -d version=0.1 -f
conan new cmake_exe -d name=conan2zlibtest -d version=0.1 -f
D:\dev_tools\Conan\conan\conan.exe new cmake_exe -d name=conan2asiotest -d version=0.1 -f

D:\dev_tools\Conan\conan\conan.exe install -u ./ --build=missing