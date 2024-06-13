#include <iostream>

void mbox(const std::string &message);

int main()
{
    mbox("ab\ncde\nf");

    return 0;
}

void mbox(const std::string &message)
{
    // 1. loop through the string
    // 2. split at \n
    // 3. width = logest word + 2
    // 4. height num of words +2

    int max = 0;
    int curr = 0;
    int count = 0;
    int width;
    int height;
    char temp;
    int n = message.length();
    for (int i = 0; i < n; ++i) {
        char temp = message[i];
        if (temp == '\n') {
            count++;
            if (curr > max) {
                max = curr;
            } curr = 0;
        }
        else {
            ++curr;
        }
    }

    width = max + 2;
    height = count + 3;
    std::cout << "Width: " << width <<'\n';
    std::cout << "Heigth: " << height << '\n';

    for (int i = 0; i < width; i++) {
        std::cout << "*";
    }

    std::cout << std::endl;

    std::cout << '*';
    for (int i = 0; i < n; ++i) {
        char temp2 = message[i];
        std::cout << temp2;
        if (temp2 == '\n') {
            std::cout << "*";
        }
        
    }
    std::cout << std::endl;

    char wo[n];
    char m;
    for (int i = 0; i<n; i++) {
        wo[i] == message[i];
    }


    for (int i = 0; i < width; i++) {
        std::cout << "*";
    }

    std::cout << std::endl;
    
}