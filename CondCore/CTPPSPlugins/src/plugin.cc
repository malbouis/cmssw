#include "CondCore/ESSources/interface/registration_macros.h"
#include "CondFormats/CTPPSObjects/interface/CTPPSDAQMapping.h"
#include "CondFormats/DataRecord/interface/CTPPSDAQMappingRcd.h"
#include "CondFormats/CTPPSObjects/interface/CTPPSAnalysisMask.h"
#include "CondFormats/DataRecord/interface/CTPPSAnalysisMaskRcd.h"

 
REGISTER_PLUGIN(CTPPSDAQMappingRcd,CTPPSDAQMapping);
REGISTER_PLUGIN(CTPPSAnalysisMaskRcd,CTPPSAnalysisMask);
