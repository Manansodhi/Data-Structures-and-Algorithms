/* 
Compute 2 elements that are occuring once whereas rest of the elements are occuring 2 times
Ex:- 3,4,8,2,1,2,8,3
Ans 4, 1 (Two Element that are occuring once only)
Question :- How can we use the previous approch(XOR Approch) to solve this problem
Solution :- When compute XOR of all the elements then all the elements occuring 2 will cancel each other and 2 distinct 
elements XOR will be calculated in this we will get the 4 XOR 1 which occurs once only (4 XOR(^) 1 => 5)
 4 :-  1 0 0
 1 :-  0 0 1  XOR
      ----------
 ALL = 1 0 1   <= XOR of ALL elements becoz same elements XOR result to 0(zero) [x^x=0]

Result of XOR of ALL elements will definately have Atleast  one bit=1 at of the position.In this case it has 2 bit turned to 1 
at 0rth bit position and 2nd bit position. Now we pick any one Random Bit turned to 1 and it be Kth bit
Now we are going to parition the array in 2 halfs A & B. First set A will have K bit turned to 1 (means all the elemenst
from array which have Kth bit turned to 1 will come under this set A / Multiset). All the elemenst from array which have 
Kth bit turned Off to 0 will come under this set B / Multiset

ALL != 0 (will have Kth bit turned on to 1 )
ALL = x^y (two elements which occurs only once & also only one of x ,y will have Kth bit turned ON both x and y cannnot have
Kth bit turned ON (=1)) And when we partioned the array in a & b then x may when in set A or set B it can go in only one set
and y(2nd element that occur once) will go in another set to which x has gone and after that the problem turned to finding 1
unique element in array x and y will be in different parition. since all elements were occuring in duplicates . 
All elements will still present in duplicates in parition a & b. Now we can find the XOR of parition A and parition B they 
will give x & y respectively in which they have gone which setting the kth bit
*/


#include<bits/stdc++.h>
using namespace std;


//This "hasBitSet" function is used to find right most bit which is 1 . if it is present then while loop will increment the
//value of k to find the position of right most bit in this we are doing the left sift by the value of k to find the right
//most bit(turned On biy(=1)) and then doing and(&) operation with ALL(XOR of 2 unique number)

bool hasBitSet(int n, int x) {
	int tem = n & (1<<x);
	return tem!=0;
	//
}

void find_Unique_Element(int * arr, int size){
	int all = 0;
	int ans[2] = {0,0};
	for(int i=0; i<size; i++){
		cin >> arr[i];
		all ^= arr[i];
	}
	
	/*assert(all != 0); 
	 This while loop is used to find the right most bit position (Turned ON bit(=1)). if hasSetBit() returns 0 means ki 0th
	 position per nahi h right most bit toh k++ kiya*/

	int k = 0;
	while( hasBitSet(all, k) == 0 ) k++;

	//int rightbit = all & ~(all-1);
	
	//parition array into two sets: kth bit on v/s off
	for (int i=0; i<size; i++) {
		/*"hasBitSet(arr[i], k)" es se bacically ham kya kar rahe h ki Element ka AND(&) kiya with K(right most bit) jisse ki
		   ham element ko 2 paritition m divide kar de jinkke right most bit same us base per */
		ans[hasBitSet(arr[i], k)] ^= arr[i];
	}
	
	cout << ans[0] << " " << ans[1] << endl;;
}



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size;
        int arr[size];
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }

        find_Unique_Element(arr, size);
    }
    return 0;
}