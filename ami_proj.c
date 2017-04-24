

									//Advanced C programming Project Semester 2 
									//BY AM.AR.U316BCA015 Amit Krishna
									//Amrita University
									//Project Topic-Library Management System
									//concepts used files,Structure,Functions.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct LIB{//to store records
	int b_id1;
	int b_id2;
	char b_name1[20];
	char b_name2[20];
	char a_name1[20];
	char a_name2[20];
	int s_id;
	char s_name[20];
	int dd;
	int rd;
	int mm;
	int rm;
	int yy;
	int ry;
	float fin;

	
}S;

struct LIBC{//to store deleted records
	int b_id1;
	int b_id2;
	char b_name1[20];
	char b_name2[20];
	char a_name1[20];
	char a_name2[20];
	int s_id;
	char s_name[20];
	int dd;
	int rd;
	int mm;
	int rm;
	int yy;
	int ry;
	float fin;

	
}C;

FILE *p1;

FILE *fp;

FILE *z;

int rno;
char c[30];
int d,m,y;
void mainmenue();
void addBooks();
void returnbook();
void editbook();
void searchbook();
void d_play();
void dp();
void delete1();
void disply();
void ed();
void Show();
void del();
void s();
void tim();
void r_books();
void ret();
void se();
void thank();
void sort();
void gotoxy();
int search();
void disc();
void clear();
void del_d();
void fin_p();
int main()
{
	//LIB S[200];
		printf("\n\t\t\t\t\t**############## WELCOME TO AMRITA LIBRARY MANAGEMANT SYSTEM ###############**");
		//p1=fopen("ami.txt","w+");
		
		p1=fopen("ami.txt","r+");
		//fclose(p);
		//p=fopen("ami.txt","r+");

	if(p1==NULL)
	{
		printf("\nno connection to the file or database");
		
		p1=fopen("ami.txt","w");
		
		fclose(p1);
		
		p1=fopen("ami.txt","r+");
	}
			rewind(p1);

	
	mainmenue();
	
	return 0;
}
void mainmenue()
{ 
	
	int i,j;
	
	//gotoxy(30,10);
    printf("\nEnter \n*1 to issue book \n*2 to return book \n*3 to edit books \n*4 to search book \n*5 to show details\n*6 to renew books\n*7 to sort books \n*8 to exit portal\n*9 description of library\n*10 clear All record\n*11 Show student details\n*12 PAY FINE AMOUNT ");
   
    printf("\nEnter your choice");
   
    scanf("%d",&i);
    switch(i)
    {
		case 1:
		
		addBooks(S);
		
		break;
		
		case 2:
		
			//printf("\nYour book has been deleted");
			
			//del_d(C);
				
		//returnbook(S);
		del_d(S,C);
		break;
		
		case 3:
		
		editbook(S);
		
		break;
		
		case 4:
		
		searchbook(S);
		
		break;
		
		case 5:
		
		disply(S);
		
		case 8:
		
		printf("\nThank you");
		
		fclose(p1);
		
		exit(0);
		
		break;
		
		case 6:
		
		r_books(S);
		
		break;
		
		case 7:
		
		sort(S);
		
		break;
		
		case 9:
		
		disc();
		
		break;
		
		case 10:
		
		clear(S);
		
		break;
		
		case 11:
		
		j=search(S);
		j++;
		
		break;
		
		case 12:
		fin_p(S);
		
		default:
		
		printf("\nEnter the correct option please");
		
		mainmenue();
		
		break;
	}
	
}
void addBooks(struct LIB S)
{
	fseek(p1,0L,SEEK_END);
	
	int j,d,m,y;
	time_t rawtime;
	
    struct tm * timeinfo;
    
    time ( &rawtime );
    
    timeinfo = localtime ( &rawtime );
    //gotoxy(20,9);
	printf("\nEnter the student id ");
	
	scanf("%d",&S.s_id);
	/*while(fread(&S,sizeof(struct LIB),1,p))
	{
		if(a==S.s_id)
		{
			printf("\nThe student id %d has already issued books",a);
		}
		else
		{
			fseek(p,0L,SEEK_END);

			S.s_id=a;
		}
	}*/
	getchar();
	
	printf("\nEnter the student name ");
    
    scanf("%s",S.s_name);
    
    getchar();
    
    printf("\nEnter the book id 1 ");
    
    scanf(" %d",&S.b_id1);
	
	getchar();
	
	printf("\nEnter the book id 2 ");
	
	scanf(" %d",&S.b_id2);
    
    printf("\nEnter the book name1 ");
    
    scanf(" %s",S.b_name1);
    
    printf("\nEnter the book name 2 ");
    
    scanf(" %s",S.b_name2);
    
    printf("\nEnter the author name 1 ");
    
    scanf(" %s",S.a_name1);
    
    printf("\nEnter the author name 2 ");
    
    scanf("%s",S.a_name2);
    
    DATE:
    
    printf("\nEnter the date dd/mm/yyyy ");
    
    scanf(" %d%d%d",&d,&m,&y);
    
    if(d>31 || m>12 || y<0)
    
    {
		
		printf("\nPlease Enter a valid date");
		
		goto DATE;
	}
	
	else
	{
		S.dd=d;
		S.mm=m;
		S.yy=y;
	}
    
    printf("\nYour books are issued on %s ",asctime (timeinfo));
    
    S.fin=0.0;
    S.rd=S.dd;
	S.rm=S.mm+1;
	S.ry=S.yy;
	
	if(S.mm==12)
	{
		S.ry+=1;
		S.rm=1;
	}


    fwrite(&S,sizeof(struct LIB),1,p1);

	printf("\nThe book should be returned on %d/%d/%d",S.rd,S.rm,S.ry);
	
	
    
    printf("\nIf u want to continue press 1 or to exit press 0");
    
    scanf("%d",&j);
    
    if(j==1)
    {
	   mainmenue();
	   
	}
	else
	{
		printf("\n--------------Thank you----------------");
		exit(0);
	}
	

}
void returnbook(struct LIB S)
{
	
	//p=fopen("ami.dat","rb");
	fp=fopen("temp.txt","w+");

	disply(S);//displays all the record
	int j;
	
	//u=search();
	//delete1(u,S);
	int id;
	
	printf("\nEnter the id of the student");
	
	scanf("%d",&id);
	
	rewind(p1);
	
	while(fread(&S,sizeof(struct LIB),1,p1)==1)
	{
		if(id!=S.s_id)
		{
			fwrite(&S,sizeof(struct LIB),1,fp);
			
			
		
		
		
		}
		
		
	}
	
	
	rename("temp.txt","ami.txt");

	disply(S);
	
	
	printf("\nYour books with s_id %d is returned on ",id);
	tim();
	
	
	
	
	printf("\nIf u wana continue press 1 to exit press 0");
    
    scanf("%d",&j);
    if(j==1)
    {
	   mainmenue();
	   
	}
	else
	{
		printf("\nThank you");
		exit(0);
	}

}
void disply(struct LIB S)
{
		int c=0;
		    //fseek(p1,0L,SEEK_SET);
		rewind(p1);
		
		printf("\n-------------------------------------------------------------------------------------------------------------------------");
		
		printf("\nstud_id |s_name  |b_id1   |b_name1  \t|a_name1  |b_id2  |b_name2  |a_name2  |ret_date  |Date of issue | Fine amount | FINE STATUS");
		
		printf("\n-------------------------------------------------------------------------------------------------------------------------");
		
		while((fread(&S,sizeof(S),1,p1)))
		{
  			
  			
  			
  			
  			printf("  \n%3d",S.s_id);
			
			printf("  %10s",S.s_name);
			
			printf("  %4d",S.b_id1);
			
			printf("  %10s",S.b_name1);
			
			printf("  %-10s",S.a_name1);
			
			printf("  %3d",S.b_id2);
			
			printf("  %-10s",S.b_name2);
			
			printf("  %-10s",S.a_name2);
			
			printf("  %3d/%d/%d",S.rd,S.rm,S.ry);
			
			printf("  %3d/%d/%d",S.dd,S.mm,S.yy);
			
			printf("  %3f",S.fin);
			//printf("  %-10s",S.stat);
			c++;
		}
		printf("\n\n\n\t\t\tTotal number of students who have issued books =%d",c);
		printf("\n\t\t\t----------------------------------------------------------------------");
		printf("\n\n\n\t\t\tTotal number of books issued from Library=%d",2*c);
		printf("\n\t\t\t-------------------------------------------------------------------------");
		
		
		
		
		
		
		
	
}
	 
