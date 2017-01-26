// -*- C++ -*-
//
// Package:    CalibForward/CTPPSCalibration
// Class:      CTPPSCalibration
//
/**\class CTPPSCalibration CTPPSCalibration.cc CalibForward/CTPPSCalibration/plugins/CTPPSCalibration.cc
 Description: [one line class summary]
 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Helena Brandao Malbouisson
//         Created:  Fri, 15 Jul 2016 13:43:03 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CondCore/DBOutputService/interface/PoolDBOutputService.h"

#include "CondFormats/CTPPSObjects/interface/CTPPSDAQMapping.h"

//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<> and also remove the line from
// constructor "usesResource("TFileService");"
// This will improve performance in multithreaded jobs.

class CTPPSCalibration : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit CTPPSCalibration(const edm::ParameterSet&);
      ~CTPPSCalibration();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;
      std::string m_record;

      // ----------member data ---------------------------
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
CTPPSCalibration::CTPPSCalibration(const edm::ParameterSet& iConfig):
  m_record(iConfig.getParameter<std::string>("record"))

{
   //now do what ever initialization is needed
   usesResource("TFileService");

}


CTPPSCalibration::~CTPPSCalibration()
{

   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
CTPPSCalibration::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;

   CTPPSDAQMapping* pCTPPSDAQMapping = new CTPPSDAQMapping();

   // Form the data here
   edm::Service<cond::service::PoolDBOutputService> poolDbService;
   if( poolDbService.isAvailable() )
      poolDbService->writeOne( pCTPPSDAQMapping, poolDbService->currentTime(),
                                                m_record  );


/*#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
*/
}


// ------------ method called once each job just before starting event loop  ------------
void
CTPPSCalibration::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void
CTPPSCalibration::endJob()
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
CTPPSCalibration::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(CTPPSCalibration);
