#include <stdio.h>
#include <math.h>

#define FUNC_1(x) (pow(x, 3) + 4 * pow(x, 2) - 10)  // x^3 + 4x^2 - 10
#define FUNC_2(x) (pow(x, 2) - exp(-x))  // x^2 - e^(-x)

void test_case_1(void);
void test_case_2(void);
void test_case_3(void);

int main(void)
{
	test_case_1();
	test_case_2();
	test_case_3();

	return 0;
}

void test_case_1(void)
{
	const double tol = 0.0005;
	const int n = 100;
	double a = 1, b = 2;
	int success = 0;

	// Show basic information.
	printf("TOL = %0.4lf, N = %d\n", tol, n);
	printf("a = %0.0lf, b = %0.0lf\n\n", a, b);
	printf("n        a               b               p1              p2              f(p1)           f(p2)\n");

	for (int i = 0; i < n; i++) {
		double interval;
		double p1, p2;
		double fa, fb, fp1, fp2;

		if (b - a < tol) {
			success = 1;
			break;
		}

		interval = (b - a) / 3;
		p1       = a + interval;
		p2       = a + interval * 2;

		fa  = FUNC_1(a);
		fb  = FUNC_1(b);
		fp1 = FUNC_1(p1);
		fp2 = FUNC_1(p2);

		// Iteration information.
		printf("%d        %f        %f        %f        %f        %-16f%-16f\n", i + 1, a, b, p1, p2, fp1, fp2);
		
		if (fa * fp1 < 0) {
			b = p1;
			continue;
		}

		if (fp1 * fp2 < 0) {
			a = p1;
			b = p2;
			continue;
		}

		if (fp2 * fb < 0) {
			a = p2;
			continue;
		}

		break;
	}

	if (success) {
		printf("Success!!\n\n\n");
	} else {
		printf("Fail!!\n\n\n");
	}
}

void test_case_2(void)
{
	const double tol = 0.0001;
	const int n = 100;
	double a = 0, b = 1;
	int success = 0;

	// Show basic information.
	printf("TOL = %0.4lf, N = %d\n", tol, n);
	printf("a = %0.0lf, b = %0.0lf\n\n", a, b);
	printf("n        a               b               p1              p2              f(p1)           f(p2)\n");

	for (int i = 0; i < n; i++) {
		double interval;
		double p1, p2;
		double fa, fb, fp1, fp2;

		if (b - a < tol) {
			success = 1;
			break;
		}

		interval = (b - a) / 3;
		p1 = a + interval;
		p2 = a + interval * 2;

		fa  = FUNC_2(a);
		fb  = FUNC_2(b);
		fp1 = FUNC_2(p1);
		fp2 = FUNC_2(p2);

		// Iteration information.
		printf("%d        %f        %f        %f        %f        %-16f%-16f\n", i + 1, a, b, p1, p2, fp1, fp2);
		
		if (fa * fp1 < 0) {
			b = p1;
			continue;
		}

		if (fp1 * fp2 < 0) {
			a = p1;
			b = p2;
			continue;
		}

		if (fp2 * fb < 0) {
			a = p2;
			continue;
		}

		break;
	}

	if (success) {
		printf("Success!!\n\n\n");
	} else {
		printf("Fail!!\n\n\n");
	}
}

void test_case_3(void)
{
	double tol = 0.0001;
	int a = 1, b = 2;
}
