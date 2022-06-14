#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class myString {
};

class ReadClass {
    public:
        string c ="class";
        int count=0;
        string name;
        void showClass() {
            ifstream in;
            in.open("main.cpp");
            string value;
            while(getline(in,value)){
                int class_pos = value.find(c,0);
                if(value.find(c,0)==0) {
                    count++;
                    for (int i=0;i<1;i++) {
                        if (in.eof()) {
                            break;
                        } else {
                            cout<<value<<endl;                            
                        }
                    }
                }
            }
            if (count!=0) {
                cout<<count<<" class in main.cpp"<<endl;
            } else {
                cout<<"no class in main.cpp"<<endl;
            }
        }
};

int main() {
    ReadClass rflie;
    rflie.showClass();
    return 0;
}