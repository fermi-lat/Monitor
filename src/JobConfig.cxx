// header file
#include "JobConfig.h"

// stl
#include <stdlib.h>
#include <string>
#include <fstream>
#include <time.h>

// ROOT io
#include "TSystem.h"
#include "TChain.h"

// xml and file parsing
#include "xmlBase/IFile.h"
#include "facilities/Util.h"


JobConfig::JobConfig(const char* appName, const char* desc)
  :m_theApp(appName),
   m_description(desc),
   m_optval_n(0),
   m_optval_s(0),
   m_optval_b(10),
   m_digiChain(0),
   m_reconChain(0),
   m_svacChain(0),
   m_meritChain(0)
{

}

JobConfig::~JobConfig() 
{
  delete m_digiChain;
  delete m_reconChain;
  delete m_svacChain; 
  delete m_meritChain;
}

void JobConfig::usage() {

  using std::cout;
  using std::cerr;
  using std::endl;
  
  cout << endl
       << m_theApp << endl
       << m_description << endl
       << endl;
  
  cout << "Usage:" << endl
       << "\t" << m_theApp << " -c <configFile>" << endl 
       << endl
       << "\t   <configFile>      : name of xml file with job configuration" << endl
       << endl
       << "\t" << m_theApp << " [options] [input] -o <output>" << endl 
       << endl
       << "\tINPUT" << endl
       << "\t   -r <reconFiles>   : comma seperated list of recon ROOT files" << endl
       << "\t   -d <digiFiles>    : comma seperated list of digi ROOT files" << endl
       << "\t   -S <svacFiles>    : comma seperated list of svac ROOT files" << endl
       << "\t   -m <meritFiles>   : comma seperated list of merit ROOT files" << endl 
       << "\tNOTE:  Different calibrations jobs take diffenent types of input files" << endl
       << endl
       << "\t   -o <output>       : prefix (path or filename) to add to output files" << endl
       << endl
       << "\tOPTIONS for all jobs" << endl
       << "\t   -h                : print this message" << endl
       << "\t   -n <nEvents>      : run over <nEvents>" << endl
       << "\t   -s <startEvent>   : start with event <startEvent>" << endl
       << endl
       << "\tOPTIONS for specific jobs (will be ignored by other jobs)"  << endl
       << "\t   -b <binSize>         : size of time bins in seconds [10]" << endl   
       << endl;
}
  
