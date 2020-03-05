// Roman2Dec Main.cpp
// Sebastian Skarics

#include <iostream>
#include <string>
#include <exception>
#include <utility>
#include <vector>
#include <cassert>

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


void test(string roman){
  for(int i {0}; i < roman.length(); i++){
    int anz {0};
    if(i + 2 < roman.length()){
      if(value(roman[i]) < value(roman[i + 1]) || value(roman[i]) < value(roman[i + 2])){
        if(value(roman[i]) < value(roman[i + 2]) && value(roman[i + 1]) < value(roman[i + 2])) {
          if(roman[i] != roman[i + 1]){
            throw logic_error("wrong sequenz of digits");
          }
          if(value(roman[i + 2]) == 5 || value(roman[i + 2]) == 50 || value(roman[i + 2]) == 500){
            throw logic_error("calculating minus V, L or D");
          }
          if(value(roman[i + 2]) == 10 || value(roman[i + 2]) == 100 || value(roman[i + 2]) == 1000){
            throw logic_error("calculating minus X, C or M");
          }
        }
        if(value(roman[i]) == 5 || value(roman[i]) == 50 || value(roman[i]) == 500){
          throw logic_error("calculating minus V, L or D");
        }
      }
    }
    for(int y {i + 1}; y < roman.length(); y++){
      if(value(roman[i]) == value(roman[y])){
        anz++;
      }
      if(anz > 3){
        throw logic_error("Too many digits of the same kind ");
      }
    }
    if (value(roman[i + 1]) == 5 || value(roman[i]) == 50 || value(roman[i]) == 500) {
      for(int y {i}; y < roman.length(); y++){
        if(value(roman[i]) == value(roman[y])){
          anz++;
        }
        if(anz > 1){
          throw logic_error("Too many digits of the same kind ");
        }
      }
    }
  }
}


unsigned int roman2dec(string roman){
  test(roman);
  int erg {0};
  for(int i {0}; i < roman.length(); i++){
    while(i + 2 < roman.length()){
      if(value(roman[i]) >= value(roman[i +1]) && value(roman[i + 2])){
        erg += value(roman[i]);
      }
      else{
        erg -= value(roman[i]);
      }
      i++;
    }
    if(i + 2 == roman.length()){
      if(value(roman[i]) >= value(roman[i +1])){
        erg += value(roman[i]);
      }
      else{
        erg -= value(roman[i]);
      }
    }
    if(i + 1 == roman.length()){
      erg += value(roman[i]);
    }
  }
  return erg;
}


int main(){
  string str {};
  int erg {};
  vector<string> invalid_data {"A", "IIII", "VV", "VIIII", "IIV", "XIIII", "XIIIII", "IIX", "XXXX", "XXXXX", "XXIIIV", "LIVX", "LXVIV", "VIV", "LXL", "DD", "DCDII", "IVI", "LC", "DM"};
  for(auto item: invalid_data) {
    bool caught{};
  try{
    cout << item << endl;
    roman2dec(item);
  }
  catch(logic_error &e) {
    caught = true;
    cout << e.what() << endl;
  }
  assert(caught);
}
  vector<pair<string, unsigned int>> valid_data{
    {"I",1}, {"II",2}, {"III",3}, {"IV",4}, {"V",5},{"VI",6}, {"VII",7}, {"VIII",8}, {"IX",9}, {"X",10},{"XI",11}, {"XII",12}, {"XIII",13}, {"XIV",14}, {"XV",15},{"XVI",16},
    {"XVII",17}, {"XVIII",18}, {"XIX",19}, {"XX",20},{"XXI",21}, {"XXII",22}, {"XXIII",23}, {"XXIV",24}, {"XXV",25},{"XXVI",26}, {"XXVII",27}, {"XXVIII",28}, {"XXIX",29}, {"XXX",30},
    {"XXXI",31}, {"XXXII",32}, {"XXXIII",33}, {"XXXIV",34}, {"XXXV",35},{"XXXVI",36}, {"XXXVII",37}, {"XXXVIII",38}, {"XXXIX",39}, {"XL",40},{"XLI",41}, {"XLII",42}, {"XLIII",43},
    {"XLIV",44}, {"XLV",45},{"XLVI",46}, {"XLVII",47}, {"XLVIII",48}, {"IL",49}, {"L",50},{"LI",51}, {"LII",52}, {"LIII",53}, {"LIV",54}, {"LV",55},{"LVI",56}, {"LVII",57},
    {"LVIII",58}, {"LIX",59}, {"LX",60},{"LXI",61}, {"LXII",62}, {"LXIII",63}, {"LXIV",64}, {"LXV",65},{"LXVI",66}, {"LXVII",67}, {"LXVIII",68}, {"LXIX",69}, {"LXX",70},{"LXXI",71},
    {"LXXII",72}, {"LXXIII",73}, {"LXXIV",74}, {"LXXV",75},{"LXXVI",76}, {"LXXVII",77}, {"LXXVIII",78}, {"LXXIX",79}, {"LXXX",80},{"LXXXI",81}, {"LXXXII",82}, {"LXXXIII",83},
    {"LXXXIV",84}, {"LXXXV",85},{"LXXXVI",86}, {"LXXXVII",87}, {"LXXXVIII",88}, {"LXXXIX",89}, {"XC",90},{"XCI",91}, {"XCII",92}, {"XCIII",93}, {"XCIV",94}, {"XCV",95},{"XCVI",96},
    {"XCVII",97}, {"XCVIII",98}, {"IC",99}, {"C",100},{"CXLVIII",148}, {"CXCIII",193}, {"CCCXC",390}, {"CCCIC",399},{"ID",499}, {"D",500}, {"MMMCM",3900}, {"MMMCMXLIV",3944}
  };
  try{
    for(auto p: valid_data) {
      cout << roman2dec(p.first) << "     ";
      assert(roman2dec(p.first) == p.second);
    }
  }
  catch(logic_error &e){
    cout << e.what() << endl;
  }
  cout << "Das Ergebnis lautet " << erg << endl;
}
