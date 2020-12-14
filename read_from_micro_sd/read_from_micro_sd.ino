#include <SPI.h> //Include library.
#include <SD.h> //Include library.

File notepad; //Create a file object.

void setup()
{
  Serial.begin(9600); //Initializing serial port.
  Serial.print("Initializing:\n"); //Write in serial port "initializing".
  if(!SD.begin(10)) //If the card is not available.
  {
    Serial.print("failed \n"); //Write in serial port "failed".
    Serial.print(SD.begin(10));
    return; //Return.
  }
  
  Serial.print("done"); //Write in serial port "done".
  notepad = SD.open("memo.txt"); //Set the path to the object to the file.
  Serial.print(notepad);
  if(notepad) //If the file is available.
  {
    Serial.print("memo.txt"); //Write in serial port "text.txt".
    while(notepad.available()) //While the file is available.
    {
      Serial.write(notepad.read()); //Read line.
    }
    notepad.close(); //Close file.
  }
  else //else if the file is not available.
  {
    Serial.println("error opening"); //Write in serial port "error opening".
  }
}

void loop()
{
 
}
