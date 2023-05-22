#include <doctest/doctest.h>

#include <cstdint>
#include <simple_calc.hpp>

namespace vva {
TEST_CASE("TestAdd_OneToTwo_Three [simple-calc]") { REQUIRE(add(1, 2) == 3); }

TEST_CASE("TestAdd_UnsignedIntOverflow [simple-calc]") {
  constexpr uint8_t a = 255;
  constexpr uint8_t b = 1;
  // Note: 8 bit integer will be printed as char
  REQUIRE(add(a, b) == 0);
}

TEST_CASE("TestAdd_SignedIntOverflow [simple-calc]") {
  constexpr int8_t a = 127;
  constexpr int8_t b = 1;
  // Note: 8 bit integer will be printed as char
  REQUIRE(int(add(a, b)) == -128);
}

TEST_CASE("TestSubtract_ThreeByFive_Two [simple-calc]") {
  REQUIRE(subtract(5, 3) == 2);
}

TEST_CASE("TestMultiply_FiveBySix_Thirty [simple-calc]") {
  REQUIRE(multiply(5, 6) == 30);
}

TEST_CASE("TestDivide_TenByTwo_Five [simple-calc]") {
  REQUIRE(divide(10, 2) == 5);
}

}  // namespace vva
