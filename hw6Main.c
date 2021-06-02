#include <stdio.h>
#include "phone.h"

void registerPhoneData();
void print();
// print() invokes printArray()
void printArray(void *arr, int size);
void searchByName();
void deleteByName();
void sort();

// array of function pointers.
void (* pFuncs[5])()={registerPhoneData, print, searchByName, deleteByName,sort};

// function pointer declaration
typedef int (*cmp)(const void*, int, int);
typedef int (*swap)(void*, int, int);

// Sorting PhoneBook using bubble sort
// 3rd parameter cmp cfn: a pointer to function
// 4th parameter swap sfn: a pointer to function
void sortPhoneBook(void *A, int size, cmp cfn, swap sfn);

// Functions for sortPhoneBook
// Should implement these two fuction
int contactCmpr(const void*, int, int);
int contactSwap(void*, int, int);

static int count_service = 0;	// Total number of service requests

int main()
{
	int service;		// a variable for storing user's request
	do
	{
        printf("============ Telephone Book Management ============");
        printf("\n <<<1. Register\t 2. Print All \t 3. Search by ID \t 4. Delete \t 5. Sort \t 6. Exit >>>\n");
        printf(" Please enter your service number (1-6)> ");
		scanf("%d", &service);
		if ( service > 0 && service <= 5 )
		{
			pFuncs[service-1]();
		}
		else if( service ==0 || service > 6)
		{
			printf("You choose a wrong service number\n");
		}
	} while (service != 6);	// if Exit is not entered, the loop continues
	return 0;
}

/*****************
** Your code..
** This function should be implemented in register.c
*************************/
void registerPhoneData()
{
    printf("Registration\n");
}

/*****************
** Your code..
** This function should be implemented in search.c
** Please modify this code with your vairables
*************************/
void print()
{
    printf("Print all contants in the PhoneBook\n");
	// This code illustrate sample usage of printArray()
	// Please modify this
	Contact A[5]={
        {"Roki", "12345678"},
        {"Thor", "33333333"},
        {"IronMan","3765898"},
        {"Hulk", "74561253"},
        {"Groot", "99999999"}
    };
	printArray(A, 5);
}

/*****************
** Your code..
** This function should be implemented in search.c
*************************/
void searchByName()
{
    printf("Search by Name\n");
}

/*****************
** Your code..
** This function should be implemented in delete.c
*************************/
void deleteByName()
{
    printf("Deletion is done\n");
}

/*****************
** Your code..
** This function should be implemented in sort.c
** Please modify some parts with your vairables
*************************/
void sort()
{
	printf("Sort fuction is called\n");
	// This is test codes
	// Please modify
	Contact A[5]={
        {"Roki", "12345678"},
        {"Thor", "33333333"},
        {"IronMan","3765898"},
        {"Hulk", "74561253"},
        {"Groot", "99999999"}
    };
	printf("Before sorting\n");
	printArray(A,5);
	// calling actual bubble sort
	// modify this function with your arrays
	// if you implement contactCmpr() and contactSwap() well
	// this code works correctly
	sortPhoneBook(A, 5, contactCmpr, contactSwap);
	printf("After sorting\n");
	printArray(A,5);
}


/*****************
*** Bubble sort code is provided
*** Do not modify this code
*************************/
void sortPhoneBook(void *A, int size, cmp cfn, swap sfn)
{
    int i, j;
    for(i=0; i<size-1; i++)
    {
        for(j=0; j<size-i-1; j++)
        {
            if(cfn(A, j,j+1)>0)
                sfn(A,j,j+1);
        }
    }
}

/*****************
** Your code..
** This function should be implemented in sort.c
*************************/
int contactCmpr(const void* arr, int i, int j)
{
    // if arr[i]> arr[j], return 1
    // else retrun 0

	// Calculate address for arr[i]:  ((Contact*)arr+i)
    // derefernce structure Contact: *((Contact*)arr+i)).Name
    // for stucture we use ->: ((Contact*)arr+i)->Name

}

/*****************
** Your code..
** This function should be implemented in sort.c
*************************/
int contactSwap(void* arr, int i, int j)
{
    // Goal: arr[i] <- arr[j], arr[j] <- arr[i]
    // calculate address for arr[i]:  ((int*)arr+i)
    // derefernce int: *((int*)arr+i))


    return 1;
}

/*****************
** for implementing above two functions
** please study this funciton well
** Students can use this function for testing your codes.
*************************/
void printArray(void *arr, int size)
{
    int i;
    void *vp;
    vp= arr;
    for(i=0; i<size; i++)
    {
        // Calculate address for arr[i]:  ((Contact*)arr+i)
        // derefernce structure Contact: *((Contact*)arr+i)).Name
        // for stucture we use ->: ((Contact*)vp+i)->Name
        printf("Addr vp:%p\t", (Contact*)vp+i);
        printf("name:%s\t phone:%s\n", ((Contact*)vp+i)->Name, ((Contact*)vp+i)->PhoneNumber);
    }
    printf("\n");
}
