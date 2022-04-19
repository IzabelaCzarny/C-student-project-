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
int i,N;
double N0, N1,N2,N3, alfa, alfa2, delta,time,yN1New,yN2New,yN3New;

datafiles();

printf("wyniki");


N = 1000;
delta = 0.1;
alfa = 0.1;
alfa2 = 0.1;
N1 =  1000; N2 = N3 = 0;

for(i=1;i<=N;i++)
{


    time = i*delta;

    yN1New = N1 - delta * N1 * alfa;
    yN2New = N2  +delta * N1 * alfa - delta * N2 * alfa2;
    yN3New = N3+delta*N2 *alfa2;

    fprintf(fp1,"%lf %lf %lf %lf\n",time,N1,N2,N3);

    N1 = yN1New;
    N2 = yN2New;
    N3 = yN3New;//podmianka
}



system("Pause");

fclose(fp);
fclose(fp1);
return 1;
}
/* ***************** end of main ******************************************* */
