#ifndef INCLUDED_CYFITTERIAR_INC
#define INCLUDED_CYFITTERIAR_INC
    INCLUDE cydeviceiar_trm.inc

/* P2_4 */
P2_4__0__DM__MASK EQU 0x7000
P2_4__0__DM__SHIFT EQU 12
P2_4__0__DR EQU CYREG_PRT2_DR
P2_4__0__HSIOM EQU CYREG_HSIOM_PORT_SEL2
P2_4__0__HSIOM_MASK EQU 0x000F0000
P2_4__0__HSIOM_SHIFT EQU 16
P2_4__0__INTCFG EQU CYREG_PRT2_INTCFG
P2_4__0__INTSTAT EQU CYREG_PRT2_INTSTAT
P2_4__0__MASK EQU 0x10
P2_4__0__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
P2_4__0__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
P2_4__0__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
P2_4__0__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
P2_4__0__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
P2_4__0__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
P2_4__0__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
P2_4__0__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
P2_4__0__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
P2_4__0__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
P2_4__0__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
P2_4__0__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
P2_4__0__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
P2_4__0__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
P2_4__0__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
P2_4__0__PC EQU CYREG_PRT2_PC
P2_4__0__PC2 EQU CYREG_PRT2_PC2
P2_4__0__PORT EQU 2
P2_4__0__PS EQU CYREG_PRT2_PS
P2_4__0__SHIFT EQU 4
P2_4__DR EQU CYREG_PRT2_DR
P2_4__INTCFG EQU CYREG_PRT2_INTCFG
P2_4__INTSTAT EQU CYREG_PRT2_INTSTAT
P2_4__MASK EQU 0x10
P2_4__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
P2_4__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
P2_4__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
P2_4__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
P2_4__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
P2_4__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
P2_4__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
P2_4__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
P2_4__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
P2_4__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
P2_4__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
P2_4__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
P2_4__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
P2_4__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
P2_4__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
P2_4__PC EQU CYREG_PRT2_PC
P2_4__PC2 EQU CYREG_PRT2_PC2
P2_4__PORT EQU 2
P2_4__PS EQU CYREG_PRT2_PS
P2_4__SHIFT EQU 4

/* UART_1_rx */
UART_1_rx__0__DM__MASK EQU 0x07
UART_1_rx__0__DM__SHIFT EQU 0
UART_1_rx__0__DR EQU CYREG_PRT3_DR
UART_1_rx__0__HSIOM EQU CYREG_HSIOM_PORT_SEL3
UART_1_rx__0__HSIOM_MASK EQU 0x0000000F
UART_1_rx__0__HSIOM_SHIFT EQU 0
UART_1_rx__0__INTCFG EQU CYREG_PRT3_INTCFG
UART_1_rx__0__INTSTAT EQU CYREG_PRT3_INTSTAT
UART_1_rx__0__MASK EQU 0x01
UART_1_rx__0__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
UART_1_rx__0__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
UART_1_rx__0__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
UART_1_rx__0__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
UART_1_rx__0__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
UART_1_rx__0__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
UART_1_rx__0__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
UART_1_rx__0__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
UART_1_rx__0__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
UART_1_rx__0__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
UART_1_rx__0__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
UART_1_rx__0__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
UART_1_rx__0__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
UART_1_rx__0__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
UART_1_rx__0__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
UART_1_rx__0__PC EQU CYREG_PRT3_PC
UART_1_rx__0__PC2 EQU CYREG_PRT3_PC2
UART_1_rx__0__PORT EQU 3
UART_1_rx__0__PS EQU CYREG_PRT3_PS
UART_1_rx__0__SHIFT EQU 0
UART_1_rx__DR EQU CYREG_PRT3_DR
UART_1_rx__INTCFG EQU CYREG_PRT3_INTCFG
UART_1_rx__INTSTAT EQU CYREG_PRT3_INTSTAT
UART_1_rx__MASK EQU 0x01
UART_1_rx__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
UART_1_rx__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
UART_1_rx__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
UART_1_rx__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
UART_1_rx__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
UART_1_rx__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
UART_1_rx__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
UART_1_rx__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
UART_1_rx__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
UART_1_rx__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
UART_1_rx__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
UART_1_rx__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
UART_1_rx__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
UART_1_rx__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
UART_1_rx__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
UART_1_rx__PC EQU CYREG_PRT3_PC
UART_1_rx__PC2 EQU CYREG_PRT3_PC2
UART_1_rx__PORT EQU 3
UART_1_rx__PS EQU CYREG_PRT3_PS
UART_1_rx__SHIFT EQU 0

