#include <string>
#include <iostream>
#include <map>
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "CondFormats/CTPPSObjects/interface/CTPPSDAQMapping.h"
#include "CondFormats/DataRecord/interface/CTPPSDAQMappingRcd.h"
#include "CondFormats/CTPPSObjects/interface/CTPPSAnalysisMask.h"


namespace edmtest
{
  class myCTPPSDAQMappingAnalyzer : public edm::EDAnalyzer
  {
  public:
    explicit  myCTPPSDAQMappingAnalyzer(edm::ParameterSet const& p) { 
      std::cout<<"myCTPPSDAQMappingAnalyzer"<<std::endl;
          }
    explicit  myCTPPSDAQMappingAnalyzer(int i) {
      std::cout<<"myCTPPSRPPosESAnalyzer "<<i<<std::endl; 
    }
    virtual ~myCTPPSDAQMappingAnalyzer() {  
      std::cout<<"~myCTPPSDAQMappingAnalyzer "<<std::endl;
    }
        virtual void analyze(const edm::Event& e, const edm::EventSetup& c) override;
  };
  
  void
  myCTPPSDAQMappingAnalyzer::analyze(const edm::Event& e, const edm::EventSetup& context){
    
    std::cout<<"###myCTPPSDAQMappingAnalyzer::analyze"<<std::endl;
    std::cout <<" I AM IN RUN NUMBER "<<e.id().run() <<std::endl;
    std::cout <<" ---EVENT NUMBER "<<e.id().event() <<std::endl;

    edm::eventsetup::EventSetupRecordKey recordKey(edm::eventsetup::EventSetupRecordKey::TypeTag::findType("CTPPSDAQMappingRcd"));
    if( recordKey.type() == edm::eventsetup::EventSetupRecordKey::TypeTag()) {
      //record not found
      std::cout <<"Record \"CTPPSDAQMappingRcd"<<"\" does not exist "<<std::endl;
    }

    //this part gets the handle of the event source and the record (i.e. the Database)
    edm::ESHandle<CTPPSDAQMapping> mapping;
    std::cout<<"got eshandle"<<std::endl;

    context.get<CTPPSDAQMappingRcd>().get(mapping);
    std::cout<<"got context"<<std::endl;

    // print mapping
    printf("* DAQ mapping\n");
    for (const auto &p : mapping->VFATMapping)
    std::cout << "    " << p.first << " -> " << p.second << std::endl;

   
  }
  DEFINE_FWK_MODULE(myCTPPSDAQMappingAnalyzer);
}
