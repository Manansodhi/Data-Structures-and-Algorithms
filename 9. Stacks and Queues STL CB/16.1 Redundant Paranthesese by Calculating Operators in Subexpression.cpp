#include<bits/stdc++.h>
using namespace std;

bool checkRedundant(string s)
{
	stack<char>st;
	for(char ch:s){
		if(ch!=')'){
			//pusing all operator, operand and opening bracket '(' except closing bracket ')'
			st.push(ch);
		}
		else{
			//it will come here when ch has ')' so it will check if it has any operator between '(' and ')' if it doesnot 
			//have any then redundant parenthesis
			bool operator_found=false;
			while(!st.empty() and st.top!='('){
				char top = st.pop();
				if(top=='+' or top=='-' or top=='/' or top=='*'){
					operator_found=true;
				}
				s.pop();//poping all operator and operand except last opening bracket will pop outside while loop
			}
			s.pop();
			if(operator_found==false){
				return true;
			// means we do not find any operator between operand so they have redundabt parenthesis in between and we if we
			//	have found operator then we made operator_found again equal to false to check for for next sub expression
			}
		}
	}
	return false;
}

int main(){
	string str = "((a+b))+c";
	if(checkRedundant(str)){
		cout<<"Contain Redundant Parenthesis"<<endl;
	}
	else{
		cout<<"Does Not Contain Redundant Parenthesis"<<endl;
	}