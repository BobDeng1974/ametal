/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief ZLG116 时钟用户配置文件
 * \sa am_hwconf_zlg116_clk.c
 *
 * \internal
 * \par Modification history
 * - 1.00 17-04-13  sdy, first implementation.
 * \endinternal
 */
 
#include "am_zlg115_clk.h"
#include "hw/amhw_zlg115_rcc.h"
#include "hw/amhw_zlg116_rcc.h"

/**
 * \addtogroup am_if_src_hwconf_zlg116_clk
 * \copydoc am_hwconf_zlg116_clk.c
 * @{
 */

/** \brief CLK 平台初始化 */
static void __zlg115_clk_plfm_init (void)
{

}

/**
 * \brief CLK设备信息
 */
static const am_zlg115_clk_devinfo_t __g_clk_devinfo =
{

    /**
     * \brief 时钟输入频率
     *    若SYS时钟为 HSE  此项配置值为用户外部晶振的实际频率
     *    若SYS时钟为 HSI  则此配置项作为内部晶振频率选择项，有两种频率可供选择：
     *                       AM_ZLG115_HSI_72M、 AM_ZLG115_HSI_48M
     */
     AM_ZLG115_HSI_48M,

    /** \brief
     *    SYS 时钟源选择
     *    -# AMHW_ZLG115_SYSCLK_HSI_DIV6 : HSI 振荡器  6 分频作为系统时钟
     *    -# AMHW_ZLG115_SYSCLK_HSE      : HSE 作为系统时钟
     *    -# AMHW_ZLG115_SYSCLK_HSI      : HSI 作为系统时钟
     *    -# AMHW_ZLG115_SYSCLK_LSI      : LSI 作为系统时钟
     */
    AMHW_ZLG115_SYSCLK_HSI,

    /**
     * \brief AHB分频系数，AHBCLK = PLLOUT / DIV,AHB最大频率为48Mhz
     *
     *    ahb_div |  DIV
     *   ---------------------
     *        0-7 |   1
     *        8   |   2
     *        9   |   4
     *        10  |   8
     *        11  |   16
     *        12  |   64
     *        13  |  128
     *        14  |  256
     *        15  |  512
     */
    0,

    /**
     * \brief APB1分频系数，APB1CLK = AHBCLK / (2 ^ apb1_div)
     *        APB1最大频率为24Mhz
     */
    1,

    /**
     * \brief APB2分频系数，APB2CLK = AHBCLK / (2 ^ apb2_div)
     *        APB2最大频率为48Mhz
     */
    0,

    /* 平台初始化函数，配置时钟引脚等操作 */
    __zlg115_clk_plfm_init,

    /* CLK无平台去初始化函数 */
    NULL
};

/** \brief 时钟设备实例 */
static am_zlg115_clk_dev_t __g_clk_dev;

/**
 * \brief CLK 实例初始化，初始化系统时钟
 * \retval AM_OK : 时钟成功初始化
 */
int am_zlg115_clk_inst_init (void)
{
    return am_zlg115_clk_init(&__g_clk_dev, &__g_clk_devinfo);
}

/**
 * @}
 */

/* end of file */
