/*
 * The Apache Software License, Version 1.1
 * 
 * Copyright (c) 1999-2000 The Apache Software Foundation.  All rights 
 * reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer. 
 * 
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 
 * 3. The end-user documentation included with the redistribution,
 *    if any, must include the following acknowledgment:  
 *       "This product includes software developed by the
 *        Apache Software Foundation (http://www.apache.org/)."
 *    Alternately, this acknowledgment may appear in the software itself,
 *    if and wherever such third-party acknowledgments normally appear.
 * 
 * 4. The names "Xerces" and "Apache Software Foundation" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written 
 *    permission, please contact apache\@apache.org.
 * 
 * 5. Products derived from this software may not be called "Apache",
 *    nor may "Apache" appear in their name, without prior written
 *    permission of the Apache Software Foundation.
 * 
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE APACHE SOFTWARE FOUNDATION OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * ====================================================================
 * 
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Software Foundation, and was
 * originally based on software copyright (c) 1999, International
 * Business Machines, Inc., http://www.ibm.com .  For more information
 * on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 */


// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include <util/BitOps.hpp>
#include <util/XMLIBM1140Transcoder.hpp>
#include <util/TranscodingException.hpp>
#include <memory.h>



// ---------------------------------------------------------------------------
//  Local const data
//
//  gIBM1140XlatTable
//      This is the translation table for ibm-1140 to Unicode. This table
//      contains 255 entries. The entry for x is the Unicode symbol for
//      ibm-1140 code x.
// ---------------------------------------------------------------------------
static const XMLCh gIBM1140XlatTable[256] =
{
    0x0000, 0x0001, 0x0002, 0x0003, 0x009C, 0x0009, 0x0086, 0x007F
  , 0x0097, 0x008D, 0x008E, 0x000B, 0x000C, 0x000D, 0x000E, 0x000F
  , 0x0010, 0x0011, 0x0012, 0x0013, 0x009D, 0x0085, 0x0008, 0x0087
  , 0x0018, 0x0019, 0x0092, 0x008F, 0x001C, 0x001D, 0x001E, 0x001F
  , 0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x000A, 0x0017, 0x001B
  , 0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x0005, 0x0006, 0x0007
  , 0x0090, 0x0091, 0x0016, 0x0093, 0x0094, 0x0095, 0x0096, 0x0004
  , 0x0098, 0x0099, 0x009A, 0x009B, 0x0014, 0x0015, 0x009E, 0x001A
  , 0x0020, 0x00A0, 0x00E2, 0x00E4, 0x00E0, 0x00E1, 0x00E3, 0x00E5
  , 0x00E7, 0x00F1, 0x00A2, 0x002E, 0x003C, 0xFF08, 0xFF0B, 0xFF5C
  , 0x0026, 0x00E9, 0x00EA, 0x00EB, 0x00E8, 0x00ED, 0x00EE, 0x00EF
  , 0x00EC, 0x00DF, 0x0021, 0x0024, 0x002A, 0xFF09, 0x003B, 0x00AC
  , 0x002D, 0xFF0F, 0x00C2, 0x00C4, 0x00C0, 0x00C1, 0x00C3, 0x00C5
  , 0x00C7, 0x00D1, 0x00A6, 0x002C, 0xFF05, 0xFF3F, 0x003E, 0x003F
  , 0x00F8, 0x00C9, 0x00CA, 0x00CB, 0x00C8, 0x00CD, 0x00CE, 0x00CF
  , 0x00CC, 0xFF40, 0xFF1A, 0x0023, 0xFF20, 0x0027, 0xFF1D, 0x0022
  , 0x00D8, 0x0061, 0xFF42, 0x0063, 0xFF44, 0xFF45, 0x0066, 0x0067
  , 0xFF48, 0x0069, 0x00AB, 0x00BB, 0x00F0, 0x00FD, 0x00FE, 0x00B1
  , 0x00B0, 0xFF4A, 0x006B, 0x006C, 0xFF4D, 0x006E, 0xFF4F, 0x0070
  , 0x0071, 0xFF52, 0x00AA, 0x00BA, 0x00E6, 0x00B8, 0x00C6, 0x20AC
  , 0x00B5, 0x007E, 0x0073, 0x0074, 0x0075, 0xFF56, 0x0077, 0x0078
  , 0xFF59, 0xFF5A, 0x00A1, 0x00BF, 0x00D0, 0x00DD, 0x00DE, 0x00AE
  , 0xFF3E, 0x00A3, 0x00A5, 0x00B7, 0x00A9, 0x00A7, 0x00B6, 0x00BC
  , 0x00BD, 0x00BE, 0x005B, 0x005D, 0x00AF, 0x00A8, 0x00B4, 0x00D7
  , 0xFF5B, 0xFF21, 0xFF22, 0x0043, 0xFF24, 0xFF25, 0xFF26, 0x0047
  , 0xFF28, 0x0049, 0x00AD, 0x00F4, 0x00F6, 0x00F2, 0x00F3, 0x00F5
  , 0x007D, 0xFF2A, 0xFF2B, 0xFF2C, 0x004D, 0x004E, 0x004F, 0x0050
  , 0x0051, 0x0052, 0x00B9, 0x00FB, 0x00FC, 0x00F9, 0x00FA, 0x00FF
  , 0x005C, 0x00F7, 0x0053, 0x0054, 0xFF35, 0xFF36, 0x0057, 0xFF38
  , 0xFF39, 0x005A, 0x00B2, 0x00D4, 0x00D6, 0x00D2, 0x00D3, 0x00D5
  , 0x0030, 0x0031, 0x0032, 0xFF13, 0xFF14, 0xFF15, 0x0036, 0x0037
  , 0x0038, 0xFF19, 0x00B3, 0x00DB, 0x00DC, 0x00D9, 0x00DA, 0x009F
};



