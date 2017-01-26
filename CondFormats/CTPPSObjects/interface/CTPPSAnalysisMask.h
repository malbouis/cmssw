/****************************************************************************
*
* This is a part of TOTEM offline software.
* Authors: 
*   Maciej Wróbel (wroblisko@gmail.com)
*   Jan Kašpar (jan.kaspar@cern.ch)
*
****************************************************************************/

#ifndef CondFormats_CTPPSObjects_CTPPSAnalysisMask
#define CondFormats_CTPPSObjects_CTPPSAnalysisMask

#include "CondFormats/CTPPSObjects/interface/CTPPSSymbId.h"

#include <set>
#include <map>

//----------------------------------------------------------------------------------------------------

/**
 *\brief Contains data on masked channels of a VFAT.
 */
class CTPPSVFATAnalysisMask
{
  public:
    CTPPSVFATAnalysisMask() : fullMask(false) {}

    /// whether all channels of the VFAT shall be masked
    bool fullMask;

    /// list of channels to be masked
    std::set<unsigned char> maskedChannels;

    COND_SERIALIZABLE;
};

//----------------------------------------------------------------------------------------------------

/**
 *\brief Channel-mask mapping.
 **/
class CTPPSAnalysisMask
{
  public:
    std::map<CTPPSSymbID, CTPPSVFATAnalysisMask> analysisMask;

    void insert(const CTPPSSymbID &sid, const CTPPSVFATAnalysisMask &vam);
  
    COND_SERIALIZABLE;
};

#endif
