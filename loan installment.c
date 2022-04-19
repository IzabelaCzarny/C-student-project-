#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define dprint(expr) printf(#expr " = %d\n",expr)
#define gprint(expr) printf(#expr " = %g\n",expr)
#define fprint(expr) printf(#expr " = %6.20f\n",expr)

#define  Pi 3.14159265358979323846264338328

char filename[40],filename1[40];
FILE *fp,*fp1;
/* ************************************************************************* */
void datafiles()
{

strcpy(filename,"inpR.dat");
strcpy(filename1,"resule.dat");


	if((fp=fopen(filename,"r"))==NULL)
	{
        printf("I cannot open the file");
	}
	if((fp1=fopen(filename1,"w"))==NULL)
	{
        printf("I cannot open the file");
	}
}
// -------------------------------------------------------------
int main()
{
int i,N, miesiac;
double kwota, kwota0, kwotaNew, alfa, deltaT;

datafiles();




printf("wyniki");


N = 100;
alfa=0.05/12.0;
kwota = kwota0 = 10000.0;


for(i=1;i<=10000;i++)
{miesiac= i;
deltaT = 1;
kwotaNew=kwota+alfa*deltaT*kwota;

fprintf(fp1, "%d %lf\n",miesiac,kwotaNew);

kwota=kwotaNew;//podmianka
}



system("Pause");

fclose(fp);
fclose(fp1);
return 1;
}
/* ***************** end of main ******************************************* */