/* UART_1_SCB */
UART_1_SCB__BIST_CONTROL EQU CYREG_SCB1_BIST_CONTROL
UART_1_SCB__BIST_DATA EQU CYREG_SCB1_BIST_DATA
UART_1_SCB__CTRL EQU CYREG_SCB1_CTRL
UART_1_SCB__EZ_DATA00 EQU CYREG_SCB1_EZ_DATA00
UART_1_SCB__EZ_DATA01 EQU CYREG_SCB1_EZ_DATA01
UART_1_SCB__EZ_DATA02 EQU CYREG_SCB1_EZ_DATA02
UART_1_SCB__EZ_DATA03 EQU CYREG_SCB1_EZ_DATA03
UART_1_SCB__EZ_DATA04 EQU CYREG_SCB1_EZ_DATA04
UART_1_SCB__EZ_DATA05 EQU CYREG_SCB1_EZ_DATA05
UART_1_SCB__EZ_DATA06 EQU CYREG_SCB1_EZ_DATA06
UART_1_SCB__EZ_DATA07 EQU CYREG_SCB1_EZ_DATA07
UART_1_SCB__EZ_DATA08 EQU CYREG_SCB1_EZ_DATA08
UART_1_SCB__EZ_DATA09 EQU CYREG_SCB1_EZ_DATA09
UART_1_SCB__EZ_DATA10 EQU CYREG_SCB1_EZ_DATA10
UART_1_SCB__EZ_DATA11 EQU CYREG_SCB1_EZ_DATA11
UART_1_SCB__EZ_DATA12 EQU CYREG_SCB1_EZ_DATA12
UART_1_SCB__EZ_DATA13 EQU CYREG_SCB1_EZ_DATA13
UART_1_SCB__EZ_DATA14 EQU CYREG_SCB1_EZ_DATA14
UART_1_SCB__EZ_DATA15 EQU CYREG_SCB1_EZ_DATA15
UART_1_SCB__EZ_DATA16 EQU CYREG_SCB1_EZ_DATA16
UART_1_SCB__EZ_DATA17 EQU CYREG_SCB1_EZ_DATA17
UART_1_SCB__EZ_DATA18 EQU CYREG_SCB1_EZ_DATA18
UART_1_SCB__EZ_DATA19 EQU CYREG_SCB1_EZ_DATA19
UART_1_SCB__EZ_DATA20 EQU CYREG_SCB1_EZ_DATA20
UART_1_SCB__EZ_DATA21 EQU CYREG_SCB1_EZ_DATA21
UART_1_SCB__EZ_DATA22 EQU CYREG_SCB1_EZ_DATA22
UART_1_SCB__EZ_DATA23 EQU CYREG_SCB1_EZ_DATA23
UART_1_SCB__EZ_DATA24 EQU CYREG_SCB1_EZ_DATA24
UART_1_SCB__EZ_DATA25 EQU CYREG_SCB1_EZ_DATA25
UART_1_SCB__EZ_DATA26 EQU CYREG_SCB1_EZ_DATA26
UART_1_SCB__EZ_DATA27 EQU CYREG_SCB1_EZ_DATA27
UART_1_SCB__EZ_DATA28 EQU CYREG_SCB1_EZ_DATA28
UART_1_SCB__EZ_DATA29 EQU CYREG_SCB1_EZ_DATA29
UART_1_SCB__EZ_DATA30 EQU CYREG_SCB1_EZ_DATA30
UART_1_SCB__EZ_DATA31 EQU CYREG_SCB1_EZ_DATA31
UART_1_SCB__I2C_CFG EQU CYREG_SCB1_I2C_CFG
UART_1_SCB__I2C_CTRL EQU CYREG_SCB1_I2C_CTRL
UART_1_SCB__I2C_M_CMD EQU CYREG_SCB1_I2C_M_CMD
UART_1_SCB__I2C_S_CMD EQU CYREG_SCB1_I2C_S_CMD
UART_1_SCB__I2C_STATUS EQU CYREG_SCB1_I2C_STATUS
UART_1_SCB__INTR_CAUSE EQU CYREG_SCB1_INTR_CAUSE
UART_1_SCB__INTR_I2C_EC EQU CYREG_SCB1_INTR_I2C_EC
UART_1_SCB__INTR_I2C_EC_MASK EQU CYREG_SCB1_INTR_I2C_EC_MASK
UART_1_SCB__INTR_I2C_EC_MASKED EQU CYREG_SCB1_INTR_I2C_EC_MASKED
UART_1_SCB__INTR_M EQU CYREG_SCB1_INTR_M
UART_1_SCB__INTR_M_MASK EQU CYREG_SCB1_INTR_M_MASK
UART_1_SCB__INTR_M_MASKED EQU CYREG_SCB1_INTR_M_MASKED
UART_1_SCB__INTR_M_SET EQU CYREG_SCB1_INTR_M_SET
UART_1_SCB__INTR_RX EQU CYREG_SCB1_INTR_RX
UART_1_SCB__INTR_RX_MASK EQU CYREG_SCB1_INTR_RX_MASK
UART_1_SCB__INTR_RX_MASKED EQU CYREG_SCB1_INTR_RX_MASKED
UART_1_SCB__INTR_RX_SET EQU CYREG_SCB1_INTR_RX_SET
UART_1_SCB__INTR_S EQU CYREG_SCB1_INTR_S
UART_1_SCB__INTR_S_MASK EQU CYREG_SCB1_INTR_S_MASK
UART_1_SCB__INTR_S_MASKED EQU CYREG_SCB1_INTR_S_MASKED
UART_1_SCB__INTR_S_SET EQU CYREG_SCB1_INTR_S_SET
UART_1_SCB__INTR_SPI_EC EQU CYREG_SCB1_INTR_SPI_EC
UART_1_SCB__INTR_SPI_EC_MASK EQU CYREG_SCB1_INTR_SPI_EC_MASK
UART_1_SCB__INTR_SPI_EC_MASKED EQU CYREG_SCB1_INTR_SPI_EC_MASKED
UART_1_SCB__INTR_TX EQU CYREG_SCB1_INTR_TX
UART_1_SCB__INTR_TX_MASK EQU CYREG_SCB1_INTR_TX_MASK
UART_1_SCB__INTR_TX_MASKED EQU CYREG_SCB1_INTR_TX_MASKED
UART_1_SCB__INTR_TX_SET EQU CYREG_SCB1_INTR_TX_SET
UART_1_SCB__RX_CTRL EQU CYREG_SCB1_RX_CTRL
UART_1_SCB__RX_FIFO_CTRL EQU CYREG_SCB1_RX_FIFO_CTRL
UART_1_SCB__RX_FIFO_RD EQU CYREG_SCB1_RX_FIFO_RD
UART_1_SCB__RX_FIFO_RD_SILENT EQU CYREG_SCB1_RX_FIFO_RD_SILENT
UART_1_SCB__RX_FIFO_STATUS EQU CYREG_SCB1_RX_FIFO_STATUS
UART_1_SCB__RX_MATCH EQU CYREG_SCB1_RX_MATCH
UART_1_SCB__SPI_CTRL EQU CYREG_SCB1_SPI_CTRL
UART_1_SCB__SPI_STATUS EQU CYREG_SCB1_SPI_STATUS
UART_1_SCB__STATUS EQU CYREG_SCB1_STATUS
UART_1_SCB__TX_CTRL EQU CYREG_SCB1_TX_CTRL
UART_1_SCB__TX_FIFO_CTRL EQU CYREG_SCB1_TX_FIFO_CTRL
UART_1_SCB__TX_FIFO_STATUS EQU CYREG_SCB1_TX_FIFO_STATUS
UART_1_SCB__TX_FIFO_WR EQU CYREG_SCB1_TX_FIFO_WR
UART_1_SCB__UART_CTRL EQU CYREG_SCB1_UART_CTRL
UART_1_SCB__UART_RX_CTRL EQU CYREG_SCB1_UART_RX_CTRL
UART_1_SCB__UART_RX_STATUS EQU CYREG_SCB1_UART_RX_STATUS
UART_1_SCB__UART_TX_CTRL EQU CYREG_SCB1_UART_TX_CTRL

