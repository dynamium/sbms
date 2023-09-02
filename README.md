# sBMS

Open-source SmartBMS design made for self-balancing electric vehicles.

## Features

- Max cell configuration of **36S** (or **151.2V**)
- Cell-to-cell balancing topology with _ETA3000_
- Cell voltage monitoring with [_LTC6803_](https://www.analog.com/media/en/technical-documentation/data-sheets/680324fa.pdf)
- Pack temperature/humidity sensing with [_HDC3022_](https://www.ti.com/lit/ds/symlink/hdc3022.pdf)
- Current sensing with [_TMCS1123_](https://www.ti.com/lit/ds/symlink/tmcs1123.pdf), on discharge **and** charge paths
- Powered by **_STM32G0B1_**
- BMS-Controller communication via **CAN-FD and OpenCyphal**
- Over-current charging protection and no protection on the discharge path
- And much more!
