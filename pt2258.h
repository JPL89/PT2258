// @File		PT2258.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		05/05/23
//
//
// Copyright (C) 2023 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#ifndef PT2258_H
#define PT2258_H

#include "wire.h"

#define PT2258_SLA_W	0x88

const char channel[7] =
{
    0xD0,		// CHANNEL MASTER
    0x80,		// CHANNEL 1
    0x40,		// CHANNEL 2
    0x00,		// CHANNEL 3
    0x20,		// CHANNEL 4
    0x60,		// CHANNEL 5
    0xA0,		// CHANNEL 6
};

void PT2258_Set_Channel_Volume(unsigned char ch, unsigned char vol)
{
    vol = (79 - vol);

    unsigned char c	= (channel[ ch ] | 0x00) | (vol / 10);
    unsigned char v	= (channel[ ch ] | 0x10) | (vol % 10);

    Wire_Start();
    Wire_Write( PT2258_SLA_W );
    Wire_Write( c );
    Wire_Write( v );
    Wire_Stop();
}

void PT2258_Set_Mute(unsigned char mute)
{
    Wire_Start();
    Wire_Write( PT2258_SLA_W );
    Wire_Write( 0xF8 | mute );
    Wire_Stop();
}

void PT2258_Reset()
{
    Wire_Start();
    Wire_Write( PT2258_SLA_W );
    Wire_Write( 0xC0 );
    Wire_Stop();
}

#endif
