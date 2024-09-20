int clockPin = 5;
int latchPin = 6;
int dataPin = 7;

boolean leds[16];

void setup()
{
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
	atualizar();
}

void atualizar()
{
  	digitalWrite(latchPin, LOW);
  	
  	for(int i = 15; i >= 0; i--)
    {
      	digitalWrite(clockPin, LOW);
      	digitalWrite(dataPin, leds[i]);
      	digitalWrite(clockPin, HIGH);
    }
  
  	digitalWrite(latchPin, HIGH);
}

void limpar()
{
  	for(int i = 0; i < 16; i++)
    {	
     	leds[i] = LOW;
      	atualizar();
    }
}


//Efeito #1: acende um por um da esquerda para a direita
void Efeito1()
{
  	limpar();
  
  	for(int i = 0; i < 16; i++)
    {	
     	leds[i] = HIGH;
      	delay(40);
      	atualizar();
      
      	leds[i] = LOW;
      	delay(40);
      	atualizar();
    }
}


//Efeito #2: acende um por um da direita para a esquerda
void Efeito2()
{
  	limpar();
  
  	for(int i = 15; i >= 0; i--)
    {	
     	leds[i] = HIGH;
      	delay(40);
      	atualizar();
      
      	leds[i] = LOW;
      	delay(40);
      	atualizar();
    }
}


//Efeito #3: acende uma fileira inteira da esquerda para a direita
void Efeito3()
{
  	limpar();
  
  	for(int i = 0; i < 16; i++)
    {	
     	leds[i] = HIGH;
      	delay(80);
      	atualizar();
    }
  	for(int i = 0; i < 16; i++)
    {	
     	leds[i] = LOW;
      	delay(80);
      	atualizar();
    }
}


//Efeito #4: acende uma fileira inteira da direita para a esquerda
void Efeito4()
{
  	limpar();
  
  	for(int i = 15; i >= 0; i--)
    {	
     	leds[i] = HIGH;
      	delay(80);
      	atualizar();
    }
  	for(int i = 15; i >= 0; i--)
    {	
     	leds[i] = LOW;
      	delay(80);
      	atualizar();
    }
}


//Efeito #5: mix dos efeitos #1 e #4
void Efeito5()
{
  	limpar();
  
  	int j = 15;
  	int k = j;
  
  	for(j = 15; j >= 0; j--)
    {
      	for(int i = 0; i < k; i++)
        {
          	leds[i] = HIGH;
      		delay(50);
      		atualizar();
      
      		leds[i] = LOW;
      		delay(50);
      		atualizar();
        }
      	leds[j] = HIGH;
      	delay(50);
      	atualizar();
      
      	k--;
    }
  	
}

//Efeito #6: mix dos efeitos #2 e #3
void Efeito6()
{
  	limpar();
  
  	int j = 0;
  	int k = j;
  
  	for(j = 0; j < 16; j++)
    {
      	for(int i = 16; i >= k; i--)
        {
          	leds[i] = HIGH;
      		delay(50);
      		atualizar();
      
      		leds[i] = LOW;
      		delay(50);
      		atualizar();
        }
      	leds[j] = HIGH;
      	delay(50);
      	atualizar();
      
      	k++;
    }
  	
}

//Efeito #7: acende os leds de fora para dentro
void Efeito7()
{
  	limpar();
  	
  	int j = 0;
  	int k = 15;
  
  	for(int i = j; i < k; i++)
    {
      	leds[j] = HIGH;
      	delay(60);
      	atualizar();
      	leds[k] = HIGH;
      	delay(60);
      	atualizar();
      	
      	j++;
      	k--;
    }
  
  	j = 0;
  	k = 15;
  
  	for(int i = j; i < k; i++)
    {
      	leds[j] = LOW;
      	delay(60);
      	atualizar();
      	leds[k] = LOW;
      	delay(60);
      	atualizar();
      
      	j++;
      	k--;
    }
}

//Efeito #8: acende os leds de dentro para fora
void Efeito8()
{
  	limpar();
  	
  	int j = 7;
  	int k = 8;
  
  	for(int i = 0; i < 8; i++)
    {
      	leds[j] = HIGH;
      	delay(60);
      	atualizar();
      	leds[k] = HIGH;
      	delay(60);
      	atualizar();
      	
      	j--;
      	k++;
    }
  
  	j = 7;
  	k = 8;
  
  	for(int i = 0; i < 8; i++)
    {
      	leds[j] = LOW;
      	delay(60);
      	atualizar();
      	leds[k] = LOW;
      	delay(60);
      	atualizar();
      
      	j--;
      	k++;
    }
}

