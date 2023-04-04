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

#include "parser_common.h"
#include "substrate_methods_V9.h"
#include "substrate_types_V9.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V9(parser_context_t* c, pd_AccountId_V9_t* v);
parser_error_t _readAccountIdLookupOfT_V9(parser_context_t* c, pd_AccountIdLookupOfT_V9_t* v);
parser_error_t _readAccountIndex_V9(parser_context_t* c, pd_AccountIndex_V9_t* v);
parser_error_t _readAccountVoteSplit_V9(parser_context_t* c, pd_AccountVoteSplit_V9_t* v);
parser_error_t _readAccountVoteStandard_V9(parser_context_t* c, pd_AccountVoteStandard_V9_t* v);
parser_error_t _readAccountVote_V9(parser_context_t* c, pd_AccountVote_V9_t* v);
parser_error_t _readCompactAccountIndex_V9(parser_context_t* c, pd_CompactAccountIndex_V9_t* v);
parser_error_t _readCompactPerBill_V9(parser_context_t* c, pd_CompactPerBill_V9_t* v);
parser_error_t _readConviction_V9(parser_context_t* c, pd_Conviction_V9_t* v);
parser_error_t _readEcdsaPublic_V9(parser_context_t* c, pd_EcdsaPublic_V9_t* v);
parser_error_t _readEcdsaSignature_V9(parser_context_t* c, pd_EcdsaSignature_V9_t* v);
parser_error_t _readEd25519Public_V9(parser_context_t* c, pd_Ed25519Public_V9_t* v);
parser_error_t _readEd25519Signature_V9(parser_context_t* c, pd_Ed25519Signature_V9_t* v);
parser_error_t _readEraIndex_V9(parser_context_t* c, pd_EraIndex_V9_t* v);
parser_error_t _readEthereumAddress_V9(parser_context_t* c, pd_EthereumAddress_V9_t* v);
parser_error_t _readKeys_V9(parser_context_t* c, pd_Keys_V9_t* v);
parser_error_t _readLookupasStaticLookupSource_V9(parser_context_t* c, pd_LookupasStaticLookupSource_V9_t* v);
parser_error_t _readMemberCount_V9(parser_context_t* c, pd_MemberCount_V9_t* v);
parser_error_t _readMultiSignature_V9(parser_context_t* c, pd_MultiSignature_V9_t* v);
parser_error_t _readMultiSigner_V9(parser_context_t* c, pd_MultiSigner_V9_t* v);
parser_error_t _readOpaqueCall_V9(parser_context_t* c, pd_OpaqueCall_V9_t* v);
parser_error_t _readOptionAccountId_V9(parser_context_t* c, pd_OptionAccountId_V9_t* v);
parser_error_t _readOptionMultiSignature_V9(parser_context_t* c, pd_OptionMultiSignature_V9_t* v);
parser_error_t _readOptionMultiSigner_V9(parser_context_t* c, pd_OptionMultiSigner_V9_t* v);
parser_error_t _readOptionProxyType_V9(parser_context_t* c, pd_OptionProxyType_V9_t* v);
parser_error_t _readOptionTimepoint_V9(parser_context_t* c, pd_OptionTimepoint_V9_t* v);
parser_error_t _readParaId_V9(parser_context_t* c, pd_ParaId_V9_t* v);
parser_error_t _readPerbill_V9(parser_context_t* c, pd_Perbill_V9_t* v);
parser_error_t _readProxyType_V9(parser_context_t* c, pd_ProxyType_V9_t* v);
parser_error_t _readReferendumIndex_V9(parser_context_t* c, pd_ReferendumIndex_V9_t* v);
parser_error_t _readRegistrarIndex_V9(parser_context_t* c, pd_RegistrarIndex_V9_t* v);
parser_error_t _readRewardDestination_V9(parser_context_t* c, pd_RewardDestination_V9_t* v);
parser_error_t _readSessionIndex_V9(parser_context_t* c, pd_SessionIndex_V9_t* v);
parser_error_t _readSr25519Public_V9(parser_context_t* c, pd_Sr25519Public_V9_t* v);
parser_error_t _readSr25519Signature_V9(parser_context_t* c, pd_Sr25519Signature_V9_t* v);
parser_error_t _readTimepoint_V9(parser_context_t* c, pd_Timepoint_V9_t* v);
parser_error_t _readValidatorPrefs_V9(parser_context_t* c, pd_ValidatorPrefs_V9_t* v);
parser_error_t _readVecAccountId_V9(parser_context_t* c, pd_VecAccountId_V9_t* v);
parser_error_t _readVecLookupasStaticLookupSource_V9(parser_context_t* c, pd_VecLookupasStaticLookupSource_V9_t* v);
parser_error_t _readVestingInfo_V9(parser_context_t* c, pd_VestingInfo_V9_t* v);
parser_error_t _readVote_V9(parser_context_t* c, pd_Vote_V9_t* v);

// toString functions
parser_error_t _toStringAccountId_V9(
    const pd_AccountId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIdLookupOfT_V9(
    const pd_AccountIdLookupOfT_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V9(
    const pd_AccountIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteSplit_V9(
    const pd_AccountVoteSplit_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteStandard_V9(
    const pd_AccountVoteStandard_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVote_V9(
    const pd_AccountVote_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V9(
    const pd_CompactAccountIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V9(
    const pd_CompactPerBill_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V9(
    const pd_Conviction_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaPublic_V9(
    const pd_EcdsaPublic_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V9(
    const pd_EcdsaSignature_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEd25519Public_V9(
    const pd_Ed25519Public_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEd25519Signature_V9(
    const pd_Ed25519Signature_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V9(
    const pd_EraIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V9(
    const pd_EthereumAddress_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V9(
    const pd_Keys_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V9(
    const pd_LookupasStaticLookupSource_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V9(
    const pd_MemberCount_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSignature_V9(
    const pd_MultiSignature_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSigner_V9(
    const pd_MultiSigner_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V9(
    const pd_OpaqueCall_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V9(
    const pd_OptionAccountId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSignature_V9(
    const pd_OptionMultiSignature_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSigner_V9(
    const pd_OptionMultiSigner_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V9(
    const pd_OptionProxyType_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V9(
    const pd_OptionTimepoint_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParaId_V9(
    const pd_ParaId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V9(
    const pd_Perbill_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V9(
    const pd_ProxyType_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V9(
    const pd_ReferendumIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V9(
    const pd_RegistrarIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V9(
    const pd_RewardDestination_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSessionIndex_V9(
    const pd_SessionIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSr25519Public_V9(
    const pd_Sr25519Public_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSr25519Signature_V9(
    const pd_Sr25519Signature_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V9(
    const pd_Timepoint_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V9(
    const pd_ValidatorPrefs_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V9(
    const pd_VecAccountId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupasStaticLookupSource_V9(
    const pd_VecLookupasStaticLookupSource_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingInfo_V9(
    const pd_VestingInfo_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVote_V9(
    const pd_Vote_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
