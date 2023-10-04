/* arraystruct.c - SYSC 2006 Lab 5 */

#include <stdlib.h>  
#include <stdio.h>   

#include "arraystruct.h"


//Abody Majeed 101227327

// part 1

/* Return the maximum value in the first n elements of array of integers, ar. 
   If n is less than or equal to 0, it returns 0.  
   This function uses array indices.  Do not change this function. */
int find_max_v0(const int ar[], int n) {
	int max;
	if (n<=0) {
		return 0; // ensure we proceed only if n is reasonable
	}
	max = ar[0];
	for (int i=1; i<n; i++) {
		if (ar[i]>max) {
			max = ar[i];
		}
	}
	return max;
}

/* Return the maximum value in the first n elements of an array of integers. 
   If n is less than or equal to 0, it returns 0.  
   This function uses a pointer to an array. */
int find_max_v1(const int *arp, int n) {
	
	if(n <= 0){

		return 0;
	}
	
	int x = *arp;
	for(int i; i < n; i++){
		if(*(arp + i) > x){
			
			x = *(arp + i);
			
			}
		
		
		}
	return x;
}

/* Return the maximum value in the first n elements of an array of integers. 
   If n is less than or equal to 0, it returns 0.  
   This function uses a walking pointer to the array. */
int find_max_v2(const int *arp, int n) {
	const int *p = arp;
	
	
	int x = *arp;
	if(n <= 0){
		
		return 0;
		
		}

	for(; p < (arp+n); p++){
		
		if(*p > x){
			
			x = *p;
			
			}		
		}
	return x;
}


// part 2

/* Print fraction pointed to by pf in the form a/b. */
void print_fraction(const fraction_t* pf)
{
	printf("%d/%d",pf->num,pf->den);

}

/* Return the greatest common divisor of integers a and b; 
   i.e., return the largest positive integer that evenly divides 
   both values.  Copy this function from Lab 4.  No changes are needed.
*/
int gcd(int a, int b)
{
	/* Euclid's algorithm, using iteration and calculation of remainders. */
	int q = abs(a);
	int p = abs(b);

	int r = a%b;

	while( r!= 0){
		
		q = p;
		p = r;
		
		r = q%p;
		
		}

	return p;
}

/* Updates the fraction pointed to by pf to its reduced form.

   This means that:
   (1) if the numerator is equal to 0 the denominator is always 1.
   (2) if the numerator is not equal to 0 the denominator is always
       positive, and the numerator and denominator have no common
       divisors other than 1.

   In other words,
   (1) if the numerator is 0 the denominator is always changed to 1.
   (2) if the numerator and denominator are both negative, both values
       are made positive, or if the numerator is positive and the 
       denominator is negative, the numerator is made negative and the 
       denominator is made positive.
   (3) the numerator and denominator are both divided by their greatest
       common divisor. 
*/
void reduce(fraction_t* pf)
{
	int a = pf->num;
	int b = pf->den;
	
	if (a < 0 && b < 0){
	
		a = abs(a);
		b = abs(b);
		
		}

	if ( a == 0 && b >= 1){
		
		b = 1;
			
		pf->den = b;

		
		
		}
	if( a >= 1 && b >= 1){
		
		int g = gcd(a,b);
		a = a/g;
		b = b/g;

		pf->num = a;
		pf->den = b;

		
		
		}
	else if (a < 1 && b >= 1){
		
		int g = gcd(a,b);
		a = a/g;
		b = b/g;

		pf->num = a;
		pf->den = b;

		
		
		}
	else if (a >= 1 && b < 1){
		
		int g = gcd(a,b);
		a = a/g;
		b = b/g;

		pf->num = -a;
		pf->den = abs(b);

	
		
		}

}

/* Returns a pointer to a fraction (by reference) with numerator a and denominator b.
   Print an error message and terminate the calling program via exit()
   if the denominator is 0.
   The fraction returned by this function is always in reduced form.
*/
void make_fraction(int a, int b, fraction_t* pf)
{
	
	if(b == 0){
		
		exit(1);
		
		}
	
	pf->num = a;
	pf->den = b;
	reduce(pf);


 

}

/* Returns by reference a pointer to the sum of fractions pointed to by pf1 and pf2.
   The fraction returned by this function is always in reduced form
 */
void add_fractions(const fraction_t* pf1, const fraction_t* pf2, fraction_t* psum)
{
	
	int a = pf1->num;
	int b = pf1->den;
	int c = pf2->num;
	int d = pf2->den;

	int newNum = (a*d) + (b*c);
	int newDen = (b*d);

	 make_fraction(newNum,newDen,psum);


}

/* Returns by reference a pointer to the product of fractions pointed to by pf1 and pf2.
   The fraction returned by this function is always in reduced form
 */
void multiply_fractions(const fraction_t* pf1, const fraction_t* pf2, fraction_t* pprod)
{

	int a = pf1->num;
	int b = pf1->den;
	int c = pf2->num;
	int d = pf2->den;

	int newNum = (a*c);
	int newDen = (b*d);

	make_fraction(newNum,newDen,pprod);


}

// part 3

/* Update the GPA of the student pointed to by studentp, assuming the student has numGrades.    Note that update_gpa must call calc_gpa for each student. */
void update_gpa(student_t *studentp, int numGrades) {

	studentp->gpa = calc_gpa(studentp->grades, numGrades);
}

/* Calculate the GPA associated with the numGrades pointed to by gradesp.
   The implementation must use a walking pointer. 
   If the total weight of all courses is 0, a GPA of 0 is returned. */
float calc_gpa(const grade_t *gradesp, int numGrades) {
	const grade_t *g;
	g = gradesp;
	float sumC = 0;
	float sumP = 0;
	float sumFinal;

	for (; g <(gradesp + numGrades); g++){
		sumC += g->weight;
		sumP += g->gp;
		
		
		
	}

	if(sumC == 0){
			
			return 0;
			
			}

	sumFinal = sumP/sumC;	
	return sumFinal;
}
