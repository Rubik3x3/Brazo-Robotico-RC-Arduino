
#include <IRremote.h>   
#include <Servo.h>

#define Tecla_Arriba 0x9F600707    
#define Tecla_Abajo 0x9E610707
#define Tecla_Izquierda 0x9A650707   
#define Tecla_Derecha 0x9D620707 

#define Tecla_1 0xFB040707
#define Tecla_2 0xFA050707 
#define Tecla_3 0xF9060707

#define Tecla_4 0xF7080707
#define Tecla_5 0xF6090707
#define Tecla_6 0xF50A0707

#define Tecla_VolMas 0xF8070707
#define Tecla_VolMen 0xF40B0707 

#define Tecla_CanalMas 0xED120707 
#define Tecla_CanalMen 0xEF100707

Servo servoAbajo;
Servo servoAdelante;
Servo servoAgarrar;

int posAbajo = 0;
int posAdelante = 0;
int posAgarrar = 180;

int IR = 8;     
 
void setup() {
  Serial.begin(9600);     
  servoAbajo.attach(9);
  servoAdelante.attach(10);
  servoAgarrar.attach(11);
  IrReceiver.begin(IR, DISABLE_LED_FEEDBACK); 
  posAdelante = 90;
  posAbajo = 90;
  servoAgarrar.write(posAgarrar);
  servoAbajo.write(posAbajo);
  servoAdelante.write(posAdelante);
} 
 
void loop() {
  if (IrReceiver.decode()) {        

    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); 

    if (IrReceiver.decodedIRData.decodedRawData == Tecla_2){
      posAbajo = 90;
      servoAbajo.write(posAbajo);
    }

    if (IrReceiver.decodedIRData.decodedRawData == Tecla_3){
      posAbajo = 0;
      servoAbajo.write(posAbajo);
    }

    if (IrReceiver.decodedIRData.decodedRawData == Tecla_1){
      posAbajo = 180;
      servoAbajo.write(posAbajo);
    }

     if (IrReceiver.decodedIRData.decodedRawData == Tecla_4){
      posAdelante = 45;
      servoAdelante.write(posAdelante);
    }

    if (IrReceiver.decodedIRData.decodedRawData == Tecla_5){
      posAdelante = 90;
      servoAdelante.write(posAdelante);
    }

    if (IrReceiver.decodedIRData.decodedRawData == Tecla_6){
      posAdelante = 180;
      servoAdelante.write(posAdelante);
    }


    if (IrReceiver.decodedIRData.decodedRawData == Tecla_Izquierda){
      if(posAbajo < 165){
        posAbajo = posAbajo + 15;
      }
      servoAbajo.write(posAbajo);
    }

    if (IrReceiver.decodedIRData.decodedRawData == Tecla_Derecha){
      if(posAbajo > 15 ){
        posAbajo = posAbajo - 15;
      }
      servoAbajo.write(posAbajo);
    }

    if (IrReceiver.decodedIRData.decodedRawData == Tecla_Arriba){
      if(posAdelante < 150){
        posAdelante = posAdelante + 30;
      }
      servoAdelante.write(posAdelante);
    }

    if (IrReceiver.decodedIRData.decodedRawData == Tecla_Abajo){
      if(posAdelante > 30 ){
        posAdelante = posAdelante - 30;
      }
      servoAdelante.write(posAdelante);
    }

    if (IrReceiver.decodedIRData.decodedRawData == Tecla_CanalMas){
      posAgarrar = 180;
      servoAgarrar.write(posAgarrar);
    }

    if (IrReceiver.decodedIRData.decodedRawData == Tecla_CanalMen
    ){
      posAgarrar = 0;
      servoAgarrar.write(posAgarrar);
    }
    
    IrReceiver.resume();       
  }
  delay (100);            
}