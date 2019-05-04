/******************************************************************************
  Target Script for Freescale Kinetis

  Copyright (c) 2010, 2011 Rowley Associates Limited.

  This file may be distributed under the terms of the License Agreement
  provided with this software.

  THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE
  WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 ******************************************************************************/

function Reset()
{
  if (TargetInterface.implementation() == "crossworks_simulator")
    {
      TargetInterface.stop(1);
      return;
    }
  if (TargetInterface.implementation() == "j-link")
    {
      TargetInterface.stopAndReset(1);
      return;
    }
  if (TargetInterface.implementation() == "osjtag")
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

function MDMStatus()
{
  if (TargetInterface.implementation() == "j-link")
    {
      WScript.Echo("MDM not accessible using j-link");
      return;
    }
  if (TargetInterface.implementation() == "osjtag")
    TargetInterface.stop();
  var status = TargetInterface.getDebugRegister(0x01000000);
  if (status & (1<<0))
    WScript.Echo("Flash Mass Erase Acknowledge\n");
  if (status & (1<<1))
    WScript.Echo("Flash Ready\n");
  if (status & (1<<2))
    WScript.Echo("System Security\n");
  if (status & (1<<3))
    WScript.Echo("System Reset\n");
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
  if (TargetInterface.implementation() == "j-link")
    {
      WScript.Echo("MDM not accessible using j-link");
      return;
    }
  if (TargetInterface.implementation() == "osjtag")
    TargetInterface.stop();
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

function MassErase()
{
  if (TargetInterface.implementation() == "j-link")
    {
      WScript.Echo("MDM not accessible using j-link");
      return;
    }
  if (TargetInterface.implementation() == "osjtag")
    TargetInterface.stop();
  var i;
  TargetInterface.setDebugRegister(0x01000004, 0x1); 
  for (i=0;i<100 && (TargetInterface.getDebugRegister(0x01000004)&1);i++);
  if (i==100)
    WScript.Error("Mass Erase timed out\n");
}
