#ifndef COMPLEXNUMBER_H_INCLUDED
#define COMPLEXNUMBER_H_INCLUDED

// ====
// Structures
// ====

// should be typedef 'd but labscript doesnt do that
struct ComplexNumber;


// ====
// Constructors and Destructors
// ====

struct ComplexNumber *complexNumberConstructor( float real , float imag );
void complexNumberDestructor(struct ComplexNumber *complexNumber);


// ====
// Getters
// ====

float complexNumber_GetReal(struct ComplexNumber *complexNumber);
float complexNumber_GetImag(struct ComplexNumber *complexNumber);


// ====
// Accessors
// ====

float complexNumber_GetMag(struct ComplexNumber *complexNumber);
float complexNumber_GetAngle(struct ComplexNumber *complexNumber);


// ====
// display functions
// ====

void complexNumber_Display(struct ComplexNumber *complexNumber);


// ====
// math functions
// ====
void complexNumber_Conjugate(struct ComplexNumber *input, struct ComplexNumber *result);
void complexNumber_Add(struct ComplexNumber *input_a, struct ComplexNumber *input_b, struct ComplexNumber *result);
void complexNumber_Sub(struct ComplexNumber *input_a, struct ComplexNumber *input_b, struct ComplexNumber *result);
void complexNumber_Mul(struct ComplexNumber *input_a, struct ComplexNumber *input_b, struct ComplexNumber *result);
void complexNumber_Div(struct ComplexNumber *input_a, struct ComplexNumber *input_b, struct ComplexNumber *result);


#endif // COMPLEXNUMBER_H_INCLUDED
