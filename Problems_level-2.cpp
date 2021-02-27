//********************************************************************************************************************************************************
/*
 Problem 1 :    Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. 
                Return -1 if it is not present in the array. First index means, the index of first occurrence of x in the input array.
                Do this recursively. Indexing in the array starts from 0. 

Approach :      Base case is when size=0 , return -1 . Now if input[0] = x , return 0 . But one bug is there that after calling recursive function
                index starts with 0 again. So, if first index is at 3 , the output will yield 2. So, we have to add 1 to output. But if the
                number is not present, then output should be -1. So, we have to take care of this case explicitly.*/
                
#include<iostream>
using namespace std;
int firstIndex(int input[], int size, int x) {
	if(size==0){
        return -1;
    }
    else if(input[0]==x){
        return 0;
    }
    int ans=firstIndex(input+1,size-1,x);
    if(ans!=-1){
        return ans+1;
    }
    else{
        return -1;
    }
}
int main(){
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    int x;
    cin >> x;
    cout << firstIndex(input, n, x) << endl;
}
//**************************************************************************************************************************************************************

/* Problem 2 : Given an array of length N and an integer x, you need to find and return the last index of integer x present in the array. 
               Return -1 if it is not present in the array. Last index means - if x is present multiple times in the array, return the index 
	       at which x comes last in the array. You should start traversing your array from 0, not from (N - 1).Do this recursively. 
	       Indexing in the array starts from 0.
	    
Approach :     There are two methods. First one is to start traversing from the last and use the same approach as in the above problem.
               Second one is start traversing from the first. But here comes the main part. In previous problem we have called the recursive
	       function after the calculation as we have to deal with first index. But now, we can't do that since we want the last index.
	       So, we'll call the recursive function first and then improvise the calculation. */
	       
#include<iostream>
using namespace std;
int lastIndex(int input[], int size, int x) {
    if(size==0){
        return -1;
    }
    int ans=lastIndex(input+1,size-1,x);
    if(ans!=-1){
        return ans+1;
    }
    else if(input[0]==x){
        return 0;
    }
    else{
        return -1;
    }
}
int main(){
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    int x;
    cin >> x;
    cout << lastIndex(input, n, x) << endl;
}
