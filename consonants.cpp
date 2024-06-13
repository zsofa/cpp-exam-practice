/* 
Készítse el azt a std::string consonants(const std::string& word) függvényt, 
ami a paraméterként kapott word karakterláncnak csak a mássalhangzóit adja vissza. 

A visszatérési értékben és az eredeti karakterláncban ugyanolyan sorrendben kell lenniük a mássalhangzóknak, 
továbbá meg kell őrizni a kis- és nagybetűk közötti különbséget is.*/

#include<iostream>

std::string consonants(const std::string& word);

int main() {
    std::cout << consonants("This is the beginning of a beautiful friendship.") << std::endl;
    return 0;
}

std::string consonants(const std::string& word) {
    //char m = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    std::string result;
    for (char c : word) {
        result+=c;
    }
    int size = sizeof(result)/sizeof(result[0]);
    for (int i = 0; i < size; i++ ) {
        if (result[i] == ' ') {
            result.erase(i);
        }
    }
    return result;
}