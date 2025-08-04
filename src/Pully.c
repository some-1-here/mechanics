#include "Pully.h"
#include <stdio.h>
#include <math.h>

double m1 = 0.0;
double m2 = 0.0;
double g = 9.81;

double force = 0.0;
double s = 0.0;
int u = 0;  
double v = 0.0;
double a = 0.0;
double t = 0.0;
double tension = 0.0;

int choice = 0;

void get_masses() {
    printf("enter m1 (heavier mass) \n");
    scanf("%lf", &m1);
    printf("enter m2 (lighter mass) \n");
    scanf("%lf", &m2);
}

void calculate_accelartion_tension(double m1, double m2) {
    a = (g * (m1 - m2)) / (m1 + m2);
    tension = (m2 * g) + (m2 * a);
    printf("acceleration = %f \ntension = %f \n", a, tension);
}

void get_suvat() {
    printf("which vairable do you have: 1=(s), 2=(v), 3=(t)\n");
    scanf("%d", &choice);
}

int calculate_suvat() {
    switch (choice) {
        case 1:
            printf("enter (s) in meters\n");
            scanf("%lf", &s);
            v = sqrt( u * u) + ( 2 * a * s);
            t = ( v - u) / a;
            break;
        case 2:
            printf("enter (v) in m/s\n");
            scanf("%lf", &v);
            t = (v - u ) / a;
            s = (u * t ) + ( 0.5 * a * ( t * t ));
            break;
        case 3:
            printf("enter (t) in seconds\n");
            scanf("%lf", &t);
            s = ( u * t ) + ( 0.5 * a * ( t * t ));
            v = u + ( a * t );
            break;

        default:
            printf("invalid choice\n");
            return 1;
    }
return 0;
}

void print_everything() {
    printf("\nall results\n");
    printf("--------------\n");
    printf("tension = %f \n", tension);
    printf("displacent = %f meters \n", s);
    printf("initial velocity = %d \n", u);
    printf("final velocity %f m/s \n", v);
    printf("acceleration = %f m/s^2 \n", a);
    printf("time %.3f seconds \n", t);
}
