#include <stdio.h>
#include <math.h>

    int main() {
        double d = 0.001;
        double a = 0;
        double s = 0;
        double x = 0;
        for (x = -1; x <= 1; x = x + 0.02) {
            double k = 2;
            do
            {
                a  = ((pow(-1, k)*k)/(k*k-1)*sin(k*x));
                k++;
                s = s + a;
            }   while (a >= d);
            printf("%f \n", s);
        }
        return 0;
    } 