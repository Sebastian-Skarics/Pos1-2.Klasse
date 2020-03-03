// simpleRPN
// Sebastian Skarics

#include <iostream>
#include <string>
#include <exception>

using namespace std;

int main(){
  string r2 {};
  string r1 {};
  string x {};
  while(true){
    int erg {};
    cin >> r2;
    cin >> r1;
    cin >> x;
    try{
      switch(x[0]){
        case '+': erg = stod(r2) + stod(r1); break;
        case '-': erg = stod(r2) - stod(r1); break;
        case '*': erg = stod(r2) * stod(r1); break;
        case '/': erg = stod(r2) / stod(r1); break;
        default: throw invalid_argument(Operator entspricht nicht den Vorraussetzungen);
      }
      cout << erg;
    }
  }
}
