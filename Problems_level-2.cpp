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

//******************************************************************************************************************************************************

/* Problem 3 : Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array.
               Save all the indexes in an array (in increasing order). Do this recursively. Indexing in the array starts from 0.
	       
Approach 1 :   Call the recursive function from 2nd element. Now, update each index by adding 1 to it. Check for the element at
	       position 0. If it exists, then shift each element right by 1 position and place the index 0 at 0th position in 
	       output array. Ofcourse, increase the output array size by 1. The base case is when size=0 , return 0.*/
#include<iostream>
using namespace std;
int allIndexes(int input[], int size, int x, int output[]) {
	if(size==0){
        return 0;
    }
    int ans=allIndexes(input+1,size-1,x,output);
    if(input[0]==x){
        for(int i=ans-1;i>=0;i--){
            output[i+1]=output[i]+1;
        }
        output[0]=0;
        ans++;
    }
    else{
        for(int i=ans-1;i>=0;i--){
            output[i]=output[i]+1;
        }
    }
    return ans;
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
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    delete [] input;
    delete [] output;
}       

/* Approach 2 : Call recursive function as (input , size-1 , x , output). Here the extra work to update each element by 1 will be vanished
                and we have to check for the last element. If it exits then place the last index at the last position of output array.*/

#include<iostream>
using namespace std;

int allIndexes(int input[], int size, int x, int output[]) {
	if(size==0){
        return 0;
    }
    int ans=allIndexes(input,size-1,x,output);
    if(input[size-1]==x){
        output[ans]=size-1;
        ans++;
    }
    return ans;
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
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    delete [] input;
    delete [] output;
}       

//*************************************************************************************************************************************************************
/*	       
Problem 4 : Check whether a given String S is a palindrome using recursion. Return true or false.

Approach : Here, we will compare the first and last element and pass the rest of the string as a recursive function. The base case will
	   be when the string contains 0 or 1 element, return true. 	
*/
#include<iostream>
#include<string.h>
using namespace std;
bool checkPalindrome_helper(char input[] , int start , int end){
    if(input[0]=='\0' || input[1]=='\0'){
        return true;
    }
    if(start>=end){
        return true;
    }
    if(input[start]==input[end]){
        return checkPalindrome_helper(input , start+1 , end-1);
    }
    else{
        return false;
    }
}

bool checkPalindrome(char input[]) {
    
	int len=strlen(input);
    return checkPalindrome_helper(input,0,len-1);
}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

//**************************************************************************************************************************************************************	       
/*	       
Problem 5 : Remove all x occuring in the string recursively.

Approach : We'll see along coding the problem             */

#include<iostream>
using namespace std;

void removeX(char input[]){
	if(input[0]=='\0'){                // Base case. If there is no element in string, simply return the string
	     return;	   
	}
	if(input[0]!='x'){	           // Now if first character is not X , call the recursive function for remaining string
	    removeX(input+1);	
	}
	else{
		int i=1;                             // if first char is X , then shift each elemnent leftwards by 1 position.
	   	for(;input[0]!='\0';i++){
			input[i-1]=input[i];
			
		}
		input[i-1]=input[i];
		removeX(input);                  // Call the recursive ffunction over remaining string. Note that we have passed input as argument
		                                 //   instead of (input+1) as after shifting the characters, the string already becomes smaller.
	}
}
int main(){
	int str[100];
	cin>>str;
	removeX(str);
	cout<<str<<endl;
}

//*******************************************************************************************************************************************************************
/*
