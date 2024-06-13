/* Definiálja azt a double** average(double** mtx, int height, int width) függvényt, 
amely paraméterként egy height sorból és width oszlopból álló mtx dinamikus mátrixot kap. 
Visszatérési értéke legyen egy olyan dinamikus mátrix,
 mely a paraméter mátrix összes 3x3-as méretű blokkjának számtani közepét 
 tartalmazza ugyanolyan elrendezésben, ahogyan a blokkok az eredeti mátrixban is elhelyezkedtek!*/

 #include<iostream>

 double** average(double** mtx, int height, int width);
 void freemem(double** mtx, int height);
 void print(double** mtx, int height, int width);
 double** createMtx(const double* flat, int height, int width);

 int main () {

    double mtx[3][3] = {
		{1., 2., 3.},
		{4., 5., 6.},
		{7., 8., 9.}
	};
	double** mtx2d = createMtx(&mtx[0][0], 3, 3);
	double** block = average(mtx2d, 3, 3);
    double** createMtx(const double* flat, int height, int width);
	print(block, 1, 1);
	freemem(block, 1);
	delete[] mtx2d;

 }

 double** average(double** mtx, int height, int width) {
    int newHeight = height/3;
    int newWidth = width/3; 

    double** result = new double*[newHeight];
    for (int i = 0; i < newHeight; ++i) {
        result[i] = new double[newWidth];
    }

    for (int i = 0; i < newHeight; ++i) {
        for (int j = 0; i < newWidth; ++j) {
            double sum  = 0.0;
            for (int bi = 0; bi < 3; ++bi) {
                for (int bj = 0; bj < 3; ++bj) {
                    sum += mtx[i * 3 + bi][j * 3 + bj];
                }
            }

            result[i][j] = sum / 9.0;
        }
    }

    return result;
 }

 void print(double** mtx, int height, int width) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << mtx[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void freemem(double** mtx, int height) {
    for (int i = 0; i < height; ++i) {
        delete[] mtx[i];
    }
    delete[] mtx;
}

double** createMtx(const double* flat, int height, int width) {
    double** mtx = new double*[height];
    for (int i = 0; i < height; ++i) {
        mtx[i] = new double[width];
        for (int j = 0; j < width; ++j) {
            mtx[i][j] = flat[i * width + j];
        }
    }
    return mtx;
}