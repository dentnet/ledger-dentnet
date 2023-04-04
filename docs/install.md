# Installation

This should work on both Windows (WSL) and MacOS.

## Prerequisites

- Python 3
- pip
- virtualenv (can be installed with `pip install virtualenv`)

## Installation steps

First download the latest version from the [release page](https://github.com/dentnet/ledger-dentnet/releases) that matches your device:

- Nano S: `installer_nanos.sh` OR `installer_nanos_xl.sh`
- Nano S Plus: `installer_nanos_plus.sh`

For Nano S there are two releases, one slimmed down version with a limited set of extrinsics and the XL version with a larger set (refer to README for a list). For Nano S Plus the standard version contains all supported extrinsics. 

Place the downloaded file in a directory and create and activate a Python virtual environment:

```bash
virtualenv ledger
source ledger/bin/activate
pip install ledgerblue
```

Once `ledgerblue` is installed you can run the installer, e.g.:

```
bash$ ./installer_nanos_plus.sh
Zondax Installer [DENTNet-9.9160.0] [Warning: use only for test/demo apps]
  load    - Load DENTNet app
  delete  - Delete DENTNet app
  version - Show DENTNet app version
````
*Note: You may need to mark the installer as executable first (e.g. using `chmod u+x installer_nanos.sh`)*

To install, connect your Ledger to the computer and unlock it and then run:

`./installer_nanos_plus.sh load`

1. The device will show "Deny unsafe manager", use the navigation keys to show the signature and go to **"Allow unsafe manager"** and confirm.

2. The screen will show the DENTNet app logo and the text "Install app DENTNet" (*if you already have an older version it may prompt you to uninstall it first*). Use the navigation keys to show the version, identifier and signature until you reach "**Perform installation**" and confirm. Enter your PIN and the application will be installed.

3. You can now launch the app from the main menu. It will show a warning that the app is not genuine, navigate through the identifier to "**Open application**" and confirm.

Congratulations, the application is now successfully installed. You can use it on the DENTNet portal to manage your account and sign extrinsics.

## Troubleshooting

If you receive an error code while trying to run the load command, check the following:

- The Ledger is unlocked and on the home screen
- Make sure your Ledger has the latest firmware installed
- You do not already have a version of DENTNet application installed. In that case you may need to manually uninstall it (using `./installer_nanos.sh delete`). You may even need to download the installer for the version you have installed to do this.