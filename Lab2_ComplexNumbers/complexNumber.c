#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "complexNumber.h"


// ====
// Structures
// ====
struct ComplexNumber
{
    float real;
    float imag;
};


// ====
// Constructors and Destructors
// ====
struct ComplexNumber* complexNumberConstructor(float real, float imag)
{
    struct ComplexNumber* complexNumber;

    complexNumber = malloc(sizeof(struct ComplexNumber));

    complexNumber->real = real;
    complexNumber->imag = imag;

    return complexNumber;
}

void complexNumberDestructor(struct ComplexNumber* complexNumber)
{
    free(complexNumber);
}


// ====
// Getters
// ====
float complexNumber_GetReal(struct ComplexNumber* complexNumber)
{
    return complexNumber->real;
}

float complexNumber_GetImag(struct ComplexNumber* complexNumber)
{
    return complexNumber->imag;
}


// ====
// Accessors
// ====
float complexNumber_GetMag(struct ComplexNumber* complexNumber)
{
    return sqrt(
                pow(complexNumber->real, 2) +
                pow(complexNumber->imag, 2)
                );
}

float complexNumber_GetAngle(struct ComplexNumber* complexNumber)
{
    return atan((complexNumber->imag)/(complexNumber->real));
}


// ====
// display functions
// ====
void complexNumber_Display(struct ComplexNumber* complexNumber){
    printf(
           "[ %f + %fj ]",
           complexNumber->real,
           complexNumber->imag
           );
}


// ====
// math functions
// ====
void complexNumber_Conjugate(struct ComplexNumber* input, struct ComplexNumber* result){
    result->real = input->real;
    result->imag = -input->imag;
}

void complexNumber_Add(struct ComplexNumber* input_a, struct ComplexNumber* input_b, struct ComplexNumber* result){
    result->real = input_a->real + input_b->real;
    result->imag = input_a->imag + input_b->imag;
}

void complexNumber_Sub(struct ComplexNumber* input_a, struct ComplexNumber* input_b, struct ComplexNumber* result){
    result->real = input_a->real - input_b->real;
    result->imag = input_a->imag - input_b->imag;
}

void complexNumber_Mul(struct ComplexNumber* input_a, struct ComplexNumber* input_b, struct ComplexNumber* result){
    result->real = (input_a->real * input_b->real) - (input_a->imag * input_b->imag);
    result->imag = (input_a->real * input_b->imag) + (input_a->imag * input_b->real);
}

void complexNumber_Div(struct ComplexNumber* input_a, struct ComplexNumber* input_b, struct ComplexNumber* result){
    result->real = (
                    (input_a->real * input_b->real) +
                    (input_a->imag * input_b->imag)
                    )/(
                     pow(input_b->real,2)+pow(input_b->imag,2)
                    );

    result->imag = (
                    (input_a->imag * input_b->real) -
                    (input_a->real * input_b->imag)
                    )/(
                     pow(input_b->real,2)+pow(input_b->imag,2)
                    );
}

