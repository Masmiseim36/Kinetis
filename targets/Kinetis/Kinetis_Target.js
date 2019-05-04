/******************************************************************************
  Target Script for Freescale Kinetis

  Copyright (c) 2010-2014 Rowley Associates Limited.

  This file may be distributed under the terms of the License Agreement
  provided with this software.

  THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE
  WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 ******************************************************************************/

function Connect()
{
  TargetInterface.setMaximumJTAGFrequency(8000000);
  if (TargetInterface.implementation() != "j-link")
    TargetInterface.setDebugInterfaceProperty("max_ap_num", 3);
}

function EnableTrace(TraceInterfaceType)
{
  if (TraceInterfaceType == "ETB")
    {
      TargetInterface.pokeWord(0xE0080014, 0x00000030); // MCM_ETB_CNT_CTRL - disable TPIU
      var CSTF_Ctrl_Reg = ((0x908<<16)|0);
      v = TargetInterface.getICEBreakerRegister(CSTF_Ctrl_Reg);
      TargetInterface.setICEBreakerRegister(CSTF_Ctrl_Reg, v | 0x00000003); // EnS0 | EnS1  
    }
  else if (TraceInterfaceType == "TracePort")
    {
      TargetInterface.pokeWord(0xE0080014, 0x00000000); // MCM_ETB_CNT_CTRL - enable TPIU
      // When the TracePort is on PortA
      TargetInterface.pokeWord(0x40048038, TargetInterface.peekWord(0x40048038)|(1<<9));  
      TargetInterface.pokeWord(0x40048004, 0x00001000);   // TRACECLKSEL
      TargetInterface.pokeWord(0x40049018, 0x00000700);   // TraceClock, low drive strength
      TargetInterface.pokeWord(0x4004901C, 0x00000740);   // Trace data, High drive strength
      TargetInterface.pokeWord(0x40049020, 0x00000740);
      TargetInterface.pokeWord(0x40049024, 0x00000740);
      TargetInterface.pokeWord(0x40049028, 0x00000740);
    }
  else if (TraceInterfaceType == "SWO")
    TargetInterface.pokeWord(0xE0080014, 0x00000000); // MCM_ETB_CNT_CTRL - enable TPIU
}

function Reset()
{
  if (TargetInterface.implementation() == "crossworks_simulator")
    {
      TargetInterface.stop(1);
      return;
    }
  if (TargetInterface.implementation() == "j-link")
    {
      TargetInterface.resetAndStop(100);
      return;
    }
  if (TargetInterface.implementation() == "P&E")
    TargetInterface.stop();
  TargetInterface.setDebugRegister(0x01000004, 0x8); // set System Reset Request, 
  TargetInterface.delay(1);
  TargetInterface.setDebugRegister(0x01000004, 0x10); // clear System Reset Request and set Core Hold Reset
  TargetInterface.pokeWord(0xE000EDFC, 0x1); // Reset vector catch
  TargetInterface.setDebugRegister(0x01000004, 0x0); // clear Core Hold Reset
  TargetInterface.waitForDebugState(1000);
}

function SRAMReset()
{
  Reset();
}

function FLASHReset()
{
  Reset();
}

function CheckSystemSecurity()
{
  var status = TargetInterface.getDebugRegister(0x01000000);    
  if (status & (1<<2))
    {
      if (CWSys == undef || (CWSys.popup && CWSys.popup("System Security Enabled - MassErase to unlock?\nNote that the nSRST must be connected to the debug port\n")))
        MassEraseUnderNSRST();
      else
        TargetInterface.error("System Security Enabled\n");
    }  
  status = TargetInterface.getDebugRegister(0x01000000);  
  if ((status & (1<<3))==0)
    {
      TargetInterface.setDebugRegister(0x01000004, 0x10);
      TargetInterface.delay(1000);      
    }    
}

