#pragma once

#include <cstdint>

namespace vva {

class IOperationWarper {
 public:
  virtual ~IOperationWarper() = default;

  virtual int16_t addition(const int16_t& a, const int16_t& b) = 0;

  virtual int16_t subtraction(const int16_t& a, const int16_t& b) = 0;

  virtual int16_t multiplication(const int16_t& a, const int16_t& b) = 0;

  virtual int16_t division(const int16_t& a, const int16_t& b) = 0;
};

}  // namespace vva