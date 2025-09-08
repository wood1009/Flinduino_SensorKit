#include "Flinduino_SensorKit_DHTLINK_Class.h"


DHTLINK::DHTLINK(){
}

void DHTLINK::DHTTYPECHECK(){
	Wire.begin();
	Wire.beginTransmission(0x38);
	if(Wire.endTransmission() == 0) DHTTYPEFOUND = 20;
	else DHTTYPEFOUND = 11;
return;
}

bool DHTLINK::begin(){
	DHTTYPECHECK();
	if(DHTTYPEFOUND == 20){dht20.begin(); return 1;}
	else { dht11.begin(); return 1; }
}

float DHTLINK::readTemperature(){
	if(DHTTYPEFOUND == 20) {
		if(millis() > dht20LR_Time_T + 1000) {
			Wire.begin();
			dht20LR_Time_T = millis();
			int status = dht20.read();
			dht20LR_Data_T = dht20.getTemperature();
		}
		return(dht20LR_Data_T );
	}
	else return(dht11.readTemperature());
}

float DHTLINK::readHumidity(){
	if(DHTTYPEFOUND == 20){
		if(millis() > dht20LR_Time_H + 1000) {
			Wire.begin();
			dht20LR_Time_H= millis();
			int status = dht20.read();
			dht20LR_Data_H = dht20.getHumidity();
		} 
		return(dht20LR_Data_H);
	}
	else return(dht11.readHumidity());
}

void DHTLINK::status(){
	if(DHTTYPEFOUND == 20){
		int status = dht20.read();
 		 switch (status){
 		   case DHT20_OK:
		      Serial.print("OK");
		      break;
		    case DHT20_ERROR_CHECKSUM:
		      Serial.print("Checksum error");
		      break;
		    case DHT20_ERROR_CONNECT:
		      Serial.print("Connect error");
		      break;
		    case DHT20_MISSING_BYTES:
		      Serial.print("Missing bytes");
		      break;
		    case DHT20_ERROR_BYTES_ALL_ZERO:
		      Serial.print("All bytes read zero");
		      break;
		    case DHT20_ERROR_READ_TIMEOUT:
		      Serial.print("Read time out");
		      break;
		    case DHT20_ERROR_LASTREAD:
		      Serial.print("Error read too fast");
		      break;
		    default:
		      Serial.print("Unknown error");
		      break;
		  }
		  Serial.print("\n");
	}
	else {
	Serial.println("DHT11 does not have a Status Check");
	}
}