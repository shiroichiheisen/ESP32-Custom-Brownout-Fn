#include "ESP32_Custom_Brown_Fn.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "nvs.h"
#include "soc/soc.h"
#include "soc/cpu.h"
#include "soc/rtc_cntl_reg.h"
#include "driver/rtc_cntl.h"

ESP32_Custom_Brown_Fn::ESP32_Custom_Brown_Fn(intr_handler_t handler)
{
    REG_WRITE(RTC_CNTL_BROWN_OUT_REG,
              RTC_CNTL_BROWN_OUT_ENA             /* Enable BOD */
                  | RTC_CNTL_BROWN_OUT_PD_RF_ENA /* Automatically power down RF */
                  /* Reset timeout must be set to >1 even if BOR feature is not used */
                  | (2 << RTC_CNTL_BROWN_OUT_RST_WAIT_S));

    ESP_ERROR_CHECK(rtc_isr_register(handler, NULL, RTC_CNTL_BROWN_OUT_INT_ENA_M));

    REG_SET_BIT(RTC_CNTL_INT_ENA_REG, RTC_CNTL_BROWN_OUT_INT_ENA_M);
}