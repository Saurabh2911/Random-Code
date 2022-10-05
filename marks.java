import java.util.Scanner;
class Marksheet 
{
 int marks;
String a;
void get()
{
Scanner s = new Scanner(System.in);
System.out.println("enter name of stdnt");
a = s.nextLine(); 
System.out.println("enter marks of stdnt");
marks = s.nextInt();
}
static void swap( Marksheet ob1 , Marksheet ob2 )
{
int temp;
temp = ob1.marks;
ob1.marks = ob2.marks;
ob2.marks = temp;
}
void disp()
{
  System.out.println("marks is:" + marks);
}
}
class ABC
{
public static void main(String[] args)
{
Marksheet ob1 = new Marksheet();
Marksheet ob2 = new Marksheet();
ob1.get();
ob2.get();
Marksheet.swap(ob1,ob2);
ob1.disp();
ob2.disp();
}
}