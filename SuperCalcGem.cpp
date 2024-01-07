#include <iostream>
#include <fstream>
//#include <bits\stdc++.h>
using namespace std;

int main(){
    int st,sp;
    cout<<"start number:";
    cin>>st;
    cout<<"stop  number:";
    cin>>sp;
    if (sp-st >= 100000000){
        cout<<"Number too big!"<<endl;
        return 0;
    }
    int n;
    for (int i=st;i<=sp;i++){
        for (int j=st;j<=sp;j++){
            n+=5;
        }
    }
    cout<<"lines:"<<n<<endl;
    system("pause");

    ofstream f;
    f.open("SuperFastCalc.cpp",ios::out);

    f<<R"(
#include <iostream>
//#include <bits\stdc++.h>
using namespace std;

int main(){
    
    int a,b;
    char op;
    cin>>a>>op>>b;

    )"<<endl;

    for (int i=st;i<=sp;i++){
        //cout<<"\033c";
        cout<<i<<'/'<<sp<<endl;
        for (int j=st;j<=sp;j++){

            f<<"    if (a=="<<i<<" && op=='+' && b=="<<j<<") cout<<"<<i+j<<';'<<'\n';
            f<<"    if (a=="<<i<<" && op=='-' && b=="<<j<<") cout<<"<<i-j<<';'<<'\n';
            f<<"    if (a=="<<i<<" && op=='*' && b=="<<j<<") cout<<"<<i*j<<';'<<'\n';
            if (j!=0)
                f<<"    if (a=="<<i<<" && op=='/' && b=="<<j<<") cout<<"<<i/j<<';'<<'\n';
            f<<endl;
        }
    }
    f<<R"(
    return 0;
}
    )";
    
    f.close();

    return 0;
}
