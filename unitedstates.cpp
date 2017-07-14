#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <math.h>
#include <fstream.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <ctime>
#include <mmgw.h>

struct usa
{
	char stat[20],cap[20],sup[10],pop[20],abr[3],oras1[20],oras2[20],guv[20],high[30],ht[7],low[30],dp[7],dens[5],fus[5],temp[7],nume[50],data[20],pol[20],nick[50],motto[60];
} s[51];

struct presidents
{
	char pren[20],nume[20],ann[6],anm[6],ans[6],ane[6];
} p[46];
int n,m,v[9999];
char data[30];

//main functions
void initializare();
void intro();
void outro();
void memorare();
void meniu();
//primary functions
void generalitati();
void database();
void aplicatii();
void foto();
void extra();
//secondary functions in order
void state0();
void state1();
void state2();
void state3();
void state4();
void state5();
void state6();
void state7();
void state8();
void presidents0();
void presidents1();
void presidents2();
void declaration0();
void declaration1();
void declaration2();
void declaration3();
void maps();
void hymn();
void sortare0();
void cautare0();
void quiz();
void thetime();
void sortare1();
void sortare1a();
void sortare1b();
void sortare2();
void sortare2a();
void sortare2b();
void sortare3();
void sortare3a();
void sortare3b();
void sortare4();
void sortare4a();
void sortare4b();
void sortare5();
void sortare5a();
void sortare5b();
void sortare6();
void sortare6a();
void sortare6b();
void sortare7();
void sortare7a();
void sortare7b();
void sortare8();
void sortare8a();
void sortare8b();
void cautare1();
void cautare2();
void cautare3();
void cautare4(char caut[20]);
void cautare5(char caut1[20], char caut2[20]);
void cautare6(char caut[20]);
void cautare7(char cautan[7]);
int random(int n, int max, int v[]);
void administration();

int main()
{
	initializare();
    intro();
    meniu();
}

void initializare()
{
	int gd = DETECT, gm, errorcode;
    initwindow(800, 600, "");
}

void intro()
{
	int ok;
	readimagefile("resources/intro.jpg",0,0,800,600);
	memorare();
	do
	{ 
		ok=1;
		if(click(669,487,782,592)) meniu();
	}			
	while(ok);
}

void meniu()
{
	int ok;
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/menu.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(204,170,462,210)) generalitati();
		if(click(204,221,462,261)) database();
		if(click(204,275,462,315)) foto();
		if(click(204,328,462,368)) aplicatii();
		if(click(204,381,462,421)) extra();
		if(click(204,433,462,473)) outro();
	}			
	while(ok);
} // end menu
	
void memorare()
{
	int k=0,kp=0;
	//usa
	fstream flux1("infiles/usa.txt",ios::in);
	do
	{
		k++;
		flux1>>s[k].stat>>s[k].cap>>s[k].sup>>s[k].pop>>s[k].abr>>s[k].oras1>>s[k].oras2>>s[k].guv>>s[k].high>>s[k].ht>>s[k].low>>s[k].dp>>s[k].dens>>s[k].fus>>s[k].temp>>s[k].nume>>s[k].data>>s[k].pol>>s[k].nick>>s[k].motto;
	}
	while(!flux1.eof());
	n=k;
	
	//presidents
	fstream flux4("infiles/presidents.txt",ios::in);
	do
	{
		kp++;
		flux4>>p[kp].pren>>p[kp].nume>>p[kp].ann>>p[kp].anm>>p[kp].ans>>p[kp].ane;
	}
	while(!flux4.eof());
	m=kp;
	flux1.close();
	flux4.close();
}

void outro()
{
	cleardevice();
	readimagefile("resources/outro.jpg",0,0,800,600);
	delay(2000);
	exit(1);
}

void generalitati()
{
	int i,ok;
	char word[400];
	fstream flux2("infiles/about.txt",ios::in);
	delay(100);
	setcolor(0);
	do
	{
		cleardevice();
		readimagefile("menus/general.jpg",0,0,800,600);
		for(i=1; i<=13; i++)
		{
			settextstyle(3,0,2);
			flux2.getline(word,299,'\n');
			outtextxy(230,120+30*i,word);
		}
		do{ok=0; if(click(0,538,60,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
	}
	while(!flux2.eof());
	meniu();
}

void database()
{
	int ok;
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/database.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(204,170,483,210)) state0();
		if(click(204,230,483,270)) presidents0();
		if(click(204,290,483,330)) declaration0();
		if(click(204,350,483,390)) maps();
		if(click(204,410,483,450)) hymn();
		if(click(0,538,60,600)) meniu(); if(click(740,538,800,600)) meniu();
	}			
	while(ok);
}

void foto()
{
	int i,k=0,ok,q=0;
	char poza[20],ii[5],file[10],word[400][41];
	cleardevice();
	readimagefile("menus/places.jpg",0,0,800,600);
	do{ok=0; if(click(0,538,60,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
	strcpy(file,"places/t");
	fstream flux("infiles/foto.txt",ios::in);
	do
	{
		k++;
		flux.getline(word[k],399,'\n');
	}
	while(!flux.eof());
	cleardevice();
	delay(100);
	setcolor(0);
	settextstyle(6,0,2);
	setbkcolor(15);
	readimagefile("menus/pfshow.jpg",0,0,800,600);
	for(i=1; i<=40; i++)
	{
		q++;
		start:
		itoa(q,ii,10);
		strcpy(poza,file);
		strcat(poza,ii);
		strcat(poza,".jpg");
		readimagefile(poza,267,212,719,515);
		setfillstyle(1,15);
		bar(209,156,800,183);
		outtextxy(210,158,word[q]);
		do
		{
			ok=0; 
			if(click(0,538,60,600)) 
			{
				q--;
				if(q>0) goto start;
				if(q==0) meniu();
			} 
			if(click(370,538,426,600)) 
			{
				PlaySound(NULL,NULL,0);
				meniu();
			}
			if(click(740,538,800,600)) ok=1;
			if(click(48,370,96,420)) PlaySound("sounds/foto.wav",NULL,SND_ASYNC);
			if(click(109,370,156,420)) PlaySound(NULL,NULL,0);
		} 
		while(ok==0);
	}
	PlaySound(NULL,NULL,0);
	meniu();
}

void aplicatii()
{
	int ok;
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/applications.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(204,230,482,270)) sortare0();
		if(click(204,283,482,323)) cautare0();
		if(click(204,335,482,375)) quiz();
		if(click(0,538,60,600)) meniu(); if(click(740,538,800,600)) meniu();
	}			
	while(ok);
}

void extra()
{
	int ok;
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/extras.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(204,230,482,270)) administration();
		if(click(204,283,482,323)) system("extras\\documentation.docx");
		if(click(204,335,482,375)) system("infiles\\readme.txt");
		if(click(0,538,60,600)) meniu(); if(click(740,538,800,600)) meniu();
	}			
	while(ok);
}

//start functions in order

//1.function 'generalitati' includes no other funtion and is written above

//2.functions of 'database' branch
void state0()
{
	int ok;
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/states.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(204,118,609,158)) state1();
		if(click(204,171,609,211)) state2();
		if(click(204,223,609,263)) state3();
		if(click(204,275,609,315)) state4();
		if(click(204,330,609,370)) state5();
		if(click(204,381,609,421)) state6();
		if(click(204,433,609,473)) state7();
		if(click(204,485,609,525)) state8();
		if(click(0,538,60,600)) database(); if(click(740,538,800,600)) meniu();
	}			
	while(ok);
}

