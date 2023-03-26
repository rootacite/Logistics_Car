

#include "mixplus.h"
#include "GPIO.hpp"
#include "Serial.hpp"
#include "Timer.hpp"
#include "fatfs.h"

#include "PWM.hpp"
#include "sdio.h"

#include <string>
#include <string.h>

using namespace std;

int count = 0;

#define BUFFER_SIZE 6400
#define LINE_COUNT (BUFFER_SIZE / 320)

FIL f;
uint16_t uu[BUFFER_SIZE];
UINT dwRead;

int b_failled=1;
int b_index=0;
char b_filepath[10];

Serial Serial1(&huart1);
Serial Serial3(&huart3);

GPIO KEY1(GPIOA,GPIO_PIN_0);
GPIO KEY2(GPIOC,GPIO_PIN_13);

uint16_t* ImgData=NULL;


int SDTest(void){

    // 挂载文件系统
    retSD = f_mount(&SDFatFS, SDPath, 1);
    if(retSD)
    {
        Serial1.write("mount error\r\n");
        return -1;
    }
    else
    {
        Serial1.write("mount sucess!!! \r\n");
    }

    HAL_SD_CardCIDTypeDef CID;
    HAL_StatusTypeDef s1 = HAL_SD_GetCardCID(&hsd, &CID);
    HAL_SD_CardCSDTypeDef CSD;
    HAL_StatusTypeDef s2 = HAL_SD_GetCardCSD(&hsd, &CSD);
    HAL_SD_CardStatusTypeDef status;
    HAL_StatusTypeDef s3 = HAL_SD_GetCardStatus(&hsd, &status);
    HAL_SD_CardInfoTypeDef cardInfo;
    HAL_StatusTypeDef s4 = HAL_SD_GetCardInfo(&hsd, &cardInfo);

    uint32_t fCardSize = 1.0*cardInfo.BlockNbr*cardInfo.BlockSize/1024/1024;

    char op[255];
    sprintf(op,"BlockNum=%d   BlockSize=%d \r\n",cardInfo.BlockNbr,cardInfo.BlockSize);
    Serial1.write(op);
    sprintf(op,"Card Size:%d M\r\n", fCardSize);
    Serial1.write(op);
    return 1;
}

uint16_t r_line[320];
uint16_t g_line[320];
uint16_t b_line[320];


void setup()
{
    for(int i=0;i<320;i++)
    {
        r_line[i]=RGB(255,0,0);
        g_line[i]=RGB(0,255,0);
        b_line[i]=RGB(0,0,255);

    }


    Serial1.begin();
    Serial3.begin();
    HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_4);

    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,200);
    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,200);
    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,200);

    setColor(RGB(255,	255,  255));
    SDTest();
}


void loop()
{
    count=0;
    b_failled=1;
    sprintf(b_filepath,"%d.bin",b_index);

    if(f_open(&f,b_filepath,FA_OPEN_EXISTING|FA_READ)==FR_OK)
        Serial1.write("opened\r\n",8);
    else
    {
        b_index=0;
        Serial1.write("open failed\r\n",13);
        return;
    }

    while(b_failled)
    {
        if(KEY1.get())
        {
            f_lseek(&f,f_tell(&f)+ 320 * 240 * 2 * 24);
        }
        if(KEY2.get())
        {
            b_index++;
            f_close(&f);
            break;
        }
        setImage([](){

           if(count%LINE_COUNT==0)
           {
               f_read(&f, (uint8_t *)uu, BUFFER_SIZE * 2, &dwRead);
               if(dwRead!=BUFFER_SIZE * 2) {
                   b_failled = 0;
                   return (uint16_t*)0;
               }

               count++;
               return uu;
           }
            else
           {
               count++;
               return (uint16_t*)((uint32_t)uu + 640 * ((count - 1)%LINE_COUNT));
           }

        });
    }
    f_close(&f);
    Serial1.write("FFMPEG21\n");
}