// 
// Class for input of quantity FT1ZenithTheta for monitoring 
// 
// Created by dpaneque on Thu Mar 13 01:11:09 2008 
// Object created automatically by script makeNewMonObject.pl
//
#include "MonInput_FT1ZenithTheta.h"
#include <iostream>

// User defined part 

#define NAME FT1ZenithTheta
#define OUTBRANCH "FT1ZenithTheta"
#define LEAF "FT1ZenithTheta/F"
#define INBRANCH "FT1ZenithTheta"
#define ACCESSOR cc
#define MONSOURCE MeritEvent
#define INPUTSOURCE "MeritEvent"
#define DESCRIPTION "Reconstructed theta angle (in deg) with respect to the local zenith system"


// End user defined part 

MonInput_FT1ZenithTheta::MonInput_FT1ZenithTheta(){
  m_name=OUTBRANCH;
}
MonInput_FT1ZenithTheta::~MonInput_FT1ZenithTheta(){
}


int MonInput_FT1ZenithTheta::setOutputBranch(TTree* tree) {
 TBranch* bErr= tree->Branch(OUTBRANCH,&m_val,LEAF);
 return bErr != 0 ? 0 : 1;
}
void MonInput_FT1ZenithTheta::enableInputBranch(TTree& tree){
  tree.SetBranchStatus(INBRANCH,1);
  tree.SetBranchAddress(INBRANCH,&m_val);
}
void MonInput_FT1ZenithTheta::setValue(TObject* event) {
}
std::string MonInput_FT1ZenithTheta::getInputSource(){
  return INPUTSOURCE;
}
std::string MonInput_FT1ZenithTheta::getDescription(){
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

