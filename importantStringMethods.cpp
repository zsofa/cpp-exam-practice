#include<iostream>

using namespace std;

int main() {
    string text = "This is a sentence with nums 33 and specials: 99";

    //begin and end charatcter of a string
    auto i = text.begin();
    cout<<"The first character in the string str is: "<<*i<<endl;

    auto j = text.end()-1;
    cout<<"The last character in the string str is: "<<*j<<endl;

    // loop through a string:
    for (auto i = text.begin(); i != text.end(); i++) {
        cout << "All letters in string: " << *i << endl;
    }

    //insert a character to the end of the string - push_back()
    text.push_back('!');
    cout << text << '\n';

    std::string text2 = "Hello";
    // insert a whole string at the end of the other string with push_back()
    for (auto i = text2.begin(); i != text2.end(); i++) {
        text.push_back(*i);
    }

    cout << text;

    // remove last character of the string - pop_back();
    text.pop_back();
    cout<< "Removed the last character " << text << '\n';

    //size of a string - returns a number
    cout << text.size() << endl;

    // copy() method -> copies the string or a sub-string
    // 3 arguments: character array, length of substring, position (index) where should it start
    std::string name = "Doma Zsofi";
    char str[name.size()];
    name.copy(str, 5, 5);
    cout<< str;

    //swap() switch the strings
    std::string one = "Something";
    std::string two = "Else";
    one.swap(two);

    //store an input string -> the space wont be a problem like this
    //std::string input;
    //std::getline(cin, input);
    //cout << input << endl;

    //convert a string num into a num
    string s1 = "12345";
    inT v1 = stoi(s1);
    cout<<v1;
    
}