function GetPartName()
{
  CheckSystemSecurity();
  TargetInterface.pokeWord(0xE000EDFC, (1<<24));
  var PartName;
  var PartName2;
  var PartName3;
  var ForD;
  var SubPartName="";
  var CPUID = TargetInterface.peekWord(0xE000ED00);
  if (((CPUID>>4)&0xf)==0) // Cortex-M0
    {      
      var SIM_SDID = TargetInterface.peekWord(0x40048024);
      var SIM_FCFG2 = TargetInterface.peekWord(0x40048050);
      var Length;
      switch ((SIM_SDID>>20)&0xf)
        {
          case 0:
          case 1:
            if (((SIM_SDID>>24)&0xff) < 10)
              PartName = "MKL0"+((SIM_SDID>>24)&0xff).toString(16)+"Z";
            else if (((SIM_SDID>>28)&0xf) == 9)
              PartName = "MKL"+(((SIM_SDID>>24)&0xff)-0x10).toString(16)+"Z";
            else
              PartName = "MKL"+((SIM_SDID>>24)&0xff).toString(16)+"Z";
            Length = ((SIM_FCFG2>>24) & 0x3f)<<3;
            Length += ((SIM_FCFG2>>16) & 0x3f)<<3;
            break;
          case 2:
            if (((SIM_SDID>>24)&0xff) < 10)
              PartName = "MKE0"+((SIM_SDID>>24)&0xff).toString(16)+"Z";
            else
              PartName = "MKE"+((SIM_SDID>>24)&0xff).toString(16)+"Z";
            Length = ((SIM_FCFG2>>24) & 0x3f)<<3;
            break;
          case 5:
            if (((SIM_SDID>>24)&0xff) < 10)
              PartName = "MKW0"+((SIM_SDID>>24)&0xff).toString(16)+"Z";
            else
              PartName = "MKW"+((SIM_SDID>>24)&0xff).toString(16)+"Z";
            Length = ((SIM_FCFG2>>24) & 0x3f)<<3;
            Length += ((SIM_FCFG2>>16) & 0x3f)<<3;
            break;
          case 6:
            if (((SIM_SDID>>24)&0xff) < 10)
              PartName = "MKV0"+((SIM_SDID>>24)&0xff).toString(16)+"Z";
            else
              PartName = "MKV"+((SIM_SDID>>24)&0xff).toString(16)+"Z";
            Length = ((SIM_FCFG2>>24) & 0x3f)<<3;
            Length += ((SIM_FCFG2>>16) & 0x3f)<<3;
            break;
        }            
      PartName += Length.toString();
    }
  else
    {
      var SIM_SDID = TargetInterface.peekWord(0x40048024);
      if (((SIM_SDID)>>24) & 0xff)
        {
          switch ((SIM_SDID>>20) & 0xf)
            {
              case 0:
                PartName = "MK";
                break;
              case 1:
                PartName = "MKL";
                break;
              case 2:
                PartName = "MKE";
                break;
              case 5:
                PartName = "MKW";
                break;
              case 6:
                PartName = "MKV";
                break;
              case 7:
                PartName = "MKS";
                break;
            }
          PartName += ((SIM_SDID>>28)&0xf).toString(16);
          PartName += ((SIM_SDID>>24)&0xf).toString(16);
          if (TargetInterface.peekWord(0xE000EF40))
            ForD = "F";
          else
            ForD = "D";

          // check for "e7534: SUBFAMID reads back incorrect sub-family of the Kinetis device"
          var SIM_SOPT1 = TargetInterface.peekWord(0x4047000);
          var RamSize = (SIM_SOPT1 >> 12) &0xF;
          switch (PartName)
            {
              case "MK62":
                // There is no K62 in the Kinetis Family --> errata e7534 found
                PartName = "MK64";
                break;
              case "MK61":
                if (RamSize == 0xB)    // RAM-Size is 256 KByte.
                  {
                    // There is no K61 with 256 KByte in the Kinetis Family --> errata e7534 found
                    PartName = "MK63";
                  }
                break;
              case "MK22":
                if (RamSize == 0xB)    // RAM-Size is 256 KByte.
                  {
                    // There is no K22 with 256 KByte in the Kinetis Family --> errata e7534 found
                    PartName = "MK24";
                  }
                break;
            }
        }
      else
        {          
          switch ((SIM_SDID>>4) & 0x7)
            {
              case 0: // K10/K12
                PartName = "MK10";
                PartName2 = "MK12";
                break;
              case 1: // K20/K22
                PartName = "MK20";
                PartName2 = "MK22";
                break;
              case 2: // K30/K11/K61
                PartName = "MK30";
                PartName2 = "MK11";
                PartName3 = "MK61";
                break;
              case 3: // K40/K21
                PartName = "MK40";
                PartName2 = "MK21";
                break;
              case 4: // K60/K62
                PartName = "MK60";
                PartName2 = "MK62";
                break;
              case 5: // K70
                PartName = "MK70";
                break;
              case 6: // K50/K52
                PartName = "MK50";
                PartName2 = "MK52";
                PartName3 = "MKW24";
                break;
              case 7: // K51/K53
                PartName = "MK51";
                PartName2 = "MK53";
                break;
            }        
          if (((SIM_SDID>>7) & 0x7)==3)
            ForD = "F";
          else
            ForD = "D";
        }
      var SIM_FCFG2 = TargetInterface.peekWord(0x40048050);
      if (SIM_FCFG2 & (1<<23))
        {
          if (PartName.substring(0,3) != "MKV")
            SubPartName += "N";
          Length = ((SIM_FCFG2>>24) & 0x7f)<<3;
          Length += ((SIM_FCFG2>>16) & 0x7f)<<3;
          switch ((SIM_SDID>>7) & 0x7)
            {
              case 3:
              case 7:
                Length *= 2;
                break;
            }
          if (Length == 1024)
            SubPartName += "1M0";
          else if (Length == 2048)
            SubPartName += "2M0";
          else
            SubPartName += Length.toString();
        }
      else
        {
          if (PartName.substring(0,3) != "MKE")
            SubPartName += "X";
          Length = ((SIM_FCFG2>>24) & 0x7f)<<3;
          if (((SIM_SDID>>7) & 0x7)==3)
            Length *= 2;
          SubPartName += Length.toString();
        }
      PartName += ForD+SubPartName;
      if (PartName2)
        PartName += "/"+PartName2+ForD+SubPartName;
      if (PartName3)
        PartName += "/"+PartName3+ForD+SubPartName;
    }
  return PartName;
}