void state1()
{
	int i,ok;
	char poza1[20],poza2[20],poza3[20],ii[5],file1[10],file2[10],file3[5];
	strcpy(file1,"flag/usf");
	strcpy(file2,"emblem/use");
	strcpy(file3,"statemaps/");
	cleardevice();
	readimagefile("menus/show1.jpg",0,0,800,600);
	delay(100);
	setcolor(0);
	settextstyle(6,0,1);
	for(i=1; i<=n; i++)
	{
		cleardevice();
		readimagefile("menus/show1.jpg",0,0,800,600);
		itoa(i,ii,10);
		strcpy(poza1,file1);
		strcat(poza1,ii);
		strcat(poza1,".jpg");
		strcpy(poza2,file2);
		strcat(poza2,ii);
		strcat(poza2,".jpg");
		strcpy(poza3,file3);
		strcat(poza3,ii);
		strcat(poza3,".jpg");
		settextstyle(6,0,3);
		line(126,99,459,99);
		line(117,102,467,102);
		line(195,103,195,560);
		line(198,103,198,560);
		outtextxy(200,70,s[i].stat);
		rectangle(9,149,181,281);
		readimagefile(poza1,10,150,180,280);
		settextstyle(6,0,1);
		rectangle(63,299,122,319);
		outtextxy(65,300,"Steag");
		rectangle(9,339,181,491);
		readimagefile(poza2,10,340,180,490);
		rectangle(53,509,134,529);
		outtextxy(55,510,"Insigna");
		rectangle(575,155,799,330);
		rectangle(579,159,796,301);
		readimagefile(poza3,580,160,795,300);
		outtextxy(655,305,"Harta");
		settextstyle(3,0,2);
		outtextxy(210,110,"Capitala:");
		settextstyle(3,0,1);
		outtextxy(290,113,s[i].cap);
		settextstyle(3,0,2);
		outtextxy(210,138,"Suprafata:");
		settextstyle(3,0,1);
		outtextxy(300,141,s[i].sup);
		outtextxy(370,141,"km2");
		settextstyle(3,0,2);
		outtextxy(210,166,"Populatie:");
		settextstyle(3,0,1);
		outtextxy(300,169,s[i].pop);
		outtextxy(380,169,"loc.");
		settextstyle(3,0,2);
		outtextxy(210,194,"Guvernator:");
		settextstyle(3,0,1);
		outtextxy(315,197,s[i].guv);
		settextstyle(3,0,2);
		outtextxy(210,222,"Cel mai mare oras:");
		settextstyle(3,0,1);
		outtextxy(373,225,s[i].oras1);
		settextstyle(3,0,2);
		outtextxy(210,250,"Al doilea oras:");
		settextstyle(3,0,1);
		outtextxy(335,253,s[i].oras2);
		settextstyle(3,0,2);
		outtextxy(210,278,"Cel mai inalt loc:");
		settextstyle(3,0,1);
		outtextxy(350,281,s[i].ht);
		outtextxy(390,281,"m -");
		outtextxy(410,281,s[i].high);
		settextstyle(3,0,2);
		outtextxy(210,306,"Cel mai jos loc:");
		settextstyle(3,0,1);
		outtextxy(345,309,s[i].dp);
		outtextxy(385,309,"m -");
		outtextxy(410,309,s[i].low);
		settextstyle(3,0,2);
		outtextxy(210,334,"Nume Initial:");
		settextstyle(3,0,1);
		outtextxy(320,337,s[i].nume);
		settextstyle(3,0,2);
		outtextxy(210,362,"Data Aderarii la Federatie:");
		settextstyle(3,0,1);
		outtextxy(430,365,s[i].data);
		settextstyle(3,0,2);
		outtextxy(210,390,"Porecla (Nickname):");
		settextstyle(3,0,1);
		outtextxy(385,393,s[i].nick);
		settextstyle(3,0,2);
		outtextxy(210,418,"Motto:");
		settextstyle(3,0,1);
		outtextxy(265,421,s[i].motto);
		settextstyle(3,0,2);
		outtextxy(210,446,"Abreviere:");
		settextstyle(3,0,1);
		outtextxy(303,449,s[i].abr);
		settextstyle(3,0,2);
		outtextxy(210,474,"Densitate:");
		settextstyle(3,0,1);
		outtextxy(300,477,s[i].dens);
		outtextxy(330,477,"loc./k");
		settextstyle(3,0,2);
		outtextxy(210,502,"Fus Orar:");
		settextstyle(3,0,1);
		outtextxy(295,505,"GMT");
		outtextxy(335,505,s[i].fus);
		settextstyle(3,0,2);
		outtextxy(210,530,"Politica:");
		settextstyle(3,0,1);
		outtextxy(280,533,s[i].pol);
		settextstyle(3,0,2);
		outtextxy(572,362,"Temperatura medie anuala");
		rectangle(570,360,800,414);
		rectangle(568,358,800,416);
		line(570,387,800,387);
		settextstyle(6,0,2);
		outtextxy(635,392,s[i].temp);
		settextstyle(1,0,1);
		outtextxy(690,389,"o");
		settextstyle(6,0,2);
		outtextxy(705,392,"C");
		do{ok=0; if(click(0,538,60,600)) state0(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
	}
	state0();
}

void state2()
{
	int i,j,l=0,kp=1,ok;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/show2.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,73,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(260,72,260,500);
		line(410,72,410,500);
		line(530,72,530,500);
		line(660,72,660,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(140,93,"NUME STAT");
		outtextxy(295,93,"CAPITALA");
		outtextxy(422,93,"SUPRAFATA");
		outtextxy(550,93,"POPULATIE");
		outtextxy(670,93,"ABREV.");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(127,140+l*37,s[i].stat);
		outtextxy(280,140+l*37,s[i].cap);
		outtextxy(435,140+l*37,s[i].sup);
		outtextxy(555,140+l*37,s[i].pop);
		outtextxy(686,140+l*37,s[i].abr);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) state0(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/show2.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	readimagefile("menus/info.jpg",0,0,800,600);
	delay(1000);
	state0();
}

void state3()
{
	int i,j,l=0,kp=1,ok;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/show3.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,73,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(260,72,260,500);
		line(425,72,425,500);
		line(580,72,580,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(140,93,"NUME STAT");
		outtextxy(280,93,"GUVERNATOR");
		outtextxy(450,93,"TOP ORAS #1");
		outtextxy(605,93,"TOP ORAS #2");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(127,140+l*37,s[i].stat);
		outtextxy(275,140+l*37,s[i].guv);
		outtextxy(440,140+l*37,s[i].oras1);
		outtextxy(595,140+l*37,s[i].oras2);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) state0(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/show3.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	readimagefile("menus/info.jpg",0,0,800,600);
	delay(1000);
	state0();
}

void state4()
{
	int i,j,l=0,kp=1,ok;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/show4.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,73,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(240,72,240,500);
		line(420,72,420,500);
		line(498,72,498,500);
		line(645,72,645,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(130,93,"NUME STAT");
		outtextxy(285,93,"LOC INALT");
		outtextxy(422,93,"INALTIME");
		outtextxy(535,93,"LOC JOS");
		outtextxy(650,93,"ADANCIME");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(117,140+l*37,s[i].stat);
		outtextxy(245,140+l*37,s[i].high);
		outtextxy(440,140+l*37,s[i].ht);
		outtextxy(505,140+l*37,s[i].low);
		outtextxy(675,140+l*37,s[i].dp);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) state0(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/show4.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	readimagefile("menus/info.jpg",0,0,800,600);
	delay(1000);
	state0();
}

void state5()
{
	int i,j,l=0,kp=1,ok;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/show5.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,73,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(240,72,240,500);
		line(350,72,350,500);
		line(445,72,445,500);
		line(630,72,630,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(130,93,"NUME STAT");
		outtextxy(245,80,"DENSITATEA");
		outtextxy(248,100,"POPULATIEI");
		outtextxy(355,93,"FUS ORAR");
		outtextxy(450,80,"TEMPERATURA");
		outtextxy(575,80,"MEDIE");
		outtextxy(505,100,"ANUALA");
		outtextxy(645,93,"POLITICA");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(117,140+l*37,s[i].stat);
		outtextxy(280,140+l*37,s[i].dens);
		outtextxy(385,140+l*37,s[i].fus);
		outtextxy(520,140+l*37,s[i].temp);
		outtextxy(640,140+l*37,s[i].pol);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) state0(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/show5.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	readimagefile("menus/info.jpg",0,0,800,600);
	delay(1000);
	state0();
}

void state6()
{
	int i,j,l=0,kp=1,ok;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/show6.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,73,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(260,72,260,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(140,93,"NUME STAT");
		outtextxy(300,93,"NUMELE INITIAL INAINTEA FORMARII FEDERATIEI");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(127,140+l*37,s[i].stat);
		outtextxy(290,140+l*37,s[i].nume);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) state0(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/show6.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	readimagefile("menus/info.jpg",0,0,800,600);
	delay(1000);
	state0();
}

void state7()
{
	int i,j,l=0,kp=1,ok;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/show7.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,73,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(260,72,260,500);
		line(480,72,480,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(140,93,"NUME STAT");
		outtextxy(285,93,"PORECLA (NICKNAME)");
		outtextxy(487,93,"DATA ADERARII LA FEDERATIE");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(127,140+l*37,s[i].stat);
		outtextxy(270,140+l*37,s[i].nick);
		outtextxy(570,140+l*37,s[i].data);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) state0(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/show7.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	readimagefile("menus/info.jpg",0,0,800,600);
	delay(1000);
	state0();
}

void state8()
{
	int i,j,l=0,kp=1,ok;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/show7.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,73,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(260,72,260,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(140,93,"NUME STAT");
		outtextxy(470,93,"MOTTO");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(127,140+l*37,s[i].stat);
		outtextxy(280,140+l*37,s[i].motto);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) state0(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/show7.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	readimagefile("menus/info.jpg",0,0,800,600);
	delay(1000);
	state0();
}

void presidents0()
{
	int ok;
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/presidents.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(204,245,497,285)) presidents1();
		if(click(204,313,497,353)) presidents2();
		if(click(0,538,60,600)) database(); if(click(740,538,800,600)) meniu();
	}			
	while(ok);
}

void presidents1()
{
	int i,ok;
	char poza[20],ii[5],file[20];
	strcpy(file,"presidents/p");
	setcolor(0);
	settextstyle(6,0,1);
	for(i=1; i<=m; i++)
	{
		cleardevice();
		readimagefile("menus/pshow1.jpg",0,0,800,600);
		readimagefile("resources/banner.jpg",180,320,610,400);
		itoa(i,ii,10);
		strcpy(poza,file);
		strcat(poza,ii);
		strcat(poza,".jpg");
		rectangle(27,149,193,351);
		readimagefile(poza,28,150,193,351);
		settextstyle(6,0,3);
		rectangle(193,149,450,230);
		setfillstyle(1,7);
		bar(194,150,450,230);
		setbkcolor(7);
		outtextxy(205,165,p[i].pren);
		outtextxy(205,195,p[i].nume);
		settextstyle(6,0,3);
		setbkcolor(15);
		outtextxy(370,319,p[i].ann);
		outtextxy(470,319,p[i].anm);
		outtextxy(340,383,p[i].ans);
		outtextxy(438,383,p[i].ane);
		do{ok=0; if(click(0,538,60,600)) presidents0(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
	}
	cleardevice();
	readimagefile("menus/info.jpg",0,0,800,600);
	delay(1000);
	presidents0();
}

void presidents2()
{
	int i,j,l=0,kp=1,ok;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/pshow2.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,73,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=m; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(260,72,260,500);
		line(400,72,400,500);
		line(500,72,500,500);
		line(600,72,600,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(130,93,"PRENUME");
		outtextxy(305,93,"NUME");
		outtextxy(437,80,"AN");
		outtextxy(412,100,"NASTERE");
		outtextxy(537,80,"AN");
		outtextxy(520,100,"DECES");
		outtextxy(634,93,"MANDAT");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(125,140+l*37,p[i].pren);
		outtextxy(280,140+l*37,p[i].nume);
		outtextxy(430,140+l*37,p[i].ann);
		outtextxy(530,140+l*37,p[i].anm);
		outtextxy(620,140+l*37,p[i].ans);
		outtextxy(665,140+l*37,"-");
		outtextxy(677,140+l*37,p[i].ane);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) presidents0(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/pshow2.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	do{ok=0; if(click(0,538,60,600)) presidents0(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
	cleardevice();
	readimagefile("menus/info.jpg",0,0,800,600);
	delay(1000);
	presidents0();
}

void declaration0()
{
	int ok;
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/declaration.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(204,215,498,255)) declaration1();
		if(click(204,283,498,323)) declaration2();
		if(click(204,350,498,390)) declaration3();
		if(click(0,538,60,600)) database(); if(click(740,538,800,600)) meniu();
	}			
	while(ok);
}

void declaration1()
{
	int ok;
	cleardevice();
	readimagefile("menus/dshow1.jpg",0,0,800,600);
	do{ok=0; if(click(0,538,60,600)) declaration0(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
	readimagefile("menus/dshow2.jpg",0,0,800,600);
	do{ok=1; if(click(0,538,60,600)) declaration1(); if(click(740,538,800,600)) meniu();} while(ok);
}

void declaration2()
{
	int i,ok;
	char word[400];
	fstream flux("infiles/declaration_en.txt",ios::in);
	delay(100);
	setcolor(0);
	do
	{
		cleardevice();
		readimagefile("menus/dshow3.jpg",0,0,800,600);
		for(i=1; i<=12; i++)
		{
			settextstyle(3,0,2);
			flux.getline(word,299,'\n');
			outtextxy(230,140+30*i,word);
		}
		do{ok=0; if(click(0,538,60,600)) declaration0(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
	}
	while(!flux.eof());
	declaration0();
}

void declaration3()
{
	int i,ok;
	char word[400];
	fstream flux("infiles/declaration_ro.txt",ios::in);
	delay(100);
	setcolor(0);
	do
	{
		cleardevice();
		readimagefile("menus/dshow3.jpg",0,0,800,600);
		for(i=1; i<=12; i++)
		{
			settextstyle(3,0,2);
			flux.getline(word,299,'\n');
			outtextxy(230,140+30*i,word);
		}
		do{ok=0; if(click(0,538,60,600)) declaration0(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
	}
	while(!flux.eof());
	declaration0();
}

void maps()
{
	int ok;
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/map.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(204,215,497,245)) 
		{
			readimagefile("resources/map1.jpg",0,0,800,600);
			do{ok=1; if(click(740,538,800,600)) maps();} while(ok);
		}
		if(click(204,283,497,323)) 
		{
			readimagefile("resources/map2.jpg",0,0,800,600);
			do{ok=1; if(click(740,538,800,600)) maps();} while(ok);
		}
		if(click(204,350,497,390)) 
		{
			readimagefile("resources/map3.jpg",0,0,800,600);
			do{ok=1; if(click(740,538,800,600)) maps();} while(ok);
		}
		if(click(0,538,60,600)) database(); if(click(740,538,800,600)) meniu();
	}			
	while(ok);
}

void hymn()
{
	int ok;
	cleardevice();
	readimagefile("menus/hymn.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(407,466,474,532)) PlaySound("sounds/hymn.wav",NULL,SND_ASYNC);
		if(click(490,466,555,532)) PlaySound(NULL,NULL,0);
		if(click(0,538,60,600))
		{
			PlaySound(NULL,NULL,0);
			database();
		}
		if(click(740,538,800,600))
		{
			PlaySound(NULL,NULL,0);
			meniu();
		}
	}			
	while(ok);
}

void sortare0()
{
	int ok;
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/sort.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(204,118,491,158)) sortare1();
		if(click(204,170,491,210)) sortare2();
		if(click(204,222,491,262)) sortare3();
		if(click(204,275,491,315)) sortare4();
		if(click(204,328,491,368)) sortare5();
		if(click(204,381,491,421)) sortare6();
		if(click(204,433,491,473)) sortare7();
		if(click(204,486,491,526)) sortare8();
		if(click(0,538,60,600)) aplicatii(); if(click(740,538,800,600)) meniu();
	}			
	while(ok);
}

void cautare0()
{
	int ok,ok2;
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/search.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(204,132,513,172)) cautare1();
		if(click(204,186,513,226)) cautare2();
		if(click(204,238,513,278)) cautare3();
		if(click(204,291,513,331))
		{
			char caut[20];
			cleardevice();
			readimagefile("menus/search4.jpg",0,0,800,600);
			setcolor(0);
			settextstyle(6,0,3);
			setbkcolor(15);
			cautare4(caut);
		}
		if(click(204,343,513,383)) 
		{
			char caut1[20],caut2[20];
			cleardevice();
			readimagefile("menus/search5.jpg",0,0,800,600);
			setcolor(0);
			settextstyle(6,0,3);
			setbkcolor(15);
			cautare5(caut1,caut2);
		}
		if(click(204,396,513,436)) 
		{
			char caut[20];
			cleardevice();
			readimagefile("menus/search6.jpg",0,0,800,600);
			setcolor(0);
			settextstyle(6,0,3);
			setbkcolor(15);
			cautare6(caut);
		}
		if(click(204,448,513,488)) 
		{
			char cautan[20];
			cleardevice();
			readimagefile("menus/search7.jpg",0,0,800,600);
			setcolor(0);
			settextstyle(6,0,3);
			setbkcolor(15);
			cautare7(cautan);
		}
		if(click(0,538,60,600)) aplicatii(); if(click(740,538,800,600)) meniu();
	}			
	while(ok);
}

int random(int n, int max, int v[])
{
	int i, j, nr, ok;
	srand(time(NULL)); 
	for(i=1;i<=n;i++)
	{
		do
		{
		   ok=1;
		   nr=rand()%max+1;
		   for(j=1;j<=i;j++) if(nr==v[j]) ok=0;
		   if(ok==1) v[i]=nr;
		}
		while(ok==0);
	}
   return *v;
}

void thetime()
{
	char year[5],month[3],day[3],hour[3],min[3],sec[3];
	//needs <ctime>
	time_t now = time(0);
  	tm *ltm = localtime(&now);
	cleardevice();
	itoa(1900 + ltm->tm_year,year,10);
	itoa(ltm->tm_mon + 1,month,10);
    itoa(1+ltm->tm_mday - 1,day,10);
    itoa(ltm->tm_hour,hour,10);
	itoa(ltm->tm_min,min,10);
	itoa(ltm->tm_sec,sec,10);
	strcpy(data,day); strcat(data,"/"); strcat(data,month); strcat(data,"/"); strcat(data,year); strcat(data," "); strcat(data,hour); strcat(data,":"); strcat(data,min); strcat(data,":"); strcat(data,sec);
}

void quiz()
{
	int kr=0,kw=0,kn=0,nq,i,kq=0,k=0,ok2,ok;
	char lit,a[2],sirkr[5],sirkw[5],name[30],quest[31][500],var1[31][100],var2[31][100],var3[31][100],var4[31][100],answer[31][2];
	cleardevice();
	fstream flux("infiles/quiz.txt",ios::in);
	do
	{
		kq++;
		flux.getline(quest[kq],555,'\n'); 
		flux.getline(var1[kq],555,'\n');
		flux.getline(var2[kq],555,'\n');
		flux.getline(var3[kq],555,'\n');
		flux.getline(var4[kq],555,'\n');
		flux.getline(answer[kq],555,'\n');
	}
	while(!flux.eof());
	flux.close(); 
	nq=kq;
	random(nq,nq,v);
	readimagefile("menus/quiz.jpg",0,0,800,600);
	PlaySound("sounds/qstart.wav",NULL,SND_ASYNC);
	do
	{ 
		ok2=1;
		if(click(0,538,60,600)) {PlaySound(NULL,NULL,0); aplicatii();} if(click(740,538,800,600)) {PlaySound(NULL,NULL,0); meniu();}
		if(click(375,418,701,445))
		{
			setfillstyle(1,15);
			bar(375,418,701,445);
			do
			{
				start:
				lit=getch();
				if(lit!=char(8))
				{
					name[k]=lit; name[k+1]=NULL;
					outtextxy(380,423,name);
					k++;
				}
				if(lit==char(8)) if(k==0) goto start;
				if(lit==char(8))
				{
					name[k]=lit; name[k+1]=NULL;
					name[k-1]=NULL;
					k--;
					setfillstyle(1,15);
					bar(375,418,701,445);
					outtextxy(380,423,name);
					goto start;
				}
			}
			while(lit!=char(13));
			name[k-1]=NULL;
			readimagefile("resources/startbutton.jpg",370,495,550,540);
		}
		if(click(370,495,550,540))
		{
			thetime();
			//questions
			for(i=1;i<=nq;i++)
			{
				cleardevice();
				PlaySound(NULL,NULL,0);
				readimagefile("menus/qshow.jpg",0,0,800,600);
				PlaySound("sounds/qquestion.wav",NULL,SND_ASYNC);
				delay(100);
				setcolor(0);
				settextstyle(3,0,2);
				setbkcolor(15);
				setlinestyle(0,0,0);
				outtextxy(211,171,quest[v[i]]);
				settextstyle(6,0,1);
				outtextxy(261,252,var1[v[i]]);
				outtextxy(261,292,var2[v[i]]);
				outtextxy(261,332,var3[v[i]]);
				outtextxy(261,372,var4[v[i]]);
				lit=getch();
				if(lit==char(27)) goto quizend;
				delay(55);
				a[0]=lit; a[1]=NULL;
				settextstyle(6,0,4);
				outtextxy(363,427,a);
				delay(500);
				if(strcmp(a,answer[v[i]])==0)
				{
					kr++;
					readimagefile("resources/qcorrect.jpg",482,420,620,460);
					PlaySound("sounds/qright.wav",NULL,SND_ASYNC);
					do{ok=0; if(click(0,538,60,600)) goto quizend; if(click(740,538,800,600)) ok=1;} while(ok==0);
				}
				else if(strcmp(a,answer[v[i]])!=0)
				{
					kw++;
					readimagefile("resources/qincorrect.jpg",482,420,620,460);
					PlaySound("sounds/qwrong.wav",NULL,SND_ASYNC);
					delay(700);
					setcolor(4);
					settextstyle(6,0,2);
					outtextxy(260,485,"Raspunsul corect era");
					outtextxy(520,485,answer[v[i]]);
					do{ok=0; if(click(0,538,60,600)) goto quizend; if(click(740,538,800,600)) ok=1;} while(ok==0);
				}
				if(lit==char(27)) meniu();
			}
			//end of quiz
			quizend: 
			{
				ofstream flux3("infiles/quiz_score.txt",ios::app);
				flux3<<name<<" "<<kr<<" "<<kw<<" "<<data<<endl;
				fstream flux("resources/quiz_temp.html",ios::out);
				flux<<"<HTML><HEAD><TITLE>State</title></head>";
				flux<<"<body><center><font face='Papyrus' size='36'>Statele Unite ale Americii</font></center><br><hr>";
				flux<<"<br><br><center><h1>Rezulatate Quiz</h1><br><table border=\"1\" bgcolor=\"GhostWhite\" width=\"44%\">";
				flux<<"<tr align=\"center\"><td bgcolor='lightgray'><b>Top</b><td bgcolor='lightgray'><b>Concurent</b>";
				flux<<"<td bgcolor='lightgray'><b>Raspunsuri Corecte</b><td bgcolor='lightgray'><b>Raspunsuri Gresite</b><td bgcolor='lightgray'><b>Data si ora</b>"<<endl;
				int ka=0,i,skr[100],skw[100],ok3,inv,inv3;
				char nume[100][30],inv2[30],date[100][30],inv4[30],time[100][30],inv5[30];
				fstream flux2("infiles/quiz_score.txt",ios::in);
				do
				{
					ka++;
					flux2>>nume[ka]>>skr[ka]>>skw[ka]>>date[ka]>>time[ka];
				}
				while(!flux2.eof());
				do
				{
					ok3=0;
					for(i=1; i<ka; i++) if(skr[i]<skr[i+1])
					{
						ok3=1;
						inv=skr[i];
						skr[i]=skr[i+1];
						skr[i+1]=inv;
						strcpy(inv2,nume[i]);
						strcpy(nume[i],nume[i+1]);
						strcpy(nume[i+1],inv2);
						inv3=skw[i];
						skw[i]=skw[i+1];
						skw[i+1]=inv3;
						strcpy(inv4,date[i]);
						strcpy(date[i],date[i+1]);
						strcpy(date[i+1],inv4);
						strcpy(inv5,time[i]);
						strcpy(time[i],time[i+1]);
						strcpy(time[i+1],inv5);
					}
				}
				while(ok3!=0);
				ofstream flux4("resources/quiz_temp.html",ios::app);
				for(i=1; i<ka; i++) flux4<<"<tr><td  align=\"center\">"<<i<<"<td><center>"<<nume[i]<<"</center><td><center>"<<skr[i]<<"</center><td><center>"<<skw[i]<<"</center><td><center>"<<date[i]<<" "<<time[i]<<"</center>"<<endl;
				flux4<<"</table></center></body></html>"; 
				flux4.close();
				cleardevice();
				PlaySound(NULL,NULL,0);
				readimagefile("menus/quizend.jpg",0,0,800,600);
				PlaySound("sounds/qend.wav",NULL,SND_ASYNC);
				setcolor(0);
				settextstyle(6,0,2);
				setbkcolor(15);
				itoa(kr,sirkr,10);
				itoa(kw,sirkw,10);
				outtextxy(425,312,sirkr);
				outtextxy(425,340,sirkw);
				do
				{
					ok=1; 
					if(click(534,478,669,518))
					{
						system("copy resources\\quiz_temp.html outfiles\\quiz.html");
						system("outfiles\\quiz.html"); aplicatii();}
					if(click(534,530,669,570))
					{
						PlaySound(NULL,NULL,0);
						aplicatii();
					}
				} 
				while(ok);
			}
			meniu();
		}
	}
	while(ok2);
}

void sortare1()
{
	int ok;
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/s1.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(204,253,535,293)) sortare1a();
		if(click(204,313,535,353)) sortare1b();
		if(click(0,538,60,600)) sortare0(); if(click(740,538,800,600)) meniu();
	}			
	while(ok);
}

void sortare1a()
{
	int ok=0,i;
	char cuv[51][20],inv[20],cuv2[51][20],inv2[20];
	for(i=1; i<=n; i++) 
	{
		strcpy(cuv[i],s[i].stat);
		strcpy(cuv2[i],s[i].cap);
	}
	do
	{
		ok=0;
		for(i=1; i<n; i++) if(strcmp(cuv[i],cuv[i+1])>0)
		{
			ok=1;
			strcpy(inv,cuv[i]);
			strcpy(cuv[i],cuv[i+1]);
			strcpy(cuv[i+1],inv);
			strcpy(inv2,cuv2[i]);
			strcpy(cuv2[i],cuv2[i+1]);
			strcpy(cuv2[i+1],inv2);
		}
	}
	while(ok!=0);
	int j,l=0,kp=1;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/sshow1.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,71,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(400,72,400,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(235,93,"STAT");
		outtextxy(530,93,"CAPITALA");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(200,140+l*37,cuv[i]);
		outtextxy(510,140+l*37,cuv2[i]);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) sortare1(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/sshow1.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/save.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(393,260,527,300)) 
		{
			fstream flux("outfiles/s_stat_az.html",ios::out);
			flux<<"<HTML><HEAD><TITLE>State</title></head>";
			flux<<"<body><center><font face='Papyrus' size='36'>Statele Unite ale Americii</font></center><br><hr>";
			flux<<"<br><br><center><h1>Sortare state in ordine alfabetica</h1><br><table border=\"1\" bgcolor=\"GhostWhite\" width=\"44%\">";
			flux<<"<tr align=\"center\"><td bgcolor='lightgray'><b>Nr.crt</b><td bgcolor='lightgray'><b>Stat</b><td bgcolor='lightgray'><b>Capitala</b>"<<endl;
			for(i=1; i<=n; i++) flux<<"<tr><td  align=\"center\">"<<i<<"<td><center>"<<cuv[i]<<"</center><td><center>"<<cuv2[i]<<endl<<"</center>";
			flux<<"</table></center></body></html>"; 
			flux.close();
			cleardevice();
			readimagefile("menus/savefile.jpg",0,0,800,600);
			outtextxy(344,158,"s_stat_az.html");
			do{
				ok=1; 
				if(click(392,298,525,338)) {system("outfiles\\s_stat_az.html"); sortare0();}
				if(click(393,359,525,399)) sortare0();
			} 
			while(ok);
		}
		if(click(393,321,527,361))
		{
			cleardevice();
			readimagefile("menus/savenull.jpg",0,0,800,600);
			delay(1500);
			sortare0();
		}
	}			
	while(ok);
}

void sortare1b()
{
	int ok=0,i;
	char cuv[51][20],inv[20],cuv2[51][20],inv2[20];
	for(i=1; i<=n; i++) 
	{
		strcpy(cuv[i],s[i].stat);
		strcpy(cuv2[i],s[i].cap);
	}
	do
	{
		ok=0;
		for(i=1; i<n; i++) if(strcmp(cuv[i],cuv[i+1])<0)
		{
			ok=1;
			strcpy(inv,cuv[i]);
			strcpy(cuv[i],cuv[i+1]);
			strcpy(cuv[i+1],inv);
			strcpy(inv2,cuv2[i]);
			strcpy(cuv2[i],cuv2[i+1]);
			strcpy(cuv2[i+1],inv2);
		}
	}
	while(ok!=0);
	int j,l=0,kp=1;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/sshow1.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,71,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(400,72,400,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(235,93,"STAT");
		outtextxy(530,93,"CAPITALA");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(200,140+l*37,cuv[i]);
		outtextxy(510,140+l*37,cuv2[i]);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) sortare1(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/sshow1.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/save.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(393,260,527,300)) 
		{
			fstream flux("outfiles/s_stat_za.html",ios::out);
			flux<<"<HTML><HEAD><TITLE>State</title></head>";
			flux<<"<body><center><font face='Papyrus' size='36'>Statele Unite ale Americii</font></center><br><hr>";
			flux<<"<br><br><center><h1>Sortare state in ordine invers alfabetica</h1><br><table border=\"1\" bgcolor=\"GhostWhite\" width=\"44%\">";
			flux<<"<tr align=\"center\"><td bgcolor='lightgray'><b>Nr.crt</b><td bgcolor='lightgray'><b>Stat</b><td bgcolor='lightgray'><b>Capitala</b>"<<endl;
			for(i=1; i<=n; i++) flux<<"<tr><td  align=\"center\">"<<i<<"<td><center>"<<cuv[i]<<"</center><td><center>"<<cuv2[i]<<endl<<"</center>";
			flux<<"</table></center></body></html>"; 
			flux.close();
			cleardevice();
			readimagefile("menus/savefile.jpg",0,0,800,600);
			outtextxy(344,158,"s_stat_za.html");
			do{
				ok=1; 
				if(click(392,298,525,338)) {system("outfiles\\s_stat_za.html"); sortare0();}
				if(click(393,359,525,399)) sortare0();
			} 
			while(ok);
		}
		if(click(393,321,527,361))
		{
			cleardevice();
			readimagefile("menus/savenull.jpg",0,0,800,600);
			delay(1500);
			sortare0();
		}
	}			
	while(ok);
}

void sortare2()
{
	int ok;
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/s2.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(204,253,535,293)) sortare2a();
		if(click(204,313,535,353)) sortare2b();
		if(click(0,538,60,600)) sortare0(); if(click(740,538,800,600)) meniu();
	}			
	while(ok);
}

void sortare2a()
{
	int ok=0,i;
	char cuv[51][20],inv[20],cuv2[51][20],inv2[20];
	for(i=1; i<=n; i++) 
	{
		strcpy(cuv[i],s[i].cap);
		strcpy(cuv2[i],s[i].stat);
	}
	do
	{
		ok=0;
		for(i=1; i<n; i++) if(strcmp(cuv[i],cuv[i+1])>0)
		{
			ok=1;
			strcpy(inv,cuv[i]);
			strcpy(cuv[i],cuv[i+1]);
			strcpy(cuv[i+1],inv);
			strcpy(inv2,cuv2[i]);
			strcpy(cuv2[i],cuv2[i+1]);
			strcpy(cuv2[i+1],inv2);
		}
	}
	while(ok!=0);
	int j,l=0,kp=1;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/sshow2.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,71,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(400,72,400,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(215,93,"CAPITALA");
		outtextxy(545,93,"STAT");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(210,140+l*37,cuv[i]);
		outtextxy(520,140+l*37,cuv2[i]);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) sortare2(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/sshow2.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/save.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(393,260,527,300)) 
		{
			fstream flux("outfiles/s_cap_az.html",ios::out);
			flux<<"<HTML><HEAD><TITLE>Capitale</title></head>";
			flux<<"<body><center><font face='Papyrus' size='36'>Statele Unite ale Americii</font></center><br><hr>";
			flux<<"<br><br><center><h1>Sortare capitale in ordine alfabetica</h1><br><table border=\"1\" bgcolor=\"GhostWhite\" width=\"44%\">";
			flux<<"<tr align=\"center\"><td bgcolor='lightgray'><b>Nr.crt</b><td bgcolor='lightgray'><b>Capitala</b><td bgcolor='lightgray'><b>Stat</b>"<<endl;
			for(i=1; i<=n; i++) flux<<"<tr><td  align=\"center\">"<<i<<"<td><center>"<<cuv[i]<<"</center><td><center>"<<cuv2[i]<<endl<<"</center>";
			flux<<"</table></center></body></html>"; 
			flux.close();
			cleardevice();
			readimagefile("menus/savefile.jpg",0,0,800,600);
			outtextxy(344,158,"s_cap_az.html");
			do{
				ok=1; 
				if(click(392,298,525,338)) {system("outfiles\\s_cap_az.html"); sortare0();}
				if(click(393,359,525,399)) sortare0();
			} 
			while(ok);
		}
		if(click(393,321,527,361))
		{
			cleardevice();
			readimagefile("menus/savenull.jpg",0,0,800,600);
			delay(1500);
			sortare0();
		}
	}
	while(ok);	
}

void sortare2b()
{
	int ok=0,i;
	char cuv[51][20],inv[20],cuv2[51][20],inv2[20];
	for(i=1; i<=n; i++) 
	{
		strcpy(cuv[i],s[i].cap);
		strcpy(cuv2[i],s[i].stat);
	}
	do
	{
		ok=0;
		for(i=1; i<n; i++) if(strcmp(cuv[i],cuv[i+1])<0)
		{
			ok=1;
			strcpy(inv,cuv[i]);
			strcpy(cuv[i],cuv[i+1]);
			strcpy(cuv[i+1],inv);
			strcpy(inv2,cuv2[i]);
			strcpy(cuv2[i],cuv2[i+1]);
			strcpy(cuv2[i+1],inv2);
		}
	}
	while(ok!=0);
	int j,l=0,kp=1;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/sshow2.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,71,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(400,72,400,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(215,93,"CAPITALA");
		outtextxy(545,93,"STAT");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(210,140+l*37,cuv[i]);
		outtextxy(520,140+l*37,cuv2[i]);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) sortare2(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/sshow2.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/save.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(393,260,527,300)) 
		{
			fstream flux("outfiles/s_cap_za.html",ios::out);
			flux<<"<HTML><HEAD><TITLE>Capitale</title></head>";
			flux<<"<body><center><font face='Papyrus' size='36'>Statele Unite ale Americii</font></center><br><hr>";
			flux<<"<br><br><center><h1>Sortare capitale in ordine invers alfabetica</h1><br><table border=\"1\" bgcolor=\"GhostWhite\" width=\"44%\">";
			flux<<"<tr align=\"center\"><td bgcolor='lightgray'><b>Nr.crt</b><td bgcolor='lightgray'><b>Capitala</b><td bgcolor='lightgray'><b>Stat</b>"<<endl;
			for(i=1; i<=n; i++) flux<<"<tr><td  align=\"center\">"<<i<<"<td><center>"<<cuv[i]<<"</center><td><center>"<<cuv2[i]<<endl<<"</center>";
			flux<<"</table></center></body></html>"; 
			flux.close();
			cleardevice();
			readimagefile("menus/savefile.jpg",0,0,800,600);
			outtextxy(344,158,"s_cap_za.html");
			do{
				ok=1; 
				if(click(392,298,525,338)) {system("outfiles\\s_cap_za.html"); sortare0();}
				if(click(393,359,525,399)) sortare0();
			} 
			while(ok);
		}
		if(click(393,321,527,361))
		{
			cleardevice();
			readimagefile("menus/savenull.jpg",0,0,800,600);
			delay(1500);
			sortare0();
		}
	}
	while(ok);
}

void sortare3()
{
	int ok;
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/s3.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(204,253,535,293)) sortare3a();
		if(click(204,313,535,353)) sortare3b();
		if(click(0,538,60,600)) sortare0(); if(click(740,538,800,600)) meniu();
	}			
	while(ok);
}

