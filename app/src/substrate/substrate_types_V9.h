/*******************************************************************************
 *  (c) 2019 - 2022 Zondax GmbH
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
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include <stddef.h>
#include <stdint.h>

// Based
// https://github.com/paritytech/substrate/blob/master/node/primitives/src/lib.rs

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_V9_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_V9_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EcdsaPublic_V9_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EcdsaSignature_V9_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Ed25519Public_V9_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Ed25519Signature_V9_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Sr25519Public_V9_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Sr25519Signature_V9_t;

typedef struct {
    uint8_t value;
} pd_Vote_V9_t;

typedef struct {
    pd_BalanceOf_t aye;
    pd_BalanceOf_t nay;
} pd_AccountVoteSplit_V9_t;

typedef struct {
    pd_Vote_V9_t vote;
    pd_BalanceOf_t balance;
} pd_AccountVoteStandard_V9_t;

typedef struct {
    compactInt_t value;
} pd_CompactPerBill_V9_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_V9_t id;
        pd_CompactAccountIndex_V9_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_LookupasStaticLookupSource_V9_t;

typedef struct {
    uint8_t value;
    union {
        pd_Ed25519Signature_V9_t ed25519;
        pd_Sr25519Signature_V9_t sr25519;
        pd_EcdsaSignature_V9_t ecdsa;
    };
} pd_MultiSignature_V9_t;

typedef struct {
    uint8_t value;
    union {
        pd_Ed25519Public_V9_t ed25519;
        pd_Sr25519Public_V9_t sr25519;
        pd_EcdsaPublic_V9_t ecdsa;
    };
} pd_MultiSigner_V9_t;

typedef struct {
    uint8_t value;
} pd_ProxyType_V9_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_V9_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountVoteStandard_V9_t voteStandard;
        pd_AccountVoteSplit_V9_t voteSplit;
    };
} pd_AccountVote_V9_t;

typedef struct {
    pd_Call_t call;
} pd_OpaqueCall_V9_t;

typedef struct {
    uint8_t some;
    pd_MultiSignature_V9_t contained;
} pd_OptionMultiSignature_V9_t;

typedef struct {
    uint8_t some;
    pd_MultiSigner_V9_t contained;
} pd_OptionMultiSigner_V9_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_V9_t contained;
} pd_OptionTimepoint_V9_t;

typedef struct {
    uint8_t value;
    pd_AccountId_V9_t accountId;
} pd_RewardDestination_V9_t;

typedef struct {
    pd_CompactPerBill_V9_t commission;
    pd_bool_t blocked;
} pd_ValidatorPrefs_V9_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecLookupasStaticLookupSource_V9_t;

typedef struct {
    pd_BalanceOf_t locked;
    pd_BalanceOf_t per_block;
    pd_BlockNumber_t starting_block;
} pd_VestingInfo_V9_t;

typedef struct {
    uint32_t value;
} pd_AccountIndex_V9_t;

typedef struct {
    uint8_t value;
} pd_Conviction_V9_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_V9_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EthereumAddress_V9_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V9_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_V9_t;

typedef struct {
    uint8_t some;
    pd_AccountId_V9_t contained;
} pd_OptionAccountId_V9_t;

typedef struct {
    uint8_t some;
    pd_ProxyType_V9_t contained;
} pd_OptionProxyType_V9_t;

typedef struct {
    uint32_t value;
} pd_ParaId_V9_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V9_t;

typedef struct {
    uint32_t value;
} pd_ReferendumIndex_V9_t;

typedef struct {
    uint32_t value;
} pd_RegistrarIndex_V9_t;

typedef struct {
    uint32_t value;
} pd_SessionIndex_V9_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V9_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_V9_t id;
        pd_CompactAccountIndex_V9_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_AccountIdLookupOfT_V9_t;

typedef struct {
    uint64_t value;
} pd_Weight_V9_t;

#ifdef __cplusplus
}
#endif
