// 
// Class for input of quantity CTBClassLevel for monitoring 
// 
// Created by dpaneque on Sat Sep 29 01:10:02 2007 
// Object created automatically by script makeNewMonObject.pl
//
#include "MonInput_CTBClassLevel.h"
#include <iostream>

// User defined part 

#define NAME CTBClassLevel
#define OUTBRANCH "CTBClassLevel"
#define LEAF "CTBClassLevel/F"
#define INBRANCH "CTBClassLevel"
#define ACCESSOR vv
#define MONSOURCE MeritEvent
#define INPUTSOURCE "MeritEvent"
#define DESCRIPTION "Description not available at the moment ... FIX ME !!"


// End user defined part 

MonInput_CTBClassLevel::MonInput_CTBClassLevel(){
  m_name=OUTBRANCH;
}
MonInput_CTBClassLevel::~MonInput_CTBClassLevel(){
}


int MonInput_CTBClassLevel::setOutputBranch(TTree* tree) {
 TBranch* bErr= tree->Branch(OUTBRANCH,&m_val,LEAF);
 return bErr != 0 ? 0 : 1;
}
void MonInput_CTBClassLevel::enableInputBranch(TTree& tree){
  tree.SetBranchStatus(INBRANCH,1);
  tree.SetBranchAddress(INBRANCH,&m_val);
}
void MonInput_CTBClassLevel::setValue(TObject* event) {
}
std::string MonInput_CTBClassLevel::getInputSource(){
  return INPUTSOURCE;
}
std::string MonInput_CTBClassLevel::getDescription(){
  return DESCRIPTION;
}

#undef INPUTSOURCE
#undef NAME
#undef OUTBRANCH
#undef LEAF
#undef INBRANCH 
#undef ACCESSOR
#undef MONSOURCE
#undef DESCRIPTION

