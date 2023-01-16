#include "musicLibrary.h"
#include "Arduino.h"



//moonRepresentHeart
int melody1[] = {
  NOTE_G5, 2, REST, 8, NOTE_E5, 8, NOTE_D5, 8, NOTE_C5, 8, //1
  NOTE_E5, 1, 
  NOTE_A5, 2, REST, 8, NOTE_F5, 8, NOTE_D5, 8, NOTE_C5, 8,
  NOTE_B4, -2, REST, 8, NOTE_G4, 8, //4
  NOTE_C5, -4, NOTE_E5, 8, NOTE_G5, -4, NOTE_C5, 8,
  NOTE_B4, -4, NOTE_E5, 8, NOTE_G5, -4, NOTE_G5, 8,
  NOTE_A5, -4, NOTE_B5, 8, NOTE_C6, -4, NOTE_A5, 8,
  NOTE_G5, -2, NOTE_E5, 8, NOTE_D5, 8, //8
  NOTE_C5, -4, NOTE_C5, 8, NOTE_C5, 4, NOTE_E5, 8, NOTE_D5, 8,
  NOTE_C5, -4, NOTE_C5, 8, NOTE_C5, 4, NOTE_D5, 8, NOTE_E5, 8,
  NOTE_D5, -4, NOTE_C5, 8, NOTE_A4, 4, NOTE_E5, 4,
  NOTE_D5, -2, REST, 8, NOTE_G4, 8, //12
  NOTE_C5, -4, NOTE_E5, 8, NOTE_G5, -4, NOTE_C5, 8,
  NOTE_B4, -4, NOTE_E5, 8, NOTE_G5, -4, NOTE_G5, 8,
  NOTE_A5, -4, NOTE_B5, 8, NOTE_C6, -4, NOTE_A5, 8,
  NOTE_G5, -2, NOTE_E5, 8, NOTE_D5, 8, //16
  NOTE_C5, -4, NOTE_C5, 8, NOTE_C5, 4, NOTE_C5, 8, NOTE_D5, 8,
  NOTE_C5, -4, NOTE_C5, 8, NOTE_C5, 4, NOTE_D5, 8, NOTE_E5, 8,
  NOTE_D5, -4, NOTE_A4, 8, NOTE_B4, 4, NOTE_C5, 8, NOTE_D5, 8, //19
  NOTE_C5, -2, NOTE_G5, 4,
  NOTE_E5, -4, NOTE_D5, 8, NOTE_C5, 4, NOTE_G5, 8,
  NOTE_B4, -2, NOTE_A4, 8, NOTE_B4, 8,
  NOTE_A4, -4, NOTE_B4, 8, NOTE_A4, 4, NOTE_G4, 4, //23
  NOTE_E5, -2, NOTE_G5, 4,
  NOTE_E5, -4, NOTE_D5, 8, NOTE_C5, 4, NOTE_G5, 4, 
  NOTE_B4, -2, NOTE_A4, 8, NOTE_B4, 8,
  NOTE_C5, -4, NOTE_C5, 8, NOTE_C5, 4, NOTE_D5, 8, NOTE_E5, 8, //27
  NOTE_D5, -2, REST, 8, NOTE_G4, 8, 
  NOTE_C5, -4, NOTE_E5, 8, NOTE_G5, -4, NOTE_C5, 8,
  NOTE_B4, -4, NOTE_E5, 8, NOTE_G5, -4, NOTE_G5, 8,
  NOTE_A5, -4, NOTE_B5, 8, NOTE_C6, -4, NOTE_A5, 8, //31
  NOTE_G5, -2, NOTE_E5, 8, NOTE_D5, 8,
  NOTE_C5, -4, NOTE_C5, 8, NOTE_C5, 4, NOTE_E5, 8, NOTE_D5, 8,
  NOTE_C5, -4, NOTE_C5, 8, NOTE_C5, 4, NOTE_D5, 8, NOTE_E5, 8,
  NOTE_D5, -4, NOTE_A4, 8, NOTE_B4, 4, NOTE_C5, 8, NOTE_D5, 8, //35
  NOTE_C5, -2, NOTE_E5, 8, NOTE_D5, 8,
  NOTE_C5, -4, NOTE_C5, 8, NOTE_C5, 4, NOTE_E5, 8, NOTE_D5, 8,
  NOTE_C5, -4, NOTE_C5, 8, NOTE_C5, 4, NOTE_D5, 8, NOTE_E5, 8, //38
  NOTE_D5, -4, NOTE_A4, 8, NOTE_B4, 4, NOTE_C5, 8, NOTE_D5, 8,
  NOTE_C5, -2, REST, 4,  
};

