#include <iostream>
#include <string>

using namespace std;
// Polynomial: 𝑥𝑛 + 𝑎(𝑥𝑛−1 + 𝑎(𝑥𝑛−2 + … + 𝑎 (𝑥1 + 𝑎𝑥0)))

unsigned int polynomialHash(const string& str, int size, int a) {
    unsigned int hashValue = 0;

    for (char c : str) {
        cout << c << " " << a << " " << hashValue << endl;
        hashValue = (hashValue * a) + c;
        cout << hashValue << endl;
    }

    return hashValue;
}

int main() {
    string text = "abc";
    int size = 10; 
    int a = 33;    

    unsigned int hashValue = polynomialHash(text, size, a);
    
    cout << "Metnin hash kodu: " << hashValue << endl;

    return 0;
}
