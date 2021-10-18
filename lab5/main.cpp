#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void CheckFiles ( ifstream &main_file, ofstream &same_symbols_output, ofstream &palindrom_output ){
    if (!main_file.is_open() || !same_symbols_output.is_open() || !palindrom_output.is_open() ){
        cout<< "Files aren't opened. Try again."<< endl;
    }
    else {
        cout<< "Files are opened." << endl;
    }
}

void CloseFiles ( ifstream &main_file, ofstream &same_symbols_output, ofstream &palindrom_output ){
    main_file.close();
    same_symbols_output.close ();
    palindrom_output.close ();
    if (main_file.is_open() || same_symbols_output.is_open() || palindrom_output.is_open() ){
        cout<< "Files aren't closed."<< endl;
    }
    else {
        cout<< "Files are closed." << endl;
    }
}

bool  AllSameSymbols (string s_copy) {
    for (int r= 1; r < s_copy.size() ; r++) {
        if (s_copy[r] != s_copy[0]) {
            return false;
        }
    }
    return true;
}

void PalindromAndSameStrings (vector <string> &array,ofstream &palindrom_output, ofstream &same_symbols_output) {
    for (int j=0; j< array.size(); j++) {
        string s_copy = array[j];
        for (int i = array[j].size() - 1; i >= 0; i--) {
            if (array[j][i] >= 'A' && array[j][i] <= 'Z') {
                int temp = array[j][i] - 'A';
                s_copy[i] = 'a' + temp;
            }
            if (array[j][i] == '.' || array[j][i] == ' ' || array[j][i] == '?' || array[j][i] == ',' ||
                array[j][i] == '-') {
                s_copy.erase(i, 1);
            }
        }
        string s_copy1(s_copy.rbegin(), s_copy.rend());
        if (s_copy == s_copy1) {
            palindrom_output << array[j] << endl;
        }
        if (AllSameSymbols (s_copy)) {
            same_symbols_output << array[j] <<endl;
        }
    }
}

int main() {
    ifstream main_file("File for lab 5.5.txt");
    ofstream same_symbols_output("Same symbols strings.txt");
    ofstream palindrom_output("Palindroms strings.txt");
    CheckFiles (main_file, same_symbols_output, palindrom_output );
    string file;
    vector <string> array ;
    while (getline (main_file, file)){
        array.push_back(file);
    }
    PalindromAndSameStrings (array,palindrom_output, same_symbols_output);
    CloseFiles (main_file, same_symbols_output, palindrom_output );
    return 0;
}
