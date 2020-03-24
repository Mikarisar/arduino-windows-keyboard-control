#include <IRremote.h>

IRrecv irrecv(2); // указываем вывод, к которому подключен приемник | infrared reciever pin
decode_results results;

int remoteButton;
int lastRemoteButton;

char numKey;

void setup() 
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() 
{
  /* Here is a description of
   * my remote controller buttons' codes
   * Your remote controller buttons' codes may be different,
   * so, check your codes first and change them here.
   */
  if ( irrecv.decode( &results )) // если данные пришли | if something recieved
  { 
    if (results.value == 16753245)
    {
      remoteButton = 1; //1
    }
    else if (results.value == 16736925)
    {
      remoteButton = 2; //2
    }
    else if (results.value == 16769565)
    {
      remoteButton = 3; //3
    }
    else if (results.value == 16720605)
    {
      remoteButton = 4; //4
    }
    else if (results.value == 16712445)
    {
      remoteButton = 5; //5
    }
    else if (results.value == 16761405)
    {
      remoteButton = 6; //6
    }
    else if (results.value == 16769055)
    {
      remoteButton = 7; //7
    }
    else if (results.value == 16754775)
    {
      remoteButton = 8; //8
    }  
    else if (results.value == 16748655)
    {
      remoteButton = 9; //9
    }
    else if (results.value == 16750695)
    {
      remoteButton = 0; //0
    }
    else if (results.value == 16738455)
    {
      remoteButton = 10; //* (10)
    }
    else if (results.value == 16756815)
    {
      remoteButton = 11; //# (11)
    }
    else if (results.value == 16718055)
    {
      remoteButton = 12; //вверх | up (12)
    }
    else if (results.value == 16730805)
    {
      remoteButton = 13; //вниз | down (13)
    }
    else if (results.value == 16716015)
    {
      remoteButton = 14; //влево | left (14)
    }
    else if (results.value == 16734885)
    {
      remoteButton = 15; //вправо | right (15)
    }
    else if (results.value == 16726215)
    {
      remoteButton = 16; //OK (16)
    }
    else // if (results.value == 4294967295)  //удерживание кнопки | buton hold
    {
      remoteButton = 17; //удерживание кнопки либо отсутствие нажатия | button hold or no pressing
    }


    /* Here you give the names of the buttons,
     * and these names will come to the PC via the COM port
     * !!!NAMES MUST BE CHAR TYPE!!!
     */
     
    if (remoteButton == 10)
    {
      Serial.println('A');
      lastRemoteButton = remoteButton;
    }
    else if (remoteButton == 11)
    {
      Serial.println('H');
      lastRemoteButton = remoteButton;
    }
    else if (remoteButton == 12)
    {
      Serial.println('U');
      lastRemoteButton = remoteButton;
    }
    else if (remoteButton == 13)
    {
      Serial.println('D');
      lastRemoteButton = remoteButton;
    }
    else if (remoteButton == 14)
    {
      Serial.println('L');
      lastRemoteButton = remoteButton;
    }
    else if (remoteButton == 15)
    {
      Serial.println('R');
      lastRemoteButton = remoteButton;
    }
    else if (remoteButton == 16)
    {
      Serial.println('O');
      lastRemoteButton = remoteButton;
    }
    else if (remoteButton == 17)
    {
      //ничего не происходит | nothing happens
    }
    else
    {
      numKey = remoteButton + '0'; //преобразует int в char | changes int to char
      Serial.println(numKey);
      lastRemoteButton = remoteButton;
    }
    
    irrecv.resume();
  }
}