//int melody0[] = {
//  // Never Gonna Give You Up - Rick Astley
//  // Score available at https://musescore.com/chlorondria_5/never-gonna-give-you-up_alto-sax
//  // Arranged by Chlorondria
//
//  NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,4, //1
//  NOTE_E5,-4, NOTE_FS5,-4, NOTE_A5,16, NOTE_G5,16, NOTE_FS5,8,
//  NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,2,
//  NOTE_A4,16, NOTE_A4,16, NOTE_B4,16, NOTE_D5,8, NOTE_D5,16,
//  NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,4, //repeat from 1
//  NOTE_E5,-4, NOTE_FS5,-4, NOTE_A5,16, NOTE_G5,16, NOTE_FS5,8,
//  NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,2,
//  NOTE_A4,16, NOTE_A4,16, NOTE_B4,16, NOTE_D5,8, NOTE_D5,16,
//  REST,4, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_D5,8, NOTE_E5,8, NOTE_CS5,-8,
//  NOTE_B4,16, NOTE_A4,2, REST,4, 
//
//  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,4, NOTE_A4,8, //7
//  NOTE_A5,8, REST,8, NOTE_A5,8, NOTE_E5,-4, REST,4, 
//  NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, NOTE_D5,8, NOTE_E5,8, REST,8,
//  REST,8, NOTE_CS5,8, NOTE_B4,8, NOTE_A4,-4, REST,4,
//  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, NOTE_A4,4,
//  NOTE_E5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,4, REST,4,
//   
//  NOTE_D5,2, NOTE_E5,8, NOTE_FS5,8, NOTE_D5,8, //13
//  NOTE_E5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,4, NOTE_A4,4,
//  REST,2, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8,
//  REST,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//
//  NOTE_E5,-8, NOTE_E5,-8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,-8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16, //18
//  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,8, NOTE_A4,8, NOTE_A4,8, 
//  NOTE_E5,4, NOTE_D5,2, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//  NOTE_A5,4, NOTE_CS5,8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//
//  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8,  //23
//  NOTE_E5,4, NOTE_D5,2, REST,4,
//  REST,8, NOTE_B4,8, NOTE_D5,8, NOTE_B4,8, NOTE_D5,8, NOTE_E5,4, REST,8,
//  REST,8, NOTE_CS5,8, NOTE_B4,8, NOTE_A4,-4, REST,4,
//  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, NOTE_A4,4,
//  REST,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8, NOTE_D5,8,
//  
//  REST,8, NOTE_A4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, //29
//  REST,8, NOTE_CS5,8, NOTE_B4,8, NOTE_A4,-4, REST,4,
//  NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, NOTE_A4,4, REST,8,
//  REST,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,4, NOTE_E5,-4, 
//  NOTE_D5,2, NOTE_D5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,4, 
//  NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8, NOTE_A4,8, NOTE_A4,4,
//
//  REST,-4, NOTE_A4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, //35
//  REST,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//  NOTE_E5,-8, NOTE_E5,-8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8, 
//
//  NOTE_E5,4, NOTE_D5,2, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16, //40
//  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//  NOTE_A5,4, NOTE_CS5,8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8,  
//  NOTE_E5,4, NOTE_D5,2, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//   
//  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16, //45
//  NOTE_A5,4, NOTE_CS5,8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8,  
//  NOTE_E5,4, NOTE_D5,2, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16, //45
//  
//  NOTE_A5,4, NOTE_CS5,8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8, 
//
//  NOTE_E5,4, NOTE_D5,2, REST,4
//};

//int melody2[] = {
//  // Dart Vader theme (Imperial March) - Star wars 
//  // Score available at https://musescore.com/user/202909/scores/1141521
//  // The tenor saxophone part was used
//  
//  NOTE_AS4,8, NOTE_AS4,8, NOTE_AS4,8,//1
//  NOTE_F5,2, NOTE_C6,2,
//  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
//  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
//  NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,8, NOTE_C5,8, NOTE_C5,8,
//  NOTE_F5,2, NOTE_C6,2,
//  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
//
//  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4, //8  
//  NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,-8, NOTE_C5,16, 
//  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
//  NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C5,-8, NOTE_C5,16,
//  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
//  
//  NOTE_C6,-8, NOTE_G5,16, NOTE_G5,2, REST,8, NOTE_C5,8,//13
//  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
//  NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C6,-8, NOTE_C6,16,
//  NOTE_F6,4, NOTE_DS6,8, NOTE_CS6,4, NOTE_C6,8, NOTE_AS5,4, NOTE_GS5,8, NOTE_G5,4, NOTE_F5,8,
//  NOTE_C6,1
// 
//  
//};

//int melody3[] = {
//  
//  // Mii Channel theme 
//  // Score available at https://musescore.com/user/16403456/scores/4984153
//  // Uploaded by Catalina Andrade 
//  
//  NOTE_FS4,8, REST,8, NOTE_A4,8, NOTE_CS5,8, REST,8,NOTE_A4,8, REST,8, NOTE_FS4,8, //1
//  NOTE_D4,8, NOTE_D4,8, NOTE_D4,8, REST,8, REST,4, REST,8, NOTE_CS4,8,
//  NOTE_D4,8, NOTE_FS4,8, NOTE_A4,8, NOTE_CS5,8, REST,8, NOTE_A4,8, REST,8, NOTE_F4,8,
//  NOTE_E5,-4, NOTE_DS5,8, NOTE_D5,8, REST,8, REST,4,
//
//  NOTE_GS4,8, REST,8, NOTE_CS5,8, NOTE_FS4,8, REST,8,NOTE_CS5,8, REST,8, NOTE_GS4,8, //5
//  REST,8, NOTE_CS5,8, NOTE_G4,8, NOTE_FS4,8, REST,8, NOTE_E4,8, REST,8,
//  NOTE_E4,8, NOTE_E4,8, NOTE_E4,8, REST,8, REST,4, NOTE_E4,8, NOTE_E4,8,
//  NOTE_E4,8, REST,8, REST,4, NOTE_DS4,8, NOTE_D4,8, 
//
//  NOTE_CS4,8, REST,8, NOTE_A4,8, NOTE_CS5,8, REST,8,NOTE_A4,8, REST,8, NOTE_FS4,8, //9
//  NOTE_D4,8, NOTE_D4,8, NOTE_D4,8, REST,8, NOTE_E5,8, NOTE_E5,8, NOTE_E5,8, REST,8,
//  REST,8, NOTE_FS4,8, NOTE_A4,8, NOTE_CS5,8, REST,8, NOTE_A4,8, REST,8, NOTE_F4,8,
//  NOTE_E5,2, NOTE_D5,8, REST,8, REST,4,
//
//  NOTE_B4,8, NOTE_G4,8, NOTE_D4,8, NOTE_CS4,4, NOTE_B4,8, NOTE_G4,8, NOTE_CS4,8, //13
//  NOTE_A4,8, NOTE_FS4,8, NOTE_C4,8, NOTE_B3,4, NOTE_F4,8, NOTE_D4,8, NOTE_B3,8,
//  NOTE_E4,8, NOTE_E4,8, NOTE_E4,8, REST,4, REST,4, NOTE_AS4,4,
//  NOTE_CS5,8, NOTE_D5,8, NOTE_FS5,8, NOTE_A5,8, REST,8, REST,4, 
//
//  REST,2, NOTE_A3,4, NOTE_AS3,4, //17 
//  NOTE_A3,-4, NOTE_A3,8, NOTE_A3,2,
//  REST,4, NOTE_A3,8, NOTE_AS3,8, NOTE_A3,8, NOTE_F4,4, NOTE_C4,8,
//  NOTE_A3,-4, NOTE_A3,8, NOTE_A3,2,
//
//  REST,2, NOTE_B3,4, NOTE_C4,4, //21
//  NOTE_CS4,-4, NOTE_C4,8, NOTE_CS4,2,
//  REST,4, NOTE_CS4,8, NOTE_C4,8, NOTE_CS4,8, NOTE_GS4,4, NOTE_DS4,8,
//  NOTE_CS4,-4, NOTE_DS4,8, NOTE_B3,1,
//  
//  NOTE_E4,4, NOTE_E4,4, NOTE_E4,4, REST,8,//25
//
//  //repeats 1-25
//
//  NOTE_FS4,8, REST,8, NOTE_A4,8, NOTE_CS5,8, REST,8,NOTE_A4,8, REST,8, NOTE_FS4,8, //1
//  NOTE_D4,8, NOTE_D4,8, NOTE_D4,8, REST,8, REST,4, REST,8, NOTE_CS4,8,
//  NOTE_D4,8, NOTE_FS4,8, NOTE_A4,8, NOTE_CS5,8, REST,8, NOTE_A4,8, REST,8, NOTE_F4,8,
//  NOTE_E5,-4, NOTE_DS5,8, NOTE_D5,8, REST,8, REST,4,
//  
//  NOTE_GS4,8, REST,8, NOTE_CS5,8, NOTE_FS4,8, REST,8,NOTE_CS5,8, REST,8, NOTE_GS4,8, //5
//  REST,8, NOTE_CS5,8, NOTE_G4,8, NOTE_FS4,8, REST,8, NOTE_E4,8, REST,8,
//  NOTE_E4,8, NOTE_E4,8, NOTE_E4,8, REST,8, REST,4, NOTE_E4,8, NOTE_E4,8,
//  NOTE_E4,8, REST,8, REST,4, NOTE_DS4,8, NOTE_D4,8, 
//
//  NOTE_CS4,8, REST,8, NOTE_A4,8, NOTE_CS5,8, REST,8,NOTE_A4,8, REST,8, NOTE_FS4,8, //9
//  NOTE_D4,8, NOTE_D4,8, NOTE_D4,8, REST,8, NOTE_E5,8, NOTE_E5,8, NOTE_E5,8, REST,8,
//  REST,8, NOTE_FS4,8, NOTE_A4,8, NOTE_CS5,8, REST,8, NOTE_A4,8, REST,8, NOTE_F4,8,
//  NOTE_E5,2, NOTE_D5,8, REST,8, REST,4,
//
//  NOTE_B4,8, NOTE_G4,8, NOTE_D4,8, NOTE_CS4,4, NOTE_B4,8, NOTE_G4,8, NOTE_CS4,8, //13
//  NOTE_A4,8, NOTE_FS4,8, NOTE_C4,8, NOTE_B3,4, NOTE_F4,8, NOTE_D4,8, NOTE_B3,8,
//  NOTE_E4,8, NOTE_E4,8, NOTE_E4,8, REST,4, REST,4, NOTE_AS4,4,
//  NOTE_CS5,8, NOTE_D5,8, NOTE_FS5,8, NOTE_A5,8, REST,8, REST,4, 
//
//  REST,2, NOTE_A3,4, NOTE_AS3,4, //17 
//  NOTE_A3,-4, NOTE_A3,8, NOTE_A3,2,
//  REST,4, NOTE_A3,8, NOTE_AS3,8, NOTE_A3,8, NOTE_F4,4, NOTE_C4,8,
//  NOTE_A3,-4, NOTE_A3,8, NOTE_A3,2,
//
//  REST,2, NOTE_B3,4, NOTE_C4,4, //21
//  NOTE_CS4,-4, NOTE_C4,8, NOTE_CS4,2,
//  REST,4, NOTE_CS4,8, NOTE_C4,8, NOTE_CS4,8, NOTE_GS4,4, NOTE_DS4,8,
//  NOTE_CS4,-4, NOTE_DS4,8, NOTE_B3,1,
//  
//  NOTE_E4,4, NOTE_E4,4, NOTE_E4,4, REST,8,//25
//
//  //finishes with 26
//  //NOTE_FS4,8, REST,8, NOTE_A4,8, NOTE_CS5,8, REST,8, NOTE_A4,8, REST,8, NOTE_FS4,8
//};

//rasasayang
int melody3[] = {
  NOTE_E4, 4, NOTE_F4, 4, NOTE_G4, 2, NOTE_G4, 2, NOTE_C5, 2, NOTE_B4, 4, NOTE_A4, 4,
  NOTE_G4, 4, NOTE_G4, 4, NOTE_E4, 4, NOTE_F4, 4, NOTE_G4, 2, NOTE_B4, 2, NOTE_A4, 4, NOTE_A4, 4, NOTE_G4, 4, NOTE_F4, 4,
  NOTE_E4, 2, NOTE_C4, 4, NOTE_E4, 4, NOTE_D4, 4, NOTE_D4, 4, NOTE_C4, 4, NOTE_E4, 4, 
  NOTE_D4, 2, NOTE_E4, 4, NOTE_F4, 4, NOTE_G4, 2, NOTE_G4, 2, NOTE_C5, 2, NOTE_B4, 4, NOTE_A4, 4,
  NOTE_G4, 4, NOTE_G4, 4, NOTE_E4, 4, NOTE_F4, 4, NOTE_G4, 2, NOTE_B4, 2, NOTE_A4, 4, NOTE_A4, 4, NOTE_G4, 4, NOTE_F4, 4,
  NOTE_E4, 2, NOTE_C4, 4, NOTE_E4, 4, NOTE_D4, 4, NOTE_D4, 4, NOTE_B3, 4, NOTE_D4, 4, NOTE_C4, 1
};

