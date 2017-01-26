/****************************************************************************
*
* This is a part of TOTEM offline software.
* Authors: 
*  Jan Kašpar (jan.kaspar@gmail.com) 
*
****************************************************************************/

#include "FWCore/Framework/interface/one/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/ESHandle.h"

// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CondCore/DBOutputService/interface/PoolDBOutputService.h"

#include "CondFormats/DataRecord/interface/CTPPSDAQMappingRcd.h"
#include "CondFormats/CTPPSObjects/interface/CTPPSDAQMapping.h"
#include "CondFormats/CTPPSObjects/interface/CTPPSAnalysisMask.h"

//----------------------------------------------------------------------------------------------------

/**
 *\brief Prints the DAQ mapping loaded by TotemDAQMappingESSourceXML.
 **/
class PrintTotemDAQMapping : public edm::one::EDAnalyzer<>
{
  public:
    PrintTotemDAQMapping(const edm::ParameterSet &ps) {}
    ~PrintTotemDAQMapping() {}

  private:
    virtual void analyze(const edm::Event &e, const edm::EventSetup &es) override;
};

using namespace std;
using namespace edm;

//----------------------------------------------------------------------------------------------------

void PrintTotemDAQMapping::analyze(const edm::Event&, edm::EventSetup const& es)
{
  // get mapping
  ESHandle<CTPPSDAQMapping> mapping;
  es.get<CTPPSDAQMappingRcd>().get(mapping);

  // get analysis mask to mask channels
  ESHandle<CTPPSAnalysisMask> analysisMask;
  es.get<CTPPSDAQMappingRcd>().get(analysisMask);

  // print mapping
  printf("* DAQ mapping\n");
  for (const auto &p : mapping->VFATMapping)
    cout << "    " << p.first << " -> " << p.second << endl;

  // print mapping
  printf("* mask\n");
  for (const auto &p : analysisMask->analysisMask)
    cout << "    " << p.first
      << ": fullMask=" << p.second.fullMask
      << ", number of masked channels " << p.second.maskedChannels.size() << endl;

  const CTPPSDAQMapping* pCTPPSDAQMapping = mapping.product();
  edm::Service<cond::service::PoolDBOutputService> poolDbService;
  if( poolDbService.isAvailable() )
    poolDbService->writeOne( pCTPPSDAQMapping, poolDbService->currentTime(), /*m_record*/ "CTPPSDAQMappingRcd"  );
        
}

//----------------------------------------------------------------------------------------------------

DEFINE_FWK_MODULE(PrintTotemDAQMapping);