void sortare3a()
{
	int ok=0,i;
	char cuv2[51][20],inv2[20],cuv3[51][20];
	long cuv[51],inv;
	for(i=1; i<=n; i++)
	{
		cuv[i]=atol(s[i].sup);
		strcpy(cuv2[i],s[i].stat);
		
	}
	do
	{
		ok=0;
		for(i=1; i<n; i++) if(cuv[i]>cuv[i+1])
		{
			ok=1;
			inv=cuv[i];
			cuv[i]=cuv[i+1];
			cuv[i+1]=inv;
			strcpy(inv2,cuv2[i]);
			strcpy(cuv2[i],cuv2[i+1]);
			strcpy(cuv2[i+1],inv2);
		}
	}
	while(ok!=0);
	for(i=1; i<=n; i++) ltoa(cuv[i],cuv3[i],10);
	int j,l=0,kp=1;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/sshow3.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,71,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(400,72,400,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(205,93,"SUPRAFATA");
		outtextxy(545,93,"STAT");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(220,140+l*37,cuv3[i]);
		outtextxy(520,140+l*37,cuv2[i]);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) sortare3(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/sshow3.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/save.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(393,260,527,300)) 
		{
			fstream flux("outfiles/s_sup_09.html",ios::out);
			flux<<"<HTML><HEAD><TITLE>Suprafete</title></head>";
			flux<<"<body><center><font face='Papyrus' size='36'>Statele Unite ale Americii</font></center><br><hr>";
			flux<<"<br><br><center><h1>Sortare suprafete in ordine crescatoare</h1><br><table border=\"1\" bgcolor=\"GhostWhite\" width=\"44%\">";
			flux<<"<tr align=\"center\"><td bgcolor='lightgray'><b>Nr.crt</b><td bgcolor='lightgray'><b>Suprafata</b><td bgcolor='lightgray'><b>Stat</b>"<<endl;
			for(i=1; i<=n; i++) flux<<"<tr><td  align=\"center\">"<<i<<"<td><center>"<<cuv3[i]<<"</center><td><center>"<<cuv2[i]<<endl<<"</center>";
			flux<<"</table></center></body></html>"; 
			flux.close();
			cleardevice();
			readimagefile("menus/savefile.jpg",0,0,800,600);
			outtextxy(344,158,"s_sup_09.html");
			do{
				ok=1; 
				if(click(392,298,525,338)) {system("outfiles\\s_sup_09.html"); sortare0();}
				if(click(393,359,525,399)) sortare0();
			} 
			while(ok);
		}
		if(click(393,321,527,361))
		{
			cleardevice();
			readimagefile("menus/savenull.jpg",0,0,800,600);
			delay(1500);
			sortare0();
		}
	}
	while(ok);
}

