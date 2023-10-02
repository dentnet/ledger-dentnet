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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V10.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V10 0
#define PD_CALL_PREIMAGE_V10 10
#define PD_CALL_TIMESTAMP_V10 3
#define PD_CALL_INDICES_V10 4
#define PD_CALL_BALANCES_V10 5
#define PD_CALL_STAKING_V10 7
#define PD_CALL_SESSION_V10 9
#define PD_CALL_GRANDPA_V10 11
#define PD_CALL_COUNCIL_V10 15
#define PD_CALL_TECHNICALCOMMITTEE_V10 16
#define PD_CALL_TREASURY_V10 19
#define PD_CALL_VESTING_V10 25
#define PD_CALL_UTILITY_V10 26
#define PD_CALL_IDENTITY_V10 28
#define PD_CALL_PROXY_V10 29
#define PD_CALL_MULTISIG_V10 30
#define PD_CALL_ELECTIONPROVIDERMULTIPHASE_V10 36
#define PD_CALL_VOTERLIST_V10 37
#define PD_CALL_CONFIGURATION_V10 51
#define PD_CALL_INITIALIZER_V10 57
#define PD_CALL_HRMP_V10 60
#define PD_CALL_PARASDISPUTES_V10 62
#define PD_CALL_REGISTRAR_V10 70
#define PD_CALL_AUCTIONS_V10 72
#define PD_CALL_CROWDLOAN_V10 73

