// Algorithm to find the nth number in the series which is a factor of 2,3,5

# include<iostream> 
using namespace std; 

typedef unsigned int uint;

/* Function to get the nth number*/
uint findNthNumber(uint n) 
{ 
  uint num_array[n]; // To store numbers which are factors of 2,3,5
  uint index2 = 0, index3 = 0, index5 = 0; //index for every number
  uint next_multiple_of_2 = 2; //first three numbers as well as store the next multiple of respective factors
  uint next_multiple_of_3 = 3; 
  uint next_multiple_of_5 = 5; 
  uint next_num = 1; 

  num_array[0] = 1; 
  for (int i=1; i<n; i++) 
  { 
    //find the minimum next number
    next_num = min(next_multiple_of_2, 
              min(next_multiple_of_3, 
                next_multiple_of_5)); 
    num_array[i] = next_num; 
    //find which contributed to it and store the updated index
    if (next_num == next_multiple_of_2) 
    { 
      index2 = index2+1; 
      next_multiple_of_2 = num_array[index2]*2; 
    } 
    if (next_num == next_multiple_of_3) 
    { 
      index3 = index3+1; 
      next_multiple_of_3 = num_array[index3]*3; 
    } 
    if (next_num == next_multiple_of_5) 
    { 
      index5 = index5+1; 
      next_multiple_of_5 = num_array[index5]*5; 
    } 
  }
  return next_num; 
} 

/* Driver program to test above function */
int main() 
{ 
    int n;
    cout<<"Enter a which number in a series you wanna find out:"<<endl;
    cin>>n;
    cout << findNthNumber(n); 
    return 0; 
} 
