/********************************/
/**exercise name: exercise one **/
/**student name: Boyang YAN *****/
/**student username: by932 ******/
/********************************/
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
void push(string);
string top();
void pop();
bool isEmpty();
char stack[50][20];
int stackIndex = 0;
int main(int argc, char *argv[])
{
	char fileName[20];
    cout << "please input file name: ";
    cin >> fileName;
    ifstream myfile (fileName);

    if (myfile.fail()){
        cout << "Can not find this file" << endl;
        return 0;
    }

    string temp = "";
    while (!myfile.eof()) {
        myfile >> temp;
        if (!myfile.good()) {
            break;
        }
        push(temp);
    }

    myfile.close();

    while (!isEmpty()) {
        cout << top();
        pop();
    }
    cout << endl;
    return 0;
}
void push(string word){
    char temp[20];
    strncpy(temp, word.c_str(), sizeof(temp));
    temp[sizeof(temp) - 1] = 0;
    for (int i = 0; i < 20; i++) {
        stack[stackIndex][i] = temp[i];
    }
    stackIndex++;
    return;
}
string top(){
    string output;
    for (int i = 0; i < 20; i++) {
        output += stack[stackIndex - 1][i];
    }
    output += " ";
    return output;
}
void pop(){
    stackIndex--;
    return;
}
bool isEmpty(){
    if (stackIndex == 0) {
        return true;
    }
    return false;
}
