import FWCore.ParameterSet.Config as cms
from Configuration.AlCa.autoCond import autoCond

process = cms.Process("GeometryFileDump")
process.load('CondCore.CondDB.CondDB_cfi')
process.load('Configuration.StandardSequences.GeometryDB_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = autoCond['run2_mc']
process.GlobalTag.toGet = cms.VPSet(
    cms.PSet(record = cms.string("GeometryFileRcd"),
             tag = cms.string("XMLFILE_Geometry_111YV1_Extended2018CTPPS_mc"),
             #connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS"),
             connect = cms.string("sqlite_file:PPS_geometry_DB.db"),
             #label = cms.string("Extended2017CTPPS")
             )
    )

process.source = cms.Source("EmptyIOVSource",
                            lastValue = cms.uint64(1),
                            timetype = cms.string('runnumber'),
                            firstValue = cms.uint64(1),
                            interval = cms.uint64(1)
                            )

process.GeometryFileDump = cms.EDAnalyzer("XMLGeometryReader",
                                          XMLFileName = cms.untracked.string("XMLFILE_Geometry_111YV1_2018CTPPS_mc.xml"),
                                          geomLabel = cms.untracked.string("")
                                          )

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1)
    )

process.p1 = cms.Path(process.GeometryFileDump)