void editbook(struct LIB S)
{
	int j,h;
	int d,m,y;
	
	disply(S);
	h=search();

	if(h)
	{
	printf("\nEnter the student_id");
	scanf("%d",&S.s_id);
	printf("\n\t enter student name ");
    scanf("%s",S.s_name);

	printf("\nEnter the book1 id");
	scanf("%d",&S.b_id1);
    printf("\n\t enter new book1 name ");
    scanf("%s",S.b_name1);
    printf("\nEnter the book 2 id");
    scanf("%d",&S.b_id2);
    printf("\n\t enter new book2 name ");
    scanf("%s",S.b_name2);
    printf("\n\t enter new book1 author name ");
    scanf("%s",S.a_name1);
    printf("\n\t enter new book2 author name ");
    scanf("%s",S.a_name1);
    DATE1:
    
    printf("\nEnter the date dd/mm/yyyy ");
    
    scanf(" %d%d%d",&d,&m,&y);
    
    if(d>31 || m>12 || y<0)
    
    {
		
		printf("\nPlease Enter a valid date");
		
		goto DATE1;
	}
	S.dd=d;
	S.mm=m;
	S.yy=y;
    S.rd=S.dd;
    S.rm=S.mm+1;
    S.ry=S.yy;
    if(S.mm==12)
    {
		S.rm=1;
		S.ry=S.ry+1;
	}
	
	fseek(p1,-((long)sizeof(struct LIB)),SEEK_CUR);

    fwrite(&S,sizeof(S),1,p1);
    printf("\n\tData updated\n");
	}
    //fclose(p);
	printf("\nIf u wana continue press 1 to exit press 0");
    scanf("%d",&j);
    if(j==1)
    {
	   mainmenue();
	   
	}
	else
	{
		printf("\nThank you");
		exit(0);
	}

}
void searchbook(struct LIB S)
{
	
	disply(S);
	int z,j;
	int f=0;
	printf("\nEnter the book id");
	scanf("%d",&z);
    while((fread(&S,sizeof(struct LIB),1,p1)))
    {
		if(z==S.b_id1 || z==S.b_id2)
		{
			f=1;
			fseek(p1,-10L,1);
			
			printf("\nThe book is issued by sid %d",S.s_id);
			
			break;
		}
		
		
		
	}
	if(f==0)
	{
		printf("\nBook not issued");
	}
		

	printf("\nIf u wana continue press 1 to exit press 0");
    
    scanf("%d",&j);
    if(j==1)
    {
	   mainmenue();
	   
	}
	else
	{
		printf("\nThank you");
		exit(0);
	}
}
int search()
{

    int found=0;
    printf("\n\tEnter the roll number you want to search\t");
    scanf("%d",&rno);

    fseek(p1,0L,0);

    while(fread(&S,sizeof(S),1,p1))
    {
        if(rno==S.s_id)
        {
            printf("\n\tRoll number : %d",S.s_id);
            printf("\n\tName : %s",S.s_name);

            printf("\n\tBook1 name : %s",S.b_name1);
            printf("\n\tAuthor1 name : %s",S.a_name1);

            printf("\n\tBook2 name : %s",S.b_name2);
            printf("\n\tAuthor2 name : %s",S.a_name2);
            printf("\n\tDate of issue : %d/%d%d",S.dd,S.mm,S.yy);
              
            found=1;
            break;
        }

    }
    if(found!=1)
            printf("\nRoll number not found");
    
    
    return 1;

}


