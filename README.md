# Ledger DENTNet app

Forked from [ledger-polkadot](https://github.com/Zondax/ledger-polkadot)

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

---

This project contains the Polkadot Generic app (<https://polkadot.network/>) for Ledger devices with necessary changes for DENTNet legacy support.

**All calls from any Polkadot SDK** chain, including nested ones, will be supported. However, while all methods will function in a nested call, the transaction may be rejected if there is insufficient RAM. 
This situation might arise with the Ledger Nano S, which provides limited memory in comparison to the Ledger Nano S Plus and the Ledger Nano X.

This application also supports the recent Ledger stax device. 

This repository contains:

- Ledger (BOLOS) app
- Specs / Documentation
- C++ unit tests
- Zemu tests

For more information:

- [How to build](docs/build.md)
- :warning:[Formatting Limitations](docs/format.md)

## ATTENTION

Please:

- **Do not use in production**
- **Do not use a Ledger device with funds for development purposes.**
- **Have a separate and marked device that is used ONLY for development and testing**
