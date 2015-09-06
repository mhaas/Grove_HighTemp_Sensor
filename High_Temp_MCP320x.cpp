/*
  High_Temp.cpp

  2014 Copyright (c) Seeed Technology Inc.  All right reserved.

  Loovee
  2013-4-14

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <Arduino.h>
#include "High_Temp_MCP320x.h"

// offset voltage, mv
const float VOL_OFFSET = 350;                       
// Av of amplifier
const float AMP_AV     = 54.16;                    


HighTempMCP320x::HighTemp(int _spiCS, int _pinTmp, int _pinThmc)
{
    spiChipSelect = _spiCS;
    adc = MCP3208(spiChipSelect); 
}


int HighTempMCP320x::getAnalog(int pin)
{
    long sum = 0;

    for(int i=0; i<32; i++)
    {
        sum += adc.analogRead(pin);
    }
    // 3.3V supply
    return ((sum>>5));                                              