void sortare3b()
{
	int ok=0,i;
	char cuv2[51][20],inv2[20],cuv3[51][20];
	long cuv[51],inv;
	for(i=1; i<=n; i++)
	{
		cuv[i]=atol(s[i].sup);
		strcpy(cuv2[i],s[i].stat);
		
	}
	do
	{
		ok=0;
		for(i=1; i<n; i++) if(cuv[i]<cuv[i+1])
		{
			ok=1;
			inv=cuv[i];
			cuv[i]=cuv[i+1];
			cuv[i+1]=inv;
			strcpy(inv2,cuv2[i]);
			strcpy(cuv2[i],cuv2[i+1]);
			strcpy(cuv2[i+1],inv2);
		}
	}
	while(ok!=0);
	for(i=1; i<=n; i++) ltoa(cuv[i],cuv3[i],10);
	int j,l=0,kp=1;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/sshow3.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,71,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(400,72,400,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(205,93,"SUPRAFATA");
		outtextxy(545,93,"STAT");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(220,140+l*37,cuv3[i]);
		outtextxy(520,140+l*37,cuv2[i]);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) sortare3(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/sshow3.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/save.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(393,260,527,300)) 
		{
			fstream flux("outfiles/s_sup_90.html",ios::out);
			flux<<"<HTML><HEAD><TITLE>Suprafete</title></head>";
			flux<<"<body><center><font face='Papyrus' size='36'>Statele Unite ale Americii</font></center><br><hr>";
			flux<<"<br><br><center><h1>Sortare suprafete in ordine descrescatoare</h1><br><table border=\"1\" bgcolor=\"GhostWhite\" width=\"44%\">";
			flux<<"<tr align=\"center\"><td bgcolor='lightgray'><b>Nr.crt</b><td bgcolor='lightgray'><b>Suprafata</b><td bgcolor='lightgray'><b>Stat</b>"<<endl;
			for(i=1; i<=n; i++) flux<<"<tr><td  align=\"center\">"<<i<<"<td><center>"<<cuv3[i]<<"</center><td><center>"<<cuv2[i]<<endl<<"</center>";
			flux<<"</table></center></body></html>"; 
			flux.close();
			cleardevice();
			readimagefile("menus/savefile.jpg",0,0,800,600);
			outtextxy(344,158,"s_sup_90.html");
			do{
				ok=1; 
				if(click(392,298,525,338)) {system("outfiles\\s_sup_90.html"); sortare0();}
				if(click(393,359,525,399)) sortare0();
			} 
			while(ok);
		}
		if(click(393,321,527,361))
		{
			cleardevice();
			readimagefile("menus/savenull.jpg",0,0,800,600);
			delay(1500);
			sortare0();
		}
	}
	while(ok);
}

void sortare4()
{
	int ok;
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/s4.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(204,253,535,293)) sortare4a();
		if(click(204,313,535,353)) sortare4b();
		if(click(0,538,60,600)) sortare0(); if(click(740,538,800,600)) meniu();
	}			
	while(ok);
}

void sortare4a()
{
	int ok=0,i;
	char cuv2[51][20],inv2[20],cuv3[51][20];
	long cuv[51],inv;
	for(i=1; i<=n; i++)
	{
		cuv[i]=atol(s[i].pop);
		strcpy(cuv2[i],s[i].stat);
		
	}
	do
	{
		ok=0;
		for(i=1; i<n; i++) if(cuv[i]>cuv[i+1])
		{
			ok=1;
			inv=cuv[i];
			cuv[i]=cuv[i+1];
			cuv[i+1]=inv;
			strcpy(inv2,cuv2[i]);
			strcpy(cuv2[i],cuv2[i+1]);
			strcpy(cuv2[i+1],inv2);
		}
	}
	while(ok!=0);
	for(i=1; i<=n; i++) ltoa(cuv[i],cuv3[i],10);
	int j,l=0,kp=1;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/sshow4.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,71,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(400,72,400,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(205,93,"POPULATIA");
		outtextxy(545,93,"STAT");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(215,140+l*37,cuv3[i]);
		outtextxy(520,140+l*37,cuv2[i]);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) sortare4(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/sshow4.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/save.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(393,260,527,300)) 
		{
			fstream flux("outfiles/s_pop_09.html",ios::out);
			flux<<"<HTML><HEAD><TITLE>Populatie</title></head>";
			flux<<"<body><center><font face='Papyrus' size='36'>Statele Unite ale Americii</font></center><br><hr>";
			flux<<"<br><br><center><h1>Sortare populatie in ordine crescatoare</h1><br><table border=\"1\" bgcolor=\"GhostWhite\" width=\"44%\">";
			flux<<"<tr align=\"center\"><td bgcolor='lightgray'><b>Nr.crt</b><td bgcolor='lightgray'><b>Populatia</b><td bgcolor='lightgray'><b>Stat</b>"<<endl;
			for(i=1; i<=n; i++) flux<<"<tr><td  align=\"center\">"<<i<<"<td><center>"<<cuv3[i]<<"</center><td><center>"<<cuv2[i]<<endl<<"</center>";
			flux<<"</table></center></body></html>"; 
			flux.close();
			cleardevice();
			readimagefile("menus/savefile.jpg",0,0,800,600);
			outtextxy(344,158,"s_pop_09.html");
			do{
				ok=1; 
				if(click(392,298,525,338)) {system("outfiles\\s_pop_09.html"); sortare0();}
				if(click(393,359,525,399)) sortare0();
			} 
			while(ok);
		}
		if(click(393,321,527,361))
		{
			cleardevice();
			readimagefile("menus/savenull.jpg",0,0,800,600);
			delay(1500);
			sortare0();
		}
	}
	while(ok);
}