/* UART_1_SCBCLK */
UART_1_SCBCLK__DIVIDER_MASK EQU 0x0000FFFF
UART_1_SCBCLK__ENABLE EQU CYREG_CLK_DIVIDER_C00
UART_1_SCBCLK__ENABLE_MASK EQU 0x80000000
UART_1_SCBCLK__MASK EQU 0x80000000
UART_1_SCBCLK__REGISTER EQU CYREG_CLK_DIVIDER_C00

/* UART_1_tx */
UART_1_tx__0__DM__MASK EQU 0x38
UART_1_tx__0__DM__SHIFT EQU 3
UART_1_tx__0__DR EQU CYREG_PRT3_DR
UART_1_tx__0__HSIOM EQU CYREG_HSIOM_PORT_SEL3
UART_1_tx__0__HSIOM_MASK EQU 0x000000F0
UART_1_tx__0__HSIOM_SHIFT EQU 4
UART_1_tx__0__INTCFG EQU CYREG_PRT3_INTCFG
UART_1_tx__0__INTSTAT EQU CYREG_PRT3_INTSTAT
UART_1_tx__0__MASK EQU 0x02
UART_1_tx__0__OUT_SEL EQU CYREG_UDB_PA3_CFG10
UART_1_tx__0__OUT_SEL_SHIFT EQU 2
UART_1_tx__0__OUT_SEL_VAL EQU -1
UART_1_tx__0__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
UART_1_tx__0__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
UART_1_tx__0__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
UART_1_tx__0__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
UART_1_tx__0__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
UART_1_tx__0__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
UART_1_tx__0__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
UART_1_tx__0__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
UART_1_tx__0__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
UART_1_tx__0__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
UART_1_tx__0__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
UART_1_tx__0__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
UART_1_tx__0__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
UART_1_tx__0__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
UART_1_tx__0__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
UART_1_tx__0__PC EQU CYREG_PRT3_PC
UART_1_tx__0__PC2 EQU CYREG_PRT3_PC2
UART_1_tx__0__PORT EQU 3
UART_1_tx__0__PS EQU CYREG_PRT3_PS
UART_1_tx__0__SHIFT EQU 1
UART_1_tx__DR EQU CYREG_PRT3_DR
UART_1_tx__INTCFG EQU CYREG_PRT3_INTCFG
UART_1_tx__INTSTAT EQU CYREG_PRT3_INTSTAT
UART_1_tx__MASK EQU 0x02
UART_1_tx__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
UART_1_tx__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
UART_1_tx__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
UART_1_tx__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
UART_1_tx__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
UART_1_tx__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
UART_1_tx__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
UART_1_tx__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
UART_1_tx__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
UART_1_tx__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
UART_1_tx__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
UART_1_tx__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
UART_1_tx__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
UART_1_tx__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
UART_1_tx__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
UART_1_tx__PC EQU CYREG_PRT3_PC
UART_1_tx__PC2 EQU CYREG_PRT3_PC2
UART_1_tx__PORT EQU 3
UART_1_tx__PS EQU CYREG_PRT3_PS
UART_1_tx__SHIFT EQU 1

