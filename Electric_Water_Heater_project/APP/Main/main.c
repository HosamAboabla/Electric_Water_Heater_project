
#include "main.h"
uint8_t btn1_read_;
uint8_t btn0_read_;
uint8_t power_flag=0;
uint8_t first_push_flag=0;
uint8_t degree=50;

uint8_t test=0;


uint16_t current_temp;
uint16_t last_10_temp[10] = {0,0,0,0,0,0,0,0,0,0};
uint8_t temp_index = 0;
extern TIMER1_OVF;
uint32_t timer1_count = 0;

void sitting_temp(uint8_t,uint8_t);
float calcualate_avg_temp(uint16_t* arr);

int main(void)
{

	
	

	Interrupt_Initialization(INT0_Signal);
	DIO_SetPinPullUp(DIO_PORTD,DIO_PIN2);
	Timer0_WithInterrupt_Initialization(Normal_Mode,Pin_disconnected);
	Timer1_with_interrupt_initialization(TIMER1_Normal , TIMER1_PIN_Disconnected);
	Timer1_start(TIMER1_Prescaler_1024);
	Timer1_with_interrupt_setDelay(TIMER1_Normal , 100 , 255);
	BTN0_Initialization();
	BTN1_Initialization();
	LED0_Initialization();
	LED1_Initialization();
	ADC_Initialization(ADC1);

	
	/* Replace with your application code */
	while (1)
	{
		btn1_read_ = BTN1_Read();
		btn0_read_ =BTN0_Read();
		if (power_flag==0);
		else if((first_push_flag==0&&btn0_read_==PRESSED)||(first_push_flag==0&&btn1_read_==PRESSED)){
			first_push_flag=1;
			Timer0_Start(PreS_1024);
			Timer0_WithInterrupt_SetDelay(Normal_Mode,5000,255);
			btn1_read_=0;
			btn0_read_=0;
		}
		else {
			sitting_temp(btn0_read_,btn1_read_);
		}
		
	}
	return 0;
}

ISR(INT0_vect){
	power_flag^=1;
	if(power_flag==0){
		LED0_OFF();
		Timer0_Stop();
		first_push_flag=0;
		SEVSEG_Disable1();
		SEVSEG_Disable2();
		SEVSEG_Dot_Disable();
	}
	else {
		LED0_ON();
		SEVSEG_Initialization();
		test=1;
	}
}
void sitting_temp(uint8_t btn0_read_,uint8_t btn1_read_){		//if user press the button make test = 1 to restart timer
	if(btn0_read_==PRESSED&&degree<75){
		degree+=5;
		test=1;
		Timer0_Stop();
		Timer0_Start(PreS_1024);
		Timer0_WithInterrupt_SetDelay(Normal_Mode,5000,255);
	}
	else if(btn1_read_==PRESSED&&degree>35) {
		degree-=5;
		test=1;
		Timer0_Stop();
		Timer0_Start(PreS_1024);
		Timer0_WithInterrupt_SetDelay(Normal_Mode,5000,255);
	}
	else if((btn1_read_==PRESSED&&degree==35)||(btn0_read_==PRESSED&&degree==75)) {
		test=1;
		Timer0_Stop();
		Timer0_Start(PreS_1024);
		Timer0_WithInterrupt_SetDelay(Normal_Mode,5000,255);
	}

}

float calcualate_avg_temp(uint16_t* arr)
{
	uint16_t sum = 0;
	
	for(uint8_t i = 0 ; i < 10 ; i++)
	{
		sum += arr[i];
	}
	
	return (float ) sum / (float ) 10;
}

ISR(TIMER0_OVF_vect){
	
	static uint32_t cnt=0;
	if(test==1){	//restart count from 0 if user press the buttons
		cnt=0;
		test=0;
	}
	if(cnt==Number_OVF){		//if counter reach number of overflows
		Timer0_Stop();			//stop the timer
		first_push_flag=0;
		LED1_TGL();
		cnt=0;					//make  counter =0
	}
	else if(cnt%(Number_OVF/5)==0){
		SEVSEG_Display(degree);
	}

	cnt++;
}


ISR(TIMER1_OVF_vect)
{
	if(timer1_count < TIMER1_OVF)
	{
		timer1_count++;
	}
	else
	{
		// ADC read
		last_10_temp[temp_index] = (5 * ADC_Read() * 100) / 1024 ; // degree
		temp_index++;
		
		if(temp_index > 9)
		{
			temp_index = 0;
		}
		timer1_count = 0;
	}
}