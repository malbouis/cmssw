#include "CondFormats/CTPPSObjects/src/headers.h"

namespace CondFormats_CTPPSObjects {
   struct dictionary {
   std::map<CTPPSFramePosition,CTPPSVFATInfo> VFATMapping; 
   std::map<CTPPSSymbID, CTPPSVFATAnalysisMask> analysisMask;
 };
}     
