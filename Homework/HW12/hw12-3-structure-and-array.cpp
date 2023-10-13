/*
    ผู้ใช้กรอกข้อมูลพนักงานในบริษัท โดยจะกรอกข้อมูล ชื่อ, เงินเดือน, อายุการทำงาน ของแต่ละคน โดยเมื่อผู้ใช้กรอกตัว n จะถือเป็นการหยุดโปรแกรมและทำการแสดงข้อมูลเงินเดือนเฉลี่ยของพนักงานในบริษัท และเงินเดือนของทุกคนรวมกันที่ผู้บริหารต้องจ่าย และแสดงคนที่อายุงานเยอะที่สุดพร้อมระบุ ชื่อ เงินเดือน และอายุงาน ของคนๆ นั้น

    Test case:
        Do you want to Enter Employee Information? (y/n) :
            y
        ----
        Employee Name :
            Yorn
        Salary (Bath/Month) :
            15000
        Duration (Year) :
            4
        Do you want to Enter Employee Information? (y/n) :
            y
        ----
        Employee Name :
            Van
        Salary (Bath/Month) :
            14550
        Duration (Year) :
            2
        Do you want to Enter Employee Information? (y/n) :
            y
        ----
        Employee Name :
            Thane
        Salary (Bath/Month) :
            22500
        Duration (Year) :
            8
        Do you want to Enter Employee Information? (y/n) :
            n
    Output:
        Average of Salary : 17,350.00 Bath
        Payment of every month : 52,050.00 Bath
        ----------------------------------------
        ** Most duration in this business **
        Name : Thane (8 Years)
        Salary : 22,500.00 Bath

*/

// TODO: #21 output money should in decimal format (eg. 120,200,340.42).

#include <stdio.h>
#include <locale.h>

struct employeeinfo
{
    char Name[99];
    int salary , dura ;
} typedef employeeinfo;

int main()
{
    setlocale(LC_NUMERIC, "");
    int count = 0 ;
    char want;
    employeeinfo einfo[99];

    for (int i = 0; want != 'n' ; i++ , count++ )
    {
        printf("Do you want to Enter Employee Information? (y/n) :");
        scanf("%s", &want);
        if ( want == 'n' )
        {
             break;
        }
        else if ( want == 'y' )
        {
            printf("\nEmployee Name :");
            scanf("%s", einfo[i].Name );
                
            printf("\nSalary (Bath/Month) :");
            scanf("%d", &einfo[i].salary );
                
            printf("\nDuration (Year) :");
            scanf("%d", &einfo[i].dura );

            printf( "\n" ) ;
        }
        else
        {
            printf("wrong input, try again! \n");
        }
    }


    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (einfo[i].dura < einfo[j].dura )
            {
                employeeinfo temp = einfo[i];
                einfo[i] = einfo[j];
                einfo[j] = temp;
            }
        }
    }

    float allsala ; 

    for (int i = 0; i <= count ; i++)
    {
        allsala += einfo[i].salary ; 
    }
    
    float avg = allsala / count ;
    
    float mostsala = einfo[0].salary;

    printf( "Average of Salary : %'.2f Bath\n" , avg ) ;
    printf( "Payment of every month : %'.2f Bath\n" , allsala ) ;
    printf( "----------------------------------------\n" ) ;
    printf( "Name : %s (%d Years)\n" , einfo[0].Name , einfo[0].dura ) ;
    printf( "Salary : %'.2f Bath\n" , mostsala ) ;


    


    return 0 ;
}