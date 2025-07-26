#include <iostream>
#include "constexprmath.h"

using namespace cexprm;

int main(void) {
    double arg = TAU / 100;
    for (int i = 0; i < 100; i++) {
        arg += TAU / 100;
        double csin = cexprm::sin(arg);
        double ssin = std::sin(arg);
        double sub = std::fabs(csin - ssin);
        printf("cexprm::sin(%f) = %.16ff, sin(%f) = %.16f, err = %.16f\n", arg, csin, arg, ssin, sub);
    }
    for (int i = 0; i < 100; i++) {
        arg += TAU / 100;
        double ccos = cexprm::cos(arg);
        double scos = std::cos(arg);
        double sub = std::fabs(ccos - scos);
        printf("cexprm::cos(%f) = %.16ff, cos(%f) = %.16f, err = %.16f\n", arg, ccos, arg, scos, sub);
    }
    return 0;
}
