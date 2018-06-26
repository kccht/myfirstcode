/*
 * crc.h
 * 
 * Copyright 2018 cc <>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
#ifndef _CRC_H_
#define _CRC_H_

#include <iostream>
#include "std_msgs/UInt8.h"
#include <stdio.h>
//#include < stdint.h>
namespace crc
{
class CRC
{

public:
	CRC();//构造函数
	~CRC();//构造函数
    int cc11;
    void sayHello(void);
    uint8_t sum(uint8_t *buf,uint8_t i,uint8_t number);
    unsigned int CRC16(unsigned char* pchMsg, unsigned int wDataLen);
};



}
#endif
