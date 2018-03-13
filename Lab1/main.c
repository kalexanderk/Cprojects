#include <stdio.h>
#include <math.h>

int main(){
    float x, z;
    printf ("Please enter number x.\n");
    scanf("%f", &x);
    printf ("Please enter number z.\n");
    scanf("%f", &z);
    if (x==-z || z==0 || x==0) printf("Error! Input is wrong.\n");
    else {
        float y = 5*x/(pow(x,3)+pow(z,3)) - 1/tan(3*x/z);
        printf("The result is %.4f.\n", y);
    }
    return 0;
}
