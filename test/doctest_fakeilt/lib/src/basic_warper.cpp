#include "basic_warper.hpp"

#include "simple_calc.hpp"

namespace vva {

int16_t BasicOperationWarper::addition(const int16_t& a, const int16_t& b) {
  return add(a, b);
}

int16_t BasicOperationWarper::subtraction(const int16_t& a, const int16_t& b) {
  return subtract(a, b);
}

int16_t BasicOperationWarper::multiplication(const int16_t& a,
                                             const int16_t& b) {
  return multiply(a, b);
}

int16_t BasicOperationWarper::division(const int16_t& a, const int16_t& b) {
  return divide(a, b);
}

}  // namespace vva