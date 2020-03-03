// simpleRPN
// Sebastian Skarics

#include <iostream>
#include <string>
#include <exception>
#include <sstream>

using namespace std;


void print(string r1, string r2, string r3, string r4){
  cout << "r1 = " << r1 << endl << "r2 = " << r2 << endl << "r3 = " << r3 << endl << "r4 = " << r4 << endl;
}


void clear(string &r1, string &r2, string &r3, string &r4){
  r1 = "0";
  r2 = "0";
  r3 = "0";
  r4 = "0";
}


void quit(bool &l){
  l = false;
}


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
  bool l {true};
  string r4 {"0"};
  string r3 {"0"};
  string r2 {"0"};
  string r1 {"0"};
  string nInp {};
  while(l){
    ostringstream strs {};
    double erg {stod(r2)};
    cin >> nInp;
    int lenInp {nInp.length()};
    size_t digi {};
    try{
      if(!(nInp[0] == '+' || nInp[0] == '-' || nInp[0] == '*' || nInp[0] == '/' || nInp == "print" || nInp == "quit" || nInp == "clear")){
        double num {stod(nInp, &digi)};
        if(digi != lenInp){
          throw invalid_argument("Fehler bei der Umwandlung ");
        }
      }
      if(nInp == "print"){
        print(r1, r2, r3, r4);
      }
      else if(nInp == "quit"){
        quit(l);
      }
      else if(nInp == "clear"){
        clear(r1, r2, r3, r4);
      }
      else{
        if(nInp[0] == '+' || nInp[0] == '-' || nInp[0] == '*' || nInp[0] == '/'){
          erg = rechnung(nInp[0], r1, r2);
          registerSwitchRev(r1, r2, r3, r4);
          strs << erg;
          r1 = strs.str();
          cout << r1 << endl;
        }
        else{
          registerSwitch(r1, r2, r3, r4);
          r1 = nInp;
        }
      }
    }
    catch(exception &e){
      cout << e.what() << endl;
    }
  }
  if(!cin){
    l = false;
  }
}
