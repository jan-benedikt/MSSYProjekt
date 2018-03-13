# MSSY

### úkoly
- connect (Dynamicke přidělování adres)
- discovery (Broadcastem [0xFFF])


## Instalace/config
M:\MSSY\Software\lightweight_mesh_stack_v1.2.1

1. udelat definice 
[LVM Developer-Guide_Application]{./podklady/Atmel-42028-Lightweight-Mesh-Developer-Guide_Application-Note_AVR2130.pdf}

strana 7
Required Definitions

    F_CPU=8000000
    PHY_ATMEGARFR2
    HAL_ATMEGA256RFR2




- import
sys ,hal, nwk, phy -> do rootu


    include paths
    sys/inc
    phy/atmegarfr2/inc
    hal/atmegarf2r/inc
    nwk/inc
    hal/driver/atmega256rfr2
	..


vsechny nastaveni pujdou do config.h

.
 * [LVMdemo](./LVMdemo)
 * [hal](./hal)
   * [atmega256rfr2](./atmega256rfr2/file21.ext)
 * [nwk](./nwk)
   * [inc](./nwk/inc)
   * [src](./nwk/src)
 * [phy](./phy)
 * [sys](./sys)
   * [inc](./sys/inc)
   * [src](./sys/src)
 * [config.h](./config.h)
`


app_addr ->1


NWK_openEndpoint (cislo socketu, callback funkce po prijeti dat)

po naplneni struktu
nwk_datareq odeslia data

