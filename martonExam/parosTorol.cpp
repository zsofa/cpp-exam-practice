#include<iostream>

/*
1. egyszesen láncolt lista
2. kitörli listából páros számokat
2. return head
*/

struct data {
    int num;
    data* link;
    
};

data* parosTorol(data* head);
void freeUp(data* head);

int main() {
    return 0;
}

data* parosTorol(data* head) {
    data** current = &head;

    while(current != nullptr) {
        if ((*current)->num % 2 == 0) {
            data* temp = *current;
            *current = (*current)->link;
            delete temp;
        } else {
            current = &(*current)->link;
            return current;
        }
    }


}
