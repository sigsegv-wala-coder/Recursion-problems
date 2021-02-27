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
