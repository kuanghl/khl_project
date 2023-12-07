#include "crc.h"

/******************************************************************************
 * Name:    CRC-8               x8+x2+x+1
 * Poly:    0x07
 * Init:    0x00
 * Refin:   False
 * Refout:  False
 * Xorout:  0x00
 * Note:
 *****************************************************************************/
uint8_t crc8(uint8_t *data, uint32_t length)
{
    uint8_t i;
    uint8_t crc = 0;        // Initial value
    while(length--)
    {
        crc ^= *data++;        // crc ^= *data; data++;
        for ( i = 0; i < 8; i++ )
        {
            if ( crc & 0x80 )
                crc = (crc << 1) ^ 0x07;
            else
                crc <<= 1;
        }
    }
    return crc;
}
 
/******************************************************************************
 * Name:    CRC-8/ITU           x8+x2+x+1
 * Poly:    0x07
 * Init:    0x00
 * Refin:   False
 * Refout:  False
 * Xorout:  0x55
 * Alias:   CRC-8/ATM
 *****************************************************************************/
uint8_t crc8_itu(uint8_t *data, uint32_t length)
{
    uint8_t i;
    uint8_t crc = 0;        // Initial value
    while(length--)
    {
        crc ^= *data++;        // crc ^= *data; data++;
        for ( i = 0; i < 8; i++ )
        {
            if ( crc & 0x80 )
                crc = (crc << 1) ^ 0x07;
            else
                crc <<= 1;
        }
    }
    return crc ^ 0x55;
}
 
/******************************************************************************
 * Name:    CRC-8/ROHC          x8+x2+x+1
 * Poly:    0x07
 * Init:    0xFF
 * Refin:   True
 * Refout:  True
 * Xorout:  0x00
 * Note:
 *****************************************************************************/
uint8_t crc8_rohc(uint8_t *data, uint32_t length)
{
    uint8_t i;
    uint8_t crc = 0xFF;         // Initial value
    while(length--)
    {
        crc ^= *data++;            // crc ^= *data; data++;
        for (i = 0; i < 8; ++i)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0xE0;        // 0xE0 = reverse 0x07
            else
                crc = (crc >> 1);
        }
    }
    return crc;
}
 
/******************************************************************************
 * Name:    CRC-8/MAXIM         x8+x5+x4+1
 * Poly:    0x31
 * Init:    0x00
 * Refin:   True
 * Refout:  True
 * Xorout:  0x00
 * Alias:   DOW-CRC,CRC-8/IBUTTON
 * Use:     Maxim(Dallas)'s some devices,e.g. DS18B20
 *****************************************************************************/
uint8_t crc8_maxim(uint8_t *data, uint32_t length)
{
    uint8_t i;
    uint8_t crc = 0;         // Initial value
    while(length--)
    {
        crc ^= *data++;        // crc ^= *data; data++;
        for (i = 0; i < 8; i++)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0x8C;        // 0x8C = reverse 0x31
            else
                crc >>= 1;
        }
    }
    return crc;
}