/* UART_2_rx */
UART_2_rx__0__DM__MASK EQU 0x07
UART_2_rx__0__DM__SHIFT EQU 0
UART_2_rx__0__DR EQU CYREG_PRT4_DR
UART_2_rx__0__HSIOM EQU CYREG_HSIOM_PORT_SEL4
UART_2_rx__0__HSIOM_MASK EQU 0x0000000F
UART_2_rx__0__HSIOM_SHIFT EQU 0
UART_2_rx__0__INTCFG EQU CYREG_PRT4_INTCFG
UART_2_rx__0__INTSTAT EQU CYREG_PRT4_INTSTAT
UART_2_rx__0__MASK EQU 0x01
UART_2_rx__0__PC EQU CYREG_PRT4_PC
UART_2_rx__0__PC2 EQU CYREG_PRT4_PC2
UART_2_rx__0__PORT EQU 4
UART_2_rx__0__PS EQU CYREG_PRT4_PS
UART_2_rx__0__SHIFT EQU 0
UART_2_rx__DR EQU CYREG_PRT4_DR
UART_2_rx__INTCFG EQU CYREG_PRT4_INTCFG
UART_2_rx__INTSTAT EQU CYREG_PRT4_INTSTAT
UART_2_rx__MASK EQU 0x01
UART_2_rx__PC EQU CYREG_PRT4_PC
UART_2_rx__PC2 EQU CYREG_PRT4_PC2
UART_2_rx__PORT EQU 4
UART_2_rx__PS EQU CYREG_PRT4_PS
UART_2_rx__SHIFT EQU 0

/* UART_2_SCB */
UART_2_SCB__BIST_CONTROL EQU CYREG_SCB0_BIST_CONTROL
UART_2_SCB__BIST_DATA EQU CYREG_SCB0_BIST_DATA
UART_2_SCB__CTRL EQU CYREG_SCB0_CTRL
UART_2_SCB__EZ_DATA00 EQU CYREG_SCB0_EZ_DATA00
UART_2_SCB__EZ_DATA01 EQU CYREG_SCB0_EZ_DATA01
UART_2_SCB__EZ_DATA02 EQU CYREG_SCB0_EZ_DATA02
UART_2_SCB__EZ_DATA03 EQU CYREG_SCB0_EZ_DATA03
UART_2_SCB__EZ_DATA04 EQU CYREG_SCB0_EZ_DATA04
UART_2_SCB__EZ_DATA05 EQU CYREG_SCB0_EZ_DATA05
UART_2_SCB__EZ_DATA06 EQU CYREG_SCB0_EZ_DATA06
UART_2_SCB__EZ_DATA07 EQU CYREG_SCB0_EZ_DATA07
UART_2_SCB__EZ_DATA08 EQU CYREG_SCB0_EZ_DATA08
UART_2_SCB__EZ_DATA09 EQU CYREG_SCB0_EZ_DATA09
UART_2_SCB__EZ_DATA10 EQU CYREG_SCB0_EZ_DATA10
UART_2_SCB__EZ_DATA11 EQU CYREG_SCB0_EZ_DATA11
UART_2_SCB__EZ_DATA12 EQU CYREG_SCB0_EZ_DATA12
UART_2_SCB__EZ_DATA13 EQU CYREG_SCB0_EZ_DATA13
UART_2_SCB__EZ_DATA14 EQU CYREG_SCB0_EZ_DATA14
UART_2_SCB__EZ_DATA15 EQU CYREG_SCB0_EZ_DATA15
UART_2_SCB__EZ_DATA16 EQU CYREG_SCB0_EZ_DATA16
UART_2_SCB__EZ_DATA17 EQU CYREG_SCB0_EZ_DATA17
UART_2_SCB__EZ_DATA18 EQU CYREG_SCB0_EZ_DATA18
UART_2_SCB__EZ_DATA19 EQU CYREG_SCB0_EZ_DATA19
UART_2_SCB__EZ_DATA20 EQU CYREG_SCB0_EZ_DATA20
UART_2_SCB__EZ_DATA21 EQU CYREG_SCB0_EZ_DATA21
UART_2_SCB__EZ_DATA22 EQU CYREG_SCB0_EZ_DATA22
UART_2_SCB__EZ_DATA23 EQU CYREG_SCB0_EZ_DATA23
UART_2_SCB__EZ_DATA24 EQU CYREG_SCB0_EZ_DATA24
UART_2_SCB__EZ_DATA25 EQU CYREG_SCB0_EZ_DATA25
UART_2_SCB__EZ_DATA26 EQU CYREG_SCB0_EZ_DATA26
UART_2_SCB__EZ_DATA27 EQU CYREG_SCB0_EZ_DATA27
UART_2_SCB__EZ_DATA28 EQU CYREG_SCB0_EZ_DATA28
UART_2_SCB__EZ_DATA29 EQU CYREG_SCB0_EZ_DATA29
UART_2_SCB__EZ_DATA30 EQU CYREG_SCB0_EZ_DATA30
UART_2_SCB__EZ_DATA31 EQU CYREG_SCB0_EZ_DATA31
UART_2_SCB__I2C_CFG EQU CYREG_SCB0_I2C_CFG
UART_2_SCB__I2C_CTRL EQU CYREG_SCB0_I2C_CTRL
UART_2_SCB__I2C_M_CMD EQU CYREG_SCB0_I2C_M_CMD
UART_2_SCB__I2C_S_CMD EQU CYREG_SCB0_I2C_S_CMD
UART_2_SCB__I2C_STATUS EQU CYREG_SCB0_I2C_STATUS
UART_2_SCB__INTR_CAUSE EQU CYREG_SCB0_INTR_CAUSE
UART_2_SCB__INTR_I2C_EC EQU CYREG_SCB0_INTR_I2C_EC
UART_2_SCB__INTR_I2C_EC_MASK EQU CYREG_SCB0_INTR_I2C_EC_MASK
UART_2_SCB__INTR_I2C_EC_MASKED EQU CYREG_SCB0_INTR_I2C_EC_MASKED
UART_2_SCB__INTR_M EQU CYREG_SCB0_INTR_M
UART_2_SCB__INTR_M_MASK EQU CYREG_SCB0_INTR_M_MASK
UART_2_SCB__INTR_M_MASKED EQU CYREG_SCB0_INTR_M_MASKED
UART_2_SCB__INTR_M_SET EQU CYREG_SCB0_INTR_M_SET
UART_2_SCB__INTR_RX EQU CYREG_SCB0_INTR_RX
UART_2_SCB__INTR_RX_MASK EQU CYREG_SCB0_INTR_RX_MASK
UART_2_SCB__INTR_RX_MASKED EQU CYREG_SCB0_INTR_RX_MASKED
UART_2_SCB__INTR_RX_SET EQU CYREG_SCB0_INTR_RX_SET
UART_2_SCB__INTR_S EQU CYREG_SCB0_INTR_S
UART_2_SCB__INTR_S_MASK EQU CYREG_SCB0_INTR_S_MASK
UART_2_SCB__INTR_S_MASKED EQU CYREG_SCB0_INTR_S_MASKED
UART_2_SCB__INTR_S_SET EQU CYREG_SCB0_INTR_S_SET
UART_2_SCB__INTR_SPI_EC EQU CYREG_SCB0_INTR_SPI_EC
UART_2_SCB__INTR_SPI_EC_MASK EQU CYREG_SCB0_INTR_SPI_EC_MASK
UART_2_SCB__INTR_SPI_EC_MASKED EQU CYREG_SCB0_INTR_SPI_EC_MASKED
UART_2_SCB__INTR_TX EQU CYREG_SCB0_INTR_TX
UART_2_SCB__INTR_TX_MASK EQU CYREG_SCB0_INTR_TX_MASK
UART_2_SCB__INTR_TX_MASKED EQU CYREG_SCB0_INTR_TX_MASKED
UART_2_SCB__INTR_TX_SET EQU CYREG_SCB0_INTR_TX_SET
UART_2_SCB__RX_CTRL EQU CYREG_SCB0_RX_CTRL
UART_2_SCB__RX_FIFO_CTRL EQU CYREG_SCB0_RX_FIFO_CTRL
UART_2_SCB__RX_FIFO_RD EQU CYREG_SCB0_RX_FIFO_RD
UART_2_SCB__RX_FIFO_RD_SILENT EQU CYREG_SCB0_RX_FIFO_RD_SILENT
UART_2_SCB__RX_FIFO_STATUS EQU CYREG_SCB0_RX_FIFO_STATUS
UART_2_SCB__RX_MATCH EQU CYREG_SCB0_RX_MATCH
UART_2_SCB__SPI_CTRL EQU CYREG_SCB0_SPI_CTRL
UART_2_SCB__SPI_STATUS EQU CYREG_SCB0_SPI_STATUS
UART_2_SCB__STATUS EQU CYREG_SCB0_STATUS
UART_2_SCB__TX_CTRL EQU CYREG_SCB0_TX_CTRL
UART_2_SCB__TX_FIFO_CTRL EQU CYREG_SCB0_TX_FIFO_CTRL
UART_2_SCB__TX_FIFO_STATUS EQU CYREG_SCB0_TX_FIFO_STATUS
UART_2_SCB__TX_FIFO_WR EQU CYREG_SCB0_TX_FIFO_WR
UART_2_SCB__UART_CTRL EQU CYREG_SCB0_UART_CTRL
UART_2_SCB__UART_RX_CTRL EQU CYREG_SCB0_UART_RX_CTRL
UART_2_SCB__UART_RX_STATUS EQU CYREG_SCB0_UART_RX_STATUS
UART_2_SCB__UART_TX_CTRL EQU CYREG_SCB0_UART_TX_CTRL

