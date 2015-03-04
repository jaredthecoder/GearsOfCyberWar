// <copyright file="XorCrypt.h" company="Jonathan Racicot">
//    C++ XOR Encryption/Decryption Implementation
//    Copyright (C) 2015 Jonathan Racicot
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
// </copyright>
// <author>Jonathan Racicot</author>
// <email>infectedpacket@gmail.com</email>
// <date>2015-03-01</date>
// <summary>C++ implementation of the XOR encryption/decryption mechanism.</summary>


#include <stdio.h>
#include "XorCrypt.h"

/**
<summary></summary>
<param name="CipherData"></param>
<param name="DataLength"></param>
<param name="Key"></param>
<param name="KeyLength"></param>
<returns></returns>
*/
unsigned char* XorCrypt(unsigned char* CipherData, unsigned int DataLength, 
	char* Key, unsigned int KeyLength) {
	
	if ((CipherData && DataLength > 0) &&
		(Key && KeyLength > 0)) {
		unsigned char* PlainData = new unsigned char[DataLength];
		unsigned int idx = 0;
		for (idx = 0; idx < DataLength; idx++) {
			PlainData[idx] = (CipherData[idx] ^ Key[idx%KeyLength]);
		}

		return PlainData;
	}

	return 0;
}


int TestXorCrypt() {
	unsigned char TestData[] = {0x0, 'A', 'B', 'C', 'D', '1', 0xFA};
	unsigned int TestDataLen = 7;
	char Key[] = {0x41};
	unsigned int KeyLen = 1;

	printf("[*] Test Bytes: ");
	for (unsigned int i = 0; i < TestDataLen; i++) {
		printf("0x%02X ", TestData[i]);
	}
	printf("\n");

	printf("[*] Key Bytes: ");
	for (unsigned int i = 0; i < KeyLen; i++) {
		printf("0x%02X ", Key[i]);
	}
	printf("\n");
	unsigned char* CipherData = XorCrypt(TestData, TestDataLen, Key, KeyLen);

	printf("[*] Result: ");
	for (unsigned int i = 0; i < TestDataLen; i++) {
		printf("0x%02X ", CipherData[i]);
	}
	printf("\n");

	return 0;
}