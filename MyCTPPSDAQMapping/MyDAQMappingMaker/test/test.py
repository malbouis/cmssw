import FWCore.ParameterSet.Config as cms
 
process = cms.Process("ProcessOne")

process.load("CondCore.CondDB.CondDB_cfi")

#input database (in this case local sqlite file)
process.CondDB.connect = 'sqlite_file:MyDAQMapping.db'
process.CondDB.messageLevel = cms.untracked.int32(3) #3 for high verbosity

process.ReferenceRetrieval = cms.ESSource("PoolDBESSource",
                                          process.CondDB,
                                          toGet = cms.VPSet(cms.PSet(record = cms.string('CTPPSDAQMappingRcd'),
                                                                     tag = cms.string('myDAQMapping_test')
                                                                    )
                                                           )
                                         )

