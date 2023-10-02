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
#include "substrate_methods_V10.h"
#include "substrate_types_V10.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V10(parser_context_t* c, pd_AccountId_V10_t* v);
parser_error_t _readAccountIdLookupOfT_V10(parser_context_t* c, pd_AccountIdLookupOfT_V10_t* v);
parser_error_t _readAccountIndex_V10(parser_context_t* c, pd_AccountIndex_V10_t* v);
parser_error_t _readAccountVoteSplit_V10(parser_context_t* c, pd_AccountVoteSplit_V10_t* v);
parser_error_t _readAccountVoteStandard_V10(parser_context_t* c, pd_AccountVoteStandard_V10_t* v);
parser_error_t _readAccountVote_V10(parser_context_t* c, pd_AccountVote_V10_t* v);
parser_error_t _readCompactAccountIndex_V10(parser_context_t* c, pd_CompactAccountIndex_V10_t* v);
parser_error_t _readCompactPerBill_V10(parser_context_t* c, pd_CompactPerBill_V10_t* v);
parser_error_t _readConviction_V10(parser_context_t* c, pd_Conviction_V10_t* v);
parser_error_t _readEcdsaPublic_V10(parser_context_t* c, pd_EcdsaPublic_V10_t* v);
parser_error_t _readEcdsaSignature_V10(parser_context_t* c, pd_EcdsaSignature_V10_t* v);
parser_error_t _readEd25519Public_V10(parser_context_t* c, pd_Ed25519Public_V10_t* v);
parser_error_t _readEd25519Signature_V10(parser_context_t* c, pd_Ed25519Signature_V10_t* v);
parser_error_t _readEraIndex_V10(parser_context_t* c, pd_EraIndex_V10_t* v);
parser_error_t _readEthereumAddress_V10(parser_context_t* c, pd_EthereumAddress_V10_t* v);
parser_error_t _readKeys_V10(parser_context_t* c, pd_Keys_V10_t* v);
parser_error_t _readLookupasStaticLookupSource_V10(parser_context_t* c, pd_LookupasStaticLookupSource_V10_t* v);
parser_error_t _readMemberCount_V10(parser_context_t* c, pd_MemberCount_V10_t* v);
parser_error_t _readMultiSignature_V10(parser_context_t* c, pd_MultiSignature_V10_t* v);
parser_error_t _readMultiSigner_V10(parser_context_t* c, pd_MultiSigner_V10_t* v);
parser_error_t _readOpaqueCall_V10(parser_context_t* c, pd_OpaqueCall_V10_t* v);
parser_error_t _readOptionAccountId_V10(parser_context_t* c, pd_OptionAccountId_V10_t* v);
parser_error_t _readOptionMultiSignature_V10(parser_context_t* c, pd_OptionMultiSignature_V10_t* v);
parser_error_t _readOptionMultiSigner_V10(parser_context_t* c, pd_OptionMultiSigner_V10_t* v);
parser_error_t _readOptionProxyType_V10(parser_context_t* c, pd_OptionProxyType_V10_t* v);
parser_error_t _readOptionTimepoint_V10(parser_context_t* c, pd_OptionTimepoint_V10_t* v);
parser_error_t _readParaId_V10(parser_context_t* c, pd_ParaId_V10_t* v);
parser_error_t _readPerbill_V10(parser_context_t* c, pd_Perbill_V10_t* v);
parser_error_t _readProxyType_V10(parser_context_t* c, pd_ProxyType_V10_t* v);
parser_error_t _readReferendumIndex_V10(parser_context_t* c, pd_ReferendumIndex_V10_t* v);
parser_error_t _readRegistrarIndex_V10(parser_context_t* c, pd_RegistrarIndex_V10_t* v);
parser_error_t _readRewardDestination_V10(parser_context_t* c, pd_RewardDestination_V10_t* v);
parser_error_t _readSessionIndex_V10(parser_context_t* c, pd_SessionIndex_V10_t* v);
parser_error_t _readSr25519Public_V10(parser_context_t* c, pd_Sr25519Public_V10_t* v);
parser_error_t _readSr25519Signature_V10(parser_context_t* c, pd_Sr25519Signature_V10_t* v);
parser_error_t _readTimepoint_V10(parser_context_t* c, pd_Timepoint_V10_t* v);
parser_error_t _readValidatorPrefs_V10(parser_context_t* c, pd_ValidatorPrefs_V10_t* v);
parser_error_t _readVecAccountId_V10(parser_context_t* c, pd_VecAccountId_V10_t* v);
parser_error_t _readVecLookupasStaticLookupSource_V10(parser_context_t* c, pd_VecLookupasStaticLookupSource_V10_t* v);
parser_error_t _readVestingInfo_V10(parser_context_t* c, pd_VestingInfo_V10_t* v);
parser_error_t _readVote_V10(parser_context_t* c, pd_Vote_V10_t* v);

// toString functions
parser_error_t _toStringAccountId_V10(
    const pd_AccountId_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIdLookupOfT_V10(
    const pd_AccountIdLookupOfT_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V10(
    const pd_AccountIndex_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteSplit_V10(
    const pd_AccountVoteSplit_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteStandard_V10(
    const pd_AccountVoteStandard_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVote_V10(
    const pd_AccountVote_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V10(
    const pd_CompactAccountIndex_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V10(
    const pd_CompactPerBill_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V10(
    const pd_Conviction_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaPublic_V10(
    const pd_EcdsaPublic_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V10(
    const pd_EcdsaSignature_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEd25519Public_V10(
    const pd_Ed25519Public_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEd25519Signature_V10(
    const pd_Ed25519Signature_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V10(
    const pd_EraIndex_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V10(
    const pd_EthereumAddress_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V10(
    const pd_Keys_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V10(
    const pd_LookupasStaticLookupSource_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V10(
    const pd_MemberCount_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSignature_V10(
    const pd_MultiSignature_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSigner_V10(
    const pd_MultiSigner_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V10(
    const pd_OpaqueCall_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V10(
    const pd_OptionAccountId_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSignature_V10(
    const pd_OptionMultiSignature_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSigner_V10(
    const pd_OptionMultiSigner_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V10(
    const pd_OptionProxyType_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V10(
    const pd_OptionTimepoint_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParaId_V10(
    const pd_ParaId_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V10(
    const pd_Perbill_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V10(
    const pd_ProxyType_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V10(
    const pd_ReferendumIndex_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V10(
    const pd_RegistrarIndex_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V10(
    const pd_RewardDestination_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSessionIndex_V10(
    const pd_SessionIndex_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSr25519Public_V10(
    const pd_Sr25519Public_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSr25519Signature_V10(
    const pd_Sr25519Signature_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V10(
    const pd_Timepoint_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V10(
    const pd_ValidatorPrefs_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V10(
    const pd_VecAccountId_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupasStaticLookupSource_V10(
    const pd_VecLookupasStaticLookupSource_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingInfo_V10(
    const pd_VestingInfo_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVote_V10(
    const pd_Vote_V10_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
