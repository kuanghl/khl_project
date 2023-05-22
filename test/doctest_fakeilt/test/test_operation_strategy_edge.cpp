#include <doctest/doctest.h>

#include <basic_warper.hpp>
#include <checked_warper.hpp>
#include <clamped_warper.hpp>
#include <cstdint>
#include <limits>
#include <operation_strategy.hpp>
#include <stdexcept>

namespace {
constexpr auto kMaxValue = std::numeric_limits<int16_t>::max();
constexpr auto kMinValue = std::numeric_limits<int16_t>::min();
}  // namespace

namespace vva {

class StrategyClampedTest {
 protected:
  ClampedOperationWarper warper_;
  OperationStrategy test_strategy_{warper_};
};

TEST_CASE_FIXTURE(
    StrategyClampedTest,
    "StrategyClampedTest_FirstStageOverflow_Exception [operation-strategy]") {
  constexpr auto a = kMaxValue;
  constexpr int16_t b = 1;
  REQUIRE(test_strategy_(a, b) == 1);
}

TEST_CASE_FIXTURE(
    StrategyClampedTest,
    "StrategyClampedTest_FirstStageUnderflow_Exception [operation-strategy]") {
  constexpr auto a = kMinValue;
  constexpr int16_t b = -1;
  REQUIRE(test_strategy_(a, b) == 1);
}

TEST_CASE_FIXTURE(
    StrategyClampedTest,
    "StrategyClampedTest_SecondStageOverflow_Exception [operation-strategy]") {
  constexpr auto a = kMaxValue / 2;
  constexpr int16_t b = 1;
  REQUIRE(test_strategy_(a, b) == 2);
}

TEST_CASE_FIXTURE(
    StrategyClampedTest,
    "StrategyClampedTest_SecondStageUnderflow_Exception [operation-strategy]") {
  constexpr auto a = kMinValue / 2;
  constexpr int16_t b = -1;
  REQUIRE(test_strategy_(a, b) == 2);
}

TEST_CASE_FIXTURE(
    StrategyClampedTest,
    "StrategyClampedTest_ThirdStageOverflow_Exception [operation-strategy]") {
  constexpr auto a = 1 + kMaxValue / 2;
  constexpr int16_t b = kMinValue / 2;
  REQUIRE(test_strategy_(a, b) == 0);
}

TEST_CASE_FIXTURE(
    StrategyClampedTest,
    "StrategyClampedTest_ThirdStageUnderflow_Exception [operation-strategy]") {
  constexpr auto a = 1 - kMaxValue / 2;
  constexpr int16_t b = kMinValue / 2;
  REQUIRE(test_strategy_(a, b) == kMinValue / 2);
}

TEST_CASE_FIXTURE(StrategyClampedTest,
                  "StrategyClampedTest_ThirdStagedivisionByZero_Exception "
                  "[operation-strategy]") {
  constexpr auto a = 1;
  constexpr int16_t b = 1;
  REQUIRE_THROWS_AS(test_strategy_(a, b), std::invalid_argument);
}

class StrategyCheckedTest {
 protected:
  CheckedOperationWarper warper_;
  OperationStrategy test_strategy_{warper_};
};

TEST_CASE_FIXTURE(
    StrategyCheckedTest,
    "StrategyCheckedTest_FirstStageOverflow_Exception [operation-strategy]") {
  constexpr auto a = kMaxValue;
  constexpr int16_t b = 1;
  REQUIRE_THROWS_AS(test_strategy_(a, b), std::overflow_error);
}

TEST_CASE_FIXTURE(
    StrategyCheckedTest,
    "StrategyCheckedTest_FirstStageUnderflow_Exception [operation-strategy]") {
  constexpr auto a = kMinValue;
  constexpr int16_t b = -1;
  REQUIRE_THROWS_AS(test_strategy_(a, b), std::underflow_error);
}

TEST_CASE_FIXTURE(
    StrategyCheckedTest,
    "StrategyCheckedTest_SecondStageOverflow_Exception [operation-strategy]") {
  constexpr auto a = kMaxValue / 2;
  constexpr int16_t b = 1;
  REQUIRE_THROWS_AS(test_strategy_(a, b), std::overflow_error);
}

TEST_CASE_FIXTURE(
    StrategyCheckedTest,
    "StrategyCheckedTest_SecondStageUnderflow_Exception [operation-strategy]") {
  constexpr auto a = kMinValue / 2;
  constexpr int16_t b = -1;
  REQUIRE_THROWS_AS(test_strategy_(a, b), std::underflow_error);
}

TEST_CASE_FIXTURE(
    StrategyCheckedTest,
    "StrategyCheckedTest_ThirdStageOverflow_Exception [operation-strategy]") {
  constexpr auto a = 1 + kMaxValue / 2;
  constexpr int16_t b = kMinValue / 2;
  REQUIRE_THROWS_AS(test_strategy_(a, b), std::overflow_error);
}

TEST_CASE_FIXTURE(
    StrategyCheckedTest,
    "StrategyCheckedTest_ThirdStageUnderflow_Exception [operation-strategy]") {
  constexpr auto a = 1 - kMaxValue / 2;
  constexpr int16_t b = kMinValue / 2;
  REQUIRE_THROWS_AS(test_strategy_(a, b), std::underflow_error);
}

TEST_CASE_FIXTURE(StrategyCheckedTest,
                  "StrategyCheckedTest_ThirdStagedivisionByZero_Exception "
                  "[operation-strategy]") {
  constexpr auto a = 1;
  constexpr int16_t b = 1;
  REQUIRE_THROWS_AS(test_strategy_(a, b), std::invalid_argument);
}

}  // namespace vva
