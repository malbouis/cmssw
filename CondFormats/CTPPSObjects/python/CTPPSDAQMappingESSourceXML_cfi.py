import FWCore.ParameterSet.Config as cms

CTPPSDAQMappingESSourceXML = cms.ESSource("CTPPSDAQMappingESSourceXML",
  verbosity = cms.untracked.uint32(1),

  mappingFileNames = cms.untracked.vstring("/afs/cern.ch/work/m/malbouis/CT-PPS/DB/CMSSW_8_1_0_pre7/src/CondFormats/CTPPSObjects/xml/ctpps_210_mapping.xml"),
  maskFileNames = cms.untracked.vstring("/afs/cern.ch/work/m/malbouis/CT-PPS/DB/CMSSW_8_1_0_pre7/src/CondFormats/CTPPSObjects/xml/totem_rp_mask_example.xml")
)