//to display the current time of the system

void tim()//it is a function used to print the current time of the system
{
  
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  puts(asctime(timeinfo));
  
}

void r_books(struct LIB S)
{

	int q,i;
	int f=0;
	printf("\nEnter the student id");
	scanf("%d",&q);
	while((fread(&S,sizeof(struct LIB),1,p1)))
	{
	if(q==S.s_id)
		{
			f=1;
			S.fin=S.fin+1.5;
			printf("\n\t\tYour books are");
			
			printf("\n1.Book name %s\t Book id %d",S.b_name1,S.b_id1);
			
			printf("\n2.Book name %s\t Book id %d",S.b_name2,S.b_id2);
			
			printf("\nYour fine amount is %f",S.fin);
			
					d=S.rd;
					m=S.rm;
					y=S.ry;
                    if(m==12)
					{
						m=1;
						y=y+1;
					}
					else
					{
						m=m+1;
					}
			break;
		}
		else
		{
			continue;
		}
	}
	if(f==1)
	{
	printf("\nYour book renewed on:-");
	tim();

	printf("\nYou must return the  books on %d/%d/%d",d,m,y);
	


	while(1)
	{
		
		
		

			
			
			
			S.rd=d;
			S.rm=m;
			S.ry=y;
			fseek(p1,-((long)sizeof(struct LIB)),SEEK_CUR);

			fwrite(&S,sizeof(struct LIB),1,p1);

			break;
			
			
     }
        
        
        


		printf("\nYour books are renewed");
	}
	else
	{
		printf("\nThe student id %d has not issued any books",q);
	
	printf("\nDo you want to renew books 1:yes |0 :no");
	scanf("%d",&i);
	if(i==1)
	{
		r_books(S);
	}
	else
	{
		printf("\nThank you");
	
	}



	}
}

			
			
	

 


