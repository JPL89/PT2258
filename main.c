// @File		MAIN.C		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		01/05/23
//
//
// Copyright (C) 2023 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#include "utils.h"
#include "wire.h"
#include "pt2258.h"

void main(void)
{
    __delay_ms(1000);
    
    PIC18F2520();
    
    Wire_Init();
 
    PT2258_Reset();
    
    PT2258_Set_Mute(0);
    
    PT2258_Set_Channel_Volume(1, 70);  
    
    while(1)
    {
        
    }
    
    return;
}
