import FWCore.ParameterSet.Config as cms

src1 = cms.ESSource("PoolDBESSource",
    loadAll = cms.bool(True),
    toGet = cms.VPSet(cms.PSet(
        record = cms.string('CTPPSDAQMappingRcd'),
        tag = cms.string('myDAQMapping_test')
    ), 
        cms.PSet(
            record = cms.string('CTPPSDAQMappingRcd'),
            tag = cms.string('myDAQMapping_test')
        )),
    messagelevel = cms.untracked.uint32(1),
    #catalog = cms.untracked.string('file:/afs/cern.ch/cms/ECAL/testbeam/pedestal/2004/v2/PoolFileCatalog.xml'),
    timetype = cms.string('runnumber'),
    connect = cms.string('sqlite_file:MyDAQMapping.db'),
    authenticationMethod = cms.untracked.uint32(0)
)

getCalibrations = cms.EDAnalyzer("EventSetupRecordDataGetter",
    toGet = cms.VPSet(cms.PSet(
        record = cms.string('CTPPSDAQMappingRcd'),
        data = cms.vstring('CTPPSDAQMapping')
    ), 
        cms.PSet(
            record = cms.string('CTPPSDAQMappingRcd'),
            data = cms.vstring('CTPPSDAQMapping')
        )),
    verbose = cms.untracked.bool(True)
)
 
