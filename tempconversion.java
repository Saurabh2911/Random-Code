import java.util.Scanner;
class temperature
{
public static void main(String[] args)
{
double far, celsius;
Scanner s = new Scanner(System.in);

System.out.println("enter temp in far");
far = s.nextDouble(); 
celsius = ((far-32)*(0.5556));
System.out.println("your temp in celsius is " + celsius);
}
}