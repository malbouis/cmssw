import FWCore.ParameterSet.Config as cms

process = cms.Process("GeometryWriter")

process.load('CondCore.CondDB.CondDB_cfi')

# This will read all the little XML files and from
# that fill the DDCompactView. The modules that fill
# the reco part of the database need the DDCompactView.
process.load('Configuration.Geometry.GeometryExtended2018_CTPPS_cff')

process.source = cms.Source("EmptyIOVSource",
                            lastValue = cms.uint64(1),
                            timetype = cms.string('runnumber'),
                            firstValue = cms.uint64(1),
                            interval = cms.uint64(1)
                            )

# This reads the big XML file and the only way to fill the
# nonreco part of the database is to read this file.  It
# somewhat duplicates the information read from the little
# XML files, but there is no way to directly build the
# DDCompactView from this.
process.XMLGeometryWriter = cms.EDAnalyzer("XMLGeometryBuilder",
                                           XMLFileName = cms.untracked.string('./geometryEntended2018_PPS_SingleBigFile.xml'),
                                           ZIP = cms.untracked.bool(True)
                                           )

process.CondDB.timetype = cms.untracked.string('runnumber')
process.CondDB.connect = cms.string('sqlite_file:cmsGeometryExtended2018_PPS.db')
process.PoolDBOutputService = cms.Service("PoolDBOutputService",
                                          process.CondDB,
                                          toPut = cms.VPSet(cms.PSet(record = cms.string('GeometryFileRcd'),tag = cms.string('XMLFILE_Geometry_TagV1_Extended2018_PPS_mc'))
                                                            )
                                          )

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1)
    )

process.p1 = cms.Path(process.XMLGeometryWriter)
