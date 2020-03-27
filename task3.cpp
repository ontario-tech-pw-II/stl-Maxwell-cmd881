#include<iostream>
#include<fstream>
#include<map>
using namespace std;

int main(){
    map<string,int> mStud;
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    string name = "";
    double grade = 0.0;
    while(fin >> name){
        fin >> grade;
        
        if(grade < 50){
            mStud[name]++;
        }else if(mStud.find(name) == mStud.end()){
            mStud[name] = 0;
        }



    }

    map<string,int>::iterator i;
    for(i = mStud.begin();i!=mStud.end();i++){
        fout << i->first << " " << i->second << endl;
    }

    fin.close();
    fout.close();

}