// ---------------------------------------------------------------------------
//  XMLIBM1140Transcoder: Public, static methods
// ---------------------------------------------------------------------------
XMLCh XMLIBM1140Transcoder::xlatThisOne(const XMLByte toXlat)
{
    return gIBM1140XlatTable[toXlat];
}


// ---------------------------------------------------------------------------
//  XMLIBM1140Transcoder: Constructors and Destructor
// ---------------------------------------------------------------------------
XMLIBM1140Transcoder::XMLIBM1140Transcoder( const   XMLCh* const encodingName
                                            , const unsigned int blockSize) :

    XMLTranscoder(encodingName, blockSize)
{
}


XMLIBM1140Transcoder::~XMLIBM1140Transcoder()
{
}


// ---------------------------------------------------------------------------
//  XMLIBM1140Transcoder: Implementation of the transcoder API
// ---------------------------------------------------------------------------
bool XMLIBM1140Transcoder::supportsSrcOfs() const
{
    // Yes we support this
    return true;
}


XMLCh
XMLIBM1140Transcoder::transcodeOne( const   XMLByte* const  srcData
                                    , const unsigned int    srcBytes
                                    ,       unsigned int&   bytesEaten)
{
    // If no source, give up
    if (!srcBytes)
        return 0;

    // We will eat one byte
    bytesEaten = 1;

    // And use the 0th byte as a look in our table
    return gIBM1140XlatTable[*srcData];
}


unsigned int
XMLIBM1140Transcoder::transcodeXML( const   XMLByte* const       srcData
                                    , const unsigned int         srcCount
                                    ,       XMLCh* const         toFill
                                    , const unsigned int         maxChars
                                    ,       unsigned int&        bytesEaten
                                    ,       unsigned char* const charSizes)
{
    // If debugging, make sure that the block size is legal
    #if defined(XML4C_DEBUG)
    checkBlockSize(maxChars);
    #endif

    //
    //  Calculate the max chars we can do here. Its the lesser of the
    //  max output chars and the number of chars in the source.
    //
    const unsigned int countToDo = srcCount < maxChars ? srcCount : maxChars;

    //
    //  Loop through the count we have to do and map each char via the
    //  lookup table.
    //
    const XMLByte*  srcPtr = srcData;
    const XMLByte*  endPtr = (srcPtr + countToDo);
    XMLCh*          outPtr = toFill;
    while (srcPtr < endPtr)
        *outPtr++ = gIBM1140XlatTable[*srcPtr++];

    // Set the bytes eaten
    bytesEaten = countToDo;

    // Set the character sizes to the fixed size
    memset(charSizes, 1, countToDo);

    // Return the chars we transcoded
    return countToDo;
}