void sort(struct LIB S)
{
	int s,y;
	int f=0;
	int c=0;
	int m;
	char mo[20];
	rewind(p1);
	printf("\nIf you want to sort by year press 1 :: by month press 0"); 
	
	scanf("%d",&m);
	if(m==0)
	{
	printf("\nEnter the month in which book was issued");
	scanf("%d",&s);
	printf("\nThe books are");
	while((fread(&S,sizeof(struct LIB),1,p1)))
	{
		if(s==S.mm)
		{
			
			f=1;
			printf("\n* %s",S.b_name1);

			printf("\n* %s",S.b_name2);
			c++;
			f=1;
		}
		else
		{
			continue;
		}
	}
	if(f==0)
	{
		switch(s)
		{
			case 1:
			strcpy(mo,"January");
			break;
			case 2:
			strcpy(mo,"February");
			break;
			case 3:
			strcpy(mo,"March");
			break;
			case 5:
			strcpy(mo,"May");
			break;
			case 6:
			strcpy(mo,"June");
			break;
			case 7:
			strcpy(mo,"July");
			break;
			case 8:
			strcpy(mo,"August");
			break;
			case 9:
			strcpy(mo,"September");
			break;
			case 10:
			strcpy(mo,"October");
			break;
			case 11:
			strcpy(mo,"November");
			break;
			case 12:
			strcpy(mo,"December");
			break;
			case 4:
			strcpy(mo,"April");
			break;
			default:
			printf("\nEnter the valid month");
		}
			
		printf("\nNo books issued in the month of %s are %c",mo,c);
		
	}
	else
	{
	printf("\nTotal number of books issued in the month of %s is %d",mo,c);
	}
  }
  else 
  {
	  
	printf("\nEnter the year in which book was issued");
	
	scanf("%d",&y);
	
	printf("\nThe books are");
	
	while((fread(&S,sizeof(struct LIB),1,p1)))
	{
		if(y==S.yy)
		{
			
			f=1;
			printf("\n* %s",S.b_name1);

			printf("\n* %s",S.b_name2);
			c++;
		}
		else
		{
			continue;
		}
	}
	if(f==0)
	{
		printf("\nNo books issued in the year of %d",y);
		
	}
	else
	{
	printf("\nTotal number of books issued in the year of %d is %d",y,c);
	}
  }
	  
}
/*void clear(struct LIB S)
{
	remove(p);
}
*/
//this is a function used to fix the cursor to a fixed position
void gotoxy(int x,int y)
{
	printf("%c[%d;%df",0x1B,y,x);
}	
//IN THIS FUNCTION I HAVE SHOWN THE USE OF gotoxy() to print in a different pattern
//in this when the character 0x1B is read the comiler identifies that the this statement is for commanding the cursor
//the next two degits represents the coordinates at which the cursor must be plased
//%df means the cursor must be fixed to the coordinates 
//then the printf statements are executed 	
void disc()
{
	system("clear");
	printf("\n\t\t\t\t\t**############## WELCOME TO AMRITA LIBRARY MANAGEMANT SYSTEM ###############**");
	
	gotoxy(10,10);
	int j;
	printf("\n\t\t\tAMRITA LIBRARY MANAGEMENT SYSTEM WAS INTRODUSED IN THE YEAR 2017 BY STUDENTS OF S2 BCA");
	printf("\n\n\t\t\tTHIS IS A PROJECT ON ADVANCED C PROGRAMMING BY AMIT KRISHNA S2,BCA");
	printf("\n\n\t\t\t*Rules to be followed in library");
	printf("\n\t\t\t1:Each student can issue two books at atime");
	printf("\n\t\t\t2:Student must return the book at the return date itself");
	printf("\n\t\t\t3:Student will be fined with 1.5 Rs if he/she fails to return the book at before the last date");
	printf("\n\t\t\t4:Maintain total silence in the reading room");
	printf("\n\t\t\t5:Use of Gadgets such as mobile phones,Laptops... etc are not allowed");
	printf("\n\t\t\t6:Strict action will be taken if any Student Violates the rules");
	printf("\n\n\t\t\tOm Amriteswaryai Namah");

	printf("\n\n\t\t\t\'Real happiness in life comes from the mental capacity to adapt to any situation.\'"); 
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\tChancellor, Sri Mata Amritanandamayi Devi");
 
	
	printf("\nIf u want to continue press 1 or to exit press 0");
    scanf("%d",&j);
    if(j==1)
    {
	   mainmenue();
	   
	}
	else
	{
		printf("\n--------------Thank you----------------");
		exit(0);
	}
	
	
	
}
void clear(struct LIB S)
{
	int j;
	fp=fopen("temp.dat","wb+");
	rewind(p1);
	
	while(fread(&S,sizeof(struct LIB),1,p1)==1)
	{
		if(1)
		{
			fread(&S,sizeof(struct LIB),1,p1);
			break;
			/*S.s_id=0;
			strcpy(" ",S.s_name);
			S.b_id1=0;
			S.b_id2=0;
			strcpy(" ",S.b_name1);
			strcpy(" ",S.b_name2);
			strcpy(" ",S.a_name1);
			strcpy(" ",S.a_name2);
			S.dd=0;
			S.mm=0;
			S.yy=0;
			S.rd=0;
			S.rm=0;
			S.ry=0;
			fwrite(&S,sizeof(struct LIB),1,p);*/
			//printf("\nYour books with s_id %d is returned on",rno);
			//tim();
		}
		else
		{
		fwrite(&S,sizeof(struct LIB),1,fp);
		}
		
	}	
	fclose(p1);
	fclose(fp);
	
	remove("ami.txt");
	rename("temp.txt","ami.txt");
	printf("\nThe Library record are cleared do you want to continue");
	printf("\npress 1:to continue 0:to exit");
	scanf("%d",&j);
	if(j==1)
	{
		main();
	}
	else
	{
		printf("\nThank You");
		exit(0);
	}
}
void del_d(struct LIBC C,struct LIB S)
{
	
		int c=0;
		int s;

		
		z=fopen("del.txt","r+");
		rewind(z);
		printf("\nEnter the Student id ypou want to delete");
		
		scanf("%d",&s);
		
		while(fread(&S,sizeof(struct LIB),1,p1))
		{
			if(s==S.s_id)
			{
				C.s_id=S.s_id;
				strcpy(C.s_name,S.s_name);
				C.b_id1=S.b_id1;
				C.b_id2=S.b_id2;
				strcpy(C.b_name1,S.b_name1);
				strcpy(C.b_name2,S.b_name2);
				strcpy(C.a_name1,C.a_name2);
				C.dd=S.dd;
				C.mm=S.mm;
				C.yy=S.yy;
				C.rd=S.rd;
				C.rm=S.rm;
				C.ry=S.ry;
				C.fin=S.fin;
				//strcpy(C.stat,S.stat);
			}
				
			
		}
		printf("\n\t\t\t\t--::RECORDS OF DELETED BOOKS::--");
		printf("\n-------------------------------------------------------------------------------------------------------------------------");
		printf("\nstud_id |s_name  |b_id1   |b_name1  \t|a_name1  |b_id2  |b_name2  |a_name2  |ret_date  |Date of issue | Fine amount |Status of FINE");
		printf("\n-------------------------------------------------------------------------------------------------------------------------");
		while((fread(&C,sizeof(struct LIBC),1,z)))
		{
  			
  			
  			
  			
  			printf("  \n%3d",C.s_id);
			printf("  %10s",C.s_name);
			printf("  %4d",C.b_id1);
			printf("  %10s",C.b_name1);
			printf("  %-10s",C.a_name1);
			printf("  %3d",C.b_id2);
			printf("  %-10s",C.b_name2);
			printf("  %-10s",C.a_name2);
			printf("  %3d/%d/%d",C.rd,C.rm,C.ry);
			printf("  %3d/%d/%d",C.dd,C.mm,C.yy);
			printf("  %3f",C.fin);
			c++;
		}
		printf("\n\n\n\t\t\tTotal number of students who have returned the books =%d",c);
		printf("\n\t\t\t----------------------------------------------------------------------");
		printf("\n\n\n\t\t\tTotal number of books returned to Library=%d",2*c);
		printf("\n\t\t\t-------------------------------------------------------------------------");
		fclose(z);
}
void fin_p(struct LIB S)
{
	int i,s;
	printf("\nIF U WANT TO PAY FINE::press 1 or press 0");
	scanf("%d",&i);
	if(i==1)
	{
		printf("\nEnter the student id");
		scanf("%d",&s);
		while(fread(&S,sizeof(struct LIB),1,p1))
		{
			if(s==S.s_id)
			{
			
				printf("\nYour fine amount is %f:",S.fin);
				if(S.fin==0.0)
				{
					printf("\nYOU HAVE NO FINE AMOUNT");
					exit(0);
				}
				S.fin=0.0;
				printf("\nYour fine is paid on ");
				tim();
				
			}
			else
			{
				printf("\nThe student id %d has not issued any book",s);
			}
		}
	}
	else
	{
		main();
	}
}
				
		
	
	
	

		
		
		
		
		
		
	
	
	
	
	
	

	
		

	
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	
	
	
	
		
	
		
		
