/****************************************************************************
*
* This is a part of TOTEM offline software.
* Authors: 
*   Maciej Wróbel (wroblisko@gmail.com)
*   Jan Kašpar (jan.kaspar@cern.ch)
*
****************************************************************************/

#include "FWCore/Utilities/interface/typelookup.h"

#include "CondFormats/CTPPSObjects/interface/CTPPSAnalysisMask.h"

//----------------------------------------------------------------------------------------------------

void CTPPSAnalysisMask::insert(const CTPPSSymbID &sid, const CTPPSVFATAnalysisMask &vam)
{
  analysisMask[sid] = vam;
}

//----------------------------------------------------------------------------------------------------