#if 0
struct XlatRecord
{
    XMLCh   xmlCh;
    XMLByte ebcdicCh;
};

static XlatRecord gXlatTable[] =
{
    { 0x0000  , 0x00 }
  , { 0x0001  , 0x01 }
  , { 0x0002  , 0x02 }
  , { 0x0003  , 0x03 }
  , { 0x0004  , 0x37 }
  , { 0x0005  , 0x2D }
  , { 0x0006  , 0x2E }
  , { 0x0007  , 0x2F }
  , { 0x0008  , 0x16 }
  , { 0x0009  , 0x05 }
  , { 0x000A  , 0x25 }
  , { 0x000B  , 0x0B }
  , { 0x000C  , 0x0C }
  , { 0x000D  , 0x0D }
  , { 0x000E  , 0x0E }
  , { 0x000F  , 0x0F }
  , { 0x0010  , 0x10 }
  , { 0x0011  , 0x11 }
  , { 0x0012  , 0x12 }
  , { 0x0013  , 0x13 }
  , { 0x0014  , 0x3C }
  , { 0x0015  , 0x3D }
  , { 0x0016  , 0x32 }
  , { 0x0017  , 0x26 }
  , { 0x0018  , 0x18 }
  , { 0x0019  , 0x19 }
  , { 0x001A  , 0x3F }
  , { 0x001B  , 0x27 }
  , { 0x001C  , 0x1C }
  , { 0x001D  , 0x1D }
  , { 0x001E  , 0x1E }
  , { 0x001F  , 0x1F }
  , { 0x0020  , 0x40 }
  , { 0xFF01  , 0x5A }
  , { 0x0021  , 0x5A }
  , { 0xFF02  , 0x7F }
  , { 0x0022  , 0x7F }
  , { 0xFF03  , 0x7B }
  , { 0x0023  , 0x7B }
  , { 0xFF04  , 0x5B }
  , { 0x0024  , 0x5B }
  , { 0xFF05  , 0x6C }
  , { 0x0025  , 0x6C }
  , { 0xFF06  , 0x50 }
  , { 0x0026  , 0x50 }
  , { 0xFF07  , 0x7D }
  , { 0x0027  , 0x7D }
  , { 0xFF08  , 0x4D }
  , { 0x0028  , 0x4D }
  , { 0xFF09  , 0x5D }
  , { 0x0029  , 0x5D }
  , { 0xFF0A  , 0x5C }
  , { 0x002A  , 0x5C }
  , { 0xFF0B  , 0x4E }
  , { 0x002B  , 0x4E }
  , { 0xFF0C  , 0x6B }
  , { 0x002C  , 0x6B }
  , { 0xFF0D  , 0x60 }
  , { 0x002D  , 0x60 }
  , { 0xFF0E  , 0x4B }
  , { 0x002E  , 0x4B }
  , { 0xFF0F  , 0x61 }
  , { 0x002F  , 0x61 }
  , { 0xFF10  , 0xF0 }
  , { 0x0030  , 0xF0 }
  , { 0xFF11  , 0xF1 }
  , { 0x0031  , 0xF1 }
  , { 0xFF12  , 0xF2 }
  , { 0x0032  , 0xF2 }
  , { 0xFF13  , 0xF3 }
  , { 0x0033  , 0xF3 }
  , { 0xFF14  , 0xF4 }
  , { 0x0034  , 0xF4 }
  , { 0xFF15  , 0xF5 }
  , { 0x0035  , 0xF5 }
  , { 0xFF16  , 0xF6 }
  , { 0x0036  , 0xF6 }
  , { 0xFF17  , 0xF7 }
  , { 0x0037  , 0xF7 }
  , { 0xFF18  , 0xF8 }
  , { 0x0038  , 0xF8 }
  , { 0xFF19  , 0xF9 }
  , { 0x0039  , 0xF9 }
  , { 0xFF1A  , 0x7A }
  , { 0x003A  , 0x7A }
  , { 0xFF1B  , 0x5E }
  , { 0x003B  , 0x5E }
  , { 0xFF1C  , 0x4C }
  , { 0x003C  , 0x4C }
  , { 0xFF1D  , 0x7E }
  , { 0x003D  , 0x7E }
  , { 0xFF1E  , 0x6E }
  , { 0x003E  , 0x6E }
  , { 0xFF1F  , 0x6F }
  , { 0x003F  , 0x6F }
  , { 0xFF20  , 0x7C }
  , { 0x0040  , 0x7C }
  , { 0xFF21  , 0xC1 }
  , { 0x0041  , 0xC1 }
  , { 0xFF22  , 0xC2 }
  , { 0x0042  , 0xC2 }
  , { 0xFF23  , 0xC3 }
  , { 0x0043  , 0xC3 }
  , { 0xFF24  , 0xC4 }
  , { 0x0044  , 0xC4 }
  , { 0xFF25  , 0xC5 }
  , { 0x0045  , 0xC5 }
  , { 0xFF26  , 0xC6 }
  , { 0x0046  , 0xC6 }
  , { 0xFF27  , 0xC7 }
  , { 0x0047  , 0xC7 }
  , { 0xFF28  , 0xC8 }
  , { 0x0048  , 0xC8 }
  , { 0xFF29  , 0xC9 }
  , { 0x0049  , 0xC9 }
  , { 0xFF2A  , 0xD1 }
  , { 0x004A  , 0xD1 }
  , { 0xFF2B  , 0xD2 }
  , { 0x004B  , 0xD2 }
  , { 0xFF2C  , 0xD3 }
  , { 0x004C  , 0xD3 }
  , { 0xFF2D  , 0xD4 }
  , { 0x004D  , 0xD4 }
  , { 0xFF2E  , 0xD5 }
  , { 0x004E  , 0xD5 }
  , { 0xFF2F  , 0xD6 }
  , { 0x004F  , 0xD6 }
  , { 0xFF30  , 0xD7 }
  , { 0x0050  , 0xD7 }
  , { 0xFF31  , 0xD8 }
  , { 0x0051  , 0xD8 }
  , { 0xFF32  , 0xD9 }
  , { 0x0052  , 0xD9 }
  , { 0xFF33  , 0xE2 }
  , { 0x0053  , 0xE2 }
  , { 0xFF34  , 0xE3 }
  , { 0x0054  , 0xE3 }
  , { 0xFF35  , 0xE4 }
  , { 0x0055  , 0xE4 }
  , { 0xFF36  , 0xE5 }
  , { 0x0056  , 0xE5 }
  , { 0xFF37  , 0xE6 }
  , { 0x0057  , 0xE6 }
  , { 0xFF38  , 0xE7 }
  , { 0x0058  , 0xE7 }
  , { 0xFF39  , 0xE8 }
  , { 0x0059  , 0xE8 }
  , { 0xFF3A  , 0xE9 }
  , { 0x005A  , 0xE9 }
  , { 0xFF3B  , 0xBA }
  , { 0x005B  , 0xBA }
  , { 0xFF3C  , 0xE0 }
  , { 0x005C  , 0xE0 }
  , { 0xFF3D  , 0xBB }
  , { 0x005D  , 0xBB }
  , { 0xFF3E  , 0xB0 }
  , { 0x005E  , 0xB0 }
  , { 0xFF3F  , 0x6D }
  , { 0x005F  , 0x6D }
  , { 0xFF40  , 0x79 }
  , { 0x0060  , 0x79 }
  , { 0xFF41  , 0x81 }
  , { 0x0061  , 0x81 }
  , { 0xFF42  , 0x82 }
  , { 0x0062  , 0x82 }
  , { 0xFF43  , 0x83 }
  , { 0x0063  , 0x83 }
  , { 0xFF44  , 0x84 }
  , { 0x0064  , 0x84 }
  , { 0xFF45  , 0x85 }
  , { 0x0065  , 0x85 }
  , { 0xFF46  , 0x86 }
  , { 0x0066  , 0x86 }
  , { 0xFF47  , 0x87 }
  , { 0x0067  , 0x87 }
  , { 0xFF48  , 0x88 }
  , { 0x0068  , 0x88 }
  , { 0xFF49  , 0x89 }
  , { 0x0069  , 0x89 }
  , { 0xFF4A  , 0x91 }
  , { 0x006A  , 0x91 }
  , { 0xFF4B  , 0x92 }
  , { 0x006B  , 0x92 }
  , { 0xFF4C  , 0x93 }
  , { 0x006C  , 0x93 }
  , { 0xFF4D  , 0x94 }
  , { 0x006D  , 0x94 }
  , { 0xFF4E  , 0x95 }
  , { 0x006E  , 0x95 }
  , { 0xFF4F  , 0x96 }
  , { 0x006F  , 0x96 }
  , { 0xFF50  , 0x97 }
  , { 0x0070  , 0x97 }
  , { 0xFF51  , 0x98 }
  , { 0x0071  , 0x98 }
  , { 0xFF52  , 0x99 }
  , { 0x0072  , 0x99 }
  , { 0xFF53  , 0xA2 }
  , { 0x0073  , 0xA2 }
  , { 0xFF54  , 0xA3 }
  , { 0x0074  , 0xA3 }
  , { 0xFF55  , 0xA4 }
  , { 0x0075  , 0xA4 }
  , { 0xFF56  , 0xA5 }
  , { 0x0076  , 0xA5 }
  , { 0xFF57  , 0xA6 }
  , { 0x0077  , 0xA6 }
  , { 0xFF58  , 0xA7 }
  , { 0x0078  , 0xA7 }
  , { 0xFF59  , 0xA8 }
  , { 0x0079  , 0xA8 }
  , { 0xFF5A  , 0xA9 }
  , { 0x007A  , 0xA9 }
  , { 0xFF5B  , 0xC0 }
  , { 0x007B  , 0xC0 }
  , { 0xFF5C  , 0x4F }
  , { 0x007C  , 0x4F }
  , { 0xFF5D  , 0xD0 }
  , { 0x007D  , 0xD0 }
  , { 0xFF5E  , 0xA1 }
  , { 0x007E  , 0xA1 }
  , { 0x007F  , 0x07 }
  , { 0x0080  , 0x20 }
  , { 0x0081  , 0x21 }
  , { 0x0082  , 0x22 }
  , { 0x0083  , 0x23 }
  , { 0x0084  , 0x24 }
  , { 0x0085  , 0x15 }
  , { 0x0086  , 0x06 }
  , { 0x0087  , 0x17 }
  , { 0x0088  , 0x28 }
  , { 0x0089  , 0x29 }
  , { 0x008A  , 0x2A }
  , { 0x008B  , 0x2B }
  , { 0x008C  , 0x2C }
  , { 0x008D  , 0x09 }
  , { 0x008E  , 0x0A }
  , { 0x008F  , 0x1B }
  , { 0x0090  , 0x30 }
  , { 0x0091  , 0x31 }
  , { 0x0092  , 0x1A }
  , { 0x0093  , 0x33 }
  , { 0x0094  , 0x34 }
  , { 0x0095  , 0x35 }
  , { 0x0096  , 0x36 }
  , { 0x0097  , 0x08 }
  , { 0x0098  , 0x38 }
  , { 0x0099  , 0x39 }
  , { 0x009A  , 0x3A }
  , { 0x009B  , 0x3B }
  , { 0x009C  , 0x04 }
  , { 0x009D  , 0x14 }
  , { 0x009E  , 0x3E }
  , { 0x009F  , 0xFF }
  , { 0x00A0  , 0x41 }
  , { 0x00A1  , 0xAA }
  , { 0x00A2  , 0x4A }
  , { 0x00A3  , 0xB1 }
  , { 0x00A5  , 0xB2 }
  , { 0x00A6  , 0x6A }
  , { 0x00A7  , 0xB5 }
  , { 0x00A8  , 0xBD }
  , { 0x00A9  , 0xB4 }
  , { 0x00AA  , 0x9A }
  , { 0x00AB  , 0x8A }
  , { 0x00AC  , 0x5F }
  , { 0x00AD  , 0xCA }
  , { 0x00AE  , 0xAF }
  , { 0x203E  , 0xBC }
  , { 0x00AF  , 0xBC }
  , { 0x00B0  , 0x90 }
  , { 0x00B1  , 0x8F }
  , { 0x00B2  , 0xEA }
  , { 0x00B3  , 0xFA }
  , { 0x00B4  , 0xBE }
  , { 0x00B5  , 0xA0 }
  , { 0x00B6  , 0xB6 }
  , { 0x00B7  , 0xB3 }
  , { 0x00B8  , 0x9D }
  , { 0x00B9  , 0xDA }
  , { 0x00BA  , 0x9B }
  , { 0x00BB  , 0x8B }
  , { 0x00BC  , 0xB7 }
  , { 0x00BD  , 0xB8 }
  , { 0x00BE  , 0xB9 }
  , { 0x00BF  , 0xAB }
  , { 0x00C0  , 0x64 }
  , { 0x00C1  , 0x65 }
  , { 0x00C2  , 0x62 }
  , { 0x00C3  , 0x66 }
  , { 0x00C4  , 0x63 }
  , { 0x00C5  , 0x67 }
  , { 0x00C6  , 0x9E }
  , { 0x00C7  , 0x68 }
  , { 0x00C8  , 0x74 }
  , { 0x00C9  , 0x71 }
  , { 0x00CA  , 0x72 }
  , { 0x00CB  , 0x73 }
  , { 0x00CC  , 0x78 }
  , { 0x00CD  , 0x75 }
  , { 0x00CE  , 0x76 }
  , { 0x00CF  , 0x77 }
  , { 0x00D0  , 0xAC }
  , { 0x00D1  , 0x69 }
  , { 0x00D2  , 0xED }
  , { 0x00D3  , 0xEE }
  , { 0x00D4  , 0xEB }
  , { 0x00D5  , 0xEF }
  , { 0x00D6  , 0xEC }
  , { 0x00D7  , 0xBF }
  , { 0x00D8  , 0x80 }
  , { 0x00D9  , 0xFD }
  , { 0x00DA  , 0xFE }
  , { 0x00DB  , 0xFB }
  , { 0x00DC  , 0xFC }
  , { 0x00DD  , 0xAD }
  , { 0x00DE  , 0xAE }
  , { 0x00DF  , 0x59 }
  , { 0x00E0  , 0x44 }
  , { 0x00E1  , 0x45 }
  , { 0x00E2  , 0x42 }
  , { 0x00E3  , 0x46 }
  , { 0x00E4  , 0x43 }
  , { 0x00E5  , 0x47 }
  , { 0x00E6  , 0x9C }
  , { 0x00E7  , 0x48 }
  , { 0x00E8  , 0x54 }
  , { 0x00E9  , 0x51 }
  , { 0x00EA  , 0x52 }
  , { 0x00EB  , 0x53 }
  , { 0x00EC  , 0x58 }
  , { 0x00ED  , 0x55 }
  , { 0x00EE  , 0x56 }
  , { 0x00EF  , 0x57 }
  , { 0x00F0  , 0x8C }
  , { 0x00F1  , 0x49 }
  , { 0x00F2  , 0xCD }
  , { 0x00F3  , 0xCE }
  , { 0x00F4  , 0xCB }
  , { 0x00F5  , 0xCF }
  , { 0x00F6  , 0xCC }
  , { 0x00F7  , 0xE1 }
  , { 0x00F8  , 0x70 }
  , { 0x00F9  , 0xDD }
  , { 0x00FA  , 0xDE }
  , { 0x00FB  , 0xDB }
  , { 0x00FC  , 0xDC }
  , { 0x00FD  , 0x8D }
  , { 0x00FE  , 0x8E }
  , { 0x00FF  , 0xDF }
  , { 0x20AC  , 0x9F }
};

#include <search.h>
#include <stdio.h>
int compFunc(const void* p1, const void* p2)
{
    const XlatRecord* rec1 = (const XlatRecord*)p1;
    const XlatRecord* rec2 = (const XlatRecord*)p2;

    return (int)rec1->ebcdicCh - (int)rec2->ebcdicCh;
}

class SpitOutTable
{
public :
    SpitOutTable()
    {
        spitOutTable();
    }

    void spitOutTable()
    {
        const unsigned int recCount = sizeof(gXlatTable) / sizeof(gXlatTable[0]);
        qsort
        (
            gXlatTable
            , recCount
            , sizeof(XlatRecord)
            , compFunc
        );

        unsigned int curValue = 0;
        for (unsigned int index = 0; index < recCount; index++)
        {
            if (gXlatTable[index].ebcdicCh == curValue)
            {
                printf("0x%04X\n", (unsigned int)gXlatTable[index].xmlCh);
                curValue++;
            }
             else
            {
                // We've hit a gap, so catch up
                while (curValue < gXlatTable[index].ebcdicCh)
                {
                    printf("0xFFFF\n");
                    curValue++;
                }
            }
        }
    }
};

SpitOutTable kicker;

#endif
