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


HighTempMCP320x::HighTempMCP320x(int _spiCS, int _pinTmp, int _pinThmc) : HighTemp(_pinTmp, _pinThmc)
{
    spiChipSelect = _spiCS;
    adc = MCP3208(spiChipSelect); 
}


int HighTempMCP320x::getAnalog(int pin)
{
    return adc.analogRead(pin);
}
