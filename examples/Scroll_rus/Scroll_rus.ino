#include "HDSP2000Shield.h"

const wchar_t text[] PROGMEM = L"Ублюдок, мать твою, а ну иди сюда, говно собачье! \
    Что, решил ко мне лезть?! Ты, засранец вонючий, мать твою, а? Ну, иди сюда,﻿\
     попробуй меня трахнуть, я тебя сам трахну, ублюдок, онанист чертов, будь ты проклят! \
     Иди, идиот, трахать тебя и всю твою семью, говно собачье, жлоб вонючий, дерьмо, сука, падла! \
     Иди сюда, мерзавец, негодяй, гад, иди сюда, ты, говно, ЖОПА!\0"; //some text
wchar_t c;
int txtLen = 0;
int startOffset = 0;

int wstrlen(wchar_t * text)
{
  int i = 0;
  while((wchar_t)pgm_read_word(&(text[i]))) {
    i++;
  }
  return i;
};

void setup()   {
  txtLen = wstrlen(text);
  HDSP2000.begin();
}

void loop()
{
    //wizzer
    if(startOffset > (txtLen - 4*dispCount - 1))
    {
        startOffset = 0;
    }

    for(int i = 0; i <= (dispCount*4); i++) {
        c = (wchar_t)pgm_read_word(&(text[startOffset + i]));
        if( c > 128)
            c -= 0xd050;
        HDSP2000.txtBuffer[i] = short(c);
    }

    startOffset++;

    if((startOffset > (txtLen - 4*dispCount - 1)) || (startOffset == 1))
    {
      delay(1000);
    }
    else
    {
      delay(120);
    }
}
