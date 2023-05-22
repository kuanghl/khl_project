#include "operation_strategy.hpp"

namespace vva {
OperationStrategy::OperationStrategy(IOperationWarper& warper)
    : warper_(warper) {}

int16_t OperationStrategy::operator()(const int16_t& a, const int16_t& b) {
  const auto sum = warper_.addition(a, b);

  constexpr int16_t operands_count = 2;
  const auto doubled_sum = warper_.multiplication(sum, operands_count);

  const auto difference = warper_.subtraction(a, b);

  const auto result = warper_.division(doubled_sum, difference);

  return result;
}

}  // namespace vva