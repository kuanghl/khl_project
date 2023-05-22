#include "clamped_warper.hpp"

#include <limits>
#include <stdexcept>

#include "simple_calc.hpp"

namespace {
using WarperType = int32_t;

constexpr WarperType kMaxValue = std::numeric_limits<int16_t>::max();
constexpr WarperType kMinValue = std::numeric_limits<int16_t>::min();

WarperType clampValue(WarperType value) {
  if (value > kMaxValue) {
    return kMaxValue;
  }

  if (value < kMinValue) {
    return kMinValue;
  }

  return value;
}

}  // namespace

namespace vva {

ClampedOperationWarper::OperandType ClampedOperationWarper::addition(
    const OperandType& a, const OperandType& b) {
  const auto result = add<WarperType>(a, b);

  const auto clamped_result = clampValue(result);
  return static_cast<OperandType>(clamped_result);
}

ClampedOperationWarper::OperandType ClampedOperationWarper::subtraction(
    const OperandType& a, const OperandType& b) {
  const auto result = subtract<WarperType>(a, b);

  const auto clamped_result = clampValue(result);
  return static_cast<OperandType>(clamped_result);
}

ClampedOperationWarper::OperandType ClampedOperationWarper::multiplication(
    const OperandType& a, const OperandType& b) {
  const auto result = multiply<WarperType>(a, b);

  const auto clamped_result = clampValue(result);
  return static_cast<OperandType>(clamped_result);
}

ClampedOperationWarper::OperandType ClampedOperationWarper::division(
    const OperandType& a, const OperandType& b) {
  if (b == 0) {
    throw std::invalid_argument("Division by zero");
  }

  const auto result = divide<WarperType>(a, b);
  return static_cast<OperandType>(result);
}

}  // namespace vva