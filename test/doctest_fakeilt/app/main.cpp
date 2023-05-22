#include <iostream>

#include "basic_warper.hpp"
#include "checked_warper.hpp"
#include "clamped_warper.hpp"
#include "simple_calc.hpp"

int main() {
  const int a = 4;
  const int b = 2;

  std::cout << "a+b = " << vva::add(a, b) << '\n';
  std::cout << "a-b = " << vva::subtract(a, b) << '\n';
  std::cout << "a*b = " << vva::multiply(a, b) << '\n';
  std::cout << "a/b = " << vva::divide(a, b) << '\n';

  vva::BasicOperationWarper basic_warper;
  std::cout << "BasicOperationWarper a+b = " << basic_warper.addition(a, b)
            << '\n';
  std::cout << "BasicOperationWarper a-b = " << basic_warper.subtraction(a, b)
            << '\n';
  std::cout << "BasicOperationWarper a*b = "
            << basic_warper.multiplication(a, b) << '\n';
  std::cout << "BasicOperationWarper a/b = " << basic_warper.division(a, b)
            << '\n';

  vva::ClampedOperationWarper clamped_warper;
  std::cout << "ClampedOperationWarper a+b = " << clamped_warper.addition(a, b)
            << '\n';
  std::cout << "ClampedOperationWarper a-b = "
            << clamped_warper.subtraction(a, b) << '\n';
  std::cout << "ClampedOperationWarper a*b = "
            << clamped_warper.multiplication(a, b) << '\n';
  std::cout << "ClampedOperationWarper a/b = " << clamped_warper.division(a, b)
            << '\n';

  vva::CheckedOperationWarper checked_warper;
  std::cout << "CheckedOperationWarper a+b = " << checked_warper.addition(a, b)
            << '\n';
  std::cout << "CheckedOperationWarper a-b = "
            << checked_warper.subtraction(a, b) << '\n';
  std::cout << "CheckedOperationWarper a*b = "
            << checked_warper.multiplication(a, b) << '\n';
  std::cout << "CheckedOperationWarper a/b = " << checked_warper.division(a, b)
            << '\n';

  return 0;
}
