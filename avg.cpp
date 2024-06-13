/*
Definiálja azt a double* atlagok(const double* tomb, int n) függvényt, 
ami a paraméterként kapott n elemű tomb minden 2-2 szomszédos elemének meghatározza a számtani közepét (átlagát), 
és az ezekből álló, dinamikusan lefoglalt területen elhelyezett tömb címét adja vissza!*/


#include<iostream>

double* atlagok(const double* tomb, int n);
void print(const double* tomb, int n);

int main() {

    double t[] = { 1, 2, 4, 8, 16 }; 
	double* a = atlagok(t, 5);
	print(a, 4);
	delete[] a;

    double t2[] = { 1 };
    double* a2 = atlagok(t2, 1);
    std::cout << (a2==nullptr?"OK\n":"Hiba\n");    

    return 0;
}

double* atlagok(const double* tomb, int n){
    if (tomb == nullptr || n < 2) {
        return nullptr;
    } else {
        double* avgArray = new double[n-1];

        for (int i = 0; i < n-1; i++) {
            avgArray[i] = (tomb[i] + tomb[i+1])/2.0;
        }
        return avgArray;
    }
    
}

void print(const double* tomb, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << tomb[i] << " ";
    }

    std::cout << std::endl;
}