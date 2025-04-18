
#include <stdint.h>
#include <system_stm32f4xx.h>
#include "timer.h"
#include "Ucglib.h"

static ucg_t ucg;

int main(void
		)
{
    SystemCoreClockUpdate();
    TimerInit();

    // Khởi tạo LCD
    Ucglib4WireSWSPI_begin(&ucg, UCG_FONT_MODE_SOLID);
    ucg_ClearScreen(&ucg);

    ucg_SetFont(&ucg, ucg_font_7x13_tf);
    ucg_SetColor(&ucg, 0, 255, 255, 0); // Text color: white
    ucg_SetColor(&ucg, 1, 0, 0, 0);       // Background color: black
    ucg_SetRotate180(&ucg);               // Rotate display 180 degrees

    ucg_DrawString(&ucg, 0, 75, 0, "Nhom 3.ttcs");
   // ucg_DrawString(&ucg, 0, 20, 0, "thuctapcs");

    while(1)
    {
        processTimerScheduler();
    }
}
