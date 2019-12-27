readme
27/12/2019

things I had to do to make this work:

tmp
SMSlib.h

I had to hardcode array size
/*__at (0x8000)*/unsigned char SMS_SRAM[10];

I had to wrap SMS_SRAM and "guess" at the return type
devkit_SMS_SRAM()

unsigned char* devkit_SMS_SRAM()
{
	return SMS_SRAM;
}