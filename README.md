

# MSSY

### Generating PubKey
	ssh-keygen -t rsa -b 4096 -C "benedikthonza@gmail.com"
	ssh-keygen -t rsa -b 4096 -C "hajda14@gmail.com"

### úkoly
- connect (Dynamicke přidělování adres)
- discovery (Broadcastem [0xFFF])


## Instalace/config
Založíme projekt
 Stáhneme [lightweight_mesh_stack_v1.2.1](./podklady/lightweight_mesh_stack_v1.2.1) 

- vykopírujeme z [lightweight_mesh_stack_v1.2.1](./podklady/lightweight_mesh_stack_v1.2.1) 
	sys ,hal, nwk, phy -> do rootu projektu

1. udelame definice (project -> properties -> symbols)
 * [LVM Developer-Guide_Application](./podklady/Atmel-42028-Lightweight-Mesh-Developer-Guide_Application-Note_AVR2130.pdf)

strana 7
Required Definitions

    F_CPU=8000000
    PHY_ATMEGARFR2
    HAL_ATMEGA256RFR2

1. nadefinujeme cesty (project -> properties -> include paths)
	

        sys/inc
	    phy/atmegarfr2/inc
	    hal/atmegarf2r/inc
	    nwk/inc
	    hal/driver/atmega256rfr2
	    ..


vsechny nastaveni pujdou souboru  do [config.h](./Brana/config.h)

.
 * [Brana](./Brana)
   * [hal](./Brana/hal)
     * [atmega256rfr2](./Brana/hal/atmega256rfr2)
   * [nwk](./Brana/nwk)
     * [inc](./Brana/nwk/inc)
     * [src](./Brana/nwk/src)
   * [phy](./Brana/phy)
     * [atmegarfr2](./Brana/phy/atmegarfr2)
   * [sys](./Brana/sys)
     * [inc](./Brana/sys/inc)
     * [src](./Brana/sys/src)
   * [config.h](./Brana/config.h)
`
### UML
![Alt text](./podklady/diagramy/device_table.png)

### nase workflow

![Alt text](./podklady/diagramy/full.png)


app_addr -> nastavení adresy 


NWK_openEndpoint (cislo socketu, callback funkce po prijeti dat)

po naplneni struktu
nwk_datareq odeslia data