Int_t JobConfig::parse(int argn, char** argc) {

  using std::cout;
  using std::cerr;
  using std::endl;
  using std::string;

  // grab path from env
  m_path = ::getenv("TESTREPORTROOT");
  m_jobOptionXmlFile = m_path + string("/src/jobOptions.xml");
  
  // parse options
  char* endPtr;  
  int opt;
  while ( (opt = getopt(argn, argc, "ho:d:r:S:m:c:n:s:b:")) != EOF ) {
    switch (opt) {
    case 'h':   // help      
      usage();
      return 1;
    case 'o':   //  output
      m_outputPrefix = string(optarg);
      break;
    case 'd':   // digi files
      m_inputDigiFileStr += string(optarg);
      m_inputDigiFileStr += ',';
      break;
    case 'r':   // recon files
      m_inputReconFileStr += string(optarg);
      m_inputReconFileStr += ',';
      break;
    case 'S':   // Svac files
      m_inputSvacFileStr += string(optarg);
      m_inputSvacFileStr += ',';
      break;
    case 'm':   // Merit files
      m_inputMeritFileStr += string(optarg);
      m_inputMeritFileStr += ',';
      break;
    case 'c':   // config file
      m_jobOptionXmlFile = string(optarg);
      break;
    case 'b':   // size of bins
      m_optval_b = strtoul( optarg, &endPtr, 0 );
      break;
    case 'n':   // number of events
      m_optval_n = strtoul( optarg, &endPtr, 0 );
      break;
    case 's':   // start event
      m_optval_s = strtoul( optarg, &endPtr, 0 );
      break;
    case '?':
      usage();
      return 2;
    default:
      cerr << opt << " not parsable..." << endl;
      cerr << "Try " << m_theApp << " -h" << endl;
      return 2;
    }
  }

  if ( argn - optind > 0 ) {
    cerr << m_theApp << " only takes options, not bare arguments" << endl
	 << "Try " << m_theApp << " -h" << endl;
    return 3;
  }

  // parse xml config file
  using xmlBase::IFile;
  IFile myFile(m_jobOptionXmlFile.c_str()); 

  // output file prefix
  if (myFile.contains("parameters","outputPrefix") && m_outputPrefix == "" ) {
    m_outputPrefix = myFile.getString("parameters", "outputPrefix");
  }
    
  // timestamp
  std::time_t theTime = std::time(0);
  const char* timeString = std::ctime(&theTime);

  m_timeStamp = string(timeString);
  m_timeStamp.erase(m_timeStamp.size()-1);

  // digi files
  if (myFile.contains("parameters","digiFileList")) {
    m_inputDigiFileStr += myFile.getString("parameters", "digiFileList");
  }
  
  if ( m_inputDigiFileStr != "" ) {
    cout << "Input digi files:" << endl;
    m_digiChain = makeChain("Digi",m_inputDigiFileStr);
  }    


  // recon files
  if (myFile.contains("parameters","reconFileList")) {
    m_inputReconFileStr += myFile.getString("parameters", "reconFileList");
  }
  
  if ( m_inputReconFileStr != "" ) {
    cout << "Input recon files:" << endl;
    m_reconChain = makeChain("Recon",m_inputReconFileStr);
  }    


  // svac files
  if (myFile.contains("parameters","svacFileList")) {
    m_inputSvacFileStr += myFile.getString("parameters", "svacFileList");
  }
  
  if ( m_inputSvacFileStr != "" ) {
    cout << "Input svac files:" << endl;
    m_svacChain = makeChain("Output",m_inputSvacFileStr);
  }    

  // merit files
  if (myFile.contains("parameters","meritFileList")) {
    m_inputMeritFileStr += myFile.getString("parameters", "meritFileList");
  }
  
  if ( m_inputMeritFileStr != "" ) {
    cout << "Input merit files:" << endl;
    m_meritChain = makeChain("MeritTuple",m_inputMeritFileStr);
  }    

  std::cout << "output file prefix: " << m_outputPrefix << std::endl;
  std::cout << "timestamp: " << m_timeStamp << std::endl;

  return 0;
}


TChain* JobConfig::makeChain(const char* name, const std::string& fileString) const {

  TChain* chain(0);
  std::vector <std::string> token;
  facilities::Util::stringTokenize(fileString, ";, ", token);
  unsigned int nFiles = token.size();
  
  for ( unsigned int iFile(0); iFile < nFiles; iFile++ ) {
    if (token[iFile]=="") continue;
    if ( chain == 0 ) chain = new TChain(name);
    chain->Add(token[iFile].c_str());
    std::cout << "   " << iFile+1 << ") " << token[iFile] << std::endl;
  }
  return chain;
  
}


Bool_t JobConfig::checkDigi() const {
  if ( m_digiChain == 0 ) {
    std::cerr << "This job requires digi ROOT files as input." << std::endl
	      << "\tuse -d <file> option to specify them." << std::endl
	      << std::endl;
    return kFALSE;
  }
  return kTRUE;
}

Bool_t JobConfig::checkRecon() const {
  if ( m_reconChain == 0 ) {
    std::cerr << "This job requires recon ROOT files as input." << std::endl
	      << "\tuse -r <file> option to specify them." << std::endl
	      << std::endl;
    return kFALSE;
  }
  return kTRUE;
}

Bool_t JobConfig::checkSvac() const {
  if ( m_svacChain == 0 ) {
    std::cerr << "This job requires svac ROOT files as input." << std::endl
	      << "\tuse -S <file> option to specify them." << std::endl
	      << std::endl;
    return kFALSE;
  }
  return kTRUE;
}

Bool_t JobConfig::checkMerit() const {
  if ( m_meritChain == 0 ) {
    std::cerr << "This job requires merit ROOT files as input." << std::endl
	      << "\tuse -m <file> option to specify them." << std::endl
	      << std::endl;
    return kFALSE;
  }
  return kTRUE;
}
