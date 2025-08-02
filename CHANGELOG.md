# Changelog

## [02-08-2025] car.c
### fixed
- all SUVAT variables were now initialised to 0
- extra comma for scanf("%f,", &driving_force) has now been removed and is now -> scanf("%f", &driving_force)

### Notes
- declaring variables to 0 seem to have fixed some bugs
- tested with known exam questions and program gives correct answers
- in future i will add in a discriminant to prevent imaginary values from causing bugs in sketch
