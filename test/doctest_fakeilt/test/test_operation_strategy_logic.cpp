#include <doctest/doctest.h>

#include <cstdint>
#include <fakeit/fakeit.hpp>
#include <i_warper.hpp>
#include <limits>
#include <operation_strategy.hpp>

namespace {
using fakeit::Mock;
using fakeit::When;
}  // namespace

namespace vva {

class MockedOperationStrategyTest {
 protected:
  fakeit::Mock<IOperationWarper> mockWarper_;
};

TEST_CASE_FIXTURE(
    MockedOperationStrategyTest,
    "MockOperationStrategy_Arg_Result [mock-operation-strategy]") {
  constexpr int16_t first_arg = 6;
  constexpr int16_t second_arg = 2;
  constexpr int16_t operation_result = 4;

  constexpr int16_t first_stage_result = 8;
  constexpr int16_t second_stage_result = 16;
  constexpr int16_t third_stage_result = 4;

  When(Method(mockWarper_, addition).Using(first_arg, second_arg))
      .Return(first_stage_result);
  When(Method(mockWarper_, multiplication).Using(first_stage_result, 2))
      .Return(second_stage_result);
  When(Method(mockWarper_, subtraction).Using(first_arg, second_arg))
      .Return(third_stage_result);
  When(Method(mockWarper_, division)
           .Using(second_stage_result, third_stage_result))
      .Return(operation_result);

  OperationStrategy test_strategy(mockWarper_.get());

  REQUIRE(test_strategy(first_arg, second_arg) == operation_result);
}

}  // namespace vva