/* UART_2_SCBCLK */
UART_2_SCBCLK__DIVIDER_MASK EQU 0x0000FFFF
UART_2_SCBCLK__ENABLE EQU CYREG_CLK_DIVIDER_A00
UART_2_SCBCLK__ENABLE_MASK EQU 0x80000000
UART_2_SCBCLK__MASK EQU 0x80000000
UART_2_SCBCLK__REGISTER EQU CYREG_CLK_DIVIDER_A00

/* UART_2_tx */
UART_2_tx__0__DM__MASK EQU 0x38
UART_2_tx__0__DM__SHIFT EQU 3
UART_2_tx__0__DR EQU CYREG_PRT4_DR
UART_2_tx__0__HSIOM EQU CYREG_HSIOM_PORT_SEL4
UART_2_tx__0__HSIOM_MASK EQU 0x000000F0
UART_2_tx__0__HSIOM_SHIFT EQU 4
UART_2_tx__0__INTCFG EQU CYREG_PRT4_INTCFG
UART_2_tx__0__INTSTAT EQU CYREG_PRT4_INTSTAT
UART_2_tx__0__MASK EQU 0x02
UART_2_tx__0__PC EQU CYREG_PRT4_PC
UART_2_tx__0__PC2 EQU CYREG_PRT4_PC2
UART_2_tx__0__PORT EQU 4
UART_2_tx__0__PS EQU CYREG_PRT4_PS
UART_2_tx__0__SHIFT EQU 1
UART_2_tx__DR EQU CYREG_PRT4_DR
UART_2_tx__INTCFG EQU CYREG_PRT4_INTCFG
UART_2_tx__INTSTAT EQU CYREG_PRT4_INTSTAT
UART_2_tx__MASK EQU 0x02
UART_2_tx__PC EQU CYREG_PRT4_PC
UART_2_tx__PC2 EQU CYREG_PRT4_PC2
UART_2_tx__PORT EQU 4
UART_2_tx__PS EQU CYREG_PRT4_PS
UART_2_tx__SHIFT EQU 1

