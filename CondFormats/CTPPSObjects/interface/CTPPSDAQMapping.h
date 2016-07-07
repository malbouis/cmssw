/****************************************************************************
*
* This is a part of TOTEM offline software.
* Authors: 
*   Maciej Wróbel (wroblisko@gmail.com)
*   Jan Kašpar (jan.kaspar@cern.ch)
*
****************************************************************************/

#ifndef CondFormats_CTPPSObjects_CTPPSDAQMapping_H
#define CondFormats_CTPPSObjects_CTPPSDAQMapping_H

#include "CondFormats/Serialization/interface/Serializable.h"
#include "CondFormats/CTPPSObjects/interface/CTPPSFramePosition.h"
#include "CondFormats/CTPPSObjects/interface/CTPPSSymbId.h"

#include <boost/cstdint.hpp>
#include <map>

//----------------------------------------------------------------------------------------------------

/**
 *\brief Contains mappind data related to a VFAT.
 */
class CTPPSVFATInfo
{
  public:
   
    CTPPSVFATInfo() {}

    ~CTPPSVFATInfo() {}
    
    /// is data of coincidence-chip VFAT
    enum {data, CC} type;

    /// the symbolic id
    CTPPSSymbID symbolicID;

    /// the hardware ID (16 bit)
    unsigned int hwID;
    
    friend std::ostream& operator << (std::ostream& s, const CTPPSVFATInfo &fp);

    //COND_SERIALIZABLE;

};

//----------------------------------------------------------------------------------------------------

/**
 *\brief The mapping between FramePosition and VFATInfo.
 */
class CTPPSDAQMapping
{
  public:
    
    CTPPSDAQMapping() {}
    ~CTPPSDAQMapping() {}
    
    std::map<CTPPSFramePosition, CTPPSVFATInfo> VFATMapping;
    
    void insert(const CTPPSFramePosition &fp, const CTPPSVFATInfo &vi);

    COND_SERIALIZABLE;
};

#endif
