#include "./program.h"

program::program(): code_(0) {}
program::~program() {}

int program::code() {
  return this->code_;
}

void program::code(const int &code) {
  code_ = code;
}

void program::compute() { }