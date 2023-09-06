# sBMS

Open-source SmartBMS design made for self-balancing electric vehicles, like EUCs and Onewheels.

## Features

- Max cell configuration of **36S** (or **151.2V**)
- Cell-to-cell balancing with [_ETA3000_](https://www.st.com/resource/en/datasheet/dm00748675.pdf)
- Cell voltage monitoring and controlled self-discharge with [_LTC6803-4_](https://www.analog.com/media/en/technical-documentation/data-sheets/680324fa.pdf)
- Pack temperature/humidity sensing with up to 8 [_HDC3022_](https://www.ti.com/lit/ds/symlink/hdc3022.pdf) ICs
- Current sensing with [_TMCS1123_](https://www.ti.com/lit/ds/symlink/tmcs1123.pdf), on discharge **and** charge paths
- Powered by [**_STM32G0B1_**](https://www.st.com/resource/en/datasheet/dm00748675.pdf)
- BMS-Controller communication via **CAN-FD and OpenCyphal**
- Charging over-current protection
- And much more!
