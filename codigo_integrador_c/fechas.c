#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "fechas.h"

int es_fecha_valida(const t_fecha *f)
{
// Funci�n que determina s� una fecha es formalmente correcta
    int fv=0;
    if (f->an > ANIO_BASE)
        if (f->me >=1 && f->me <= 12)
            if (f->di >= 1 && f->di <= cant_dias_mes(f->me,f->an))
                fv=1;
    return fv;
}

int es_fecha_juliana_valida(const t_fecha_jul *f)
{
// Valida una fecha en formato juliano
    int fv=0;
    if((f->an)>1600)
    {
      if((f->di)>0 &&(f->di)<=(365 + esBisiesto(f->an)))
      fv=1;
    }

    return fv;
}

void ingresar_fecha(t_fecha *f)
{
// Pide por pantalla el ingreso de una fecha hasta que se ingrese
// una fecha v�lida y lo carga en el puntero que se le pasa como par�metro
    printf("\nIngrese una fecha de la forma dd/mm/aaaa: ");
    fflush(stdin);
    scanf("%2d/%2d/%4d", &(f -> di) , &(f -> me), &(f -> an));

    while(!es_fecha_valida(f))
        {
        printf("\nError al ingresar la fecha. \nIngrese una fecha de la forma dd/mm/aaaa: ");
        fflush(stdin);
        scanf("%2d/%2d/%4d", &(f -> di) , &(f -> me),&(f -> an));
        }
}

void ingresar_fecha_juliana_valida(t_fecha_jul *f_jul)
{
// Pide por pantalla una fecha en formato juliano hasta que sea valida
    printf("\nIngrese una fecha en formato juliano de la forma ddd/aaaa: ");
    scanf("%03d/%04d", &(f_jul->di),&(f_jul->an));

    while(es_fecha_juliana_valida(f_jul))
    {
    printf("\nError al ingresar la fecha en formato juliano.\nIngrese una fecha de la forma ddd/aaaa: ");
    scanf("%03d/%04d", &(f_jul->di),&(f_jul->an));
    }
}

int cant_dias_mes(int me, int an)
{
// Funci�n que obtiene la cantidad de d�as de un mes
    int cdm[][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
    return cdm[esBisiesto(an)][me-1];
}

void dia_sig(t_fecha *f)
{
// Funci�n que obtiene el d�a siguiente a una determinada fecha
    sumar_dias(f,1);
}

void sumar_dias(t_fecha *f, int di)
{
// Funci�n que le suma N d�as a una fecha
    int cdm;
    f->di += di;
    cdm = cant_dias_mes(f->me,f->an);
    while (f->di > cdm)
    {
        f->di -= cdm;
        f->me++;
        if (f->me > 12)
        {
            f->me = 1;
            f->an++;
        }
        cdm = cant_dias_mes(f->me,f->an);
    }
}

void restar_dias(t_fecha *f, int di)
{
// Funci�n que le resta N d�as a una fecha
    f->di -= di;
    while (f->di <= 0)
        {
            f->me--;
            if (f->me == 0)
            {
                f->me = 12;
                f->an--;
            }
            f->di += cant_dias_mes(f->me,f->an);
        }
}

void f_juliana(const t_fecha *f, t_fecha_jul *f1)
{
// Funci�n que obtiene la fecha jualiana
// a partir de la fecha gregoriana
    int i;
    f1->di = f->di;
    for ( i=1 ; i < f->me ; i++ )
        f1->di += cant_dias_mes(i,f->an);
    f1->an = f->an;
}

void f_gregoriana(const t_fecha_jul *f, t_fecha *f1)
{
// Funci�n que obtiene la fecha gregoriana
// a partir de la fecha juliana
    int i=1;
    f1->di = f->di;
    f1->me = 1;
    f1->an = f->an;
    while (f1->di > cant_dias_mes(i,f1->an))
    {
        f1->di -= cant_dias_mes(i,f1->an);
        f1->me++;
        i++;
    }
}

int comp_fechas(const t_fecha *f1, const t_fecha *f2)
{
// Funci�n que compara dos fechas
// Devuelve: -1 S� la fecha 1 es menor a la fecha 2
//            0 S� las fechas son iguales
//            1 S� la fecha 1 es mayor a la fecha 2
    int x;
    if((f1->an) > (f2->an))
        x = 1;
    else
    {   if((f1->an) < (f2->an))
            x = (-1);
        else
        {   if((f1->me) > (f2->me))
                x = 1;
            else
            {   if((f1->me) < (f2->me))
                    x = (-1);
                else
                {   if((f1->di) > (f2->di))
                        x = 1;
                    else
                    {   if((f1->di) < (f2->di))
                            x = (-1);
                        else
                            x = 0;
                    }
                }
            }
        }
    }
    return x;
}

int dias_a(int a_menor, int a_mayor)
{
// Obtiene la diferencia de d�as entre dos a�os
    int x;
    x=(a_mayor-a_menor)*365;
    while (a_mayor > a_menor)
    {
        if (esBisiesto(a_menor))
            x++;
        a_menor++;
    }
    return x;
}

int dif_fechas(const t_fecha *f1, const t_fecha *f2)
{
// Funci�n que calcula de diferencia de d�as entre dos fechas
    t_fecha_jul f1_j, f2_j;
    f_juliana(f1, &f1_j);
    f_juliana(f2, &f2_j);
    if (!comp_fechas(f1,f2))
        return(fabs(f1_j.di - f2_j.di));
    if (comp_fechas(f1,f2) == -1)
        return (dias_a(f1_j.an,f2_j.an) + f2_j.di - f1_j.di);
    else
        return (dias_a(f2_j.an, f1_j.an) + f1_j.di - f2_j.di);
}

int dia_semana(const t_fecha *f)
{
// Funci�n que obtiene el d�a de la semana
// de una determinada fecha
    t_fecha f_dom;
    int x;
    f_dom.di = 2;
    f_dom.me = 1;
    f_dom.an = ANIO_BASE;
    x = dif_fechas(f,&f_dom);
    x%=7;
    if (x <0 )
        x+=7;
    return x;
}
