#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;
struct Student{
string name;
int id;
double cgpa;
}students[5];//declaring hard-coded student-structure array
int stringCompare(char mj1[], char mj2[])//compares 2 strings and returns a 2 if the strings are not in order
{
    int i = 0, flag = 0;//same stuff
    while(mj1[i] != '\0' && mj2[i] != '\0')
    {
        if(mj1[i] != mj2[i])
        {
            if(mj1[i] > mj2[i])
            {
                flag = 2;//needs swapping
            }
            else
            {
                flag = 1;//its okay no need swapping
            }
            break;
        }
        i++;
    }
    if(flag == 0 && mj1[i] == '\0' && mj2[i] == '\0')
        return flag;
    else
        return flag;
}
void merge_array(Student arr[],int low,int mid,int high)//Merge-Sort Algorithm
{
    int n1,n2,i,j,k;
        n1=mid-low+1;
        n2=high-mid;
    Student *left=new Student[n1+1];
    Student *right=new Student[n2+1];

    for(i=0;i<n1;i++){
        left[i]=arr[low+i];
    }
    for(j=0;j<n2;j++)
    {
        right[j]=arr[mid+j+1];
    }
    left[n1].name=right[n2].name='{';
    i=j=0;

   for(int k=low;k<=high;k++)
   {
        char temp1[20],temp2[20];
        strcpy(temp1,(left[i].name).c_str());
        strcpy(temp2,(right[j].name).c_str());
        if(stringCompare(temp1,temp2)<2)
        {
            arr[k]=left[i];
            i++;
        }
        else
        {
            arr[k]=right[j];
            j++;
        }
    }
 delete[] left;
 delete[] right;
}
void merge_sort(Student arr[],int low,int high)//Merge-Sort Algorithm
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        merge_sort(students,low,mid);
        merge_sort(students,mid+1,high);
        merge_array(students,low,mid,high);
    }
}
int main()
{
    students[0]={"Momin",11,3.23};//inserting hard-coded
    students[1]={"Momena",5,3.74};
    students[2]={"Aria",20,3.59};
    students[3]={"Sakib",12,3.39};
    students[4]={"Arif",14,3.55};
    merge_sort(students,0,4);//using merge-sort to lexicographically sort the structures

  for(int i=0;i<5;i++)
  {
      cout<<students[i].name<< " ";
      cout<<students[i].id<< " ";
      cout<<students[i].cgpa<< "\n";
  }
  return 0;
}
