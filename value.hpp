
#ifndef VALUE_HPP
#define VALUE_HPP

enum Value_kind {
  int_val,
  real_val,
};

union Value_data {
  int n;
  double d;
};

// Discriminated union or variant.
struct Value {
  Value_kind kind;
  Value_data data;
};

#endif