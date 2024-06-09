/*
Definiálja azt a void charCounter(std::string str, int n) függvényt, 
ami abc-sorrendben a szabvány kimenetre nyomtatja azokat a betűket szóközzel elválasztva, 
melyek pontosan n alkalommal fordultak elő az str karakterláncban! */

/*

A kis- és nagybetűket ne különböztesse meg egymástól! 
Feltételezheti, hogy az str karakterlánc csak az angol abc betűit tartalmazza.
*/

#include<iostream>
#include <map>
#include <set>
#include <algorithm>

void charCounter(std::string str, int n);

int main() {
    charCounter("OneTwoThree", 2);
    charCounter("OneTwoThree", 1);
    return 0;
}

void charCounter(std::string str, int n) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);

    std::map<char, int> frequency;

    for (char c: str) {
        frequency[c]++;
    }

    std::set<char> result;

    for (const auto& pair : frequency) {
        if (pair.second == n) {
            result.insert(pair.first);
        }
    }

    for (char c : result) {
        std::cout << c << " ";
    }

    std::cout << std::endl;
    

}