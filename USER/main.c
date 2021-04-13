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
	delay_init();	    	 //��ʱ������ʼ��	  
	KEY_Init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
 	LED_Init();			     //LED�˿ڳ�ʼ��
	OLED_Init();			//��ʼ��OLED      	   
	OLED_Refresh_Gram();//������ʾ��OLED 
	uart_init(115200);//���ڳ�ʼ��Ϊ115200
	RTC_Init();
      TPAD_Init(6);			//��ʼ����������
      while(1)
	{
		key=KEY_Scan(0);//��֧��������
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
