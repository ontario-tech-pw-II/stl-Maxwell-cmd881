#include<iostream>
#include<fstream>
#include<set>
using namespace std;

int main(){
    set<string> sStud;
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    string name = "";
    double grade = 0.0;
    while(fin >> name){
        fin >> grade;
        
        if(grade < 50){
            sStud.insert(name);
        }

    }

    set<string>::iterator i;
    for(i=sStud.cbegin();i!=sStud.cend();i++){
        fout << *i << endl;
    }

    fin.close();
    fout.close();

}