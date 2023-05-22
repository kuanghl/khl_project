#include <doctest/doctest.h>

#include <basic_warper.hpp>
#include <checked_warper.hpp>
#include <clamped_warper.hpp>
#include <cstdint>
#include <operation_strategy.hpp>

namespace vva {

TEST_CASE_TEMPLATE("GeneralOperationStrategy [operation-strategy-logic]", T,
                   BasicOperationWarper, CheckedOperationWarper,
                   ClampedOperationWarper) {
  T i = T();

  OperationStrategy test_strategy(i);

  REQUIRE(test_strategy(6, 2) == 4);
}

}  // namespace vva
