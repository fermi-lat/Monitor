
#include "MonValue_t.h"
#include "TROOT.h"
#include "TTree.h"
#include "TSystem.h"
#include "TSelector.h"
#include "TTreeFormula.h"
#include "TEventList.h"
#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
#include <unistd.h>
#include "compareFiles.h"
#include <time.h>

std::vector<double> *MonValue::m_result=new std::vector<double>;
std::vector<double> *MonValue::m_result2=new std::vector<double>;
unsigned int MonValue::m_counter=0;

MonValue::MonValue(const char* name, const char* formula, const char* cut):m_cut(cut), m_formula(formula),m_sel(0),m_histdim(0),m_timeprof(0){
  // split up the name into the name part and the dimension part

  char* dimpos=strchr(name,'[');
  if (dimpos==0){
    m_name=std::string(name);
    m_dim=1;
    m_dimstring="";
  }else{
    char res[128];
    char* dimpos=strchr(name,'[')+1;
    strncpy(res,name,dimpos-name-1);
    res[dimpos-name-1]='\0';
    m_name=std::string(res);
    char* dimstart=dimpos-1;
    char* token=strstr(dimpos,"][");
    int dims=1;
    while (token!=0){
      strncpy (res,dimpos,token-dimpos);
      res[token-dimpos]='\0';
      dims*=atoi(res);
      dimpos=token+2;
      token=strstr(dimpos,"][");
    }
    token=strchr(dimpos,']');
    assert(token);
    strncpy (res,dimpos,token-dimpos);
    res[token-dimpos]='\0';
    dims*=atoi(res);
    strcpy(res,dimstart);
    m_dimstring=std::string(res);
    m_dim=dims;
  }
}
  
