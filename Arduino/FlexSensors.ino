const float VCC = 5;			// voltage at Ardunio 5V line
const float R_DIV = 47000.0;	// resistor used to create a voltage divider
const float flatResistance = 25000.0;	// resistance when flat
const float bendResistance = 100000.0;	// resistance at 90 deg



void ReadFlex(float &DFlexV, int FingerPin, String FingerName){
	

    int ADCflex = map(analogRead(FingerPin), 0, 4095, 0, 1023);
	  float Vflex = ADCflex * VCC / 1023.0;
	  float Rflex = R_DIV * (VCC / Vflex - 1.0);
	  float angle = map(Rflex, flatResistance, bendResistance, 0, 90.0);

    if(FingerName == "Thumb"){
          DFlexV = (angle-168)/1.5;
    }
    if(FingerName == "Index"){
          DFlexV = (angle-90)/1.8;
    }
    if(FingerName == "Middle"){
          DFlexV = angle-36;
    }
    if(FingerName == "Ring"){
          DFlexV = angle-35;
    }
    if(FingerName == "Pinky"){
          DFlexV = (angle-180)/1.5;
    }
    

}
void ReadFlexAnalog(float &DFlexV, int FingerPin){
	

    DFlexV = analogRead(FingerPin);

}