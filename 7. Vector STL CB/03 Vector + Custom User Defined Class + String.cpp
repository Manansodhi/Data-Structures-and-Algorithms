#include<bits/stdc++.h>
using namespace std;


class Car{
public:
	string car_name;
	int x,y;
	Car(){

	}
	Car(string name,int x,int y){
		car_name = name;
		this->x=x;
		this->y=y;
	}

	int dist(){
		//returns the square of distance from origin
		return x*x + y*y;
	}
};

bool comapre(Car A, Car B){
	int da=A.dist();
	int db=B.dist();

	if(da==db){
		return A.car_name.length() <B.car_name.length();
	}
	return da<db;

}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin>>n;
	vector<Car> v; //Each Box of vector v will conatin car object

	for(int i=0;i<n;i++){
		int x,y;
		string name;
		cin>>nane>>x>>y;
		Car temp(name,x,y);
		v.push_back(temp);
	}

	sort(v.begin(),v.end(),compare);

	for(auto c:v){
		cout<<c.car_name<<" "<<"Distance "<<c.dist()<<"Location "<<c.x<<","<<<c.y<<endl;
	}

	return 0;
}