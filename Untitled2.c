#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findstring(char *sstring,char *needtofind)
{
	int ns,nf;
	int i,j;
	int vitri=0;
	char buffer[10];
	ns=strlen(sstring);
	nf=strlen(needtofind);
	
	for(i=0;i<ns-nf+1;i++)
	{
		for(j=0;j<nf;j++)
		{
			buffer[j]=sstring[i+j];
		}
		buffer[nf]='\0';
		if(strcmp(buffer,needtofind)==0)
		{
			vitri=i;
			return vitri;
		}
		else;
		
	}
	return -1;	
}

void hamdaochuoi(char *chuoinguon, char *chuoidich)
{
	int i;
	int n = strlen(chuoinguon);
	for(i=0;i<n;i++)
	{
		chuoidich[i]=chuoinguon[n-1-i];
	}
	chuoidich[n]='\0';
}

char * timchuoidoixung(char *chuoicantim)
{
	char *result = NULL;
	char daochuoi[100];
	char chuoidoixung[100];
	char buffer1[50];
	char buffer2[50];
	int nss,ndem,ndoixung;
	int vitricuoi1;
	int vitricuoi2;
	int chenhlechvitri;
	int vitridao;
	int i,j,k,x,h;
	int dk=0;	
	hamdaochuoi(chuoicantim,daochuoi);
	puts(daochuoi);
	printf("%d \n",nss);
	ndem=nss/2;

	for(i=ndem;i>1;i--)
	{
		for(j=0;j<nss-i+1;j++)
		{
			for(x=0;x<i;x++)
			{
				buffer1[x]=chuoicantim[j+x];
			}
			buffer1[i]='\0';
			//puts(buffer1);
			vitridao = findstring(daochuoi,buffer1);
			vitricuoi1=j+i-1;
			vitricuoi2=nss-vitridao-i;
			chenhlechvitri=vitricuoi2-vitricuoi1;
			if((vitridao!=-1)&&(chenhlechvitri==1))
			{
				printf("Co ton tai chuoi doi xung trong chuoi va da ghi ra file \n");								
				ndoixung=2*strlen(buffer1);
				for(h=0;h<(ndoixung/2);h++)
				{
					chuoidoixung[h]=buffer1[h];
					chuoidoixung[ndoixung-h-1]=buffer1[h];
				}
				chuoidoixung[ndoixung]='\0';
				puts(chuoidoixung);
				dk=1;
				result = chuoidoixung;
				return result;
			}
			else if((vitridao!=-1)&&(chenhlechvitri>1))
			{
				printf("Phai xoa ki tu moi co chuoi doi xung va da ghi ra file \n");
				ndoixung=2*strlen(buffer1);
				for(h=0;h<(ndoixung/2);h++)
				{
					chuoidoixung[h]=buffer1[h];
					chuoidoixung[ndoixung-h-1]=buffer1[h];
				}
				chuoidoixung[ndoixung]='\0';
				puts(chuoidoixung);
				dk=1;
				result = chuoidoixung;
				return result;
			}
		}

	}
	if(dk==0)
	{
		return result;
	}

}

void process(char *filename)
{
	FILE *doc;
	FILE *ghi;

	char chuoicantim[100];
	doc = fopen(filename,"r");
	ghi = fopen("ketqua.txt","w+");
	while(!feof(doc))
	{
		fgets(chuoicantim,100,doc);
		puts(chuoicantim);
		int nss=strlen(chuoicantim);
		printf("%d \n",nss);

		if(chuoicantim[nss-1]=='\n')
		{
			chuoicantim[nss-1]='\0';
		}
		printf("%d \n",strlen(chuoicantim));
		char * result = timchuoidoixung(chuoicantim);
		if(result!=NULL)
		{
			fprintf(ghi,result);
			fprintf(ghi,"%c",'\n');
		}		
	}
	fclose(doc);
	fclose(ghi);
}

int main()
{
	char filename[20] = "nguon.txt";
	process(filename);	
	return 0 ;
}
