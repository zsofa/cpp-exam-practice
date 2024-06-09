/*
Adott egy szövegfájl, mely soronként tartalmazza egy hallgató keresztnevét, majd a vizsgákon elért eredményeit, szóközökkel elválasztva. Például az exam1.txt tartalma a következő:

Mary 1 4
Joe 5
John 1 1 2
Jenny 3

Definiálja a void examCount(const std::string& fileName) függvényt, ami külön sorokban kiírja a hallgatók nevét és vizsgáik számát!*/

#include<iostream>
#include<fstream>
#include<sstream>

void examCount(const std::string& fileName);

int main () {
    examCount("exam1.txt");
    return 0;
}

void examCount(const std::string& fileName) {
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Error opening file" << '\n';
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream iss(line);
        std::string name;
        iss >> name;

        int count = 0;
        int grade;
        while (iss >> grade) {
            count++;
        }

        std::cout << name << " " << count << '\n';

        
    }
    file.close();

}