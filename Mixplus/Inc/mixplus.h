
#ifndef __H_MIXPLUS
#define __H_MIXPLUS


#include "main.h"
#include "bsp_ili9341_lcd.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define RGB(R,G,B)	(((R >> 3) << 11) | ((G >> 2) << 5) | (B >> 3))	/* 将8位R,G,B转化为 16位RGB565格式 */
#define RGB565_R(x)  ((x >> 8) & 0xF8)
#define RGB565_G(x)  ((x >> 3) & 0xFC)
#define RGB565_B(x)  ((x << 3) & 0xF8)

	void setup();
	void loop();
    void setColor(uint16_t color);
    void drawText(int x,int y,const char * str);
    void setPoint(int x, int y,uint16_t c);
    void setImage(PFNUpdate UpdateProc);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif