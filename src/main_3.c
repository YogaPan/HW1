#include <stdio.h>
#include <math.h>

#define FUNC(x, v) (pow(x, 2) - v)  // x^2 - v
#define FUNC_2(x) (2 * x)  // 2x

void test_case(double v);

int main(void)
{
    test_case(729);
    test_case(1500);
    test_case(-72);

    return 0;
}

void test_case(double v)
{
    const int n = 100;
    const double tol = 0.0001;
    double p0, p1;
    int success = 0;

    // Basic information.
    printf("tol = %lf, N = %d\n\n", tol, n);
    printf("N        p               f(p)\n");

    p1 = v;

    for (int i = 0; i < n; i++) {
        p0 = p1;
        p1 = p0 - FUNC(p0, v) / FUNC_2(p0);

        printf("%-8d %-15lf %-15lf\n", i + 1, p1, FUNC(p1, v));

        if (fabs((p1 - p0) / p0) < tol) {
            success = 1;
            break;
        }   
    }

    if (success) {
        printf("Success!!\n\n\n");
    } else {
        printf("Fail!!\n\n\n");
    }
}