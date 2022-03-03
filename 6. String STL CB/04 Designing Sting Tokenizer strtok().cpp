#include<bits/stdc++.h>
using namespace std;

//instead we pass array(char*) of delimeter we accept single character that will be delimiter
char *mystrtok(char*str, char delim) {
//string str and single char as delimeter

	/*we are making multiple function call to extract token each time for this we have to maintain variable which will maintain
	that how much string is tokenized and from where it should give next token for this we have to maintain static variable
	(to maintain how many token you have returned till now)
	static input pointer. state of static variable is intialized only once in function call and in every subsequent call it will
	have same state as in previous function call
	*/
	static char *input = NULL;


	//input will point to the starting position of string if string str is not NULL
	if (str != NULL) {
		input = str;
	}

	//Base case. After the final token has been returned
	if (input == NULL) {
		return NULL;
	}


	/*
	when designing  strtok() we have to store the entire string inside function and for storing we will take dynamic array
	becoz it will exist even after function call is over. we will create new array of same length of string each time becoz whole
	 string may be one token also +1 for null character which we will add for last token
	*/

	char *output = new char[strlen(input) + 1];
	int i = 0;
	for (; input[i] != '\0'; i++) {
		if (input[i] != delim) {
			output[i] = input[i];//copying the string in output array untill delimeter
		}
		else {
			output[i] = '\0';
			input = input + i + 1; //to change the location of input pointer after first token is copied in output array
			return output;
		}
	}
	/*corner case: For very last token there might may not be space at the end so four loop will get over so we put '\0' at the
	 end explicity*/
	output[i] = '\0';
	input = NULL;
	return output;

}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	char s[100] = "Today is a rainy day";
	char *ptr = mystrtok(s, ' ');
	cout << ptr << endl;

	while (ptr != NULL) {
		ptr = mystrtok(NULL, ' ');
		cout << ptr << endl;
	}

	return 0;
}