//******************************************************************************************
//  File: InterruptSensor.h
//  Authors: Dan G Ogorchock & Daniel J Ogorchock (Father and Son)
//
//  Summary:  st::InterruptSensor is a generic class which inherits from st::Sensor.  This is the
//			  parent class for the st::IS_Motion class.
//			  In general, this file should not need to be modified.   
//
//  Change History:
//
//    Date        Who            What
//    ----        ---            ----
//    2015-01-03  Dan & Daniel   Original Creation
//
//
//******************************************************************************************

#ifndef ST_INTERRUPTSENSOR_H
#define ST_INTERRUPTSENSOR_H

#include "Sensor.h"

namespace st
{
	class InterruptSensor: public Sensor
	{
		private:
			byte m_nInterruptPin;	//pin that will be monitored for change of state
			bool m_bInterruptState; //the state (HIGH/LOW) in which an interrupt has triggered
			bool m_bStatus;			//true == interrupted
			bool m_bPullup;			//true == Internal Pullup resistor required, set in constructor call in your sketch
			bool m_bInitRequired;

			void checkIfTriggered(); 
			
		public:
			//constructor
			InterruptSensor(const String &name, byte pin, bool iState, bool internalPullup=false); //(defaults to NOT using internal pullup resistors)
			
			//destructor
			virtual ~InterruptSensor();
			
			//initialization function
			virtual void init();

			//update function 
			void update();

			//handles what to do when interrupt is triggered - all derived classes should implement this virtual function
			virtual void runInterrupt();

			//handles what to do when interrupt is ended - all derived classes should implement this virtual function
			virtual void runInterruptEnded();
			
			//gets
			inline byte getInterruptPin() const {return m_nInterruptPin;}
			inline bool getInterruptState() const {return m_bInterruptState;}
			inline bool getStatus() const {return m_bStatus;}	//whether or not the device is currently interrupted
			
			
			//sets
			void setInterruptPin(byte pin);
			void setInterruptState(bool b) {m_bInterruptState=b;}
	
			//debug flag to determine if debug print statements are executed (set value in your sketch)
			static bool debug;
	
	};
}


#endif