function MatchPartName(name)
{  
  var partName = GetPartName();
  if (partName.length >= 8)
    {
      if (partName.substring(0,4) == "MK10" && name.substring(0,4) == "MK12")
        return name.substring(4,4) == partName.substring(4,4);
      else if (partName.substring(0,4) == "MK20" && name.substring(0,4) == "MK22")
        return name.substring(4,4) == partName.substring(4,4);
      else if (partName.substring(0,4) == "MK30" && (name.substring(0,4) == "MK11" || name.substring(0,4) == "MK61"))
        return name.substring(4,4) == partName.substring(4,4);
      else if (partName.substring(0,4) == "MK40" && (name.substring(0,4) == "MK21") || (name.substring(0,4) == "MKW2"))
        return name.substring(4,4) == partName.substring(4,4);
      else if (partName.substring(0,4) == "MK60" && name.substring(0,4) == "MK22")
        return name.substring(4,4) == partName.substring(4,4);
      else if (partName.substring(0,4) == "MK50" && (name.substring(0,4) == "MK52") || (name.substring(0,4) == "MKW2"))
        return name.substring(4,4) == partName.substring(4,4);
      else if (partName.substring(0,4) == "MK51" && name.substring(0,4) == "MK53")
        return name.substring(4,4) == partName.substring(4,4);
      else
        return name.substring(0, 8) == partName.substring(0, 8);
    }
  else (partName.length >= 6)
    return name.substring(0, 6) == partName.substring(0, 6);
  return false;
}

// MKM devices have the SIM module at a different address
function GetPartName2()
{
  TargetInterface.setMaximumJTAGFrequency(2000000);
  CheckSystemSecurity();
  TargetInterface.pokeWord(0xE000EDFC, (1<<24));
  var PartName;
  var SIM_SDID = TargetInterface.peekWord(0x4003F024);
  var SIM_FCFG2 = TargetInterface.peekWord(0x4003F050);
  switch (SIM_SDID >> 20)
    {
      case 0x123:
      case 0x133:
      case 0x143:
      case 0x323:
      case 0x333:
      case 0x343:
        PartName = "MKM"+((SIM_SDID>>28)&0xf).toString()+((SIM_SDID>>24)&0xf).toString()+"Z"+(((SIM_FCFG2>>24) & 0x3f)<<3).toString();
        break;
    }
  return PartName;
}

function MatchPartName2(name)
{  
  var partName = GetPartName2();  
  return name.substring(0, 8) == partName.substring(0, 8);
}

