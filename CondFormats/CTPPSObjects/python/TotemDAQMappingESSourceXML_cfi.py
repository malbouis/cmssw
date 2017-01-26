import FWCore.ParameterSet.Config as cms

totemDAQMappingESSourceXML = cms.ESSource("TotemDAQMappingESSourceXML",
  verbosity = cms.untracked.uint32(0),
  
  #configuration = cms.VPSet(
    # example configuration block:
    #cms.PSet(
      #validityRange = cms.EventRange("1:min - 999999999:max"),
      #mappingFileNames = cms.vstring("CondFormats/CTPPSReadoutObjects/xml/mapping_tracking_strip_from_fill_5330"),
      #maskFileNames = cms.vstring("CondFormats/CTPPSReadoutObjects/xml/totem_rp_mask_example.xml")
    
    #)
  #)
)