void sortare4b()
{
	int ok=0,i;
	char cuv2[51][20],inv2[20],cuv3[51][20];
	long cuv[51],inv;
	for(i=1; i<=n; i++)
	{
		cuv[i]=atol(s[i].pop);
		strcpy(cuv2[i],s[i].stat);
		
	}
	do
	{
		ok=0;
		for(i=1; i<n; i++) if(cuv[i]<cuv[i+1])
		{
			ok=1;
			inv=cuv[i];
			cuv[i]=cuv[i+1];
			cuv[i+1]=inv;
			strcpy(inv2,cuv2[i]);
			strcpy(cuv2[i],cuv2[i+1]);
			strcpy(cuv2[i+1],inv2);
		}
	}
	while(ok!=0);
	for(i=1; i<=n; i++) ltoa(cuv[i],cuv3[i],10);
	int j,l=0,kp=1;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/sshow4.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,71,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(400,72,400,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(205,93,"POPULATIA");
		outtextxy(545,93,"STAT");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(215,140+l*37,cuv3[i]);
		outtextxy(520,140+l*37,cuv2[i]);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) sortare4(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/sshow4.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/save.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(393,260,527,300)) 
		{
			fstream flux("outfiles/s_pop_90.html",ios::out);
			flux<<"<HTML><HEAD><TITLE>Populatie</title></head>";
			flux<<"<body><center><font face='Papyrus' size='36'>Statele Unite ale Americii</font></center><br><hr>";
			flux<<"<br><br><center><h1>Sortare populatie in ordine descrescatoare</h1><br><table border=\"1\" bgcolor=\"GhostWhite\" width=\"44%\">";
			flux<<"<tr align=\"center\"><td bgcolor='lightgray'><b>Nr.crt</b><td bgcolor='lightgray'><b>Populatia</b><td bgcolor='lightgray'><b>Stat</b>"<<endl;
			for(i=1; i<=n; i++) flux<<"<tr><td  align=\"center\">"<<i<<"<td><center>"<<cuv3[i]<<"</center><td><center>"<<cuv2[i]<<endl<<"</center>";
			flux<<"</table></center></body></html>"; 
			flux.close();
			cleardevice();
			readimagefile("menus/savefile.jpg",0,0,800,600);
			outtextxy(344,158,"s_pop_90.html");
			do{
				ok=1; 
				if(click(392,298,525,338)) {system("outfiles\\s_pop_90.html"); sortare0();}
				if(click(393,359,525,399)) sortare0();
			} 
			while(ok);
		}
		if(click(393,321,527,361))
		{
			cleardevice();
			readimagefile("menus/savenull.jpg",0,0,800,600);
			delay(1500);
			sortare0();
		}
	}
	while(ok);
}

void sortare5()
{
	int ok;
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/s5.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(204,253,535,293)) sortare5a();
		if(click(204,313,535,353)) sortare5b();
		if(click(0,538,60,600)) sortare0(); if(click(740,538,800,600)) meniu();
	}			
	while(ok);
}

void sortare5a()
{
	int ok=0,i;
	char cuv[51][20],inv[20],cuv2[51][20],inv2[20];
	for(i=1; i<=n; i++) 
	{
		strcpy(cuv[i],s[i].abr);
		strcpy(cuv2[i],s[i].stat);
	}
	do
	{
		ok=0;
		for(i=1; i<n; i++) if(strcmp(cuv[i],cuv[i+1])>0)
		{
			ok=1;
			strcpy(inv,cuv[i]);
			strcpy(cuv[i],cuv[i+1]);
			strcpy(cuv[i+1],inv);
			strcpy(inv2,cuv2[i]);
			strcpy(cuv2[i],cuv2[i+1]);
			strcpy(cuv2[i+1],inv2);
		}
	}
	while(ok!=0);
	int j,l=0,kp=1;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/sshow5.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,71,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(400,72,400,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(205,93,"ABREVIERE");
		outtextxy(545,93,"STAT");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(240,140+l*37,cuv[i]);
		outtextxy(520,140+l*37,cuv2[i]);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) sortare5(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/sshow5.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/save.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(393,260,527,300)) 
		{
			fstream flux("outfiles/s_abr_az.html",ios::out);
			flux<<"<HTML><HEAD><TITLE>Abrevieri</title></head>";
			flux<<"<body><center><font face='Papyrus' size='36'>Statele Unite ale Americii</font></center><br><hr>";
			flux<<"<br><br><center><h1>Sortare abrevieri in ordine alfabetica</h1><br><table border=\"1\" bgcolor=\"GhostWhite\" width=\"44%\">";
			flux<<"<tr align=\"center\"><td bgcolor='lightgray'><b>Nr.crt</b><td bgcolor='lightgray'><b>Abreviere</b><td bgcolor='lightgray'><b>Stat</b>"<<endl;
			for(i=1; i<=n; i++) flux<<"<tr><td  align=\"center\">"<<i<<"<td><center>"<<cuv[i]<<"</center><td><center>"<<cuv2[i]<<endl<<"</center>";
			flux<<"</table></center></body></html>"; 
			flux.close();
			cleardevice();
			readimagefile("menus/savefile.jpg",0,0,800,600);
			outtextxy(344,158,"s_abr_az.html");
			do{
				ok=1; 
				if(click(392,298,525,338)) {system("outfiles\\s_abr_az.html"); sortare0();}
				if(click(393,359,525,399)) sortare0();
			} 
			while(ok);
		}
		if(click(393,321,527,361))
		{
			cleardevice();
			readimagefile("menus/savenull.jpg",0,0,800,600);
			delay(1500);
			sortare0();
		}
	}
	while(ok);
}

void sortare5b()
{
	int ok=0,i;
	char cuv[51][20],inv[20],cuv2[51][20],inv2[20];
	for(i=1; i<=n; i++) 
	{
		strcpy(cuv[i],s[i].abr);
		strcpy(cuv2[i],s[i].stat);
	}
	do
	{
		ok=0;
		for(i=1; i<n; i++) if(strcmp(cuv[i],cuv[i+1])<0)
		{
			ok=1;
			strcpy(inv,cuv[i]);
			strcpy(cuv[i],cuv[i+1]);
			strcpy(cuv[i+1],inv);
			strcpy(inv2,cuv2[i]);
			strcpy(cuv2[i],cuv2[i+1]);
			strcpy(cuv2[i+1],inv2);
		}
	}
	while(ok!=0);
	int j,l=0,kp=1;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/sshow5.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,71,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(400,72,400,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(205,93,"ABREVIERE");
		outtextxy(545,93,"STAT");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(240,140+l*37,cuv[i]);
		outtextxy(520,140+l*37,cuv2[i]);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) sortare5(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/sshow5.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/save.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(393,260,527,300)) 
		{
			fstream flux("outfiles/s_abr_za.html",ios::out);
			flux<<"<HTML><HEAD><TITLE>Abrevieri</title></head>";
			flux<<"<body><center><font face='Papyrus' size='36'>Statele Unite ale Americii</font></center><br><hr>";
			flux<<"<br><br><center><h1>Sortare abrevieri in ordine invers alfabetica</h1><br><table border=\"1\" bgcolor=\"GhostWhite\" width=\"44%\">";
			flux<<"<tr align=\"center\"><td bgcolor='lightgray'><b>Nr.crt</b><td bgcolor='lightgray'><b>Abreviere</b><td bgcolor='lightgray'><b>Stat</b>"<<endl;
			for(i=1; i<=n; i++) flux<<"<tr><td  align=\"center\">"<<i<<"<td><center>"<<cuv[i]<<"</center><td><center>"<<cuv2[i]<<endl<<"</center>";
			flux<<"</table></center></body></html>"; 
			flux.close();
			cleardevice();
			readimagefile("menus/savefile.jpg",0,0,800,600);
			outtextxy(344,158,"s_abr_za.html");
			do{
				ok=1; 
				if(click(392,298,525,338)) {system("outfiles\\s_abr_za.html"); sortare0();}
				if(click(393,359,525,399)) sortare0();
			} 
			while(ok);
		}
		if(click(393,321,527,361))
		{
			cleardevice();
			readimagefile("menus/savenull.jpg",0,0,800,600);
			delay(1500);
			sortare0();
		}
	}
	while(ok);
}

void sortare6()
{
	int ok;
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/s6.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(204,253,535,293)) sortare6a();
		if(click(204,313,535,353)) sortare6b();
		if(click(0,538,60,600)) sortare0(); if(click(740,538,800,600)) meniu();
	}			
	while(ok);
}

void sortare6a()
{
	int ok=0,i,cuv[51],inv;
	char cuv2[51][20],inv2[20],cuv3[51][20],cuv4[51][20],inv3[20];
	for(i=1; i<=n; i++)
	{
		cuv[i]=atoi(s[i].ht);
		strcpy(cuv2[i],s[i].high);
		strcpy(cuv4[i],s[i].stat);
		
	}
	do
	{
		ok=0;
		for(i=1; i<n; i++) if(cuv[i]>cuv[i+1])
		{
			ok=1;
			inv=cuv[i];
			cuv[i]=cuv[i+1];
			cuv[i+1]=inv;
			strcpy(inv2,cuv2[i]);
			strcpy(cuv2[i],cuv2[i+1]);
			strcpy(cuv2[i+1],inv2);
			strcpy(inv3,cuv4[i]);
			strcpy(cuv4[i],cuv4[i+1]);
			strcpy(cuv4[i+1],inv3);
		}
	}
	while(ok!=0);
	for(i=1; i<=n; i++) ltoa(cuv[i],cuv3[i],10);
	int j,l=0,kp=1;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/sshow6.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,73,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(260,72,260,500);
		line(520,72,520,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(145,93,"INALTIME");
		outtextxy(297,93,"PUNCTUL DE INALTIME");
		outtextxy(605,93,"STAT");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(160,140+l*37,cuv3[i]);
		outtextxy(275,140+l*37,cuv2[i]);
		outtextxy(555,140+l*37,cuv4[i]);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) sortare6(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/sshow6.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/save.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(393,260,527,300)) 
		{
			fstream flux("outfiles/s_inaltimi.html",ios::out);
			flux<<"<HTML><HEAD><TITLE>Inaltimi</title></head>";
			flux<<"<body><center><font face='Papyrus' size='36'>Statele Unite ale Americii</font></center><br><hr>";
			flux<<"<br><br><center><h1>Sortare puncte de inaltime</h1><br><table border=\"1\" bgcolor=\"GhostWhite\" width=\"44%\">";
			flux<<"<tr align=\"center\"><td bgcolor='lightgray'><b>Nr.crt</b><td bgcolor='lightgray'><b>Inaltime</b><td bgcolor='lightgray'><b>Punctul de inaltime</b><td bgcolor='lightgray'><b>Stat</b>"<<endl;
			for(i=1; i<=n; i++) flux<<"<tr><td  align=\"center\">"<<i<<"<td><center>"<<cuv3[i]<<"</center><td><center>"<<cuv2[i]<<endl<<"</center><td><center>"<<cuv4[i]<<"</center>";
			flux<<"</table></center></body></html>"; 
			flux.close();
			cleardevice();
			readimagefile("menus/savefile.jpg",0,0,800,600);
			outtextxy(344,158,"s_inaltimi.html");
			do{
				ok=1; 
				if(click(392,298,525,338)) {system("outfiles\\s_inaltimi.html"); sortare0();}
				if(click(393,359,525,399)) sortare0();
			} 
			while(ok);
		}
		if(click(393,321,527,361))
		{
			cleardevice();
			readimagefile("menus/savenull.jpg",0,0,800,600);
			delay(1500);
			sortare0();
		}
	}
	while(ok);
}

void sortare6b()
{
	int ok=0,i,cuv[51],inv;
	char cuv2[51][20],inv2[20],cuv3[51][20],cuv4[51][20],inv3[20];
	for(i=1; i<=n; i++)
	{
		cuv[i]=atoi(s[i].dp);
		strcpy(cuv2[i],s[i].low);
		strcpy(cuv4[i],s[i].stat);
		
	}
	do
	{
		ok=0;
		for(i=1; i<n; i++) if(cuv[i]>cuv[i+1])
		{
			ok=1;
			inv=cuv[i];
			cuv[i]=cuv[i+1];
			cuv[i+1]=inv;
			strcpy(inv2,cuv2[i]);
			strcpy(cuv2[i],cuv2[i+1]);
			strcpy(cuv2[i+1],inv2);
			strcpy(inv3,cuv4[i]);
			strcpy(cuv4[i],cuv4[i+1]);
			strcpy(cuv4[i+1],inv3);
		}
	}
	while(ok!=0);
	for(i=1; i<=n; i++) ltoa(cuv[i],cuv3[i],10);
	int j,l=0,kp=1;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/sshow6.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,73,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(260,72,260,500);
		line(520,72,520,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(140,93,"ADANCIME");
		outtextxy(295,93,"PUNCTUL DE ADANCIME");
		outtextxy(605,93,"STAT");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(165,140+l*37,cuv3[i]);
		outtextxy(320,140+l*37,cuv2[i]);
		outtextxy(555,140+l*37,cuv4[i]);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) sortare6(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/sshow6.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/save.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(393,260,527,300)) 
		{
			fstream flux("outfiles/s_adancimi.html",ios::out);
			flux<<"<HTML><HEAD><TITLE>Adancimi</title></head>";
			flux<<"<body><center><font face='Papyrus' size='36'>Statele Unite ale Americii</font></center><br><hr>";
			flux<<"<br><br><center><h1>Sortare puncte de adancime</h1><br><table border=\"1\" bgcolor=\"GhostWhite\" width=\"44%\">";
			flux<<"<tr align=\"center\"><td bgcolor='lightgray'><b>Nr.crt</b><td bgcolor='lightgray'><b>Adancime</b><td bgcolor='lightgray'><b>Punctul de adancime</b><td bgcolor='lightgray'><b>Stat</b>"<<endl;
			for(i=1; i<=n; i++) flux<<"<tr><td  align=\"center\">"<<i<<"<td><center>"<<cuv3[i]<<"</center><td><center>"<<cuv2[i]<<endl<<"</center><td><center>"<<cuv4[i]<<"</center>";
			flux<<"</table></center></body></html>"; 
			flux.close();
			cleardevice();
			readimagefile("menus/savefile.jpg",0,0,800,600);
			outtextxy(344,158,"s_adancimi.html");
			do{
				ok=1; 
				if(click(392,298,525,338)) {system("outfiles\\s_adancimi.html"); sortare0();}
				if(click(393,359,525,399)) sortare0();
			} 
			while(ok);
		}
		if(click(393,321,527,361))
		{
			cleardevice();
			readimagefile("menus/savenull.jpg",0,0,800,600);
			delay(1500);
			sortare0();
		}
	}
	while(ok);
}

