#pragma once

#include "i_warper.hpp"

namespace vva {

class BasicOperationWarper : public IOperationWarper {
 public:
  ~BasicOperationWarper() override = default;

  int16_t addition(const int16_t& a, const int16_t& b) override;

  int16_t subtraction(const int16_t& a, const int16_t& b) override;

  int16_t multiplication(const int16_t& a, const int16_t& b) override;

  int16_t division(const int16_t& a, const int16_t& b) override;
};

}  // namespace vva