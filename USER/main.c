#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "oled.h"
#include "tpad.h"
#include "usart.h" 
#include "rtc.h"
	
 int main(void)
 {	
	u8 key;
	delay_init();	    	 //延时函数初始化	  
	KEY_Init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
 	LED_Init();			     //LED端口初始化
	OLED_Init();			//初始化OLED      	   
	OLED_Refresh_Gram();//更新显示到OLED 
	uart_init(115200);//串口初始化为115200
	RTC_Init();
      TPAD_Init(6);			//初始化触摸按键
      while(1)
	{
		key=KEY_Scan(0);//不支持连续按
		if(key)
		{
			switch(key)
			{
				case KEY0_PRES:
                                OLED_ShowSurface(1);				
                                break;
				case KEY1_PRES:      //case 2
                                OLED_ShowSurface(2);
				break;
				case WKUP_PRES:
                                OLED_ShowSurface(3);
				break;
			}						
		}
            if(TPAD_Scan(0))
            {
                    OLED_Clear();
                    OLED_ShowTime();
                    delay_ms(10);     
            
            
            }     
      
      }
}
