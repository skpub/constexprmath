#pragma once

#include <cmath>
#include <cstdint>

namespace cexprm
{
    constexpr double PI = 3.1415926535897932384626433832795028841971;
    constexpr double TAU = 2.0 * PI;

    constexpr double pow(double base, int exp) {
        return (exp == 0) ? 1.0 : base * pow(base, exp - 1);
    }

    constexpr double sin(double angle) {
        angle = std::fabs(std::fmod(angle, TAU));
        // std::fmod is constexpr since C++23.
        // c.f. https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2021/p0533r9.pdf
        bool negative_value = angle > PI;
        angle = std::fmod(angle, PI);

        if (angle > PI / 2) {
            angle = PI - angle;
        }

        double result = 0.0;

        if (angle < PI / 4) {
            // sin expansion
            double angle_sq = angle * angle;
            double current_term = angle;
            result = current_term;
            for (int k = 1; k < 12; k++) {
                current_term *= -angle_sq / ((2 * k + 1) * (2 * k));
                result += current_term;
            }
        } else {
            // angle >= PI / 4
            // cos expansion
            // cos(theta) = sin(theta + pi / 2)
            angle -= PI / 2;
            result += 1.0;

            double angle_sq = angle * angle;
            double current_term = 1.0;

            for (int k = 1; k < 12; k++) {
                current_term *= -angle_sq / ((2 * k - 1) * (2 * k));
                result += current_term;
            }
        }

        return negative_value ? -result : result;
    }

    constexpr double cos(double angle) {
        return sin(angle + PI / 2);
    }
}