//Efeito #9: inverso do efeito #5
void Efeito9()
{
  	limpar();
  	
  	int j = 0;
  
  	for(j = 0; j < 16; j++)
    {
      	leds[j] = HIGH;
      	delay(40);
      	atualizar();
      	
      	for(int i = j+1; i < 16+1; i++)
        {
          	leds[i] = HIGH;
      		delay(40);
      		atualizar();
      
      		leds[i] = LOW;
      		delay(40);
      		atualizar();
        }
    }
}

//Efeito #10: inverso do efeito #6
void Efeito10()
{
  	limpar();
  	
  	int j = 15;
  
  	for(j = 15; j >= 0; j--)
    {
      	leds[j] = HIGH;
      	delay(40);
      	atualizar();
      	
      	for(int i = j-1; i >= 0; i--)
        {
          	leds[i] = HIGH;
      		delay(40);
      		atualizar();
      
      		leds[i] = LOW;
      		delay(40);
      		atualizar();
        }
    }
}

//Efeito #11: luzes aleatórias
void Efeito11()
{
  	limpar();
  
  	int num = random(1, 17);
  
  	leds[num] = HIGH;
  	delay(100);
  	atualizar();
  
  	leds[num] = LOW;
  	delay(100);
  	atualizar();
  	
}

//Efeito #12: duas luzes aleatórias por vez
void Efeito12()
{
	limpar();
  
  	int num1 = random(1, 17);
  	int num2 = random(1, 17);
  
  	if(num1 == num2)
    {
      	leds[num1] = HIGH;
      	delay(300);
      	atualizar;
    }
  	else if(num1 != num2)
    {
      	
      	leds[num1] = HIGH;
        atualizar();
      
      	leds[num2] = HIGH;
        atualizar();
     
      	delay(300);

        leds[num1] = LOW;
        atualizar();

        leds[num2] = LOW;
        atualizar();
      
    }
}

//Efeito #13: luzes de natal (par e ímpar)
void Efeito13()
{
  	limpar();
      
	for(int i = 0; i < 16; i++)
    {
    	if(i % 2 == 0 || i == 0)
        {
        	leds[i] = HIGH;
          	atualizar();
        }
    }
      
    delay(300);
	
	for(int i = 0; i < 16; i++)
    {
    	if(i % 2 == 0 || i == 0)
        {
        	leds[i] = LOW;
          	atualizar();
        }
    }
  
	for(int i = 0; i < 16; i++)
    {
    	if(i % 2 != 0)
        {
        	leds[i] = HIGH;
          	atualizar();
        }
    }
  
  	delay(300);

}

//Efeito #14: fileira de leds (a cada 4)
void Efeito14()
{
	limpar();
  
  	int a = 0;
  	int b = 4;
  	int c = 8;
  	int d = 12;
  
  	for(int i = 0; i < 4; i++)
    {
    	limpar();
      	
      	leds[a] = HIGH;
      	atualizar();
      	leds[b] = HIGH;
      	atualizar();
      	leds[c] = HIGH;
      	atualizar();
      	leds[d] = HIGH;
      	atualizar();
      
      	delay(200);
      
      	leds[a] = LOW;
      	atualizar();
      	leds[b] = LOW;
      	atualizar();
      	leds[c] = LOW;
      	atualizar();
      	leds[d] = LOW;
      	atualizar();
      
      	a++;
      	b++;
      	c++;
      	d++;
      
      	if(a == 16)
        {
            a = 0;
        }
        else if(b == 16)
        {
            b = 0;
        }
        else if(c == 16)
        {
            c = 0;
        }
        else if(d == 16)
        {
            d = 0;
        }
      	
    }
}

//Efeito #15: "vai e volta" até completar a sequência
void Efeito15()
{
	limpar();
  	
  	for(int count = 0; count <= 16; count++)
    {
    	for(int i = 0; i < count; i++)
        {	
            leds[i] = HIGH;
            delay(10);
          	atualizar();
        }
      	delay(100);
      	for(int i = count; i >= 0; i--)
        {
          	leds[i] = LOW;
            delay(10);
            atualizar();
        }
        delay(500);
    }
}

//Efeito #16: 
void Efeito16()
{
	limpar();
  
  	int a = 0;
  	int b = 2;
  
  	for(int i = 0; i < 15; i++)
    { 
    	leds[a] = HIGH;
      	delay(300);
      	atualizar();
      	leds[b] = HIGH;
      	delay(300);
      	atualizar();
      	
      	leds[a] = LOW;
      	atualizar();
      	leds[b] = LOW;
      	atualizar;
      	
      	a++;
      	b++;
    }
}

void loop() 
{
  	Efeito1();
  	Efeito2();
  	Efeito3();
  	Efeito4();
  	Efeito5();
  	Efeito6();
  	Efeito7();
  	Efeito8();
  	Efeito9();
  	Efeito10();
  	Efeito11();
  	Efeito12();
  	Efeito13();
  	Efeito14();
  	Efeito15();
	  Efeito16();
}
