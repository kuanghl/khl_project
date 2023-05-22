#include <doctest/doctest.h>

#include <clamped_warper.hpp>
#include <cstdint>
#include <limits>
#include <stdexcept>

namespace {
constexpr auto kMaxValue = std::numeric_limits<int16_t>::max();
constexpr auto kMinValue = std::numeric_limits<int16_t>::min();
}  // namespace

namespace vva {
class ClampedWarperTest {
 protected:
  ClampedOperationWarper warper_;
};

TEST_CASE_FIXTURE(ClampedWarperTest,
                  "ClampedWarperTestAdd_OneToTwo_Three [clamped-warper]") {
  REQUIRE(warper_.addition(1, 2) == 3);
}

TEST_CASE_FIXTURE(
    ClampedWarperTest,
    "ClampedWarperTestAdd_SignedIntOverflow_ClampedToMax [clamped-warper]") {
  constexpr auto a = kMaxValue;
  constexpr int16_t b = 1;
  REQUIRE(warper_.addition(a, b) == kMaxValue);
}

TEST_CASE_FIXTURE(
    ClampedWarperTest,
    "ClampedWarperTestAdd_SignedIntUnderflow_ClampedToMin [clamped-warper]") {
  constexpr auto a = kMinValue;
  constexpr int16_t b = -1;
  REQUIRE(warper_.addition(a, b) == kMinValue);
}

TEST_CASE_FIXTURE(
    ClampedWarperTest,
    "ClampedWarperTestSubtract_ThreeByFive_Two [clamped-warper]") {
  REQUIRE(warper_.subtraction(5, 3) == 2);
}

TEST_CASE_FIXTURE(ClampedWarperTest,
                  "ClampedWarperTestSubtract_SignedIntOverflow_ClampedToMax "
                  "[clamped-warper]") {
  constexpr auto a = kMinValue;
  constexpr int16_t b = 1;
  REQUIRE(warper_.subtraction(a, b) == kMinValue);
}

TEST_CASE_FIXTURE(ClampedWarperTest,
                  "ClampedWarperTestSubtract_SignedIntUnderflow_ClampedToMin "
                  "[clamped-warper]") {
  constexpr auto a = kMaxValue;
  constexpr int16_t b = -1;
  REQUIRE(warper_.subtraction(a, b) == kMaxValue);
}

TEST_CASE_FIXTURE(
    ClampedWarperTest,
    "ClampedWarperTestMultiply_FiveBySix_Thirty [clamped-warper]") {
  REQUIRE(warper_.multiplication(5, 6) == 30);
}

TEST_CASE_FIXTURE(ClampedWarperTest,
                  "ClampedWarperTestMultiply_SignedIntOverflow_ClampedToMax "
                  "[clamped-warper]") {
  constexpr auto a = kMaxValue;
  constexpr int16_t b = 2;
  REQUIRE(warper_.multiplication(a, b) == kMaxValue);
}

TEST_CASE_FIXTURE(ClampedWarperTest,
                  "ClampedWarperTestMultiply_SignedIntUnderflow_ClampedToMin "
                  "[clamped-warper]") {
  constexpr auto a = kMinValue;
  constexpr int16_t b = 2;
  REQUIRE(warper_.multiplication(a, b) == kMinValue);
}

TEST_CASE_FIXTURE(ClampedWarperTest,
                  "ClampedWarperTestDivide_TenByTwo_Five [clamped-warper]") {
  REQUIRE(warper_.division(10, 2) == 5);
}

TEST_CASE_FIXTURE(
    ClampedWarperTest,
    "ClampedWarperTestDivide_DivisionByZero_Exception [clamped-warper]") {
  constexpr auto a = 10;
  constexpr int16_t b = 0;
  REQUIRE_THROWS_AS(warper_.division(a, b), std::invalid_argument);
}

}  // namespace vva
