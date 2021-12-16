/** ******************************************************************************
 *  (c) 2020 Zondax GmbH
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
 ******************************************************************************* */

import Zemu, { DEFAULT_START_OPTIONS } from '@zondax/zemu'
import { newPolkadotApp } from '@zondax/ledger-substrate'
import { APP_SEED, models } from './common'
import Transport from '@ledgerhq/hw-transport'

const defaultOptions = {
  ...DEFAULT_START_OPTIONS,
  logging: true,
  custom: `-s "${APP_SEED}"`,
  X11: false,
}

jest.setTimeout(60000)

beforeAll(async () => {
  await Zemu.checkAndPullImage()
})

const newDentnetApp = (transport: Transport) => {
  const app = newPolkadotApp(transport);
  (<any>app).slip0044 = 0x800002de
  return app;
}

async function activateSecretMode(sim: any) {
  // Get to Zondax.ch menu
  for (let i = 0; i < 3; i += 1) {
    await sim.clickRight()
  }

  // Activate secret features
  for (let i = 0; i < 10; i += 1) {
    await sim.clickBoth()
  }

  let reviewSteps = 7
  if (sim.startOptions.model === 'nanox') {
    reviewSteps = 6
  }

  // Review warning message
  for (let i = 0; i < reviewSteps; i += 1) {
    await sim.clickRight()
  }

  // Accept
  await sim.clickBoth()
}

describe('Standard', function () {
  test.each(models)('main secret menu (%s)', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newDentnetApp(sim.getTransport())

      const dentnet_expected_address = 'dx5r2B9tU5LLvZCkBdfBtM7Nk3vu54fsvWyLb6niJ4tKy1X8r'
      const dentnet_expected_pk = '1b14b80690da0751fca3c3758bbe2ee057f255886d12d7a397fc23799a53ba93'
      const recovery_expected_address = 'dxALTDtpsS9vX7rX6JkD7quhH6APCMjx1tp67DZkEtDVteF67'
      const recovery_expected_pk = 'e1b4d72d27b3e91b9b6116555b4ea17138ddc12ca7cdbab30e2e0509bd848419'

      let resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000)
      console.log(resp)
      expect(resp.address).toEqual(dentnet_expected_address)
      expect(resp.pubKey).toEqual(dentnet_expected_pk)

      await activateSecretMode(sim)

      resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000)
      console.log(resp)
      expect(resp.address).toEqual(recovery_expected_address)
      expect(resp.pubKey).toEqual(recovery_expected_pk)
    } finally {
      await sim.close()
    }
  })
})
