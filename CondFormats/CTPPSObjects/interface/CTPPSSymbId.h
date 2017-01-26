/****************************************************************************
*
* This is a part of TOTEM offline software.
* Authors: 
*   Jan Kašpar (jan.kaspar@cern.ch)
*
****************************************************************************/

#ifndef CondFormats_CTPPSObjects_CTPPSSymbID
#define CondFormats_CTPPSObjects_CTPPSSymbID

#include <iostream>
#include "CondFormats/Serialization/interface/Serializable.h"

/**
 *\brief Symbolic ID describing an entity of a TOTEM subdetector.
 **/
class CTPPSSymbID
{
  public:
    /// chip ID, raw integer representation of DetId class
    unsigned int symbolicID;

    bool operator < (const CTPPSSymbID &sid) const
    {
	  return (symbolicID < sid.symbolicID);
    }

    bool operator == (const CTPPSSymbID &sid) const
    {
      return (symbolicID == sid.symbolicID);
    }
    
    friend std::ostream& operator << (std::ostream& s, const CTPPSSymbID &sid);

    COND_SERIALIZABLE;
};

#endif
