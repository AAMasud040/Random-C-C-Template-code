#include<bits/stdc++.h>

struct stu
{
    int id;
    double cgpa;
    double cgpa1;
    double cgpa2;
    double cgpa3;
    double cgpa4;
    int probation = 0;
} st[10];
int main()
{
    int i;
    FILE *fp = fopen("new.txt","r");
    if (fp==NULL)
    {
        printf("cannot find input data");
    }
    else
    {
        char c;
        for(i=0; c!=EOF; i++)
        {
            fscanf(fp,"My student ID is: %d My GPAs are: %lf %lf %lf %lf",&st[i].id,&st[i].cgpa1,&st[i].cgpa2,&st[i].cgpa3,&st[i].cgpa4);
            st[i].cgpa = st[i].cgpa1+st[i].cgpa2+st[i].cgpa3+st[i].cgpa4;
            st[i].cgpa= st[i].cgpa/4;
            if(st[i].cgpa <2.00)
            {
                st[i].probation = 1;
            }
            printf("%lf %d\n",st[i].cgpa,st[i].probation);
            c = getc(fp);
        }
    }
    fclose(fp);
    FILE *fp1 = fopen("newstudent.txt","w");
    if (fp1==NULL)
    {
        printf("cannot find input data");
    }
    else
    {
        for(int j = 0 ;j<i;j++)
        {
            if(st[j].probation == 0)
                fprintf(fp1,"My student ID is: %d My GPAs are: %lf %lf %lf %lf CGPA %lf\n",st[j].id,st[j].cgpa1,st[j].cgpa2,st[j].cgpa3,st[j].cgpa4,st[j].cgpa);
            else
            {
                fprintf(fp1,"My student ID is: %d My GPAs are: %lf %lf %lf %lf CGPA %lf probation\n",st[j].id,st[j].cgpa1,st[j].cgpa2,st[j].cgpa3,st[j].cgpa4,st[j].cgpa);
            }
        }
    }
    fclose(fp1);
}
