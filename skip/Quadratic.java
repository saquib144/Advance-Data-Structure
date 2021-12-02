import java.lang.*;
public class Quadratic
{
public static void main(String args[])
{
double root1,root2;
double a=2,b=3,c=8;
double determinant=(b*b)-(4*a*c);

if(determinant>0)
{
 root1=(-b+Math.sqrt(determinant))/(2*a);
 root2=(-b-Math.sqrt(determinant))/(2*a);

System.out.format("roots1=%.2f & root2=%.2f",root1,root2);
System.out.println("roots2"+r2);
}
else if(determinant==0)
{
root1=root2=-b / (2*a);
System.out.format("root1=root2=%.2f:"+root1)
}
else
{
double real=-b/(2*a);

double imaginary=Math.sqrt(-determinant)/(2*a);
System.out.format("root2=%.2f+%.2fi",real,imaginary);
System.out.format("root2=%.2f-%.2fi",real,imaginary);
}
}
}