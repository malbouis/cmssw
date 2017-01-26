import FWCore.ParameterSet.Config as cms

process = cms.Process('test')

#raw data source
#process.source = cms.Source("EmptySource",
#)

#process.maxEvents = cms.untracked.PSet(
#    input = cms.untracked.int32(1)
#)

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
      validityRange = cms.EventRange("1:min - 999999999:max"),
      mappingFileNames = cms.vstring("CondFormats/CTPPSObjects/xml/mapping_tracking_strip_to_fill_5288.xml"),
      maskFileNames = cms.vstring()
    )
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


# print the mapping
process.printTotemDAQMapping = cms.EDAnalyzer("PrintTotemDAQMapping"
)

process.path = cms.Path(
  process.printTotemDAQMapping
)
