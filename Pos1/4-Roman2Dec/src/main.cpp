// Roman2Dec Main.cpp
// Sebastian Skarics

#include <iostream>
#include <string>
#include <exception>

using namespace std;


int value(char digit){
  int erg {};
  switch (digit) {
    case 'I': erg = 1; break;
    case 'V': erg = 5; break;
    case 'X': erg = 10; break;
    case 'L': erg = 50; break;
    case 'C': erg = 100; break;
    case 'D': erg = 500; break;
    case 'M': erg = 1000; break;
    default: throw logic_error("wrong digit " + (1, digit));
  }
  return erg;
}


unsigned int roman2dec(string roman){
  int erg {0};
  for(int i {0}; i < roman.length(); i++){
    erg += value(roman[i]);
  }
  return erg;
}


int main(){
  string str {};
  int erg {};
  cin >> str;
  try{
    erg = roman2dec(str);
  }
  catch(logic_error &e){
    cout << e.what() << endl;
  }
  cout << "Das Ergebnis lautet " << erg << endl;
}
