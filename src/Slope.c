#include "Slope.h"
#include <stdio.h>
#include <math.h>

#define DEG_TO_RAD(x) ((x) * M_PI / 180.0)
#define RAD_TO_DEG(x) ((x) * 180 / M_PI)
double g = 9.81;

double Co_efficiant = 0;
double Normal = 0;
double Theta = 0;
double Tension = 0;
double Mass = 0;

double s = 0;
double u = 0;
double v = 0;
double a = 0;
double t = 0;

void get_all_possible_values() {
printf("Enter known values (-1 if not told)");
printf("co-efficient\n");
scanf("%lf", &Co_efficiant);
printf("Normal\n");
scanf("%lf", &Normal);
printf("theta\n");
scanf("%lf", &Theta);
printf("Tension\n");
scanf("%lf", &Tension);
printf("Mass\n");
scanf("%lf", &Mass);
printf("\nSUVAT values\n");
printf("s\n");
scanf("%lf", &s);
printf("u\n");
scanf("%lf", &u);
printf("v\n");
scanf("%lf", &v);
printf("a\n");
scanf("%lf", &a);
printf("t\n");
scanf("%lf", &t);
}

void calculate_all_possible_values() {
//Theta = DEG_TO_RAD(Theta);

// using mass and angle
if (Mass != -1 && Theta != -1) {
    Theta = DEG_TO_RAD(Theta);
    Normal = Mass * g * cos(Theta);
    printf("1");
    Theta = RAD_TO_DEG(Theta);
}
else if (Mass != -1 && Normal != -1) {
    Theta = acos(Normal / (Mass * g));
    Theta = RAD_TO_DEG(Theta);
    printf("2");
}
else if (Normal != -1 && Theta != -1) {
    Theta = DEG_TO_RAD(Theta);
    Mass = Normal / (g * cos(Theta));
    Theta = RAD_TO_DEG(Theta);
    printf("3");
}

}

void Test() {
if (Co_efficiant != -1 && Tension != -1) {
    Theta = DEG_TO_RAD(Theta);
    a = (-Co_efficiant * Mass * g * cos(Theta)) + Tension - (Mass * g * sin(Theta)) / Mass;
    Theta = RAD_TO_DEG(Theta);
}

if (Co_efficiant != -1 && a != -1) {
    Theta = DEG_TO_RAD(Theta);
    Tension = (Mass * a) + (Co_efficiant * Mass * g * cos(Theta)) + (Mass * g * sin(Theta));
    Theta = RAD_TO_DEG(Theta);
}

if (Tension != -1 && a != -1) {
    Theta = DEG_TO_RAD(Theta);
    Co_efficiant = ((Mass * a) + (Mass * g * sin(Theta)) - Tension) / (Mass * g * cos(Theta));
    Theta = RAD_TO_DEG(Theta);
}

}

void component_weights(){
    printf("Weight components");
    printf("%f * Sin(%f)", Mass * g, Theta);
    printf("%f * Cos(%f)", Mass * g, Theta);
}

void print_all_possible_values() {
printf("co-efficient=%f\n", Co_efficiant);
printf("Normal=%f\n", Normal);
printf("theta=%f\n", Theta);
printf("Tension=%f\n", Tension);
printf("Mass=%f\n", Mass);
printf("\nSUVAT values\n");
printf("s=%f\n", s);
printf("u=%f\n", u);
printf("v=%f\n", v);
printf("a=%f\n", a);
printf("t=%f\n", t);
}
