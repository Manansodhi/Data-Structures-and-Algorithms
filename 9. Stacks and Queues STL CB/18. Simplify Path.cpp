#include<bits./stdc++.h>
using namespace std;

string SimplifyPath(string path) {

    //step1- Tokenization and filtering
    istringstream iss(path);

    vector<string> tokens;
    string token;
    while (getline(iss, token, '/')) {
        if (token == "." or token == "") { //filtered out the "." tokens and redudant "/"
            continue; // ignoring "." and ""(NULL) tokens becoz they are not usefull
        }
        tokens.push_back(token);
    }
    // for(string t:tokens){
    //     cout << t <<",";
    // }

    vector<string> stack;  //need to access some element by index also  which are not available inside the stack object
    if (path[0] == '/') {
        //denotes that our path is absolute path(wrt root directory) so we pushed ""->NULL in the stack to handle
        // absolute case. and stack will have exactly one or zero special kind of symbol NULL-> ""
        stack.push_back("");
    }

//handling ".." ex /a/b/../.. => /  list of token["a", "b", "..", ".."] push in stack when encounter ".." pop() from stack
    for (string token : tokens) {
        if (token == "..") {
            //2 cases -> Absolute( "/../../" => "/") or relative path ("../../x/y/z" => "../../x/y/z")
            // this condn is for relative path
            if (stack.size() == 0 or stack[stack.size() - 1] == "..") {
                //stack.size()==0 means that we are getting ".." in the beginning or stack ki 2 consequetive position per
                //means ki pichli posn check karne k liye (stack[stack.size()-1]=="..") per ".." h toh usko push kardo
                //stack m becoz voh relative path h ex "../../a/b/c" => list of token[".., .., a, b, c"] initally stack
                //size is zero so push ".." after that pichli posn per check karne k liye ki us per bhi toh nahi h ".."
                //agar h toh usko bhi push kardo stack m and if we get "../../a/b/c/../d" so when get last ".." so then we
                //see that our preivous element is not ".." so it is not relative and we pop it by unix rule "../../a/b/d"
                stack.push_back("..");
            }

            // this condn is for absolute path as we have inserted null when we have absolute path then only this condn
            //will run. ex "/a/b/c" list of token[a, b, c, ""] since it is an absolute path we also push null "". then
            //we are going pop every thing except NULL "" becoz we have also encountered ".." in token at start of if cond
            // so we are going to do nothing "/../../.." becoz it is absolute and ".." also. so no poping list of token
            //[ .., .., ..] in stack we see "" NULL we do nothing
            else if (stack[stack.size() - 1] != "") {
                stack.pop_back();
            }
        }

        else {
            //x,y,z.........
            stack.push_back(token);
        }
    }
    //corner case when we have only single element
    if (stack.size() == 1 and stack[0] == "") {
        return "/";
    }

    //combine all elements in stack to get the answer
    ostringstream oss;
    int i = 0;
    for (auto token : stack) {
        if (i != 0) {
            oss << "/";
        }
        i++;
        oss << token ;
    }

    return oss.str();

}


int main() {
    string path = "/../x/y/../z/././w/a///../../c/./";

    cout << SimplifyPath(path) << endl;
    return 0;
}