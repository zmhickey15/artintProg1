#include <iostream>
#include <list>
#include <vector>
#include<string>

using namespace std;

struct symptom{
  int symptomNum;
  string name;
  int have; // -1 no info, 0 dont have 1 have
};

struct conclusion{
  int ruleNUM;
  string conclusion; // what conclusion is 
  int status; // -1 no info, 0 dont have, 1 false


};


int main( ){
// create var list 
 symptom varList[6] = { { 16, "trouble sleeping", -1 },   
                        { 6, "poor concentration", -1 },
                        { 12, "expereance sadness", -1 },
                        { 14, "loss of pleasure", -1 },
                        { 18, "weight loss", -1 },
                        { 21, "hallucinations", -1 }
                      };
// create conclusion list 
//conclusion conList[] = 


}