/* Clock_1 */
Clock_1__DIVIDER_MASK EQU 0x0000FFFF
Clock_1__ENABLE EQU CYREG_CLK_DIVIDER_B00
Clock_1__ENABLE_MASK EQU 0x80000000
Clock_1__MASK EQU 0x80000000
Clock_1__REGISTER EQU CYREG_CLK_DIVIDER_B00

/* isr_pwm */
isr_pwm__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
isr_pwm__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
isr_pwm__INTC_MASK EQU 0x10000
isr_pwm__INTC_NUMBER EQU 16
isr_pwm__INTC_PRIOR_MASK EQU 0xC0
isr_pwm__INTC_PRIOR_NUM EQU 3
isr_pwm__INTC_PRIOR_REG EQU CYREG_CM0_IPR4
isr_pwm__INTC_SET_EN_REG EQU CYREG_CM0_ISER
isr_pwm__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

/* NavLight */
NavLight__0__DM__MASK EQU 0x38
NavLight__0__DM__SHIFT EQU 3
NavLight__0__DR EQU CYREG_PRT1_DR
NavLight__0__HSIOM EQU CYREG_HSIOM_PORT_SEL1
NavLight__0__HSIOM_MASK EQU 0x000000F0
NavLight__0__HSIOM_SHIFT EQU 4
NavLight__0__INTCFG EQU CYREG_PRT1_INTCFG
NavLight__0__INTSTAT EQU CYREG_PRT1_INTSTAT
NavLight__0__MASK EQU 0x02
NavLight__0__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
NavLight__0__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
NavLight__0__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
NavLight__0__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
NavLight__0__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
NavLight__0__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
NavLight__0__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
NavLight__0__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
NavLight__0__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
NavLight__0__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
NavLight__0__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
NavLight__0__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
NavLight__0__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
NavLight__0__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
NavLight__0__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
NavLight__0__PC EQU CYREG_PRT1_PC
NavLight__0__PC2 EQU CYREG_PRT1_PC2
NavLight__0__PORT EQU 1
NavLight__0__PS EQU CYREG_PRT1_PS
NavLight__0__SHIFT EQU 1
NavLight__DR EQU CYREG_PRT1_DR
NavLight__INTCFG EQU CYREG_PRT1_INTCFG
NavLight__INTSTAT EQU CYREG_PRT1_INTSTAT
NavLight__MASK EQU 0x02
NavLight__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
NavLight__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
NavLight__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
NavLight__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
NavLight__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
NavLight__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
NavLight__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
NavLight__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
NavLight__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
NavLight__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
NavLight__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
NavLight__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
NavLight__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
NavLight__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
NavLight__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
NavLight__PC EQU CYREG_PRT1_PC
NavLight__PC2 EQU CYREG_PRT1_PC2
NavLight__PORT EQU 1
NavLight__PS EQU CYREG_PRT1_PS
NavLight__SHIFT EQU 1

/* RC_Timer_cy_m0s8_tcpwm_1 */
RC_Timer_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT2_CC
RC_Timer_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT2_CC_BUFF
RC_Timer_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT2_COUNTER
RC_Timer_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT2_CTRL
RC_Timer_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT2_INTR
RC_Timer_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT2_INTR_MASK
RC_Timer_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT2_INTR_MASKED
RC_Timer_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT2_INTR_SET
RC_Timer_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT2_PERIOD
RC_Timer_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT2_PERIOD_BUFF
RC_Timer_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT2_STATUS
RC_Timer_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
RC_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x04
RC_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 2
RC_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x400
RC_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 10
RC_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x4000000
RC_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 26
RC_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x40000
RC_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 18
RC_Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
RC_Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x04
RC_Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 2
RC_Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
RC_Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x04
RC_Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 2
RC_Timer_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 2
RC_Timer_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT2_TR_CTRL0
RC_Timer_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT2_TR_CTRL1
RC_Timer_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT2_TR_CTRL2

/* isr_uart */
isr_uart__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
isr_uart__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
isr_uart__INTC_MASK EQU 0x800
isr_uart__INTC_NUMBER EQU 11
isr_uart__INTC_PRIOR_MASK EQU 0xC0000000
isr_uart__INTC_PRIOR_NUM EQU 3
isr_uart__INTC_PRIOR_REG EQU CYREG_CM0_IPR2
isr_uart__INTC_SET_EN_REG EQU CYREG_CM0_ISER
isr_uart__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

/* PWM_Timer_cy_m0s8_tcpwm_1 */
PWM_Timer_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT0_CC
PWM_Timer_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT0_CC_BUFF
PWM_Timer_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT0_COUNTER
PWM_Timer_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT0_CTRL
PWM_Timer_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT0_INTR
PWM_Timer_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT0_INTR_MASK
PWM_Timer_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT0_INTR_MASKED
PWM_Timer_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT0_INTR_SET
PWM_Timer_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT0_PERIOD
PWM_Timer_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT0_PERIOD_BUFF
PWM_Timer_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT0_STATUS
PWM_Timer_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
PWM_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x01
PWM_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 0
PWM_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x100
PWM_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 8
PWM_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x1000000
PWM_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 24
PWM_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x10000
PWM_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 16
PWM_Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
PWM_Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x01
PWM_Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 0
PWM_Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
PWM_Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x01
PWM_Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 0
PWM_Timer_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 0
PWM_Timer_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT0_TR_CTRL0
PWM_Timer_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT0_TR_CTRL1
PWM_Timer_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT0_TR_CTRL2

