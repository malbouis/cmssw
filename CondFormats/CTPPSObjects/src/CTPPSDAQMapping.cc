/****************************************************************************
*
* This is a part of CTPPS offline software.
* Authors: 
*   Maciej Wróbel (wroblisko@gmail.com)
*
****************************************************************************/

#include "FWCore/Utilities/interface/typelookup.h"

#include "CondFormats/CTPPSObjects/interface/CTPPSDAQMapping.h"

using namespace std;

//----------------------------------------------------------------------------------------------------

std::ostream& operator << (std::ostream& s, const CTPPSVFATInfo &vi)
{
  s << vi.symbolicID << ", hw id=0x" << hex << vi.hwID << dec;

  return s;
}

//----------------------------------------------------------------------------------------------------

void CTPPSDAQMapping::insert(const CTPPSFramePosition &fp, const CTPPSVFATInfo &vi)
{
  auto it = VFATMapping.find(fp);  
  if (it != VFATMapping.end())
  {
    cerr << "WARNING in DAQMapping::insert > Overwriting entry at " << fp << ". Previous: " << endl 
      << "    " << VFATMapping[fp] << "," << endl << "  new: " << endl << "    " << vi << ". " << endl;
  }

  VFATMapping[fp] = vi;
}

//----------------------------------------------------------------------------------------------------