//****************************************************************************************************************************************

/* Problem 1 : Write a program to find x to the power n (i.e. x^n). Take x and n from the user. Do it recursively.

 Approach : Base case should be if power is 0 , return 1. Inductive relation should be x^n = x * x^(n-1) */

#include<iostream>
using namespace std;

int power(int x , int n ){
  if(n==0){
        return 1;
    }
    else
        return x*power(x,n-1);
}

int main(){
  int x,n;
  cin>>x>>n;
  
  cout<<power(x,n)<<endl;

}
//******************************************************************************************************************************************

/* Problem 2 : Print numbers from 1 to n in increasing order recursively.

Approach : Base case should print 1 and return. */

#include<iostream>
using namespace std;

void print(int n){
    if(n == 1){
        cout<<n<<" ";
        return;
    }
    
    print(n - 1);
    cout << n << " ";
}

int main(){
  int n;
  cin>>n;
  print(n);
}

// One thing to note is if we interchange line 40 and 41, the order reverses. So, little attentive while calling the recursive function.

//*********************************************************************************************************************************************

/* Problem 3 : Count the digits recursively

Approach : If number is less than 10 , return 1 . Call the recursion after dividing the number by 10 i.e. excluding one digit and subsequently
            add 1 as we're excluding that digit after dividing by 10 */

#include<iostream>
using namespace std;

int digits(int n){
    if(n<10){
        return 1;
    }
    return 1+digits(n/10);
}

int main(){
  int n;
  cin>>n;
  cout<<digits(n)<<endl;
}

//*************************************************************************************************************************************************

/* Problem 4 : Check whether the given array is sorted recursively.

Approach : If array consists of 0 or 1 element, it is already sorted. Now check for 1st and 2nd element.
           If 1st > 2nd , return false . Now call the recursive function for the rest of the array by passing
           arr+1 and size-1 .                  */
           
#include <iostream>
using namespace std;

bool check_sorted(int arr[] , int size){
    if(size==0 || size==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    return check_sorted(arr+1,size-1);
}
int main(){
    int n;
    cin>>n;
    // int *p=new int[n];
    // for(int i=0;i<n;i++){
    //     cin>>p[i];
    // }
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<check_sorted(arr,n)<<endl;
}

//*************************************************************************************************************************************************

/* Problem 5 : Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
               Do it recursively.
               
  Approach : The base case is when size=0 , return 0. Now the recursive relation is if input[0]=x , return true. Then call the recursive function*/

#include<iostream>
using namespace std;

bool checkNumber(int input[], int size, int x) {
	if(size==0){
        return false;
    }
 else if(input[0]==x){
        return true;
    }
 checkNumber(input+1,size-1,x);
}
int main(){
  int n,x;
  cin>>n>>x;
  int arr[n];
  for(int i=0;i<n;i++){
      cin>>arr[i];
  }
  cout<<checkNumber(arr,n,x)<<endl;
}
//*******************************************************************************************************************************************************

/* Problem 6 : Multiply numbers without using multiply/divide operator recursively

Approach : if we multiply 5 x 6 then, we are basically adding 5 till 6 times. */

#include<iostream>
using namespace std;

int multiplyNumbers(int m, int n) {
     if(n==0){
        return 0;
    }
    return m+multiplyNumbers(m,n-1);
}
int main(){
	int m,n;
	cin>>m>>n;
	multiplyNumbers(m,n);
}

//********************************************************************************************************************************************************

/* Problem 7 : Geometric Sum recursively. 1 + 1/2 + 1/4 + 1/8 + ........ + 1/2^k . 

Approach : Break the series into 2 parts. First (k-1) terms and the kth term. The base case is when k=0 , return 1. */

#include <iostream>
#include <math.h>
#include <iomanip>
#include "solution.h"
using namespace std;

double geometricSum(int k) {
	if(k==0){
           return 1;
	}
	return (1/pow(2,k)) + geometricSum(k-1);
}


int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);    //upto 5 decimal places
    cout << geometricSum(k) << endl;   
}

//******************************************************************************************************************************************************
/*
Problem 8 : Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
	    Do it recursively.
Approach : See the code        */

#include<iostream>
using namespace std;

void replaceCharacter(char input[], char c1, char c2) {
    if(input[0]=='\0'){
        return;
    }
    if(input[0]==c1){
        input[0]=c2;
    }
    replaceCharacter(input+1,c1,c2);
}
int main() {
    char input[1000000];
    char c1, c2;
    cin >> input;
    cin >> c1 >> c2;
    replaceCharacter(input, c1, c2);
    cout << input << endl;

//****************************************************************************************************************************************************************














