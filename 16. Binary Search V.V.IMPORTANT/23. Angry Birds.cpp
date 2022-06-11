bool isvalid(vector<int>&nests, int birds, int mx){
	int BirdsRequired=1,last_location=nests[0],noOfNests=nests.size();
	for(int i=1;i<=noOfNests-1;i++){
		int current_location = nests[i];
		if(current_location-last_location>=mx){
			//cout<<"        B"<<i<<" current_location-last_location: "<<current_location-last_location<<endl;
			BirdsRequired++;
			last_location=current_location;
		}

		if(BirdsRequired==birds){
			return true;
		}
	}
	return false;
}

int angeryBirds(vector<int>&nests, int birds){

	int n = nests.size();
	int result = -1;
	int start = 0,end = nests[n-1]-nests[0];

	if (n < birds)
    return -1;

	while(start<=end){
		int mid = start+(end-start)/2;
		//cout<<"1 Mid: "<<mid<<" Start: "<<start<<" End: "<<end<<endl;
		if(isvalid(nests,birds,mid)){
		//	cout<<"2 Mid: "<<mid<<" Start: "<<start<<" End: "<<end<<endl;
			result=mid;
			start=mid+1;
		//	cout<<"2.1 Mid: "<<mid<<" Start: "<<start<<" End: "<<end<<endl;
		}
		else{
			end=mid-1;
		//	cout<<"3 Mid: "<<mid<<" Start: "<<start<<" End: "<<end<<endl;
		}
	}
	return result;
}


int main(){
	int birds=3;
	vector<int> nests{1,2,4,8,9};
	cout<<angeryBirds(nests,birds)<<endl;
}