#include <stdio.h>

void get_xy(double* x, double*y){
    printf("address of pointer:: x: %p, y: %p\n",&x, &y);

    *x = 1.0;
    *y = 2.0;

}

int main(void){
    double x, y;
    printf("address:: x: %p, y: %p\n",&x, &y);

    get_xy(&x, &y);

    printf("result:: x: %f, y: %f\n", x, y);

}