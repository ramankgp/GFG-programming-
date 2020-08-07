https://www.geeksforgeeks.org/count-set-bits-in-an-integer/

Count set bits in an integer


Approach 1:

// C++ program to Count set 
// bits in an integer 
#include <bits/stdc++.h> 
using namespace std; 

/* Function to get no of set bits in binary 
representation of positive integer n */
unsigned int countSetBits(unsigned int n) 
{ 
	unsigned int count = 0; 
	while (n) { 
		count += n & 1; 
		n >>= 1; 
	} 
	return count; 
} 

/* Program to test function countSetBits */
int main() 
{ 
	int i = 9; 
	cout << countSetBits(i); 
	return 0; 
} 




Approach 2:

Brian Kernighan’s Algorithm:

1  Initialize count: = 0
   2  If integer n is not zero
      (a) Do bitwise & with (n-1) and assign the value back to n
          n: = n&(n-1)
      (b) Increment count by 1
      (c) go to step 2
   3  Else return count
   


// C++ program to Count set 
// bits in an integer 
#include <iostream> 
using namespace std; 
class gfg { 
	/* Function to get no of set bits in binary 
representation of passed binary no. */
public: 
	unsigned int countSetBits(int n) 
	{ 
		unsigned int count = 0; 
		while (n) { 
			n &= (n - 1); 
			count++; 
		} 
		return count; 
	} 
}; 
/* Program to test function countSetBits */
int main() 
{ 
	gfg g; 
	int i = 9; 
	cout << g.countSetBits(i); 
	return 0; 
} 