#define PD_CALL_BALANCES_TRANSFER_ALL_V10 4
typedef struct {
    pd_LookupasStaticLookupSource_V10_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V10_t;

#define PD_CALL_STAKING_BOND_V10 0
typedef struct {
    pd_LookupasStaticLookupSource_V10_t controller;
    pd_CompactBalance_t amount;
    pd_RewardDestination_V10_t payee;
} pd_staking_bond_V10_t;

#define PD_CALL_STAKING_BOND_EXTRA_V10 1
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_bond_extra_V10_t;

#define PD_CALL_STAKING_UNBOND_V10 2
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_unbond_V10_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V10 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V10_t;

#define PD_CALL_STAKING_VALIDATE_V10 4
typedef struct {
    pd_ValidatorPrefs_V10_t prefs;
} pd_staking_validate_V10_t;

#define PD_CALL_STAKING_NOMINATE_V10 5
typedef struct {
    pd_VecLookupasStaticLookupSource_V10_t targets;
} pd_staking_nominate_V10_t;

#define PD_CALL_STAKING_CHILL_V10 6
typedef struct {
} pd_staking_chill_V10_t;

#define PD_CALL_STAKING_SET_PAYEE_V10 7
typedef struct {
    pd_RewardDestination_V10_t payee;
} pd_staking_set_payee_V10_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V10 8
typedef struct {
    pd_LookupasStaticLookupSource_V10_t controller;
} pd_staking_set_controller_V10_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V10 18
typedef struct {
    pd_AccountId_V10_t validator_stash;
    pd_EraIndex_V10_t era;
} pd_staking_payout_stakers_V10_t;

#define PD_CALL_STAKING_REBOND_V10 19
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_rebond_V10_t;

#define PD_CALL_SESSION_SET_KEYS_V10 0
typedef struct {
    pd_Keys_V10_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V10_t;

#define PD_CALL_SESSION_PURGE_KEYS_V10 1
typedef struct {
} pd_session_purge_keys_V10_t;

#define PD_CALL_UTILITY_BATCH_V10 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V10_t;

#define PD_CALL_UTILITY_BATCH_ALL_V10 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V10_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V10 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V10_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_PREIMAGE_NOTE_PREIMAGE_V10 0
typedef struct {
    pd_Vecu8_t bytes;
} pd_preimage_note_preimage_V10_t;

#define PD_CALL_PREIMAGE_UNNOTE_PREIMAGE_V10 1
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unnote_preimage_V10_t;

#define PD_CALL_PREIMAGE_REQUEST_PREIMAGE_V10 2
typedef struct {
    pd_Hash_t hash;
} pd_preimage_request_preimage_V10_t;

#define PD_CALL_PREIMAGE_UNREQUEST_PREIMAGE_V10 3
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unrequest_preimage_V10_t;

#define PD_CALL_TIMESTAMP_SET_V10 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V10_t;

#define PD_CALL_INDICES_CLAIM_V10 0
typedef struct {
    pd_AccountIndex_V10_t index;
} pd_indices_claim_V10_t;

#define PD_CALL_INDICES_TRANSFER_V10 1
typedef struct {
    pd_AccountId_V10_t new_;
    pd_AccountIndex_V10_t index;
} pd_indices_transfer_V10_t;

#define PD_CALL_INDICES_FREE_V10 2
typedef struct {
    pd_AccountIndex_V10_t index;
} pd_indices_free_V10_t;

#define PD_CALL_INDICES_FORCE_TRANSFER_V10 3
typedef struct {
    pd_AccountId_V10_t new_;
    pd_AccountIndex_V10_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_V10_t;

#define PD_CALL_INDICES_FREEZE_V10 4
typedef struct {
    pd_AccountIndex_V10_t index;
} pd_indices_freeze_V10_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V10 5
typedef struct {
    pd_LookupasStaticLookupSource_V10_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V10_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V10 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V10_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V10 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V10_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V10 12
typedef struct {
} pd_staking_force_no_eras_V10_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V10 13
typedef struct {
} pd_staking_force_new_era_V10_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V10 14
typedef struct {
    pd_VecAccountId_V10_t invulnerables;
} pd_staking_set_invulnerables_V10_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V10 15
typedef struct {
    pd_AccountId_V10_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V10_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V10 16
typedef struct {
} pd_staking_force_new_era_always_V10_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V10 17
typedef struct {
    pd_EraIndex_V10_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V10_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH_V10 20
typedef struct {
    pd_Compactu32_t new_history_depth;
    pd_Compactu32_t era_items_deleted;
} pd_staking_set_history_depth_V10_t;

#define PD_CALL_STAKING_REAP_STASH_V10 21
typedef struct {
    pd_AccountId_V10_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V10_t;

#define PD_CALL_STAKING_KICK_V10 22
typedef struct {
    pd_VecLookupasStaticLookupSource_V10_t who;
} pd_staking_kick_V10_t;

#define PD_CALL_STAKING_CHILL_OTHER_V10 24
typedef struct {
    pd_AccountId_V10_t controller;
} pd_staking_chill_other_V10_t;

#define PD_CALL_STAKING_FORCE_APPLY_MIN_COMMISSION_V10 25
typedef struct {
    pd_AccountId_V10_t validator_stash;
} pd_staking_force_apply_min_commission_V10_t;

#define PD_CALL_SUDO_SUDO_V10 0
typedef struct {
    pd_Call_t call;
} pd_sudo_sudo_V10_t;

#define PD_CALL_SUDO_SUDO_UNCHECKED_WEIGHT_V10 1
typedef struct {
    pd_Call_t call;
    pd_Weight_t weight;
} pd_sudo_sudo_unchecked_weight_V10_t;

#define PD_CALL_SUDO_SET_KEY_V10 2 
typedef struct {
    pd_AccountIdLookupOfT_V10_t new_;
} pd_sudo_set_key_V10_t;

#define PD_CALL_GRANDPA_NOTE_STALLED_V10 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_V10_t;

#define PD_CALL_COUNCIL_SET_MEMBERS_V10 0
typedef struct {
    pd_VecAccountId_V10_t new_members;
    pd_OptionAccountId_V10_t prime;
    pd_MemberCount_V10_t old_count;
} pd_council_set_members_V10_t;

#define PD_CALL_COUNCIL_EXECUTE_V10 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_execute_V10_t;

#define PD_CALL_COUNCIL_PROPOSE_V10 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_propose_V10_t;

#define PD_CALL_COUNCIL_VOTE_V10 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_council_vote_V10_t;

#define PD_CALL_COUNCIL_CLOSE_OLD_WEIGHT_V10 6
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_council_close_old_weight_V10_t;

#define PD_CALL_COUNCIL_DISAPPROVE_PROPOSAL_V10 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_council_disapprove_proposal_V10_t;

#define PD_CALL_COUNCIL_CLOSE_V10 6
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Weight_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_council_close_V10_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS_V10 0
typedef struct {
    pd_VecAccountId_V10_t new_members;
    pd_OptionAccountId_V10_t prime;
    pd_MemberCount_V10_t old_count;
} pd_technicalcommittee_set_members_V10_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE_V10 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V10_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE_V10 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V10_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V10 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V10_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V10 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Weight_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V10_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V10 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V10_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND_V10 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_LookupasStaticLookupSource_V10_t beneficiary;
} pd_treasury_propose_spend_V10_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V10 1
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_reject_proposal_V10_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V10 2
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_approve_proposal_V10_t;

#define PD_CALL_TREASURY_SPEND_V10 3
typedef struct {
    pd_CompactBalance_t amount;
    pd_LookupasStaticLookupSource_V10_t beneficiary;
} pd_treasury_spend_V10_t;

#define PD_CALL_TREASURY_REMOVE_APPROVAL_V10 4
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_remove_approval_V10_t;

#define PD_CALL_VESTING_VEST_V10 0
typedef struct {
} pd_vesting_vest_V10_t;

#define PD_CALL_VESTING_VEST_OTHER_V10 1
typedef struct {
    pd_LookupasStaticLookupSource_V10_t target;
} pd_vesting_vest_other_V10_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V10 2
typedef struct {
    pd_LookupasStaticLookupSource_V10_t target;
    pd_VestingInfo_V10_t schedule;
} pd_vesting_vested_transfer_V10_t;

#define PD_CALL_VESTING_FORCE_VESTED_TRANSFER_V10 3
typedef struct {
    pd_LookupasStaticLookupSource_V10_t source;
    pd_LookupasStaticLookupSource_V10_t target;
    pd_VestingInfo_V10_t schedule;
} pd_vesting_force_vested_transfer_V10_t;

#define PD_CALL_VESTING_MERGE_SCHEDULES_V10 4
typedef struct {
    pd_u32_t schedule1_index;
    pd_u32_t schedule2_index;
} pd_vesting_merge_schedules_V10_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V10 0
typedef struct {
    pd_AccountIdLookupOfT_V10_t account;
} pd_identity_add_registrar_V10_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V10 3
typedef struct {
} pd_identity_clear_identity_V10_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V10 4
typedef struct {
    pd_Compactu32_t reg_index;
    pd_Compactu128_t max_fee;
} pd_identity_request_judgement_V10_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V10 5
typedef struct {
    pd_RegistrarIndex_V10_t reg_index;
} pd_identity_cancel_request_V10_t;

#define PD_CALL_IDENTITY_SET_FEE_V10 6
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t fee;
} pd_identity_set_fee_V10_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V10 7
typedef struct {
    pd_Compactu32_t index;
    pd_AccountId_V10_t new_;
} pd_identity_set_account_id_V10_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V10 10
typedef struct {
    pd_LookupasStaticLookupSource_V10_t target;
} pd_identity_kill_identity_V10_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V10 13
typedef struct {
    pd_LookupasStaticLookupSource_V10_t sub;
} pd_identity_remove_sub_V10_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V10 14
typedef struct {
} pd_identity_quit_sub_V10_t;

#define PD_CALL_PROXY_ADD_PROXY_V10 1
typedef struct {
    pd_AccountId_V10_t delegate;
    pd_ProxyType_V10_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V10_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V10 2
typedef struct {
    pd_AccountId_V10_t delegate;
    pd_ProxyType_V10_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V10_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V10 3
typedef struct {
} pd_proxy_remove_proxies_V10_t;

#define PD_CALL_PROXY_ANONYMOUS_V10 4
typedef struct {
    pd_ProxyType_V10_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V10_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V10 5
typedef struct {
    pd_AccountId_V10_t spawner;
    pd_ProxyType_V10_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V10_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V10 9
typedef struct {
    pd_AccountIdLookupOfT_V10_t delegate;
    pd_AccountIdLookupOfT_V10_t real;
    pd_OptionProxyType_V10_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V10_t;

#define PD_CALL_ELECTIONPROVIDERMULTIPHASE_GOVERNANCE_FALLBACK_V10 4
typedef struct {
    pd_Optionu32_t maybe_max_voters;
    pd_Optionu32_t maybe_max_targets;
} pd_electionprovidermultiphase_governance_fallback_V10_t;

#define PD_CALL_VOTERLIST_REBAG_V10 0
typedef struct {
    pd_AccountId_V10_t dislocated;
} pd_voterlist_rebag_V10_t;

#define PD_CALL_VOTERLIST_PUT_IN_FRONT_OF_V10 1
typedef struct {
    pd_AccountId_V10_t lighter;
} pd_voterlist_put_in_front_of_V10_t;

#define PD_CALL_CONFIGURATION_SET_VALIDATION_UPGRADE_COOLDOWN_V10 0
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_validation_upgrade_cooldown_V10_t;

#define PD_CALL_CONFIGURATION_SET_VALIDATION_UPGRADE_DELAY_V10 1
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_validation_upgrade_delay_V10_t;

#define PD_CALL_CONFIGURATION_SET_CODE_RETENTION_PERIOD_V10 2
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_code_retention_period_V10_t;

#define PD_CALL_CONFIGURATION_SET_MAX_CODE_SIZE_V10 3
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_code_size_V10_t;

#define PD_CALL_CONFIGURATION_SET_MAX_POV_SIZE_V10 4
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_pov_size_V10_t;

#define PD_CALL_CONFIGURATION_SET_MAX_HEAD_DATA_SIZE_V10 5
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_head_data_size_V10_t;

#define PD_CALL_CONFIGURATION_SET_PARATHREAD_CORES_V10 6
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_parathread_cores_V10_t;

#define PD_CALL_CONFIGURATION_SET_PARATHREAD_RETRIES_V10 7
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_parathread_retries_V10_t;

#define PD_CALL_CONFIGURATION_SET_GROUP_ROTATION_FREQUENCY_V10 8
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_group_rotation_frequency_V10_t;

#define PD_CALL_CONFIGURATION_SET_CHAIN_AVAILABILITY_PERIOD_V10 9
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_chain_availability_period_V10_t;

#define PD_CALL_CONFIGURATION_SET_THREAD_AVAILABILITY_PERIOD_V10 10
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_thread_availability_period_V10_t;

#define PD_CALL_CONFIGURATION_SET_SCHEDULING_LOOKAHEAD_V10 11
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_scheduling_lookahead_V10_t;

#define PD_CALL_CONFIGURATION_SET_MAX_VALIDATORS_PER_CORE_V10 12
typedef struct {
    pd_Optionu32_t new_;
} pd_configuration_set_max_validators_per_core_V10_t;

#define PD_CALL_CONFIGURATION_SET_MAX_VALIDATORS_V10 13
typedef struct {
    pd_Optionu32_t new_;
} pd_configuration_set_max_validators_V10_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_POST_CONCLUSION_ACCEPTANCE_PERIOD_V10 15
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_dispute_post_conclusion_acceptance_period_V10_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_MAX_SPAM_SLOTS_V10 16
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_dispute_max_spam_slots_V10_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_CONCLUSION_BY_TIME_OUT_PERIOD_V10 17
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_dispute_conclusion_by_time_out_period_V10_t;

#define PD_CALL_CONFIGURATION_SET_NO_SHOW_SLOTS_V10 18
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_no_show_slots_V10_t;

#define PD_CALL_CONFIGURATION_SET_N_DELAY_TRANCHES_V10 19
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_n_delay_tranches_V10_t;

#define PD_CALL_CONFIGURATION_SET_ZEROTH_DELAY_TRANCHE_WIDTH_V10 20
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_zeroth_delay_tranche_width_V10_t;

#define PD_CALL_CONFIGURATION_SET_NEEDED_APPROVALS_V10 21
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_needed_approvals_V10_t;

#define PD_CALL_CONFIGURATION_SET_RELAY_VRF_MODULO_SAMPLES_V10 22
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_relay_vrf_modulo_samples_V10_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_QUEUE_COUNT_V10 23
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_queue_count_V10_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_QUEUE_SIZE_V10 24
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_queue_size_V10_t;

#define PD_CALL_CONFIGURATION_SET_MAX_DOWNWARD_MESSAGE_SIZE_V10 25
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_downward_message_size_V10_t;

#define PD_CALL_CONFIGURATION_SET_UMP_SERVICE_TOTAL_WEIGHT_V10 26
typedef struct {
    pd_Weight_V10_t new_;
} pd_configuration_set_ump_service_total_weight_V10_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_MESSAGE_SIZE_V10 27
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_message_size_V10_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_MESSAGE_NUM_PER_CANDIDATE_V10 28
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_message_num_per_candidate_V10_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_OPEN_REQUEST_TTL_V10 29
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_open_request_ttl_V10_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_SENDER_DEPOSIT_V10 30
typedef struct {
    pd_Balance_t new_;
} pd_configuration_set_hrmp_sender_deposit_V10_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_RECIPIENT_DEPOSIT_V10 31
typedef struct {
    pd_Balance_t new_;
} pd_configuration_set_hrmp_recipient_deposit_V10_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_CAPACITY_V10 32
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_capacity_V10_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_TOTAL_SIZE_V10 33
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_total_size_V10_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARACHAIN_INBOUND_CHANNELS_V10 34
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parachain_inbound_channels_V10_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARATHREAD_INBOUND_CHANNELS_V10 35
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parathread_inbound_channels_V10_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_MESSAGE_SIZE_V10 36
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_message_size_V10_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARACHAIN_OUTBOUND_CHANNELS_V10 37
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parachain_outbound_channels_V10_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARATHREAD_OUTBOUND_CHANNELS_V10 38
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parathread_outbound_channels_V10_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_MESSAGE_NUM_PER_CANDIDATE_V10 39
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_message_num_per_candidate_V10_t;

#define PD_CALL_CONFIGURATION_SET_UMP_MAX_INDIVIDUAL_WEIGHT_V10 40
typedef struct {
    pd_Weight_V10_t new_;
} pd_configuration_set_ump_max_individual_weight_V10_t;

#define PD_CALL_CONFIGURATION_SET_PVF_CHECKING_ENABLED_V10 41
typedef struct {
    pd_bool_t new_;
} pd_configuration_set_pvf_checking_enabled_V10_t;

#define PD_CALL_CONFIGURATION_SET_PVF_VOTING_TTL_V10 42
typedef struct {
    pd_SessionIndex_V10_t new_;
} pd_configuration_set_pvf_voting_ttl_V10_t;

#define PD_CALL_CONFIGURATION_SET_MINIMUM_VALIDATION_UPGRADE_DELAY_V10 43
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_minimum_validation_upgrade_delay_V10_t;

#define PD_CALL_CONFIGURATION_SET_BYPASS_CONSISTENCY_CHECK_V10 44
typedef struct {
    pd_bool_t new_;
} pd_configuration_set_bypass_consistency_check_V10_t;

#define PD_CALL_INITIALIZER_FORCE_APPROVE_V10 0
typedef struct {
    pd_BlockNumber_t up_to;
} pd_initializer_force_approve_V10_t;

#define PD_CALL_HRMP_FORCE_PROCESS_HRMP_OPEN_V10 4
typedef struct {
    pd_u32_t channels;
} pd_hrmp_force_process_hrmp_open_V10_t;

#define PD_CALL_HRMP_FORCE_PROCESS_HRMP_CLOSE_V10 5
typedef struct {
    pd_u32_t channels;
} pd_hrmp_force_process_hrmp_close_V10_t;

#define PD_CALL_REGISTRAR_RESERVE_V10 5
typedef struct {
} pd_registrar_reserve_V10_t;

#define PD_CALL_AUCTIONS_NEW_AUCTION_V10 0
typedef struct {
    pd_Compactu32_t duration;
    pd_Compactu32_t lease_period_index;
} pd_auctions_new_auction_V10_t;

#define PD_CALL_AUCTIONS_BID_V10 1
typedef struct {
    pd_Compactu32_t para;
    pd_Compactu32_t auction_index;
    pd_Compactu32_t first_slot;
    pd_Compactu32_t last_slot;
    pd_CompactBalance_t amount;
} pd_auctions_bid_V10_t;

#define PD_CALL_AUCTIONS_CANCEL_AUCTION_V10 2
typedef struct {
} pd_auctions_cancel_auction_V10_t;

#endif

typedef union {
    pd_balances_transfer_all_V10_t balances_transfer_all_V10;
    pd_staking_bond_V10_t staking_bond_V10;
    pd_staking_bond_extra_V10_t staking_bond_extra_V10;
    pd_staking_unbond_V10_t staking_unbond_V10;
    pd_staking_withdraw_unbonded_V10_t staking_withdraw_unbonded_V10;
    pd_staking_validate_V10_t staking_validate_V10;
    pd_staking_nominate_V10_t staking_nominate_V10;
    pd_staking_chill_V10_t staking_chill_V10;
    pd_staking_set_payee_V10_t staking_set_payee_V10;
    pd_staking_set_controller_V10_t staking_set_controller_V10;
    pd_staking_payout_stakers_V10_t staking_payout_stakers_V10;
    pd_staking_rebond_V10_t staking_rebond_V10;
    pd_session_set_keys_V10_t session_set_keys_V10;
    pd_session_purge_keys_V10_t session_purge_keys_V10;
    pd_utility_batch_V10_t utility_batch_V10;
    pd_utility_batch_all_V10_t utility_batch_all_V10;
    pd_utility_force_batch_V10_t utility_force_batch_V10;
#ifdef SUBSTRATE_PARSER_FULL
    pd_preimage_note_preimage_V10_t preimage_note_preimage_V10;
    pd_preimage_unnote_preimage_V10_t preimage_unnote_preimage_V10;
    pd_preimage_request_preimage_V10_t preimage_request_preimage_V10;
    pd_preimage_unrequest_preimage_V10_t preimage_unrequest_preimage_V10;
    pd_timestamp_set_V10_t timestamp_set_V10;
    pd_indices_claim_V10_t indices_claim_V10;
    pd_indices_transfer_V10_t indices_transfer_V10;
    pd_indices_free_V10_t indices_free_V10;
    pd_indices_force_transfer_V10_t indices_force_transfer_V10;
    pd_indices_freeze_V10_t indices_freeze_V10;
    pd_balances_force_unreserve_V10_t balances_force_unreserve_V10;
    pd_staking_set_validator_count_V10_t staking_set_validator_count_V10;
    pd_staking_increase_validator_count_V10_t staking_increase_validator_count_V10;
    pd_staking_force_no_eras_V10_t staking_force_no_eras_V10;
    pd_staking_force_new_era_V10_t staking_force_new_era_V10;
    pd_staking_set_invulnerables_V10_t staking_set_invulnerables_V10;
    pd_staking_force_unstake_V10_t staking_force_unstake_V10;
    pd_staking_force_new_era_always_V10_t staking_force_new_era_always_V10;
    pd_staking_cancel_deferred_slash_V10_t staking_cancel_deferred_slash_V10;
    pd_staking_set_history_depth_V10_t staking_set_history_depth_V10;
    pd_staking_reap_stash_V10_t staking_reap_stash_V10;
    pd_staking_kick_V10_t staking_kick_V10;
    pd_staking_chill_other_V10_t staking_chill_other_V10;
    pd_staking_force_apply_min_commission_V10_t staking_force_apply_min_commission_V10;
    pd_sudo_set_key_V10_t sudo_set_key_V10;
    pd_sudo_sudo_V10_t sudo_sudo_V10;
    pd_sudo_sudo_unchecked_weight_V10_t sudo_sudo_unchecked_weight_V10;
    pd_grandpa_note_stalled_V10_t grandpa_note_stalled_V10;
    pd_council_set_members_V10_t council_set_members_V10;
    pd_council_execute_V10_t council_execute_V10;
    pd_council_propose_V10_t council_propose_V10;
    pd_council_vote_V10_t council_vote_V10;
    pd_council_close_old_weight_V10_t council_close_old_weight_V10;
    pd_council_disapprove_proposal_V10_t council_disapprove_proposal_V10;
    pd_council_close_V10_t council_close_V10;
    pd_technicalcommittee_set_members_V10_t technicalcommittee_set_members_V10;
    pd_technicalcommittee_execute_V10_t technicalcommittee_execute_V10;
    pd_technicalcommittee_propose_V10_t technicalcommittee_propose_V10;
    pd_technicalcommittee_vote_V10_t technicalcommittee_vote_V10;
    pd_technicalcommittee_close_V10_t technicalcommittee_close_V10;
    pd_technicalcommittee_disapprove_proposal_V10_t technicalcommittee_disapprove_proposal_V10;
    pd_treasury_propose_spend_V10_t treasury_propose_spend_V10;
    pd_treasury_reject_proposal_V10_t treasury_reject_proposal_V10;
    pd_treasury_approve_proposal_V10_t treasury_approve_proposal_V10;
    pd_treasury_spend_V10_t treasury_spend_V10;
    pd_treasury_remove_approval_V10_t treasury_remove_approval_V10;
    pd_vesting_vest_V10_t vesting_vest_V10;
    pd_vesting_vest_other_V10_t vesting_vest_other_V10;
    pd_vesting_vested_transfer_V10_t vesting_vested_transfer_V10;
    pd_vesting_force_vested_transfer_V10_t vesting_force_vested_transfer_V10;
    pd_vesting_merge_schedules_V10_t vesting_merge_schedules_V10;
    pd_identity_add_registrar_V10_t identity_add_registrar_V10;
    pd_identity_clear_identity_V10_t identity_clear_identity_V10;
    pd_identity_request_judgement_V10_t identity_request_judgement_V10;
    pd_identity_cancel_request_V10_t identity_cancel_request_V10;
    pd_identity_set_fee_V10_t identity_set_fee_V10;
    pd_identity_set_account_id_V10_t identity_set_account_id_V10;
    pd_identity_kill_identity_V10_t identity_kill_identity_V10;
    pd_identity_remove_sub_V10_t identity_remove_sub_V10;
    pd_identity_quit_sub_V10_t identity_quit_sub_V10;
    pd_proxy_add_proxy_V10_t proxy_add_proxy_V10;
    pd_proxy_remove_proxy_V10_t proxy_remove_proxy_V10;
    pd_proxy_remove_proxies_V10_t proxy_remove_proxies_V10;
    pd_proxy_anonymous_V10_t proxy_anonymous_V10;
    pd_proxy_kill_anonymous_V10_t proxy_kill_anonymous_V10;
    pd_proxy_proxy_announced_V10_t proxy_proxy_announced_V10;
    pd_electionprovidermultiphase_governance_fallback_V10_t electionprovidermultiphase_governance_fallback_V10;
    pd_voterlist_rebag_V10_t voterlist_rebag_V10;
    pd_voterlist_put_in_front_of_V10_t voterlist_put_in_front_of_V10;
    pd_configuration_set_validation_upgrade_cooldown_V10_t configuration_set_validation_upgrade_cooldown_V10;
    pd_configuration_set_validation_upgrade_delay_V10_t configuration_set_validation_upgrade_delay_V10;
    pd_configuration_set_code_retention_period_V10_t configuration_set_code_retention_period_V10;
    pd_configuration_set_max_code_size_V10_t configuration_set_max_code_size_V10;
    pd_configuration_set_max_pov_size_V10_t configuration_set_max_pov_size_V10;
    pd_configuration_set_max_head_data_size_V10_t configuration_set_max_head_data_size_V10;
    pd_configuration_set_parathread_cores_V10_t configuration_set_parathread_cores_V10;
    pd_configuration_set_parathread_retries_V10_t configuration_set_parathread_retries_V10;
    pd_configuration_set_group_rotation_frequency_V10_t configuration_set_group_rotation_frequency_V10;
    pd_configuration_set_chain_availability_period_V10_t configuration_set_chain_availability_period_V10;
    pd_configuration_set_thread_availability_period_V10_t configuration_set_thread_availability_period_V10;
    pd_configuration_set_scheduling_lookahead_V10_t configuration_set_scheduling_lookahead_V10;
    pd_configuration_set_max_validators_per_core_V10_t configuration_set_max_validators_per_core_V10;
    pd_configuration_set_max_validators_V10_t configuration_set_max_validators_V10;
    pd_configuration_set_dispute_post_conclusion_acceptance_period_V10_t configuration_set_dispute_post_conclusion_acceptance_period_V10;
    pd_configuration_set_dispute_max_spam_slots_V10_t configuration_set_dispute_max_spam_slots_V10;
    pd_configuration_set_dispute_conclusion_by_time_out_period_V10_t configuration_set_dispute_conclusion_by_time_out_period_V10;
    pd_configuration_set_no_show_slots_V10_t configuration_set_no_show_slots_V10;
    pd_configuration_set_n_delay_tranches_V10_t configuration_set_n_delay_tranches_V10;
    pd_configuration_set_zeroth_delay_tranche_width_V10_t configuration_set_zeroth_delay_tranche_width_V10;
    pd_configuration_set_needed_approvals_V10_t configuration_set_needed_approvals_V10;
    pd_configuration_set_relay_vrf_modulo_samples_V10_t configuration_set_relay_vrf_modulo_samples_V10;
    pd_configuration_set_max_upward_queue_count_V10_t configuration_set_max_upward_queue_count_V10;
    pd_configuration_set_max_upward_queue_size_V10_t configuration_set_max_upward_queue_size_V10;
    pd_configuration_set_max_downward_message_size_V10_t configuration_set_max_downward_message_size_V10;
    pd_configuration_set_ump_service_total_weight_V10_t configuration_set_ump_service_total_weight_V10;
    pd_configuration_set_max_upward_message_size_V10_t configuration_set_max_upward_message_size_V10;
    pd_configuration_set_max_upward_message_num_per_candidate_V10_t configuration_set_max_upward_message_num_per_candidate_V10;
    pd_configuration_set_hrmp_open_request_ttl_V10_t configuration_set_hrmp_open_request_ttl_V10;
    pd_configuration_set_hrmp_sender_deposit_V10_t configuration_set_hrmp_sender_deposit_V10;
    pd_configuration_set_hrmp_recipient_deposit_V10_t configuration_set_hrmp_recipient_deposit_V10;
    pd_configuration_set_hrmp_channel_max_capacity_V10_t configuration_set_hrmp_channel_max_capacity_V10;
    pd_configuration_set_hrmp_channel_max_total_size_V10_t configuration_set_hrmp_channel_max_total_size_V10;
    pd_configuration_set_hrmp_max_parachain_inbound_channels_V10_t configuration_set_hrmp_max_parachain_inbound_channels_V10;
    pd_configuration_set_hrmp_max_parathread_inbound_channels_V10_t configuration_set_hrmp_max_parathread_inbound_channels_V10;
    pd_configuration_set_hrmp_channel_max_message_size_V10_t configuration_set_hrmp_channel_max_message_size_V10;
    pd_configuration_set_hrmp_max_parachain_outbound_channels_V10_t configuration_set_hrmp_max_parachain_outbound_channels_V10;
    pd_configuration_set_hrmp_max_parathread_outbound_channels_V10_t configuration_set_hrmp_max_parathread_outbound_channels_V10;
    pd_configuration_set_hrmp_max_message_num_per_candidate_V10_t configuration_set_hrmp_max_message_num_per_candidate_V10;
    pd_configuration_set_ump_max_individual_weight_V10_t configuration_set_ump_max_individual_weight_V10;
    pd_configuration_set_pvf_checking_enabled_V10_t configuration_set_pvf_checking_enabled_V10;
    pd_configuration_set_pvf_voting_ttl_V10_t configuration_set_pvf_voting_ttl_V10;
    pd_configuration_set_minimum_validation_upgrade_delay_V10_t configuration_set_minimum_validation_upgrade_delay_V10;
    pd_configuration_set_bypass_consistency_check_V10_t configuration_set_bypass_consistency_check_V10;
    pd_initializer_force_approve_V10_t initializer_force_approve_V10;
    pd_hrmp_force_process_hrmp_open_V10_t hrmp_force_process_hrmp_open_V10;
    pd_hrmp_force_process_hrmp_close_V10_t hrmp_force_process_hrmp_close_V10;
    pd_registrar_reserve_V10_t registrar_reserve_V10;
    pd_auctions_new_auction_V10_t auctions_new_auction_V10;
    pd_auctions_bid_V10_t auctions_bid_V10;
    pd_auctions_cancel_auction_V10_t auctions_cancel_auction_V10;
#endif
} pd_MethodBasic_V10_t;

#define PD_CALL_BALANCES_TRANSFER_V10 0
typedef struct {
    pd_LookupasStaticLookupSource_V10_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V10_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V10 2
typedef struct {
    pd_LookupasStaticLookupSource_V10_t source;
    pd_LookupasStaticLookupSource_V10_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V10_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V10 3
typedef struct {
    pd_LookupasStaticLookupSource_V10_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V10_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_REMARK_V10 0
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_V10_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V10 1
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V10_t;

#define PD_CALL_SYSTEM_SET_CODE_V10 2
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V10_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V10 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V10_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V10 7
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_with_event_V10_t;

#define PD_CALL_BALANCES_SET_BALANCE_V10 1
typedef struct {
    pd_LookupasStaticLookupSource_V10_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V10_t;

#define PD_CALL_PROXY_PROXY_V10 0
typedef struct {
    pd_AccountIdLookupOfT_V10_t real;
    pd_OptionProxyType_V10_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V10_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V10 0
typedef struct {
    pd_VecAccountId_V10_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V10_t;

#define PD_CALL_MULTISIG_AS_MULTI_V10 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V10_t other_signatories;
    pd_OptionTimepoint_V10_t maybe_timepoint;
    pd_Call_t call;
    pd_Weight_t max_weight;
} pd_multisig_as_multi_V10_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V10 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V10_t other_signatories;
    pd_OptionTimepoint_V10_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_t max_weight;
} pd_multisig_approve_as_multi_V10_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V10 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V10_t other_signatories;
    pd_Timepoint_V10_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V10_t;

#endif

typedef union {
    pd_balances_transfer_V10_t balances_transfer_V10;
    pd_balances_force_transfer_V10_t balances_force_transfer_V10;
    pd_balances_transfer_keep_alive_V10_t balances_transfer_keep_alive_V10;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_remark_V10_t system_remark_V10;
    pd_system_set_heap_pages_V10_t system_set_heap_pages_V10;
    pd_system_set_code_V10_t system_set_code_V10;
    pd_system_set_code_without_checks_V10_t system_set_code_without_checks_V10;
    pd_system_remark_with_event_V10_t system_remark_with_event_V10;
    pd_balances_set_balance_V10_t balances_set_balance_V10;
    pd_proxy_proxy_V10_t proxy_proxy_V10;
    pd_multisig_as_multi_threshold_1_V10_t multisig_as_multi_threshold_1_V10;
    pd_multisig_as_multi_V10_t multisig_as_multi_V10;
    pd_multisig_approve_as_multi_V10_t multisig_approve_as_multi_V10;
    pd_multisig_cancel_as_multi_V10_t multisig_cancel_as_multi_V10;
#endif
} pd_MethodNested_V10_t;

typedef union {
    pd_MethodBasic_V10_t basic;
    pd_MethodNested_V10_t nested;
} pd_Method_V10_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
