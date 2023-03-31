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

#include "substrate_dispatch_V9.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_balances_transfer_V9(
    parser_context_t* c, pd_balances_transfer_V9_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V9(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V9(
    parser_context_t* c, pd_balances_force_transfer_V9_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V9(c, &m->source))
    CHECK_ERROR(_readLookupasStaticLookupSource_V9(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V9(
    parser_context_t* c, pd_balances_transfer_keep_alive_V9_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V9(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V9(
    parser_context_t* c, pd_balances_transfer_all_V9_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V9(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V9(
    parser_context_t* c, pd_staking_bond_V9_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V9(c, &m->controller))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readRewardDestination_V9(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V9(
    parser_context_t* c, pd_staking_bond_extra_V9_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V9(
    parser_context_t* c, pd_staking_unbond_V9_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V9(
    parser_context_t* c, pd_staking_withdraw_unbonded_V9_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V9(
    parser_context_t* c, pd_staking_validate_V9_t* m)
{
    CHECK_ERROR(_readValidatorPrefs_V9(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V9(
    parser_context_t* c, pd_staking_nominate_V9_t* m)
{
    CHECK_ERROR(_readVecLookupasStaticLookupSource_V9(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V9(
    parser_context_t* c, pd_staking_chill_V9_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V9(
    parser_context_t* c, pd_staking_set_payee_V9_t* m)
{
    CHECK_ERROR(_readRewardDestination_V9(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V9(
    parser_context_t* c, pd_staking_set_controller_V9_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V9(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V9(
    parser_context_t* c, pd_staking_payout_stakers_V9_t* m)
{
    CHECK_ERROR(_readAccountId_V9(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex_V9(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V9(
    parser_context_t* c, pd_staking_rebond_V9_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V9(
    parser_context_t* c, pd_session_set_keys_V9_t* m)
{
    CHECK_ERROR(_readKeys_V9(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V9(
    parser_context_t* c, pd_session_purge_keys_V9_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V9(
    parser_context_t* c, pd_utility_batch_V9_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V9(
    parser_context_t* c, pd_utility_batch_all_V9_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_force_batch_V9(
    parser_context_t* c, pd_utility_force_batch_V9_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
__Z_INLINE parser_error_t _readMethod_system_fill_block_V9(
    parser_context_t* c, pd_system_fill_block_V9_t* m)
{
    CHECK_ERROR(_readPerbill_V9(c, &m->ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V9(
    parser_context_t* c, pd_system_remark_V9_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V9(
    parser_context_t* c, pd_system_set_heap_pages_V9_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V9(
    parser_context_t* c, pd_system_set_code_V9_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V9(
    parser_context_t* c, pd_system_set_code_without_checks_V9_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V9(
    parser_context_t* c, pd_system_remark_with_event_V9_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_note_preimage_V9(
    parser_context_t* c, pd_preimage_note_preimage_V9_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->bytes))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_unnote_preimage_V9(
    parser_context_t* c, pd_preimage_unnote_preimage_V9_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_request_preimage_V9(
    parser_context_t* c, pd_preimage_request_preimage_V9_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_unrequest_preimage_V9(
    parser_context_t* c, pd_preimage_unrequest_preimage_V9_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V9(
    parser_context_t* c, pd_timestamp_set_V9_t* m)
{
    CHECK_ERROR(_readCompactu64(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_claim_V9(
    parser_context_t* c, pd_indices_claim_V9_t* m)
{
    CHECK_ERROR(_readAccountIndex_V9(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_transfer_V9(
    parser_context_t* c, pd_indices_transfer_V9_t* m)
{
    CHECK_ERROR(_readAccountId_V9(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V9(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_free_V9(
    parser_context_t* c, pd_indices_free_V9_t* m)
{
    CHECK_ERROR(_readAccountIndex_V9(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_force_transfer_V9(
    parser_context_t* c, pd_indices_force_transfer_V9_t* m)
{
    CHECK_ERROR(_readAccountId_V9(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V9(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->freeze))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_freeze_V9(
    parser_context_t* c, pd_indices_freeze_V9_t* m)
{
    CHECK_ERROR(_readAccountIndex_V9(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V9(
    parser_context_t* c, pd_balances_set_balance_V9_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V9(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V9(
    parser_context_t* c, pd_balances_force_unreserve_V9_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V9(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V9(
    parser_context_t* c, pd_staking_set_validator_count_V9_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V9(
    parser_context_t* c, pd_staking_increase_validator_count_V9_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V9(
    parser_context_t* c, pd_staking_force_no_eras_V9_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V9(
    parser_context_t* c, pd_staking_force_new_era_V9_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V9(
    parser_context_t* c, pd_staking_set_invulnerables_V9_t* m)
{
    CHECK_ERROR(_readVecAccountId_V9(c, &m->invulnerables))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V9(
    parser_context_t* c, pd_staking_force_unstake_V9_t* m)
{
    CHECK_ERROR(_readAccountId_V9(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V9(
    parser_context_t* c, pd_staking_force_new_era_always_V9_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V9(
    parser_context_t* c, pd_staking_cancel_deferred_slash_V9_t* m)
{
    CHECK_ERROR(_readEraIndex_V9(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_history_depth_V9(
    parser_context_t* c, pd_staking_set_history_depth_V9_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_history_depth))
    CHECK_ERROR(_readCompactu32(c, &m->era_items_deleted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V9(
    parser_context_t* c, pd_staking_reap_stash_V9_t* m)
{
    CHECK_ERROR(_readAccountId_V9(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_kick_V9(
    parser_context_t* c, pd_staking_kick_V9_t* m)
{
    CHECK_ERROR(_readVecLookupasStaticLookupSource_V9(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_other_V9(
    parser_context_t* c, pd_staking_chill_other_V9_t* m)
{
    CHECK_ERROR(_readAccountId_V9(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_apply_min_commission_V9(
    parser_context_t* c, pd_staking_force_apply_min_commission_V9_t* m)
{
    CHECK_ERROR(_readAccountId_V9(c, &m->validator_stash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_set_key_V9(
     parser_context_t* c, pd_sudo_set_key_V9_t* m)
 {
     CHECK_ERROR(_readLookupasStaticLookupSource_V9(c, &m->new_))
     return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_V9(
     parser_context_t* c, pd_sudo_sudo_V9_t* m)
 {
     CHECK_ERROR(_readCall(c, &m->call))
     return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_unchecked_weight_V9(
     parser_context_t* c, pd_sudo_sudo_unchecked_weight_V9_t* m)
 {
     CHECK_ERROR(_readCall(c, &m->call))
     CHECK_ERROR(_readWeight(c, &m->weight))
     return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_note_stalled_V9(
    parser_context_t* c, pd_grandpa_note_stalled_V9_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readBlockNumber(c, &m->best_finalized_block_number))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_set_members_V9(
    parser_context_t* c, pd_council_set_members_V9_t* m)
{
    CHECK_ERROR(_readVecAccountId_V9(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V9(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V9(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_execute_V9(
    parser_context_t* c, pd_council_execute_V9_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_propose_V9(
    parser_context_t* c, pd_council_propose_V9_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_vote_V9(
    parser_context_t* c, pd_council_vote_V9_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_close_old_weight_V9(
    parser_context_t* c, pd_council_close_old_weight_V9_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu64(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_disapprove_proposal_V9(
    parser_context_t* c, pd_council_disapprove_proposal_V9_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_close_V9(
    parser_context_t* c, pd_council_close_V9_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readWeight(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_members_V9(
    parser_context_t* c, pd_technicalcommittee_set_members_V9_t* m)
{
    CHECK_ERROR(_readVecAccountId_V9(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V9(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V9(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_execute_V9(
    parser_context_t* c, pd_technicalcommittee_execute_V9_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_propose_V9(
    parser_context_t* c, pd_technicalcommittee_propose_V9_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_V9(
    parser_context_t* c, pd_technicalcommittee_vote_V9_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_close_V9(
    parser_context_t* c, pd_technicalcommittee_close_V9_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readWeight(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_disapprove_proposal_V9(
    parser_context_t* c, pd_technicalcommittee_disapprove_proposal_V9_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_propose_spend_V9(
    parser_context_t* c, pd_treasury_propose_spend_V9_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readLookupasStaticLookupSource_V9(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reject_proposal_V9(
    parser_context_t* c, pd_treasury_reject_proposal_V9_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_approve_proposal_V9(
    parser_context_t* c, pd_treasury_approve_proposal_V9_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_spend_V9(
    parser_context_t* c, pd_treasury_spend_V9_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readLookupasStaticLookupSource_V9(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_remove_approval_V9(
    parser_context_t* c, pd_treasury_remove_approval_V9_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_V9(
    parser_context_t* c, pd_vesting_vest_V9_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_other_V9(
    parser_context_t* c, pd_vesting_vest_other_V9_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V9(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vested_transfer_V9(
    parser_context_t* c, pd_vesting_vested_transfer_V9_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V9(c, &m->target))
    CHECK_ERROR(_readVestingInfo_V9(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_force_vested_transfer_V9(
    parser_context_t* c, pd_vesting_force_vested_transfer_V9_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V9(c, &m->source))
    CHECK_ERROR(_readLookupasStaticLookupSource_V9(c, &m->target))
    CHECK_ERROR(_readVestingInfo_V9(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_merge_schedules_V9(
    parser_context_t* c, pd_vesting_merge_schedules_V9_t* m)
{
    CHECK_ERROR(_readu32(c, &m->schedule1_index))
    CHECK_ERROR(_readu32(c, &m->schedule2_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_registrar_V9(
    parser_context_t* c, pd_identity_add_registrar_V9_t* m)
{
    CHECK_ERROR(_readAccountId_V9(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_clear_identity_V9(
    parser_context_t* c, pd_identity_clear_identity_V9_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_request_judgement_V9(
    parser_context_t* c, pd_identity_request_judgement_V9_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->reg_index))
    CHECK_ERROR(_readCompactu128(c, &m->max_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cancel_request_V9(
    parser_context_t* c, pd_identity_cancel_request_V9_t* m)
{
    CHECK_ERROR(_readRegistrarIndex_V9(c, &m->reg_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fee_V9(
    parser_context_t* c, pd_identity_set_fee_V9_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu128(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_account_id_V9(
    parser_context_t* c, pd_identity_set_account_id_V9_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readAccountId_V9(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_kill_identity_V9(
    parser_context_t* c, pd_identity_kill_identity_V9_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V9(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_sub_V9(
    parser_context_t* c, pd_identity_remove_sub_V9_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V9(c, &m->sub))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_quit_sub_V9(
    parser_context_t* c, pd_identity_quit_sub_V9_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_V9(
    parser_context_t* c, pd_proxy_proxy_V9_t* m)
{
    CHECK_ERROR(_readAccountId_V9(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V9(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_add_proxy_V9(
    parser_context_t* c, pd_proxy_add_proxy_V9_t* m)
{
    CHECK_ERROR(_readAccountId_V9(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V9(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxy_V9(
    parser_context_t* c, pd_proxy_remove_proxy_V9_t* m)
{
    CHECK_ERROR(_readAccountId_V9(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V9(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxies_V9(
    parser_context_t* c, pd_proxy_remove_proxies_V9_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_anonymous_V9(
    parser_context_t* c, pd_proxy_anonymous_V9_t* m)
{
    CHECK_ERROR(_readProxyType_V9(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readu16(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_kill_anonymous_V9(
    parser_context_t* c, pd_proxy_kill_anonymous_V9_t* m)
{
    CHECK_ERROR(_readAccountId_V9(c, &m->spawner))
    CHECK_ERROR(_readProxyType_V9(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCompactu32(c, &m->height))
    CHECK_ERROR(_readCompactu32(c, &m->ext_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_announced_V9(
    parser_context_t* c, pd_proxy_proxy_announced_V9_t* m)
{
    CHECK_ERROR(_readAccountId_V9(c, &m->delegate))
    CHECK_ERROR(_readAccountId_V9(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V9(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V9(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V9_t* m)
{
    CHECK_ERROR(_readVecAccountId_V9(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V9(
    parser_context_t* c, pd_multisig_as_multi_V9_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V9(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V9(c, &m->maybe_timepoint))
    CHECK_ERROR(_readOpaqueCall_V9(c, &m->call))
    CHECK_ERROR(_readbool(c, &m->store_call))
    CHECK_ERROR(_readWeight(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V9(
    parser_context_t* c, pd_multisig_approve_as_multi_V9_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V9(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V9(c, &m->maybe_timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    CHECK_ERROR(_readWeight(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V9(
    parser_context_t* c, pd_multisig_cancel_as_multi_V9_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V9(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint_V9(c, &m->timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionprovidermultiphase_governance_fallback_V9(
    parser_context_t* c, pd_electionprovidermultiphase_governance_fallback_V9_t* m)
{
    CHECK_ERROR(_readOptionu32(c, &m->maybe_max_voters))
    CHECK_ERROR(_readOptionu32(c, &m->maybe_max_targets))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V9(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V9_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 1280: /* module 5 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V9(c, &method->nested.balances_transfer_V9))
        break;
    case 1282: /* module 5 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V9(c, &method->nested.balances_force_transfer_V9))
        break;
    case 1283: /* module 5 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V9(c, &method->nested.balances_transfer_keep_alive_V9))
        break;
    case 1284: /* module 5 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V9(c, &method->basic.balances_transfer_all_V9))
        break;
    case 1792: /* module 7 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V9(c, &method->basic.staking_bond_V9))
        break;
    case 1793: /* module 7 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V9(c, &method->basic.staking_bond_extra_V9))
        break;
    case 1794: /* module 7 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V9(c, &method->basic.staking_unbond_V9))
        break;
    case 1795: /* module 7 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V9(c, &method->basic.staking_withdraw_unbonded_V9))
        break;
    case 1796: /* module 7 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V9(c, &method->basic.staking_validate_V9))
        break;
    case 1797: /* module 7 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V9(c, &method->basic.staking_nominate_V9))
        break;
    case 1798: /* module 7 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V9(c, &method->basic.staking_chill_V9))
        break;
    case 1799: /* module 7 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V9(c, &method->basic.staking_set_payee_V9))
        break;
    case 1800: /* module 7 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V9(c, &method->basic.staking_set_controller_V9))
        break;
    case 1810: /* module 7 call 18 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V9(c, &method->basic.staking_payout_stakers_V9))
        break;
    case 1811: /* module 7 call 19 */
        CHECK_ERROR(_readMethod_staking_rebond_V9(c, &method->basic.staking_rebond_V9))
        break;
    case 2304: /* module 9 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V9(c, &method->basic.session_set_keys_V9))
        break;
    case 2305: /* module 9 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V9(c, &method->basic.session_purge_keys_V9))
        break;
    case 6656: /* module 26 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V9(c, &method->basic.utility_batch_V9))
        break;
    case 6658: /* module 26 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V9(c, &method->basic.utility_batch_all_V9))
        break;
    case 6660: /* module 26 call 4 */
        CHECK_ERROR(_readMethod_utility_force_batch_V9(c, &method->basic.utility_force_batch_V9))
        break;

#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V9(c, &method->nested.system_fill_block_V9))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V9(c, &method->nested.system_remark_V9))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V9(c, &method->nested.system_set_heap_pages_V9))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V9(c, &method->nested.system_set_code_V9))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V9(c, &method->nested.system_set_code_without_checks_V9))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_remark_with_event_V9(c, &method->nested.system_remark_with_event_V9))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V9(c, &method->basic.timestamp_set_V9))
        break;
    case 1024: /* module 4 call 0 */
        CHECK_ERROR(_readMethod_indices_claim_V9(c, &method->basic.indices_claim_V9))
        break;
    case 1025: /* module 4 call 1 */
        CHECK_ERROR(_readMethod_indices_transfer_V9(c, &method->basic.indices_transfer_V9))
        break;
    case 1026: /* module 4 call 2 */
        CHECK_ERROR(_readMethod_indices_free_V9(c, &method->basic.indices_free_V9))
        break;
    case 1027: /* module 4 call 3 */
        CHECK_ERROR(_readMethod_indices_force_transfer_V9(c, &method->basic.indices_force_transfer_V9))
        break;
    case 1028: /* module 4 call 4 */
        CHECK_ERROR(_readMethod_indices_freeze_V9(c, &method->basic.indices_freeze_V9))
        break;
    case 1281: /* module 5 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V9(c, &method->nested.balances_set_balance_V9))
        break;
    case 1285: /* module 5 call 5 */
        CHECK_ERROR(_readMethod_balances_force_unreserve_V9(c, &method->basic.balances_force_unreserve_V9))
        break;
    case 1801: /* module 7 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V9(c, &method->basic.staking_set_validator_count_V9))
        break;
    case 1802: /* module 7 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V9(c, &method->basic.staking_increase_validator_count_V9))
        break;
    case 1804: /* module 7 call 12 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V9(c, &method->basic.staking_force_no_eras_V9))
        break;
    case 1805: /* module 7 call 13 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V9(c, &method->basic.staking_force_new_era_V9))
        break;
    case 1806: /* module 7 call 14 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V9(c, &method->basic.staking_set_invulnerables_V9))
        break;
    case 1807: /* module 7 call 15 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V9(c, &method->basic.staking_force_unstake_V9))
        break;
    case 1808: /* module 7 call 16 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V9(c, &method->basic.staking_force_new_era_always_V9))
        break;
    case 1809: /* module 7 call 17 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V9(c, &method->basic.staking_cancel_deferred_slash_V9))
        break;
    case 1812: /* module 7 call 20 */
        CHECK_ERROR(_readMethod_staking_set_history_depth_V9(c, &method->basic.staking_set_history_depth_V9))
        break;
    case 1813: /* module 7 call 21 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V9(c, &method->basic.staking_reap_stash_V9))
        break;
    case 1814: /* module 7 call 22 */
        CHECK_ERROR(_readMethod_staking_kick_V9(c, &method->basic.staking_kick_V9))
        break;
    case 1816: /* module 7 call 24 */
        CHECK_ERROR(_readMethod_staking_chill_other_V9(c, &method->basic.staking_chill_other_V9))
        break;
    case 1817: /* module 7 call 25 */
        CHECK_ERROR(_readMethod_staking_force_apply_min_commission_V9(c, &method->basic.staking_force_apply_min_commission_V9))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_sudo_sudo_V9(c, &method->basic.sudo_sudo_V9))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_sudo_sudo_unchecked_weight_V9(c, &method->basic.sudo_sudo_unchecked_weight_V9))
        break;
    case 2562: /* module 10 call 2 */
        CHECK_ERROR(_readMethod_sudo_set_key_V9(c, &method->basic.sudo_set_key_V9))
        break;
    case 2818: /* module 11 call 2 */
        CHECK_ERROR(_readMethod_grandpa_note_stalled_V9(c, &method->basic.grandpa_note_stalled_V9))
        break;
    case 3840: /* module 15 call 0 */
        CHECK_ERROR(_readMethod_council_set_members_V9(c, &method->basic.council_set_members_V9))
        break;
    case 3841: /* module 15 call 1 */
        CHECK_ERROR(_readMethod_council_execute_V9(c, &method->basic.council_execute_V9))
        break;
    case 3842: /* module 15 call 2 */
        CHECK_ERROR(_readMethod_council_propose_V9(c, &method->basic.council_propose_V9))
        break;
    case 3843: /* module 15 call 3 */
        CHECK_ERROR(_readMethod_council_vote_V9(c, &method->basic.council_vote_V9))
        break;
    case 3844: /* module 15 call 4 */
        CHECK_ERROR(_readMethod_council_close_old_weight_V9(c, &method->basic.council_close_old_weight_V9))
        break;
    case 3845: /* module 15 call 5 */
        CHECK_ERROR(_readMethod_council_disapprove_proposal_V9(c, &method->basic.council_disapprove_proposal_V9))
        break;
    case 3846: /* module 15 call 6 */
        CHECK_ERROR(_readMethod_council_close_V9(c, &method->basic.council_close_V9))
        break;
    case 4096: /* module 16 call 0 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_members_V9(c, &method->basic.technicalcommittee_set_members_V9))
        break;
    case 4097: /* module 16 call 1 */
        CHECK_ERROR(_readMethod_technicalcommittee_execute_V9(c, &method->basic.technicalcommittee_execute_V9))
        break;
    case 4098: /* module 16 call 2 */
        CHECK_ERROR(_readMethod_technicalcommittee_propose_V9(c, &method->basic.technicalcommittee_propose_V9))
        break;
    case 4099: /* module 16 call 3 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_V9(c, &method->basic.technicalcommittee_vote_V9))
        break;
    case 4101: /* module 16 call 5 */
        CHECK_ERROR(_readMethod_technicalcommittee_disapprove_proposal_V9(c, &method->basic.technicalcommittee_disapprove_proposal_V9))
        break;
    case 4102: /* module 16 call 6 */
        CHECK_ERROR(_readMethod_technicalcommittee_close_V9(c, &method->basic.technicalcommittee_close_V9))
        break;
    case 4864: /* module 19 call 0 */
        CHECK_ERROR(_readMethod_treasury_propose_spend_V9(c, &method->basic.treasury_propose_spend_V9))
        break;
    case 4865: /* module 19 call 1 */
        CHECK_ERROR(_readMethod_treasury_reject_proposal_V9(c, &method->basic.treasury_reject_proposal_V9))
        break;
    case 4866: /* module 19 call 2 */
        CHECK_ERROR(_readMethod_treasury_approve_proposal_V9(c, &method->basic.treasury_approve_proposal_V9))
        break;
    case 4867: /* module 19 call 3 */
        CHECK_ERROR(_readMethod_treasury_spend_V9(c, &method->basic.treasury_spend_V9))
        break;
    case 4868: /* module 19 call 4 */
        CHECK_ERROR(_readMethod_treasury_remove_approval_V9(c, &method->basic.treasury_remove_approval_V9))
        break;
    case 6400: /* module 25 call 0 */
        CHECK_ERROR(_readMethod_vesting_vest_V9(c, &method->basic.vesting_vest_V9))
        break;
    case 6401: /* module 25 call 1 */
        CHECK_ERROR(_readMethod_vesting_vest_other_V9(c, &method->basic.vesting_vest_other_V9))
        break;
    case 6402: /* module 25 call 2 */
        CHECK_ERROR(_readMethod_vesting_vested_transfer_V9(c, &method->basic.vesting_vested_transfer_V9))
        break;
    case 6403: /* module 25 call 3 */
        CHECK_ERROR(_readMethod_vesting_force_vested_transfer_V9(c, &method->basic.vesting_force_vested_transfer_V9))
        break;
    case 6404: /* module 25 call 4 */
        CHECK_ERROR(_readMethod_vesting_merge_schedules_V9(c, &method->basic.vesting_merge_schedules_V9))
        break;
    case 7168: /* module 28 call 0 */
        CHECK_ERROR(_readMethod_identity_add_registrar_V9(c, &method->basic.identity_add_registrar_V9))
        break;
    case 7171: /* module 28 call 3 */
        CHECK_ERROR(_readMethod_identity_clear_identity_V9(c, &method->basic.identity_clear_identity_V9))
        break;
    case 7172: /* module 28 call 4 */
        CHECK_ERROR(_readMethod_identity_request_judgement_V9(c, &method->basic.identity_request_judgement_V9))
        break;
    case 7173: /* module 28 call 5 */
        CHECK_ERROR(_readMethod_identity_cancel_request_V9(c, &method->basic.identity_cancel_request_V9))
        break;
    case 7174: /* module 28 call 6 */
        CHECK_ERROR(_readMethod_identity_set_fee_V9(c, &method->basic.identity_set_fee_V9))
        break;
    case 7175: /* module 28 call 7 */
        CHECK_ERROR(_readMethod_identity_set_account_id_V9(c, &method->basic.identity_set_account_id_V9))
        break;
    case 7178: /* module 28 call 10 */
        CHECK_ERROR(_readMethod_identity_kill_identity_V9(c, &method->basic.identity_kill_identity_V9))
        break;
    case 7181: /* module 28 call 13 */
        CHECK_ERROR(_readMethod_identity_remove_sub_V9(c, &method->basic.identity_remove_sub_V9))
        break;
    case 7182: /* module 28 call 14 */
        CHECK_ERROR(_readMethod_identity_quit_sub_V9(c, &method->basic.identity_quit_sub_V9))
        break;
    case 7424: /* module 29 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V9(c, &method->nested.proxy_proxy_V9))
        break;
    case 7425: /* module 29 call 1 */
        CHECK_ERROR(_readMethod_proxy_add_proxy_V9(c, &method->basic.proxy_add_proxy_V9))
        break;
    case 7426: /* module 29 call 2 */
        CHECK_ERROR(_readMethod_proxy_remove_proxy_V9(c, &method->basic.proxy_remove_proxy_V9))
        break;
    case 7427: /* module 29 call 3 */
        CHECK_ERROR(_readMethod_proxy_remove_proxies_V9(c, &method->basic.proxy_remove_proxies_V9))
        break;
    case 7428: /* module 29 call 4 */
        CHECK_ERROR(_readMethod_proxy_anonymous_V9(c, &method->basic.proxy_anonymous_V9))
        break;
    case 7429: /* module 29 call 5 */
        CHECK_ERROR(_readMethod_proxy_kill_anonymous_V9(c, &method->basic.proxy_kill_anonymous_V9))
        break;
    case 7433: /* module 29 call 9 */
        CHECK_ERROR(_readMethod_proxy_proxy_announced_V9(c, &method->basic.proxy_proxy_announced_V9))
        break;
    case 7680: /* module 30 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V9(c, &method->nested.multisig_as_multi_threshold_1_V9))
        break;
    case 7681: /* module 30 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V9(c, &method->nested.multisig_as_multi_V9))
        break;
    case 7682: /* module 30 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V9(c, &method->nested.multisig_approve_as_multi_V9))
        break;
    case 7683: /* module 30 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V9(c, &method->nested.multisig_cancel_as_multi_V9))
        break;
    case 9220: /* module 36 call 4 */
        CHECK_ERROR(_readMethod_electionprovidermultiphase_governance_fallback_V9(c, &method->basic.electionprovidermultiphase_governance_fallback_V9))
        break;
    case 10240: /* module 40 call 0 */
        CHECK_ERROR(_readMethod_preimage_note_preimage_V9(c, &method->basic.preimage_note_preimage_V9))
        break;
    case 10241: /* module 40 call 1 */
        CHECK_ERROR(_readMethod_preimage_unnote_preimage_V9(c, &method->basic.preimage_unnote_preimage_V9))
        break;
    case 10242: /* module 40 call 2 */
        CHECK_ERROR(_readMethod_preimage_request_preimage_V9(c, &method->basic.preimage_request_preimage_V9))
        break;
    case 10243: /* module 40 call 3 */
        CHECK_ERROR(_readMethod_preimage_unrequest_preimage_V9(c, &method->basic.preimage_unrequest_preimage_V9))
        break;
#endif
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V9(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 5:
        return STR_MO_BALANCES;
    case 7:
        return STR_MO_STAKING;
    case 9:
        return STR_MO_SESSION;
    case 26:
        return STR_MO_UTILITY;
#ifdef SUBSTRATE_PARSER_FULL
    case 0:
        return STR_MO_SYSTEM;
    case 3:
        return STR_MO_TIMESTAMP;
    case 4:
        return STR_MO_INDICES;
    case 10:
        return STR_MO_SUDO;
    case 11:
        return STR_MO_GRANDPA;
    case 15:
        return STR_MO_COUNCIL;
    case 16:
        return STR_MO_TECHNICALCOMMITTEE;
    case 19:
        return STR_MO_TREASURY;
    case 25:
        return STR_MO_VESTING;
    case 28:
        return STR_MO_IDENTITY;
    case 29:
        return STR_MO_PROXY;
    case 30:
        return STR_MO_MULTISIG;
    case 36:
        return STR_MO_ELECTIONPROVIDERMULTIPHASE;
    case 37:
        return STR_MO_VOTERLIST;
    case 40:
        return STR_MO_PREIMAGE;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V9(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1280: /* module 5 call 0 */
        return STR_ME_TRANSFER;
    case 1282: /* module 5 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 1283: /* module 5 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 1284: /* module 5 call 4 */
        return STR_ME_TRANSFER_ALL;
    case 1792: /* module 7 call 0 */
        return STR_ME_BOND;
    case 1793: /* module 7 call 1 */
        return STR_ME_BOND_EXTRA;
    case 1794: /* module 7 call 2 */
        return STR_ME_UNBOND;
    case 1795: /* module 7 call 3 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 1796: /* module 7 call 4 */
        return STR_ME_VALIDATE;
    case 1797: /* module 7 call 5 */
        return STR_ME_NOMINATE;
    case 1798: /* module 7 call 6 */
        return STR_ME_CHILL;
    case 1799: /* module 7 call 7 */
        return STR_ME_SET_PAYEE;
    case 1800: /* module 7 call 8 */
        return STR_ME_SET_CONTROLLER;
    case 1810: /* module 7 call 18 */
        return STR_ME_PAYOUT_STAKERS;
    case 1811: /* module 7 call 19 */
        return STR_ME_REBOND;
    case 2304: /* module 9 call 0 */
        return STR_ME_SET_KEYS;
    case 2305: /* module 9 call 1 */
        return STR_ME_PURGE_KEYS;
    case 6656: /* module 26 call 0 */
        return STR_ME_BATCH;
    case 6658: /* module 26 call 2 */
        return STR_ME_BATCH_ALL;
    case 6660: /* module 26 call 4 */
        return STR_ME_FORCE_BATCH;
    case 18688: /* module 73 call 0 */
        return STR_ME_CREATE;
    case 18689: /* module 73 call 1 */
        return STR_ME_CONTRIBUTE;
    case 18690: /* module 73 call 2 */
        return STR_ME_WITHDRAW;
    case 18691: /* module 73 call 3 */
        return STR_ME_REFUND;
    case 18692: /* module 73 call 4 */
        return STR_ME_DISSOLVE;
    case 18693: /* module 73 call 5 */
        return STR_ME_EDIT;
    case 18694: /* module 73 call 6 */
        return STR_ME_ADD_MEMO;
    case 18695: /* module 73 call 7 */
        return STR_ME_POKE;
    case 18696: /* module 73 call 8 */
        return STR_ME_CONTRIBUTE_ALL;
    default:
        return _getMethod_Name_V9_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V9_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return STR_ME_FILL_BLOCK;
    case 1: /* module 0 call 1 */
        return STR_ME_REMARK;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_HEAP_PAGES;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE;
    case 4: /* module 0 call 4 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 8: /* module 0 call 8 */
        return STR_ME_REMARK_WITH_EVENT;
    case 10240: /* module 10 call 0 */
        return STR_ME_NOTE_PREIMAGE;
    case 10241: /* module 10 call 1 */
        return STR_ME_UNNOTE_PREIMAGE;
    case 10242: /* module 10 call 2 */
        return STR_ME_REQUEST_PREIMAGE;
    case 10243: /* module 10 call 3 */
        return STR_ME_UNREQUEST_PREIMAGE;
    case 768: /* module 3 call 0 */
        return STR_ME_SET;
    case 1024: /* module 4 call 0 */
        return STR_ME_CLAIM;
    case 1025: /* module 4 call 1 */
        return STR_ME_TRANSFER;
    case 1026: /* module 4 call 2 */
        return STR_ME_FREE;
    case 1027: /* module 4 call 3 */
        return STR_ME_FORCE_TRANSFER;
    case 1028: /* module 4 call 4 */
        return STR_ME_FREEZE;
    case 1281: /* module 5 call 1 */
        return STR_ME_SET_BALANCE;
    case 1285: /* module 5 call 5 */
        return STR_ME_FORCE_UNRESERVE;
    case 1801: /* module 7 call 9 */
        return STR_ME_SET_VALIDATOR_COUNT;
    case 1802: /* module 7 call 10 */
        return STR_ME_INCREASE_VALIDATOR_COUNT;
    case 1804: /* module 7 call 12 */
        return STR_ME_FORCE_NO_ERAS;
    case 1805: /* module 7 call 13 */
        return STR_ME_FORCE_NEW_ERA;
    case 1806: /* module 7 call 14 */
        return STR_ME_SET_INVULNERABLES;
    case 1807: /* module 7 call 15 */
        return STR_ME_FORCE_UNSTAKE;
    case 1808: /* module 7 call 16 */
        return STR_ME_FORCE_NEW_ERA_ALWAYS;
    case 1809: /* module 7 call 17 */
        return STR_ME_CANCEL_DEFERRED_SLASH;
    case 1812: /* module 7 call 20 */
        return STR_ME_SET_HISTORY_DEPTH;
    case 1813: /* module 7 call 21 */
        return STR_ME_REAP_STASH;
    case 1814: /* module 7 call 22 */
        return STR_ME_KICK;
    case 1816: /* module 7 call 24 */
        return STR_ME_CHILL_OTHER;
    case 1817: /* module 7 call 25 */
        return STR_ME_FORCE_APPLY_MIN_COMMISSION;
    case 2560: /* module 10 call 0 */
        return STR_ME_SUDO;
    case 2561: /* module 10 call 1 */
        return STR_ME_SUDO_UNCHECKED_WEIGHT;
    case 2562: /* module 10 call 2 */
        return STR_ME_SUDO_SET_KEY;
    case 2818: /* module 11 call 2 */
        return STR_ME_NOTE_STALLED;
    case 3584: /* module 14 call 0 */
        return STR_ME_PROPOSE;
    case 3585: /* module 14 call 1 */
        return STR_ME_SECOND;
    case 3586: /* module 14 call 2 */
        return STR_ME_VOTE;
    case 3587: /* module 14 call 3 */
        return STR_ME_EMERGENCY_CANCEL;
    case 3588: /* module 14 call 4 */
        return STR_ME_EXTERNAL_PROPOSE;
    case 3589: /* module 14 call 5 */
        return STR_ME_EXTERNAL_PROPOSE_MAJORITY;
    case 3590: /* module 14 call 6 */
        return STR_ME_EXTERNAL_PROPOSE_DEFAULT;
    case 3591: /* module 14 call 7 */
        return STR_ME_FAST_TRACK;
    case 3592: /* module 14 call 8 */
        return STR_ME_VETO_EXTERNAL;
    case 3593: /* module 14 call 9 */
        return STR_ME_CANCEL_REFERENDUM;
    case 3594: /* module 14 call 10 */
        return STR_ME_CANCEL_QUEUED;
    case 3595: /* module 14 call 11 */
        return STR_ME_DELEGATE;
    case 3596: /* module 14 call 12 */
        return STR_ME_UNDELEGATE;
    case 3597: /* module 14 call 13 */
        return STR_ME_CLEAR_PUBLIC_PROPOSALS;
    case 3598: /* module 14 call 14 */
        return STR_ME_NOTE_PREIMAGE;
    case 3599: /* module 14 call 15 */
        return STR_ME_NOTE_PREIMAGE_OPERATIONAL;
    case 3600: /* module 14 call 16 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE;
    case 3601: /* module 14 call 17 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE_OPERATIONAL;
    case 3602: /* module 14 call 18 */
        return STR_ME_REAP_PREIMAGE;
    case 3603: /* module 14 call 19 */
        return STR_ME_UNLOCK;
    case 3604: /* module 14 call 20 */
        return STR_ME_REMOVE_VOTE;
    case 3605: /* module 14 call 21 */
        return STR_ME_REMOVE_OTHER_VOTE;
    case 3606: /* module 14 call 22 */
        return STR_ME_ENACT_PROPOSAL;
    case 3608: /* module 14 call 24 */
        return STR_ME_CANCEL_PROPOSAL;
    case 3840: /* module 15 call 0 */
        return STR_ME_SET_MEMBERS;
    case 3841: /* module 15 call 1 */
        return STR_ME_EXECUTE;
    case 3842: /* module 15 call 2 */
        return STR_ME_PROPOSE;
    case 3843: /* module 15 call 3 */
        return STR_ME_VOTE;
    case 3844: /* module 15 call 4 */
        return STR_ME_CLOSE_OLD_WEIGHT;
    case 3845: /* module 15 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 3846: /* module 15 call 6 */
        return STR_ME_CLOSE;
    case 4096: /* module 16 call 0 */
        return STR_ME_SET_MEMBERS;
    case 4097: /* module 16 call 1 */
        return STR_ME_EXECUTE;
    case 4098: /* module 16 call 2 */
        return STR_ME_PROPOSE;
    case 4099: /* module 16 call 3 */
        return STR_ME_VOTE;
    case 4101: /* module 16 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 4102: /* module 16 call 6 */
        return STR_ME_CLOSE;
    case 4352: /* module 17 call 0 */
        return STR_ME_VOTE;
    case 4353: /* module 17 call 1 */
        return STR_ME_REMOVE_VOTER;
    case 4354: /* module 17 call 2 */
        return STR_ME_SUBMIT_CANDIDACY;
    case 4356: /* module 17 call 4 */
        return STR_ME_REMOVE_MEMBER;
    case 4357: /* module 17 call 5 */
        return STR_ME_CLEAN_DEFUNCT_VOTERS;
    case 4608: /* module 18 call 0 */
        return STR_ME_ADD_MEMBER;
    case 4609: /* module 18 call 1 */
        return STR_ME_REMOVE_MEMBER;
    case 4610: /* module 18 call 2 */
        return STR_ME_SWAP_MEMBER;
    case 4611: /* module 18 call 3 */
        return STR_ME_RESET_MEMBERS;
    case 4612: /* module 18 call 4 */
        return STR_ME_CHANGE_KEY;
    case 4613: /* module 18 call 5 */
        return STR_ME_SET_PRIME;
    case 4614: /* module 18 call 6 */
        return STR_ME_CLEAR_PRIME;
    case 4864: /* module 19 call 0 */
        return STR_ME_PROPOSE_SPEND;
    case 4865: /* module 19 call 1 */
        return STR_ME_REJECT_PROPOSAL;
    case 4866: /* module 19 call 2 */
        return STR_ME_APPROVE_PROPOSAL;
    case 4867: /* module 19 call 3 */
        return STR_ME_REMOVE_APPROVAL;
    case 6144: /* module 24 call 0 */
        return STR_ME_CLAIM;
    case 6146: /* module 24 call 2 */
        return STR_ME_CLAIM_ATTEST;
    case 6147: /* module 24 call 3 */
        return STR_ME_ATTEST;
    case 6148: /* module 24 call 4 */
        return STR_ME_MOVE_CLAIM;
    case 6400: /* module 25 call 0 */
        return STR_ME_VEST;
    case 6401: /* module 25 call 1 */
        return STR_ME_VEST_OTHER;
    case 6402: /* module 25 call 2 */
        return STR_ME_VESTED_TRANSFER;
    case 6403: /* module 25 call 3 */
        return STR_ME_FORCE_VESTED_TRANSFER;
    case 6404: /* module 25 call 4 */
        return STR_ME_MERGE_SCHEDULES;
    case 7168: /* module 28 call 0 */
        return STR_ME_ADD_REGISTRAR;
    case 7171: /* module 28 call 3 */
        return STR_ME_CLEAR_IDENTITY;
    case 7172: /* module 28 call 4 */
        return STR_ME_REQUEST_JUDGEMENT;
    case 7173: /* module 28 call 5 */
        return STR_ME_CANCEL_REQUEST;
    case 7174: /* module 28 call 6 */
        return STR_ME_SET_FEE;
    case 7175: /* module 28 call 7 */
        return STR_ME_SET_ACCOUNT_ID;
    case 7178: /* module 28 call 10 */
        return STR_ME_KILL_IDENTITY;
    case 7181: /* module 28 call 13 */
        return STR_ME_REMOVE_SUB;
    case 7182: /* module 28 call 14 */
        return STR_ME_QUIT_SUB;
    case 7424: /* module 29 call 0 */
        return STR_ME_PROXY;
    case 7425: /* module 29 call 1 */
        return STR_ME_ADD_PROXY;
    case 7426: /* module 29 call 2 */
        return STR_ME_REMOVE_PROXY;
    case 7427: /* module 29 call 3 */
        return STR_ME_REMOVE_PROXIES;
    case 7428: /* module 29 call 4 */
        return STR_ME_ANONYMOUS;
    case 7429: /* module 29 call 5 */
        return STR_ME_KILL_ANONYMOUS;
    case 7433: /* module 29 call 9 */
        return STR_ME_PROXY_ANNOUNCED;
    case 7680: /* module 30 call 0 */
        return STR_ME_AS_MULTI_THRESHOLD_1;
    case 7681: /* module 30 call 1 */
        return STR_ME_AS_MULTI;
    case 7682: /* module 30 call 2 */
        return STR_ME_APPROVE_AS_MULTI;
    case 7683: /* module 30 call 3 */
        return STR_ME_CANCEL_AS_MULTI;
    case 8704: /* module 34 call 0 */
        return STR_ME_PROPOSE_BOUNTY;
    case 8705: /* module 34 call 1 */
        return STR_ME_APPROVE_BOUNTY;
    case 8706: /* module 34 call 2 */
        return STR_ME_PROPOSE_CURATOR;
    case 8707: /* module 34 call 3 */
        return STR_ME_UNASSIGN_CURATOR;
    case 8708: /* module 34 call 4 */
        return STR_ME_ACCEPT_CURATOR;
    case 8709: /* module 34 call 5 */
        return STR_ME_AWARD_BOUNTY;
    case 8710: /* module 34 call 6 */
        return STR_ME_CLAIM_BOUNTY;
    case 8711: /* module 34 call 7 */
        return STR_ME_CLOSE_BOUNTY;
    case 8712: /* module 34 call 8 */
        return STR_ME_EXTEND_BOUNTY_EXPIRY;
    case 10496: /* module 41 call 0 */
        return STR_ME_ADD_CHILD_BOUNTY;
    case 10497: /* module 38 call 1 */
        return STR_ME_PROPOSE_CURATOR;
    case 10498: /* module 38 call 2 */
        return STR_ME_ACCEPT_CURATOR;
    case 10499: /* module 38 call 3 */
        return STR_ME_UNASSIGN_CURATOR;
    case 10500: /* module 38 call 4 */
        return STR_ME_AWARD_CHILD_BOUNTY;
    case 10501: /* module 38 call 5 */
        return STR_ME_CLAIM_CHILD_BOUNTY;
    case 10502: /* module 38 call 6 */
        return STR_ME_CLOSE_CHILD_BOUNTY;
    case 8960: /* module 35 call 0 */
        return STR_ME_REPORT_AWESOME;
    case 8961: /* module 35 call 1 */
        return STR_ME_RETRACT_TIP;
    case 8962: /* module 35 call 2 */
        return STR_ME_TIP_NEW;
    case 8963: /* module 35 call 3 */
        return STR_ME_TIP;
    case 8964: /* module 35 call 4 */
        return STR_ME_CLOSE_TIP;
    case 8965: /* module 35 call 5 */
        return STR_ME_SLASH_TIP;
    case 9220: /* module 36 call 4 */
        return STR_ME_GOVERNANCE_FALLBACK;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V9(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1280: /* module 5 call 0 */
        return 2;
    case 1282: /* module 5 call 2 */
        return 3;
    case 1283: /* module 5 call 3 */
        return 2;
    case 1284: /* module 5 call 4 */
        return 2;
    case 1792: /* module 7 call 0 */
        return 3;
    case 1793: /* module 7 call 1 */
        return 1;
    case 1794: /* module 7 call 2 */
        return 1;
    case 1795: /* module 7 call 3 */
        return 1;
    case 1796: /* module 7 call 4 */
        return 1;
    case 1797: /* module 7 call 5 */
        return 1;
    case 1798: /* module 7 call 6 */
        return 0;
    case 1799: /* module 7 call 7 */
        return 1;
    case 1800: /* module 7 call 8 */
        return 1;
    case 1810: /* module 7 call 18 */
        return 2;
    case 1811: /* module 7 call 19 */
        return 1;
    case 2304: /* module 9 call 0 */
        return 2;
    case 2305: /* module 9 call 1 */
        return 0;
    case 6656: /* module 26 call 0 */
        return 1;
    case 6658: /* module 26 call 2 */
        return 1;
    case 6660: /* module 26 call 4 */
        return 1;
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 4: /* module 0 call 4 */
        return 1;
    case 8: /* module 0 call 8 */
        return 1;
    case 768: /* module 3 call 0 */
        return 1;
    case 1024: /* module 4 call 0 */
        return 1;
    case 1025: /* module 4 call 1 */
        return 2;
    case 1026: /* module 4 call 2 */
        return 1;
    case 1027: /* module 4 call 3 */
        return 3;
    case 1028: /* module 4 call 4 */
        return 1;
    case 1281: /* module 5 call 1 */
        return 3;
    case 1285: /* module 5 call 5 */
        return 2;
    case 1801: /* module 7 call 9 */
        return 1;
    case 1802: /* module 7 call 10 */
        return 1;
    case 1804: /* module 7 call 12 */
        return 0;
    case 1805: /* module 7 call 13 */
        return 0;
    case 1806: /* module 7 call 14 */
        return 1;
    case 1807: /* module 7 call 15 */
        return 2;
    case 1808: /* module 7 call 16 */
        return 0;
    case 1809: /* module 7 call 17 */
        return 2;
    case 1812: /* module 7 call 20 */
        return 2;
    case 1813: /* module 7 call 21 */
        return 2;
    case 1814: /* module 7 call 22 */
        return 1;
    case 1816: /* module 7 call 24 */
        return 1;
    case 1817: /* module 7 call 25 */
        return 1;
    case 2560: /* module 10 call 0 */
        return 1;
    case 2561: /* module 10 call 1 */
        return 2;
    case 2562: /* module 10 call 2 */
        return 1;
    case 2818: /* module 11 call 2 */
        return 2;
    case 3584: /* module 14 call 0 */
        return 2;
    case 3585: /* module 14 call 1 */
        return 2;
    case 3586: /* module 14 call 2 */
        return 2;
    case 3587: /* module 14 call 3 */
        return 1;
    case 3588: /* module 14 call 4 */
        return 1;
    case 3589: /* module 14 call 5 */
        return 1;
    case 3590: /* module 14 call 6 */
        return 1;
    case 3591: /* module 14 call 7 */
        return 3;
    case 3592: /* module 14 call 8 */
        return 1;
    case 3593: /* module 14 call 9 */
        return 1;
    case 3594: /* module 14 call 10 */
        return 1;
    case 3595: /* module 14 call 11 */
        return 3;
    case 3596: /* module 14 call 12 */
        return 0;
    case 3597: /* module 14 call 13 */
        return 0;
    case 3598: /* module 14 call 14 */
        return 1;
    case 3599: /* module 14 call 15 */
        return 1;
    case 3600: /* module 14 call 16 */
        return 1;
    case 3601: /* module 14 call 17 */
        return 1;
    case 3602: /* module 14 call 18 */
        return 2;
    case 3603: /* module 14 call 19 */
        return 1;
    case 3604: /* module 14 call 20 */
        return 1;
    case 3605: /* module 14 call 21 */
        return 2;
    case 3606: /* module 14 call 22 */
        return 2;
    case 3608: /* module 14 call 24 */
        return 1;
    case 3840: /* module 15 call 0 */
        return 3;
    case 3841: /* module 15 call 1 */
        return 2;
    case 3842: /* module 15 call 2 */
        return 3;
    case 3843: /* module 15 call 3 */
        return 3;
    case 3844: /* module 15 call 4 */
        return 4;
    case 3845: /* module 15 call 5 */
        return 1;
    case 3846: /* module 15 call 6 */
        return 4;
    case 4096: /* module 16 call 0 */
        return 3;
    case 4097: /* module 16 call 1 */
        return 2;
    case 4098: /* module 16 call 2 */
        return 3;
    case 4099: /* module 16 call 3 */
        return 3;
    case 4101: /* module 16 call 5 */
        return 1;
    case 4102: /* module 16 call 6 */
        return 4;
    case 4352: /* module 17 call 0 */
        return 2;
    case 4353: /* module 17 call 1 */
        return 0;
    case 4354: /* module 17 call 2 */
        return 1;
    case 4356: /* module 17 call 4 */
        return 2;
    case 4357: /* module 17 call 5 */
        return 2;
    case 4608: /* module 18 call 0 */
        return 1;
    case 4609: /* module 18 call 1 */
        return 1;
    case 4610: /* module 18 call 2 */
        return 2;
    case 4611: /* module 18 call 3 */
        return 1;
    case 4612: /* module 18 call 4 */
        return 1;
    case 4613: /* module 18 call 5 */
        return 1;
    case 4614: /* module 18 call 6 */
        return 0;
    case 4864: /* module 19 call 0 */
        return 2;
    case 4865: /* module 19 call 1 */
        return 1;
    case 4866: /* module 19 call 2 */
        return 1;
    case 4867: /* module 19 call 3 */
        return 1;
    case 6144: /* module 24 call 0 */
        return 2;
    case 6146: /* module 24 call 2 */
        return 3;
    case 6147: /* module 24 call 3 */
        return 1;
    case 6148: /* module 24 call 4 */
        return 3;
    case 6400: /* module 25 call 0 */
        return 0;
    case 6401: /* module 25 call 1 */
        return 1;
    case 6402: /* module 25 call 2 */
        return 2;
    case 6403: /* module 25 call 3 */
        return 3;
    case 6404: /* module 25 call 4 */
        return 2;
    case 7168: /* module 28 call 0 */
        return 1;
    case 7171: /* module 28 call 3 */
        return 0;
    case 7172: /* module 28 call 4 */
        return 2;
    case 7173: /* module 28 call 5 */
        return 1;
    case 7174: /* module 28 call 6 */
        return 2;
    case 7175: /* module 28 call 7 */
        return 2;
    case 7178: /* module 28 call 10 */
        return 1;
    case 7181: /* module 28 call 13 */
        return 1;
    case 7182: /* module 28 call 14 */
        return 0;
    case 7424: /* module 29 call 0 */
        return 3;
    case 7425: /* module 29 call 1 */
        return 3;
    case 7426: /* module 29 call 2 */
        return 3;
    case 7427: /* module 29 call 3 */
        return 0;
    case 7428: /* module 29 call 4 */
        return 3;
    case 7429: /* module 29 call 5 */
        return 5;
    case 7433: /* module 29 call 9 */
        return 4;
    case 7680: /* module 30 call 0 */
        return 2;
    case 7681: /* module 30 call 1 */
        return 6;
    case 7682: /* module 30 call 2 */
        return 5;
    case 7683: /* module 30 call 3 */
        return 4;
    case 8704: /* module 34 call 0 */
        return 2;
    case 8705: /* module 34 call 1 */
        return 1;
    case 8706: /* module 34 call 2 */
        return 3;
    case 8707: /* module 34 call 3 */
        return 1;
    case 8708: /* module 34 call 4 */
        return 1;
    case 8709: /* module 34 call 5 */
        return 2;
    case 8710: /* module 34 call 6 */
        return 1;
    case 8711: /* module 34 call 7 */
        return 1;
    case 8712: /* module 34 call 8 */
        return 2;
    case 10240: /* module 40 call 0 */
        return 1;
    case 10241: /* module 40 call 1 */
        return 1;
    case 10242: /* module 40 call 2 */
        return 1;
    case 10243: /* module 40 call 3 */
        return 1;
    case 10496: /* module 41 call 0 */
        return 3;
    case 10497: /* module 41 call 1 */
        return 4;
    case 10498: /* module 41 call 2 */
        return 2;
    case 10499: /* module 41 call 3 */
        return 2;
    case 10500: /* module 41 call 4 */
        return 3;
    case 10501: /* module 41 call 5 */
        return 2;
    case 10502: /* module 41 call 6 */
        return 2;
    case 8960: /* module 35 call 0 */
        return 2;
    case 8961: /* module 35 call 1 */
        return 1;
    case 8962: /* module 35 call 2 */
        return 3;
    case 8963: /* module 35 call 3 */
        return 2;
    case 8964: /* module 35 call 4 */
        return 1;
    case 8965: /* module 35 call 5 */
        return 1;
    case 9220: /* module 36 call 4 */
        return 2;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V9(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1284: /* module 5 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_keep_alive;
        default:
            return NULL;
        }
    case 1792: /* module 7 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 1793: /* module 7 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1794: /* module 7 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1795: /* module 7 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 1796: /* module 7 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefs;
        default:
            return NULL;
        }
    case 1797: /* module 7 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_targets;
        default:
            return NULL;
        }
    case 1798: /* module 7 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1799: /* module 7 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 1800: /* module 7 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 1810: /* module 7 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 1811: /* module 7 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ratio;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 10240: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bytes;
        default:
            return NULL;
        }
    case 10241: /* module 10 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 10242: /* module 10 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 10243: /* module 10 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_now;
        default:
            return NULL;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_freeze;
        default:
            return NULL;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        case 2:
            return STR_IT_new_reserved;
        default:
            return NULL;
        }
    case 1285: /* module 5 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1801: /* module 7 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 1802: /* module 7 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_additional;
        default:
            return NULL;
        }
    case 1804: /* module 7 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1805: /* module 7 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1806: /* module 7 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_invulnerables;
        default:
            return NULL;
        }
    case 1807: /* module 7 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 1808: /* module 7 call 16 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1809: /* module 7 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_era;
        case 1:
            return STR_IT_slash_indices;
        default:
            return NULL;
        }
    case 1812: /* module 7 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_history_depth;
        case 1:
            return STR_IT_era_items_deleted;
        default:
            return NULL;
        }
    case 1813: /* module 7 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 1814: /* module 7 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 1816: /* module 7 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 1817: /* module 7 call 25 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        default:
            return NULL;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        case 1:
            return STR_IT_weight_limit;
        default:
            return NULL;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 2818: /* module 11 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delay;
        case 1:
            return STR_IT_best_finalized_block_number;
        default:
            return NULL;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_seconds_upper_bound;
        default:
            return NULL;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        case 1:
            return STR_IT_vote;
        default:
            return NULL;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3589: /* module 14 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3590: /* module 14 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3591: /* module 14 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_voting_period;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 3592: /* module 14 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3593: /* module 14 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
    case 3594: /* module 14 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_which;
        default:
            return NULL;
        }
    case 3595: /* module 14 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_to;
        case 1:
            return STR_IT_conviction;
        case 2:
            return STR_IT_balance;
        default:
            return NULL;
        }
    case 3596: /* module 14 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 3597: /* module 14 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 3598: /* module 14 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 3599: /* module 14 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 3600: /* module 14 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 3601: /* module 14 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 3602: /* module 14 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_proposal_len_upper_bound;
        default:
            return NULL;
        }
    case 3603: /* module 14 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 3604: /* module 14 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 3605: /* module 14 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 3606: /* module 14 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 3608: /* module 14 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prop_index;
        default:
            return NULL;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_members;
        case 1:
            return STR_IT_prime;
        case 2:
            return STR_IT_old_count;
        default:
            return NULL;
        }
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3843: /* module 15 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_proposal_weight_bound;
        case 3:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3846: /* module 15 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_proposal_weight_bound;
        case 3:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_members;
        case 1:
            return STR_IT_prime;
        case 2:
            return STR_IT_old_count;
        default:
            return NULL;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 4101: /* module 16 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 4102: /* module 16 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_proposal_weight_bound;
        case 3:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_votes;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_candidate_count;
        default:
            return NULL;
        }
    case 4356: /* module 17 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_has_replacement;
        default:
            return NULL;
        }
    case 4357: /* module 17 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num_voters;
        case 1:
            return STR_IT_num_defunct;
        default:
            return NULL;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 4611: /* module 18 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 4612: /* module 18 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 4613: /* module 18 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4614: /* module 18 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 4865: /* module 19 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 4867: /* module 19 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_ethereum_signature;
        default:
            return NULL;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_ethereum_signature;
        case 2:
            return STR_IT_statement;
        default:
            return NULL;
        }
    case 6147: /* module 24 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_statement;
        default:
            return NULL;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_old;
        case 1:
            return STR_IT_new_;
        case 2:
            return STR_IT_maybe_preclaim;
        default:
            return NULL;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 6404: /* module 25 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_schedule1_index;
        case 1:
            return STR_IT_schedule2_index;
        default:
            return NULL;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7172: /* module 28 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        case 1:
            return STR_IT_max_fee;
        default:
            return NULL;
        }
    case 7173: /* module 28 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        default:
            return NULL;
        }
    case 7174: /* module 28 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 7175: /* module 28 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 7178: /* module 28 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 7181: /* module 28 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        default:
            return NULL;
        }
    case 7182: /* module 28 call 14 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_force_proxy_type;
        case 2:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7428: /* module 29 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proxy_type;
        case 1:
            return STR_IT_delay;
        case 2:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 7429: /* module 29 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_spawner;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_index;
        case 3:
            return STR_IT_height;
        case 4:
            return STR_IT_ext_index;
        default:
            return NULL;
        }
    case 7433: /* module 29 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_real;
        case 2:
            return STR_IT_force_proxy_type;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_other_signatories;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call;
        case 4:
            return STR_IT_store_call;
        case 5:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call_hash;
        case 4:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 7683: /* module 30 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_timepoint;
        case 3:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 8704: /* module 34 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_description;
        default:
            return NULL;
        }
    case 8705: /* module 34 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8706: /* module 34 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_curator;
        case 2:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 8707: /* module 34 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8708: /* module 34 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8709: /* module 34 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 8710: /* module 34 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8711: /* module 34 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8712: /* module 34 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 8960: /* module 35 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reason;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 8961: /* module 35 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 8962: /* module 35 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reason;
        case 1:
            return STR_IT_who;
        case 2:
            return STR_IT_tip_value;
        default:
            return NULL;
        }
    case 8963: /* module 35 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        case 1:
            return STR_IT_tip_value;
        default:
            return NULL;
        }
    case 8964: /* module 35 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 8965: /* module 35 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 9220: /* module 36 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_maybe_max_voters;
        case 1:
            return STR_IT_maybe_max_targets;
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V9(
    pd_Method_V9_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V9 - dest */;
            return _toStringLookupasStaticLookupSource_V9(
                &m->nested.balances_transfer_V9.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V9 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V9.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V9 - source */;
            return _toStringLookupasStaticLookupSource_V9(
                &m->nested.balances_force_transfer_V9.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V9 - dest */;
            return _toStringLookupasStaticLookupSource_V9(
                &m->nested.balances_force_transfer_V9.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V9 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V9.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V9 - dest */;
            return _toStringLookupasStaticLookupSource_V9(
                &m->nested.balances_transfer_keep_alive_V9.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V9 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V9.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1284: /* module 5 call 4 */
        switch (itemIdx) {
        case 0: /* balances_transfer_all_V9 - dest */;
            return _toStringLookupasStaticLookupSource_V9(
                &m->basic.balances_transfer_all_V9.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_all_V9 - keep_alive */;
            return _toStringbool(
                &m->basic.balances_transfer_all_V9.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1792: /* module 7 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V9 - controller */;
            return _toStringLookupasStaticLookupSource_V9(
                &m->basic.staking_bond_V9.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V9 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_bond_V9.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_bond_V9 - payee */;
            return _toStringRewardDestination_V9(
                &m->basic.staking_bond_V9.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1793: /* module 7 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V9 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_bond_extra_V9.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1794: /* module 7 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V9 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_unbond_V9.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1795: /* module 7 call 3 */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V9 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_withdraw_unbonded_V9.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1796: /* module 7 call 4 */
        switch (itemIdx) {
        case 0: /* staking_validate_V9 - prefs */;
            return _toStringValidatorPrefs_V9(
                &m->basic.staking_validate_V9.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1797: /* module 7 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V9 - targets */;
            return _toStringVecLookupasStaticLookupSource_V9(
                &m->basic.staking_nominate_V9.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1798: /* module 7 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1799: /* module 7 call 7 */
        switch (itemIdx) {
        case 0: /* staking_set_payee_V9 - payee */;
            return _toStringRewardDestination_V9(
                &m->basic.staking_set_payee_V9.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1800: /* module 7 call 8 */
        switch (itemIdx) {
        case 0: /* staking_set_controller_V9 - controller */;
            return _toStringLookupasStaticLookupSource_V9(
                &m->basic.staking_set_controller_V9.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1810: /* module 7 call 18 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_V9 - validator_stash */;
            return _toStringAccountId_V9(
                &m->basic.staking_payout_stakers_V9.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_V9 - era */;
            return _toStringEraIndex_V9(
                &m->basic.staking_payout_stakers_V9.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1811: /* module 7 call 19 */
        switch (itemIdx) {
        case 0: /* staking_rebond_V9 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_rebond_V9.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V9 - keys */;
            return _toStringKeys_V9(
                &m->basic.session_set_keys_V9.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V9 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V9.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V9 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V9.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V9 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_all_V9.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0: /* utility_force_batch_V9 - calls */;
            return _toStringVecCall(
                &m->basic.utility_force_batch_V9.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_fill_block_V9 - ratio */;
            return _toStringPerbill_V9(
                &m->nested.system_fill_block_V9.ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V9 - remark */;
            return _toStringVecu8(
                &m->nested.system_remark_V9.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V9 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V9.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_V9 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_V9.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V9 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_without_checks_V9.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0: /* system_remark_with_event_V9 - remark */;
            return _toStringVecu8(
                &m->nested.system_remark_with_event_V9.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10240: /* module 40 call 0 */
        switch (itemIdx) {
        case 0: /* preimage_note_preimage_V9 - bytes */;
            return _toStringVecu8(
                &m->basic.preimage_note_preimage_V9.bytes,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10241: /* module 40 call 1 */
        switch (itemIdx) {
        case 0: /* preimage_unnote_preimage_V9 - hash */;
            return _toStringHash(
                &m->basic.preimage_unnote_preimage_V9.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10242: /* module 40 call 2 */
        switch (itemIdx) {
        case 0: /* preimage_request_preimage_V9 - hash */;
            return _toStringHash(
                &m->basic.preimage_request_preimage_V9.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10243: /* module 40 call 3 */
        switch (itemIdx) {
        case 0: /* preimage_unrequest_preimage_V9 - hash */;
            return _toStringHash(
                &m->basic.preimage_unrequest_preimage_V9.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V9 - now */;
            return _toStringCompactu64(
                &m->basic.timestamp_set_V9.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0: /* indices_claim_V9 - index */;
            return _toStringAccountIndex_V9(
                &m->basic.indices_claim_V9.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0: /* indices_transfer_V9 - new_ */;
            return _toStringAccountId_V9(
                &m->basic.indices_transfer_V9.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_transfer_V9 - index */;
            return _toStringAccountIndex_V9(
                &m->basic.indices_transfer_V9.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0: /* indices_free_V9 - index */;
            return _toStringAccountIndex_V9(
                &m->basic.indices_free_V9.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0: /* indices_force_transfer_V9 - new_ */;
            return _toStringAccountId_V9(
                &m->basic.indices_force_transfer_V9.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_force_transfer_V9 - index */;
            return _toStringAccountIndex_V9(
                &m->basic.indices_force_transfer_V9.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* indices_force_transfer_V9 - freeze */;
            return _toStringbool(
                &m->basic.indices_force_transfer_V9.freeze,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0: /* indices_freeze_V9 - index */;
            return _toStringAccountIndex_V9(
                &m->basic.indices_freeze_V9.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V9 - who */;
            return _toStringLookupasStaticLookupSource_V9(
                &m->nested.balances_set_balance_V9.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V9 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V9.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V9 - new_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V9.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1285: /* module 5 call 5 */
        switch (itemIdx) {
        case 0: /* balances_force_unreserve_V9 - who */;
            return _toStringLookupasStaticLookupSource_V9(
                &m->basic.balances_force_unreserve_V9.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_unreserve_V9 - amount */;
            return _toStringBalance(
                &m->basic.balances_force_unreserve_V9.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1801: /* module 7 call 9 */
        switch (itemIdx) {
        case 0: /* staking_set_validator_count_V9 - new_ */;
            return _toStringCompactu32(
                &m->basic.staking_set_validator_count_V9.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1802: /* module 7 call 10 */
        switch (itemIdx) {
        case 0: /* staking_increase_validator_count_V9 - additional */;
            return _toStringCompactu32(
                &m->basic.staking_increase_validator_count_V9.additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1804: /* module 7 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1805: /* module 7 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1806: /* module 7 call 14 */
        switch (itemIdx) {
        case 0: /* staking_set_invulnerables_V9 - invulnerables */;
            return _toStringVecAccountId_V9(
                &m->basic.staking_set_invulnerables_V9.invulnerables,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1807: /* module 7 call 15 */
        switch (itemIdx) {
        case 0: /* staking_force_unstake_V9 - stash */;
            return _toStringAccountId_V9(
                &m->basic.staking_force_unstake_V9.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_force_unstake_V9 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_force_unstake_V9.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1808: /* module 7 call 16 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1809: /* module 7 call 17 */
        switch (itemIdx) {
        case 0: /* staking_cancel_deferred_slash_V9 - era */;
            return _toStringEraIndex_V9(
                &m->basic.staking_cancel_deferred_slash_V9.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_cancel_deferred_slash_V9 - slash_indices */;
            return _toStringVecu32(
                &m->basic.staking_cancel_deferred_slash_V9.slash_indices,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1812: /* module 7 call 20 */
        switch (itemIdx) {
        case 0: /* staking_set_history_depth_V9 - new_history_depth */;
            return _toStringCompactu32(
                &m->basic.staking_set_history_depth_V9.new_history_depth,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_history_depth_V9 - era_items_deleted */;
            return _toStringCompactu32(
                &m->basic.staking_set_history_depth_V9.era_items_deleted,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1813: /* module 7 call 21 */
        switch (itemIdx) {
        case 0: /* staking_reap_stash_V9 - stash */;
            return _toStringAccountId_V9(
                &m->basic.staking_reap_stash_V9.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_reap_stash_V9 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_reap_stash_V9.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1814: /* module 7 call 22 */
        switch (itemIdx) {
        case 0: /* staking_kick_V9 - who */;
            return _toStringVecLookupasStaticLookupSource_V9(
                &m->basic.staking_kick_V9.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1816: /* module 7 call 24 */
        switch (itemIdx) {
        case 0: /* staking_chill_other_V9 - controller */;
            return _toStringAccountId_V9(
                &m->basic.staking_chill_other_V9.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1817: /* module 7 call 25 */
        switch (itemIdx) {
        case 0: /* staking_force_apply_min_commission_V9 - validator_stash */;
            return _toStringAccountId_V9(
                &m->basic.staking_force_apply_min_commission_V9.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2818: /* module 11 call 2 */
        switch (itemIdx) {
        case 0: /* grandpa_note_stalled_V9 - delay */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V9.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_note_stalled_V9 - best_finalized_block_number */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V9.best_finalized_block_number,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0: /* council_set_members_V9 - new_members */;
            return _toStringVecAccountId_V9(
                &m->basic.council_set_members_V9.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_set_members_V9 - prime */;
            return _toStringOptionAccountId_V9(
                &m->basic.council_set_members_V9.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_set_members_V9 - old_count */;
            return _toStringMemberCount_V9(
                &m->basic.council_set_members_V9.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0: /* council_execute_V9 - proposal */;
            return _toStringProposal(
                &m->basic.council_execute_V9.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_execute_V9 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_execute_V9.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0: /* council_propose_V9 - threshold */;
            return _toStringCompactu32(
                &m->basic.council_propose_V9.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_propose_V9 - proposal */;
            return _toStringProposal(
                &m->basic.council_propose_V9.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_propose_V9 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_propose_V9.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3843: /* module 15 call 3 */
        switch (itemIdx) {
        case 0: /* council_vote_V9 - proposal */;
            return _toStringHash(
                &m->basic.council_vote_V9.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_vote_V9 - index */;
            return _toStringCompactu32(
                &m->basic.council_vote_V9.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_vote_V9 - approve */;
            return _toStringbool(
                &m->basic.council_vote_V9.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0: /* council_close_V9 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_close_old_weight_V9.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_close_V9 - index */;
            return _toStringCompactu32(
                &m->basic.council_close_old_weight_V9.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_close_V9 - proposal_weight_bound */;
            return _toStringCompactu64(
                &m->basic.council_close_old_weight_V9.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* council_close_V9 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_close_old_weight_V9.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0: /* council_disapprove_proposal_V9 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_disapprove_proposal_V9.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3846: /* module 15 call 6 */
        switch (itemIdx) {
        case 0: /* council_close_V9 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_close_V9.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_close_V9 - index */;
            return _toStringCompactu32(
                &m->basic.council_close_V9.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_close_V9 - proposal_weight_bound */;
            return _toStringWeight(
                &m->basic.council_close_V9.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* council_close_V9 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_close_V9.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_members_V9 - new_members */;
            return _toStringVecAccountId_V9(
                &m->basic.technicalcommittee_set_members_V9.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_set_members_V9 - prime */;
            return _toStringOptionAccountId_V9(
                &m->basic.technicalcommittee_set_members_V9.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_set_members_V9 - old_count */;
            return _toStringMemberCount_V9(
                &m->basic.technicalcommittee_set_members_V9.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_execute_V9 - proposal */;
            return _toStringProposal(
                &m->basic.technicalcommittee_execute_V9.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_execute_V9 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_execute_V9.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_propose_V9 - threshold */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_propose_V9.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_propose_V9 - proposal */;
            return _toStringProposal(
                &m->basic.technicalcommittee_propose_V9.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_propose_V9 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_propose_V9.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_vote_V9 - proposal */;
            return _toStringHash(
                &m->basic.technicalcommittee_vote_V9.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_vote_V9 - index */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_vote_V9.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_vote_V9 - approve */;
            return _toStringbool(
                &m->basic.technicalcommittee_vote_V9.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4101: /* module 16 call 5 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_disapprove_proposal_V9 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_disapprove_proposal_V9.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4102: /* module 16 call 6 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_close_V9 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_close_V9.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_close_V9 - index */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_close_V9.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_close_V9 - proposal_weight_bound */;
            return _toStringWeight(
                &m->basic.technicalcommittee_close_V9.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* technicalcommittee_close_V9 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_close_V9.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0: /* treasury_propose_spend_V9 - amount */;
            return _toStringCompactBalance(
                &m->basic.treasury_propose_spend_V9.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_propose_spend_V9 - beneficiary */;
            return _toStringLookupasStaticLookupSource_V9(
                &m->basic.treasury_propose_spend_V9.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4865: /* module 19 call 1 */
        switch (itemIdx) {
        case 0: /* treasury_reject_proposal_V9 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_reject_proposal_V9.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        case 0: /* treasury_approve_proposal_V9 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_approve_proposal_V9.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4867: /* module 19 call 3 */
        switch (itemIdx) {
        case 0: /* treasury_remove_approval_V9 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_remove_approval_V9.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0: /* vesting_vest_other_V9 - target */;
            return _toStringLookupasStaticLookupSource_V9(
                &m->basic.vesting_vest_other_V9.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0: /* vesting_vested_transfer_V9 - target */;
            return _toStringLookupasStaticLookupSource_V9(
                &m->basic.vesting_vested_transfer_V9.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_vested_transfer_V9 - schedule */;
            return _toStringVestingInfo_V9(
                &m->basic.vesting_vested_transfer_V9.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        case 0: /* vesting_force_vested_transfer_V9 - source */;
            return _toStringLookupasStaticLookupSource_V9(
                &m->basic.vesting_force_vested_transfer_V9.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_force_vested_transfer_V9 - target */;
            return _toStringLookupasStaticLookupSource_V9(
                &m->basic.vesting_force_vested_transfer_V9.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* vesting_force_vested_transfer_V9 - schedule */;
            return _toStringVestingInfo_V9(
                &m->basic.vesting_force_vested_transfer_V9.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6404: /* module 25 call 4 */
        switch (itemIdx) {
        case 0: /* vesting_merge_schedules_V9 - schedule1_index */;
            return _toStringu32(
                &m->basic.vesting_merge_schedules_V9.schedule1_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_merge_schedules_V9 - schedule2_index */;
            return _toStringu32(
                &m->basic.vesting_merge_schedules_V9.schedule2_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0: /* identity_add_registrar_V9 - account */;
            return _toStringAccountId_V9(
                &m->basic.identity_add_registrar_V9.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7172: /* module 28 call 4 */
        switch (itemIdx) {
        case 0: /* identity_request_judgement_V9 - reg_index */;
            return _toStringCompactu32(
                &m->basic.identity_request_judgement_V9.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_request_judgement_V9 - max_fee */;
            return _toStringCompactu128(
                &m->basic.identity_request_judgement_V9.max_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7173: /* module 28 call 5 */
        switch (itemIdx) {
        case 0: /* identity_cancel_request_V9 - reg_index */;
            return _toStringRegistrarIndex_V9(
                &m->basic.identity_cancel_request_V9.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7174: /* module 28 call 6 */
        switch (itemIdx) {
        case 0: /* identity_set_fee_V9 - index */;
            return _toStringCompactu32(
                &m->basic.identity_set_fee_V9.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fee_V9 - fee */;
            return _toStringCompactu128(
                &m->basic.identity_set_fee_V9.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7175: /* module 28 call 7 */
        switch (itemIdx) {
        case 0: /* identity_set_account_id_V9 - index */;
            return _toStringCompactu32(
                &m->basic.identity_set_account_id_V9.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_account_id_V9 - new_ */;
            return _toStringAccountId_V9(
                &m->basic.identity_set_account_id_V9.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7178: /* module 28 call 10 */
        switch (itemIdx) {
        case 0: /* identity_kill_identity_V9 - target */;
            return _toStringLookupasStaticLookupSource_V9(
                &m->basic.identity_kill_identity_V9.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7181: /* module 28 call 13 */
        switch (itemIdx) {
        case 0: /* identity_remove_sub_V9 - sub */;
            return _toStringLookupasStaticLookupSource_V9(
                &m->basic.identity_remove_sub_V9.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7182: /* module 28 call 14 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_V9 - real */;
            return _toStringAccountId_V9(
                &m->nested.proxy_proxy_V9.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_V9 - force_proxy_type */;
            return _toStringOptionProxyType_V9(
                &m->nested.proxy_proxy_V9.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_V9 - call */;
            return _toStringCall(
                &m->nested.proxy_proxy_V9.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0: /* proxy_add_proxy_V9 - delegate */;
            return _toStringAccountId_V9(
                &m->basic.proxy_add_proxy_V9.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_add_proxy_V9 - proxy_type */;
            return _toStringProxyType_V9(
                &m->basic.proxy_add_proxy_V9.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_add_proxy_V9 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_add_proxy_V9.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0: /* proxy_remove_proxy_V9 - delegate */;
            return _toStringAccountId_V9(
                &m->basic.proxy_remove_proxy_V9.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_proxy_V9 - proxy_type */;
            return _toStringProxyType_V9(
                &m->basic.proxy_remove_proxy_V9.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_remove_proxy_V9 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_remove_proxy_V9.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7428: /* module 29 call 4 */
        switch (itemIdx) {
        case 0: /* proxy_anonymous_V9 - proxy_type */;
            return _toStringProxyType_V9(
                &m->basic.proxy_anonymous_V9.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_anonymous_V9 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_anonymous_V9.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_anonymous_V9 - index */;
            return _toStringu16(
                &m->basic.proxy_anonymous_V9.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7429: /* module 29 call 5 */
        switch (itemIdx) {
        case 0: /* proxy_kill_anonymous_V9 - spawner */;
            return _toStringAccountId_V9(
                &m->basic.proxy_kill_anonymous_V9.spawner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_kill_anonymous_V9 - proxy_type */;
            return _toStringProxyType_V9(
                &m->basic.proxy_kill_anonymous_V9.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_kill_anonymous_V9 - index */;
            return _toStringu16(
                &m->basic.proxy_kill_anonymous_V9.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_kill_anonymous_V9 - height */;
            return _toStringCompactu32(
                &m->basic.proxy_kill_anonymous_V9.height,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* proxy_kill_anonymous_V9 - ext_index */;
            return _toStringCompactu32(
                &m->basic.proxy_kill_anonymous_V9.ext_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7433: /* module 29 call 9 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_announced_V9 - delegate */;
            return _toStringAccountId_V9(
                &m->basic.proxy_proxy_announced_V9.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_announced_V9 - real */;
            return _toStringAccountId_V9(
                &m->basic.proxy_proxy_announced_V9.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_announced_V9 - force_proxy_type */;
            return _toStringOptionProxyType_V9(
                &m->basic.proxy_proxy_announced_V9.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_proxy_announced_V9 - call */;
            return _toStringCall(
                &m->basic.proxy_proxy_announced_V9.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V9 - other_signatories */;
            return _toStringVecAccountId_V9(
                &m->nested.multisig_as_multi_threshold_1_V9.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V9 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_threshold_1_V9.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V9 - threshold */;
            return _toStringu16(
                &m->nested.multisig_as_multi_V9.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V9 - other_signatories */;
            return _toStringVecAccountId_V9(
                &m->nested.multisig_as_multi_V9.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V9 - maybe_timepoint */;
            return _toStringOptionTimepoint_V9(
                &m->nested.multisig_as_multi_V9.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V9 - call */;
            return _toStringOpaqueCall_V9(
                &m->nested.multisig_as_multi_V9.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V9 - store_call */;
            return _toStringbool(
                &m->nested.multisig_as_multi_V9.store_call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* multisig_as_multi_V9 - max_weight */;
            return _toStringWeight(
                &m->nested.multisig_as_multi_V9.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V9 - threshold */;
            return _toStringu16(
                &m->nested.multisig_approve_as_multi_V9.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V9 - other_signatories */;
            return _toStringVecAccountId_V9(
                &m->nested.multisig_approve_as_multi_V9.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V9 - maybe_timepoint */;
            return _toStringOptionTimepoint_V9(
                &m->nested.multisig_approve_as_multi_V9.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V9 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_approve_as_multi_V9.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V9 - max_weight */;
            return _toStringWeight(
                &m->nested.multisig_approve_as_multi_V9.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7683: /* module 30 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V9 - threshold */;
            return _toStringu16(
                &m->nested.multisig_cancel_as_multi_V9.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V9 - other_signatories */;
            return _toStringVecAccountId_V9(
                &m->nested.multisig_cancel_as_multi_V9.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V9 - timepoint */;
            return _toStringTimepoint_V9(
                &m->nested.multisig_cancel_as_multi_V9.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V9 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_cancel_as_multi_V9.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }

    case 9220: /* module 36 call 4 */
        switch (itemIdx) {
        case 0: /* electionprovidermultiphase_governance_fallback_V9 - maybe_max_voters */;
            return _toStringOptionu32(
                &m->basic.electionprovidermultiphase_governance_fallback_V9.maybe_max_voters,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* electionprovidermultiphase_governance_fallback_V9 - maybe_max_targets */;
            return _toStringOptionu32(
                &m->basic.electionprovidermultiphase_governance_fallback_V9.maybe_max_targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V9(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1795: // Staking:Withdraw Unbonded
        switch (itemIdx) {
        case 0: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 1807: // Staking:Force unstake
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 1813: // Staking:Reap stash
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V9(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 768: // Timestamp:Set
    case 1024: // Indices:Claim
    case 1025: // Indices:Transfer
    case 1026: // Indices:Free
    case 1027: // Indices:Force transfer
    case 1028: // Indices:Freeze
    case 1284: // Balances:Transfer all
    case 1285: // Balances:Force unreserve
    case 1792: // Staking:Bond
    case 1793: // Staking:Bond extra
    case 1794: // Staking:Unbond
    case 1795: // Staking:Withdraw Unbonded
    case 1796: // Staking:Validate
    case 1797: // Staking:Nominate
    case 1798: // Staking:Chill
    case 1799: // Staking:Set payee
    case 1800: // Staking:Set controller
    case 1801: // Staking:Set validator count
    case 1802: // Staking:Increase validator count
    case 1804: // Staking:Force no eras
    case 1805: // Staking:Force new era
    case 1806: // Staking:Set invulnerables
    case 1807: // Staking:Force unstake
    case 1808: // Staking:Force new era always
    case 1809: // Staking:Cancel deferred slash
    case 1810: // Staking:Payout stakers
    case 1811: // Staking:Rebond
    case 1812: // Staking:Set history depth
    case 1813: // Staking:Reap stash
    case 1814: // Staking:Kick
    case 1816: // Staking:Chill other
    case 1817: // Staking:Force apply min commission
    case 2304: // Session:Set keys
    case 2305: // Session:Purge keys
    case 2560: // Sudo:Sudo
    case 2562: // Sudo:Set key
    case 2561: // Sudo:Sudo unchecked weight
    case 2818: // Grandpa:Note stalled
    case 3840: // Council:Set members
    case 3841: // Council:Execute
    case 3842: // Council:Propose
    case 3843: // Council:Vote
    case 3844: // Council:Close old weight
    case 3845: // Council:Disapprove proposal
    case 3846: // Council:Close
    case 4096: // TechnicalCommittee:Set members
    case 4097: // TechnicalCommittee:Execute
    case 4098: // TechnicalCommittee:Propose
    case 4099: // TechnicalCommittee:Vote
    case 4101: // TechnicalCommittee:Disapprove proposal
    case 4102: // TechnicalCommittee:Close
    case 4864: // Treasury:Propose spend
    case 4865: // Treasury:Reject proposal
    case 4866: // Treasury:Approve proposal
    case 4867: // Treasury:Spend
    case 4868: // Treasury:Remove approval
    case 6400: // Vesting:Vest
    case 6401: // Vesting:Vest other
    case 6402: // Vesting:Vested transfer
    case 6403: // Vesting:Force vested transfer
    case 6404: // Vesting:Merge schedules
    case 6656: // Utility:Batch
    case 6658: // Utility:Batch all
    case 6660: // Utility:Force batch
    case 7168: // Identity:Add registrar
    case 7171: // Identity:Clear identity
    case 7172: // Identity:Request judgement
    case 7173: // Identity:Cancel request
    case 7174: // Identity:Set fee
    case 7175: // Identity:Set account id
    case 7178: // Identity:Kill identity
    case 7181: // Identity:Remove sub
    case 7182: // Identity:Quit sub
    case 7425: // Proxy:Add proxy
    case 7426: // Proxy:Remove proxy
    case 7427: // Proxy:Remove proxies
    case 7428: // Proxy:Anonymous
    case 7429: // Proxy:Kill anonymous
    case 7433: // Proxy:Proxy announced
    case 9220: // ElectionProviderMultiPhase:Governance fallback
    case 10240: // Preimage:Note preimage
    case 10241: // Preimage:Unnote preimage
    case 10242: // Preimage:Request preimage
    case 10243: // Preimage:Unrequest preimage
        return false;
    default:
        return true;
    }
}