//caringway
int melody2[] = {
  NOTE_F4, 4, NOTE_F4, 4, NOTE_F4, 4, NOTE_A4, 4, NOTE_G4, 4, NOTE_E4, 4, NOTE_C4, 2, 
  NOTE_D4, 4, NOTE_D4, 4, NOTE_D4, 4, NOTE_F4, 4, NOTE_E4, 4, NOTE_C4, 4, NOTE_A3, 2, 
  NOTE_AS3, 4, NOTE_C4, 4, NOTE_D4, 4, NOTE_AS3, 4, NOTE_A3, 4, NOTE_C4, 4, NOTE_F4, 2,
  NOTE_D4, 4, NOTE_E4, 4, NOTE_F4, 4, NOTE_A4, 4, NOTE_G4, 4, NOTE_E4, 4, NOTE_C4, 2,
  NOTE_F4, 4, NOTE_F4, 4, NOTE_G4, 4, NOTE_A4, 4, NOTE_G4, 4, NOTE_E4, 4, NOTE_C4, 4, 
  NOTE_D4, 4, NOTE_D4, 4, NOTE_E4, 4, NOTE_F4, 4, NOTE_E4, 4, NOTE_C4, 4, NOTE_A3, 4,
  NOTE_AS3, 4, NOTE_C4, 4, NOTE_D4, 4, NOTE_AS3, 4, NOTE_A3, 4, NOTE_C4, 4, NOTE_F4, 2,
  NOTE_D4, 4, NOTE_E4, 4, NOTE_F4, 4, NOTE_A4, 4, NOTE_G4, -2, NOTE_F4, 4, NOTE_F4, -1, 
  NOTE_A4, 4, NOTE_AS4, 4, NOTE_C5, 4, NOTE_AS4, 4, NOTE_A4, 4, NOTE_G4, 4, 
  NOTE_A4, 4, NOTE_G4, 4, NOTE_F4, 4, NOTE_E4, 4, NOTE_F4, 4, NOTE_E4, 4, NOTE_D4, 4, NOTE_F4, 4,
  NOTE_C4, -2, NOTE_C4, 4, NOTE_D4, 4, NOTE_F4, 4, NOTE_F4, 4, NOTE_D5, 4, NOTE_C5, 4, NOTE_A4, 4, NOTE_B4, 4, NOTE_A4, 4,
  NOTE_G4, 4, NOTE_F4, 4, NOTE_D4, 4, NOTE_A4, 4, NOTE_G4, 2, NOTE_A4, 4, NOTE_AS4, 4,
  NOTE_C5, 4, NOTE_AS4, 4, NOTE_A4, 4, NOTE_G4, 4, NOTE_A4, 4, NOTE_G4, 4, NOTE_F4, 4, NOTE_E4, 4,
  NOTE_F4, 4, NOTE_A4, 4, NOTE_A4, 4, NOTE_C5, -2, NOTE_C5, 4,
  NOTE_D5, 4, NOTE_C5, 4, NOTE_AS4, 4, NOTE_A4, 4, NOTE_G4, 4, NOTE_F4, 4, NOTE_G4, 4, NOTE_A4, 4,
  NOTE_AS4, 2, NOTE_A4, 2, NOTE_F4, -2, NOTE_E4, 4, NOTE_F4, -1, NOTE_A4, 4, NOTE_AS4, 4,
  NOTE_C5, 4, NOTE_AS4, 4, NOTE_A4, 4, NOTE_G4, 4, NOTE_A4, 4, NOTE_G4, 4, NOTE_F4, 4, NOTE_E4, 4,
  NOTE_F4, 4, NOTE_E4, 4, NOTE_D4, 4, NOTE_F4, 4, NOTE_C4, -2, NOTE_C4, 4, 
  NOTE_D4, 4, NOTE_F4, 4, NOTE_F4, 4, NOTE_D5, 4, NOTE_C5, 4, NOTE_A4, 4, NOTE_AS4, 4, NOTE_A4, 4,
  NOTE_G4, 4, NOTE_F4, 4, NOTE_D4, 4, NOTE_A4, 4, NOTE_G4, 2, NOTE_A4, 4, NOTE_AS4, 4, 
  NOTE_C5, 4, NOTE_AS4, 4, NOTE_A4, 4, NOTE_G4, 4, NOTE_A4, 4, NOTE_G4, 4, NOTE_F4, 4, NOTE_E4, 4,
  NOTE_F4, 4, NOTE_A4, 4, NOTE_A4, 4, NOTE_D5, 4, NOTE_C5, -2, NOTE_C5, 4, 
  NOTE_D5, 4, NOTE_C5, 4, NOTE_AS4, 4, NOTE_A4, 4, NOTE_G4, 4, NOTE_F4, 4, NOTE_G4, 4, NOTE_A4, 4, 
  NOTE_AS4, 2, NOTE_A4, 2, NOTE_AS4, -2, NOTE_AS4, 4, NOTE_C5, 1, NOTE_G5, 1,
  
};

