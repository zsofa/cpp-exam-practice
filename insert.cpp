#include<iostream>

/* Definiálja azt az elem* beszur(elem* horgony, std::string szo) függvényt, 
ami úgy szúrja be a horgony címen kezdődő, elem struktúrákból álló láncolt listába a szo-t, 
hogy amennyiben a listában tárolt szavak eddig abc-sorrendben álltak, 
akkor ez a rendezettség a beszúrás után is megmarad! 
Az elem struktúra már definiált a következőképpen:*/

/*A függvény visszatérési értéke a módosított lista kezdőcíme.*/

struct elem {
	std::string szo;
	elem* kov;
};

elem* beszur(elem* horgony, std::string szo);
void listaKiir(elem* horgony);

int main() {

    /*elem* horgony = nullptr;
	horgony = beszur(horgony, "banan");
	horgony = beszur(horgony, "dio");
	horgony = beszur(horgony, "alma");
	horgony = beszur(horgony, "cekla");
	printErase(horgony);*/

    elem* lista = nullptr;
    
    // Beszúrunk néhány szót a listába
    lista = beszur(lista, "alma");
    lista = beszur(lista, "banán");
    lista = beszur(lista, "citrom");
    lista = beszur(lista, "eper");
    lista = beszur(lista, "dinnye");
    
    // Kiírjuk a lista tartalmát
    listaKiir(lista);


    return 0;
}

elem* beszur(elem* horgony, std::string szo) {
    // new elem with neew word
    elem* newElement = new elem{szo, nullptr};

    //empty list or place it to the beginning
    if (horgony == nullptr || szo < horgony->szo) {
        newElement->kov = horgony;
        return newElement;
    }

    elem* actual = horgony;
    while (actual != nullptr && actual->kov->szo < szo) {
        actual = actual->kov;
    }

    //put the new element in the found place
    newElement->kov = actual->kov;
    actual->kov = newElement;

    //return with the start adress of the list, which did not chage
    return horgony;

}

// Segédfüggvény a lista kiírásához
void listaKiir(elem* horgony) {
    elem* aktualis = horgony;
    while (aktualis != nullptr) {
        std::cout << aktualis->szo << " -> ";
        aktualis = aktualis->kov;
    }
    std::cout << "nullptr" << std::endl;
}