/* isr_blink */
isr_blink__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
isr_blink__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
isr_blink__INTC_MASK EQU 0x20000
isr_blink__INTC_NUMBER EQU 17
isr_blink__INTC_PRIOR_MASK EQU 0xC000
isr_blink__INTC_PRIOR_NUM EQU 3
isr_blink__INTC_PRIOR_REG EQU CYREG_CM0_IPR4
isr_blink__INTC_SET_EN_REG EQU CYREG_CM0_ISER
isr_blink__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

/* isr_timer */
isr_timer__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
isr_timer__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
isr_timer__INTC_MASK EQU 0x40000
isr_timer__INTC_NUMBER EQU 18
isr_timer__INTC_PRIOR_MASK EQU 0xC00000
isr_timer__INTC_PRIOR_NUM EQU 3
isr_timer__INTC_PRIOR_REG EQU CYREG_CM0_IPR4
isr_timer__INTC_SET_EN_REG EQU CYREG_CM0_ISER
isr_timer__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

/* Blink_Timer_cy_m0s8_tcpwm_1 */
Blink_Timer_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT1_CC
Blink_Timer_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT1_CC_BUFF
Blink_Timer_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT1_COUNTER
Blink_Timer_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT1_CTRL
Blink_Timer_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT1_INTR
Blink_Timer_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT1_INTR_MASK
Blink_Timer_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT1_INTR_MASKED
Blink_Timer_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT1_INTR_SET
Blink_Timer_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT1_PERIOD
Blink_Timer_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT1_PERIOD_BUFF
Blink_Timer_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT1_STATUS
Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x02
Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 1
Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x200
Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 9
Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x2000000
Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 25
Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x20000
Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 17
Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x02
Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 1
Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x02
Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 1
Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 1
Blink_Timer_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT1_TR_CTRL0
Blink_Timer_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT1_TR_CTRL1
Blink_Timer_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT1_TR_CTRL2

/* StrobeLight */
StrobeLight__0__DM__MASK EQU 0x1C0000
StrobeLight__0__DM__SHIFT EQU 18
StrobeLight__0__DR EQU CYREG_PRT1_DR
StrobeLight__0__HSIOM EQU CYREG_HSIOM_PORT_SEL1
StrobeLight__0__HSIOM_MASK EQU 0x0F000000
StrobeLight__0__HSIOM_SHIFT EQU 24
StrobeLight__0__INTCFG EQU CYREG_PRT1_INTCFG
StrobeLight__0__INTSTAT EQU CYREG_PRT1_INTSTAT
StrobeLight__0__MASK EQU 0x40
StrobeLight__0__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
StrobeLight__0__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
StrobeLight__0__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
StrobeLight__0__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
StrobeLight__0__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
StrobeLight__0__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
StrobeLight__0__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
StrobeLight__0__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
StrobeLight__0__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
StrobeLight__0__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
StrobeLight__0__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
StrobeLight__0__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
StrobeLight__0__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
StrobeLight__0__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
StrobeLight__0__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
StrobeLight__0__PC EQU CYREG_PRT1_PC
StrobeLight__0__PC2 EQU CYREG_PRT1_PC2
StrobeLight__0__PORT EQU 1
StrobeLight__0__PS EQU CYREG_PRT1_PS
StrobeLight__0__SHIFT EQU 6
StrobeLight__DR EQU CYREG_PRT1_DR
StrobeLight__INTCFG EQU CYREG_PRT1_INTCFG
StrobeLight__INTSTAT EQU CYREG_PRT1_INTSTAT
StrobeLight__MASK EQU 0x40
StrobeLight__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
StrobeLight__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
StrobeLight__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
StrobeLight__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
StrobeLight__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
StrobeLight__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
StrobeLight__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
StrobeLight__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
StrobeLight__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
StrobeLight__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
StrobeLight__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
StrobeLight__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
StrobeLight__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
StrobeLight__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
StrobeLight__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
StrobeLight__PC EQU CYREG_PRT1_PC
StrobeLight__PC2 EQU CYREG_PRT1_PC2
StrobeLight__PORT EQU 1
StrobeLight__PS EQU CYREG_PRT1_PS
StrobeLight__SHIFT EQU 6

/* LandingLight */
LandingLight__0__DM__MASK EQU 0x07
LandingLight__0__DM__SHIFT EQU 0
LandingLight__0__DR EQU CYREG_PRT1_DR
LandingLight__0__HSIOM EQU CYREG_HSIOM_PORT_SEL1
LandingLight__0__HSIOM_MASK EQU 0x0000000F
LandingLight__0__HSIOM_SHIFT EQU 0
LandingLight__0__INTCFG EQU CYREG_PRT1_INTCFG
LandingLight__0__INTSTAT EQU CYREG_PRT1_INTSTAT
LandingLight__0__MASK EQU 0x01
LandingLight__0__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
LandingLight__0__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
LandingLight__0__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
LandingLight__0__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
LandingLight__0__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
LandingLight__0__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
LandingLight__0__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
LandingLight__0__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
LandingLight__0__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
LandingLight__0__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
LandingLight__0__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
LandingLight__0__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
LandingLight__0__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
LandingLight__0__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
LandingLight__0__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
LandingLight__0__PC EQU CYREG_PRT1_PC
LandingLight__0__PC2 EQU CYREG_PRT1_PC2
LandingLight__0__PORT EQU 1
LandingLight__0__PS EQU CYREG_PRT1_PS
LandingLight__0__SHIFT EQU 0
LandingLight__DR EQU CYREG_PRT1_DR
LandingLight__INTCFG EQU CYREG_PRT1_INTCFG
LandingLight__INTSTAT EQU CYREG_PRT1_INTSTAT
LandingLight__MASK EQU 0x01
LandingLight__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
LandingLight__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
LandingLight__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
LandingLight__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
LandingLight__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
LandingLight__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
LandingLight__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
LandingLight__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
LandingLight__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
LandingLight__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
LandingLight__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
LandingLight__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
LandingLight__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
LandingLight__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
LandingLight__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
LandingLight__PC EQU CYREG_PRT1_PC
LandingLight__PC2 EQU CYREG_PRT1_PC2
LandingLight__PORT EQU 1
LandingLight__PS EQU CYREG_PRT1_PS
LandingLight__SHIFT EQU 0