void MonValue::makeProxy(TTree* tree){
  bool engineloop=false;
  bool towerloop=false;
  bool tkrlayerloop=false;
  bool tkrplaneloop=false;
  bool acdfaceloop=false;
  bool acdrowloop=false;
  bool acdcolumnloop=false;
  bool acdpmtloop=false;
  bool acdgarcloop=false;
  bool acdgafeloop=false;
  bool acdtileloop=false;
  bool callayerloop=false;
  bool calcolumnloop=false;
  bool dooutsideformula=false;
  std::string formula(m_formula);

  ///  std::cout << "Formula BEFORE all loops subrtraction: " << formula.c_str() << std::endl;

  std::string outsideformula;
  unsigned int outsidepos=formula.find("runonce:");
  if(outsidepos!=0xffffffff){
    dooutsideformula=true;
    unsigned int endformula=formula.find("#");
    outsideformula=formula.substr(outsidepos+strlen("runonce:"),endformula-outsidepos-strlen("runonce:"));
    formula.replace(outsidepos,endformula+1,"");
  }
  unsigned int enginepos=formula.find("foreachengine:");
  if(enginepos!=0xffffffff){
    engineloop=true;
    formula.replace(enginepos,enginepos+strlen("foreachengine:"),"");
  }
  unsigned int towerpos=formula.find("foreachtower:");
  if(towerpos!=0xffffffff){
    towerloop=true;
    formula.replace(towerpos,towerpos+strlen("foreachtower:"),"");
  }
  unsigned int tkrlayerpos=formula.find("foreachtkrlayer:");
  if(tkrlayerpos!=0xffffffff){
    tkrlayerloop=true;
    formula.replace(tkrlayerpos,tkrlayerpos+strlen("foreachtkrlayer:"),"");
  }
  unsigned int tkrplanepos=formula.find("foreachtkrplane:");
  if(tkrplanepos!=0xffffffff){
    tkrplaneloop=true;
    formula.replace(tkrplanepos,tkrplanepos+strlen("foreachtkrplane:"),"");
  }
  unsigned int acdfacepos=formula.find("foreachacdface:");
  if(acdfacepos!=0xffffffff){
    acdfaceloop=true;
    formula.replace(acdfacepos,acdfacepos+strlen("foreachacdface:"),"");
  }
  unsigned int acdrowpos=formula.find("foreachacdrow:");
  if(acdrowpos!=0xffffffff){
    acdrowloop=true;
    formula.replace(acdrowpos,acdrowpos+strlen("foreachacdrow:"),"");
  }
  unsigned int acdcolumnpos=formula.find("foreachacdcolumn:");
  if(acdcolumnpos!=0xffffffff){
    acdcolumnloop=true;
    formula.replace(acdcolumnpos,acdcolumnpos+strlen("foreachacdcolumn:"),"");
  }
  unsigned int acdpmtpos=formula.find("foreachacdpmt:");
  if(acdpmtpos!=0xffffffff){
    acdpmtloop=true;
    formula.replace(acdpmtpos,acdpmtpos+strlen("foreachacdpmt:"),"");
  }
  unsigned int acdgarcpos=formula.find("foreachgarc:");
  if(acdgarcpos!=0xffffffff){
    acdgarcloop=true;
    formula.replace(acdgarcpos,acdgarcpos+strlen("foreachgarc:"),"");
  }
  unsigned int acdgafepos=formula.find("foreachgafe:");
  if(acdgafepos!=0xffffffff){
    acdgafeloop=true;
    formula.replace(acdgafepos,acdgafepos+strlen("foreachgafe:"),"");
  }

  unsigned int acdtilepos=formula.find("foreachacdtile:");
  if(acdtilepos!=0xffffffff){
    acdtileloop=true;
    formula.replace(acdtilepos,acdtilepos+strlen("foreachacdtile:"),"");
  }
  

   unsigned int callayerpos=formula.find("foreachcallayer:");
  if(callayerpos!=0xffffffff){
    callayerloop=true;
    formula.replace(callayerpos,callayerpos+strlen("foreachcallayer:"),"");
  }


  unsigned int calcolumnpos=formula.find("foreachcalcolumn:");
  if(calcolumnpos!=0xffffffff){
    calcolumnloop=true;
    formula.replace(calcolumnpos,calcolumnpos+strlen("foreachcalcolumn:"),"");
  }

  //  std::cout << "Formula after all loops subrtraction: " << formula.c_str() << std::endl;

  if (!engineloop && !towerloop && !tkrlayerloop && !tkrplaneloop && !acdfaceloop && !acdrowloop && !acdcolumnloop && !acdpmtloop && !acdgarcloop && !acdgafeloop && !acdtileloop && !calcolumnloop && !callayerloop
      && !dooutsideformula &&strstr(m_formula.c_str(),"RFun")==0 && strstr(m_cut.c_str(),"RFun")==0)return;

  std::ofstream formfile;
  formfile.open((m_sodir+m_name+"_val.C_tmp").c_str());
  formfile<<"std::vector<double> *resultvector;"<<std::endl;
  if(m_histdim==2)formfile<<"std::vector<double> *resultvector2;"<<std::endl;
  formfile <<"unsigned int *counter;"<<std::endl
	   <<"double "<<m_name+"_val"<<"() {"<<std::endl;
  formfile<<"double val;"<<std::endl;
  if(dooutsideformula)formfile<<"std::vector<double> runonceformula="<<outsideformula<<";"<<std::endl;
  if(engineloop)formfile<<"for(int engine=0;engine<16;engine++){"<<std::endl;
  if(towerloop)formfile<<"for(int tower=0;tower<16;tower++){"<<std::endl;
  if(tkrlayerloop)formfile<<"for(int tkrlayer=0;tkrlayer<19;tkrlayer++){"<<std::endl;
  if(tkrplaneloop)formfile<<"for(int tkrplane=0;tkrplane<36;tkrplane++){"<<std::endl;
  if(acdfaceloop)formfile<<"for(int acdface=0;acdface<5;acdface++){"<<std::endl;
  if(acdrowloop)formfile<<"for(int acdrow=0;acdrow<5;acdrow++){"<<std::endl;
  if(acdcolumnloop)formfile<<"for(int acdcolumn=0;acdcolumn<5;acdcolumn++){"<<std::endl;
  if(acdpmtloop)formfile<<"for(int acdpmt=0;acdpmt<2;acdpmt++){"<<std::endl;
  if(acdgarcloop)formfile<<"for(int garc=0;garc<12;garc++){"<<std::endl;
  if(acdgafeloop)formfile<<"for(int gafe=0;gafe<18;gafe++){"<<std::endl;
  if(acdtileloop)formfile<<"for(int acdtile=0;acdtile<128;acdtile++){"<<std::endl;
  if(callayerloop)formfile<<"for(int callayer=0;callayer<8;callayer++){"<<std::endl;
  if(calcolumnloop)formfile<<"for(int calcolumn=0;calcolumn<12;calcolumn++){"<<std::endl;
  

  


  //formula 2 is only used for 2-d histograms
  std::string formula2;
  if (m_histdim==2){
    std::string dfo="["+formula+"]";
    // for the parsing replace : by ; so :: does not get interpreted as a separator
    for (unsigned int i=1;i<dfo.size()-1;i++) if(dfo[i]==':'&&dfo[i-1]!=':'&&dfo[i+1]!=':')dfo[i]=';'; 
    std::vector<std::string> tt=parse(dfo,"[",";","]");
    if (tt.size()!=2){
      std::cerr<<"2-d histogram "<<m_name<<" does not have a formula for both dimensions"<<std::endl;
      assert(0);
    }
    formula=tt[0];
    formula2=tt[1];
  }    
 
  formfile <<"val = double("<<formula<<");"<<std::endl
	   <<"resultvector->push_back(val);"<<std::endl;
  if(m_histdim==2){
    formfile <<"val = "<<formula2<<";"<<std::endl
	     <<"resultvector2->push_back(val);"<<std::endl;
  }
  if(engineloop)formfile<<"}"<<std::endl;
  if(towerloop)formfile<<"}"<<std::endl;
  if(tkrlayerloop)formfile<<"}"<<std::endl;
  if(tkrplaneloop)formfile<<"}"<<std::endl;
  if(acdfaceloop)formfile<<"}"<<std::endl;
  if(acdrowloop)formfile<<"}"<<std::endl;
  if(acdcolumnloop)formfile<<"}"<<std::endl;
  if(acdpmtloop)formfile<<"}"<<std::endl;
  if(acdgafeloop)formfile<<"}"<<std::endl;
  if(acdgarcloop)formfile<<"}"<<std::endl;
  if(acdtileloop)formfile<<"}"<<std::endl;
  if(calcolumnloop)formfile<<"}"<<std::endl;
  if(callayerloop)formfile<<"}"<<std::endl;


  formfile<<"(*counter)++;"<<std::endl;
  formfile<<"return val;"<<std::endl<<"}"<<std::endl;
  formfile.close();


  formfile.open((m_sodir+m_name+"_val.h_tmp").c_str());
  formfile<<"#include \"Monitor/RFun.h\""<<std::endl;
  formfile.close();
  if(access((m_sodir+m_name+"_val.h").c_str(),F_OK)!=0 || 
     compareFiles((m_sodir+m_name+"_val.h").c_str(),(m_sodir+m_name+"_val.h_tmp").c_str())!=0){   
    rename((m_sodir+m_name+"_val.h_tmp").c_str(),(m_sodir+m_name+"_val.h").c_str());
  }else{
    unlink((m_sodir+m_name+"_val.h_tmp").c_str());
  }


  if (m_cut!=""){
    formfile.open((m_sodir+m_name+"_cut.C_tmp").c_str());
    formfile<<"int "<<m_name+"_cut"<<"(){"<<std::endl
	    <<"return "<<m_cut<<";"<<std::endl<<"}"<<std::endl;
    formfile.close();

    formfile.open((m_sodir+m_name+"_cut.h_tmp").c_str());
    formfile<<"#include \"Monitor/RFun.h\""<<std::endl;
    formfile.close();
    if(access((m_sodir+m_name+"_cut.h").c_str(),F_OK)!=0 || 
    compareFiles((m_sodir+m_name+"_cut.h").c_str(),(m_sodir+m_name+"_cut.h_tmp").c_str())!=0){   
      rename((m_sodir+m_name+"_cut.h_tmp").c_str(),(m_sodir+m_name+"_cut.h").c_str());
    }else{
      unlink((m_sodir+m_name+"_cut.h_tmp").c_str());
    }
  }
  // check if we need to recompile a formula
  bool compile=false;
  // if there was/wasn't a cut before but now there is one we have to compile
  if (m_cut==""){
    if (access((m_sodir+m_name+"_cut.C").c_str(),F_OK)==0){
      compile=true;
      unlink((m_sodir+m_name+"_cut.C").c_str());
    }
  }else{
    if (access((m_sodir+m_name+"_cut.C").c_str(),F_OK)!=0){
      compile=true;
      rename((m_sodir+m_name+"_cut.C_tmp").c_str(),(m_sodir+m_name+"_cut.C").c_str());
     }
  }
  if(access((m_sodir+m_name+"_val.C").c_str(),F_OK)!=0){
    rename((m_sodir+m_name+"_val.C_tmp").c_str(),(m_sodir+m_name+"_val.C").c_str());
    compile=true;
  }else{
    if (compareFiles((m_sodir+m_name+"_val.C").c_str(),(m_sodir+m_name+"_val.C_tmp").c_str())!=0){
    rename((m_sodir+m_name+"_val.C_tmp").c_str(),(m_sodir+m_name+"_val.C").c_str());
    compile=true;
    }else{
      unlink((m_sodir+m_name+"_val.C_tmp").c_str());
    }
  }
  if (m_cut!=""&& !compile){
    if (compareFiles((m_sodir+m_name+"_cut.C").c_str(),(m_sodir+m_name+"_cut.C_tmp").c_str())!=0){
      rename((m_sodir+m_name+"_cut.C_tmp").c_str(),(m_sodir+m_name+"_cut.C").c_str());
      compile=true;
    }else{
      unlink((m_sodir+m_name+"_cut.C_tmp").c_str());
    }
  }
  char rootcommand[128];
  if (compile){
    if (m_cut!=""){
      tree->MakeProxy((m_sodir+m_name+"Selector").c_str(),(m_sodir+m_name+"_val.C").c_str(),(m_sodir+m_name+"_cut.C").c_str(),"nohist");
    }else{
      tree->MakeProxy((m_sodir+m_name+"Selector").c_str(),(m_sodir+m_name+"_val.C").c_str(),"","nohist");
    }
    // patch for root 5.14
    std::ifstream inf((m_sodir+m_name+"Selector.h").c_str());
    std::ofstream outf((m_sodir+m_name+"Selector.h_tmp").c_str());
    char st[200];
    inf.getline(st,200);
    while(strstr(st,"SetTree")==0){
      outf<<st<<std::endl;
      inf.getline(st,200);
    }
    outf<<st<<std::endl;
    outf<<"   delete fHelper;"<<std::endl;
    while(!inf.eof()){
      inf.getline(st,200);
      outf<<st<<std::endl;
    }
    rename((m_sodir+m_name+"Selector.h_tmp").c_str(),(m_sodir+m_name+"Selector.h").c_str());
    //end patch
    std::cout<<"Compiling formula for "<<m_name<<std::endl;
    sprintf(rootcommand,".L %s.h+O",(m_sodir+m_name+"Selector").c_str());
    gROOT->ProcessLine(rootcommand);
  }else{
    std::cout<<"Formula/cut for "<<m_name<<" has not changed. Using old library"<<std::endl;
    gSystem->Load((m_sodir+m_name+"Selector_h.so").c_str());
    //sprintf(rootcommand,".L %s.h+O",(m_name+"Selector").c_str());
    //gROOT->ProcessLine(rootcommand);
  }
  sprintf(rootcommand,"new %s((TTree*)0x%%x);",(m_name+"Selector").c_str());
  m_sel=(TSelector*)gROOT->ProcessLineFast(Form(rootcommand,tree));
  sprintf(rootcommand,"&((%s*)0x%%x)->resultvector;",(m_name+"Selector").c_str());
  std::vector<double> **fVar1 = (std::vector<double>**)gROOT->ProcessLineFast(Form(rootcommand,m_sel));
  *fVar1=m_result;
  if (m_histdim==2){
    sprintf(rootcommand,"&((%s*)0x%%x)->resultvector2;",(m_name+"Selector").c_str());
    std::vector<double> **fVar2 = (std::vector<double>**)gROOT->ProcessLineFast(Form(rootcommand,m_sel));
    *fVar2=m_result2;
  }
  sprintf(rootcommand,"&((%s*)0x%%x)->counter;",(m_name+"Selector").c_str());
  unsigned int **ct = (unsigned int**)gROOT->ProcessLineFast(Form(rootcommand,m_sel));
  *ct=&m_counter;
}
  

