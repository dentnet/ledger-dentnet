/*******************************************************************************
*   (c) 2019 Zondax GmbH
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/

/*
 * Modified by DENT Wireless to add support for multi-byte address types in
 * ss58 encoding.
 */

#include "crypto_helper.h"
#include "base58.h"

#if defined(TARGET_NANOS) || defined(TARGET_NANOX)
#include "cx.h"

int ss58hash(const unsigned char *in, unsigned int inLen,
                   unsigned char *out, unsigned int outLen) {

    cx_blake2b_t ctx;
    cx_blake2b_init(&ctx, 512);
    cx_hash(&ctx.header, 0, SS58_BLAKE_PREFIX, SS58_BLAKE_PREFIX_LEN, NULL, 0);
    cx_hash(&ctx.header, CX_LAST, in, inLen, out, outLen);

    return 0;
}
#else

#include <hexutils.h>
#include "blake2.h"

int ss58hash(const unsigned char *in, unsigned int inLen,
             unsigned char *out, unsigned int outLen) {
    blake2b_state s;
    blake2b_init(&s, 64);
    blake2b_update(&s, SS58_BLAKE_PREFIX, SS58_BLAKE_PREFIX_LEN);
    blake2b_update(&s, in, inLen);
    blake2b_final(&s, out, outLen);
    return 0;
}

#endif

uint8_t crypto_SS58EncodePubkey(uint8_t *buffer, uint16_t buffer_len,
                                uint16_t addressType, const uint8_t *pubkey) {
    if (buffer == NULL || buffer_len < SS58_ADDRESS_MAX_LEN) {
        return 0;
    }
    if (pubkey == NULL) {
        return 0;
    }
    MEMZERO(buffer, buffer_len);

    uint8_t unencoded[36];
    uint8_t hash[64];
    uint8_t addressTypeLen = 1;

    if (addressType < 64) {
        unencoded[0] = (uint8_t)addressType;                  // address type
    } else {
        unencoded[0] = ((addressType & 0b0000000011111100) >> 2) | 0b01000000;
        unencoded[1] = (addressType >> 8) | ((addressType & 0b0000000000000011) << 6);
        addressTypeLen = 2;
    } 

    memcpy(unencoded + addressTypeLen, pubkey, 32);           // account id
    ss58hash((uint8_t *) unencoded, 32 + addressTypeLen, hash, 64);
    unencoded[32+addressTypeLen] = hash[0];
    unencoded[33+addressTypeLen] = hash[1];

    size_t outLen = buffer_len;
    encode_base58(unencoded, 34 + addressTypeLen, buffer, &outLen);

    return outLen;
}
