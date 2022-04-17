#include<bits./stdc++.h>
using namespace std;

string SimplifyPath(string path){

    //step1- Tokenization and filtering
    istringstream iss(path);
    
    vector<string> tokens;
    string token;
    while (getline(iss, token, '/')){
        if (token == "." or token == ""){//filtered out the "." tokens and redudant "/"
            continue; // ignoring "." and ""(NULL) tokens becoz they are not usefull
        }
        tokens.push_back(token);
    }
    // for(string t:tokens){
    //     cout << t <<","; 
    // }
     
    vector<string> stack;
    if (path[0] == '/'){
        //denotes that our path is absolute path(wrt root directory) so we pushed ""->NULL in the stack
        stack.push_back("");
    } 

    //handlinh ".."
    for (string token:tokens){
        if (token == ".."){
            //2 cases -> Absolute or relative path
            if(stack.size() == 0 or stack[stack.size()-1] == ".."){
                stack.push_back("..");
            }// this above condn is for relative path

// this condn is for absolute path as we have inserted null when we ahev absolute path then only this condn will run
            else if(stack[stack.size()-1] != ""){
                   stack.pop_back();
            }
        }

        else{
            //x,y,z.........
            stack.push_back(token);
        }
    }
      //corner case when we have only single element
     if(stack.size() == 1 and stack[0] ==""){
         return "/";
     }

    //combine all elements in stack to get the answer
    int i = 0;
    ostringstream oss;
    if (i!=0){
        oss << "/";
    }
    i++;
    for (auto token:stack){
        oss << token <<"/";
    }

    return oss.str();

}


int main(){
    string path = "/../x/y/../z/././w/a///../../c/./";

     cout << SimplifyPath(path) << endl;
    return 0;
}