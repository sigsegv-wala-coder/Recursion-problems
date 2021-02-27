//****************************************************************************************************************************************

// Problem 1 : Write a program to find x to the power n (i.e. x^n). Take x and n from the user. Do it recursively.

// Approach : Base case should be if power is 0 , return 1. Inductive relation should be x^n = x * x^(n-1)

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

