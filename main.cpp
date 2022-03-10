#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <ctime>
#include <vector>

using namespace std;
int random_num(int min, int max){
    return rand() % (max - min) + min;
}
int szamjegyekosszege(int number){
    if(number != 0){
        return number % 10 + szamjegyekosszege(number/10);
    }
    return 0;
}

int szamjegyekszama(int number){
    if(number != 0){
        return 1 + szamjegyekszama(number/10);
    }
    return 0;
}

int szamfordit(int number, int currNumber = 0){
    if(number != 0){
        currNumber = currNumber * 10 + number % 10;
        return szamfordit(number/10, currNumber);
    }
    return currNumber;
}

void read_array(int *a, int n, ifstream &f){
    if(n > 0){
        read_array(a,n-1,f);
        f >> a[n];
    }
}

void print_array(int *a, int n){
    if(n > 0){
        print_array(a,n-1);
        cout << a[n] << " ";
    }
}

int sumArray(int *a, int n){
    if(n > 0){
        return sumArray(a, n-1)+a[n];
    }
    return 0;
}

double avgArray(int *a, int n){
    double avg = sumArray(a,n);
    return avg / n;
}

int minArray(int *a, int n, int minNumber = 32000){
    if(n > 0){
        if(a[n] < minNumber){
            minNumber = a[n];
        }
        return minArray(a,n-1, minNumber);
    }
    return minNumber;
}

string reverseWord(string word, string newWord = "", int i = 1){
    if(word.length() != newWord.length()){
        newWord += word[word.length()-i];
        return reverseWord(word, newWord, ++i);
    }
    return newWord;
}

void randomizeStringArray(vector<string> &words, int i = 3){
    if(i > 0){
        int randomNumber1 = random_num(0, words.size());
        int randomNumber2 = random_num(0, words.size());
        string word = words[randomNumber1];
        words[randomNumber1] = words[randomNumber2];
        words[randomNumber2] = word;
        return randomizeStringArray(words, --i);
    }
}
long factorial(int i, long n = 1){
    if(i > 0){
        return factorial(--i, n*i);
    }
    return n;
}
int lnko(int a, int b){
    if(a != b){
        if(a > b){
            return lnko(a-b, b);
        }
        return lnko(a, b-a);
    }
    return a;
}

int main() {
    srand(time(nullptr));
    std::cout << szamjegyekosszege(11);
    std::cout << std::endl;
    std::cout << szamjegyekszama(400);
    std::cout << std::endl;
    std::cout << szamfordit(123);
    std::cout << endl;
    ifstream f;
    f.open("input.txt");
    if(!f.is_open()){
        printf("ERROR");
        return -1;
    }
    int *a;
    a = new int[6];
    read_array(a, 5, f);
    print_array(a, 5);
    cout <<endl << sumArray(a,5);
    f.close();
    cout << endl << avgArray(a, 5);
    cout << endl << minArray(a, 5);
    cout << endl << reverseWord("Adatszerkezetek");
    vector<string> words;
    words.emplace_back("Adat");
    words.emplace_back("Szer");
    words.emplace_back("Ke");
    words.emplace_back("Zetek");
    randomizeStringArray(words);
    cout << endl << words[0] << " " << words[1] << " " << words[2] << " " << words[3];
    cout << endl << factorial(4);
    cout << endl << lnko(12, 6);
    return 0;
}
