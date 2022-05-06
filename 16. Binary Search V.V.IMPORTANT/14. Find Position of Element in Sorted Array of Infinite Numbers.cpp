
int binarySearch(int arr[], int start, int end, int key){
	while(start<=end){
		int mid=start+(end-start)/2;
		if(arr[mid]==key){
			return mid;
		}
		else if(arr[mid]>=key){
			end=mid-1;
		}
		else{
			start=mid+1;
		}
	}
	return -1;
}

int findPostion(int arr[],int key){
	int start=0,end=1;
	while(arr[end]<key){
		start=end;
		end=end*2;
	}
	return binarySearch(arr,start,end,key);
}

/*
Let p be the position of element to be searched. Number of steps for finding end index ‘end’ is O(Log p). The value of ‘end’
must be less than 2*p. The number of elements between end/2 and end must be O(p).Therefore, time complexity of Binary Search 
step is also O(Log p) and overall time complexity is 2*O(Log p) which is O(Log p).
*/

int main()
{
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130,
                               140, 160, 170};
    int ans = findPos(arr, 10);
    if (ans==-1)
        cout << "Element not found";
    else
        cout << "Element found at index " << ans;
    return 0;
}