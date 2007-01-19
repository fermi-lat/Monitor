#ifndef JobConfig_h
#define JobConfig_h 

#include <iostream>

#include "Rtypes.h"
#include <string>

class TChain;

 
class JobConfig {

public :
  
  // Standard c'tor
  JobConfig(const char* appName, const char* desc);

  virtual ~JobConfig();  

  void usage();
  
  Int_t parse(int argn, char** argc);

  inline const std::string& theApp() const { return m_theApp; }
  inline const std::string& path() const { return m_path; }

  inline const std::string& jobOptionXmlFile() const { return m_jobOptionXmlFile; }

  inline const std::string& inputDigiFileStr() const { return m_inputDigiFileStr; }
  inline const std::string& inputReconFileStr() const { return m_inputReconFileStr; }
  inline const std::string& inputSvacFileStr() const { return m_inputSvacFileStr; }
  inline const std::string& inputMeritFileStr() const { return m_inputMeritFileStr; }

  inline const std::string& outputPrefix() const { return m_outputPrefix; }
  inline const std::string& timeStamp() const { return m_timeStamp; }

  inline int optval_n() const { return m_optval_n; }
  inline int optval_s() const { return m_optval_s; }
  inline int optval_b() const { return m_optval_b; }

  inline TChain* digiChain() const { return m_digiChain;}
  inline TChain* reconChain() const { return m_reconChain;}
  inline TChain* svacChain() const { return m_svacChain;}
  inline TChain* meritChain() const { return m_meritChain;}

  Bool_t checkDigi() const;
  Bool_t checkRecon() const;
  Bool_t checkSvac() const;
  Bool_t checkMerit() const;
   
protected:

  TChain* makeChain(const char* name, const std::string& fileString) const;
 
private:

  std::string m_theApp;
  std::string m_description;
  std::string m_path;

  std::string m_jobOptionXmlFile;

  std::string m_inputDigiFileStr;
  std::string m_inputReconFileStr;
  std::string m_inputSvacFileStr;
  std::string m_inputMeritFileStr;

  std::string m_outputPrefix;
  std::string m_timeStamp;

  int m_optval_n;
  int m_optval_s;
  int m_optval_b;

  TChain* m_digiChain;
  TChain* m_reconChain;
  TChain* m_svacChain;
  TChain* m_meritChain;
    
};

#endif
