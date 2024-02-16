# Ledger DENTNet app

Forked from [ledger-polkadot](https://github.com/Zondax/ledger-polkadot)

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

-------------------

This project contains the DENTNet app (https://www.dentnet.io/) for Ledger Nano S and X.

- Ledger Nano S/X BOLOS app
- Specs / Documentation
- C++ unit tests
- Zemu tests

For more information:
- [How to build](docs/build.md)
- [How to install](docs/install.md)

## ATTENTION

Please:

- **Do not use in production**
- **Do not use a Ledger device with funds for development purposes.**
- **Have a separate and marked device that is used ONLY for development and testing**

# DENTNet 10.9240.x

## System

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Remark |    | :heavy_check_mark: | :heavy_check_mark: | `Bytes` remark <br/> | 
|Set heap pages |    | :heavy_check_mark: | :heavy_check_mark: | `u64` pages <br/> | 
|Set code |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` code <br/> | 
|Set code without checks |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` code <br/> | 
|Set storage |    |   |   | `VecKeyValue` items <br/> | 
|Kill storage |    |   |   | `VecKey` keys <br/> | 
|Kill prefix |    |   |   | `Key` prefix <br/>`u32` subkeys <br/> | 
|Remark with event |    | :heavy_check_mark: | :heavy_check_mark: | `Bytes` remark <br/> | 

## Preimage

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Note preimage |    | :heavy_check_mark: |   | `Vecu8` bytes <br/> |
|Unnote preimage |    | :heavy_check_mark: |   | `Hash` hash <br/> |
|Request preimage |    | :heavy_check_mark: |   | `Hash` hash <br/> |
|Unrequest preimage |    | :heavy_check_mark: |   | `Hash` hash <br/> |

## Timestamp

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set |    | :heavy_check_mark: |   | `Compactu64` now <br/> | 

## Indices

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Claim |    | :heavy_check_mark: |   | `AccountIndex` index <br/> | 
|Transfer |    | :heavy_check_mark: |   | `AccountId` new_ <br/>`AccountIndex` index <br/> | 
|Free |    | :heavy_check_mark: |   | `AccountIndex` index <br/> | 
|Force transfer |    | :heavy_check_mark: |   | `AccountId` new_ <br/>`AccountIndex` index <br/>`bool` freeze <br/> | 
|Freeze |    | :heavy_check_mark: |   | `AccountIndex` index <br/> | 

## Balances

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> | 
|Set balance |    | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` who <br/>`CompactBalance` new_free <br/>`CompactBalance` new_reserved <br/> | 
|Force transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` source <br/>`LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> | 
|Transfer keep alive | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> | 
|Transfer all | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`bool` keep_alive <br/> | 
|Force unreserve |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/>`Balance` amount <br/> | 

## Staking

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Bond | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` controller <br/>`CompactBalance` amount <br/>`RewardDestination` payee <br/> | 
|Bond extra | :heavy_check_mark:  | :heavy_check_mark: |   | `CompactBalance` amount <br/> | 
|Unbond | :heavy_check_mark:  | :heavy_check_mark: |   | `CompactBalance` amount <br/> | 
|Withdraw Unbonded | :heavy_check_mark:  | :heavy_check_mark: |   | `u32` num_slashing_spans <br/> | 
|Validate | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `ValidatorPrefs` prefs <br/> | 
|Nominate | :heavy_check_mark:  | :heavy_check_mark: |   | `VecLookupasStaticLookupSource` targets <br/> | 
|Chill | :heavy_check_mark:  | :heavy_check_mark: |   |  | 
|Set payee | :heavy_check_mark:  | :heavy_check_mark: |   | `RewardDestination` payee <br/> | 
|Set controller | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` controller <br/> | 
|Set validator count |    | :heavy_check_mark: |   | `Compactu32` new_ <br/> | 
|Increase validator count |    | :heavy_check_mark: |   | `Compactu32` additional <br/> | 
|Scale validator count |    |   |   | `Percent` factor <br/> | 
|Force no eras |    | :heavy_check_mark: |   |  | 
|Force new era |    | :heavy_check_mark: |   |  | 
|Set invulnerables |    | :heavy_check_mark: |   | `VecAccountId` invulnerables <br/> | 
|Force unstake |    | :heavy_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> | 
|Force new era always |    | :heavy_check_mark: |   |  | 
|Cancel deferred slash |    | :heavy_check_mark: |   | `EraIndex` era <br/>`Vecu32` slash_indices <br/> | 
|Payout stakers | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `AccountId` validator_stash <br/>`EraIndex` era <br/> | 
|Rebond | :heavy_check_mark:  | :heavy_check_mark: |   | `CompactBalance` amount <br/> | 
|Set history depth |    | :heavy_check_mark: |   | `Compactu32` new_history_depth <br/>`Compactu32` era_items_deleted <br/> | 
|Reap stash |    | :heavy_check_mark: |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> | 
|Kick |    | :heavy_check_mark: |   | `VecLookupasStaticLookupSource` who <br/> | 
|Set staking configs |    |   |   | `ConfigOpBalanceOfT` min_nominator_bond <br/>`ConfigOpBalanceOfT` min_validator_bond <br/>`ConfigOpu32` max_nominator_count <br/>`ConfigOpu32` max_validator_count <br/>`ConfigOpPercent` chill_threshold <br/>`ConfigOpPerbill` min_commission <br/> | 
|Chill other |    | :heavy_check_mark: |   | `AccountId` controller <br/> | 
|Force apply min commission |    | :heavy_check_mark: |   | `AccountId` validator_stash <br/> | 

## Session

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set keys | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `Keys` keys <br/>`Bytes` proof <br/> | 
|Purge keys | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: |  | 

## Assets

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Transfer | :heavy_check_mark:  | :heavy_check_mark: |  | `Compactu32` asset_id <br />`LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/>| 
|Transfer keep alive | :heavy_check_mark:  | :heavy_check_mark: |   | `Compactu32` asset_id <br /> `LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> | 

## Sudo

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
| Set key |    | :heavy_check_mark: |   | `AccountId` new_ <br/> | 
| Sudo |    | :heavy_check_mark: |   | `Call` call <br/> | 
| Sudo as |    |  |   | `AccountId` who <br/>, `Call` call <br/> | 
| Sudo unchecked weight |    | :heavy_check_mark: |   | `Call` call <br/> | 


## Grandpa

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Report equivocation |    |   |   | `BoxEquivocationProofHashBlockNumber` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|Report equivocation unsigned |    |   |   | `BoxEquivocationProofHashBlockNumber` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|Note stalled |    | :heavy_check_mark: |   | `BlockNumber` delay <br/>`BlockNumber` best_finalized_block_number <br/> | 

## Council

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set members |    |   |   | `VecAccountId` new_members <br/>`OptionAccountId` prime <br/>`MemberCount` old_count <br/> | 
|Execute |    |   |   | `BoxTasConfigIProposal` proposal <br/>`Compactu32` length_bound <br/> | 
|Propose |    |   |   | `Compactu32` threshold <br/>`BoxTasConfigIProposal` proposal <br/>`Compactu32` length_bound <br/> | 
|Vote |    | :heavy_check_mark: |   | `Hash` proposal <br/>`Compactu32` index <br/>`bool` approve <br/> | 
|Close old weight |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compactu33` index <br/>`Compactu64` proposal_weight_bound <br/>`Compactu32` length_bound <br/> | 
|Disapprove proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> | 
|Close |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compactu33` index <br/>`Weight` proposal_weight_bound <br/>`Compactu32` length_bound <br/> | 

## TechnicalCommittee

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set members |    |   |   | `VecAccountId` new_members <br/>`OptionAccountId` prime <br/>`MemberCount` old_count <br/> | 
|Execute |    |   |   | `BoxTasConfigIProposal` proposal <br/>`Compactu32` length_bound <br/> | 
|Propose |    |   |   | `Compactu32` threshold <br/>`BoxTasConfigIProposal` proposal <br/>`Compactu32` length_bound <br/> | 
|Vote |    | :heavy_check_mark: |   | `Hash` proposal <br/>`Compactu32` index <br/>`bool` approve <br/> | 
|Disapprove proposal |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/> | 
|Close |    | :heavy_check_mark: |   | `Hash` proposal_hash <br/>`Compactu32` index <br/>`Weight` proposal_weight_bound <br/>`Compactu32` length_bound <br/> | 

## Treasury

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose spend |    | :heavy_check_mark: |   | `CompactBalance` amount <br/>`LookupasStaticLookupSource` beneficiary <br/> | 
|Reject proposal |    | :heavy_check_mark: |   | `Compactu32` proposal_id <br/> | 
|Approve proposal |    | :heavy_check_mark: |   | `Compactu32` proposal_id <br/> | 
|Spend |    | :heavy_check_mark: |   | `CompactBalance` amount <br/>`LookupasStaticLookupSource` beneficiary <br/> |
|Remove approval |    | :heavy_check_mark: |   | `Compactu32` proposal_id <br/> |

## Vesting

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Vest |    | :heavy_check_mark: |   |  | 
|Vest other |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` target <br/> | 
|Vested transfer |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` target <br/>`VestingInfo` schedule <br/> | 
|Force vested transfer |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` source <br/>`LookupasStaticLookupSource` target <br/>`VestingInfo` schedule <br/> | 
|Merge schedules |    | :heavy_check_mark: |   | `u32` schedule1_index <br/>`u32` schedule2_index <br/> | 

## Utility

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Batch | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> | 
|As derivative |    |   |   | `u16` index <br/>`Call` call <br/> | 
|Batch all | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> | 
|Dispatch as |    |   |   | `BoxPalletsOrigin` as_origin <br/>`Call` call <br/> | 
|Force batch | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> |
|With weight |    |   |   | `Call` call <br/>`Weight` weight | 

## Identity

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add registrar |    | :heavy_check_mark: |   | `AccountId` account <br/> | 
|Set identity |    |   |   | `BoxIdentityInfoMaxAdditionalFields` info <br/> | 
|Set subs |    |   |   | `VecTupleAccountIdData` subs <br/> | 
|Clear identity |    | :heavy_check_mark: |   |  | 
|Request judgement |    | :heavy_check_mark: |   | `Compactu32` reg_index <br/>`Compactu128` max_fee <br/> | 
|Cancel request |    | :heavy_check_mark: |   | `RegistrarIndex` reg_index <br/> | 
|Set fee |    | :heavy_check_mark: |   | `Compactu32` index <br/>`Compactu128` fee <br/> | 
|Set account id |    | :heavy_check_mark: |   | `Compactu32` index <br/>`AccountId` new_ <br/> | 
|Set fields |    |   |   | `Compactu32` index <br/>`IdentityFields` fields <br/> | 
|Provide judgement |    |   |   | `Compactu32` reg_index <br/>`LookupasStaticLookupSource` target <br/>`JudgementBalanceOfT` judgement <br/> | 
|Kill identity |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` target <br/> | 
|Add sub |    |   |   | `LookupasStaticLookupSource` sub <br/>`Data` data <br/> | 
|Rename sub |    |   |   | `LookupasStaticLookupSource` sub <br/>`Data` data <br/> | 
|Remove sub |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` sub <br/> | 
|Quit sub |    | :heavy_check_mark: |   |  | 

## Proxy

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Proxy |    | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT` real <br/>`OptionProxyType` force_proxy_type <br/>`Call` call <br/> | 
|Add proxy |    | :heavy_check_mark: |   | `AccountIdLookupOfT` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> | 
|Remove proxy |    | :heavy_check_mark: |   | `AccountIdLookupOfT` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> | 
|Remove proxies |    | :heavy_check_mark: |   |  | 
|Anonymous |    | :heavy_check_mark: |   | `ProxyType` proxy_type <br/>`BlockNumber` delay <br/>`u16` index <br/> | 
|Kill pure |    | :heavy_check_mark: |   | `AccountIdLookupOfT` spawner <br/>`ProxyType` proxy_type <br/>`u16` index <br/>`Compactu32` height <br/>`Compactu32` ext_index <br/> | 
|Announce |    |   |   | `AccountIdLookupOfT` real <br/>`CallHashOf` call_hash <br/> | 
|Remove announcement |    |   |   | `AccountIdLookupOfT` real <br/>`CallHashOf` call_hash <br/> | 
|Reject announcement |    |   |   | `AccountIdLookupOfT` delegate <br/>`CallHashOf` call_hash <br/> | 
|Proxy announced |    | :heavy_check_mark: |   | `AccountIdLookupOfT` delegate <br/>`AccountIdLookupOfT` real <br/>`OptionProxyType` force_proxy_type <br/>`Call` call <br/> | 

## Multisig

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|As multi threshold 1 |    | :heavy_check_mark: | :heavy_check_mark: | `VecAccountId` other_signatories <br/>`Call` call <br/> |
|As multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`OpaqueCall` call <br/>`bool` store_call <br/>`Weight` max_weight <br/> |
|Approve as multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`H256` call_hash <br/>`Weight` max_weight <br/> | 
|Cancel as multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`Timepoint` timepoint <br/>`H256` call_hash <br/> | 

## ElectionProviderMultiPhase

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|Submit unsigned |    |   |   | `BoxRawSolutionSolutionOfMinerConfig` raw_solution <br/>`SolutionOrSnapshotSize` witness <br/> |
|Set minimum untrusted score |    |   |   | `OptionElectionScore` maybe_next_score <br/> | 
|Set emergency election result |    |   |   | `SupportsAccountId` supports <br/> |
|Submit |    |   |   | `BoxRawSolutionSolutionOfMinerConfig` raw_solution <br/> |
|Governance fallback |    | :heavy_check_mark: |   | `Optionu32` maybe_max_voters <br/>`Optionu32` maybe_max_targets <br/> |

## NominationPools

| Name                       | Nano S | Nano S / XL        | Nesting            | Arguments                                                                                                                                                                                                               |
| -------------------------- | ------ | ------------------ | ------------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Join                       |        | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>`PoolId`pool_id<br/>                                                                                                                                                                         |
| Bond extra                 |        | :heavy_check_mark: | :heavy_check_mark: | `BondExtraBalanceOfT`extra<br/>                                                                                                                                                                                         |
| Claim payout               |        | :heavy_check_mark: | :heavy_check_mark: |                                                                                                                                                                                                                         |
| Unbond                     |        | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`member_account<br/>`CompactBalance`unbonding_points<br/>                                                                                                                                            |
| Pool withdraw unbonded     |        | :heavy_check_mark: |                    | `PoolId`pool_id<br/>`u32`num_slashing_spans<br/>                                                                                                                                                                        |
| Withdraw Unbonded          |        | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`member_account<br/>`u32`num_slashing_spans<br/>                                                                                                                                                     |
| Create                     |        | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>`AccountIdLookupOfT`root<br/>`AccountIdLookupOfT`nominator<br/>`AccountIdLookupOfT`bouncer<br/>                                                                                              |
| Create with pool id        |        | :heavy_check_mark: |                    | `CompactBalance`amount<br/>`AccountIdLookupOfT`root<br/>`AccountIdLookupOfT`nominator<br/>`AccountIdLookupOfT`bouncer<br/>`PoolId`pool_id<br/>                                                                          |
| Nominate                   |        | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`VecAccountId`validators<br/>                                                                                                                                                                       |
| Set state                  |        | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`PoolState`state<br/>                                                                                                                                                                               |
| Set metadata               |        | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`Vecu8`metadata<br/>                                                                                                                                                                                |
| Set configs                |        | :heavy_check_mark: |                    | `ConfigOpBalanceOfT`min_join_bond<br/>`ConfigOpBalanceOfT`min_create_bond<br/>`ConfigOpu32`max_pools<br/>`ConfigOpu32`max_members<br/>`ConfigOpu32`max_members_per_pool<br/>`ConfigOpPerbill`global_max_commission<br/> |
| Update roles               |        | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`ConfigOpAccountId`new_root<br/>`ConfigOpAccountId`new_nominator<br/>`ConfigOpAccountId`new_bouncer<br/>                                                                                            |
| Chill                      |        | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>                                                                                                                                                                                                    |
| Bond extra other           |        | :heavy_check_mark: |                    | `AccountIdLookupOfT`member<br/>`BondExtraBalanceOfT`extra<br/>                                                                                                                                                          |
| Set claim permission       |        | :heavy_check_mark: | :heavy_check_mark: | `ClaimPermission`permission<br/>                                                                                                                                                                                        |
| Claim payout other         |        | :heavy_check_mark: | :heavy_check_mark: | `AccountId`other<br/>                                                                                                                                                                                                   |
| Set commission             |        | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`OptionTuplePerbillAccountId`new_commission<br/>                                                                                                                                                    |
| Set commission max         |        | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`Perbill`max_commission<br/>                                                                                                                                                                        |
| Set commission change rate |        | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`CommissionChangeRateBlockNumber`change_rate<br/>                                                                                                                                                   |
| Claim commission           |        | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>                                                                                                                                                                                                    |
| Adjust pool deposit        |        | :heavy_check_mark: |                    | `PoolId`pool_id<br/>     


## Sponsor 

| Name                  | Nano S | Nano S / XL        |  Nesting | Arguments                                                                                |
| --------------------- | ------ | ------------------ |  ------- | ---------------------------------------------------------------------------------------- |
| Register Sponsor      |        | :heavy_check_mark: |          | `AccountId`account<br/>                                                                  |
| Remove Sponsor        |        | :heavy_check_mark: |          | `AccountId`account<br/>                                                                  |
