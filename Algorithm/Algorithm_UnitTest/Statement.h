#pragma once


/*��һ��*/
bool Read_Input(char *section, char *numsname, char *filename, char *keyname);
int Read_Output(char *section, char *key1, char *filename);

/*�ڶ���*/
int Num_Juage(char *section, char *keyname, char *filename);

/*������*/
int Num3_Juage(char *section, char *keyname, char *filename);

/*������*/
int Num4_Juage(char *section, char *keyname, char *filename);

/*������*/

bool Nums_Juage(char *section, char *numsname, char *filename);

/*�ڰ���*/
unsigned int Num8_Juage(char *section, char *keyname, char *filename);