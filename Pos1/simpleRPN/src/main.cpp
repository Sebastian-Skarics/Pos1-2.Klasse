// simpleRPN
// Sebastian Skarics

#include <iostream>
#include <string>
#include <exception>
#include <sstream>

using namespace std;


double rechnung(char op, string r1, string r2){
  double erg {};
  switch(op){
    case '+': erg = stod(r2) + stod(r1); break;
    case '-': erg = stod(r2) - stod(r1); break;
    case '*': erg = stod(r2) * stod(r1); break;
    case '/':
    if(r1 == "0"){
      throw invalid_argument("Division by 0");
    }
    else{
      erg = stod(r2) / stod(r1); break;
    }
    default: throw invalid_argument("Operator entspricht nicht den Vorraussetzungen");
  }
  return erg;
}


void registerSwitch(string &r1, string &r2, string &r3, string &r4){
  r4 = r3;
  r3 = r2;
  r2 = r1;
  return;
}


void registerSwitchRev(string &r1, string &r2, string &r3, string &r4){
  r2 = r3;
  r3 = r4;
  r4 = "0";
}


int main(){
  string r4 {"0"};
  string r3 {"0"};
  string r2 {"0"};
  string r1 {"0"};
  string nInp {};
  while(true){
    ostringstream strs {};
    double erg {stod(r2)};
    cin >> nInp;
    if(nInp[0] == '+' || nInp[0] == '-' || nInp[0] == '*' || nInp[0] == '/'){
      try{
        erg = rechnung(nInp[0], r1, r2);
        registerSwitchRev(r1, r2, r3, r4);
        strs << erg;
        r1 = strs.str();
        cout << r1 << endl;
      }
      catch(exception &e){
        cout << e.what() << endl;
      }
    }
    else{
      registerSwitch(r1, r2, r3, r4);
      r1 = nInp;
    }
  }
}
