#include <bits/stdc++.h>
using namespace std;

//Pass-by-Value
int square1(int n)
{
    //Address of n in square1() is not the same as n1 in main()
    cout << "address of n1 in square1(): " << &n << "\n";  
      
    n *= n; // clone modified inside the function
    return n;
}

//Pass-by-Reference with Pointer Arguments
void square2(int *n)
{
    //Address of n in square2() is the same as n2 in main()
    cout << "address of n2 in square2(): " << n << "\n";
      
    *n *= *n; // Explicit de-referencing to get the value pointed-to
}

//Pass-by-Reference with Reference Arguments
void square3(int &n)
{
    //Address of n in square3() is the same as n3 in main()
    cout << "address of n3 in square3(): " << &n << "\n";
      
    n *= n; // Implicit de-referencing (without '*')
}
/*--------------------------------------------------------------------------------*/
void increase(void *data,int ptrsize)
{
    if(ptrsize == sizeof(char))
    {
        char *ptrchar;
          
        //Typecast data to a char pointer
        ptrchar = (char*)data;
          
        //Increase the char stored at *ptrchar by 1
        (*ptrchar)++;
        cout << "*data points to a char"<<"\n";
    }
    else if(ptrsize == sizeof(int))
    {
        int *ptrint;
          
        //Typecast data to a int pointer
        ptrint = (int*)data;
          
        //Increase the int stored at *ptrchar by 1
        (*ptrint)++;
        cout << "*data points to an int"<<"\n";
    }
}
void pointers()
{
    char c='x';
    int i=10;
      
    //Call increase function using a char and int address respectively
    increase(&c,sizeof(c));
    cout << "The new value of c is: " << c <<"\n";
    increase(&i,sizeof(i));
    cout << "The new value of i is: " << i <<"\n";
      
}
int main() {

	// 3-ways pass arguments to a functions
	// 1. call by value
	int n1 = 10;
	cout << "Address: " << &n1 << endl;
	cout << "Functions: " << square1(n1) << endl;
	cout << "No change: " << n1 << endl;

	// 2. call by reference with pointer argument
	int n2 = 7;
	cout << "Address: " << &n2 << endl;
	square2(&n2);
	cout << "Functions: " << n2 << endl;
	cout << "change: " << n2 << endl;

	// 3. call by reference with reference argument
	int n3 = 5;
	cout << "Address: " << &n3 << endl;
	square3(n3);
	cout << "Functions: " << n3 << endl;
	cout << "change: " << n3 << endl;
/*----------------------------------------------------------------------------------------*/
	// Array name as pointers
	int val[3] = {5, 10, 20};
	int* ptr = val;
	cout << "Elements of the array are: " << ptr[0] << " " << ptr[1] << " " << ptr[2] << endl;
/*----------------------------------------------------------------------------------------*/
	// Pointer Expression and pointer arithmetic
	for (int i = 0; i < 3; ++i) {
		cout << "Value at ptr = " << ptr << endl;
		ptr++;
	}
/*----------------------------------------------------------------------------------------*/
	// Advanced Pointer Notation
	int nums[2][3] = {
		{16, 18, 20},
		{25, 26, 27}
	};
	cout << *(*nums) << endl;
	cout << *(*nums + 2) << endl;
	cout << *(*(nums + 1) + 1) << endl;
/*----------------------------------------------------------------------------------------*/
	// Pointers and String Literals
	const char *p = "string";
	char x = *(p + 3);
	char y = p[3];
	cout << x << " " << y << endl;
/*----------------------------------------------------------------------------------------*/
	// pointers to pointers
	int a = 10;
	int *ptr2 = &a;

	cout << "a = " << a << endl;
	cout << "*ptr2 = " << *ptr2 << endl;

	int** q = &ptr2;
	cout << "**q = " << **q << endl;

	int*** r = &q;
	cout << "***r = " << ***r << endl;

/*----------------------------------------------------------------------------------------*/
	// void pointers
	pointers();

	return 0;
}