#include<iostream>
#include<cstring>
#include <algorithm> // for std::transform
#include <cctype>    // for std::toupper
using namespace std;

string screaming(std::string* words, int n);

int main() {
    string s[] = {"I", "hate", "cpp"};
    int size = sizeof(s)/sizeof(s[0]);
    string name = "zso";
    cout << screaming(s, size);
    return 0;
}

/*string screaming(std::string* words, int n) {
    //transform(str.begin(), str.end(), str.begin(), ::toupper);
    std::string *temp[] = new std::string[n];
    string help;
    int size = sizeof(words) / sizeof(words[0]);
    for (int i = 0; i < size; i++) {
        for (char &c: words[i]) {
            temp[i] += std::toupper(c);
        }
        
    }
    return temp;
}*/

string screaming(string* words, int n) {
    string result;
    string temp;
    for (int i = 0; i < n; i++)
    {
        temp = words[i];
        transform(temp.begin(), temp.end(), temp.begin(), [](unsigned char c) { return toupper(c); });
        for (auto j = temp.begin(); j != temp.end(); j++) {
            result.pushback(*j);
           //result.push_back('');
        } 
        if (i < n - 1) {
            result += "_";
        }
    } 

    return result;
}