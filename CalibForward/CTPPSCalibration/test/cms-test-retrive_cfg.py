import FWCore.ParameterSet.Config as cms

process = cms.Process("ProcessOne")

process.load("CondCore.CondDB.CondDB_cfi")

#input database (in this case local sqlite file)
process.CondDB.connect = 'sqlite_file:CTPPSDAQMapping.db'
process.CondDB.messageLevel = cms.untracked.int32(3)

process.PoolDBESSource = cms.ESSource("PoolDBESSource",
    process.CondDB,
    DumpStat=cms.untracked.bool(True),
    toGet = cms.VPSet(cms.PSet(
        record = cms.string('CTPPSDAQMappingRcd'),
        tag = cms.string('myDAQMapping_test')
    )),
)

process.source = cms.Source("EmptySource",
    
)
process.maxEvents = cms.untracked.PSet(
     input = cms.untracked.int32(1)
)

process.get = cms.EDAnalyzer("EventSetupRecordDataGetter",
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
 
process.p = cms.Path(process.get)
