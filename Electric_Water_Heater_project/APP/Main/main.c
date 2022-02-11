


#include "main.h"

uint8_t btn1_read_;
uint8_t btn0_read_;
uint8_t power_flag=0;
uint8_t first_push_flag=0;
uint8_t degree=60;
extern uint32_t Number_OVF;
extern uint32_t Number_CTC;
extern uint32_t Init_Value;
uint8_t test=0;
uint8_t heat_flag=0;
uint8_t degree_addr = 64;
uint8_t access_flag=0;
fint32_t current_temp=0;
uint16_t last_10_temp[10] = {0,0,0,0,0,0,0,0,0,0};
uint8_t temp_index = 0;
extern uint32_t Timer2_OVF;
uint8_t blink_7_segment = 0;
// extern uint32_t TIMER1_OVF;


void sitting_temp(uint8_t,uint8_t);
float calcualate_avg_temp(uint16_t* arr);
void cmpare_temp(void);

int main(void)
{

	
	

	Interrupt_Initialization(INT0_Signal);
	DIO_SetPinPullUp(DIO_PORTD,DIO_PIN2);
	Timer0_WithInterrupt_Initialization(Normal_Mode,Pin_disconnected);
	Timer2_WithInterrupt_Initialization(Normal_Mode_ , Pin_disconnected_);

	// Timer1_with_interrupt_initialization(TIMER1_Normal , TIMER1_PIN_Disconnected,TIMER1_Channel_A);
	// Timer1_start(TIMER1_Prescaler_1024);
	// Timer1_with_interrupt_setDelay(TIMER1_Normal , 100 , 255);
	ADC_Initialization(ADC1);
	BTN0_Initialization();
	BTN1_Initialization();
	LED0_Initialization();
	LED1_Initialization();
	LED2_Initialization();
	Relay_Initialization();
	
	Timer2_Start(PreS_1024_);	//start timer2 to get the ADC read every 100 ms
	Timer2_WithInterrupt_SetDelay(Normal_Mode_ , 100 , 255);

	
	/* Replace with your application code */
	while (1)
	{
		btn1_read_ = BTN1_Read();	//get button1 read
		btn0_read_ =BTN0_Read();	//get button0 read
		

		//check if the device is on or off
		if (power_flag==0);	//if off do noting
		else{	//if on start operations
			if (access_flag==1)
			{
				degree=EEPROM_Read(degree_addr);
			}
			

			if((first_push_flag==0&&btn0_read_==PRESSED)||(first_push_flag==0&&btn1_read_==PRESSED)){	//check if buttons are clicked for the first time to enter setting mode
				first_push_flag=1;	//raise the flag
				Timer0_Start(PreS_1024);	//start timer0 so that if 5 seconds spend without using buttons ,exit setting mode
				Timer0_WithInterrupt_SetDelay(Normal_Mode,5000,255);
				blink_7_segment = 1;
				//reset buttons read
				// btn1_read_=0;
				// btn0_read_=0;
			}
			else//  if( (btn0_read_==PRESSED) ||(btn1_read_==PRESSED) ) 
			{	//if this isn't the first click call the function of setting mode
				sitting_temp(btn0_read_,btn1_read_);
				
			}
			
			//compare the current temp with set_temp
			
			if(current_temp<degree-5){
				heat_flag=1;	//raise flag of heating element
				LED1_ON(); // Heating element on
				LED2_OFF(); // Cooling element off
			}
			else if (current_temp>degree+5)
			{
				heat_flag=0;	//raise flag of heating element
				LED1_OFF(); // Heating element off
				LED2_ON(); // Cooling element on
			}
			else if (current_temp <=degree - 5 && current_temp >= degree + 5)
			{
				LED1_OFF(); // Heating element off
				LED2_OFF(); // Cooling element off
				heat_flag=0;	//raise flag of heating element
				Relay_ON();
				_delay_ms(10);
				Relay_OFF();
			}
			
			
			if (first_push_flag==0)
			{
				// LCD_Clear();
				// LCD_Write_Number(current_temp);
				SEVSEG_Display(current_temp);
			}
			
			
			
		}
		
	}
	return 0;
}



//===============================================================================================

ISR(INT0_vect){
	power_flag^=1;
	if(power_flag==0){
		LED0_OFF();
		LED1_OFF();
		LED2_OFF();
		Timer0_Stop();
		Timer2_Stop();
		first_push_flag=0;
		//SEVSEG_Disable1();
		//SEVSEG_Disable2();
		//SEVSEG_Dot_Disable();
		LCD_disable();
	}
	else {
		LED0_ON();
		//SEVSEG_Initialization();
		LCD_Initialization();
		test=1;	//to reset the counter
		Timer2_Start(PreS_1024_);	//start timer2 to get the ADC read every 100 ms
		Timer2_WithInterrupt_SetDelay(Normal_Mode_ , 100 , 255);
	}
}


//===============================================================================================


void sitting_temp(uint8_t btn0_read_,uint8_t btn1_read_){		//if user press the button make test = 1 to restart timer
	if(btn0_read_==PRESSED&&degree<75){
		degree+=5;
		EEPROM_Write(degree_addr , degree); // Saving desired temperature on EEPROM
		access_flag=1;
		test=1;
		Timer0_Stop();
		Timer0_Start(PreS_1024);
		Timer0_WithInterrupt_SetDelay(Normal_Mode,5000,255);
	}
	else if(btn1_read_==PRESSED&&degree>35) {
		degree-=5;
		EEPROM_Write(degree_addr , degree); // Saving desired temperature on EEPROM
		access_flag=1;
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


//===============================================================================================


float calcualate_avg_temp(uint16_t* arr)
{
	uint16_t sum = 0;
	
	for(uint8_t i = 0 ; i < 10 ; i++)
	{
		sum += arr[i];
	}
	
	return (float ) sum / (float ) 10;
}

//===============================================================================================



ISR(TIMER0_OVF_vect){
	
	static uint32_t cnt=0;
	if(test==1){	//restart count from 0 if user press the buttons
		cnt=0;
		test=0;
	}
	if(cnt==Number_OVF){		//if counter reach number of overflows
		Timer0_Stop();			//stop the timer
		first_push_flag=0;
		cnt=0;					//make  counter =0
	}
	/*
	else if(cnt%(Number_OVF/5)==0){
		LCD_Write_Number(degree);
		//SEVSEG_Display(degree);
	}
	*/
	cnt++;
}


//===============================================================================================


ISR(TIMER2_OVF_vect)
{
	static uint32_t timer2_count = 0;
	
	if (first_push_flag == 1)
	{
		if( blink_7_segment )
		{
			SEVSEG_Display(degree);
		}
		else
		{
			SEVSEG_Disable1();
			SEVSEG_Disable2();
		}
		
	}
	/*
	else
	{
		SEVSEG_Display(current_temp);
	}
	*/
	if(timer2_count < Timer2_OVF)
	{
		timer2_count++;
	}
	else
	{
		// ADC read
		last_10_temp[temp_index] = (500.0 * ADC_Read()) / 1024.0 ; // degree
		temp_index++;

		if(temp_index > 9)
		{
			temp_index = 0;
			current_temp=calcualate_avg_temp(last_10_temp);
			
			blink_7_segment ^= 1;
		}
		timer2_count = 0;

	}
}

//===============================================================================================