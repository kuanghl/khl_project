#include <stdio.h>
#include <stdint.h>

uint8_t crc8(uint8_t *data, size_t length, uint8_t poly, uint8_t init, int refin, int refout, uint8_t xorout) {
    uint8_t crc = init;
    while (length--) {
        crc ^= *data++;
        for (int i = 0; i < 8; i++) {
            if (crc & 0x80) {
                crc = (crc << 1) ^ poly;
            } else {
                crc <<= 1;
            }
        }
    }
    crc ^= xorout;
    return refout ? crc : (uint8_t)reflect(crc, 8);
}

uint16_t crc16(uint8_t *data, size_t length, uint16_t poly, uint16_t init, int refin, int refout, uint16_t xorout) {
    uint16_t crc = init;
    while (length--) {
        crc ^= *data++;
        for (int i = 0; i < 8; i++) {
            if (crc & 0x8000) {
                crc = (crc << 1) ^ poly;
            } else {
                crc <<= 1;
            }
        }
    }
    crc ^= xorout;
    return refout ? crc : (uint16_t)reflect(crc, 16);
}

uint32_t crc32(uint8_t *data, size_t length, uint32_t poly, uint32_t init, int refin, int refout, uint32_t xorout) {
    uint32_t crc = init;
    while (length--) {
        crc ^= *data++;
        for (int i = 0; i < 8; i++) {
            if (crc & 0x80000000) {
                crc = (crc << 1) ^ poly;
            } else {
                crc <<= 1;
            }
        }
    }
    crc ^= xorout;
    return refout ? crc : (uint32_t)reflect(crc, 32);
}

uint64_t crc64(uint8_t *data, size_t length, uint64_t poly, uint64_t init, int refin, int refout, uint64_t xorout) {
    uint64_t crc = init;
    while (length--) {
        crc ^= *data++;
        for (int i = 0; i < 8; i++) {
            if (crc & 0x8000000000000000) {
                crc = (crc << 1) ^ poly;
            } else {
                crc <<= 1;
            }
        }
    }
    crc ^= xorout;
    return refout ? crc : (uint64_t)reflect(crc, 64);
}

void generate_crc_table(uint32_t *table, int width, uint32_t poly) {
    for (int i = 0; i < 256; i++) {
        uint32_t crc = i;
        if (width == 8) {
            for (int j = 0; j < 8; j++) {
                crc = (crc & 0x80) ? (crc << 1) ^ poly : (crc << 1);
            }
        } else if (width == 16) {
            for (int j = 0; j < 8; j++) {
                crc = (crc & 0x8000) ? (crc << 1) ^ poly : (crc << 1);
            }
        } else if (width == 32) {
            for (int j = 0; j < 8; j++) {
                crc = (crc & 0x80000000) ? (crc << 1) ^ poly : (crc << 1);
            }
        } else if (width == 64) {
            for (int j = 0; j < 8; j++) {
                crc = (crc & 0x8000000000000000) ? (crc << 1) ^ poly : (crc << 1);
            }
        }
        table[i] = crc;
    }
}
