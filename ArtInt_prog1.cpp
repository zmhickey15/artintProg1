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
conclusion conList[25] = { { 10, "A", -1 },   
                           { 20, "B", -1 },
                           { 30, "C", -1 },
                           { 40, "G", -1 },
                           { 50, "N", -1 },
                           { 60, "disease", -1 },
                           { 70, "H", -1 },
                           { 80, "disease", -1 },
                           { 90, "O", -1 },
                           { 100, "disease", -1 },
                           { 110, "D", -1 },
                           { 120, "I", -1 },
                           { 130, "P", -1 },
                           { 140, "disease", -1 },
                           { 150, "J", -1 },
                           { 160, "Q", -1 },
                           { 170, "disease", -1 },
                           { 180, "E", -1 },
                           { 190, "S", -1 },
                           { 200, "disease", -1 },
                           { 210, "F", -1 },
                           { 220, "L", -1 },
                           { 230, "disease", -1 },
                           { 240, "M", -1 },
                           { 250, "disease", -1 }
                      };


}