void MonValue::increment(TTree* tree){
  struct timespec ts1, ts2;
  clock_gettime(CLOCK_REALTIME, &ts1);
  // Have to reserve space for return values from tree
  Long64_t est;
  unsigned nev;
  TEventList* el=tree->GetEventList();
  if (el==0)nev=tree->GetEntries();
  else nev=el->GetN();
  est=nev*m_dim;
  unsigned iterations=1;
  //tree->SetEstimate(5000000);
  // if there is too much data we have to iterate so we don't run out of memory
  // no proxy case:
  if (m_sel==0){
    if (est>tree->GetEstimate()){
      if(est<MAXMEM)tree->SetEstimate(est);
      else{
	tree->SetEstimate((long long int)MAXMEM+m_dim);//160 MB
	iterations=(unsigned int)(est/MAXMEM+1);
      }
    }
    // proxy case
  }else{
    if (est>m_result->capacity()){
      if(est<MAXMEM){
	m_result->reserve(est);
	if(m_histdim==2)m_result2->reserve(est);
      }
      else{
	m_result->reserve((unsigned int)MAXMEM+m_dim);//160 MB
	if (m_histdim==2) m_result2->reserve((unsigned int)MAXMEM+m_dim);//160 MB
	iterations=(unsigned int)(est/MAXMEM+1);
      }
    }
  }    
  unsigned evperit=nev/iterations+1;
  //  std::cout<<"Estimate: "<<tree->GetEstimate()<<std::endl;
  for (unsigned it=0;it<iterations;it++){
    if (m_sel==0){
      tree->Draw(m_formula.c_str(),m_cut.c_str(),"goff",evperit,evperit*it);
      if (tree->GetPlayer()->GetVar1()->GetNdata()!=(int)m_dim){
	std::cout<<"The dimension of the formula "<<m_formula<<" ("<<tree->GetPlayer()->GetVar1()->GetNdata()<<")"
		 <<" does not match the definition of variable "<<m_name<<m_dimstring<<" ("<<m_dim<<")"<<std::endl;
	assert(0);
      }
      double *val=tree->GetV1();
      double *val2=tree->GetV2();
      for (int i=0;i<tree->GetSelectedRows();i+=m_dim){
	if (val2){
	  singleincrement(&val[i],&val2[i]);
	}else{
	  singleincrement(&val[i]);
	}
      }
    }else{
      m_result->clear();
      m_counter=0;
      tree->Process(m_sel,"goff",evperit,evperit*it);
      unsigned int fdim=0;
      if (m_counter>0)fdim=(unsigned int)((double)m_result->size()/double(m_counter));
      if (m_counter>0&&fdim!=m_dim){
	std::cout<<"The dimension of the formula "<<m_formula<<" ("<<fdim<<")"
		 <<" does not match the definition of variable "<<m_name<<m_dimstring<<" ("<<m_dim<<")"<<std::endl;
	assert(0);
      }
      double *val=&((*m_result)[0]);
      double *val2=&((*m_result2)[0]);
      for (unsigned i=0;i<m_result->size();i+=m_dim){
	if(m_histdim==2)singleincrement(&val[i],&val2[i]);
	else singleincrement(&val[i]);
      }
    }
  }    
  clock_gettime(CLOCK_REALTIME, &ts2);
  // std::cout<<"Moninputcollection "<<ts1.tv_nsec<<" "<<ts2.tv_nsec<<std::endl;
  unsigned long starttime=ts1.tv_sec*1000000+ts1.tv_nsec/1000;
  unsigned long endtime=ts2.tv_sec*1000000+ts2.tv_nsec/1000;
  //sometimes the clock goes backwards.
  if(endtime>starttime)m_timeprof+=(endtime-starttime);

}

