// simpleRPN
// Sebastian Skarics

#include <iostream>
#include <string>
#include <exception>

using namespace std;


double rechnung(char op, int r1, int r2){
  double erg {};
  switch(x[0]){
    case '+': erg = stod(r2) + stod(r1); break;
    case '-': erg = stod(r2) - stod(r1); break;
    case '*': erg = stod(r2) * stod(r1); break;
    case '/': erg = stod(r2) / stod(r1); break;
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


int main(){
  string r4 {};
  string r3 {};
  string r2 {};
  string r1 {};
  string nInp {};
  while(true){
    double erg {};
    cin >> nInp;
    if(nInp[0] == '+' || nInp[0] == '-' || nInp[0] == '*' || nInp[0] == '/''){
      try{
        erg = rechnung(x, r1, r2);
      }
      catch(exception &e){
        cout << "Es ist zu einem Fehler gekommen -->" << e.what() << endl;
      }
      registerSwitch();
      r1 = std(erg)
      cout << r1;
    }
    else{
      registerSwitch()
      r1 = nInp;
    }
  }
}
