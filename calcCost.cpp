/*
Laminált padlóval szeretnénk burkolni egy area területű szobát.
A boltban kapható laminált padló jellemzőit a flooringStruct struktúra segítségével lehet megadni. 
Ennek footage tagja megadja, hogy egy csomag mekkora terület lefedésére alkalmas (racionális szám), a
price tag pedig egy csomag padló ára (egész szám). Csomagokat a boltban nem bontanak meg, 
csak egész számút lehet vásárolni.
*/

/*
Definiálja a struktúrát, majd azt a double calcCost(flooringStruct flooring, double area) függvényt, 
ami visszaadja, hogy mennyibe kerülne leburkolni flooring típusú laminált padlóval az area nagyságú szobát!
*/

#include<iostream>
#include<cmath>

struct flooringStruct {
    double footage;
    int price;

};

double calcCost(flooringStruct flooring, double area);

int main() {

    std::cout << calcCost({1.727, 15417}, 2.5) << std::endl;
    return 0;
}

double calcCost(flooringStruct flooring, double area) {
    double unit = area/flooring.footage;
    if (trunc(unit) == unit) {
        return unit * flooring.price;
    } else {
        return (trunc(unit) + 1) * flooring.price;
    }
    return 0;
}

