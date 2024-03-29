// 
// Class for input of quantity TkrHitsTowerPlane for monitoring 
// 
// Created by dpaneque on Fri Apr  6 01:40:59 2007 
// Object created automatically by script makeNewMonObject.pl
//
#include "MonInput_TkrHitsTowerPlane.h"
#include "digiRootData/GlastAxis.h"
#include "../Geo.h"

#include <iostream>
#include <cassert>

// User defined part 
#define NAME TkrHitsTowerPlane
#define OUTBRANCH "TkrHitsTowerPlane"
#define LEAF "TkrHitsTowerPlane[16][36]/s"
#define INBRANCH "m_tkrDigiCol"
// #define ACCESSOR Capullo2
#define MONSOURCE DigiEvent
#define INPUTSOURCE "DigiEvent"
#define DESCRIPTION "Number of hits in a given tower and plane"
#include "digiRootData/DigiEvent.h"

// End user defined part 

MonInput_TkrHitsTowerPlane::MonInput_TkrHitsTowerPlane(){
  m_name=OUTBRANCH;
}
MonInput_TkrHitsTowerPlane::~MonInput_TkrHitsTowerPlane(){
}


int MonInput_TkrHitsTowerPlane::setOutputBranch(TTree* tree) {
 TBranch* bErr= tree->Branch(OUTBRANCH,m_val,LEAF);
 return bErr != 0 ? 0 : 1;
}
void MonInput_TkrHitsTowerPlane::enableInputBranch(TTree& tree){
  tree.SetBranchStatus(INBRANCH,1);
}
void MonInput_TkrHitsTowerPlane::setValue(TObject* event) {
  MONSOURCE* de=dynamic_cast<MONSOURCE*>(event);
  if (de==0){
    std::cerr<<"Using object "<<OUTBRANCH<<" with wrong kind of data tree (like digi, reco, etc.)"<<std::endl;
    assert(de);
  }


  const UShort_t NTower = 16; // should we get that from defined macro with global quantities? 
  const UShort_t NPlane = 36;

  for(UShort_t i = 0; i < NTower; i++){
    for(UShort_t j = 0; j < NPlane;j++)
      m_val[i][j] = 0;
  }

  // let's compute number of hits per tower and plane
  //  Loop over TkrDigiCol object and Fill 2d vector m_val[NTower][NPlane] with number of hits
            
  Int_t TowerId(0),BiLayer(0),View(0),Plane(0);
  
  Int_t nTkrDigis = de->getTkrDigiCol()->GetLast()+1;
  
  for(Int_t i = 0; i < nTkrDigis; i++) {
    const TkrDigi* tkrDigi = de->getTkrDigi(i);
    assert(tkrDigi != 0); 
    
    TowerId= tkrDigi->getTower().id();
    BiLayer = tkrDigi->getBilayer();
    GlastAxis::axis direction = tkrDigi->getView();
    View = (direction == GlastAxis::X) ? 0 : 1;
    Plane= Geo::instance()->getPlane(BiLayer, View);
    
    // temp 
    /*
      std::cout << i << " Tower=" << TowerId << ", Bilayer=" << BiLayer 
      << ", Plane=" << Plane << std::endl
      << "Hits= " << tkrDigi->getm_val() << std::endl;
    */
    // end temp
    
    m_val[TowerId][Plane] = UShort_t(tkrDigi->getNumHits());
  }
  
}


std::string MonInput_TkrHitsTowerPlane::getInputSource(){
  return INPUTSOURCE;
}
std::string MonInput_TkrHitsTowerPlane::getDescription(){
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

