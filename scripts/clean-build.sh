rm -rf build

cmake -B build -S . -G "Ninja" -D CMAKE_C_COMPILER=clang -D CMAKE_CXX_COMPILER=clang++ -D CMAKE_BUILD_TYPE=Release -D OpenCV_DIR="C:/opencv-cmake-install"
