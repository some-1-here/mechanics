#ifndef TRAILER_H
#define TRAILER_H

extern double m1;
extern double m2;
extern double driving_force;
extern double tension;

// F=ma
extern double force;
extern double mass;

// SUVAT
extern double s;
extern double u;
extern double v;
extern double a;
extern double t;

extern int choice1;
extern int choice2;

void get_masses_driving_force();
void calculate_acceleration_tension();
void print_acceleration_tension();
void which_suvat();
int calculate_suvat_depending_on_known_values();
void print_all_values();

#endif
