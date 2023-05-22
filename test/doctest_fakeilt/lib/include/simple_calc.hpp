#pragma once

namespace vva {

template <typename T>
T add(const T& a, const T& b) {
  return a + b;
}

template <typename T>
T subtract(const T& a, const T& b) {
  return a - b;
}

template <typename T>
T multiply(const T& a, const T& b) {
  return a * b;
}

template <typename T>
T divide(const T& a, const T& b) {
  return a / b;
}

}  // namespace vva