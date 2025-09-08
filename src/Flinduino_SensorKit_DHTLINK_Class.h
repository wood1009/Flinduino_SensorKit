#include "DHT.h"                       // Temp & Humidity
#include "DHT20.h"                     // Temp & Humidity
//Defines

#ifndef Flinduino_SensorKit_DHTLINK_h
#define Flinduino_SensorKit_DHTLINK_h


class DHTLINK {

	uint8_t DHTTYPE = DHT11;
	uint8_t DHTPIN = 3;

	DHT20 dht20;
	DHT dht11 = DHT(DHTPIN,DHTTYPE);

	public:
		DHTLINK();
		void DHTTYPECHECK();
		bool begin();
		float readTemperature();
		float readHumidity();
		void status();
		int DHTTYPEFOUND;
	private:
		int dht20LR_Time_T = 0;
		float dht20LR_Data_T = 0.0;
		int dht20LR_Time_H = 0;
		float dht20LR_Data_H = 0.0;
};

#endif