void sortare7()
{
	int ok;
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/s7.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(204,253,535,293)) sortare7a();
		if(click(204,313,535,353)) sortare7b();
		if(click(0,538,60,600)) sortare0(); if(click(740,538,800,600)) meniu();
	}			
	while(ok);
}

void sortare7a()
{
	int ok=0,i,cuv[51],inv;
	char cuv2[51][20],inv2[20],cuv3[51][20];
	for(i=1; i<=n; i++)
	{
		cuv[i]=atoi(s[i].dens);
		strcpy(cuv2[i],s[i].stat);
		
	}
	do
	{
		ok=0;
		for(i=1; i<n; i++) if(cuv[i]>cuv[i+1])
		{
			ok=1;
			inv=cuv[i];
			cuv[i]=cuv[i+1];
			cuv[i+1]=inv;
			strcpy(inv2,cuv2[i]);
			strcpy(cuv2[i],cuv2[i+1]);
			strcpy(cuv2[i+1],inv2);
		}
	}
	while(ok!=0);
	for(i=1; i<=n; i++) ltoa(cuv[i],cuv3[i],10);
	int j,l=0,kp=1;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/sshow7.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,71,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(400,72,400,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(155,93,"DENSITATEA POPULATIEI");
		outtextxy(545,93,"STAT");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(240,140+l*37,cuv3[i]);
		outtextxy(520,140+l*37,cuv2[i]);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) sortare7(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/sshow7.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/save.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(393,260,527,300)) 
		{
			fstream flux("outfiles/s_dens_09.html",ios::out);
			flux<<"<HTML><HEAD><TITLE>Densitati</title></head>";
			flux<<"<body><center><font face='Papyrus' size='36'>Statele Unite ale Americii</font></center><br><hr>";
			flux<<"<br><br><center><h1>Sortare densitatea populatiei in ordine crescatoare</h1><br><table border=\"1\" bgcolor=\"GhostWhite\" width=\"44%\">";
			flux<<"<tr align=\"center\"><td bgcolor='lightgray'><b>Nr.crt</b><td bgcolor='lightgray'><b>Densitate</b><td bgcolor='lightgray'><b>Stat</b>"<<endl;
			for(i=1; i<=n; i++) flux<<"<tr><td  align=\"center\">"<<i<<"<td><center>"<<cuv3[i]<<"</center><td><center>"<<cuv2[i]<<endl<<"</center>";
			flux<<"</table></center></body></html>"; 
			flux.close();
			cleardevice();
			readimagefile("menus/savefile.jpg",0,0,800,600);
			outtextxy(344,158,"s_dens_09.html");
			do{
				ok=1; 
				if(click(392,298,525,338)) {system("outfiles\\s_dens_09.html"); sortare0();}
				if(click(393,359,525,399)) sortare0();
			} 
			while(ok);
		}
		if(click(393,321,527,361))
		{
			cleardevice();
			readimagefile("menus/savenull.jpg",0,0,800,600);
			delay(1500);
			sortare0();
		}
	}
	while(ok);
}

void sortare7b()
{
	int ok=0,i,cuv[51],inv;
	char cuv2[51][20],inv2[20],cuv3[51][20];
	for(i=1; i<=n; i++)
	{
		cuv[i]=atoi(s[i].dens);
		strcpy(cuv2[i],s[i].stat);
		
	}
	do
	{
		ok=0;
		for(i=1; i<n; i++) if(cuv[i]<cuv[i+1])
		{
			ok=1;
			inv=cuv[i];
			cuv[i]=cuv[i+1];
			cuv[i+1]=inv;
			strcpy(inv2,cuv2[i]);
			strcpy(cuv2[i],cuv2[i+1]);
			strcpy(cuv2[i+1],inv2);
		}
	}
	while(ok!=0);
	for(i=1; i<=n; i++) ltoa(cuv[i],cuv3[i],10);
	int j,l=0,kp=1;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/sshow7.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,71,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(400,72,400,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(155,93,"DENSITATEA POPULATIEI");
		outtextxy(545,93,"STAT");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(240,140+l*37,cuv3[i]);
		outtextxy(520,140+l*37,cuv2[i]);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) sortare7(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/sshow7.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/save.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(393,260,527,300)) 
		{
			fstream flux("outfiles/s_dens_90.html",ios::out);
			flux<<"<HTML><HEAD><TITLE>Densitati</title></head>";
			flux<<"<body><center><font face='Papyrus' size='36'>Statele Unite ale Americii</font></center><br><hr>";
			flux<<"<br><br><center><h1>Sortare densitatea populatiei in ordine descrescatoare</h1><br><table border=\"1\" bgcolor=\"GhostWhite\" width=\"44%\">";
			flux<<"<tr align=\"center\"><td bgcolor='lightgray'><b>Nr.crt</b><td bgcolor='lightgray'><b>Densitate</b><td bgcolor='lightgray'><b>Stat</b>"<<endl;
			for(i=1; i<=n; i++) flux<<"<tr><td  align=\"center\">"<<i<<"<td><center>"<<cuv3[i]<<"</center><td><center>"<<cuv2[i]<<endl<<"</center>";
			flux<<"</table></center></body></html>"; 
			flux.close();
			cleardevice();
			readimagefile("menus/savefile.jpg",0,0,800,600);
			outtextxy(344,158,"s_dens_90.html");
			do{
				ok=1; 
				if(click(392,298,525,338)) {system("outfiles\\s_dens_90.html"); sortare0();}
				if(click(393,359,525,399)) sortare0();
			} 
			while(ok);
		}
		if(click(393,321,527,361))
		{
			cleardevice();
			readimagefile("menus/savenull.jpg",0,0,800,600);
			delay(1500);
			sortare0();
		}
	}
	while(ok);
}

void sortare8()
{
	int ok;
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/s7.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(204,253,535,293)) sortare8a();
		if(click(204,313,535,353)) sortare8b();
		if(click(0,538,60,600)) sortare0(); if(click(740,538,800,600)) meniu();
	}			
	while(ok);
}

void sortare8a()
{
	int ok=0,i;
	float cuv[51],inv;
	char cuv2[51][20],inv2[20],cuv3[51][20];
	for(i=1; i<=n; i++)
	{
		cuv[i]=atof(s[i].temp);
		strcpy(cuv2[i],s[i].stat);
		
	}
	do
	{
		ok=0;
		for(i=1; i<n; i++) if(cuv[i]>cuv[i+1])
		{
			ok=1;
			inv=cuv[i];
			cuv[i]=cuv[i+1];
			cuv[i+1]=inv;
			strcpy(inv2,cuv2[i]);
			strcpy(cuv2[i],cuv2[i+1]);
			strcpy(cuv2[i+1],inv2);
		}
	}
	while(ok!=0);
	for(i=1; i<=n; i++) sprintf(cuv3[i],"%.4g",cuv[i]);
	int j,l=0,kp=1;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/sshow8.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,71,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(400,72,400,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(190,93,"TEMPERATURA");
		outtextxy(545,93,"STAT");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(240,140+l*37,cuv3[i]);
		outtextxy(520,140+l*37,cuv2[i]);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) sortare8(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/sshow8.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/save.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(393,260,527,300)) 
		{
			fstream flux("outfiles/s_temp_09.html",ios::out);
			flux<<"<HTML><HEAD><TITLE>Temperaturi</title></head>";
			flux<<"<body><center><font face='Papyrus' size='36'>Statele Unite ale Americii</font></center><br><hr>";
			flux<<"<br><br><center><h1>Sortare temperaturi medii anuale in ordine crescatoare</h1><br><table border=\"1\" bgcolor=\"GhostWhite\" width=\"44%\">";
			flux<<"<tr align=\"center\"><td bgcolor='lightgray'><b>Nr.crt</b><td bgcolor='lightgray'><b>Temperatura</b><td bgcolor='lightgray'><b>Stat</b>"<<endl;
			for(i=1; i<=n; i++) flux<<"<tr><td  align=\"center\">"<<i<<"<td><center>"<<cuv3[i]<<"</center><td><center>"<<cuv2[i]<<endl<<"</center>";
			flux<<"</table></center></body></html>"; 
			flux.close();
			cleardevice();
			readimagefile("menus/savefile.jpg",0,0,800,600);
			outtextxy(344,158,"s_temp_09.html");
			do{
				ok=1; 
				if(click(392,298,525,338)) {system("outfiles\\s_temp_09.html"); sortare0();}
				if(click(393,359,525,399)) sortare0();
			} 
			while(ok);
		}
		if(click(393,321,527,361))
		{
			cleardevice();
			readimagefile("menus/savenull.jpg",0,0,800,600);
			delay(1500);
			sortare0();
		}
	}
	while(ok);
}

