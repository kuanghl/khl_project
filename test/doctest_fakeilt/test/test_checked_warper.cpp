#include <doctest/doctest.h>

#include <checked_warper.hpp>
#include <cstdint>
#include <limits>
#include <stdexcept>

namespace {
constexpr auto kMaxValue = std::numeric_limits<int16_t>::max();
constexpr auto kMinValue = std::numeric_limits<int16_t>::min();
}  // namespace

namespace vva {
class CheckedWarperTest {
 protected:
  CheckedOperationWarper warper_;
};

TEST_CASE_FIXTURE(CheckedWarperTest,
                  "CheckedWarperTestAdd_OneToTwo_Three [checked-warper]") {
  REQUIRE(warper_.addition(1, 2) == 3);
}

TEST_CASE_FIXTURE(
    CheckedWarperTest,
    "CheckedWarperTestAdd_SignedIntOverflow_Exception [checked-warper]") {
  constexpr auto a = kMaxValue;
  constexpr int16_t b = 1;
  REQUIRE_THROWS_AS(warper_.addition(a, b), std::overflow_error);
}

TEST_CASE_FIXTURE(
    CheckedWarperTest,
    "CheckedWarperTestAdd_SignedIntUnderflow_Exception [checked-warper]") {
  constexpr auto a = kMinValue;
  constexpr int16_t b = -1;
  REQUIRE_THROWS_AS(warper_.addition(a, b), std::underflow_error);
}

TEST_CASE_FIXTURE(
    CheckedWarperTest,
    "CheckedWarperTestSubtract_ThreeByFive_Two [checked-warper]") {
  REQUIRE(warper_.subtraction(5, 3) == 2);
}

TEST_CASE_FIXTURE(
    CheckedWarperTest,
    "CheckedWarperTestSubtract_SignedIntOverflow_Exception [checked-warper]") {
  constexpr auto a = kMinValue;
  constexpr int16_t b = 1;
  REQUIRE_THROWS_AS(warper_.subtraction(a, b), std::underflow_error);
}

TEST_CASE_FIXTURE(
    CheckedWarperTest,
    "CheckedWarperTestSubtract_SignedIntUnderflow_Exception [checked-warper]") {
  constexpr auto a = kMaxValue;
  constexpr int16_t b = -1;
  REQUIRE_THROWS_AS(warper_.subtraction(a, b), std::overflow_error);
}

TEST_CASE_FIXTURE(
    CheckedWarperTest,
    "CheckedWarperTestMultiply_FiveBySix_Thirty [checked-warper]") {
  REQUIRE(warper_.multiplication(5, 6) == 30);
}

TEST_CASE_FIXTURE(
    CheckedWarperTest,
    "CheckedWarperTestMultiply_SignedIntOverflow_Exception [checked-warper]") {
  constexpr auto a = kMaxValue;
  constexpr int16_t b = 2;
  REQUIRE_THROWS_AS(warper_.multiplication(a, b), std::overflow_error);
}

TEST_CASE_FIXTURE(
    CheckedWarperTest,
    "CheckedWarperTestMultiply_SignedIntUnderflow_Exception [checked-warper]") {
  constexpr auto a = kMinValue;
  constexpr int16_t b = 2;
  REQUIRE_THROWS_AS(warper_.multiplication(a, b), std::underflow_error);
}

TEST_CASE_FIXTURE(CheckedWarperTest,
                  "CheckedWarperTestDivide_TenByTwo_Five [checked-warper]") {
  REQUIRE(warper_.division(10, 2) == 5);
}

TEST_CASE_FIXTURE(
    CheckedWarperTest,
    "CheckedWarperTestDivide_DivisionByZero_Exception [checked-warper]") {
  constexpr auto a = 10;
  constexpr int16_t b = 0;
  REQUIRE_THROWS_AS(warper_.division(a, b), std::invalid_argument);
}

}  // namespace vva
