#include <Multiplier.h>
#include <Adder.h>

static int multiply(int mul1, int mul2, int accumulator) {
    return 1 < mul2 ? multiply(mul1, mul2 - 1, add(accumulator, mul1))
                    : mul2 < -1 ? multiply(mul1, mul2 + 1, add(accumulator, mul1))
                                : mul2 == 1 ? add(accumulator, mul1)
                                            : mul2 == -1 ? -add(accumulator, mul1)
                                                         : accumulator;
}

int multiply(int mul1, int mul2) {
    return multiply(mul1, mul2, 0);
}