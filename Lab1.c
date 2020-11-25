#include <stdio.h>
#include <math.h>

int main() {
    double x;
    double result;
    for (x = 3; x <= 6.1; x = x + 0.2){
        if (x < 4) {
            result = log(x) - cos(x);
        } else if (4 <= x && x < 5) {
            result = cos(exp(x) + 3)/sin(exp(x) + 3);
        } else {
            result = pow(5*x, x);
        }
        printf("x = %.1lf\n", x);
        printf("Result = %lf\n", result);
    }
    return 0;
}
