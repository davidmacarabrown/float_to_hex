#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

unsigned long precision = 0;
char temp_char;
char ac_binary[65];

void str_cat(unsigned long long unsigned_cast, unsigned long ul_precision, char* ac_binary)
{
	for(int i = ul_precision; i > 0; i--)
	{
		ltoa( (unsigned_cast >> i) & 1), &temp_char, 10);
		strcat(ac_binary, &temp_char);
	}
	
	memset(&ac_binary[precision + 1], 0, (65 - precision));
}

int main()
{
	char fp_char[50];
	double double_to_cast;
	
	unsigned long long cast;
	unsigned long msb;
	unsigned long lsb;
	
	float float_to_cast;
	unsigned long ul_cast;
	
	memset(ac_binary, 0, (sizeof(double) + 1));
	
	while(1)
	{
	    printf("Enter Precision:\n");
		fscanf(stdin, "%s", fp_char);
		
		precision = atol(fp_char);
		
		if(precision == 64)
		{
			printf("Using 64Bit Precision\n");
			printf("Enter FP:\n");
			
			fscanf(stdin, "%s", fp_char);
			
			double_to_cast = strtod(fp_char, NULL);
			memcpy(&cast, &double_to_cast, sizeof(double));
			
			msb = (unsigned long) ((cast >> 32) & 0xFFFFFFFF);
			lsb = (unsigned long) (cast & 0xFFFFFFFF);
			
			printf("\nMSB: 0x%08X\n", msb);
			printf("\nLSB: 0x%08X\n", lsb);
			
			str_cat(cast, precision, ac_binary);
			
			printf("S|---EXP---||-------------------MANTISSA------------------------|\n");
			printf("%s\n\n", ac_binary);
		}
		else if(precision == 32)
		{
			printf("Using 32Bit Precision\n");
			printf("Enter FP:\n");
			
			fscanf(stdin, "%s", fp_char);
			
			float_to_cast = atof(fp_char);
			
			memcpy(&ul_cast, &float_to_cast, sizeof(float));
			
			printf("Hex: 0x%08X\n\n", ul_cast);
			
			str_cat(ul_cast, precision, ac_binary);
			
			printf("S|-EXP--||-------MANTISSA------|\n");
			printf("%s\n\n", ac_binary);
		}
		else
		{
			printf("Invalid Precision\n");
		}
	}
	return 0;
}