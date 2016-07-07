/****************************************************************************
*
* This is a part of TOTEM offline software.
* Authors: 
*   Jan Kašpar (jan.kaspar@cern.ch)
*
****************************************************************************/

#ifndef CondFormats_CTPPSObjects_CTPPSSymbId_H
#define CondFormats_CTPPSObjects_CTPPSSymbId_H

#include "CondFormats/Serialization/interface/Serializable.h"

#include <iostream>

/**
 *\brief Symbolic ID describing an entity of a CTPPS subdetector.
 **/
class CTPPSSymbID
{
  public:

    CTPPSSymbID() {}
    ~CTPPSSymbID() {}

    /// identifies the CTPPS subsystem
    enum {RP, T1, T2} subSystem;

    /// integer-encoded symbolic ID
    unsigned int symbolicID;

    bool operator < (const CTPPSSymbID &sid) const
    {
      if (subSystem == sid.subSystem)
		  return (symbolicID < sid.symbolicID);
      return (subSystem < sid.subSystem);
    }

    bool operator == (const CTPPSSymbID &sid) const
    {
      return ((subSystem==sid.subSystem) && (symbolicID==sid.symbolicID));
    }
    
    friend std::ostream& operator << (std::ostream& s, const CTPPSSymbID &sid);

    // dummy vector for testing
    std::vector<int> dummyvector;

    COND_SERIALIZABLE;

};

#endif
