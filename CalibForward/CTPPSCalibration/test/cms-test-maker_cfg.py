import FWCore.ParameterSet.Config as cms

process = cms.Process("ProcessOne")

process.source = cms.Source("EmptyIOVSource",
    timetype = cms.string('runnumber'),
    firstValue = cms.uint64(1),
    lastValue = cms.uint64(1),
    interval = cms.uint64(1)
)


#Database output service

process.load("CondCore.CondDB.CondDB_cfi")
# output database (in this case local sqlite file)
process.CondDB.connect = 'sqlite_file:CTPPSDAQMapping.db'


process.PoolDBOutputService = cms.Service("PoolDBOutputService",
    process.CondDB,
    timetype = cms.untracked.string('runnumber'),
    toPut = cms.VPSet(cms.PSet(
        record = cms.string('CTPPSDAQMappingRcd'),
        tag = cms.string('myDAQMapping_test')
    ))
)

process.WriteInDB = cms.EDAnalyzer("CTPPSCalibration",
                                   record= cms.string('CTPPSDAQMappingRcd'))

process.p = cms.Path(process.WriteInDB)
