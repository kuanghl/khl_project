#include "checked_warper.hpp"

#include <limits>
#include <stdexcept>

#include "simple_calc.hpp"

namespace {
using WarperType = int32_t;

constexpr WarperType kMaxValue = std::numeric_limits<int16_t>::max();
constexpr WarperType kMinValue = std::numeric_limits<int16_t>::min();

void checkValue(WarperType value) {
  if (value > kMaxValue) {
    throw std::overflow_error("Overflow");
  }

  if (value < kMinValue) {
    throw std::underflow_error("Underflow");
  }
}

}  // namespace

namespace vva {

CheckedOperationWarper::OperandType CheckedOperationWarper::addition(
    const OperandType& a, const OperandType& b) {
  const auto result = add<WarperType>(a, b);
  checkValue(result);

  return static_cast<OperandType>(result);
}

CheckedOperationWarper::OperandType CheckedOperationWarper::subtraction(
    const OperandType& a, const OperandType& b) {
  const auto result = subtract<WarperType>(a, b);
  checkValue(result);

  return static_cast<OperandType>(result);
}

CheckedOperationWarper::OperandType CheckedOperationWarper::multiplication(
    const OperandType& a, const OperandType& b) {
  const auto result = multiply<WarperType>(a, b);
  checkValue(result);

  return static_cast<OperandType>(result);
}

CheckedOperationWarper::OperandType CheckedOperationWarper::division(
    const OperandType& a, const OperandType& b) {
  if (b == 0) {
    throw std::invalid_argument("Division by zero");
  }

  const auto result = divide<WarperType>(a, b);
  return static_cast<OperandType>(result);
}

}  // namespace vva