import FWCore.ParameterSet.Config as cms
process = cms.Process("GeometryInfo")

# minimum of logs
process.MessageLogger = cms.Service("MessageLogger",
    statistics = cms.untracked.vstring(),
    destinations = cms.untracked.vstring('cout'),
    cout = cms.untracked.PSet(
        threshold = cms.untracked.string('INFO')
    )
)

# load alignment correction
#process.load("Geometry.VeryForwardGeometryBuilder.ctppsIncludeAlignmentsFromXML_cfi")
#process.ctppsIncludeAlignmentsFromXML.RealFiles = cms.vstring("Geometry/VeryForwardGeometryBuilder/test/sample_alignment_corrections.xml")

# no events to process
process.source = cms.Source("EmptyIOVSource",
    timetype = cms.string('runnumber'),
    firstValue = cms.uint64(1),
    lastValue = cms.uint64(1),
    interval = cms.uint64(1)
)
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1)
)

#Database output service
process.load("CondCore.CondDB.CondDB_cfi")
# input database (in this case local sqlite file)
process.CondDB.connect = 'sqlite_file:CTPPSRPAlignment.db'

process.PoolDBESSource = cms.ESSource("PoolDBESSource",
    process.CondDB,
    DumpStat=cms.untracked.bool(True),
    toGet = cms.VPSet(
      cms.PSet(
        record = cms.string('RPMisalignedAlignmentRecord'),
        tag = cms.string("CTPPSRPAlignment_misaligned")
      )
    )
)


process.ctppsAlignmentInfo = cms.EDAnalyzer("CTPPSAlignmentInfo",
    alignmentType = cms.untracked.string("misaligned"),
)

process.p = cms.Path(
    process.ctppsAlignmentInfo
)
