#include <iostream>
#include <gtest/gtest.h>

int main(int argc, char **argv) {
  std::cout << "Runtest...\n";
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
