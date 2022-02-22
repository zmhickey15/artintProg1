#include <iostream>
#include <list>
#include <stack>
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
  string diseaseName;


};
void getVar( knowledge &var );
void checkRule( int ruleNUM, knowledge *conclusions, knowledge *vars);
string forwardChain( knowledge *vars, knowledge disease);

int main( ){
// create var list 
 knowledge varList[16] = { { 0, "trouble sleeping", -1 },  //0  16
                        { 1, "poor concentration", -1 },  //1   6
                        { 2, "expereance sadness", -1 }, //2   12
                        { 3, "loss of pleasure", -1 },  //3  14
                        { 4, "weight loss", -1 },      //4  18
                        { 5, "hallucinations", -1 },   //5   21

                                                        // for forward chain                                                      
                        { 6, "strugle to controle emotions", -1 }, //6
                        { 7, "migranes", -1 }, //7
                        { 8, "anxiety", -1 },  //8
                        { 9, "stress", -1 },  //9
                        { 10, "inappropriate emotions", -1 }, //10
                        { 11, "depression", -1 }, //11 
                        { 12, "maina", -1 }, //12
                        { 13, "OCD", -1 }, //13
                        { 14, "irriability", -1 }, //14
                        { 15, "PTSD", -1 }, //15
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
    clauseVarList[2] = nullptr;

    clauseVarList[5] = &varList[0];
    clauseVarList[6] = nullptr;
    clauseVarList[9] = &conList[0];
    clauseVarList[10] = &varList[1];
    clauseVarList[11] = nullptr;

    clauseVarList[13] = &conList[2];
    clauseVarList[14] = &varList[2];
    clauseVarList[15] = &varList[3];
  clauseVarList[16] = nullptr;

    clauseVarList[17] = &conList[3];
    clauseVarList[18] = &varList[4];
clauseVarList[19] = nullptr;

    clauseVarList[21] = &conList[4];
    clauseVarList[22] = nullptr;

    clauseVarList[25] = &conList[3];
    clauseVarList[26] = &varList[2];
    clauseVarList[27] = nullptr;

    clauseVarList[29] = &conList[6];
    clauseVarList[30] = nullptr;

    clauseVarList[33] = &conList[3];
    clauseVarList[34] = &varList[4];
clauseVarList[35] = nullptr;

    clauseVarList[37] = &conList[8];
  clauseVarList[38] = nullptr;

    clauseVarList[41] = &conList[0];
    clauseVarList[42] = &varList[1];
clauseVarList[43] = nullptr;

    clauseVarList[45] = &conList[10];
    clauseVarList[46] = &varList[2];
    clauseVarList[47] = &varList[3];
clauseVarList[48] = nullptr;

    clauseVarList[49] = &conList[11];
    clauseVarList[50] = &varList[4];
  clauseVarList[51] = nullptr;

    clauseVarList[53] = &conList[12];
    clauseVarList[54] = nullptr;

    clauseVarList[57] = &conList[10];
    clauseVarList[58] = &varList[2];
clauseVarList[59] = nullptr;

    clauseVarList[61] = &conList[14];
    clauseVarList[62] = &varList[4];
      clauseVarList[63] = nullptr;
    
    clauseVarList[65] = &conList[15];
    clauseVarList[66] = nullptr;

    clauseVarList[69] = &conList[1];
    clauseVarList[70] = &varList[1]; // was 6
clauseVarList[71] = nullptr;

    clauseVarList[73] = &conList[17];
    clauseVarList[74] = &varList[5];
clauseVarList[75] = nullptr;

    clauseVarList[77] = &conList[18];
    clauseVarList[78] = nullptr;

    clauseVarList[81] = &conList[1];
    clauseVarList[82] = &varList[1];

    clauseVarList[83] = nullptr;

    clauseVarList[85] = &conList[20];
    clauseVarList[86] = &varList[5];
clauseVarList[87] = nullptr;

    clauseVarList[89] = &conList[21]; // was 22
    clauseVarList[90] = nullptr;

    clauseVarList[93] = &conList[20]; // was 21
    clauseVarList[94] = &varList[5];
  clauseVarList[95] = nullptr;

    clauseVarList[97] = &conList[23]; // was 24
  clauseVarList[98] = nullptr;







    bool done = false;
    knowledge* disease;
    stack<knowledge> conStack; 
    while ( done == false ){  

      for ( knowledge con : conList){
        //cout << con.Name << endl;
        if ( con.Name.compare("disease")==0 && con.status == -1 ){
          conStack.push(con);
          break;
        }
        if ( con.Name.compare("disease")==0 && con.status == 1 )
        {
        done = true;
        *disease = con;   
        }
        //end while loop
        if (done == true){
          break;
        }
      } 


        while( !conStack.empty() ){ // loop to check if disease is good or not 
          disease = &conStack.top();
          int clauseNum = (4 * ( (*disease).identifyNum / 10 - 1 ) + 1 );

      // checs diseases stuff in clause var list 
          while (clauseVarList[clauseNum] != nullptr){
            if( clauseVarList[clauseNum]->status == -1){
              if( clauseVarList[clauseNum]->identifyNum < 10 )// its a var 
                getVar(*clauseVarList[clauseNum]);
              else{ 
                conStack.push( *clauseVarList[clauseNum] );
                //cout<<clauseVarList[clauseNum]->Name << endl; // for testing  // endliss loop is heer
              }
          }
            clauseNum ++;
          }
          // check rule 
        disease = &conStack.top();
        clauseNum = (4 * ( (*disease).identifyNum / 10 - 1 ) + 1 ); 
        bool rule = true;

        while (clauseVarList[clauseNum] != nullptr){
            if(clauseVarList[clauseNum]->status == -1){
              rule = false;
            }
            clauseNum++;
        }
        if( rule == true ){
              checkRule((*disease).identifyNum, conList, varList);
              
              clauseNum = (4 * ( (*disease).identifyNum / 10 - 1 ) + 1 ); 
              disease = clauseVarList[clauseNum];
             //  cout << "rule tested" << (*disease).Name << (*disease).status << endl;
               conStack.pop();
        }

     if ( (*disease).Name.compare("disease")== 0 && (*disease).status == 1 )
        done = true;
    }
    // edge case
    int k = 0;
    for ( knowledge con : conList){
      if( con.Name.compare("disease")== 0 && con.status == 0){
        k++;
      }
    }
    if( k == 8){
      done =true;
      disease->diseaseName="no disease found";
    }
  }

  string treatment = forwardChain( varList, *disease );
  cout << endl << endl << "you have been diagnosed with: " << (*disease).diseaseName << endl
      << "the recomended treatment is: " << treatment << endl;
  
  


}

void getVar( knowledge &var ){
  cout<< endl << "Do you expereance the following symptom:"<<endl;
  cout<<var.Name<<endl;
  cout<< "enter 1 if you experance the symptom" << endl
      << "enter 0 if you do not" << endl;
      int value;
      cin >> value;
      do
      {
        if (value == 1 || value == 0){
          var.status=value;
          return;
        }   
        else {
          cout<< "incorect imput: please enter 1 if you have symptom or 0 if you dont" 
              << endl;
            cin >>value;

        }
      } while (1==1);
      
}

void checkRule( int ruleNUM, knowledge *conclusions, knowledge *symptoms){
  // conclusions ints 
  int a = 0;
  int b = 1;
  int c = 2;
  int d = 10;
  int e = 17;
  int f = 20;
  int g = 3;
  int h = 6;
  int i = 11;
  int j = 14;
  int k = 1;
  int l = 21;
  int m = 23;
  int n = 4;
  int o = 8;
  int p = 12;
  int q = 15;
  int s = 18;
  int ruleNum = ruleNUM;

  switch (ruleNum){

    case 10:
      if( symptoms[0].status == 1 )
        conclusions[a].status = 1;
      else
        conclusions[a].status = 0;
    break;
    
    case 20:
      if ( symptoms[0].status == 0 )
        conclusions[b].status = 1;
      else
        conclusions[b].status = 0;
    break;
    
    case 30:
      if ( conclusions[a].status == 1 && symptoms[1].status == 1 )
        conclusions[c].status = 1;
      else 
        conclusions[c].status = 0;
    break;
    
    case 40:
      if ( conclusions[c].status == 1 && symptoms[2].status == 1 
            && symptoms[3].status ==1 )
          conclusions[g].status = 1;
      else 
        conclusions[g].status = 0;
    break;
    
    case 50:
      if ( conclusions[g].status == 1 && symptoms[4].status == 1 )
        conclusions[n].status = 1;
      else 
        conclusions[n].status = 0;
     break;
    
    case 60:
      if ( conclusions[n].status == 1 ){
        conclusions[5].status = 1;
        conclusions[5].diseaseName = "Dyshymia";
      }
      else  
        conclusions[5].status = 0;
    break;
    
    case 70:
      if ( conclusions[c].status == 1 && symptoms[2].status == 0)
        conclusions[h].status = 1;
      else
        conclusions[h].status = 0;
    break;
    
    case 80:
      if ( conclusions[h].status == 1 ){
        conclusions[7].status = 1;
        conclusions[7].diseaseName = "Generalized Anxiety";
      }
      else
        conclusions[7].status = 0;
    break;
    
    case 90:
      if ( conclusions[g].status == 1 && symptoms[4].status == 0 )
        conclusions[o].status = 1;
      else
        conclusions[o].status = 0;
    break;
    
    case 100:
      if ( conclusions[o].status == 1 ){
        conclusions[9].status = 1;
        conclusions[9].diseaseName = "Bipolar";
      }
      else 
        conclusions[9].status = 0;
    break;
    
    case 110:
      if( conclusions[a].status == 1 && symptoms[1].status == 0 )
        conclusions[d].status = 1;
      else 
        conclusions[d].status = 0;
    break;
    
    case 120:
      if ( conclusions[d].status == 1 && symptoms[2].status == 1 &&
          symptoms[3].status == 1 )
        conclusions[i].status = 1;
      else
        conclusions[i].status = 0;
    break;
  
    case 130:
      if ( conclusions[i].status == 1 && symptoms[4].status == 1)
        conclusions[p].status = 1;
      else 
        conclusions[p].status = 0;
    break;
    
    case 140:
      if ( conclusions[p].status == 1 ){
        conclusions[13].status = 1;
        conclusions[13].diseaseName = "Major Depressive Disorder";
      }
      else 
        conclusions[13].status = 0;
    break;
    
    case 150:
      if ( conclusions[d].status == 1 && symptoms[2].status == 0 )
        conclusions[j].status = 1;
      else 
        conclusions[j].status = 0;
    break;

    case 160:
      if(conclusions[j].status == 1 && symptoms[4].status == 1)
        conclusions[q].status = 1;
      else 
        conclusions[q].status = 0;
    break;
    
    case 170:
      if ( conclusions[q].status == 1 ){
        conclusions[16].status = 1;
        conclusions[16].diseaseName = "Disocitve Identity Disorder";
      }
      else 
        conclusions[16].status = 0;
    break;

    case 180: 
      if ( conclusions[b].status == 1 && symptoms[1].status == 1 )
        conclusions[e].status =1;
      else
        conclusions[e].status = 0;
    break;

    case 190:
      if ( conclusions[e].status == 1 && symptoms[5].status == 1)
        conclusions[s].status = 1;
      else 
        conclusions[s].status = 0;
    break;
    
    case 200:
      if ( conclusions[s].status == 1 ){
        conclusions[19].status = 1;
        conclusions[19].diseaseName = "Schizophrenia";
      }
      else
        conclusions[19].status = 0;
    break;
    
    case 210:
      if ( conclusions[b].status == 1 && symptoms[1].status == 0 )
        conclusions[f].status = 1;
      else  
        conclusions[f].status = 0;
    break;

    case 220:
      if ( conclusions[f].status == 1 && symptoms[5].status == 1 )
        conclusions[l].status = 1;
      else conclusions[l].status = 0;
    break;

    case 230:
      if ( conclusions[l].status == 1 ){
          conclusions[22].status = 1;
          conclusions[22].diseaseName = "Schizo-Affective Disorder";
      }   
      else  
        conclusions[22].status = 0;
    break;

    case 240:
      if ( conclusions[f].status == 1 && symptoms[5].status == 0 )
        conclusions[m].status = 1;
      else
        conclusions[m].status = 0;
    break;

    case 250:
      if ( conclusions[m].status == 1 ){
          conclusions[24].status = 1;
          conclusions[24].diseaseName = "Panic Disorder with Agoraphobia";
      }
      else 
        conclusions[24].status = 0;
    break;
    default:
      break;
}



}


string forwardChain( knowledge *vars, knowledge disease){
 
  if(disease.diseaseName.compare("Bipolar") == 0){
    if( vars[6].status == -1)
      getVar( vars[6] );
    if ( vars[6].status == 1)
      return "psychotherapy";
    if ( vars[7].status == -1 )
      getVar( vars[7] );
    if ( vars[6].status == 0 && vars[7].status == 1)
      return "Divalproate";
    else 
      return "Paliperidone";
  }
  if ( disease.diseaseName.compare("Dyshymia") == 0 ){
    if( vars[8].status == -1 )
      getVar( vars[8] );
    if( vars[2].status == 1 && vars[8].status ==1 )
      return "Duloxetine";
    if ( vars[2].status == 1 && vars[8].status ==0 )
      return "Desvenlafaxine";
  }
  if( disease.diseaseName.compare ("Major Depressive Disorder") == 0){
    if( vars[9].status == -1)
      getVar( vars[9] );
    if( vars[9].status ==1 )
      return "Buspirone";
    if( vars[8].status == -1 )
      getVar( vars[8] );
    if ( vars[9].status == 0 && vars[8].status == 1 )
      return "Imipramine";
    else 
      return "Mirtazapine";
  }
  if (disease.diseaseName.compare("Disocitve Identity Disorder") == 0){
    if( vars[8].status == -1 )
      getVar( vars[8] );
    if( vars[0].status == 1 && vars[8].status == 1)
      return "Clonazepam";
    else  
      return "melatonin";

  }
  if( disease.diseaseName.compare("Generalized Anxiety") == 0){
    if( vars[10].status == -1 )
      getVar( vars[10] );
    if( vars[10].status == 1)
        return "Paliperidone";
    if( vars[11].status == -1 )
      getVar( vars[11] );
    if( vars[11].status == 1 && vars[10].status == 0)
        return "Citalopram";
    else
      return "Duloxetine";
  }

  if ( disease.diseaseName.compare("Schizophrenia") == 0 ){
    if( vars[12].status == -1 )
      getVar( vars[12] );
    if( vars[12].status == 1)
        return "Olanzapine";
    else 
      return "Quetiapine";
  }

  if( disease.diseaseName.compare ("Schizo-Affective Disorder") == 0 ){
    if( vars[13].status == -1 )
      getVar( vars[13] );
    if( vars[13].status == 1 )
      return "Sertraline";
    if( vars[14].status == -1 )
      getVar( vars[14] );
    if( vars[13].status == 0 && vars[14].status == 1 )
      return "Risperidone";   
    else  
      return "Fluoxetine";
  }

  if( disease.diseaseName.compare ("Panic Disorder with Agoraphobia") == 0 ){
    if( vars[13].status == -1 )
      getVar( vars[13] );
    if( vars[13].status == 1 )
      return "Sertraline";
    if( vars[15].status == -1 )
      getVar( vars[15] );
    if( vars[13].status == 0 && vars[15].status == 1)
      return "Paroxetine";
    if( vars[11].status == -1 )
      getVar( vars[11] );
    if( vars[13].status == 0 && vars[15].status ==0 && vars[11].status ==1 )
      return "Tricyclic Antidepressants";
    else 
      return "Fluoxetine";
  }
  return "no treatment recomended";

}