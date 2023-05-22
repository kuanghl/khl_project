#pragma once

#include "i_warper.hpp"

namespace vva {

class CheckedOperationWarper : public IOperationWarper {
 public:
  using OperandType = int16_t;

  ~CheckedOperationWarper() override = default;

  int16_t addition(const OperandType& a, const OperandType& b) override;

  int16_t subtraction(const OperandType& a, const OperandType& b) override;

  int16_t multiplication(const OperandType& a, const OperandType& b) override;

  int16_t division(const OperandType& a, const OperandType& b) override;
};

}  // namespace vva