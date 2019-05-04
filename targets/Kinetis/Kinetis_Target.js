/******************************************************************************
  Target Script for Freescale Kinetis

  Copyright (c) 2010, 2011, 2012 Rowley Associates Limited.

  This file may be distributed under the terms of the License Agreement
  provided with this software.

  THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE
  WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 ******************************************************************************/

function EnableTrace(TraceInterfaceType)
{
  if (TraceInterfaceType == "ETB")
    {
      TargetInterface.pokeWord(0xE0080014, 0x00000030); // MCM_ETB_CNT_CTRL - disable TPIU
      var CSTF_Ctrl_Reg = ((0x908<<16)|0);
      v = TargetInterface.getICEBreakerRegister(CSTF_Ctrl_Reg);
      TargetInterface.setICEBreakerRegister(CSTF_Ctrl_Reg, v | 0x00000003); // EnS0 | EnS1  
    }
}

function Reset()
{
  if (TargetInterface.implementation() == "crossworks_simulator")
    {
      TargetInterface.stop(1);
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

function GetPartName()
{    
  TargetInterface.pokeWord(0xE000EDFC, (1<<24)); 
  var status = TargetInterface.getDebugRegister(0x01000000);    
  if (status & (1<<2))
    {
      if (CWSys.popup && CWSys.popup("System Security Enabled - MassErase to unlock?\nNote that the nSRST must be connected to the debug port\n"))        
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
  var SIM_SDID = TargetInterface.peekWord(0x40048024);
  var SIM_FCFG2 = TargetInterface.peekWord(0x40048050);
  var PartName;
  switch ((SIM_SDID>>20) & 0xf) 
    {
      case 0: // K Series
        switch ((SIM_SDID>>4) & 0x7)
          {
            case 0: // K10
              PartName = "MK10";
              break;
            case 1: // K20
              PartName = "MK20";
              break;
            case 2: // K30
              PartName = "MK30";
              break;
            case 3: // K40
              PartName = "MK40";
              break;
            case 4: // K60
              PartName = "MK60";
              break;
            case 5: // K70
              PartName = "MK70";
              break;
            case 6: // K50/K52
              PartName = "MK50";
              break;
            case 7: // K51/K53
              PartName = "MK51";
              break;
          }        
        if (((SIM_SDID>>7) & 0x7)==3)
          PartName += "F";
        else
          PartName += "D";
        if (SIM_FCFG2 & (1<<23))
          {
            PartName += "N";
            Length = ((SIM_FCFG2>>24) & 0x3f)<<3;
            Length += ((SIM_FCFG2>>16) & 0x3f)<<3;
            if (((SIM_SDID>>7) & 0x7)==3)
              Length *= 2;
            if (Length == 1024)
              PartName += "1M0";
            else
              PartName += Length.toString();
          }
        else
          {
            PartName += "X";
            Length = ((SIM_FCFG2>>24) & 0x3f)<<3;
            if (((SIM_SDID>>7) & 0x7)==3)
              Length *= 2;
            PartName += Length.toString();
          }
      break;
    case 1: // KL Series
      if (((SIM_SDID>>24)&0xff) < 10)
        PartName = "MKL0"+((SIM_SDID>>24)&0xff).toString(16)+"Z";
      else
        PartName = "MKL"+((SIM_SDID>>24)&0xff).toString(16)+"Z";       
      Length = ((SIM_FCFG2>>24) & 0x3f)<<3;
      PartName += Length.toString();
      break;
    }
  return PartName;
}

function MatchPartName(name)
{
  return name && name.substring(0, 8) == GetPartName().substring(0, 8);
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