/* CollisionLight */
CollisionLight__0__DM__MASK EQU 0xE00
CollisionLight__0__DM__SHIFT EQU 9
CollisionLight__0__DR EQU CYREG_PRT1_DR
CollisionLight__0__HSIOM EQU CYREG_HSIOM_PORT_SEL1
CollisionLight__0__HSIOM_MASK EQU 0x0000F000
CollisionLight__0__HSIOM_SHIFT EQU 12
CollisionLight__0__INTCFG EQU CYREG_PRT1_INTCFG
CollisionLight__0__INTSTAT EQU CYREG_PRT1_INTSTAT
CollisionLight__0__MASK EQU 0x08
CollisionLight__0__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
CollisionLight__0__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
CollisionLight__0__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
CollisionLight__0__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
CollisionLight__0__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
CollisionLight__0__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
CollisionLight__0__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
CollisionLight__0__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
CollisionLight__0__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
CollisionLight__0__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
CollisionLight__0__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
CollisionLight__0__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
CollisionLight__0__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
CollisionLight__0__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
CollisionLight__0__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
CollisionLight__0__PC EQU CYREG_PRT1_PC
CollisionLight__0__PC2 EQU CYREG_PRT1_PC2
CollisionLight__0__PORT EQU 1
CollisionLight__0__PS EQU CYREG_PRT1_PS
CollisionLight__0__SHIFT EQU 3
CollisionLight__DR EQU CYREG_PRT1_DR
CollisionLight__INTCFG EQU CYREG_PRT1_INTCFG
CollisionLight__INTSTAT EQU CYREG_PRT1_INTSTAT
CollisionLight__MASK EQU 0x08
CollisionLight__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
CollisionLight__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
CollisionLight__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
CollisionLight__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
CollisionLight__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
CollisionLight__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
CollisionLight__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
CollisionLight__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
CollisionLight__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
CollisionLight__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
CollisionLight__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
CollisionLight__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
CollisionLight__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
CollisionLight__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
CollisionLight__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
CollisionLight__PC EQU CYREG_PRT1_PC
CollisionLight__PC2 EQU CYREG_PRT1_PC2
CollisionLight__PORT EQU 1
CollisionLight__PS EQU CYREG_PRT1_PS
CollisionLight__SHIFT EQU 3

/* Miscellaneous */
CYDEV_BCLK__HFCLK__HZ EQU 24000000
CYDEV_BCLK__HFCLK__KHZ EQU 24000
CYDEV_BCLK__HFCLK__MHZ EQU 24
CYDEV_BCLK__SYSCLK__HZ EQU 24000000
CYDEV_BCLK__SYSCLK__KHZ EQU 24000
CYDEV_BCLK__SYSCLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PANTHER EQU 4
CYDEV_CHIP_DIE_PSOC4A EQU 2
CYDEV_CHIP_DIE_PSOC5LP EQU 5
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC4
CYDEV_CHIP_JTAG_ID EQU 0x04161193
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 2
CYDEV_CHIP_MEMBER_4D EQU 3
CYDEV_CHIP_MEMBER_5A EQU 4
CYDEV_CHIP_MEMBER_5B EQU 5
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_4A
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PANTHER_ES0 EQU 0
CYDEV_CHIP_REV_PANTHER_ES1 EQU 1
CYDEV_CHIP_REV_PANTHER_PRODUCTION EQU 1
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4D_ES0 EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_4A_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_READ_ACCELERATOR EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_PROTECT_KILL EQU 4
CYDEV_DEBUG_PROTECT_OPEN EQU 1
CYDEV_DEBUG_PROTECT EQU CYDEV_DEBUG_PROTECT_OPEN
CYDEV_DEBUG_PROTECT_PROTECTED EQU 2
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_HEAP_SIZE EQU 0x0100
CYDEV_PROJ_TYPE EQU 2
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_STACK_SIZE EQU 0x0400
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 1
CYDEV_VDDA_MV EQU 3300
CYDEV_VDDD_MV EQU 3300
CYIPBLOCK_M0S8_CTBM_VERSION EQU 0
CYIPBLOCK_m0s8cpuss_VERSION EQU 0
CYIPBLOCK_m0s8csd_VERSION EQU 0
CYIPBLOCK_m0s8gpio2_VERSION EQU 0
CYIPBLOCK_m0s8hsiom4a_VERSION EQU 0
CYIPBLOCK_m0s8lcd_VERSION EQU 0
CYIPBLOCK_m0s8lpcomp_VERSION EQU 0
CYIPBLOCK_m0s8pclk_VERSION EQU 0
CYIPBLOCK_m0s8sar_VERSION EQU 0
CYIPBLOCK_m0s8scb_VERSION EQU 0
CYIPBLOCK_m0s8srssv2_VERSION EQU 1
CYIPBLOCK_m0s8tcpwm_VERSION EQU 0
CYIPBLOCK_m0s8udbif_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 2
CYDEV_BOOTLOADER_ENABLE EQU 0

#endif /* INCLUDED_CYFITTERIAR_INC */