void sortare8b()
{
	int ok=0,i;
	float cuv[51],inv;
	char cuv2[51][20],inv2[20],cuv3[51][20];
	for(i=1; i<=n; i++)
	{
		cuv[i]=atof(s[i].temp);
		strcpy(cuv2[i],s[i].stat);
		
	}
	do
	{
		ok=0;
		for(i=1; i<n; i++) if(cuv[i]<cuv[i+1])
		{
			ok=1;
			inv=cuv[i];
			cuv[i]=cuv[i+1];
			cuv[i+1]=inv;
			strcpy(inv2,cuv2[i]);
			strcpy(cuv2[i],cuv2[i+1]);
			strcpy(cuv2[i+1],inv2);
		}
	}
	while(ok!=0);
	for(i=1; i<=n; i++) sprintf(cuv3[i],"%.4g",cuv[i]);
	int j,l=0,kp=1;
	char siri[5],sirk[5];
    cleardevice();
    settextstyle(3,0,1);
	setcolor(0);
	readimagefile("menus/sshow8.jpg",0,0,800,600);
	setfillstyle(1,8);
	bar(61,71,740,130);
	setfillstyle(1,7);
	bar(61,131,740,500);
    for(i=1; i<=n; i++)
    {
		//table draw
		rectangle(60,72,740,500);
		for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
		line(110,72,110,500);
		line(400,72,400,500);
		setbkcolor(8);
		outtextxy(75,80,"NR.");
		outtextxy(70,100,"CRT");
		outtextxy(190,93,"TEMPERATURA");
		outtextxy(545,93,"STAT");
		//convertings
		itoa(kp,sirk,10);
		itoa(i,siri,10);
		//database print
		setbkcolor(7);
		outtextxy(75,140+l*37,siri);
		outtextxy(240,140+l*37,cuv3[i]);
		outtextxy(520,140+l*37,cuv2[i]);
		rectangle(60,500,740,530);
		bar(61,501,740,530);
		outtextxy(355,505,"Pagina     / 5");
		outtextxy(412,505,sirk);
		l++;
		if(i%10==0)
		{
			do{ok=0; if(click(0,538,60,600)) sortare8(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok=1;} while(ok==0);
			cleardevice();
			readimagefile("menus/sshow8.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,71,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			l=0;
			kp++;
		}
    }
	cleardevice();
	setcolor(0);
	settextstyle(6,0,3);
	setlinestyle(0,0,0);
	setbkcolor(15);
	readimagefile("menus/save.jpg",0,0,800,600);
	do
	{ 
		ok=1;
		if(click(393,260,527,300)) 
		{
			fstream flux("outfiles/s_temp_90.html",ios::out);
			flux<<"<HTML><HEAD><TITLE>Temperaturi</title></head>";
			flux<<"<body><center><font face='Papyrus' size='36'>Statele Unite ale Americii</font></center><br><hr>";
			flux<<"<br><br><center><h1>Sortare temperaturi medii anuale in ordine descrescatoare</h1><br><table border=\"1\" bgcolor=\"GhostWhite\" width=\"44%\">";
			flux<<"<tr align=\"center\"><td bgcolor='lightgray'><b>Nr.crt</b><td bgcolor='lightgray'><b>Temperatura</b><td bgcolor='lightgray'><b>Stat</b>"<<endl;
			for(i=1; i<=n; i++) flux<<"<tr><td  align=\"center\">"<<i<<"<td><center>"<<cuv3[i]<<"</center><td><center>"<<cuv2[i]<<endl<<"</center>";
			flux<<"</table></center></body></html>"; 
			flux.close();
			cleardevice();
			readimagefile("menus/savefile.jpg",0,0,800,600);
			outtextxy(344,158,"s_temp_90.html");
			do{
				ok=1; 
				if(click(392,298,525,338)) {system("outfiles\\s_temp_90.html"); sortare0();}
				if(click(393,359,525,399)) sortare0();
			} 
			while(ok);
		}
		if(click(393,321,527,361))
		{
			cleardevice();
			readimagefile("menus/savenull.jpg",0,0,800,600);
			delay(1500);
			sortare0();
		}
	}
	while(ok);
}

void cautare1()
{
	int k=0,poz,i,ok=0,ok2;
	char lit,caut[20];
	cleardevice();
	readimagefile("menus/search1.jpg",0,0,800,600);
	do
	{ 
		ok2=1;
		if(click(0,538,60,600)) cautare0(); if(click(740,538,800,600)) meniu(); if(click(388,488,546,505))
		{
			setfillstyle(1,15);
			bar(387,485,800,507);
			do
			{
				start:
				lit=getch();
				if(lit!=char(8))
				{
					caut[k]=lit; caut[k+1]=NULL;
					outtextxy(387,485,caut);
					k++;
				}
				if(lit==char(8)) if(k==0) goto start;
				if(lit==char(8))
				{
					caut[k]=lit; caut[k+1]=NULL;
					caut[k-1]=NULL;
					k--;
					setfillstyle(1,15);
					bar(387,485,800,507);
					outtextxy(387,485,caut);
					goto start;
				}
			}
			while(lit!=char(13));
			caut[k-1]=NULL;
			caut[0]=toupper(caut[0]);
			for(i=1; i<=n; i++) if(strstr(s[i].stat,caut))
			{
				ok=1;
				poz=i;
			}
			if(ok==1)
			{
				char poza1[20],poza2[20],poza3[20],ii[5],file1[10],file2[10],file3[5];
				strcpy(file1,"flag/usf");
				strcpy(file2,"emblem/use");
				strcpy(file3,"statemaps/");
				cleardevice();
				readimagefile("menus/show0.jpg",0,0,800,600);
				delay(100);
				setcolor(0);
				settextstyle(6,0,1);
				itoa(poz,ii,10);
				strcpy(poza1,file1);
				strcat(poza1,ii);
				strcat(poza1,".jpg");
				strcpy(poza2,file2);
				strcat(poza2,ii);
				strcat(poza2,".jpg");
				strcpy(poza3,file3);
				strcat(poza3,ii);
				strcat(poza3,".jpg");
				settextstyle(6,0,3);
				line(126,99,459,99);
				line(117,102,467,102);
				line(195,103,195,560);
				line(198,103,198,560);
				outtextxy(200,70,s[poz].stat);
				rectangle(9,149,181,281);
				readimagefile(poza1,10,150,180,280);
				settextstyle(6,0,1);
				rectangle(63,299,122,319);
				outtextxy(65,300,"Steag");
				rectangle(9,339,181,491);
				readimagefile(poza2,10,340,180,490);
				rectangle(53,509,134,529);
				outtextxy(55,510,"Insigna");
				rectangle(575,155,799,330);
				rectangle(579,159,796,301);
				readimagefile(poza3,580,160,795,300);
				outtextxy(655,305,"Harta");
				settextstyle(3,0,2);
				outtextxy(210,110,"Capitala:");
				settextstyle(3,0,1);
				outtextxy(290,113,s[poz].cap);
				settextstyle(3,0,2);
				outtextxy(210,138,"Suprafata:");
				settextstyle(3,0,1);
				outtextxy(300,141,s[poz].sup);
				outtextxy(370,141,"km2");
				settextstyle(3,0,2);
				outtextxy(210,166,"Populatie:");
				settextstyle(3,0,1);
				outtextxy(300,169,s[poz].pop);
				outtextxy(380,169,"loc.");
				settextstyle(3,0,2);
				outtextxy(210,194,"Guvernator:");
				settextstyle(3,0,1);
				outtextxy(315,197,s[poz].guv);
				settextstyle(3,0,2);
				outtextxy(210,222,"Cel mai mare oras:");
				settextstyle(3,0,1);
				outtextxy(373,225,s[poz].oras1);
				settextstyle(3,0,2);
				outtextxy(210,250,"Al doilea oras:");
				settextstyle(3,0,1);
				outtextxy(335,253,s[poz].oras2);
				settextstyle(3,0,2);
				outtextxy(210,278,"Cel mai inalt loc:");
				settextstyle(3,0,1);
				outtextxy(350,281,s[poz].ht);
				outtextxy(390,281,"m -");
				outtextxy(410,281,s[poz].high);
				settextstyle(3,0,2);
				outtextxy(210,306,"Cel mai jos loc:");
				settextstyle(3,0,1);
				outtextxy(345,309,s[poz].dp);
				outtextxy(385,309,"m -");
				outtextxy(410,309,s[poz].low);
				settextstyle(3,0,2);
				outtextxy(210,334,"Nume Initial:");
				settextstyle(3,0,1);
				outtextxy(320,337,s[poz].nume);
				settextstyle(3,0,2);
				outtextxy(210,362,"Data Aderarii la Federatie:");
				settextstyle(3,0,1);
				outtextxy(430,365,s[poz].data);
				settextstyle(3,0,2);
				outtextxy(210,390,"Porecla (Nickname):");
				settextstyle(3,0,1);
				outtextxy(385,393,s[poz].nick);
				settextstyle(3,0,2);
				outtextxy(210,418,"Motto:");
				settextstyle(3,0,1);
				outtextxy(265,421,s[poz].motto);
				settextstyle(3,0,2);
				outtextxy(210,446,"Abreviere:");
				settextstyle(3,0,1);
				outtextxy(303,449,s[poz].abr);
				settextstyle(3,0,2);
				outtextxy(210,474,"Densitate:");
				settextstyle(3,0,1);
				outtextxy(300,477,s[poz].dens);
				outtextxy(330,477,"loc./k");
				settextstyle(3,0,2);
				outtextxy(210,502,"Fus Orar:");
				settextstyle(3,0,1);
				outtextxy(295,505,"GMT");
				outtextxy(335,505,s[poz].fus);
				settextstyle(3,0,2);
				outtextxy(210,530,"Politica:");
				settextstyle(3,0,1);
				outtextxy(280,533,s[poz].pol);
				settextstyle(3,0,2);
				outtextxy(572,362,"Temperatura medie anuala");
				rectangle(570,360,800,414);
				rectangle(568,358,800,416);
				line(570,387,800,387);
				settextstyle(6,0,2);
				outtextxy(635,392,s[poz].temp);
				settextstyle(1,0,1);
				outtextxy(690,389,"o");
				settextstyle(6,0,2);
				outtextxy(705,392,"C");
				do{ok=1; if(click(0,538,60,600)) cautare1(); if(click(740,538,800,600)) meniu(); } while(ok);
			}
			if(ok==0)
			{
				outtextxy(230,525,"Stat inexistent!");
				delay(1000);
				cautare1();
			}
		}
	}			
	while(ok2);
}

void cautare2()
{
	int k=0,poz,i,ok=0,ok2;
	char lit,caut[20];
	cleardevice();
	readimagefile("menus/search2.jpg",0,0,800,600);
	do
	{ 
		ok2=1;
		if(click(0,538,60,600)) cautare0(); if(click(740,538,800,600)) meniu(); if(click(388,488,546,505))
		{
			setfillstyle(1,15);
			bar(423,485,800,507);
			do
			{
				start:
				lit=getch();
				if(lit!=char(8))
				{
					caut[k]=lit; caut[k+1]=NULL;
					outtextxy(423,485,caut);
					k++;
				}
				if(lit==char(8)) if(k==0) goto start;
				if(lit==char(8))
				{
					caut[k]=lit; caut[k+1]=NULL;
					caut[k-1]=NULL;
					k--;
					setfillstyle(1,15);
					bar(423,485,800,507);
					outtextxy(423,485,caut);
					goto start;
				}
			}
			while(lit!=char(13));
			caut[k-1]=NULL;
			caut[0]=toupper(caut[0]);
			for(i=1; i<=n; i++) if(strstr(s[i].cap,caut))
			{
				ok=1;
				poz=i;
			}
			if(ok==1)
			{
				char poza1[20],poza2[20],poza3[20],ii[5],file1[10],file2[10],file3[5];
				strcpy(file1,"flag/usf");
				strcpy(file2,"emblem/use");
				strcpy(file3,"statemaps/");
				cleardevice();
				readimagefile("menus/seshow2.jpg",0,0,800,600);
				delay(100);
				setcolor(0);
				settextstyle(6,0,1);
				itoa(poz,ii,10);
				strcpy(poza1,file1);
				strcat(poza1,ii);
				strcat(poza1,".jpg");
				strcpy(poza2,file2);
				strcat(poza2,ii);
				strcat(poza2,".jpg");
				strcpy(poza3,file3);
				strcat(poza3,ii);
				strcat(poza3,".jpg");
				settextstyle(6,0,3);
				line(126,99,459,99);
				line(117,102,467,102);
				line(195,103,195,560);
				line(198,103,198,560);
				outtextxy(200,70,s[poz].cap);
				rectangle(9,149,181,281);
				readimagefile(poza1,10,150,180,280);
				settextstyle(6,0,1);
				rectangle(63,299,122,319);
				outtextxy(65,300,"Steag");
				rectangle(9,339,181,491);
				readimagefile(poza2,10,340,180,490);
				rectangle(53,509,134,529);
				outtextxy(55,510,"Insigna");
				settextstyle(6,0,3);
				outtextxy(430,192,s[poz].stat);
				settextstyle(6,0,2);
				outtextxy(375,258,s[poz].guv);
				outtextxy(370,356,s[poz].oras1);
				outtextxy(370,388,s[poz].oras2);
				do{ok=1; if(click(0,538,60,600)) cautare2(); if(click(740,538,800,600)) meniu(); } while(ok);
			}
			if(ok==0)
			{
				outtextxy(230,525,"Capitala inexistenta!");
				delay(1000);
				cautare2();
			}
		}
	}			
	while(ok2);
}

void cautare3()
{
	int k=0,poz,i,ok=0,ok2;
	char lit,caut[20];
	cleardevice();
	readimagefile("menus/search3.jpg",0,0,800,600);
	do
	{ 
		ok2=1;
		if(click(0,538,60,600)) cautare0(); if(click(740,538,800,600)) meniu(); if(click(388,488,546,505))
		{
			setfillstyle(1,15);
			bar(450,485,800,507);
			do
			{
				start:
				lit=getch();
				if(lit!=char(8))
				{
					caut[k]=lit; caut[k+1]=NULL;
					outtextxy(460,485,caut);
					k++;
				}
				if(lit==char(8)) if(k==0) goto start;
				if(lit==char(8))
				{
					caut[k]=lit; caut[k+1]=NULL;
					caut[k-1]=NULL;
					k--;
					setfillstyle(1,15);
					bar(450,485,800,507);
					outtextxy(460,485,caut);
					goto start;
				}
			}
			while(lit!=char(13));
			caut[k-1]=NULL;
			caut[0]=toupper(caut[0]);
			caut[1]=toupper(caut[1]);
			for(i=1; i<=n; i++) if(strcmp(caut,s[i].abr)==0)
			{
				ok=1;
				poz=i;
			}
			if(ok==1)
			{
				char poza1[20],poza2[20],poza3[20],ii[5],file1[10],file2[10],file3[5];
				strcpy(file1,"flag/usf");
				strcpy(file2,"emblem/use");
				strcpy(file3,"statemaps/");
				cleardevice();
				readimagefile("menus/seshow3.jpg",0,0,800,600);
				delay(100);
				setcolor(0);
				settextstyle(6,0,1);
				itoa(poz,ii,10);
				strcpy(poza1,file1);
				strcat(poza1,ii);
				strcat(poza1,".jpg");
				strcpy(poza2,file2);
				strcat(poza2,ii);
				strcat(poza2,".jpg");
				strcpy(poza3,file3);
				strcat(poza3,ii);
				strcat(poza3,".jpg");
				settextstyle(6,0,3);
				line(126,99,459,99);
				line(117,102,467,102);
				line(195,103,195,560);
				line(198,103,198,560);
				outtextxy(232,70,s[poz].abr);
				rectangle(9,149,181,281);
				readimagefile(poza1,10,150,180,280);
				settextstyle(6,0,1);
				rectangle(63,299,122,319);
				outtextxy(65,300,"Steag");
				rectangle(9,339,181,491);
				readimagefile(poza2,10,340,180,490);
				rectangle(53,509,134,529);
				outtextxy(55,510,"Insigna");
				settextstyle(6,0,3);
				outtextxy(431,174,s[poz].stat);
				settextstyle(6,0,2);
				outtextxy(338,240,s[poz].cap);
				outtextxy(346,337,s[poz].sup);
				outtextxy(455,337,"km2");
				outtextxy(345,400,s[poz].pop);
				outtextxy(475,400,"loc.");
				outtextxy(369,464,s[poz].guv);
				do{ok=1; if(click(0,538,60,600)) cautare3(); if(click(740,538,800,600)) meniu(); } while(ok);
			}
			if(ok==0)
			{
				outtextxy(230,525,"Abreviere inexistenta!");
				delay(1000);
				cautare3();
			}
		}
	}
	while(ok2);
}

void cautare4(char caut[20])
{
	int k=0,i,j,l=0,poz,ok=0,p[51],a=0,ok2,ok3;
	char lit,siri[5];
	do
	{ 
		ok2=1;
		if(click(0,538,60,600)) cautare0(); if(click(740,538,800,600)) meniu(); if(click(440,350,600,370))
		{
			setfillstyle(1,15);
			bar(440,350,800,370);
			do
			{
				start:
				lit=getch();
				if(lit!=char(8))
				{
					caut[k]=lit; caut[k+1]=NULL;
					outtextxy(445,350,caut);
					k++;
				}
				if(lit==char(8)) if(k==0) goto start;
				if(lit==char(8))
				{
					caut[k]=lit; caut[k+1]=NULL;
					caut[k-1]=NULL;
					k--;
					setfillstyle(1,15);
					bar(440,350,800,370);
					outtextxy(445,350,caut);
					goto start;
				}
			}
			while(lit!=char(13));
			caut[k-1]=NULL;
			cleardevice();
			settextstyle(3,0,1);
			setcolor(0);
			readimagefile("menus/seshow4.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,73,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			for(i=1; i<=n; i++) if(strcmp(caut,s[i].fus)==0)
			{
				ok=1;
				a++;
				poz=i;
				p[a]=poz;
			}
			if(ok==1)
			{
				for(i=1; i<=a; i++)
				{
					//table draw
					rectangle(60,72,740,500);
					for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
					line(110,72,110,500);
					line(260,72,260,500);
					line(480,72,480,500);
					setbkcolor(8);
					outtextxy(75,80,"NR.");
					outtextxy(70,100,"CRT");
					outtextxy(140,93,"NUME STAT");
					outtextxy(340,93,"CAPITALA");
					outtextxy(565,93,"FUS ORAR");
					//convertings
					itoa(i,siri,10);
					//database print
					setbkcolor(7);
					outtextxy(75,140+l*37,siri);
					outtextxy(127,140+l*37,s[p[i]].stat);
					outtextxy(300,140+l*37,s[p[i]].cap);
					outtextxy(600,140+l*37,s[p[i]].fus);
					l++;
					if(i%10==0) if(i<a)
					{
						do{ok3=0; if(click(0,538,60,600)) cautare0(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok3=1;} while(ok3==0);
						cleardevice();
						readimagefile("menus/seshow4.jpg",0,0,800,600);
						setfillstyle(1,8);
						bar(61,71,740,130);
						setfillstyle(1,7);
						bar(61,131,740,500);
						l=0;
					}
				}
				do{ok3=0; if(click(0,538,60,600)) cautare0(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok3=1;} while(ok3==0);
				cleardevice();
				readimagefile("menus/info.jpg",0,0,800,600);
				delay(1000);
				cautare0();
			}
			if(ok==0)
			{
				cleardevice();
				readimagefile("menus/seshow4i.jpg",0,0,800,600);
				delay(2000);
				cautare0();	
			}
		}
	}
	while(ok2);
}

void cautare5(char caut1[20], char caut2[20])
{
	int k=0,i,j,l=0,poz,ok=0,p[51],a=0,ok2,ok3,k2=0;
	float t[51],c1,c2;
	for(i=1; i<=n; i++) t[i]=atof(s[i].temp);
	char lit,siri[5];
	do
	{ 
		ok2=1;
		if(click(0,538,60,600)) cautare0(); if(click(740,538,800,600)) meniu(); if(click(428,254,491,277))
		{
			e1:
			setfillstyle(1,15);
			bar(428,254,491,280);
			do
			{
				start:
				lit=getch();
				if(lit!=char(8))
				{
					caut1[k]=lit; caut1[k+1]=NULL;
					outtextxy(440,256,caut1);
					k++;
				}
				if(lit==char(8)) if(k==0) goto start;
				if(lit==char(8))
				{
					caut1[k]=lit; caut1[k+1]=NULL;
					caut1[k-1]=NULL;
					k--;
					setfillstyle(1,15);
					bar(428,254,491,280);
					outtextxy(440,256,caut1);
					goto start;
				}
			}
			while(lit!=char(13));
			caut1[k-1]=NULL;
			if(k2==0) goto e2;
		}
		if(click(428,307,491,330))
		{
			e2:
			setfillstyle(1,15);
			bar(428,307,491,333);
			do
			{
				start2:
				lit=getch();
				if(lit!=char(8))
				{
					caut2[k2]=lit; caut2[k2+1]=NULL;
					outtextxy(440,308,caut2);
					k2++;
				}
				if(lit==char(8)) if(k2==0) goto start;
				if(lit==char(8))
				{
					caut2[k2]=lit; caut2[k2+1]=NULL;
					caut2[k2-1]=NULL;
					k2--;
					setfillstyle(1,15);
					bar(428,307,491,333);
					outtextxy(440,308,caut2);
					goto start2;
				}
			}
			while(lit!=char(13));
			caut2[k2-1]=NULL;
			if(k==0) goto e1;
		}
			if(k!=0 && k2!=0){
			cleardevice();
			settextstyle(3,0,1);
			setcolor(0);
			readimagefile("menus/seshow5.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,73,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			c1=atof(caut1); c2=atof(caut2);
			for(i=1; i<=n; i++) if(t[i]>=c1 && t[i]<=c2)
			{
				ok=1;
				a++;
				poz=i;
				p[a]=poz;
			}
			if(ok==1)
			{
				for(i=1; i<=a; i++)
				{
					//table draw
					rectangle(60,72,740,500);
					for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
					line(110,72,110,500);
					line(260,72,260,500);
					line(480,72,480,500);
					setbkcolor(8);
					outtextxy(75,80,"NR.");
					outtextxy(70,100,"CRT");
					outtextxy(140,93,"NUME STAT");
					outtextxy(340,93,"CAPITALA");
					outtextxy(545,93,"TEMPERATURA");
					//convertings
					itoa(i,siri,10);
					//database print
					setbkcolor(7);
					outtextxy(75,140+l*37,siri);
					outtextxy(127,140+l*37,s[p[i]].stat);
					outtextxy(300,140+l*37,s[p[i]].cap);
					outtextxy(595,140+l*37,s[p[i]].temp);
					l++;
					if(i%10==0) if(i<a)
					{
						do{ok3=0; if(click(0,538,60,600)) cautare0(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok3=1;} while(ok3==0);
						cleardevice();
						readimagefile("menus/seshow5.jpg",0,0,800,600);
						setfillstyle(1,8);
						bar(61,71,740,130);
						setfillstyle(1,7);
						bar(61,131,740,500);
						l=0;
					}
				}
				do{ok3=0; if(click(0,538,60,600)) cautare0(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok3=1;} while(ok3==0);
				cleardevice();
				readimagefile("menus/info.jpg",0,0,800,600);
				delay(1000);
				cautare0();
			}
			if(ok==0)
			{
				cleardevice();
				readimagefile("menus/seshow5i.jpg",0,0,800,600);
				delay(2000);
				cautare0();	
			}
		}
	}
	while(ok2);
}

void cautare6(char caut[20])
{
	int k=0,i,j,l=0,poz,ok=0,p[51],a=0,ok2,ok3;
	char lit,siri[5];
	do
	{ 
		ok2=1;
		if(click(0,538,60,600)) cautare0(); if(click(740,538,800,600)) meniu(); if(click(415,366,585,386))
		{
			setfillstyle(1,15);
			bar(415,366,800,386);
			do
			{
				start:
				lit=getch();
				if(lit!=char(8))
				{
					caut[k]=lit; caut[k+1]=NULL;
					outtextxy(424,366,caut);
					k++;
				}
				if(lit==char(8)) if(k==0) goto start;
				if(lit==char(8))
				{
					caut[k]=lit; caut[k+1]=NULL;
					caut[k-1]=NULL;
					k--;
					setfillstyle(1,15);
					bar(415,366,800,386);
					outtextxy(424,366,caut);
					goto start;
				}
			}
			while(lit!=char(13));
			caut[k-1]=NULL;
			caut[0]=toupper(caut[0]);
			cleardevice();
			settextstyle(3,0,1);
			setcolor(0);
			readimagefile("menus/seshow6.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,73,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			for(i=1; i<=n; i++) if(strstr(s[i].pol,caut))
			{
				ok=1;
				a++;
				poz=i;
				p[a]=poz;
			}
			if(ok==1)
			{
				for(i=1; i<=a; i++)
				{
					//table draw
					rectangle(60,72,740,500);
					for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
					line(110,72,110,500);
					line(260,72,260,500);
					line(480,72,480,500);
					setbkcolor(8);
					outtextxy(75,80,"NR.");
					outtextxy(70,100,"CRT");
					outtextxy(140,93,"NUME STAT");
					outtextxy(330,93,"POLITICA");
					outtextxy(550,93,"GUVERNATOR");
					//convertings
					itoa(i,siri,10);
					//database print
					setbkcolor(7);
					outtextxy(75,140+l*37,siri);
					outtextxy(127,140+l*37,s[p[i]].stat);
					outtextxy(330,140+l*37,s[p[i]].pol);
					outtextxy(540,140+l*37,s[p[i]].guv);
					l++;
					if(i%10==0)
					{
						do{ok3=0; if(click(0,538,60,600)) cautare0(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok3=1;} while(ok3==0);
						cleardevice();
						readimagefile("menus/seshow6.jpg",0,0,800,600);
						setfillstyle(1,8);
						bar(61,71,740,130);
						setfillstyle(1,7);
						bar(61,131,740,500);
						l=0;
					}
				}
				do{ok3=0; if(click(0,538,60,600)) cautare0(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok3=1;} while(ok3==0);
				cleardevice();
				readimagefile("menus/info.jpg",0,0,800,600);
				delay(1000);
				cautare0();
			}
			if(ok==0)
			{
				cleardevice();
				readimagefile("menus/seshow6i.jpg",0,0,800,600);
				delay(2000);
				cautare0();	
			}
		}
	}
	while(ok2);
}

void cautare7(char cautan[20])
{
	int k=0,i,j,l=0,ki=0,poz,ok=0,p[51],a=0,ok2,ok3;
	char lit,siri[5],an[51][5],data[51][10];
	do
	{ 
		ok2=1;
		if(click(0,538,60,600)) cautare0(); if(click(740,538,800,600)) meniu(); if(click(379,488,542,506))
		{
			setfillstyle(1,15);
			bar(379,488,800,506);
			for(i=1; i<=n; i++)
			{
				an[i][0]=s[i].data[6];
				an[i][1]=s[i].data[7];
				an[i][2]=s[i].data[8];
				an[i][3]=s[i].data[9];
				an[i][4]=NULL;
				data[i][0]=s[i].data[0];
				data[i][1]=s[i].data[1];
				data[i][2]=s[i].data[2];
				data[i][3]=s[i].data[3];
				data[i][4]=s[i].data[4];
				data[i][5]=NULL;
			}
			do
			{
				start:
				lit=getch();
				if(lit!=char(8))
				{
					cautan[k]=lit; cautan[k+1]=NULL;
					outtextxy(379,485,cautan);
					k++;
				}
				if(lit==char(8)) if(k==0) goto start;
				if(lit==char(8))
				{
					cautan[k]=lit; cautan[k+1]=NULL;
					cautan[k-1]=NULL;
					k--;
					setfillstyle(1,15);
					bar(379,488,800,506);
					outtextxy(379,485,cautan);
					goto start;
				}
			}
			while(lit!=char(13));
			cautan[k-1]=NULL;
			cleardevice();
			settextstyle(3,0,1);
			setcolor(0);
			readimagefile("menus/seshow7.jpg",0,0,800,600);
			setfillstyle(1,8);
			bar(61,73,740,130);
			setfillstyle(1,7);
			bar(61,131,740,500);
			for(i=1; i<=n; i++) if(strcmp(cautan,an[i])==0)
			{
				ok=1;
				a++;
				poz=i;
				p[a]=poz;
			}
			if(ok==1)
			{
				for(i=1; i<=a; i++)
				{
					//table draw
					rectangle(60,72,740,500);
					for(j=0; j<=10; j++) line(60,130+j*37,740,130+j*37);
					line(110,72,110,500);
					line(260,72,260,500);
					line(425,72,425,500);
					line(580,72,580,500);
					setbkcolor(8);
					outtextxy(75,80,"NR.");
					outtextxy(70,100,"CRT");
					outtextxy(140,93,"NUME STAT");
					outtextxy(295,93,"CAPITALA");
					outtextxy(440,93,"ANUL ADERARII");
					outtextxy(618,93,"DATA (Z/L)");
					//convertings
					itoa(i,siri,10);
					//database print
					setbkcolor(7);
					outtextxy(75,140+l*37,siri);
					outtextxy(127,140+l*37,s[p[i]].stat);
					outtextxy(280,140+l*37,s[p[i]].cap);
					outtextxy(482,140+l*37,an[p[i]]);
					outtextxy(635,140+l*37,data[p[i]]);
					l++;
					if(i%10==0)
					{
						do{ok3=0; if(click(0,538,60,600)) cautare0(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok3=1;} while(ok3==0);
						cleardevice();
						readimagefile("menus/seshow6.jpg",0,0,800,600);
						setfillstyle(1,8);
						bar(61,71,740,130);
						setfillstyle(1,7);
						bar(61,131,740,500);
						l=0;
					}
				}
				do{ok3=0; if(click(0,538,60,600)) cautare0(); if(click(370,538,426,600)) meniu(); if(click(740,538,800,600)) ok3=1;} while(ok3==0);
				cleardevice();
				readimagefile("menus/info.jpg",0,0,800,600);
				delay(1000);
				cautare0();
			}
			if(ok==0)
			{
				cleardevice();
				readimagefile("menus/seshow7i.jpg",0,0,800,600);
				delay(2000);
				cautare0();	
			}
		}
	}
	while(ok2);
}

void administration()
{
}