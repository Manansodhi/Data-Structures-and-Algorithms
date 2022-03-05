class Vector{
	int cs;
	int ms;
	int *arr;
	public:
		Vector(){
			cs=0;
			ms=0;
			arr=new int[ms];
		}

		void push_back(const int d){
			if(cs==ms){
				//If array is full then we have to create new array of double size and copy element from arra and then add new element
				int *oldArr=arr;
				arr=new int[2*ms];
				ms = ms*2;
				for(int i =0;i<cs;i++){
					arr[i] = oldArr[i];
				}

				//clear the old occupied memory
				delete [] oldArr;
			}

			arr[cs]=d;
			cs++;
		}

		void pop_back(){
			cs--;
		}

		int front() const{
			return arr[cs];
		}

		int back()const{
			return arr[cs-1];
		}

		bool empty() const{
			return cs==0;
		}

		int capacity() const{
			return ms;
		}

		int size() const{
			return cs;
		}

		int at(const int i){
			return arr[i];
		}

		//overloading "[]" instead of using at() to get value at location we can use v[i]
		int operator [](const int i){
			return arr[i];
		}

};