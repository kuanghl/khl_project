#pragma once

#include "i_warper.hpp"

namespace vva {

class OperationStrategy {
 public:
  OperationStrategy(IOperationWarper& warper);

  int16_t operator()(const int16_t& a, const int16_t& b);

 private:
  IOperationWarper& warper_;
};

}  // namespace vva