float MonValue::timeProfile(){
  float timeprof=(float)m_timeprof/1e6;
  std::cout<<setiosflags(std::ios::left);
  std::cout<<std::setw(60)<<std::setfill(' ')<<m_name<<": "<<timeprof<<" seconds"<<std::endl;
  return timeprof;
}
  
void MonValue::setSharedLibDir(std::string sodir){
  m_sodir=sodir;
}

std::vector<std::string> MonValue::parse(const std::string str, const std::string beg, const std::string sep, const std::string end){
  std::vector<std::string> retvec;
  unsigned int bpos=str.find(beg);
  if(bpos==(unsigned int)-1)return retvec;
  unsigned int epos=str.rfind(end);
  //unsigned int epos=str.find(end,pos+1);
  if(epos==(unsigned int)-1 || epos<bpos)return retvec;
  if (sep==""){
    retvec.push_back(str.substr(bpos+beg.length(),epos-bpos-beg.length()));
  } else{
    unsigned int mpos=str.find(sep,bpos+1);
    unsigned int len=beg.length();
    while(mpos!=(unsigned int)-1 && mpos<epos){
      retvec.push_back(str.substr(bpos+len,mpos-bpos-len));
      bpos=mpos;
      mpos=str.find(sep,mpos+1);
      len=sep.length();
    }
    retvec.push_back(str.substr(bpos+len,epos-bpos-len));
  }
  return retvec;
}
			    
const std::string MonValue::indexString(int index){
  int ind=index;
  std::vector<std::string>dims=parse(m_dimstring,"[","][","]");
  std::string retstring;
  char tmps[128];
  for (unsigned i=0;i<dims.size();i++){
    int fact=1;
    for (unsigned j=i+1;j<dims.size();j++){
      fact*=atoi(dims[j].c_str());
    }
    sprintf(tmps,"_%d",ind/fact);
    retstring+=tmps;
    ind-=ind/fact*fact;
  }
  return retstring;
}
    
    
    
