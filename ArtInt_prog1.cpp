#include <iostream>
#include <list>
#include <vector>
#include<string>

using namespace std;

struct symptom{    // not using same as knowledge 
  int symptomNum;
  string name;
  int have; // -1 no info, 0 dont have 1 have
};

struct knowledge{
  int identifyNum;
  string Name; // what conclusion is 
  int status; // -1 no info, 0 dont have, 1 false


};


int main( ){
// create var list 
 knowledge varList[6] = { { 16, "trouble sleeping", -1 },  //0 
                        { 6, "poor concentration", -1 },  //1
                        { 12, "expereance sadness", -1 }, //2
                        { 14, "loss of pleasure", -1 },  //3
                        { 18, "weight loss", -1 },      //4
                        { 21, "hallucinations", -1 }   //5 
                      };
// create conclusion list 
knowledge conList[25] = { { 10, "A", -1 },   
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
// set clause var list
knowledge *clauseVarList[100]; // 97 is last one used 

    clauseVarList[1] = &varList[0];
    clauseVarList[5] = &varList[0];
    clauseVarList[9] = &conList[0];
    clauseVarList[10] = &varList[1];
    clauseVarList[13] = &conList[1];
    clauseVarList[14] = &varList[2];
    clauseVarList[15] = &varList[3];
    clauseVarList[17] = &conList[3];
    clauseVarList[18] = &varList[4];
    clauseVarList[21] = &conList[4];
    clauseVarList[25] = &conList[3];
    clauseVarList[26] = &varList[2];
    clauseVarList[29] = &conList[6];
    clauseVarList[33] = &conList[3];
    clauseVarList[34] = &varList[4];
    clauseVarList[37] = &conList[8];
    clauseVarList[41] = &conList[0];
    clauseVarList[42] = &varList[1];
    clauseVarList[45] = &conList[10];
    clauseVarList[46] = &varList[2];
    clauseVarList[47] = &varList[3];
    clauseVarList[49] = &conList[11];
    clauseVarList[50] = &varList[4];
    clauseVarList[53] = &conList[12];
    clauseVarList[57] = &conList[10];
    clauseVarList[58] = &varList[2];
    clauseVarList[61] = &conList[14];
    clauseVarList[62] = &varList[4];
    clauseVarList[65] = &conList[15];
    clauseVarList[69] = &conList[1];
    clauseVarList[70] = &varList[6];
    clauseVarList[73] = &conList[17];
    clauseVarList[74] = &varList[5];
    clauseVarList[77] = &conList[18];
    clauseVarList[81] = &conList[1];
    clauseVarList[82] = &varList[1];
    clauseVarList[85] = &conList[20];
    clauseVarList[86] = &varList[5];
    clauseVarList[89] = &conList[22];
    clauseVarList[93] = &conList[21];
    clauseVarList[94] = &varList[5];
    clauseVarList[97] = &conList[24];
        





}

