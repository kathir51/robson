/* 2 GPF()   3 GPFFS()  4 GOFFS_GPIO()  1 GPC() 5 GPCI
6 GPEC   7 GPCD

 8 GPOS 10 GP16O  9 GPOC 11 GP16I 12 GPIP*/

#include "c_types.h"
#define LSBFIRST  0
#define MSBFIRST  1
#define GPCI_1   7
#define GPCD_1   2   

#define ESP8266_REG_1(addr) *((volatile uint32_t *)(0x60000000+(addr)))
#define ESP8266_DREG_1(addr) *((volatile uint32_t *)(0x3FF00000+(addr)))
#define ESP8266_CLOCK 80000000UL

#define GPEC_1   ESP8266_REG_1(0x314) //GPIO_ENABLE_CLR WO


#define GPC_1(p) ESP8266_REG_1(0x328 + ((p & 0xF) * 4))
uint8 esp8266_gpio[16] = {0x34, 0x18, 0x38, 0x14, 0x3C, 0x40, 0x1C, 0x20, 0x24, 0x28, 0x2C, 0x30, 0x04, 0x08, 0x0C, 0x10};

#define GPF_1(p) ESP8266_REG_1(0x800 + esp8266_gpio(p &0xF))
#define GPFFS0_1  4 //Function Select bit 0
#define GPFFS1_1 5 //Function Select bit 1
#define GPFFS2_1 8 //Function Select bit 2
#define GPFFS_1(f) (((((f) & 4) != 0) << GPFFS2_1) | ((((f) & 2)!=0) << GPFFS1_1) | ((((f) & 1) != 0) << GPFFS0_1))
#define GPFFS_GPIO_1(p) (((p)==0||(p)==2||(p)==4||(p)==5)?0:((p)==16)?1:3)

#define GPOS_1   ESP8266_REG_1(0x304) //GPIO_OUT_SET WO
#define GPOC_1   ESP8266_REG_1(0x308) //GPIO_OUT_CLR WO
#define GP16O_1  ESP8266_REG_1(0x768)
#define GP16E_1  ESP8266_REG_1(0x774)
#define GP16I_1  ESP8266_REG_1(0x78C)
#define GPI_1    ESP8266_REG_1(0x318) 

#define GPIP_1(p) ((GPI_1 & (1 << ((p) & 0xF))) != 0)

void ICACHE_FLASH_ATTR pin_set_output(uint8 pin);
void ICACHE_FLASH_ATTR  pin_set_input(uint8 pin);
void ICACHE_FLASH_ATTR pin_set_high(uint8 pin);
void ICACHE_FLASH_ATTR pin_set_low(uint8 pin);
 int ICACHE_FLASH_ATTR input(uint8 pin);
void ICACHE_FLASH_ATTR set_pin_value (uint8  pin ,uint8 val);
void ICACHE_FLASH_ATTR 
shiftdata(uint8 dataPin, uint8 clockPin, uint8 bitOrder, uint8 val);








