#cmake -S . -B build;
cmake --build  build\;
ctest --test-dir build   -C Debug
#cmake --install build --config Debug   -v --prefix  .