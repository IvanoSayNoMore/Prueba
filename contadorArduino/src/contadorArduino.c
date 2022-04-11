/*
 ============================================================================
 Name        : contadorArduino.c
 Author      : Ivan Fabella
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// C++ code
	//

	#define VERDE 4

	int segAnt=0;
	int cont=0;
	int segActual = 0;
	void setup()
	{
	  pinMode(LED_BUILTIN, OUTPUT);

	  Serial.begin(9600);
	  Serial.println(cont);
	}

	void loop()

	  {

	  	segActual = millis()/1000;
		if (segActual - segAnt >0) //verificar si pasó un seg.
	    {
	  		cont++; //si pasó un seg sumo 1 al contador
	   		segAnt = segActual;
	    	//Serial.println(segAnt);

	      	if(cont > 3)

	      		cont=0;
			Serial.println(cont);

	  	}
	}

	return EXIT_SUCCESS;
}