// MKE devices have different id scheme
function GetPartName3()
{
  CheckSystemSecurity();
  TargetInterface.pokeWord(0xE000EDFC, (1<<24));
  var PartName;
  var SIM_SRSID = TargetInterface.peekWord(0x40048000);
  switch (SIM_SRSID >> 24)
    {
      case 2: // KE02
        PartName = "MKE02Z/SKEAZN64/MWPR15";
        break;
      case 4: // KE04
        PartName = "MKE04Z/SKEAZN8";
        break;
      case 6: // KE06
        PartName = "MKE06Z/SKEAZ128";
        break;
    }
  return PartName;
}

function MatchPartName3(name)
{  
  var SIM_SRSID = TargetInterface.peekWord(0x40048000);
  switch (SIM_SRSID >> 24)
    {
      case 2: // KE02
        return name == "MKE02Z" || name.substring(0,8) == "SKEAZN64" || name == "MWPR1516";
      case 4: // KE04
        return name == "MKE04Z" || name.substring(0,7) == "SKEAZN8";
      case 6: // KE06
        return name == "MKE06Z" || name.substring(0,8) == "SKEAZ128";
        break;
    }
  return 0;
}

// MKL28 devices have the SIM module at a different address
function GetPartName4()
{  
  CheckSystemSecurity();
  TargetInterface.pokeWord(0xE000EDFC, (1<<24));
  var PartName;
  var SIM_SDID = TargetInterface.peekWord(0x40075024);
  var SIM_FCFG2 = TargetInterface.peekWord(0x40075050);
  if (((SIM_SDID>>24)&0xff) < 10)
    PartName = "MKL0"+((SIM_SDID>>24)&0xff).toString(16)+"Z";
  else
    PartName = "MKL"+((SIM_SDID>>24)&0xff).toString(16)+"Z";
  Length = ((SIM_FCFG2>>24) & 0x3f)<<3;
  Length += ((SIM_FCFG2>>16) & 0x3f)<<3;
  PartName += Length.toString();  
  return PartName;
}

function MatchPartName4(name)
{  
  var partName = GetPartName4();  
  return name.substring(0, 8) == partName.substring(0, 8);
}

function MDMStatus()
{
  var status = TargetInterface.getDebugRegister(0x01000000);  
  if (status & (1<<0))
    WScript.Echo("Flash Mass Erase Acknowledge\n");
  if (status & (1<<1))
    WScript.Echo("Flash Ready\n");
  if (status & (1<<2))
    WScript.Echo("System Security\n");
  if ((status & (1<<3))==0)
    WScript.Echo("System Is In Reset\n");
  if (status & (1<<5))
    WScript.Echo("Mass Erase Enable\n");
  if (status & (1<<6))
    WScript.Echo("Backdoor Access Key Enable\n");
  if (status & (1<<7))
    WScript.Echo("LP Enabled\n");
  if (status & (1<<8))
    WScript.Echo("Very Low Power Mode\n");
  if (status & (1<<9))
    WScript.Echo("LLS Mode Exit\n");
  if (status & (1<<10))
    WScript.Echo("VLLSx Modes Exit\n");
  if (status & (1<<16))
    WScript.Echo("Core Halted\n");
  if (status & (1<<17))
    WScript.Echo("Core SLEEPDEEP\n");
  if (status & (1<<18))
    WScript.Echo("Core SLEEPING\n");
}

function MDMControl()
{
  var status = TargetInterface.getDebugRegister(0x01000004);
  if (status & (1<<0))
    WScript.Echo("Flash Mass Erase in Progress\n");
  if (status & (1<<1))
    WScript.Echo("Debug Disable\n");
  if (status & (1<<2))
    WScript.Echo("Debug Request\n");
  if (status & (1<<3))
    WScript.Echo("System Reset Request\n");
  if (status & (1<<4))
    WScript.Echo("Core Hold Reset\n");
  if (status & (1<<5))
    WScript.Echo("VLLSx Debug Request\n");
  if (status & (1<<6))
    WScript.Echo("VLLSx Debug Acknowledge\n");
  if (status & (1<<7))
    WScript.Echo("LLS, VLLSx Status Acknowledge\n");
}

function MassEraseUnderNSRST()
{
  TargetInterface.setNSRST(0); 
  TargetInterface.setDebugRegister(0x01000004, 0x1);
  TargetInterface.delay(1000);  
  if (TargetInterface.getDebugRegister(0x01000004) & 1)    
    TargetInterface.message("MassErase failed"); 
  TargetInterface.setNSRST(1);
}
