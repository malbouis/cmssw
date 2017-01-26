import FWCore.ParameterSet.Config as cms

process = cms.Process('test')

process.source = cms.Source("EmptyIOVSource",
    timetype = cms.string('runnumber'),
    firstValue = cms.uint64(1),
    lastValue = cms.uint64(1),
    interval = cms.uint64(1)
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1)
)

# load a mapping
process.load("CondFormats.CTPPSObjects.TotemDAQMappingESSourceXML_cfi")
process.totemDAQMappingESSourceXML.subSystem = cms.untracked.string("")
process.totemDAQMappingESSourceXML.configuration = cms.VPSet(
    cms.PSet(
      validityRange = cms.EventRange("281601:min - 999999999:max"),
      mappingFileNames = cms.vstring("CondFormats/CTPPSObjects/xml/mapping_tracking_strip_from_fill_5330.xml"),
      maskFileNames = cms.vstring()
    )
)

#Database output service

process.load("CondCore.CondDB.CondDB_cfi")
# output database (in this case local sqlite file)
process.CondDB.connect = 'sqlite_file:CTPPSDAQMapping_fill_5330.db'


process.PoolDBOutputService = cms.Service("PoolDBOutputService",
    process.CondDB,
    timetype = cms.untracked.string('runnumber'),
    toPut = cms.VPSet(cms.PSet(
        record = cms.string('CTPPSDAQMappingRcd'),
        tag = cms.string('DAQMapping_fill_5330')
    ))
)


# print the mapping
process.writeCTPPSDAQMapping = cms.EDAnalyzer("WriteCTPPSDAQMapping"
)

process.path = cms.Path(
  process.writeCTPPSDAQMapping
)
