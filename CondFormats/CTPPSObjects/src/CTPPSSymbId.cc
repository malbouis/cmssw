/****************************************************************************
*
* This is a part of TOTEM offline software.
* Authors: 
*   Jan Kašpar (jan.kaspar@cern.ch)
*
****************************************************************************/

#include "CondFormats/CTPPSObjects/interface/CTPPSSymbId.h"

std::ostream& operator << (std::ostream& s, const CTPPSSymbID &sid)
{
  switch (sid.subSystem) {
    case CTPPSSymbID::RP:
      s << "sub-system=RP, ";
      break;
    case CTPPSSymbID::T1:
      s << "sub-system=T1, ";
      break;
    case CTPPSSymbID::T2:
      s << "sub-system=T2, ";
      break;
  }

  s << "symb. id=" << sid.symbolicID;

  return s;
}

