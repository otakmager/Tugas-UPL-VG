/*
Nama: Dimas Wahyu Ardiyanto
NIM: 24060120140159
Tanggal dibuat: 13 Maret 2023
Link soal: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
Tujuan: tugas mata kuliah Uji Perangkat Lunak (UPL) 
        membuat program dengan minimal 10 cyclomatic complexity V(G) 
*/

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
    Deskripsi:
        Sebagai main function dalam membuat semua kombinasi
        kata (word) dari setiap kemungkinan konversi huruf.
    @param digits: string
    @output res: vector<string>
    */
    vector<string> letterCombinations(string digits) {
        // Kamus Lokal
        vector<string> res;
        int indexStart, size;
        string initWord = "";

        // Algortima
        if(digits != ""){
            indexStart = 0;
            size = digits.size();
            solve(digits, indexStart, initWord, res, size);
        }
        return res;
    }
    
    /*
    Deskripsi:
        Membuat kombinasi kata (word) dari setiap kemungkinan
        konversi digits ke huruf. Setiap kombinasi word nantinya
        akan disimpan dalam variabel res. Function ini akan berhenti
        jika index sudah sama dengan panjang character dari digits.
        Jika belum maka akan dibuat looping untuk melakukan rekursif
        untuk membuat setiap kemungkinan kata (word).
    @param digits: String
    @param index: integer
    @param word: string
    @param &res: vector<string>
    @param size: integer
    @output void
    */
    void solve(string digits, int index, string word, vector<string> &res, int size){
        // Kamus Lokal
        int i;
        vector<string> lettersComb;
        
        // Algortima
        if(index == size){
            res.push_back(word);
            return;
        }
        lettersComb = convert(digits[index]);
        for(i=0; i<lettersComb.size(); i++){
            solve(digits, index+1, word+lettersComb[i], res, size);
        }
    }
    
    /*
    Deskripsi:
        Mengkonversi digit ke dalam bentuk vector<string> 
        yang berisi kemungkinan huruf dari digit tersebut.
    @param digit: Character
    @output res: vector<string>
    */
    vector<string> convert(char digit){
        // Kamus Lokal
        vector<string> res;

        // Algortima
        if(digit == '2'){
            res.push_back("a");
            res.push_back("b");
            res.push_back("c");
        }else if(digit == '3'){
            res.push_back("d");
            res.push_back("e");
            res.push_back("f");
        }else if(digit == '4'){
            res.push_back("g");
            res.push_back("h");
            res.push_back("i");
        }else if(digit == '5'){
            res.push_back("j");
            res.push_back("k");
            res.push_back("l");
        }else if(digit == '6'){
            res.push_back("m");
            res.push_back("n");
            res.push_back("o");
        }else if(digit == '7'){
            res.push_back("p");
            res.push_back("q");
            res.push_back("r");
            res.push_back("s");
        }else if(digit == '8'){
            res.push_back("t");
            res.push_back("u");
            res.push_back("v");
        }else if(digit == '9'){
            res.push_back("w");
            res.push_back("x");
            res.push_back("y");
            res.push_back("z");
        }else if(digit == '9'){
            res.push_back("w");
            res.push_back("x");
            res.push_back("y");
            res.push_back("z");
        }else{
            res.push_back("");
        }
        return res;
    }
};

/*
Main Driver untuk menampilkan hasil dari
setiap kombinasi konversi digit.
*/
int main(){
    // Kamus
    Solution solution;
    string problem;
    vector<string> result;
    
    
    // Algoritma
    problem = "296";
    result = solution.letterCombinations(problem);
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    
    return 0;
}

