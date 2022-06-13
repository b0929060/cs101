#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ReplaceMyString {
    public:
        void replaceString(string a, string b) {
            ifstream in;
            ofstream out;
            in.open("main.cpp");
            out.open("Rmain.cpp");
            if(out.fail()) { 
                cout << "input file opening failed...";
                exit(1);
            }
            if (in.fail()) {
                cout<<"input file opening failed";
                exit(1);
            }
            string value;
            while(getline(in,value)){
                if(value.find(a,0)!=-1) {
                    value=value.replace(value.find(a),a.length(),b);
                    out<<value<<endl;
                } else {
                    out<<value<<endl;
                }
            }
        }
};

int main() {
    ReplaceMyString my;
    my.replaceString("IU","IU is best");
    return 0;
}