
int main ()

{

	Uint8 CH[] = "SERIAL PREPHIRAL"	;

	SPI_Master_INIT();

	_delay_ms(2000);

	SPI_START_SLAVE();
	while(1)

	{

		while(CH[i] != '\0')
		{
			SPI_MasterTransmit(CH[i]);

			i++;

			}
	}

}






int main ()
{
LCD_init();
SPI_Slave_INIT();
Uint8 i = 0;

while(1){
Uint8 CH[16];

CH[i]= SPI_SlaveReceive();
while(CH[i] != '\0') {
CH[i]= SPI_SlaveReceive();
LCD_WriteCHAR(CH[i]);
i++;
}
LCD_Clear();
}
}
	