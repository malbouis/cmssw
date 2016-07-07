/****************************************************************************
*
* This is a part of TOTEM offline software.
* Authors: 
*   Maciej Wróbel (wroblisko@gmail.com)
*
****************************************************************************/

#include "CondFormats/CTPPSObjects/interface/CTPPSDAQMapping.h"

using namespace std;

//----------------------------------------------------------------------------------------------------

std::ostream& operator << (std::ostream& s, const CTPPSVFATInfo &vi)
{
  if (vi.type == CTPPSVFATInfo::data)
    s << "type=data, ";
  else
    s << "type=  CC, ";

  s << vi.symbolicID << ", hw id=0x" << hex << vi.hwID << dec;

  return s;
}

//----------------------------------------------------------------------------------------------------

void CTPPSDAQMapping::insert(const CTPPSFramePosition &fp, const CTPPSVFATInfo &vi)
{
  auto it = VFATMapping.find(fp);  
  if (it != VFATMapping.end())
  {
    cerr << "WARNING in DAQMapping::Insert > Overwriting entry at " << fp << ". Previous: " << endl 
      << "    " << VFATMapping[fp] << "," << endl << "  new: " << endl << "    " << vi << ". " << endl;
  }

  VFATMapping[fp] = vi;

}

//----------------------------------------------------------------------------------------------------

