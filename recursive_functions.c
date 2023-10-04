/* SYSC 2006 Lab 12. */

#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "recursive_functions.h"

/* Return x raised to the power n for n >= 0. */
double power(double x, int n)
{
    if(n == 0){
		
		return 1;
		
		
		}
	else{
		
		return x * power(x,n-1);
		
		}
}

/* Return the count of the number of times target occurs in the first 
 * n elements of array a.
 */
int count_in_array(int a[], int n, int target)
{
	int x = 0;
    if(n == 0){
		
		if(a[0] == target){
			
			x += 1;
			return x;
			
			}
		else if(a[0] != target){
			
			
			return x;
			
			}
		
		}
	if(a[n] == target){
		
		x += 1;
		return x + count_in_array(a, n-1, target);
		
		}
	else if(a[n] != target){
		
		return x + count_in_array(a, n-1, target);
		
		}
}

/* Return the count of the number of times target occurs in the 
 * linked list pointed to by head. 
 */
int count_in_sll(node_t *head, int target)
{
    int x = 0;
	if(head == NULL){
			
			return x;
			
			}
		
	
	if(head != NULL){
		
		if(head->data == target){
			
			x += 1;
			return x + count_in_sll(head->next, target);
			
			}
		else if(head->data != target){
			return x + count_in_sll(head->next, target);
			
			}
		
		}
}

/* Return the last element in the linked list pointed to by head.
 * Terminate (via assert) if the list is empty.
 */
int last_in_sll(node_t *head)
{
	assert(head != NULL);
    if(head->next == NULL){
		
		return head->data;
		
		}
	else {
		
		return last_in_sll(head->next);
		
		}
}

/* Extra-practice exercises. */

/* Return the number of digits in integer n, n >= 0. */
int num_digits(int n)
{
	int x = 0;
	if(n < 10){
		
		return 1;
		
		}

	
	x += 1;
	n = n/10;
	if(n < 10){
		
		return x + 1;
		
		}
	if(n >= 10){
		n = n/10;
		x += 1;
		return x + num_digits(n);
		
		}
}

/* Return x raised to the power n for n >= 0. */
double power2(double x, int n)
{

    
}