int melody4[] = {
  NOTE_A5, 8, NOTE_F5, 8, NOTE_D5,8,
  REST, 4,
  NOTE_A5, 8, NOTE_F5,8, NOTE_C5,8,
  REST, 4,
  NOTE_G5, 8, NOTE_E5, 8, NOTE_B4,8,
  REST, 4,
  NOTE_G5, 8, NOTE_E5, 8, NOTE_AS4,8,
  REST, 4,
  };


int sizeMelody1 = sizeof(melody1);
int sizeMelody1FirstNote = sizeof(melody1[0]);
int sizeMelody2 = sizeof(melody2);
int sizeMelody2FirstNote = sizeof(melody2[0]);
int sizeMelody3 = sizeof(melody3);
int sizeMelody3FirstNote = sizeof(melody3[0]);
int sizeMelody4 = sizeof(melody4);
int sizeMelody4FirstNote = sizeof(melody4[0]);

void playSong(int x) {
  if (x == 1){
    Serial.println(String("Music Lib: Melody 1 time"));
    playThisSong(x, melody1, sizeMelody1, sizeMelody1FirstNote);
  }
  else if (x ==2){
    Serial.println(String("Music Lib: Melody 2 time"));
    playThisSong(x, melody2, sizeMelody2, sizeMelody2FirstNote);
  }
  else if (x==3){
    Serial.println(String("Music Lib: Melody 3 time"));    
    playThisSong(x, melody3, sizeMelody3, sizeMelody3FirstNote);
  }
  else if (x==4){
  Serial.println(String("Music Lib: Melody 4 time"));    
  playThisSong(x, melody4, sizeMelody4, sizeMelody4FirstNote);
}
  // sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
  // there are two values per note (pitch and duration), so for each note there are four bytes
}



int thisNote = 0;
int past_melody;

void playThisSong(int x, int curMelody[], int sizeMelody, int sizeMelodyFirstNote){
  if(thisNote == 0){
    past_melody = x;
  }
  else if (thisNote > 0){
    if (past_melody != x){
      thisNote = 0;
      past_melody = x;
    }
  }

  int notes = sizeMelody / sizeMelodyFirstNote / 2;
  // this calculates the duration of a whole note in ms
  
  int wholenote = (60000 * 4) / tempo;
  int divider = 0, noteDuration = 0;

  if(thisNote < notes * 2){
    divider = curMelody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }
    // we only play the note for 90% of the duration, leaving 10% as a pause


//silentmode

//uncomment
    digitalWrite(VIBRATOR_PIN, HIGH);
    tone(SPEAKER_PIN, curMelody[thisNote], noteDuration*0.9, SPEAKER_CHANNEL);
    digitalWrite(VIBRATOR_PIN, LOW);

    delay(noteDuration);
    // Wait for the specified duration before playing the next note.
    noTone(SPEAKER_PIN, SPEAKER_CHANNEL);
    
    thisNote = thisNote + 2;
  }
    else if (thisNote == notes * 2){
   thisNote = 0;
  }
}
