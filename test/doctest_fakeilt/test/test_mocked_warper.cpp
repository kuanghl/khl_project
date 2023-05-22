#include <doctest/doctest.h>

#include <cstdint>
#include <fakeit/fakeit.hpp>
#include <i_warper.hpp>
#include <limits>
#include <stdexcept>

namespace {
using fakeit::Mock;
using fakeit::When;

constexpr auto kMaxValue = std::numeric_limits<int16_t>::max();
constexpr auto kMinValue = std::numeric_limits<int16_t>::min();

template <typename Func, typename... Args>
int16_t CallMock(vva::IOperationWarper& warper, Func func, Args... args) {
  return std::invoke(func, warper, args...);
}

}  // namespace

namespace vva {
class MockedWarperTest {
 protected:
  fakeit::Mock<IOperationWarper> mockWarper_;
};

TEST_CASE_FIXTURE(MockedWarperTest,
                  "MockedWarperTestAdd_OneToTwo_Three [mock-warper]") {
  When(Method(mockWarper_, addition).Using(1, 2)).Return(3);

  REQUIRE(CallMock(mockWarper_.get(), &IOperationWarper::addition, 1, 2) == 3);
}

// This test intentionally produces wrong result
TEST_CASE_FIXTURE(MockedWarperTest,
                  "MockedWarperTestAdd_OneToTwo_Four [mock-warper]") {
  When(Method(mockWarper_, addition)).Return(4);

  REQUIRE(CallMock(mockWarper_.get(), &IOperationWarper::addition, 1, 2) == 4);
}

TEST_CASE_FIXTURE(
    MockedWarperTest,
    "MockedWarperTestAdd_SignedIntOverflowException [mock-warper]") {
  constexpr auto a = kMaxValue;
  constexpr int16_t b = 1;

  When(Method(mockWarper_, addition).Using(a, b))
      .Throw(std::overflow_error("REQUIRE_THROWS_MATCHES"));

  REQUIRE_THROWS_AS(
      CallMock(mockWarper_.get(), &IOperationWarper::addition, a, b),
      std::overflow_error);
}

TEST_CASE_FIXTURE(
    MockedWarperTest,
    "MockedWarperTestAdd_SignedIntOverflowClamped [mock-warper]") {
  constexpr auto a = kMaxValue;
  constexpr int16_t b = 1;

  When(Method(mockWarper_, addition).Using(a, b)).Return(a);

  REQUIRE(CallMock(mockWarper_.get(), &IOperationWarper::addition, a, b) == a);
}

}  // namespace vva
